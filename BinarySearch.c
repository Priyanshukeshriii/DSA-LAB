#include<stdio.h>
int main(){
    int n;
    printf("Enter the length of array\n");
    scanf("%d",&n);
    int sorted_arr[n];
    
    for(int i =0 ; i< n ; i++){
        printf("Enter the elements of array: \n");
        scanf("%d", &sorted_arr[i]); 
        
    }
    printf("Enter the target : \n");
    
    int tar ;

    scanf("%d",&tar);
    int st= 0 , end = n-1;
    int mid;
    int pos = -1;
    while (st<= end)
    {
        mid = st + (end - st)/2;   
        if (sorted_arr[mid] == tar){
            pos = mid; 
            break;
        }
        else if (sorted_arr[mid] < tar)
        {
            st = mid+ 1;
        }
        else if (sorted_arr[mid] > tar)
        {
            end = mid - 1;
        }
    }
    printf("The index of tar is %d", pos);
    return 0 ;
    
}