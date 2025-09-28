#include<stdio.h>


void insertion_sort(int arr[] , int n){
    for(int i = 0 ; i < n ;i++){
        int key = arr[i];
        int j = i -1;
        
        while (j >=0 && key < arr[j ])
        {
            arr[j+1 ] = arr[j ];
            j--;
        }
        arr[j+1] = key;
        
    }
}

void selection_sort(int arr[] , int size){
    for(int  i = 0 ; i< size ; i++){
        int key  = arr[i];
        int smallest_index = i;

        for(int j = i+1 ; j< size; j++){
            if(key > arr[j]){
                key = arr[j];
                smallest_index = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[smallest_index];
        arr[smallest_index] = temp;
        
        

    }
}

void merge(int arr[] , int st , int mid , int end){
    int i = st , j = mid+1;
    int temp[end-st+1];
    int k = 0;
    while (i<=mid && j <= end)
    {
        if(arr[i]>arr[j]){
            temp[k++ ] = arr[j++];
        }else{
            temp[k++] = arr[i++];
        }
    }

    while (i<=mid)
    {
        temp[k++] = arr[i++];
    }
    while (j<=end)
    {
        temp[k++] = arr[j++];
    }
    
    for(int i = 0 ; i < k  ; i++){
        arr[i+st]  = temp[i]; 
    }
    
}


void merge_sort(int arr[] , int st , int end){
    if (st<end)
    {
        int mid = st + (end - st)/2;
        merge_sort(arr,st,mid);//left half
        merge_sort(arr, mid+1 , end); //right half
        merge(arr,st,mid,end);

    }
    
}


int partition(int arr[] , int st , int end){
    int idx = st-1 , pivot = arr[end];
    for(int j = st ; j <  end ; j ++){

        if(arr[j]< pivot){
            int temp = arr[++idx];
            arr[idx] = arr[j];
            arr[j] = temp;
        }
    }
    arr[end] = arr[++idx];
    arr[idx] = pivot;

    return idx;
}



void quick_sort(int arr[], int st , int end){
    if(st<end)
    {
        int pivId = partition(arr ,st , end);
        quick_sort(arr, st , pivId -1);
        quick_sort(arr,  pivId +1 , end);
    }
    
}
