#include "CustomKeypad.h"

#define ROW_1 A0
#define ROW_2 A1
#define ROW_3 0
#define ROW_4 0
#define COL_1 A2
#define COL_2 A3
#define COL_3 A4
#define COL_4 0

const byte ROWS = 4;
const byte COLS = 4;
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rows[ROWS] = {ROW_1, ROW_2, ROW_3, ROW_4};
byte cols[COLS] = {COL_1, COL_2, COL_3, COL_4};

CustomKeypad::CustomKeypad() : Keypad(makeKeymap(hexaKeys), rows, cols, ROWS, COLS) {
}

