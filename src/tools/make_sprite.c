/*

Sprite File Format
==================

  A sprite file ends with a .spr extension. Each sprite file must have an
  accompanying sprite sheet--a file with the same name but a .png extension.

  ---

  A uint8_t for the number of frames

  A uint8_t for the number of sequences

  For each frame:

    A uint16_t for the X coordinate in the sprite sheet

    A uint16_t for the Y coordinate in the sprite sheet

    A uint16_t for the width

    A uint16_t for the height

    A uint16_t for the X coordinate of the sprite's origin, in the sprite sheet

    A uint16_t for the Y coordinate of the sprite's origin, in the sprite sheet

  For each sequence:

    A uint8_t for the number of frames in the sequence

    For each frame in the sequence:

      A uint8_t for an index into the frames array

      A uint16_t for how long the frame should be displayed (in ticks)

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
  /*
  // ROAST

  FILE* fp;
  fp = fopen("bin/roast.spr", "wb");

  uint8_t num_frames = 2;
  fwrite(&num_frames, sizeof(uint8_t), 1, fp);

  uint8_t num_sequences = 1;
  fwrite(&num_sequences, sizeof(uint8_t), 1, fp);

  // idle 1
  {
    uint16_t x = 0;
    fwrite(&x, sizeof(uint16_t), 1, fp);

    uint16_t y = 0;
    fwrite(&y, sizeof(uint16_t), 1, fp);

    uint16_t w = 100;
    fwrite(&w, sizeof(uint16_t), 1, fp);

    uint16_t h = 60;
    fwrite(&h, sizeof(uint16_t), 1, fp);

    uint16_t ox = 0;
    fwrite(&ox, sizeof(uint16_t), 1, fp);

    uint16_t oy = 0;
    fwrite(&oy, sizeof(uint16_t), 1, fp);
  }

  // idle 2
  {
    uint16_t x = 100;
    fwrite(&x, sizeof(uint16_t), 1, fp);

    uint16_t y = 0;
    fwrite(&y, sizeof(uint16_t), 1, fp);

    uint16_t w = 100;
    fwrite(&w, sizeof(uint16_t), 1, fp);

    uint16_t h = 60;
    fwrite(&h, sizeof(uint16_t), 1, fp);

    uint16_t ox = 0;
    fwrite(&ox, sizeof(uint16_t), 1, fp);

    uint16_t oy = 0;
    fwrite(&oy, sizeof(uint16_t), 1, fp);
  }

  // idle

  {
    uint8_t frames_in_seq = 2;
    fwrite(&frames_in_seq, sizeof(uint8_t), 1, fp);
  }

  // idle 1
  {
    uint8_t frame = 0;
    fwrite(&frame, sizeof(uint8_t), 1, fp);

    uint16_t duration = 60;
    fwrite(&duration, sizeof(uint16_t), 1, fp);
  }

  // idle 2
  {
    uint8_t frame = 1;
    fwrite(&frame, sizeof(uint8_t), 1, fp);

    uint16_t duration = 3;
    fwrite(&duration, sizeof(uint16_t), 1, fp);
  }

  fclose(fp);
  return 0;
  */

  // HAGGAR

  FILE* fp;
  fp = fopen("bin/haggar.spr", "wb");

  uint8_t num_frames = 13;
  fwrite(&num_frames, sizeof(uint8_t), 1, fp);

  uint8_t num_sequences = 2;
  fwrite(&num_sequences, sizeof(uint8_t), 1, fp);

  // idle
  {
    uint16_t x = 24;
    fwrite(&x, sizeof(uint16_t), 1, fp);

    uint16_t y = 9;
    fwrite(&y, sizeof(uint16_t), 1, fp);

    uint16_t w = 81;
    fwrite(&w, sizeof(uint16_t), 1, fp);

    uint16_t h = 93;
    fwrite(&h, sizeof(uint16_t), 1, fp);

    uint16_t ox = 0;
    fwrite(&ox, sizeof(uint16_t), 1, fp);

    uint16_t oy = 0;
    fwrite(&oy, sizeof(uint16_t), 1, fp);
  }

  // walk 1
  {
    uint16_t x = 9;
    fwrite(&x, sizeof(uint16_t), 1, fp);

    uint16_t y = 135;
    fwrite(&y, sizeof(uint16_t), 1, fp);

    uint16_t w = 81;
    fwrite(&w, sizeof(uint16_t), 1, fp);

    uint16_t h = 100;
    fwrite(&h, sizeof(uint16_t), 1, fp);

    uint16_t ox = 0;
    fwrite(&ox, sizeof(uint16_t), 1, fp);

    uint16_t oy = 0;
    fwrite(&oy, sizeof(uint16_t), 1, fp);
  }

  // walk 2
  {
    uint16_t x = 90;
    fwrite(&x, sizeof(uint16_t), 1, fp);

    uint16_t y = 135;
    fwrite(&y, sizeof(uint16_t), 1, fp);

    uint16_t w = 81;
    fwrite(&w, sizeof(uint16_t), 1, fp);

    uint16_t h = 100;
    fwrite(&h, sizeof(uint16_t), 1, fp);

    uint16_t ox = 0;
    fwrite(&ox, sizeof(uint16_t), 1, fp);

    uint16_t oy = 0;
    fwrite(&oy, sizeof(uint16_t), 1, fp);
  }

  // walk 3
  {
    uint16_t x = 171;
    fwrite(&x, sizeof(uint16_t), 1, fp);

    uint16_t y = 135;
    fwrite(&y, sizeof(uint16_t), 1, fp);

    uint16_t w = 81;
    fwrite(&w, sizeof(uint16_t), 1, fp);

    uint16_t h = 100;
    fwrite(&h, sizeof(uint16_t), 1, fp);

    uint16_t ox = 0;
    fwrite(&ox, sizeof(uint16_t), 1, fp);

    uint16_t oy = 0;
    fwrite(&oy, sizeof(uint16_t), 1, fp);
  }

  // walk 4
  {
    uint16_t x = 252;
    fwrite(&x, sizeof(uint16_t), 1, fp);

    uint16_t y = 135;
    fwrite(&y, sizeof(uint16_t), 1, fp);

    uint16_t w = 81;
    fwrite(&w, sizeof(uint16_t), 1, fp);

    uint16_t h = 100;
    fwrite(&h, sizeof(uint16_t), 1, fp);

    uint16_t ox = 0;
    fwrite(&ox, sizeof(uint16_t), 1, fp);

    uint16_t oy = 0;
    fwrite(&oy, sizeof(uint16_t), 1, fp);
  }

  // walk 5
  {
    uint16_t x = 333;
    fwrite(&x, sizeof(uint16_t), 1, fp);

    uint16_t y = 135;
    fwrite(&y, sizeof(uint16_t), 1, fp);

    uint16_t w = 81;
    fwrite(&w, sizeof(uint16_t), 1, fp);

    uint16_t h = 100;
    fwrite(&h, sizeof(uint16_t), 1, fp);

    uint16_t ox = 0;
    fwrite(&ox, sizeof(uint16_t), 1, fp);

    uint16_t oy = 0;
    fwrite(&oy, sizeof(uint16_t), 1, fp);
  }

  // walk 6
  {
    uint16_t x = 414;
    fwrite(&x, sizeof(uint16_t), 1, fp);

    uint16_t y = 135;
    fwrite(&y, sizeof(uint16_t), 1, fp);

    uint16_t w = 81;
    fwrite(&w, sizeof(uint16_t), 1, fp);

    uint16_t h = 100;
    fwrite(&h, sizeof(uint16_t), 1, fp);

    uint16_t ox = 0;
    fwrite(&ox, sizeof(uint16_t), 1, fp);

    uint16_t oy = 0;
    fwrite(&oy, sizeof(uint16_t), 1, fp);
  }

  // walk 7
  {
    uint16_t x = 495;
    fwrite(&x, sizeof(uint16_t), 1, fp);

    uint16_t y = 135;
    fwrite(&y, sizeof(uint16_t), 1, fp);

    uint16_t w = 81;
    fwrite(&w, sizeof(uint16_t), 1, fp);

    uint16_t h = 100;
    fwrite(&h, sizeof(uint16_t), 1, fp);

    uint16_t ox = 0;
    fwrite(&ox, sizeof(uint16_t), 1, fp);

    uint16_t oy = 0;
    fwrite(&oy, sizeof(uint16_t), 1, fp);
  }

  // walk 8
  {
    uint16_t x = 576;
    fwrite(&x, sizeof(uint16_t), 1, fp);

    uint16_t y = 135;
    fwrite(&y, sizeof(uint16_t), 1, fp);

    uint16_t w = 81;
    fwrite(&w, sizeof(uint16_t), 1, fp);

    uint16_t h = 100;
    fwrite(&h, sizeof(uint16_t), 1, fp);

    uint16_t ox = 0;
    fwrite(&ox, sizeof(uint16_t), 1, fp);

    uint16_t oy = 0;
    fwrite(&oy, sizeof(uint16_t), 1, fp);
  }

  // walk 9
  {
    uint16_t x = 657;
    fwrite(&x, sizeof(uint16_t), 1, fp);

    uint16_t y = 135;
    fwrite(&y, sizeof(uint16_t), 1, fp);

    uint16_t w = 81;
    fwrite(&w, sizeof(uint16_t), 1, fp);

    uint16_t h = 100;
    fwrite(&h, sizeof(uint16_t), 1, fp);

    uint16_t ox = 0;
    fwrite(&ox, sizeof(uint16_t), 1, fp);

    uint16_t oy = 0;
    fwrite(&oy, sizeof(uint16_t), 1, fp);
  }

  // walk 10
  {
    uint16_t x = 738;
    fwrite(&x, sizeof(uint16_t), 1, fp);

    uint16_t y = 135;
    fwrite(&y, sizeof(uint16_t), 1, fp);

    uint16_t w = 81;
    fwrite(&w, sizeof(uint16_t), 1, fp);

    uint16_t h = 100;
    fwrite(&h, sizeof(uint16_t), 1, fp);

    uint16_t ox = 0;
    fwrite(&ox, sizeof(uint16_t), 1, fp);

    uint16_t oy = 0;
    fwrite(&oy, sizeof(uint16_t), 1, fp);
  }

  // walk 11
  {
    uint16_t x = 819;
    fwrite(&x, sizeof(uint16_t), 1, fp);

    uint16_t y = 135;
    fwrite(&y, sizeof(uint16_t), 1, fp);

    uint16_t w = 81;
    fwrite(&w, sizeof(uint16_t), 1, fp);

    uint16_t h = 100;
    fwrite(&h, sizeof(uint16_t), 1, fp);

    uint16_t ox = 0;
    fwrite(&ox, sizeof(uint16_t), 1, fp);

    uint16_t oy = 0;
    fwrite(&oy, sizeof(uint16_t), 1, fp);
  }

  // walk 12
  {
    uint16_t x = 900;
    fwrite(&x, sizeof(uint16_t), 1, fp);

    uint16_t y = 135;
    fwrite(&y, sizeof(uint16_t), 1, fp);

    uint16_t w = 81;
    fwrite(&w, sizeof(uint16_t), 1, fp);

    uint16_t h = 100;
    fwrite(&h, sizeof(uint16_t), 1, fp);

    uint16_t ox = 0;
    fwrite(&ox, sizeof(uint16_t), 1, fp);

    uint16_t oy = 0;
    fwrite(&oy, sizeof(uint16_t), 1, fp);
  }

  // idle

  {
    uint8_t frames_in_seq = 1;
    fwrite(&frames_in_seq, sizeof(uint8_t), 1, fp);
  }

  // idle 1
  {
    uint8_t frame = 0;
    fwrite(&frame, sizeof(uint8_t), 1, fp);

    uint16_t duration = 5;
    fwrite(&duration, sizeof(uint16_t), 1, fp);
  }

  // walk

  {
    uint8_t frames_in_seq = 12;
    fwrite(&frames_in_seq, sizeof(uint8_t), 1, fp);
  }

  // frame 1
  {
    uint8_t frame = 1;
    fwrite(&frame, sizeof(uint8_t), 1, fp);

    uint16_t duration = 5;
    fwrite(&duration, sizeof(uint16_t), 1, fp);
  }

  // frame 2
  {
    uint8_t frame = 2;
    fwrite(&frame, sizeof(uint8_t), 1, fp);

    uint16_t duration = 5;
    fwrite(&duration, sizeof(uint16_t), 1, fp);
  }

  // frame 3
  {
    uint8_t frame = 3;
    fwrite(&frame, sizeof(uint8_t), 1, fp);

    uint16_t duration = 5;
    fwrite(&duration, sizeof(uint16_t), 1, fp);
  }

  // frame 4
  {
    uint8_t frame = 4;
    fwrite(&frame, sizeof(uint8_t), 1, fp);

    uint16_t duration = 5;
    fwrite(&duration, sizeof(uint16_t), 1, fp);
  }

  // frame 5
  {
    uint8_t frame = 5;
    fwrite(&frame, sizeof(uint8_t), 1, fp);

    uint16_t duration = 5;
    fwrite(&duration, sizeof(uint16_t), 1, fp);
  }

  // frame 6
  {
    uint8_t frame = 6;
    fwrite(&frame, sizeof(uint8_t), 1, fp);

    uint16_t duration = 5;
    fwrite(&duration, sizeof(uint16_t), 1, fp);
  }

  // frame 7
  {
    uint8_t frame = 7;
    fwrite(&frame, sizeof(uint8_t), 1, fp);

    uint16_t duration = 5;
    fwrite(&duration, sizeof(uint16_t), 1, fp);
  }

  // frame 8
  {
    uint8_t frame = 8;
    fwrite(&frame, sizeof(uint8_t), 1, fp);

    uint16_t duration = 5;
    fwrite(&duration, sizeof(uint16_t), 1, fp);
  }

  // frame 9
  {
    uint8_t frame = 9;
    fwrite(&frame, sizeof(uint8_t), 1, fp);

    uint16_t duration = 5;
    fwrite(&duration, sizeof(uint16_t), 1, fp);
  }

  // frame 10
  {
    uint8_t frame = 10;
    fwrite(&frame, sizeof(uint8_t), 1, fp);

    uint16_t duration = 5;
    fwrite(&duration, sizeof(uint16_t), 1, fp);
  }

  // frame 11
  {
    uint8_t frame = 11;
    fwrite(&frame, sizeof(uint8_t), 1, fp);

    uint16_t duration = 5;
    fwrite(&duration, sizeof(uint16_t), 1, fp);
  }

  // frame 12
  {
    uint8_t frame = 12;
    fwrite(&frame, sizeof(uint8_t), 1, fp);

    uint16_t duration = 5;
    fwrite(&duration, sizeof(uint16_t), 1, fp);
  }

  fclose(fp);
  return 0;
}
