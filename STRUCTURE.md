# ESP32 CNC Pendant UI - Project Structure

This document provides a complete overview of the project structure.

## Directory Tree

```
ESP32-Pendant-UI/
├── .gitignore                      # Git ignore rules
├── platformio.ini                  # PlatformIO configuration for ESP32-S3
├── README.md                       # Main project documentation
├── STRUCTURE.md                    # This file
│
├── include/                        # Public header files
│   ├── lv_conf.h                  # LVGL 8.3 configuration
│   └── ui_api.h                   # Public UI API header
│
├── src/                           # Application source code
│   ├── main.cpp                   # Main entry point with LVGL init
│   └── ui_api.c                   # Public UI API implementation
│
├── ui/                            # UI definition and generated code
│   │
│   ├── xml/                       # XML-based UI definitions
│   │   ├── README.md             # XML format documentation
│   │   ├── project.xml           # Project configuration (480x480 display)
│   │   ├── globals.xml           # Global styles, colors, fonts, API
│   │   │
│   │   ├── screens/              # Screen definitions
│   │   │   ├── main.xml          # Main jog/DRO screen
│   │   │   ├── macros.xml        # Macro commands screen
│   │   │   └── setup.xml         # Setup/settings screen
│   │   │
│   │   └── components/           # Reusable UI components (future)
│   │
│   └── generated/                # Auto-generated C code from XML
│       ├── README.md             # Generation instructions
│       ├── main_screen_gen.h     # Main screen header
│       ├── main_screen_gen.c     # Main screen implementation
│       ├── macros_screen_gen.h   # Macros screen header
│       ├── macros_screen_gen.c   # Macros screen implementation
│       ├── setup_screen_gen.h    # Setup screen header
│       └── setup_screen_gen.c    # Setup screen implementation
│
├── scripts/                       # Build and generator scripts
│   └── xml_to_c.py               # XML to C code generator (stub)
│
├── fonts/                        # Custom fonts (currently empty)
├── images/                       # Images and icons (currently empty)
└── lib/                          # Additional libraries (currently empty)
```

## Key Files Description

### Configuration Files

- **platformio.ini**: PlatformIO project configuration
  - Target: ESP32-S3 DevKitC-1
  - Framework: Arduino
  - Libraries: LVGL 8.3, TFT_eSPI
  - Build flags for display configuration

- **include/lv_conf.h**: LVGL configuration
  - Color depth: 16-bit (RGB565)
  - Memory: 48KB
  - Display: 480x480
  - Enabled widgets: buttons, sliders, labels, etc.
  - Flex and grid layouts enabled

### Application Code

- **src/main.cpp**: Main application entry
  - LVGL initialization
  - Display driver setup (stub)
  - Touch input setup (stub)
  - Rotary encoder setup
  - Main loop with UI updates
  - Example callbacks for demo

- **src/ui_api.c**: Public API implementation
  - Screen management
  - Position updates
  - Status message handling
  - Callback routing
  - Encoder input processing

- **include/ui_api.h**: Public API header
  - Screen enum (MAIN, MACROS, SETUP)
  - Axis enum (X, Y, Z, A)
  - Function prototypes
  - Callback type definitions

### UI Definition (XML)

- **ui/xml/project.xml**: Project configuration
  - Display size: 480x480
  - Target: esp32_s3_round_display

- **ui/xml/globals.xml**: Global definitions
  - Color palette (primary, secondary, accent, warning, danger)
  - Spacing units (xs, sm, md, lg, xl)
  - Opacity values
  - Styles (screen_base, panel, button_primary, button_danger)
  - Subjects (state variables for data binding)
  - Images and fonts placeholders

- **ui/xml/screens/main.xml**: Main jog screen
  - Header with title
  - DRO panels for X, Y, Z axes
  - Control buttons (ZERO, MACRO)
  - Status bar
  - Dark theme with green accents

- **ui/xml/screens/macros.xml**: Macro commands screen
  - Header with title
  - 3x2 grid of macro buttons:
    - PROBE Z, HOME ALL
    - ZERO XY, ZERO Z
    - GOTO ZERO, UNLOCK
  - Back button
  - Status bar

- **ui/xml/screens/setup.xml**: Setup screen
  - Header with title
  - Settings panels:
    - Jog Speed slider
    - Feed Override slider
    - Display Brightness slider
    - Connection status
  - Save and Back buttons
  - Status bar

### Generated Code

- **ui/generated/*_screen_gen.h**: Generated headers
  - Widget creation functions
  - Update functions
  - Callback type definitions

- **ui/generated/*_screen_gen.c**: Generated implementations
  - LVGL widget creation code
  - Style application
  - Layout setup
  - Event handlers

### Scripts

- **scripts/xml_to_c.py**: XML to C generator
  - Parses XML screen definitions
  - Generates C header and source files
  - Command line tool
  - Currently a stub (needs full implementation)

## File Count Summary

```
Configuration: 2 files (platformio.ini, lv_conf.h)
Headers:       4 files (ui_api.h, 3x *_gen.h)
Source:        4 files (main.cpp, ui_api.c, 3x *_gen.c)
XML:           5 files (project, globals, 3x screens)
Scripts:       1 file (xml_to_c.py)
Documentation: 4 files (README.md, STRUCTURE.md, 2x ui READMEs)
```

## Build Artifacts (Ignored)

The following are generated during build and ignored by Git:

```
.pio/                   # PlatformIO build artifacts
.vscode/                # VS Code settings
*.o, *.elf, *.bin       # Compiled binaries
__pycache__/            # Python cache
```

## Usage Flow

1. **Define UI**: Edit XML files in `ui/xml/screens/`
2. **Generate Code**: Run `xml_to_c.py` to create C files
3. **Build**: Use PlatformIO to compile
4. **Upload**: Flash to ESP32-S3
5. **Test**: Interact with touch LCD and encoder

## Integration Points

### For UI Development
- Modify XML in `ui/xml/`
- Edit styles in `globals.xml`
- Add new screens in `screens/`

### For Application Development
- Use functions from `ui_api.h`
- Set callbacks for user events
- Update positions from CNC controller
- Display status messages

### For Hardware Integration
- Implement display driver in `main.cpp`
- Implement touch driver in `main.cpp`
- Configure pins in `main.cpp`
- Add custom widgets as needed

## Dependencies

### External Libraries (via PlatformIO)
- lvgl/lvgl@^8.3.0
- bodmer/TFT_eSPI@^2.5.0

### Build Tools
- PlatformIO Core
- Python 3.6+ (for code generator)
- ESP32 toolchain (installed by PlatformIO)

## Notes

- This is a UI-only project (no machine control)
- XML generator is a stub (refer to LVGL Editor for full implementation)
- Display and touch drivers need hardware-specific implementation
- Current generated C files are hand-written examples

## References

See README.md for:
- Getting started guide
- API usage examples
- Hardware requirements
- Troubleshooting
- External links
