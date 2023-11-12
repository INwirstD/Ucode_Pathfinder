#include "libmx.h"

int mx_quicksort(char **arr, int left, int right) {
    if (!arr) return -1;

    int count = 0;

    if (left <= right) {
        char *pt = arr[(left + right) / 2];

        while (left <= right) {
            while (mx_strlen(arr[left]) < mx_strlen(pt)) left++;
            while (mx_strlen(arr[right]) > mx_strlen(pt)) right--;

            if (left <= right) {
                if (mx_strlen(arr[right]) != mx_strlen(arr[left])) {
                    char *temp = arr[left];
                    arr[left] = arr[right];
                    arr[right] = temp;
                    count++;
                }
                left++;
                right--;
            }
        }

        count += mx_quicksort(arr, left, right);
        count += mx_quicksort(arr, left, right);
    }
    
    return count;
}
