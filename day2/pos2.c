#include<stdio.h>
#define SIZE 12
int position(int a[],int size,int p);

int main()
{
 int a[SIZE],p=-1;
 
 //fill the whole array with -1
 for(int i=0;i<SIZE;i++)
 {
  a[i]=-1;
 }
 
 printf("Elements must be entered in non decreasing order:\n");
 
 for(int i=0;i<SIZE;i++)
 {
  scanf("%d",&a[i]);
  if(a[i]==-1)// if -1 is entered the prompt would stop
   break;
 }
 
int k=position(a,SIZE,p);
printf("the position of first -1 is:%d\n",k);//counting of position starts from 0.
 
}

int position(int a[],int size,int p)//like binary search varient
{
 int beg=0,end=size;
 while(beg<=end)
 {
  int mid=(beg+end)/2;
  if(a[mid]==p)
  {
   if(a[mid-1]!=p)
    return mid;
   else
    end=mid;
  }
  
  else
  {
    if(a[mid+1]==p)
     return mid+1;
    else
     beg=mid+1;
  }
 }
}
















