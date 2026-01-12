# CLAUDE.md

## Project Overview

ESP32-S3 win button prop for the Christmas Red Rider room. Plays victory audio when button is pressed.

**Target Board:** ESP32-S3-DevKitC-1 (N8R2: 8MB Flash, 2MB PSRAM)

## Build Commands

```bash
pio run                    # Build
pio run --target upload    # Upload to ESP32-S3
pio run --target clean     # Clean build
pio device monitor         # Serial monitor (115200 baud)
```

## Architecture

### Code Flow
```
main.cpp          → setup() and loop(), button polling
└── AudioPlayer.cpp → DY-HV8F UART control
```

### Key Components
- **Button Input**: GPIO32 with internal pull-up, debounced
- **AudioPlayer**: DY-HV8F control via UART2

### Configuration
All settings in `src/config.h`:
- `BUTTON_PIN` - GPIO for button (32)
- `BUTTON_DEBOUNCE_MS` - Debounce delay (50ms)
- `DYPLAYER_*` - Audio player pins and settings
- `WIN_TRACK` - Track to play on press

## ESP32-S3 Notes

- GPIO32 supports input with internal pull-up
- Different GPIO numbering than ESP32
- Verify UART pins for S3 variant
