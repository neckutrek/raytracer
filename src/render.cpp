#include <SDL.h>

#include <cmath>
#include <iostream>

#include "render.h"
#include "types.h"

namespace {
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
}

Vec3 eyePos = {0.0f, 0.0f, 0.0f};
Vec3 viewDirection = {0.0, 0.0, 1.0f};
float screenDistance = 3.0f;

void renderRaytracer(Uint32* pixels, unsigned int width, unsigned int height, float time)
{
   float d = 0.009f/11.0f * time;
   std::cout << d << std::endl;
   for (unsigned int row=0; row<height; ++row)
   {
      for (unsigned int col=0; col<width; ++col)
      {
         unsigned int linIdx = linearIndex(row, col, width);
         float dx = (int)col - (int)width/2.0f;
         float dy = (int)row - (int)height/2.0f;
         float t = std::atan(dy/dx)/M_PI + 0.5f;
         if (dx < 0.0f) t = 1.0f - t;
         t += d;
         while (t > 1.0f) t -= 1.0f;
         pixels[linIdx] = getHue(t);
      }
   }
}

