# Red Rider Win Button

ESP32-S3 win button prop for the Christmas Red Rider escape room. Simple button trigger that plays a victory sound when pressed.

## Hardware

- **Board**: ESP32-S3-DevKitC-1 (N8R2: 8MB Flash, 2MB PSRAM)
- **Audio**: DY-HV8F MP3 player module
- **Input**: Momentary button

## Features

- **Button Trigger**: Debounced button input with internal pull-up
- **Victory Audio**: Plays win sound on button press
- **Simple Design**: Minimal code for reliable operation

## Quick Start

```bash
pio run                    # Build
pio run --target upload    # Upload via USB
pio device monitor         # Serial output (115200 baud)
```

## Wiring

### Button
| Connection | Pin |
|------------|-----|
| Button | GPIO32 |
| Ground | GND |

### DY-HV8F Audio
| DY-HV8F | ESP32-S3 |
|---------|----------|
| VIN | 5V |
| GND | GND |
| IO0 (TX) | GPIO16 |
| IO1 (RX) | GPIO17 |
| SPK+/- | 8ohm speaker |

### DY-HV8F Mode Selection
| Pin | Connection |
|-----|------------|
| CON1 | GND |
| CON2 | GND |
| CON3 | 3.3V |

## SD Card

Place victory sound as `00001.mp3` on the SD card.

## Configuration

Edit `src/config.h`:
- `BUTTON_PIN` - GPIO for button input
- `DYPLAYER_VOLUME` - Audio volume (0-30)
- `WIN_TRACK` - Track number to play

## Part of Otherworld Escape Rooms

This prop is part of the [OER](https://github.com/TenMoreMinutesProductions) escape room system.
