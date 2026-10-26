<?php
declare(strict_types=1);

require __DIR__ . '/bootstrap.php';

try {
    if (($_SERVER['REQUEST_METHOD'] ?? 'GET') !== 'GET') {
        header('Allow: GET');
        json_response(['error' => 'Method not allowed.'], 405);
    }

    $limit = filter_var($_GET['limit'] ?? '100', FILTER_VALIDATE_INT, [
        'options' => ['min_range' => 1, 'max_range' => 500],
    ]);
    if ($limit === false) {
        json_response(['error' => 'limit must be between 1 and 500.'], 422);
    }

    $statement = database()->prepare(
        'SELECT device_id, dht_humidity, dht_room_temp,
                mlx_Object_temp AS mlx_object_temp, mlx_room_temp,
                voltage, current, time_stamp
         FROM ColdRoomMonitor
         ORDER BY time_stamp DESC
         LIMIT :record_limit'
    );
    $statement->bindValue('record_limit', $limit, PDO::PARAM_INT);
    $statement->execute();
    $records = $statement->fetchAll();
    json_response(['data' => $records, 'count' => count($records)]);
} catch (Throwable $error) {
    error_log('Telemetry fetch failed: ' . $error->getMessage());
    json_response(['error' => 'Telemetry is temporarily unavailable.'], 500);
}

