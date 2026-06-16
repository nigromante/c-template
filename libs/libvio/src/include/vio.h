#ifndef VIO_H
#define VIO_H

typedef struct {

    void (*print)(char *, ...);

} VIO;

VIO *vio_init();
void vio_release(VIO **);

#endif
