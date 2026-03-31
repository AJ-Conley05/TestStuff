#if defined(_WIN32) || defined(_WIN64)
    //The SDL library
    #include "SDL.h"
    //Support for loading different types of images.
    #include "SDL_image.h"
    #include "SDL_types.h"
#else
    #include "SDL2/SDL.h"
    #include "SDL2/SDL_image.h"
    #include "SDL2/SDL_types.h"
#endif