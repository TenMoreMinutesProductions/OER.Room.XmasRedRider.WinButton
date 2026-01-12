#include <Arduino.h>
#include "config.h"
#include "AudioPlayer.h"

// Button state tracking
bool lastButtonState = HIGH;
bool buttonPressed = false;
unsigned long lastDebounceTime = 0;
bool firstRead = true;

void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(10); }
  delay(1000);

  Serial.println("========================================");
  Serial.println("WinButton - Simple Button to Audio");
  Serial.println("========================================");

  // Initialize button pin with internal pull-up
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  delay(100);  // Allow pull-up to stabilize

  // Read initial state to avoid false trigger
  lastButtonState = digitalRead(BUTTON_PIN);

  // Initialize audio player
  audioPlayerInit();

  Serial.println("[Setup] Complete. Waiting for button press...");
}

void loop() {
  // Skip first read cycle to ensure stable state
  if (firstRead) {
    firstRead = false;
    delay(100);
    return;
  }

  bool currentButtonState = digitalRead(BUTTON_PIN);

  // Button state changed
  if (currentButtonState != lastButtonState) {
    lastDebounceTime = millis();
  }

  // Debounce check
  if ((millis() - lastDebounceTime) > BUTTON_DEBOUNCE_MS) {
    // Button pressed (LOW because of pull-up) and hasn't been handled yet
    if (currentButtonState == LOW && !buttonPressed) {
      buttonPressed = true;
      Serial.println("[Button] Pressed! Playing track 00001.mp3");
      audioPlayerPlayTrack(WIN_TRACK);
    }
    // Button released
    else if (currentButtonState == HIGH && buttonPressed) {
      buttonPressed = false;
      Serial.println("[Button] Released");
    }
  }

  lastButtonState = currentButtonState;
  delay(10);
}
