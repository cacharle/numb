#ifndef NUMB_ARRAY_H
#define NUMB_ARRAY_H

#include <stddef.h>

typedef struct
{
    size_t  dim;
    size_t *shape;
    size_t  data_len;
    double *data;
} nb_array_t;

nb_array_t *
nb_array_new(size_t dim, ...);
void
nb_array_destroy(nb_array_t *array);

void
nb_array_fill(nb_array_t *array, double n);
void
nb_array_scalar_add(nb_array_t *array, double n);
void
nb_array_scalar_sub(nb_array_t *array, double n);
void
nb_array_scalar_mul(nb_array_t *array, double n);
void
nb_array_scalar_div(nb_array_t *array, double n);

void
nb_array_print(nb_array_t *array);

#endif
