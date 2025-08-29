#include<stdio.h>

int comparisons = 0;
int iterations = 0;

void printArray(int arr[] , int n){
    for(int i  = 0 ; i< n ; i++){
        printf("%d, " ,arr[i] );
    }
    printf("\n");
}



void insertion_sort(int arr[], int n){
    for(int i = 1 ; i< n ; i++){
        int key = arr[i];
        int j = i-1;
        iterations++;

        //checking the correct position
        while (j>=0 && arr[j] > key)
        {
            comparisons++;
            arr[j+1] = arr[j]; 
            j--;

        }
        arr[j+1] = key;
        
        //print array for every pass 
        printf("pass %d: " , i);
        printArray(arr,n);
        


         
    }
}
int main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal Array: ");
    printArray(arr, n);

    insertion_sort(arr,n);

    printf("\nFinal Sorted Array: ");
    printArray(arr, n);

    printf("\nTotal Iterations: %d", iterations);
    printf("\nTotal Comparisons: %d\n", comparisons);

    

}