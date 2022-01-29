#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "numb/array.h"

nb_array_t *
nb_array_new(uint64_t dim, uint64_t *shape)
{
    if (dim == 0)
        return NULL;
    nb_array_t *array = malloc(sizeof(nb_array_t));
    if (array == NULL)
        return NULL;
    array->shape = malloc(sizeof(uint64_t) * dim);
    if (array->shape == NULL)
    {
        free(array);
        return NULL;
    }
    array->dim = dim;
    array->data_len = 1;
    for (uint64_t i = 0; i < dim; i++)
    {
        array->shape[i] = shape[i];
        array->data_len *= array->shape[i];
    }
    array->data = malloc(sizeof(double) * array->data_len);
    if (array->data == NULL)
    {
        free(array->shape);
        free(array);
    }
    return array;
}

nb_array_t *
nb_array_newv(uint64_t dim, ...)
{
    uint64_t *shape = malloc(sizeof(uint64_t) * dim);
    if (shape == NULL)
        return NULL;
    va_list ap;
    va_start(ap, dim);
    for (uint64_t i = 0; i < dim; i++)
        shape[i] = va_arg(ap, uint64_t);
    nb_array_t *array = nb_array_new(dim, shape);
    free(shape);
    return array;
}

void
nb_array_destroy(nb_array_t *array)
{
    free(array->shape);
    free(array->data);
    free(array);
}

uint64_t
nb_array_data_len(nb_array_t *array)
{
    return array->data_len;
}

void
nb_array_copy_data(double *dest, nb_array_t *array)
{
    memcpy(dest, array->data, array->data_len * sizeof(double));
}

void
nb_array_load_data(nb_array_t *array, double *data)
{
    memcpy(array->data, data, array->data_len * sizeof(double));
}

void
nb_array_fill(nb_array_t *array, double n)
{
    for (uint64_t i = 0; i < array->data_len; i++)
        array->data[i] = n;
}

void
nb_array_scalar_add(nb_array_t *array, double n)
{
    for (uint64_t i = 0; i < array->data_len; i++)
        array->data[i] += n;
}
void
nb_array_scalar_sub(nb_array_t *array, double n)
{
    for (uint64_t i = 0; i < array->data_len; i++)
        array->data[i] -= n;
}

void
nb_array_scalar_mul(nb_array_t *array, double n)
{
    for (uint64_t i = 0; i < array->data_len; i++)
        array->data[i] *= n;
}

void
nb_array_scalar_div(nb_array_t *array, double n)
{
    for (uint64_t i = 0; i < array->data_len; i++)
        array->data[i] /= n;
}

static bool
same_shape(nb_array_t *a, nb_array_t *b)
{
    return a->dim == b->dim &&
           memcmp(a->shape, b->shape, sizeof(double) * a->dim) == 0;
}

void
nb_array_add(nb_array_t *dest, nb_array_t *src)
{
    if (!same_shape(dest, src))
        abort();
    for (uint64_t i = 0; i < dest->data_len; i++)
        dest->data[i] += src->data[i];
}

void
nb_array_sub(nb_array_t *dest, nb_array_t *src)
{
    if (!same_shape(dest, src))
        abort();
    for (uint64_t i = 0; i < dest->data_len; i++)
        dest->data[i] -= src->data[i];
}
void
nb_array_mul(nb_array_t *dest, nb_array_t *src)
{


}

// void
// nb_array_div(nb_array_t *dest, nb_array_t *src);

void
nb_array_print(nb_array_t *array)
{
    // fputc('[', stdout);
    // for (uint64_t i = 0; i < array->shape[0]; i++)
    // {
    //     nb_array_print(nb_array_at(array, 0, -1));
    //     fputc('\n', stdout);
    // }
    // fputc(']', stdout);

    switch (array->dim)
    {
    case 1:
        fputc('[', stdout);
        for (uint64_t i = 0; i < array->shape[0]; i++)
        {
            printf("%.2f", array->data[i]);
            if (i != array->shape[0] - 1)
                fputc(' ', stdout);
        }
        fputc(']', stdout);
        fputc('\n', stdout);
        break;
    case 2:
        fputc('[', stdout);
        for (uint64_t i = 0; i < array->shape[0]; i++)
        {
            if (i != 0)
                fputc(' ', stdout);
            for (uint64_t j = 0; j < array->shape[1]; j++)
            {
                printf("%.2f", array->data[i * array->shape[0] + j]);
                if (j != array->shape[1] - 1)
                    fputc(' ', stdout);
            }
            if (i != array->shape[0] - 1)
                fputc('\n', stdout);
        }
        fputc(']', stdout);
        fputc('\n', stdout);
        break;
    default:
        fprintf(stderr,
                "Not implemented: printing array with dim > 2: dim=%zu\n",
                array->dim);
        abort();
        break;
    }
}
