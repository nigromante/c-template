#ifndef VIO_H
#define VIO_H

typedef void (*fn_print)(int, char *, ...);

typedef struct {

    fn_print print;

} VIO;

VIO *vio_init();
void vio_release(VIO **);

#endif
