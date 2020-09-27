#include <SDL.h>

#include "window.h"

void renderRaytracer(Uint32* pixels, unsigned int width, unsigned int height);

int main(int argc, char ** argv)
{
   constexpr unsigned int screen_width = 1024;
   constexpr unsigned int screen_height = 768;
   Window w(screen_width, screen_height);

   bool quit = false;
   SDL_Event event;
   while (!quit)
   {
      w.prepare();
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
      renderRaytracer(w.data(), screen_width, screen_height);
      w.draw();
   }

   SDL_Quit();

   return 0;
}
