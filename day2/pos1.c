#include<stdio.h>
int main()
{
 int a[10000],i;

 
 printf("Elements must be entered in non decreasing order:\n");
 
 for(i=0; ;i++)
 {
  scanf("%d",&a[i]);
  if(a[i-1]==-1 && a[i]!=-1)//give any number after -1 to break the prompt
   break;
 }
 //linear search through out the array 
 for(i=0;i<10000;i++)
 {
  if(a[i]==-1)
   break;
 }
 
 printf("Position of first -1 is:%d",i);//counting of position starts from 0.
}
