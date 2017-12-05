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
#define COLUMNS 32
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
#define TOTAL_COLORS 5

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);

const long COLORS[TOTAL_COLORS] = {
  matrix.Color888(255, 0, 0 ),
  matrix.Color888(125, 0, 0 ),
  matrix.Color888(0, 0, 255 ),
  GOLD,
  PINK
};

void initTree() {
  matrix.drawRect( 0, ROWS - 2, COLUMNS, 2, WHITE );               // ground
  matrix.fillRect( (COLUMNS / 2 - 2), 22, 5, 9, BROWN );           // tree trunk
  matrix.fillTriangle( ( COLUMNS / 2 ), 1, 5, 21, 27, 21, GREEN ); // tree
  matrix.fillCircle( ( COLUMNS / 2 ), 1, 1, GOLD );                // topper
}

void lights() {
  const int start = 14;

  for ( int i = 0, y = 5; i < 4; i++, y+=5 ) {
    const int startX = start - ( 3 * i );
    const int maxX = (startX + ( i + 1 ) * 5);
    for ( int x = startX; x < maxX; x+=2 ) {
      matrix.drawPixel(x, y, COLORS[random(TOTAL_COLORS)]);
    }
  }
}

void snow() {
  // TODO: can we not use the brute force method here? Creating an array uses too much memory :(
  matrix.drawPixel(2, 0, matrix.Color333(0,0,0));
  matrix.drawPixel(28, 4, matrix.Color333(0,0,0));
  matrix.drawPixel(20, 6, matrix.Color333(0,0,0));
  matrix.drawPixel(8, 1, matrix.Color333(0,0,0));
  matrix.drawPixel(0, 9, matrix.Color333(0,0,0));
  matrix.drawPixel(7, 12, matrix.Color333(0,0,0));
  matrix.drawPixel(10, 9, matrix.Color333(0,0,0));
  matrix.drawPixel(28, 8, matrix.Color333(0,0,0));
  matrix.drawPixel(3, 28, matrix.Color333(0,0,0));
  matrix.drawPixel(1, 25, matrix.Color333(0,0,0));
  matrix.drawPixel(3, 17, matrix.Color333(0,0,0));
  matrix.drawPixel(31, 21, matrix.Color333(0,0,0));
  matrix.drawPixel(26, 27, matrix.Color333(0,0,0));

  matrix.drawPixel(0, 0, WHITE);
  matrix.drawPixel(30, 0, WHITE);
  matrix.drawPixel(22, 1, WHITE);
  matrix.drawPixel(10, 2, WHITE);
  matrix.drawPixel(3, 5, WHITE);
  matrix.drawPixel(4, 7, WHITE);
  matrix.drawPixel(8, 9, WHITE);
  matrix.drawPixel(24, 8, WHITE);
  matrix.drawPixel(28, 10, WHITE);
  matrix.drawPixel(3, 14, WHITE);
  matrix.drawPixel(2, 28, WHITE);
  matrix.drawPixel(4, 18, WHITE);
  matrix.drawPixel(6, 25, WHITE);
  matrix.drawPixel(22, 24, WHITE);
  matrix.drawPixel(30, 28, WHITE);
  matrix.drawPixel(28, 18, WHITE);

  delay(250);

  matrix.drawPixel(0, 0, matrix.Color333(0,0,0));
  matrix.drawPixel(30, 0, matrix.Color333(0,0,0));
  matrix.drawPixel(22, 1, matrix.Color333(0,0,0));
  matrix.drawPixel(10, 2, matrix.Color333(0,0,0));
  matrix.drawPixel(3, 5, matrix.Color333(0,0,0));
  matrix.drawPixel(4, 7, matrix.Color333(0,0,0));
  matrix.drawPixel(8, 9, matrix.Color333(0,0,0));
  matrix.drawPixel(24, 8, matrix.Color333(0,0,0));
  matrix.drawPixel(28, 10, matrix.Color333(0,0,0));
  matrix.drawPixel(3, 14, matrix.Color333(0,0,0));
  matrix.drawPixel(2, 28, matrix.Color333(0,0,0));
  matrix.drawPixel(4, 18, matrix.Color333(0,0,0));
  matrix.drawPixel(6, 25, matrix.Color333(0,0,0));
  matrix.drawPixel(22, 24, matrix.Color333(0,0,0));
  matrix.drawPixel(30, 28, matrix.Color333(0,0,0));
  matrix.drawPixel(28, 18, matrix.Color333(0,0,0));

  matrix.drawPixel(2, 0, WHITE);
  matrix.drawPixel(28, 4, WHITE);
  matrix.drawPixel(20, 6, WHITE);
  matrix.drawPixel(8, 1, WHITE);
  matrix.drawPixel(0, 9, WHITE);
  matrix.drawPixel(7, 12, WHITE);
  matrix.drawPixel(10, 9, WHITE);
  matrix.drawPixel(28, 8, WHITE);
  matrix.drawPixel(3, 28, WHITE);
  matrix.drawPixel(1, 25, WHITE);
  matrix.drawPixel(3, 17, WHITE);
  matrix.drawPixel(31, 21, WHITE);
  matrix.drawPixel(26, 27, WHITE);
}

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));

  matrix.begin();

  initTree();
}

void loop() {
  snow();
  lights();
  delay(400);
}
