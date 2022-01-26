#include "numb/array.h"

int
main(void)
{
    nb_array_t *array = nb_array_new(2, 3, 3);
    nb_array_fill(array, 42.42);

    // nb_array_print(array);
    // nb_array_scalar_add(array, 1.0);
    // nb_array_print(array);
    // nb_array_scalar_sub(array, 1.0);
    // nb_array_print(array);
    // nb_array_scalar_div(array, 2.0);
    // nb_array_print(array);
    // nb_array_scalar_mul(array, 2.0);
    // nb_array_print(array);

    nb_array_destroy(array);
    return 0;
}
