# Adequate SolarCold Platform

An integrated solar-powered cold-room platform maintained by **Adequate Infosoft**. It combines cold-room engineering assets, Arduino telemetry firmware, PCB and enclosure designs, a PHP/MySQL monitoring service, and field-validation material for off-grid cold-chain deployments.

## Platform modules

| Area | Contents |
| --- | --- |
| Cold-room engineering | Architectural exports, construction references, and system diagrams |
| Edge telemetry | Arduino Mega firmware for DHT22 and MLX90614 sensor arrays |
| Electronics | PCB source, manufacturing exports, and enclosure models |
| Monitoring | Telemetry ingestion API and browser-based operations dashboard |
| Operations | Calibration records, test plans, user guidance, and financial templates |

## Project map

- [Cold-room design](./cold-room-design/) — building and system architecture.
- [Component datasheets](./component-datasheets/) — manufacturer reference material.
- [Firmware](./firmware/) — controller code and bundled libraries.
- [PCB design](./pcb-design/) — PCB source and fabrication outputs.
- [Enclosure design](./enclosure-design/) — printable and editable enclosure assets.
- [Monitoring](./monitoring/) — telemetry API and dashboard.
- [System testing](./system-testing/) — calibration, plans, and results.
- [User manual](./user-manual/) — installation and operating guidance.

## Monitoring quick start

1. Install PHP 8.1+ with `pdo_mysql` and MySQL 8+.
2. Import the database schema described in the website guide.
3. Configure `SOLARCOLD_DB_HOST`, `SOLARCOLD_DB_PORT`, `SOLARCOLD_DB_NAME`, `SOLARCOLD_DB_USER`, and `SOLARCOLD_DB_PASSWORD` in the web-server environment.
4. Set `SOLARCOLD_INGEST_TOKEN` and provide the same value from authorized devices through the `X-Ingest-Token` header.
5. Serve `monitoring/public` as the document root.

Never publish production credentials. Credentials formerly embedded in upstream examples should be considered compromised and rotated.

## Firmware quick start

Open `firmware/src/solar_cold_controller.ino` in the Arduino IDE. Verify the board, pin mapping, sensor addresses, APN, device ID, and deployment endpoint before flashing. Test against a staging service before connecting field hardware.

## Engineering standards

- Keep deployment secrets in environment variables or a managed secret store.
- Validate telemetry at the service boundary and use prepared database statements.
- Ship editable hardware source with fabrication outputs.
- Record field-affecting changes and their results under `system-testing`.

## Ownership and provenance

Adequate Infosoft maintains this distribution and owns its original branding, rewritten documentation, security hardening, configuration system, and subsequent contributions. Upstream components retain their original copyrights and licenses. See [NOTICE.md](./NOTICE.md) and [LICENSE](./LICENSE).

## Licenses

- Software and firmware: MIT, with existing notices retained.
- Hardware: CERN-OHL-S v2.0.
- Documentation: CC BY 4.0.
- Bundled third-party libraries: their respective included licenses.

