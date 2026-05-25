#include "bdsctest.h"
#include "sort.h"

arrays_equal(arr, expected, len)
int arr[], expected[];
int len;
{
    int i;
    for (i = 0; i < len; i++) {
        if (arr[i] != expected[i]) return 0;
    }
    return 1;
}

copy_array(dst, src, len)
int dst[], src[];
int len;
{
    int i;
    for (i = 0; i < len; i++) {
        dst[i] = src[i];
    }
}

main()
{
    int arr[20];
    int i;

    int unsorted6[6];
    int sorted6[6];

    int already[5];
    int already_exp[5];

    int reverse[5];
    int reverse_exp[5];

    int dups[6];
    int dups_exp[6];

    int single[1];

    int negs[4];
    int negexp[4];

    unsorted6[0]=42; unsorted6[1]=7;  unsorted6[2]=19;
    unsorted6[3]=3;  unsorted6[4]=55; unsorted6[5]=1;
    sorted6[0]=1;    sorted6[1]=3;    sorted6[2]=7;
    sorted6[3]=19;   sorted6[4]=42;   sorted6[5]=55;

    already[0]=10; already[1]=20; already[2]=30;
    already[3]=40; already[4]=50;
    already_exp[0]=10; already_exp[1]=20; already_exp[2]=30;
    already_exp[3]=40; already_exp[4]=50;

    reverse[0]=5; reverse[1]=4; reverse[2]=3;
    reverse[3]=2; reverse[4]=1;
    reverse_exp[0]=1; reverse_exp[1]=2; reverse_exp[2]=3;
    reverse_exp[3]=4; reverse_exp[4]=5;

    dups[0]=4; dups[1]=2; dups[2]=4;
    dups[3]=1; dups[4]=2; dups[5]=3;
    dups_exp[0]=1; dups_exp[1]=2; dups_exp[2]=2;
    dups_exp[3]=3; dups_exp[4]=4; dups_exp[5]=4;

    single[0] = 99;

    negs[0]=-5; negs[1]=3;
    negs[2]=-1; negs[3]=-9;
    negexp[0]=-9; negexp[1]=-5;
    negexp[2]=-1; negexp[3]=3;

    START_TESTING("SELSORT.H -- Selection Sort Unit Tests");

    TEST_CASE("Sort six mixed integers into ascending order");

        copy_array(arr, unsorted6, 6);
        sel_sort(arr, 6);

        ASSERT_EQU(arr[0], sorted6[0]);
        ASSERT_EQU(arr[1], sorted6[1]);
        ASSERT_EQU(arr[2], sorted6[2]);
        ASSERT_EQU(arr[3], sorted6[3]);
        ASSERT_EQU(arr[4], sorted6[4]);
        ASSERT_EQU(arr[5], sorted6[5]);

    TEST_CASE("Already-sorted array is unchanged");

        copy_array(arr, already, 5);
        sel_sort(arr, 5);

        ASSERT_EQU(arr[0], already_exp[0]);
        ASSERT_EQU(arr[1], already_exp[1]);
        ASSERT_EQU(arr[2], already_exp[2]);
        ASSERT_EQU(arr[3], already_exp[3]);
        ASSERT_EQU(arr[4], already_exp[4]);

    TEST_CASE("Reverse-ordered array (worst case for swaps)");

        copy_array(arr, reverse, 5);
        sel_sort(arr, 5);

        ASSERT_EQU(arr[0], reverse_exp[0]);
        ASSERT_EQU(arr[1], reverse_exp[1]);
        ASSERT_EQU(arr[2], reverse_exp[2]);
        ASSERT_EQU(arr[3], reverse_exp[3]);
        ASSERT_EQU(arr[4], reverse_exp[4]);

    TEST_CASE("Array with duplicate values");

        copy_array(arr, dups, 6);
        sel_sort(arr, 6);

        ASSERT_EQU(arr[0], dups_exp[0]);
        ASSERT_EQU(arr[1], dups_exp[1]);
        ASSERT_EQU(arr[2], dups_exp[2]);
        ASSERT_EQU(arr[3], dups_exp[3]);
        ASSERT_EQU(arr[4], dups_exp[4]);
        ASSERT_EQU(arr[5], dups_exp[5]);

    TEST_CASE("Single-element array (edge case: nothing to sort)");

        arr[0] = single[0];
        sel_sort(arr, 1);

        ASSERT_EQU(arr[0], 99);

    TEST_CASE("Array containing negative numbers");

        copy_array(arr, negs, 4);
        sel_sort(arr, 4);

        ASSERT_EQU(arr[0], negexp[0]);
        ASSERT_EQU(arr[1], negexp[1]);
        ASSERT_EQU(arr[2], negexp[2]);
        ASSERT_EQU(arr[3], negexp[3]);

    TEST_CASE("find_min_index returns correct index in subarray");

        arr[0]=10; arr[1]=3; arr[2]=7; arr[3]=1; arr[4]=9;

        ASSERT_EQU(find_min_index(arr, 1, 5), 3);
        ASSERT_EQU(find_min_index(arr, 0, 5), 3);
        ASSERT_EQU(find_min_index(arr, 2, 5), 3);

    END_TESTING();
}
