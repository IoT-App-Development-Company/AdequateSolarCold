<?php
declare(strict_types=1);
const SITE_NAME = 'Adequate SolarCold Operations';
?>
<!doctype html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="description" content="Adequate Infosoft cold-chain telemetry operations portal">
    <title><?= htmlspecialchars(SITE_NAME, ENT_QUOTES, 'UTF-8') ?></title>
    <style>
        :root { color-scheme: dark; --ink:#eefbf4; --muted:#a8c4b7; --brand:#58d68d; --panel:#102a23; }
        * { box-sizing:border-box; }
        body { margin:0; min-height:100vh; display:grid; place-items:center; padding:24px; font:16px/1.6 system-ui,sans-serif; color:var(--ink); background:radial-gradient(circle at top left,#174d3a,#071713 65%); }
        main { width:min(760px,100%); padding:clamp(28px,6vw,64px); border:1px solid #2d5a49; border-radius:24px; background:rgba(16,42,35,.88); box-shadow:0 24px 80px #0008; }
        .eyebrow { color:var(--brand); font-weight:700; letter-spacing:.12em; text-transform:uppercase; }
        h1 { margin:.25rem 0 1rem; font-size:clamp(2rem,7vw,4.5rem); line-height:1; }
        p { color:var(--muted); max-width:58ch; }
        a { display:inline-block; margin-top:20px; padding:12px 18px; border-radius:999px; color:#062017; background:var(--brand); text-decoration:none; font-weight:750; }
        a:focus-visible { outline:3px solid white; outline-offset:4px; }
    </style>
</head>
<body>
<main>
    <div class="eyebrow">Adequate Infosoft</div>
    <h1>SolarCold Operations</h1>
    <p>Field telemetry for reliable, energy-aware cold-chain operations. Review sensor health, room conditions, and electrical readings from one operational view.</p>
    <a href="dashboard.php">Open telemetry dashboard</a>
</main>
</body>
</html>

