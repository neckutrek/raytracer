#ifndef INCGRD_RAYTRACER_WINDOW_H
#define INCGRD_RAYTRACER_WINDOW_H

#include <SDL.h>

class Window
{
   unsigned int   m_width;
   unsigned int   m_height;

   SDL_Window*    m_window   = nullptr;
   SDL_Renderer*  m_renderer = nullptr;
   SDL_Texture*   m_texture  = nullptr;
   Uint32*        m_pixels   = nullptr;

public:
                  Window(unsigned int width, unsigned int height);
                  ~Window();

   void           prepare();
   void           draw();

   Uint32*        data();
};


#endif
