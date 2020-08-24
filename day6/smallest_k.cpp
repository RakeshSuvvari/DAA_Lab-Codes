#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Finding k smallest elements using quicksort partition routine

void ksmallest(int a[], int low, int high, int k);
int partition(int a[],int low, int high);
void printarr(int a[], int low, int high );
void swap(int *a, int*b);

int main()
{   
    int n,arr[n],k;
    printf("Enter the array size:");
    scanf("%d",&n);
    
    printf("\nenter elements:\n");
    for(int i=0;i<n;i++)
    {
    	scanf("%d",&arr[i]);
    }
    printf("enter size of k:\n");
	scanf("%d",&k);
    ksmallest(arr,0,n-1,k);

}

void ksmallest(int a[], int low, int high, int k)
{
    if(low<high)
    {
        int p=partition(a,low,high);
       if(p==k+1 || p==k)
        printarr(a,low,k-1);
       else
        { 
            printarr(a,low,p);
            ksmallest(a,p+1,high,k-p);
        }
    }
}

int partition(int a[],int low, int high)
{
    int pivot = a[high];
    int s_w = low -1; //small window

    for(int i=low; i<=high - 1; i++)
    {
        if(a[i]<=pivot)
        {
            s_w++;
            swap(&a[i],&a[s_w]);
        }
    }
    swap(&a[high],&a[s_w+1]);

 return s_w+1;
}
void swap(int *a, int*b)
{
    int temp = *a;
    *a= *b;
    *b= temp;
}
void printarr(int a[], int low,int high)
{
    for(int i=low;i<=high;i++)
    cout<<a[i]<<" ";
}
