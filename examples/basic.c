#include "numb/array.h"

int main(void)
{
    nb_array_t *array = nb_array_new(2, 5, 5);

    nb_array_print(array);

    nb_array_destroy(array);
    return 0;
}
