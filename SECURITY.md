# Security policy

Report suspected vulnerabilities privately through Adequate Infosoft's established support channel. Do not include credentials, customer data, or exploitable telemetry endpoints in a public report.

## Deployment baseline

- Rotate any credential that has appeared in source code.
- Keep database and ingestion secrets in the server environment.
- Terminate TLS at the web server or reverse proxy.
- Restrict database access to the application host.
- Disable PHP error display in production and use protected logs.
- Require `SOLARCOLD_INGEST_TOKEN` on field deployments.
- Back up the database and test restoration before going live.

