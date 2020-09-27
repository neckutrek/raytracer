#include "window.h"

Window::Window(unsigned int width, unsigned int height)
   : m_width(width), m_height(height)
{
   SDL_Init(SDL_INIT_VIDEO);
   m_window = SDL_CreateWindow(
         "SDL2 Pixel Drawing",
         SDL_WINDOWPOS_UNDEFINED,
         SDL_WINDOWPOS_UNDEFINED,
         m_width,
         m_height,
         0);
   m_renderer = SDL_CreateRenderer(m_window, -1, 0);
   m_texture = SDL_CreateTexture(
         m_renderer,
         SDL_PIXELFORMAT_ARGB8888,
         SDL_TEXTUREACCESS_STATIC,
         m_width,
         m_height);
   m_pixels = new Uint32[m_width * m_height];
   memset(m_pixels, 0xffffffff, m_width * m_height * sizeof(Uint32));
}

Window::~Window()
{
   delete[] m_pixels;
   SDL_DestroyTexture(m_texture);
   SDL_DestroyRenderer(m_renderer);
   SDL_DestroyWindow(m_window);
}

Uint32* Window::data()
{
   return m_pixels;
}

void Window::draw()
{
   SDL_RenderClear(m_renderer);
   SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
   SDL_RenderPresent(m_renderer);
}

void Window::prepare()
{
   SDL_UpdateTexture(m_texture, NULL, m_pixels, m_width * sizeof(Uint32));
}
