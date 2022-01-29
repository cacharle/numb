#include "numb/array.h"

int
main(void)
{
    nb_array_t *array1 = nb_array_newv(1, 3);
    nb_array_fill(array1, 2.0);

    nb_array_t *array2 = nb_array_newv(1, 3);
    nb_array_fill(array2, 3.0);

    nb_array_print(array1);
    nb_array_print(array2);

    nb_array_mul(array1, array2);

    nb_array_print(array1);

    nb_array_destroy(array1);
    nb_array_destroy(array2);
    return 0;
}
