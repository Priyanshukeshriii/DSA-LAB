#include<stdio.h>
int main(){
   int n;
    printf("Enter the length of array\n");
    scanf("%d",&n);
    int arr[n];
    
    for(int i =0 ; i< n ; i++){
        printf("Enter the elements of array: \n");
        scanf("%d", &arr[i]); 
        
    }
    printf("Enter the target : \n");
    
    int tar ;

    scanf("%d",&tar);
   for (int i = 0 ; i < n ; i++){
    if (arr[i] == tar){
        printf("%d\n",arr[i]);
        printf("The index of the target is %d", i);
        break;
    }
    printf("%d",arr[i]);
    printf("\n");
   }
    return 0 ;
}