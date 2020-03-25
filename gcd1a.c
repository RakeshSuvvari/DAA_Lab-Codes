#include<stdio.h>
int main()
{
 
 int a,b,gcd;//iterative
 
 printf("enter two numbers:\n");
 scanf("%d",&a);
 scanf("%d",&b);
 
 if(a<0)
  a=-a;
 
 if(b<0)
  b=-b;
 
 for(int i=1;i<=a && i<=b;i++)//gcd is lessthan or equal to min of both the numbers
 {
  if(a%i==0 && b%i==0)
   gcd=i;
 }
 
 if(a==0 && b==0)
  gcd=0;
 else if(a==0 && b!=0)
  gcd=b;
 else if(a!=0 && b==0)
  gcd=a;
  
printf("GCD is:%d ",gcd);
 return 0;
}
