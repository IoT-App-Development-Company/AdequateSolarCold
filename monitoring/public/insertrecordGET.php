<?php
declare(strict_types=1);

require __DIR__ . '/bootstrap.php';

try {
    if (!in_array($_SERVER['REQUEST_METHOD'] ?? 'GET', ['GET', 'POST'], true)) {
        header('Allow: GET, POST');
        json_response(['error' => 'Method not allowed.'], 405);
    }

    $configuredToken = getenv('SOLARCOLD_INGEST_TOKEN') ?: '';
    $providedToken = $_SERVER['HTTP_X_INGEST_TOKEN'] ?? '';
    if ($configuredToken !== '' && !hash_equals($configuredToken, $providedToken)) {
        json_response(['error' => 'Unauthorized.'], 401);
    }

    $deviceId = request_value('D_id');
    if ($deviceId === null || !preg_match('/^[A-Za-z0-9._-]{1,64}$/', $deviceId)) {
        throw new InvalidArgumentException('D_id must be 1-64 letters, numbers, dots, underscores, or hyphens.');
    }

    $voltage = filter_var(request_value('v'), FILTER_VALIDATE_FLOAT);
    $current = filter_var(request_value('c'), FILTER_VALIDATE_FLOAT);
    if ($voltage === false || $current === false || !is_finite((float) $voltage) || !is_finite((float) $current)) {
        throw new InvalidArgumentException('v and c must be finite numbers.');
    }

    $timezone = getenv('SOLARCOLD_TIMEZONE') ?: 'UTC';
    $recordedAt = new DateTimeImmutable('now', new DateTimeZone($timezone));

    $statement = database()->prepare(
        'INSERT INTO ColdRoomMonitor
        (device_id, dht_humidity, dht_room_temp, mlx_Object_temp, mlx_room_temp, voltage, current, time_stamp)
        VALUES (:device_id, :dht_humidity, :dht_room_temp, :mlx_object_temp, :mlx_room_temp, :voltage, :current, :time_stamp)'
    );
    $statement->execute([
        'device_id' => $deviceId,
        'dht_humidity' => validate_series(request_value('d_h'), 'd_h'),
        'dht_room_temp' => validate_series(request_value('d_t'), 'd_t'),
        'mlx_object_temp' => validate_series(request_value('m_Ot'), 'm_Ot'),
        'mlx_room_temp' => validate_series(request_value('m_rt'), 'm_rt'),
        'voltage' => $voltage,
        'current' => $current,
        'time_stamp' => $recordedAt->format('Y-m-d H:i:s'),
    ]);

    json_response(['status' => 'accepted', 'id' => (int) database()->lastInsertId()], 201);
} catch (InvalidArgumentException $error) {
    json_response(['error' => $error->getMessage()], 422);
} catch (Throwable $error) {
    error_log('Telemetry ingestion failed: ' . $error->getMessage());
    json_response(['error' => 'Telemetry could not be stored.'], 500);
}

