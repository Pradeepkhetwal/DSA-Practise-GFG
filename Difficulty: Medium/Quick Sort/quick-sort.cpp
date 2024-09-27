//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if(low<high){
        int x = partition(arr,low,high);
        
        
        //for left subarray.
        
        quickSort(arr,low , x-1);
        
        //for right subarry.
        quickSort(arr,x+1,high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       
       
       // I am choosing the pivot as the right most index.
       int pivot = arr[high];
       
       int i = low - 1;
       
       for(int j = low ; j<high ; j++){
           if(arr[j]<pivot){
               i++;
               int t = arr[j];
               arr[j] = arr[i];
               arr[i] = t;
           }
       }
       
    int t = arr[i+1] ;
    arr[i+1] = arr[high];
    arr[high]= t;
    
    return i+1;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends