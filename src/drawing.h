// *********************************************************************
// Functions for drawing on the matrix
// *********************************************************************


// *********************************************************************
// Helper function that draws a letter at a given position of the matric in a given color
// *********************************************************************
void drawChar(String letter, uint8_t x, uint8_t y, uint16_t color)
{
  display.setTextColor(color);
  display.setCursor(x, y);
  display.print(letter);
}

// *********************************************************************
// Draws the intro screen
// *********************************************************************
void drawIntro()
{
  drawChar("T", 0, 0, myCYAN);
  drawChar("e", 5, 0, myMAGENTA);
  drawChar("t", 11, 0, myYELLOW);
  drawChar("r", 17, 0, myGREEN);
  drawChar("i", 22, 0, myBLUE);
  drawChar("s", 26, 0, myRED);

  drawChar("T", 6, 9, myRED);
  drawChar("i", 11, 9, myWHITE);
  drawChar("m", 16, 9, myCYAN);
  drawChar("e", 22, 9, myMAGENTA);
}

// *********************************************************************
// Draws a brick shape at a given position
// *********************************************************************
void drawShape(int blocktype, uint16_t color, int x_pos, int y_pos, int num_rot)
{
  // Square
  if (blocktype == 0)
  {
    display.drawPixel(x_pos, y_pos, color);
    display.drawPixel(x_pos + 1, y_pos, color);
    display.drawPixel(x_pos, y_pos - 1, color);
    display.drawPixel(x_pos + 1, y_pos - 1, color);
  }

  // L-Shape
  if (blocktype == 1)
  {
    if (num_rot == 0)
    {
      display.drawPixel(x_pos, y_pos, color);
      display.drawPixel(x_pos + 1, y_pos, color);
      display.drawPixel(x_pos, y_pos - 1, color);
      display.drawPixel(x_pos, y_pos - 2, color);
    }
    if (num_rot == 1)
    {
      display.drawPixel(x_pos, y_pos, color);
      display.drawPixel(x_pos, y_pos - 1, color);
      display.drawPixel(x_pos + 1, y_pos - 1, color);
      display.drawPixel(x_pos + 2, y_pos - 1, color);
    }
    if (num_rot == 2)
    {
      display.drawPixel(x_pos + 1, y_pos, color);
      display.drawPixel(x_pos + 1, y_pos - 1, color);
      display.drawPixel(x_pos + 1, y_pos - 2, color);
      display.drawPixel(x_pos, y_pos - 2, color);
    }
    if (num_rot == 3)
    {
      display.drawPixel(x_pos, y_pos, color);
      display.drawPixel(x_pos + 1, y_pos, color);
      display.drawPixel(x_pos + 2, y_pos, color);
      display.drawPixel(x_pos + 2, y_pos - 1, color);
    }
  }

  // L-Shape (reverse)
  if (blocktype == 2)
  {
    if (num_rot == 0)
    {
      display.drawPixel(x_pos, y_pos, color);
      display.drawPixel(x_pos + 1, y_pos, color);
      display.drawPixel(x_pos + 1, y_pos - 1, color);
      display.drawPixel(x_pos + 1, y_pos - 2, color);
    }
    if (num_rot == 1)
    {
      display.drawPixel(x_pos, y_pos, color);
      display.drawPixel(x_pos + 1, y_pos, color);
      display.drawPixel(x_pos + 2, y_pos, color);
      display.drawPixel(x_pos, y_pos - 1, color);
    }
    if (num_rot == 2)
    {
      display.drawPixel(x_pos, y_pos, color);
      display.drawPixel(x_pos, y_pos - 1, color);
      display.drawPixel(x_pos, y_pos - 2, color);
      display.drawPixel(x_pos + 1, y_pos - 2, color);
    }
    if (num_rot == 3)
    {
      display.drawPixel(x_pos, y_pos - 1, color);
      display.drawPixel(x_pos + 1, y_pos - 1, color);
      display.drawPixel(x_pos + 2, y_pos - 1, color);
      display.drawPixel(x_pos + 2, y_pos, color);
    }
  }

  // I-Shape
  if (blocktype == 3)
  {
    if (num_rot == 0 || num_rot == 2)
    { // Horizontal
      display.drawPixel(x_pos, y_pos, color);
      display.drawPixel(x_pos + 1, y_pos, color);
      display.drawPixel(x_pos + 2, y_pos, color);
      display.drawPixel(x_pos + 3, y_pos, color);
    }
    if (num_rot == 1 || num_rot == 3)
    { // Vertical
      display.drawPixel(x_pos, y_pos, color);
      display.drawPixel(x_pos, y_pos - 1, color);
      display.drawPixel(x_pos, y_pos - 2, color);
      display.drawPixel(x_pos, y_pos - 3, color);
    }
  }

  // S-Shape
  if (blocktype == 4)
  {
    if (num_rot == 0 || num_rot == 2)
    {
      display.drawPixel(x_pos + 1, y_pos, color);
      display.drawPixel(x_pos, y_pos - 1, color);
      display.drawPixel(x_pos + 1, y_pos - 1, color);
      display.drawPixel(x_pos, y_pos - 2, color);
    }
    if (num_rot == 1 || num_rot == 3)
    {
      display.drawPixel(x_pos, y_pos, color);
      display.drawPixel(x_pos + 1, y_pos, color);
      display.drawPixel(x_pos + 1, y_pos - 1, color);
      display.drawPixel(x_pos + 2, y_pos - 1, color);
    }
  }

  // S-Shape (reversed)
  if (blocktype == 5)
  {
    if (num_rot == 0 || num_rot == 2)
    {
      display.drawPixel(x_pos, y_pos, color);
      display.drawPixel(x_pos, y_pos - 1, color);
      display.drawPixel(x_pos + 1, y_pos - 1, color);
      display.drawPixel(x_pos + 1, y_pos - 2, color);
    }
    if (num_rot == 1 || num_rot == 3)
    {
      display.drawPixel(x_pos + 1, y_pos, color);
      display.drawPixel(x_pos + 2, y_pos, color);
      display.drawPixel(x_pos, y_pos - 1, color);
      display.drawPixel(x_pos + 1, y_pos - 1, color);
    }
  }

  // Half cross
  if (blocktype == 6)
  {
    if (num_rot == 0)
    {
      display.drawPixel(x_pos, y_pos, color);
      display.drawPixel(x_pos + 1, y_pos, color);
      display.drawPixel(x_pos + 2, y_pos, color);
      display.drawPixel(x_pos + 1, y_pos - 1, color);
    }
    if (num_rot == 1)
    {
      display.drawPixel(x_pos, y_pos, color);
      display.drawPixel(x_pos, y_pos - 1, color);
      display.drawPixel(x_pos, y_pos - 2, color);
      display.drawPixel(x_pos + 1, y_pos - 1, color);
    }
    if (num_rot == 2)
    {
      display.drawPixel(x_pos + 1, y_pos, color);
      display.drawPixel(x_pos, y_pos - 1, color);
      display.drawPixel(x_pos + 1, y_pos - 1, color);
      display.drawPixel(x_pos + 2, y_pos - 1, color);
    }
    if (num_rot == 3)
    {
      display.drawPixel(x_pos + 1, y_pos, color);
      display.drawPixel(x_pos, y_pos - 1, color);
      display.drawPixel(x_pos + 1, y_pos - 1, color);
      display.drawPixel(x_pos + 1, y_pos - 2, color);
    }
  }
}

