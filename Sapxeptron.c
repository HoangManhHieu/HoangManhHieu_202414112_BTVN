#include <stdio.h>
void merge(int arr[], int a[], int left, int mid, int right, int lenght) {
    int i, j, k;
    for (k = left; k <= right; k++) {
        a[k] = arr[k];
    }

    i = left;  
    j = mid + 1; 
    k = left;    
    while (i <= mid || j <= right) {
        if (i > mid) {
            arr[k++] = a[j++];
        } 
        else if (j > right) {
            arr[k++] = a[i++];
        } 
        else if (a[i] <= a[j]) {
            arr[k++] = a[i++];
        } else {
            arr[k++] = a[j++];
        }
    }
    for (int idx = 0; idx < lenght; idx++) {
        printf("%d", arr[idx]);
        if (idx < lenght - 1) {
            printf(" ");
        }
    }
    printf("\n");
}
void mergeSort(int arr[], int a[], int left, int right, int lenght) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, a, left, mid, lenght);
        mergeSort(arr, a, mid + 1, right, lenght);
        merge(arr, a, left, mid, right, lenght);
    }
}
void printArray(int A[], int lenght) {
    for (int i = 0; i < lenght; i++)
        printf("%d ", A[i]);
    printf("\n");
}
int main() {
    int arr[] = {8, 3, 4, 1, 7, 5, 2, 6};
    int lenght = 8;
    int aux[lenght]; 
    mergeSort(arr, aux, 0, lenght - 1, lenght);
    printf("Mảng sau khi sắp xếp: ");
    printArray(arr, lenght);
    return 0;

}
