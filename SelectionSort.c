#include<stdio.h>
void selectionSort(int arr[] ,int n){
    for(int i =0 ; i< n; i++){
        int small = arr[i];
        int indexOfSmall = i;
        for (int j= i+1; j <n ; j++){
            if(small > arr[j]){
                small = arr[j];
                indexOfSmall = j ;
            }
        }
         
        while (indexOfSmall -1 >=0 && small < arr[indexOfSmall-1] )
        {
            arr[indexOfSmall] = arr[indexOfSmall -1];
            indexOfSmall--;
        }
        arr[indexOfSmall] = small;
        
        printf("pass %d: " , i);
        for (int i = 0; i <n; i++)
        {
            printf("%d, ",arr[i]);
        }
        printf("\n");
        

    }
}

int main(){
    int arr[] ={5,4,3,1,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr , n);
}