#ifndef VIO_PUBLIC_H
#define VIO_PUBLIC_H

#define N 10

typedef void (*fn)(int, char *);

typedef struct {
    fn lista[N];
    int total;
} tLogger;

#ifdef VIO_PUBLIC_C
tLogger *logger;
#endif

void vio_logger(int, char *format, ...);
void vio_loggerCreate();
void vio_loggerDelete();
void vio_loggerAddListener(fn _fn);

#endif
