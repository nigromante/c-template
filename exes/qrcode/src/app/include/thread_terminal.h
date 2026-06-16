#ifndef TERMINAL_THREAD_H
#define TERMINAL_THREAD_H

#ifdef TERMINAL_THREAD_C
int ff_terminal = 1;
#else
extern int ff_terminal;
#endif

void *fn_terminal(void *args);

#endif
