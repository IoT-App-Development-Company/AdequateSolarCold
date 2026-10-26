# Adequate SolarCold monitoring service

The monitoring service receives cold-room telemetry, stores it in MySQL, and provides a responsive operations dashboard.

## Requirements

- PHP 8.1 or newer with `pdo_mysql`
- MySQL 8 or MariaDB 10.6+
- A web server configured with `public/` as its document root

## Configuration

Set these environment variables in Apache, PHP-FPM, IIS, or the deployment platform:

| Variable | Required | Default |
| --- | --- | --- |
| `SOLARCOLD_DB_HOST` | Yes | none |
| `SOLARCOLD_DB_PORT` | No | `3306` |
| `SOLARCOLD_DB_NAME` | Yes | none |
| `SOLARCOLD_DB_USER` | Yes | none |
| `SOLARCOLD_DB_PASSWORD` | Yes | none |
| `SOLARCOLD_INGEST_TOKEN` | Recommended | empty |
| `SOLARCOLD_TIMEZONE` | No | `UTC` |

Do not place credentials in PHP files. Rotate the credentials previously published in the upstream examples before deploying this version.

## Endpoints

- `GET /` — service landing page.
- `GET /dashboard.php` — latest telemetry dashboard.
- `GET /fetch_data.php?limit=100` — JSON telemetry history.
- `POST /insertrecordGET.php` — telemetry ingestion. Legacy GET requests remain accepted during device migration.

When `SOLARCOLD_INGEST_TOKEN` is configured, send `X-Ingest-Token: <token>`.

Required telemetry fields are `D_id`, `d_h`, `d_t`, `m_Ot`, `m_rt`, `v`, and `c`. Sensor-array fields are comma-separated finite numbers with at most ten values.

## Production checklist

- Enable HTTPS.
- Disable `display_errors`.
- Restrict database network access.
- Use a unique ingestion token.
- Add rate limiting at the web server or reverse proxy.
- Configure backups and retention appropriate to the installation.

