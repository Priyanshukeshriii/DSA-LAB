#include<stdio.h>
void insertion_sort(int arr[], int n){
    for(int i = 1 ; i< n ; i++){
        int key = arr[i];
        int j = i-1;
        //checking the correct position
        while (j>=0 && arr[j] > key)
        {
            arr[j+1] = arr[j]; 
            j--;

        }
        arr[j+1] = key;
        
        //print array for every pass 
        printf("pass %d: " , i);
        for (int i = 0; i < n; i++)
        {
            printf("%d, ",arr[i]);
        }
        printf("\n");
        


         
    }
}
int main(){
    int arr[] ={5,4,3,1,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertion_sort(arr,n);

}