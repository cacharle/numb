#ifndef NUMB_ARRAY_H
#define NUMB_ARRAY_H

#include <stdint.h>

typedef struct
{
    uint64_t  dim;
    uint64_t *shape;
    uint64_t  data_len;
    double *data;
} nb_array_t;

nb_array_t *
nb_array_new(uint64_t dim, uint64_t *shape);
nb_array_t *
nb_array_newv(uint64_t dim, ...);
void
nb_array_destroy(nb_array_t *array);

uint64_t
nb_array_data_len(nb_array_t *array);
void
nb_array_copy_data(double *dest, nb_array_t *array);
void
nb_array_load_data(nb_array_t *array, double *data);

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
nb_array_add(nb_array_t *dest, nb_array_t *src);
void
nb_array_sub(nb_array_t *dest, nb_array_t *src);
void
nb_array_mul(nb_array_t *dest, nb_array_t *src);
void
nb_array_div(nb_array_t *dest, nb_array_t *src);

void
nb_array_print(nb_array_t *array);

#endif
