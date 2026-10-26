# Adequate SolarCold controller firmware

The controller firmware reads DHT22 and MLX90614 sensor arrays, collects electrical measurements, controls configured relays, and submits telemetry to the monitoring service.

## Target

- Arduino Mega-class board with `Serial3`
- DHT22 sensor array
- MLX90614 infrared temperature sensors with deployment-specific I²C addresses
- Compatible GSM/GPRS modem

## Configure before flashing

Edit the deployment constants near the top of `src/solar_cold_controller.ino`:

- `DEVICE_ID`
- `TELEMETRY_ENDPOINT`
- `MOBILE_APN`

Verify sensor pins, I²C addresses, relay behavior, serial baud rates, and carrier requirements. The example endpoint intentionally uses `.invalid` and cannot transmit until configured.

## Commissioning

1. Compile for the exact board and library versions.
2. Test sensor failure and out-of-range behavior.
3. Verify relay outputs with loads disconnected.
4. Confirm the server rejects malformed or unauthenticated telemetry.
5. Compare every sensor against a calibrated reference.
6. Record the firmware version and test result in `system-testing`.

Bundled libraries retain their respective upstream notices and licenses.
