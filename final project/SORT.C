#include <stdio.h>
#include "sort.h"

#define MAX_ITEMS  100          /* maximum number it can sort   */
#define IN_FILE    "INPUT.TXT"  /* number file     */
#define OUT_FILE   "OUTPUT.TXT" /* file write sorted numbers */

/*
 * read_data
 *
 * Opens IN_FILE, reads the count, then reads that many integers
 * into arr[].  Returns the count on success, -1 on any error.
 */
read_data(arr)
int arr[];
{
    FILE *fp;
    int   count;   /* number of items stated in the file */
    int   i;       /* loop index                         */

    fp = fopen(IN_FILE, "r");
    if (fp == NULL) {
        printf("Error: cannot open %s\n", IN_FILE);
        return -1;
    }

    /* First line is the item count */
    if (fscanf(fp, "%d", &count) != 1) {
        printf("Error: cannot read count from %s\n", IN_FILE);
        fclose(fp);
        return -1;
    }

    if (count < 1 || count > MAX_ITEMS) {
        printf("Error: count %d is out of range (1-%d)\n", count, MAX_ITEMS);
        fclose(fp);
        return -1;
    }

    /* Read each integer into the array */
    for (i = 0; i < count; i++) {
        if (fscanf(fp, "%d", &arr[i]) != 1) {
            printf("Error: expected %d numbers but found only %d\n", count, i);
            fclose(fp);
            return -1;
        }
    }

    fclose(fp);
    return count;
}

/*
 * write_data
 *
 * Opens OUT_FILE and writes arr[0..count-1], one integer per line.
 * Returns 0 on success, -1 on error.
 */
write_data(arr, count)
int arr[];
int count;
{
    FILE *fp;
    int   i;

    fp = fopen(OUT_FILE, "w");
    if (fp == NULL) {
        printf("Error: cannot open %s for writing\n", OUT_FILE);
        return -1;
    }

    fprintf(fp, "%d\n", count);          /* count on first line */
    for (i = 0; i < count; i++) {
        fprintf(fp, "%d\n", arr[i]);
    }

    fclose(fp);
    return 0;
}

/*
 * print_array
 */
print_array(arr, count)
int arr[];
int count;
{
    int i;
    for (i = 0; i < count; i++) {
        if (i > 0) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
}

main()
{
    int data[MAX_ITEMS];   /* the numbers to sort   */
    int count;             /* how many we actually have */

    printf("Selection Sort\n");
    printf("==============\n");

    /* --- 1. Read input --- */
    count = read_data(data);
    if (count < 0) {
        printf("Aborting.\n");
        exit(1);
    }
    printf("Read %d numbers from %s\n", count, IN_FILE);

    /* --- 2. Show original order --- */
    printf("Before: ");
    print_array(data, count);

    /* --- 3. Sort --- */
    sel_sort(data, count);

    /* --- 4. Show sorted order --- */
    printf("After:  ");
    print_array(data, count);

    /* --- 5. Write output --- */
    if (write_data(data, count) == 0) {
        printf("Sorted data written to %s\n", OUT_FILE);
    }
}
