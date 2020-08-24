#include<stdio.h>
#include<stdlib.h>
//counting no. of ones in a binary_number using D_C
int divd(int p,int q);

int a[100];
int main()
{
    int n,x,y;
    printf("Enter size of binary_number:\n");
    scanf("%d",&n);
    
    printf("enter the binary_number:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        
        if(a[i]==1 || a[i]==0)//only 1s and 0s are allowed
        {
          continue;
        }
        else
        {
         printf("ERROR enter valid binary_number:\n");
          exit(0);
        }
    }
    
    int k=divd(0,n-1);
    printf("The no. of one's are: %d \n",k);    
    return 0;

}

int divd(int p,int q)
{
     if(p<q)
     {
        int m=(p+q)/2;
       
        return divd(p,m)+divd(m+1,q);//adds the all elements in array to get no. of 1,s in the number
     }
     else return a[p];//returns the each element in the array to div function
}
     //ex: 1 0 1 1 = 1+0+1+1=3 ones.
     
     
     

