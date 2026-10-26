// --- Parameters ---
board_size = [174.88, 153.67, 13.84]; // Measured from STL
margin = 5;
wall = 3;
base_height = 5;
cover_thickness = 3;
hole_width = 10;
hole_height = 4;
hole_spacing = 5;
radius = 6;  // Rounded corner radius
screw_hole_dia = 3;
vent_hole_dia = 4;

// --- Exploded view distances ---
explode_cover = 60;    // Raise top cover + labels
explode_board = 35;    // Raise board

// --- Derived dimensions ---
case_x = board_size[0] + 2 * margin;
case_y = board_size[1] + 2 * margin;
case_z = board_size[2] + base_height + wall;
stl_offset = [-22.61, -11.68, 3.5]; // To align STL at base

// --- Main casing with rounded corners ---
module casing_body() {
    color("lightgray")  // base casing color
    difference() {
        // Rounded box
        minkowski() {
            cube([case_x - 2*radius, case_y - 2*radius, case_z - cover_thickness], center=false);
            translate([radius, radius, 0])
                cylinder(h=0.5, r=radius, $fn=50);  // safer height
        }

        // Hollow inner cavity
        translate([margin, margin, base_height + 2])
            cube(board_size);

        // --- 5 front holes (X=0 side) ---
        for (i = [0:4]) {
            translate([
                -0.01, margin + i * (hole_width + hole_spacing), base_height + 3
            ])
                cube([wall + 0.02, hole_width, hole_height]);
        }

        // --- 2 side holes (Y=0 side) ---
        for (i = [0:1]) {
            translate([
                margin + i * (hole_width + hole_spacing), -0.01, base_height + 3
            ])
                cube([hole_width, wall + 0.02, hole_height]);
        }

        // --- 1 back hole (Y=max side) ---
        translate([
            (case_x - hole_width) / 2, case_y - wall - 0.01, base_height + 3
        ])
            cube([hole_width, wall + 0.02, hole_height]);

        // --- Screw holes (top corners) ---
        for (x = [5, case_x - 5])
            for (y = [5, case_y - 5])
                translate([x, y, case_z - cover_thickness])
                    cylinder(h = 10, r = screw_hole_dia / 2, $fn = 30);
    }
}

// --- Top Cover with screw holes ---
module top_cover() {
    color("blue")  // top cover color
    difference() {
        translate([0, 0, case_z - cover_thickness])
            minkowski() {
                cube([case_x - 2*radius, case_y - 2*radius, cover_thickness], center=false);
                translate([radius, radius, 0])
                    cylinder(h=0.5, r=radius, $fn=50);  // fixed height
            }

        // Screw holes
        for (x = [5, case_x - 5])
            for (y = [5, case_y - 5])
                translate([x, y, case_z - cover_thickness - 1])
                    cylinder(h = 10, r = screw_hole_dia / 2, $fn = 30);
    }
}

// --- Label Text and Vent Holes ---
module label_and_vents() {
    // Labels
    color("green") {
        translate([10, case_y/2 + 30, case_z - 2])
            linear_extrude(height = 3.5)
                text("      SOLAR COOLING HUB", size = 8, font = "Arial", halign="left");

        translate([10, case_y/2 + 10, case_z - 2])
            linear_extrude(height = 3.5)
                text(" BY MUNAKYALO AGROFRESH", size = 8, font = "Arial", halign="left");

        translate([10, case_y/2 - 10, case_z - 2])
            linear_extrude(height = 3.5)
                text("                ENACCESS", size = 8, font = "Arial", halign="left");
    }

    // Vent holes
    color("black")
    for (x = [case_x/2 - 15, case_x/2 - 5, case_x/2 + 5, case_x/2 + 15])
        for (y = [15, 25, 35])
            translate([x, y, case_z - 2])
                cylinder(h = 2, r = vent_hole_dia / 2, $fn=30);
}

// --- Assembly (Exploded View) ---

// Base casing (fixed)
casing_body();

// Top cover exploded up
translate([0, 0, explode_cover])
    top_cover();

// Labels & vents go with the cover
translate([0, 0, explode_cover])
    label_and_vents();

// Board exploded up
color("red")  // board STL color
translate([margin, margin, base_height + explode_board])
    translate(stl_offset)
        import("IOT B oard FIle.stl");
