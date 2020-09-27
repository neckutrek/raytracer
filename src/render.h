#ifndef INCGRD_RAYTRACER_RENDER_H
#define  INCGRD_RAYTRACER_RENDER_H

#include <SDL.h>

/// Renders the current frame on the pixel array.
void renderRaytracer(
      Uint32* pixels,
      unsigned int width,
      unsigned int height,
      float time);

#endif