// *********************************************************************
// Helper function that that return the falling instruction for a given number
// *********************************************************************
fall_instr getFallinstrByNum(int num, int blockindex)
{
  if (num == 0)
  {
    return num_0[blockindex];
  }
  if (num == 1)
  {
    return num_1[blockindex];
  }
  if (num == 2)
  {
    return num_2[blockindex];
  }
  if (num == 3)
  {
    return num_3[blockindex];
  }
  if (num == 4)
  {
    return num_4[blockindex];
  }
  if (num == 5)
  {
    return num_5[blockindex];
  }
  if (num == 6)
  {
    return num_6[blockindex];
  }
  if (num == 7)
  {
    return num_7[blockindex];
  }
  if (num == 8)
  {
    return num_8[blockindex];
  }
  if (num == 9)
  {
    return num_9[blockindex];
  }
}

// *********************************************************************
// Helper function that return the number of bricks for a given number
// *********************************************************************
int getBocksizeByNum(int num)
{
  if (num == 0)
  {
    return SIZE_NUM_0;
  }
  if (num == 1)
  {
    return SIZE_NUM_1;
  }
  if (num == 2)
  {
    return SIZE_NUM_2;
  }
  if (num == 3)
  {
    return SIZE_NUM_3;
  }
  if (num == 4)
  {
    return SIZE_NUM_4;
  }
  if (num == 5)
  {
    return SIZE_NUM_5;
  }
  if (num == 6)
  {
    return SIZE_NUM_6;
  }
  if (num == 7)
  {
    return SIZE_NUM_7;
  }
  if (num == 8)
  {
    return SIZE_NUM_8;
  }
  if (num == 9)
  {
    return SIZE_NUM_9;
  }
}

