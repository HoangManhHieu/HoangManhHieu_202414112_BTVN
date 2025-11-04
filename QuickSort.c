#include<stdio.h>
void swap( int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void printArray(int arr[], int n, int left, int right, int point) {
    for(int i = 0; i < n; i++)
            printf("%d ", arr[i]); 
    printf("\n");
}
int ActiveFunc(int arr[], int left, int right, int n){
    int point = arr[left]; 
    int i = left + 1;
    int j = right;
    
    while( i <= j){
        while( i <= right && arr[i] < point) i++; 
        while( arr[j] > point) j--;
        
        if( i < j){
            swap(&arr[i], &arr[j]);
            i++; 
            j--;
        } else {
            break; 
        }
    }
    swap( &arr[left], &arr[j]); 
    printArray(arr, n, left, right, n);
    return j; 
}
void QuickSort( int arr[], int left, int right, int n){
    if( right > left) {
        int active = ActiveFunc(arr, left, right, n); 
        QuickSort(arr, left, active - 1, n);
        QuickSort(arr, active + 1, right, n);
    }
}

int main(){
    int arr[] = {4, 5, 3, 2, 16, 78, 7, 98};
    int n;
    n = 8;
    QuickSort(arr, 0, n - 1, n); 
    for( int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}