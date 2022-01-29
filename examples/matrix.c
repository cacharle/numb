#include "numb/array.h"

int
main(void)
{
    nb_array_t *array1 = nb_array_newv(2, 3, 3);
    nb_array_fill(array1, 42.42);

    nb_array_t *array2 = nb_array_newv(2, 3, 3);
    nb_array_fill(array2, 1.0);

    nb_array_mul(array1, array2);
    nb_array_print(array1);

    // nb_array_print(array);
    // nb_array_scalar_add(array, 1.0);
    // nb_array_print(array);
    // nb_array_scalar_sub(array, 1.0);
    // nb_array_print(array);
    // nb_array_scalar_div(array, 2.0);
    // nb_array_print(array);
    // nb_array_scalar_mul(array, 2.0);
    // nb_array_print(array);

    nb_array_destroy(array1);
    nb_array_destroy(array2);
    return 0;
}
