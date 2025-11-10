# Bill of Materials (BOM)

Complete parts list for building your own Aria Art Plotter.

## 📋 Available Formats

- **[BOM.md](BOM.md)** - Main version, human-readable with organized categories
- **[BOM.xlsx](BOM.xlsx)** - Excel spreadsheet with clickable links and pricing
- **[BOM.csv](BOM.csv)** - Machine-readable format for importing

## 💰 Cost Summary

| Category | Estimated Cost |
|----------|----------------|
| Electronics | $200-250 |
| Motion Hardware | $120-150 |
| Fasteners | $40-60 |
| Extrusion & Frame | $60-80 |
| Materials & Misc | $30-50 |
| **Total** | **$450-550** |

*Prices as of November 2025, subject to market variation*

## 🛠️ Build Requirements

- **Build Time:** 20-40 hours
- **Skill Level:** Intermediate
- **3D Printing:** ~2.5kg filament (PETG or ABS recommended)
- **Tools Required:** 
  - Allen key set (metric)
  - Crimping tool (often included with JST kits)
  - Wire strippers
  - Screwdrivers
  - Measuring tape

## 📦 Sourcing Options

### Option 1: Amazon (USA)
- Fast shipping (Prime eligible items)
- Easy returns
- Links in BOM are affiliated (supports v2.0 development)
- No extra cost to you

### Option 2: AliExpress (Worldwide)
- 30-50% cost savings on electronics
- Longer shipping times (2-6 weeks)
- Bulk component availability
- Great for international builders

### Option 3: Direct from Manufacturers
- **BIGTREETECH:** Official store for Manta, CB1, TMC2209
- **BIQU:** Official store for MicroProbe
- **Mean Well:** Official distributors for power supplies

### Option 4: Local Hardware Stores
- Generic fasteners (M3, M5 bolts/nuts)
- Wire and cables
- Zip ties and cable management
- Heat shrink tubing

## 🔍 Component Notes

### Critical Components (Don't Substitute)
- BIGTREETECH Manta M5P (firmware optimized for this board)
- TMC2209 stepper drivers (silent operation, UART mode)
- MGN9 linear rails (precision critical)
- Mean Well LRS-350-24 PSU (reliable 24V power)

### Flexible Components (Substitution OK)
- Generic fasteners (M3/M5 hardware)
- Wire/cables (as long as gauge matches)
- Drag chains (similar dimensions work)
- Zip ties and cable management

### Optional Components
- Rubber band (if not using spring mechanism)
- Expanded sleeving (aesthetic wire management)
- AC wiring (if not using included power cord)

## 📐 Aluminum Extrusion Cut List

For 500mm × 500mm (20" × 20") plotter (Check the Manual for any updates):

| Quantity | Length | Purpose |
|----------|--------|---------|
| 2 | 660mm | X-axis frame sides |
| 2 | 620mm | Y-axis frame sides |
| 2 | 660mm | Z-axis verticals |
| 2 | 540mm | Gantry rails |
| 1 | 620mm | Pen assembly rail |

**Total required:** 6 meters (20 feet)  
**Recommendation:** Order 7-8 meters for practice cuts and mistakes

## 🧵 3D Printed Parts

All STL files available in [`/STL/`](../STL/) directory.

**Filament Requirements:**
- Total weight: ~2.5kg
- Recommended: PETG (durability) or ABS (rigidity)
- Alternative: PLA+ (budget option, less durable)

**Print Settings:**
- Layer height: 0.2mm
- Infill: 20-30%
- Supports: Required for some parts (see assembly guide)
- Bed adhesion: Recommended for ABS

See [Assembly Guide](../docs/AriaArtPlotterAssemblyManual.pdf) for part-by-part print orientations.

## ⚡ Wiring Requirements

### Cable Lengths (minimum)
- Stepper motors: 30 ft (22 AWG 4-conductor)
- Limit switches: 21 ft (22 AWG 2-conductor)
- Probe: 9 ft (22 AWG 5-conductor)
- DC power: 10 ft (18 AWG red/black)
- AC power (optional): 6 ft (14 AWG)

**Tip:** Buy extra wire (Amazon links includes extras)- it's cheaper than running short mid-build!

## 🔧 Assembly Sections Reference

The BOM is organized to match the assembly guide sections:

1. **Electronics** Components and Wiring 
2. **Hardware:** Motion System and Frame (Rails, belts, wheels)
3. **Fasteners** Complete list of what you need
4. **Additional Materials:** Wiring Management etc.


## 🌍 International Builders

### Voltage Considerations
- Power supply is universal input (110-240V)
- AC power cord may need regional adapter
- Check local electrical codes

### Metric vs Imperial
- All fasteners are metric (M3, M4, M5)
- Extrusions are 2020 profile (20mm × 20mm)
- Some US suppliers list in inches (conversions provided)

## 💡 Money-Saving Tips

1. **Buy hardware kits suggested** instead of individual fasteners (Amazon links)
2. **Source extrusions locally** (cheaper than shipping)
3. **Print your own drag chains** (STLs available online)
4. **Use AliExpress for electronics** if timeline permits
5. **Buy generic crimps** instead of branded (same quality)
6. **Check for BIQU/BTT sales** (frequent promotions)
7. **Join group buys** in maker communities

## 🆘 BOM Support

### Something Missing?
Open an issue: [GitHub Issues](https://github.com/gustavomayoral/aria_art_plot/issues)

### Found a Better Alternative?
Submit a pull request with:
- Component name
- Alternative part number
- Why it's better/cheaper
- Compatibility notes

### Questions About Sourcing?
- Check the [Discussions](https://github.com/gustavomayoral/aria_art_plot/discussions)
- Join community Discord (we are woring on it)
- Tag your question with `#bom` or `#sourcing`

## 🤝 Contributing

Help improve this BOM:
- Add alternative suppliers for your region
- Update pricing information
- Report broken/changed links
- Suggest better component alternatives
- Translate for international builders

See [CONTRIBUTING.md](../CONTRIBUTING.md) for guidelines.

## 📜 Affiliate Disclosure

Amazon links in this BOM are affiliated. This means:
- ✅ You pay the same price
- ✅ I receive a small commission (~3-5%)
- ✅ Funds support Version 2.0 development
- ✅ All design files remain 100% free

**You are never required to use affiliate links.** Full component specifications are provided so you can source anywhere.

## ☕ Support This Project

If this BOM helped you save time or money:
- [Buy me a coffee](https://ko-fi.com/ariaartplot)
- Star this repository
- Share with the maker community
- Contribute improvements

---

**Last Updated:** November 2025  
**BOM Version:** 1.0  
**Compatible with:** Aria Art Plotter v1.0
