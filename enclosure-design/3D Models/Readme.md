## 🧱 IOT Casing Design (OpenSCAD)

### 📂 SCAD Files Overview

This directory contains the OpenSCAD source files used to design the casing for the IoT system. :

| File Name             | Purpose                                                                 |
|-----------------------|-------------------------------------------------------------------------|
| `IOT Casing 3.scad`     | ✅ Final version used in the actual system enclosure.                    |


---

### 🏗️ Design Rules

The casing was designed in OpenSCAD following these guidelines:

- **Board Size**: `[174.88, 153.67, 13.84]` mm
- **Wall Thickness**: `3 mm` – to ensure strength and printability
- **Cover Thickness**: `3 mm` – strong enough to hold shape without warping
- **Margin**: `5 mm` around the board for airflow and tolerances
- **Rounded Corners**: `6 mm` radius for aesthetics and safety


---

### 🛠️ Manufacturing Method

The casing is designed specifically for **Fused Deposition Modeling (FDM)** 3D printing.

**Recommended Print Settings:**
- **Material**: PLA or PETG
- **Layer Height**: 0.2 mm
- **Infill**: 20%–30%
- **Supports**: Not required for the base; may be required for cover 
- **Print Bed Size**: At least 200 mm x 200 mm


---

### 🧪 Reproduction Instructions

1. Open `IOT Casing 3.scad` using [OpenSCAD](https://openscad.org/).
2. Adjust the parameters at the top of the file if needed (e.g., board size).
3. Render the model (`F6`) and export the STL file (`File → Export → Export as STL`).
4. Open the STL file in a slicer like Cura or PrusaSlicer.
5. Set print settings as per the above recommendation.
6. Print the casing using a 3D printer.
7. Assemble your electronics inside the enclosure using the screw posts and spacing provided.

---

### 🔐 Licensing

The SCAD design files are licensed under the **CERN Open Hardware License v2.0**.

You are free to:
- Use and reproduce the design
- Modify it for your needs
- Share your changes under the same license

---
