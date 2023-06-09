#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "IntVector.h"

int main()
{
    struct IntVector *a1;
    struct IntVector *a2;
    a1 = int_vector_new(87);
    a2 = int_vector_copy(a1);

    int_vector_push_back(a2,321);
    int_vector_push_back(a2,123);
    int_vector_push_back(a2,612);
    int_vector_push_back(a2,4);
    printf("new and copy   capacity - %zu size - %zu", int_vector_get_capacity(a2), int_vector_get_size(a2));
   prmas(a2);



    int_vector_shrink_to_fit(a2);
    printf("shrink to fit  capacity - %zu size - %zu ", int_vector_get_capacity(a2), int_vector_get_size(a2));
   prmas(a2);

    int_vector_pop_back(a2);
    printf("pop back       capacity - %zu size - %zu ", int_vector_get_capacity(a2), int_vector_get_size(a2));
   prmas(a2);

    int_vector_reserve(a2, 12);
    printf("reserve        capacity - %zu size - %zu ", int_vector_get_capacity(a2), int_vector_get_size(a2));
   prmas(a2);

    //пытаемся выделить с помощью Int_vector_resize меньше памяти, чем было, смотрим что получается
    int_vector_resize(a2, 2);
    printf("resize         capacity - %zu size - %zu ", int_vector_get_capacity(a2), int_vector_get_size(a2)); 
   prmas(a2);

    int_vector_resize(a2, 7);
    printf("resize         capacity - %zu size - %zu ", int_vector_get_capacity(a2), int_vector_get_size(a2));
   prmas(a2);

    int_vector_push_back(a2, 1337);
    printf("pushback       capacity - %zu size - %zu ", int_vector_get_capacity(a2), int_vector_get_size(a2));
   prmas(a2);

    int_vector_pop_back(a2);
    printf("pop back       capacity - %zu size - %zu ", int_vector_get_capacity(a2), int_vector_get_size(a2));
   prmas(a2);

    int_vector_shrink_to_fit(a2);
    printf("shrink to fit  capacity - %zu size - %zu ", int_vector_get_capacity(a2), int_vector_get_size(a2));
   prmas(a2);

    int_vector_free(a1);
    a1 = int_vector_copy(a2);
    printf("a1 copy        capacity - %zu size - %zu ",int_vector_get_capacity(a2),int_vector_get_size(a2));
   prmas(a1);

    int_vector_set_item(a2, 3, 1488);
    printf("set item       capacity - %zu size - %zu ", int_vector_get_capacity(a2), int_vector_get_size(a2));
   prmas(a2);


    int_vector_free(a1);
    int_vector_free(a2);
    return 0;
}