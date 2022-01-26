#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "numb/array.h"

nb_array_t *nb_array_new(size_t dim, ...)
{
    va_list ap;

    if (dim == 0)
        return NULL;
    nb_array_t *array = malloc(sizeof(nb_array_t));
    if (array == NULL)
        return NULL;
    array->shape = malloc(sizeof(size_t) * dim);
    if (array->shape == NULL)
    {
        free(array);
        return NULL;
    }
    array->dim = dim;
    va_start(ap, dim);
    array->data_len = 1;
    for (size_t i = 0; i < dim; i++)
    {
        array->shape[i] = va_arg(ap, size_t);
        array->data_len *= array->shape[i];
    }
    array->data = malloc(sizeof(double) * array->data_len);
    va_end(ap);
    return array;
}

void nb_array_destroy(nb_array_t *array)
{
    free(array->shape);
    free(array->data);
    free(array);
}

void nb_array_print(nb_array_t *array)
{
    // fputc('[', stdout);
    // for (size_t i = 0; i < array->shape[0]; i++)
    // {
    //     nb_array_print(nb_array_at(array, 0, -1));
    //     fputc('\n', stdout);
    // }
    // fputc(']', stdout);

    switch (array->dim)
    {
    case 1:
        fputc('[', stdout);
        for (size_t i = 0; i < array->shape[0]; i++)
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
        for (size_t i = 0; i < array->shape[0]; i++)
        {
            if (i != 0)
                fputc(' ', stdout);
            for (size_t j = 0; j < array->shape[1]; j++)
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
        fprintf(stderr, "Not implemented: printing array with dim > 2: dim=%zu\n", array->dim);
        abort();
        break;
    }

}
