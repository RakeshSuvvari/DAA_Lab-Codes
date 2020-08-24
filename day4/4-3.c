#include<stdio.h>

//counting no. of negative numbers in input numbers
int divd(int p,int q);

int a[100];
int main()
{
    int n,x,y;
    printf("Enter size:\n");
    scanf("%d",&n);
    
    printf("enter the numbers:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    int k=divd(0,n-1);
    printf("The no. of negative numbers are: %d\n",k);
    return 0;

}

int divd(int p,int q)
{
    
     if(p<q)
     {
        int m=(p+q)/2;
       
        return divd(p,m)+divd(m+1,q);// takes truth value from return either 0 or 1 and adds them.
     }
     else 
        return a[p]<0;// returns truth value of (a[p]<0) to divd function 
}

