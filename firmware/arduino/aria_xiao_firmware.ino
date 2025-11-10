/*
 * Aria Art Plotter - XIAO-OLED DRIVER
 * 
 * Copyright (c) 2025 Gustavo Mayoral
 * 
 * This file is part of the Aria Art Plotter project.
 * 
 * Hardware License: CERN-OHL-S-2.0
 * Documentation License: CC BY-SA 4.0
 * Software License: GPL-3.0
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 * 
 * Project: https://github.com/gustavomayoral/aria_art_plot
 * Support: https://ko-fi.com/ariaartplot
 * Web: https://aria-art.com
 */

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

#define MAX_MESSAGE_LENGTH 128       // Max chars for messages to fit RAM
#define MAX_CHARS_PER_LINE 21        // For text wrapping on OLED
#define Y_POS_INCREMENT 8            // Line height in pixels
#define STARTUP_TIMEOUT_MS 50000     // 50 seconds for loading
#define PROGRESS_BAR_WIDTH 100       // Progress bar dimensions
#define PROGRESS_BAR_HEIGHT 6
#define PROGRESS_BAR_X 14
#define PROGRESS_BAR_Y 20
#define PROGRESS_UPDATE_MS 500       // Min update interval for animation
#define LOOP_DELAY_MS 100            // Non-blocking loop interval

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

char currentMessage[MAX_MESSAGE_LENGTH] = "ARIA Starting.\nPlease wait...";
char incomingMessage[MAX_MESSAGE_LENGTH];
bool messageComplete = false;
unsigned long lastUpdate = 0;
unsigned long startupTime = 0;
int loadingPercent = 0;
bool klipperConnected = false;
bool showingFallback = false;

// Updates the OLED display with the current message, handling multi-line text.
void updateDisplay() {
  display.clearDisplay();  // Clear only when needed; could optimize further
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  
  renderMultiLineText(currentMessage);
  
  display.display();
}

// Renders multi-line text with wrapping (split from updateDisplay for clarity).
void renderMultiLineText(const char* text) {
  int yPos = 0;
  const char* lineStart = text;
  
  while (*lineStart && yPos < SCREEN_HEIGHT - Y_POS_INCREMENT) {
    char line[MAX_CHARS_PER_LINE + 1];
    int charCount = 0;
    
    // Extract line up to newline or max chars
    while (*lineStart && *lineStart != '\n' && charCount < MAX_CHARS_PER_LINE) {
      line[charCount++] = *lineStart++;
    }
    line[charCount] = '\0';  // Null-terminate
    
    display.setCursor(0, yPos);
    display.println(line);
    yPos += Y_POS_INCREMENT;
    
    if (*lineStart == '\n') lineStart++;  // Skip newline
  }
}

void setup() {
  Serial.begin(115200);  // USB CDC on XIAO
  
  Wire.begin();  // I2C init
  
  // Initialize OLED with retries for stability
  int retries = 3;
  while (retries > 0 && !display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println("SSD1306 allocation failed, retrying...");
    delay(1000);
    retries--;
  }
  if (retries == 0) {
    Serial.println("SSD1306 failed to initialize");
    for (;;);  // Halt if critical failure
  }
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("ARIA Starting");
  display.println("Loading:");
  display.display();
  
  startupTime = millis();
  Serial.println("OLED_READY");
}

void loop() {
  static unsigned long lastLoop = 0;
  
  if (millis() - lastLoop >= LOOP_DELAY_MS) {
    handleSerial();
    
    if (!klipperConnected && !showingFallback) {
      showLoadingAnimation();
    }
    
    lastLoop = millis();
  }
}

// Handles serial input with fixed buffer to prevent overflow.
void handleSerial() {
  static int msgIndex = 0;
  
  while (Serial.available()) {
    char receivedChar = Serial.read();
    
    if (receivedChar == '\n') {
      incomingMessage[msgIndex] = '\0';  // Null-terminate
      messageComplete = true;
      break;
    } else if (msgIndex < MAX_MESSAGE_LENGTH - 1) {
      incomingMessage[msgIndex++] = receivedChar;
    } else {
      Serial.println("ERROR: Message too long");
      msgIndex = 0;
      return;
    }
  }
  
  if (messageComplete) {
    processCommand(incomingMessage);
    msgIndex = 0;
    incomingMessage[0] = '\0';
    messageComplete = false;
  }
}

void processCommand(const char* command) {
  // Skip leading whitespace (simple trim)
  while (*command == ' ' || *command == '\t') command++;
  
  if (strncmp(command, "MSG:", 4) == 0) {
    command += 4;  // Skip "MSG:"
    strncpy(currentMessage, command, MAX_MESSAGE_LENGTH - 1);
    currentMessage[MAX_MESSAGE_LENGTH - 1] = '\0';
    
    // Replace "\\n" with "\n" manually
    char* pos;
    while ((pos = strstr(currentMessage, "\\n")) != NULL) {
      *pos = '\n';
      memmove(pos + 1, pos + 2, strlen(pos + 2) + 1);
    }
    
    klipperConnected = true;
    showingFallback = false;
    updateDisplay();
    Serial.println("OK");
  } else if (strcmp(command, "CLEAR") == 0) {
    display.clearDisplay();
    display.display();
    currentMessage[0] = '\0';
    Serial.println("OK");
  } else if (strcmp(command, "STATUS") == 0) {
    Serial.println("READY");
  } else {
    Serial.println("UNKNOWN_COMMAND");
  }
}

void showLoadingAnimation() {
  unsigned long elapsed = millis() - startupTime;
  int newPercent = (elapsed * 100UL) / STARTUP_TIMEOUT_MS;  // Use UL to avoid overflow
  
  if (newPercent > 100) {
    if (!showingFallback) {
      showingFallback = true;
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, Y_POS_INCREMENT);
      display.println("ARIA ART ROBOT");
      display.display();
    }
    return;
  }
  
  // Update only if percent changed or timeout
  if (newPercent != loadingPercent || (millis() - lastUpdate) > PROGRESS_UPDATE_MS) {
    loadingPercent = newPercent;
    lastUpdate = millis();
    
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("ARIA 1.0 Starting");
    display.print("Loading: ");
    
    // Draw progress bar
    display.drawRect(PROGRESS_BAR_X, PROGRESS_BAR_Y, PROGRESS_BAR_WIDTH, PROGRESS_BAR_HEIGHT, SSD1306_WHITE);
    
    int fillWidth = (loadingPercent * (PROGRESS_BAR_WIDTH - 2)) / 100;
    if (fillWidth > 0) {
      display.fillRect(PROGRESS_BAR_X + 1, PROGRESS_BAR_Y + 1, fillWidth, PROGRESS_BAR_HEIGHT - 2, SSD1306_WHITE);
    }
    
    display.display();
  }
}