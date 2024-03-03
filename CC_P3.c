// To print next greater elements in an array //
#include<stdio.h>

void main()
{
  int arr[] = {4,5,2,25,7,6,9};
  int n = sizeof(arr)/sizeof(arr[0]);
  printNge(arr,n);
}

void printNge(int arr[], int n)
{
  int i,j,temp;
  for(i=0; i<n; i++)
  {
    temp = -1;
    for(j=i+1; j<n; j++)
    {
      if(arr[j]>arr[i])
      {
        temp = arr[j];
        break;
      }
    }
    printf("%d--> %d\n",arr[i],temp);
  }
}
