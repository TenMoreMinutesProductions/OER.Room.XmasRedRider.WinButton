#ifndef CONFIG_H
#define CONFIG_H

// ============================================================
//                    DEVICE IDENTIFIER
// ============================================================
#define DEVICE_IDENTIFIER "WinButton"

// ============================================================
//                     PIN DEFINITIONS
// ============================================================
#define BUTTON_PIN 32 // Win button input (supports internal pull-up)

// DY-HV8F Audio Player (UART)
#define DYPLAYER_RX_PIN 16 // ESP32 RX <- DY-HV8F TX (IO0)
#define DYPLAYER_TX_PIN 17 // ESP32 TX -> DY-HV8F RX (IO1)

// ============================================================
//                   BUTTON SETTINGS
// ============================================================
#define BUTTON_DEBOUNCE_MS 50  // Debounce delay in milliseconds

// ============================================================
//                   DY-HV8F AUDIO SETTINGS
// ============================================================
#define DYPLAYER_VOLUME 25     // Volume level (0-30)
#define WIN_TRACK 1            // Track number to play on button press (00001.mp3)

/*
 * DY-HV8F WIRING:
 * ===============
 * DY-HV8F Pin    ESP32 Pin       Notes
 * ----------     ---------       -----
 * VIN            VIN (5V)        Power supply (6-35VDC)
 * GND            GND             Common ground
 * IO0 (TX)       GPIO16 (RX2)    Serial data from player
 * IO1 (RX)       GPIO17 (TX2)    Serial data to player
 * SPK+           Speaker +       8ohm speaker
 * SPK-           Speaker -       8ohm speaker
 *
 * CON1           GND             \
 * CON2           GND              } One-line serial mode
 * CON3           3.3V            /
 *
 * Note: ESP32 is 3.3V, DY-HV8F is 5V tolerant on IO pins.
 *       No resistors needed for ESP32 connection.
 */

#endif
