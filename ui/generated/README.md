# Generated UI Code

This directory contains auto-generated C code from XML UI definitions.

**DO NOT EDIT THESE FILES MANUALLY**

These files are generated using the `scripts/xml_to_c.py` script from the XML definitions in `ui/xml/`.

## Files

- `main_screen_gen.h/c` - Generated from `ui/xml/screens/main.xml`
- `macros_screen_gen.h/c` - Generated from `ui/xml/screens/macros.xml`
- `setup_screen_gen.h/c` - Generated from `ui/xml/screens/setup.xml`

## Regenerating Files

If you modify the XML definitions, regenerate the C code:

```bash
cd scripts
python xml_to_c.py ../ui/xml/screens/main.xml ../ui/generated/
python xml_to_c.py ../ui/xml/screens/macros.xml ../ui/generated/
python xml_to_c.py ../ui/xml/screens/setup.xml ../ui/generated/
```

Or use a build script if provided.

## Current Status

The files in this directory are currently hand-written stubs to demonstrate the structure.
The `xml_to_c.py` script is also a stub and needs full implementation.

For a complete implementation, refer to the LVGL Editor project.
