-- Adequate SolarCold telemetry schema
-- Apply this schema to an empty MySQL 8+ or compatible MariaDB database.

CREATE TABLE IF NOT EXISTS ColdRoomMonitor (
    id BIGINT UNSIGNED NOT NULL AUTO_INCREMENT,
    device_id VARCHAR(64) NOT NULL,
    dht_humidity VARCHAR(255) NOT NULL,
    dht_room_temp VARCHAR(255) NOT NULL,
    mlx_object_temp VARCHAR(255) NOT NULL,
    mlx_room_temp VARCHAR(255) NOT NULL,
    voltage DECIMAL(10,3) NOT NULL,
    current DECIMAL(10,3) NOT NULL,
    time_stamp DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    PRIMARY KEY (id),
    INDEX idx_coldroom_device_time (device_id, time_stamp),
    INDEX idx_coldroom_time (time_stamp)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
