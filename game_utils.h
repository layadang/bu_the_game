#ifndef __GAME_UTILS_H__
#define __GAME_UTILS_H__

#define NYI() { fprintf(stderr, "NYI: %s\n", __func__); assert(0); } 

#ifdef VERBOSE
#define VPRINT(fmt, ...) fprintf(stderr, "%s: " fmt, __func__,__VA_ARGS__)
#else
#define VPRINT(...)
#endif

#endif
