# IoT System PCB – Open Solar Cooling Hub using KiCAD

This repository contains the PCB design files for the IoT Monitoring System used in the Open Solar Cooling Hub, created and managed using **KiCAD**. The project includes schematics, PCB layout, fabrication files (Gerbers, drill files), assembly files (BOM, Pick & Place), and a 3D model for enclosure design. This guide explains how to open, modify, and produce the PCB using KiCAD.

---

## Prerequisites

1. **Install KiCAD**:
   - Download KiCAD 9.0.3 from [kicad.org](https://www.kicad.org/download/) for Windows, macOS, or Linux.
   - Install and launch KiCAD.
  
   - Application: KiCad x64 on x64

   - Libraries:
     	- wxWidgets 3.2.8
      - FreeType 2.13.3
      - HarfBuzz 10.2.0
      - FontConfig 2.15.0
      - libcurl/8.13.0-DEV Schannel zlib/1.3.1




2. **Required Files**:
   - `Solar Cooling Project.kicad_pro`: KiCAD project file.
   - `Solar Cooling Project.kicad_sch`: Schematic file.
   - `Solar Cooling Project.kicad_pcb`: PCB layout file.
   - Reference files :
     - Gerber files (`Solar Cooling Project-F_Cu.gbr`, `B_Cu.gbr`, etc.)
     - Drill files (`Solar Cooling Project-PTH.drl`, `NPTH.drl`)
     - BOM (`BOM_PartType-Open Solar Cooling Hub PCB Project.xlsx`)
     - Pick & Place (`Pick Place for IOT B oard FIle.txt`)
     - Assembly PDF (`Assembly.PDF`)
     - 3D model (`IOT B oard FIle.step`)

---

## Folder Structure and Content Description

The project follows standard hardware development practices, with files organized for PCB fabrication, assembly, and modification.

| Folder/File | Purpose |
|-------------|---------|
| `Gerber/` | PCB fabrication layers (copper, soldermask, silkscreen, etc.) |
| `NC Drill/` | Drill files for PTH and NPTH holes |
| `PCBA/` | Assembly files (BOM, Pick & Place, Assembly PDF) |
| `ExportSTEP/` | 3D STEP model for enclosure design |
| `Solar Cooling Project.kicad_pro` | KiCAD project file |
| `Solar Cooling Project.kicad_sch` | Schematic file |
| `Solar Cooling Project.kicad_pcb` | PCB layout file |
| `README.md` | Project documentation |

---

## How to Open and Modify the PCB Design in KiCAD

### 1. Open the Project
1. Launch KiCAD and open `Solar Cooling Project.kicad_pro` in the project manager.
2. This loads the schematic (`Solar Cooling Project.kicad_sch`) and PCB layout (`Solar Cooling Project.kicad_pcb`).

### 2. Edit the Schematic
1. Open the schematic editor (Eeschema) by clicking the schematic icon in the project manager.
2. Verify components, connections, and net labels against the original BOM and schematic reference .
3. **Modify **:
   - Add/remove components using KiCAD’s symbol libraries or create custom symbols.
   - Update net labels for clarity.
   - Assign footprints to each symbol via the “Assign Footprints” tool, ensuring compatibility with the BOM and Pick & Place file.
4. Generate a netlist (File > Export > Netlist) for PCB layout.

### 3. Edit the PCB Layout
1. Open the PCB editor (Pcbnew) by clicking the PCB icon in the project manager.
2. Import the netlist (File > Import > Netlist) to populate components.
3. **Validate Layout**:
   - Compare the board outline with `Solar Cooling Project-Edge_Cuts.gbr`.
   - Verify component placements using `Pick Place for IOT B oard FIle.txt` (import via File > Import > Placement File).
   - Check routing against Gerber files (`F_Cu.gbr`, `B_Cu.gbr`) using KiCAD’s Gerber Viewer (File > Import > Gerber Files).
4. **Modify (if needed)**:
   - Adjust component positions in Pcbnew.
   - Reroute traces to optimize the layout.
   - Update the board outline on the `Edge.Cuts` layer.
5. **Import Drill Files**:
   - Import `Solar Cooling Project-PTH.drl` and `NPTH.drl` (File > Import > Drill Files) to ensure correct via and hole placement.
6. **3D Verification**:
   - View the PCB in 3D (View > 3D Viewer) and compare with `IOT B oard FIle.step`.
   - Assign 3D models to footprints if needed (Footprint Properties > 3D Settings).

### 4. Generate Fabrication and Assembly Files
1. **Gerber Files**:
   - In Pcbnew, go to File > Plot.
   - Select layers: `F.Cu`, `B.Cu`, `F.Silkscreen`, `B.Silkscreen`, `F.Mask`, `B.Mask`, `Edge.Cuts`.
   - Output to a `Gerber/` folder.
   - Verify against original Gerbers using a Gerber viewer (e.g., KiCAD’s Gerber Viewer or Gerbv).
2. **Drill Files**:
   - In Pcbnew, go to File > Fabrication Outputs > Drill Files.
   - Generate Excellon drill files for PTH and NPTH.
   - Output to a `NC Drill/` folder.
3. **Bill of Materials (BOM)**:
   - In Eeschema, go to Tools > Generate Bill of Materials.
   - Export as CSV or XLSX to `PCBA/BOM.xlsx`.
   - Cross-check with `BOM_PartType-Open Solar Cooling Hub PCB Project.xlsx`.
4. **Pick & Place File**:
   - In Pcbnew, go to File > Fabrication Outputs > Component Placement File.
   - Output to `PCBA/Pick_Place.txt`.
   - Verify against `Pick Place for IOT B oard FIle.txt`.
5. **Assembly Drawing**:
   - In Pcbnew, go to File > Plot and export a PDF of the board layout to `PCBA/Assembly.pdf`.
6. **3D Model**:
   - In Pcbnew, go to File > Export > STEP.
   - Save to `ExportSTEP/Solar_Cooling_Project.step`.

### 5. Validate Outputs
- **Gerber Comparison**: Use a Gerber viewer to ensure KiCAD-generated Gerbers match the original Gerbers.
- **BOM and Pick & Place**: Confirm component lists and placements align with the original files.
- **Fabrication Test**: Send Gerber and drill files to a PCB manufacturer (e.g., JLCPCB) to verify acceptance.
- **Assembly Check**: Provide BOM, Pick & Place, and Assembly PDF to an SMT service for validation.

---

## How to Use the Outputs

- **Fabrication**: Send the `Gerber/` and `NC Drill/` folders to a PCB manufacturer e.g., JLCPCB, PCBWay.
- **Assembly**: Provide `PCBA/BOM.xlsx`, `PCBA/Pick_Place.txt`, and `PCBA/Assembly.pdf` to an SMT assembly service.
- **Modify/Rebuild**: Use `Solar Cooling Project.kicad_sch` and `.kicad_pcb` in KiCAD to edit the design and regenerate outputs.
- **Enclosure Design**: Use `ExportSTEP/Solar_Cooling_Project.step` in CAD tools like OpenSCAD or FreeCAD.

---

## Licensing

This project is licensed under the **CERN Open Hardware License v2.0**. Ensure all modifications and derivatives retain this license.


---
---
---
---
---




# 📦 Ordering Guide for Solar Cooling Hub PCB on JLCPCB

This document provides step-by-step instructions for ordering the **Solar Cooling Hub Project PCB** on [JLCPCB](https://jlcpcb.com) using the specified configuration.

---

## 1. Prepare Your Gerber File
- Put your project’s Gerber files folder and NCDrill files folder  in one zip folder and save it as SolarCoolingHub_Y60.zip.  
- File to upload: **SolarCoolingHub_Y60.zip**

---

## 2. Go to JLCPCB Website
- Visit: [https://jlcpcb.com](https://jlcpcb.com)  
- Log in or create an account.

---

## 3. Upload Your Gerber File
- Click **“Order Now”** or **“Quote Now”**.  
- Upload **SolarCoolingHub_Y60.zip**.  
- Confirm that the system correctly identifies the board dimensions.

---

## 4. Configure PCB Parameters

| Parameter | Value |
|-----------|-------|
| **Build Time** | 3 days |
| **Base Material** | FR-4 |
| **Layers** | 2 |
| **Dimension** | 166 mm × 173 mm |
| **PCB Qty** | 5 |
| **Product Type** | Industrial/Consumer electronics |
| **Different Design** | 1 |
| **Delivery Format** | Single PCB |
| **PCB Thickness** | 1.6 mm |
| **Specify Stackup** | No |
| **Layer Sequence** | Default |
| **PCB Color** | Yellow |
| **Silkscreen** | White |
| **Material Type** | FR4-Standard TG 135–140 |
| **Via Covering** | Tented |
| **Surface Finish** | HASL (with lead) |
| **Deburring/Edge rounding** | No |
| **Outer Copper Weight** | 1 oz |
| **Gold Fingers** | No |
| **Electrical Test** | Flying Probe Fully Test |
| **Castellated Holes** | No |
| **Edge Plating** | No |
| **Mark on PCB** | Remove Mark |
| **Blind Slot** | No |
| **Min via hole size/diameter** | 0.3 mm (0.4/0.45 mm) |
| **4-Wire Kelvin Test** | No |
| **Paper between PCBs** | No |
| **Appearance Quality** | IPC Class 2 Standard |
| **Confirm Production File** | No |
| **Silkscreen Technology** | Ink-jet/Screen Printing |
| **Package Box** | With JLCPCB logo |
| **Inspection Report** | No |
| **Board Outline Tolerance** | ±0.2 mm (Regular) |
| **UL Marking** | No |
| **Countersink Hole** | No |

---

## 5. Review & Confirm
- Verify all parameters match your project’s requirements.  
- Use the online preview tool to confirm the board outline.

---

## 6. Add to Cart
- Click **“Save to Cart”**.  

---

## 7. Choose Shipping Method
- Select your preferred courier. Choose from DHL, FedEx, or other shipping methods.

---

## 8. Make Payment
- Proceed to checkout and pay. Choose from PayPal or credit card.

---

## 9. Track Production
- Monitor progress in your JLCPCB dashboard:  
  *In Production → Finished → Shipped*

---

✅ In **3 days build time + shipping**, you will receive **5 Yellow Solar Cooling Hub PCBs** built to the above exact specifications.


