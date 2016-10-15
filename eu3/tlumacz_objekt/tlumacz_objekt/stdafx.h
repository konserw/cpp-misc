#pragma once

#include <curses.h>
#include <string>
#include <vector>
#include <fstream>
#if defined WIN32 && defined MOUSE_MOVED 
    #undef MOUSE_MOVED 
#endif
#include <windows.h>