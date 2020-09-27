#include <SDL.h>

#include <cmath>
#include <iostream>

uint32_t getHue(float t)
{
   float n = t / 0.3333f;
   if (t < 0.3333f)
   {
      uint32_t x = 0xff * n;
      uint32_t y = 0xff * (1.0f-n);
      return x + (y<<8);
   }
   if (t < 0.6666f)
   {
      n -= 1.0f;
      uint32_t x = 0xff * n;
      uint32_t y = 0xff * (1.0f-n);
      return (x<<16) + y;
   }
   n -= 2.0f;
   uint32_t x = 0xff * n;
   uint32_t y = 0xff * (1.0f-n);
   return (x<<8) + (y<<16);
}

uint32_t getGreyscale(float t)
{
   uint32_t x = 0xff * t;
   return x + (x << 8) + (x << 16);
}

unsigned int linearIndex(unsigned int row, unsigned int col, unsigned int width)
{
   return row*width + col;
}

float eye_pos[3] = {0.0f, 0.0f, 0.0f};
float view_direction[3] = {0.0, 0.0, 1.0f};
float screen_distance = 10.0f;
float screen_width = 20.0f;

void renderRaytracer(Uint32* pixels, unsigned int width, unsigned int height)
{
   static float d = 0.0f;
   d += 0.009f;
   for (unsigned int r=0; r<height; ++r)
   {
      for (unsigned int c=0; c<width; ++c)
      {
         unsigned int linIdx = linearIndex(r, c, width);
         float dx = (int)c - (int)width/2.0f;
         float dy = (int)r - (int)height/2.0f;
         float t = std::atan(dy/dx)/M_PI + 0.5f;
         if (dx < 0.0f) t = 1.0f - t;
         t += d;
         while (t > 1.0f) t -= 1.0f;
         pixels[linIdx] = getHue(t);
      }
   }
}
