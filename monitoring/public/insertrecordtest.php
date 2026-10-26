<?php
declare(strict_types=1);
http_response_code(410);
header('Content-Type: application/json; charset=utf-8');
echo json_encode([
    'error' => 'The database-writing test endpoint was removed. Use automated tests with an isolated test database.',
]);

