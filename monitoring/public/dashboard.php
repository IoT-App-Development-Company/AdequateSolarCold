<!doctype html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="description" content="Adequate SolarCold telemetry dashboard">
    <title>SolarCold telemetry | Adequate Infosoft</title>
    <script src="https://cdn.jsdelivr.net/npm/chart.js@4.4.7/dist/chart.umd.min.js"></script>
    <style>
        :root { --bg:#071713; --panel:#102a23; --line:#285445; --text:#eefbf4; --muted:#9dbbad; --green:#58d68d; --cyan:#55c5d8; --amber:#f4bf5f; --red:#f07178; }
        * { box-sizing:border-box; }
        body { margin:0; font:15px/1.5 system-ui,sans-serif; color:var(--text); background:var(--bg); }
        header, main { width:min(1180px,calc(100% - 32px)); margin:auto; }
        header { display:flex; justify-content:space-between; gap:20px; align-items:end; padding:36px 0 22px; border-bottom:1px solid var(--line); }
        .brand { color:var(--green); font-weight:800; letter-spacing:.12em; text-transform:uppercase; }
        h1,h2 { margin:.2rem 0; }
        .status { color:var(--muted); text-align:right; }
        main { padding:28px 0 56px; }
        .cards { display:grid; grid-template-columns:repeat(auto-fit,minmax(180px,1fr)); gap:14px; margin:18px 0 32px; }
        .card,.chart-panel,.sensor { border:1px solid var(--line); background:var(--panel); border-radius:16px; }
        .card { padding:18px; }
        .label { color:var(--muted); font-size:.84rem; }
        .value { margin-top:5px; font-size:1.65rem; font-weight:750; overflow-wrap:anywhere; }
        .sensor-grid { display:grid; grid-template-columns:repeat(auto-fit,minmax(180px,1fr)); gap:12px; margin:18px 0 32px; }
        .sensor { padding:15px; }
        .sensor strong { color:var(--green); }
        .sensor dl { display:grid; grid-template-columns:1fr auto; gap:4px 12px; margin:10px 0 0; }
        .sensor dt { color:var(--muted); }
        .sensor dd { margin:0; }
        .chart-panel { padding:18px; min-height:360px; }
        .error { color:#ffd4d6; border-color:#7c3034; background:#3b191c; }
        @media (max-width:650px) { header { align-items:start; flex-direction:column; } .status { text-align:left; } }
    </style>
</head>
<body>
<header>
    <div><div class="brand">Adequate Infosoft</div><h1>SolarCold telemetry</h1></div>
    <div class="status"><div id="connection">Connecting…</div><div id="updated"></div></div>
</header>
<main>
    <h2>Latest operating summary</h2>
    <section id="cards" class="cards" aria-live="polite"></section>
    <h2>Sensor array</h2>
    <section id="sensors" class="sensor-grid"></section>
    <h2>Current sensor profile</h2>
    <section class="chart-panel"><canvas id="chart"></canvas></section>
</main>
<script>
(() => {
    'use strict';
    const cards = document.querySelector('#cards');
    const sensors = document.querySelector('#sensors');
    const connection = document.querySelector('#connection');
    const updated = document.querySelector('#updated');
    let chart;

    const parseSeries = value => String(value ?? '').split(',').map(Number).filter(Number.isFinite);
    const average = values => values.length ? values.reduce((sum, value) => sum + value, 0) / values.length : null;
    const display = (value, suffix = '') => Number.isFinite(value) ? `${value.toFixed(2)}${suffix}` : 'Unavailable';

    function render(row) {
        const humidity = parseSeries(row.dht_humidity);
        const roomTemperature = parseSeries(row.dht_room_temp);
        const objectTemperature = parseSeries(row.mlx_object_temp);
        const ambientTemperature = parseSeries(row.mlx_room_temp);
        const summary = [
            ['Device', String(row.device_id ?? 'Unknown')],
            ['Humidity', display(average(humidity), '%')],
            ['Room temperature', display(average(roomTemperature), ' °C')],
            ['Object temperature', display(average(objectTemperature), ' °C')],
            ['Voltage', display(Number(row.voltage), ' V')],
            ['Current', display(Number(row.current), ' A')]
        ];
        cards.replaceChildren(...summary.map(([label, value]) => {
            const card = document.createElement('article');
            card.className = 'card';
            const labelNode = document.createElement('div');
            labelNode.className = 'label';
            labelNode.textContent = label;
            const valueNode = document.createElement('div');
            valueNode.className = 'value';
            valueNode.textContent = value;
            card.append(labelNode, valueNode);
            return card;
        }));

        const count = Math.max(humidity.length, roomTemperature.length, objectTemperature.length, ambientTemperature.length);
        sensors.replaceChildren(...Array.from({ length: count }, (_, index) => {
            const node = document.createElement('article');
            node.className = 'sensor';
            const title = document.createElement('strong');
            title.textContent = `Sensor ${index + 1}`;
            const list = document.createElement('dl');
            [['Humidity', display(humidity[index], '%')], ['Room', display(roomTemperature[index], ' °C')], ['Object', display(objectTemperature[index], ' °C')], ['Ambient', display(ambientTemperature[index], ' °C')]].forEach(([term, value]) => {
                const dt = document.createElement('dt'); dt.textContent = term;
                const dd = document.createElement('dd'); dd.textContent = value;
                list.append(dt, dd);
            });
            node.append(title, list);
            return node;
        }));

        if (chart) chart.destroy();
        chart = new Chart(document.querySelector('#chart'), {
            type: 'line',
            data: {
                labels: Array.from({ length: count }, (_, index) => `S${index + 1}`),
                datasets: [
                    { label:'Humidity (%)', data:humidity, borderColor:'#55c5d8' },
                    { label:'Room (°C)', data:roomTemperature, borderColor:'#58d68d' },
                    { label:'Object (°C)', data:objectTemperature, borderColor:'#f07178' },
                    { label:'Ambient (°C)', data:ambientTemperature, borderColor:'#f4bf5f' }
                ]
            },
            options: { responsive:true, maintainAspectRatio:false, animation:false, plugins:{ legend:{ labels:{ color:'#eefbf4' } } }, scales:{ x:{ ticks:{ color:'#9dbbad' }, grid:{ color:'#285445' } }, y:{ ticks:{ color:'#9dbbad' }, grid:{ color:'#285445' } } } }
        });
        updated.textContent = `Recorded ${new Date(row.time_stamp).toLocaleString()}`;
    }

    async function refresh() {
        try {
            const response = await fetch('fetch_data.php?limit=1', { headers:{ Accept:'application/json' }, cache:'no-store' });
            const payload = await response.json();
            if (!response.ok) throw new Error(payload.error || 'Request failed');
            if (!payload.data?.length) throw new Error('No telemetry has been recorded');
            render(payload.data[0]);
            connection.textContent = 'Live · refreshes every 15 seconds';
            connection.className = '';
        } catch (error) {
            connection.textContent = error.message;
            connection.className = 'error';
        }
    }
    refresh();
    setInterval(refresh, 15000);
})();
</script>
</body>
</html>
