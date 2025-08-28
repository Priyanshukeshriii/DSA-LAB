#include<stdio.h>
int main() {
    int n;
    printf("Enter the length of array\n");
    scanf("%d",&n);
    int arr[n];
    
    for(int i =0 ; i< n ; i++){
        printf("Enter the elements of array: \n");
        scanf("%d", &arr[i]); 
    }
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if(arr[j]> arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        printf("pass %d :" , i+1);
        for (int k = 0; k < n; k++)
        {
            printf("%d ,",arr[k]);
        }
        printf("\n");
        
        
    }
    
    return 0 ;
}