// *********************************************************************
// Main function that handles the drawing of all numbers
// *********************************************************************
void drawNumbers()
{
  // For each number position
  for (int numpos = 0; numpos < SIZE_NUM_STATES; numpos++)
  {

    // Draw falling shape
    if (numstates[numpos].blockindex < getBocksizeByNum(numstates[numpos].num_to_draw))
    {
      fall_instr current_fall = getFallinstrByNum(numstates[numpos].num_to_draw, numstates[numpos].blockindex);

      // Handle variations of rotations
      uint8_t rotations = current_fall.num_rot;
      if (rotations == 1)
      {
        if (numstates[numpos].fallindex < (int)(current_fall.y_stop / 2))
        {
          rotations = 0;
        }
      }
      if (rotations == 2)
      {
        if (numstates[numpos].fallindex < (int)(current_fall.y_stop / 3))
        {
          rotations = 0;
        }
        if (numstates[numpos].fallindex < (int)(current_fall.y_stop / 3 * 2))
        {
          rotations = 1;
        }
      }
      if (rotations == 3)
      {
        if (numstates[numpos].fallindex < (int)(current_fall.y_stop / 4))
        {
          rotations = 0;
        }
        if (numstates[numpos].fallindex < (int)(current_fall.y_stop / 4 * 2))
        {
          rotations = 1;
        }
        if (numstates[numpos].fallindex < (int)(current_fall.y_stop / 4 * 3))
        {
          rotations = 2;
        }
      }

      drawShape(current_fall.blocktype, current_fall.color, current_fall.x_pos + numstates[numpos].x_shift, numstates[numpos].fallindex - 1, rotations);
      numstates[numpos].fallindex++;

      if (numstates[numpos].fallindex > current_fall.y_stop)
      {
        numstates[numpos].fallindex = 0;
        numstates[numpos].blockindex++;
      }
    }

    // Draw already dropped shapes
    if (numstates[numpos].blockindex > 0)
    {
      for (int i = 0; i < numstates[numpos].blockindex; i++)
      {
        fall_instr fallen_block = getFallinstrByNum(numstates[numpos].num_to_draw, i);
        drawShape(fallen_block.blocktype, fallen_block.color, fallen_block.x_pos + numstates[numpos].x_shift, fallen_block.y_stop - 1, fallen_block.num_rot);
      }
    }
  }

  // Hour / minutes divider (blinking)
  if (seconds_odd)
  {
    display.fillRect(15, 12, 2, 2, myWHITE);
    display.fillRect(15, 8, 2, 2, myWHITE);
  }
}

// *********************************************************************
// Handler for the display refresh ticker
// *********************************************************************
void display_updater()
{
  // ISR for display refresh
  display.display(30);
}

// *********************************************************************
// Handler for the number refresh ticker
// *********************************************************************
void number_updater()
{
  display.clearDisplay();
  drawNumbers();
  display.showBuffer();
}