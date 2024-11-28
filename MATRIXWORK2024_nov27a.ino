#include <MD_Parola.h>//LIBRARY FOR TEXT EFFECTS
#include <MD_MAX72XX.h>//LIBRARYFOR CONTROLLING  MAX729
#include <SPI.h>//LIBRARY FOR SPI COMMUNICATION 

// Define hardware type and pin connections
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW//SPECIFIES HARDWARE TYPE 
#define MAX_DEVICES 4  // Number of modules in your MAX7219 display

#define DATA_PIN 11//SPI DATA
#define CS_PIN 10
#define CLK_PIN 14 or 13

// Create a Parola object
MD_Parola display = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

void setup() {
  display.begin();             // Initialize the display
  display.setIntensity(5);     // Set brightness (0-15)
  display.displayClear();      // Clear the display
  display.displayScroll("GROUP 10 PRESENTATION", PA_CENTER, PA_SCROLL_LEFT, 100);
}

void loop() {
  // Update the display
  if (display.displayAnimate()) {
    display.displayReset();    // Reset the animation to scroll continuously
  }
}
