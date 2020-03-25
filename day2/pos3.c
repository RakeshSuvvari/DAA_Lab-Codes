#include<stdio.h>
#include<stdlib.h>
int main ()
{
    
  int a[100];

    int i=0;
    char c;
    
    printf("enter other than 'e' to continue:");//enter any key other than 'e' to continue
    c=getchar();
    while( c!= 'e')
    {   
        printf("Enter the value for a[%d] : ",i);
        scanf("%d",&a[i]);
        getchar();
        i++;
        printf("enter 'e' to exit or any key to continue: " );//enter 'e' to exit the prompt
        c=getchar();
    }
   
   
    for(i=0; ;i++)//search to find pos of -1
    {
        if(a[i]==-1)
            {
                printf("position of first -1 is:%d",i);
                exit(0);
            }
    }
}
