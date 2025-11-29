# UI XML Files

This directory contains XML-based UI definitions for the CNC Pendant screens.

## Structure

- `project.xml` - Project-level configuration (display size, targets)
- `globals.xml` - Global definitions (colors, styles, fonts, images, API enums)
- `screens/` - Individual screen definitions

## Screen Files

- `main.xml` - Main jog/DRO screen with axis position display
- `macros.xml` - Macro commands screen with preset buttons
- `setup.xml` - Setup/settings screen

## XML Format

The XML format follows the LVGL Editor structure:

```xml
<screen name="screen_name">
    <styles>
        <!-- Define local styles -->
    </styles>
    
    <view>
        <!-- UI elements hierarchy -->
    </view>
</screen>
```

## Generating C Code

Use the XML to C generator script:

```bash
python scripts/xml_to_c.py ui/xml/screens/main.xml ui/generated/
```

This will generate:
- `main_screen_gen.h` - Header file
- `main_screen_gen.c` - Implementation file

## Reference

For more information on the XML format, see:
https://github.com/lvgl/lvgl_editor
