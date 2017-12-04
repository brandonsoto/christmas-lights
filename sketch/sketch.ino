
#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

// If your 32x32 matrix has the SINGLE HEADER input,
// use this pinout:
#define CLK 8  // MUST be on PORTB! (Use pin 11 on Mega)
#define OE  9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3

#define COLS 32
#define ROWS 32

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);

const uint16_t WHITE = matrix.ColorHSV( 0, 0, 75, true);
const uint16_t BROWN = matrix.ColorHSV( 120, 255, 150, true);
const uint16_t GREEN = matrix.ColorHSV( 350, 255, 125, true);
const uint16_t RED = matrix.ColorHSV( 150, 255, 100, true);
const uint16_t GOLD = matrix.ColorHSV( 220, 200, 175, true);
const uint16_t BLACK = matrix.Color333( 255, 255, 255 );
const uint16_t BLUE = 2;
const uint16_t PINK = 4098;

void initTree() {
  matrix.drawRect( 0, ROWS - 2, COLS, 2, WHITE );               // ground
  matrix.fillRect( (COLS / 2 - 2), 22, 5, 9, BROWN );           // tree trunk
  matrix.fillTriangle( ( COLS / 2 ), 1, 5, 21, 27, 21, GREEN ); // tree
  matrix.fillCircle( ( COLS / 2 ), 1, 1, GOLD );                // topper
}

void initDecorations() {
    matrix.fillCircle( 20, 20, 1, RED );
    matrix.fillCircle( 15, 5, 1, BLUE );
    matrix.fillCircle( 19, 12, 1, PINK );
}

void snow() {
  // TODO: implement
}

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  
  matrix.begin();
  
  initTree();
  initDecorations();
}

void loop() {
  snow();
}
