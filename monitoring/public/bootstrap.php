<?php
declare(strict_types=1);

function env_required(string $name): string
{
    $value = getenv($name);
    if ($value === false || trim($value) === '') {
        throw new RuntimeException("Missing required environment variable: {$name}");
    }
    return $value;
}

function database(): PDO
{
    static $connection = null;
    if ($connection instanceof PDO) {
        return $connection;
    }

    $host = env_required('SOLARCOLD_DB_HOST');
    $port = filter_var(getenv('SOLARCOLD_DB_PORT') ?: '3306', FILTER_VALIDATE_INT);
    if ($port === false || $port < 1 || $port > 65535) {
        throw new RuntimeException('SOLARCOLD_DB_PORT must be a valid TCP port.');
    }

    $dsn = sprintf(
        'mysql:host=%s;port=%d;dbname=%s;charset=utf8mb4',
        $host,
        $port,
        env_required('SOLARCOLD_DB_NAME')
    );

    $connection = new PDO($dsn, env_required('SOLARCOLD_DB_USER'), env_required('SOLARCOLD_DB_PASSWORD'), [
        PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION,
        PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC,
        PDO::ATTR_EMULATE_PREPARES => false,
    ]);

    return $connection;
}

function json_response(array $payload, int $status = 200): never
{
    http_response_code($status);
    header('Content-Type: application/json; charset=utf-8');
    header('Cache-Control: no-store');
    echo json_encode($payload, JSON_THROW_ON_ERROR);
    exit;
}

function request_value(string $name): ?string
{
    $value = $_POST[$name] ?? $_GET[$name] ?? null;
    return is_string($value) ? trim($value) : null;
}

function validate_series(?string $value, string $field): string
{
    if ($value === null || $value === '') {
        throw new InvalidArgumentException("Missing field: {$field}");
    }
    $parts = explode(',', $value);
    if (count($parts) > 10) {
        throw new InvalidArgumentException("{$field} contains too many readings.");
    }
    foreach ($parts as $part) {
        if ($part === '' || !is_numeric($part) || !is_finite((float) $part)) {
            throw new InvalidArgumentException("{$field} must contain only finite numeric readings.");
        }
    }
    return implode(',', array_map(static fn(string $part): string => trim($part), $parts));
}

