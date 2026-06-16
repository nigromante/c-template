#ifndef RAYLIB_THREAD_H
#define RAYLIB_THREAD_H

#ifdef RAYLIB_THREAD_C
int ff_raylib = 2;
#else
extern int ff_raylib;
#endif

void *fn_raylib(void *args);
#endif
