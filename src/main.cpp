#include <SDL.h>

void renderRaytracer(Uint32* pixels, unsigned int width, unsigned int height);

struct Window
{
   SDL_Window*    window   = nullptr;
   SDL_Renderer*  renderer = nullptr;
   SDL_Texture*   texture  = nullptr;
   Uint32*        pixels   = nullptr;

   Window(unsigned int width, unsigned int height)
   {
      SDL_Init(SDL_INIT_VIDEO);
      window = SDL_CreateWindow("SDL2 Pixel Drawing",
                                 SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
      renderer = SDL_CreateRenderer(window, -1, 0);
      texture = SDL_CreateTexture(renderer,
                                    SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, width, height);
      pixels = new Uint32[width * height];
      memset(pixels, 0xffffffff, width * height * sizeof(Uint32));
   }

   ~Window()
   {
      delete[] pixels;
      SDL_DestroyTexture(texture);
      SDL_DestroyRenderer(renderer);
      SDL_DestroyWindow(window);
   }
};

int main(int argc, char ** argv)
{
   constexpr unsigned int screen_width = 1024;
   constexpr unsigned int screen_height = 768;
   Window w(screen_width, screen_height);

   bool quit = false;
   SDL_Event event;
   while (!quit)
   {
      SDL_UpdateTexture(w.texture, NULL, w.pixels, screen_width * sizeof(Uint32));
      while (SDL_PollEvent(&event))
      {
         switch (event.type)
         {
         case SDL_QUIT:
            quit = true;
            break;
         }
      }
      SDL_Delay(1000/90);
      renderRaytracer(w.pixels, screen_width, screen_height);
      SDL_RenderClear(w.renderer);
      SDL_RenderCopy(w.renderer, w.texture, NULL, NULL);
      SDL_RenderPresent(w.renderer);
   }

   SDL_Quit();

    return 0;
}
