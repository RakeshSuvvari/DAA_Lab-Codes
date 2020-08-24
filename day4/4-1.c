#include<stdio.h>

//counting of n numbers GCD using D_C

int gcd(int a, int b); 
int divd(int p,int q);

int a[100];

int main()
{
    int n,x,y;
    printf("Enter no. of nuumbers:\n");
    scanf("%d",&n);
    
    printf("enter the numbers\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    int k=divd(0,n-1);
    printf("The gcd is: %d \n",k);    
    
    return 0;

}

int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
}

//dividing of the array //combining the one's gcd to next number
int divd(int p,int q)
{
     if(p<q)
     {
        int m=(p+q)/2;
        int x=divd(p,m);
        int y=divd(m+1,q);
        return gcd(x,y);
     }
     else return a[p];//returns array elements to x and y to find GCD 
}



