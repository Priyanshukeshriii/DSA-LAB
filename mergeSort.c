#include<stdio.h>

int comparisons = 0;
int iterations = 0;


void printArray(int arr[] , int n){
    for(int i  = 0 ; i< n ; i++){
        printf("%d, " ,arr[i] );
    }
    printf("\n");
}




void merge(int arr[] ,int st , int end , int mid,int n){
    int i = st; 
    int j = mid +1;
    int temp[end - st +1];
    int index = 0 ;
    iterations++;

    while (i<= mid && j<= end) 
    {
        comparisons++;
        if(arr[j] >= arr[i]){
            temp[index] = arr[i];
            i++;
        }else if (arr[j] < arr[i]){
            temp[index] = arr[j];
            j++;
        }
        index++;
    }
    //copying the left part of array 
    while (i<= mid)
    {
        temp[index] = arr[i];
        i++;
        index++;
    }
    // copying the right part of array 
    while (j<= mid)
    {
        temp[index] = arr[j];
        j++;
        index++;
    }
    //copying the array into original array
    for (int i = 0; i < index; i++)
    {
        arr[i +st] = temp[i];
    }


    printf("After iteration %d: ", iterations);
    printArray(arr, n);    
}

void merge_Sort(int arr[] , int st , int end,int n){
    int mid = st + (end - st)/2;
    if(st<end){
        merge_Sort(arr , st , mid,n); // left half
        merge_Sort(arr , mid+1 , end,n); // right half
        merge(arr,st,end,mid,n);
    }
}


int main() {
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

    merge_Sort(arr, 0, n - 1, n);

    printf("\nFinal Sorted Array: ");
    printArray(arr, n);

    printf("\nTotal Iterations: %d", iterations);
    printf("\nTotal Comparisons: %d\n", comparisons);

    return 0;
}
