#include<stdio.h>
void partition(int arr[] , int left, int right , int loc){
    while (!(loc == left && loc == right))
    {
        if(loc == left){
            if (arr[loc] > arr[right]){
                int temp = arr[loc];
                arr[loc] = arr[right];
                arr[right] = temp;
                loc = right;
                left++;
            }
            else{
                right--;
            }
        }
        else{
            if(arr[loc] < arr[left]){
                int temp1  = arr[loc];
                arr[loc] = arr[left];
                arr[left]  = temp1;
                loc = left;
                right--;
            }
            else{
                left++;
            }
        }
    }
    
}

void quick_sort(int arr[], int left, int right) {
    
    int loc = left;
    if (left < right)
    {
        partition(arr, left, right, loc);
        quick_sort(arr, left, loc - 1);
        quick_sort(arr, loc + 1, right);
    }
    
}




int main(){
    int n ;
    printf("enter the length of array: ");
    scanf("%d" , &n);
    int arr[n];
    for(int i =0 ; i < n ; i++){
        printf("enter the element of array: ");
        scanf("%d" , &arr[i]);
    }
    quick_sort(arr , 0 , n-1 );
    for (int i = 0; i < n; i++)
    {
        printf("%d," , arr[i]);
    }
    

}