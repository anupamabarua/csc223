find_min_index(arr, start, len)
int arr[];
int start, len;
{
    int min_idx;   /* index of smallest number seen so far  */
    int i;         /* loop counter                          */

    min_idx = start;

    for (i = start + 1; i < len; i++) {
        if (arr[i] < arr[min_idx]) {
            min_idx = i;
        }
    }

    return min_idx;
}

sel_sort(arr, len)
int arr[];
int len;
{
    int i;        /* index of the slot being filled this pass */
    int min_idx;  /* index of minimum in the unsorted portion */
    int tmp;      /* temporary holding value for the swap     */

    for (i = 0; i < len - 1; i++) {

        /* Step 1: find the smallest remaining element */
        min_idx = find_min_index(arr, i, len);

        /* Step 2: swap it into position i (skip if already there) */
        if (min_idx != i) {
            tmp         = arr[i];
            arr[i]      = arr[min_idx];
            arr[min_idx] = tmp;
        }
    }
}
