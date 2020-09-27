#include <SDL.h>

#include "window.h"
#include "render.h"

int main(int argc, char ** argv)
{
   constexpr unsigned int screen_width = 1024;
   constexpr unsigned int screen_height = 768;
   Window w(screen_width, screen_height);

   float time = 0.0f;
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
      time += 1000/90;
      renderRaytracer(w.data(), screen_width, screen_height, time);
      w.draw();
   }

   SDL_Quit();

   return 0;
}
