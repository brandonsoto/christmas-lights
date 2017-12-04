
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

// matrix dimensions
#define COLS 32
#define ROWS 32

// colors
#define WHITE 4226
#define BROWN 16512
#define GREEN 4480
#define RED 4096
#define GOLD 25120
#define BLACK 65535
#define BLUE 2
#define PINK 4098

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);

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
