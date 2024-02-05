#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "fisher_yates.h"

TEST_CASE("Testing swap function") {
    int a = 5, b = 10;
    swap(&a, &b);
    CHECK(a == 10);
    CHECK(b == 5);
}

TEST_CASE("Testing Fisher-Yates shuffle") {
    const int length = 5;
    int original_array[length] = {1, 2, 3, 4, 5};
    int shuffled_array[length];


    for (int i = 0; i < length; i++) {
        shuffled_array[i] = original_array[i];
    }

    fisher_yates(shuffled_array, length);

    
    for (int i = 0; i < length; i++) {
        bool found = false;
        for (int j = 0; j < length; j++) {
            if (original_array[i] == shuffled_array[j]) {
                found = true;
                break;
            }
        }
        CHECK(found);
    }
}
