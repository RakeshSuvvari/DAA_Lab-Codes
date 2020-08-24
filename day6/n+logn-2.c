#include<stdio.h>
struct Heap
{
	int arr[50];
	int last; 
};
struct Heap H;
void insert(int p);
int delete();
int main()
{
    printf("Enter the number of elements\n");
       H.last=0;

    int n,i,k,min,b;
    scanf("%d",&n);

    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
      scanf("%d",&b);
      insert(b);
    }
   
    
    
    printf("the first min is %d",delete());
    H.arr[0];
    min=H.arr[H.last];
    for(i=H.last;i>=1;i--)
    {
        if(min>H.arr[i])
        {
            min=H.arr[i];
        }
    }


    printf("The second min is %d",min);
}
void insert(int p)
{
	H.last++;
	H.arr[H.last] = p;
	int t = H.last;
	while((t/2 >= 1) && (H.arr[t] <= H.arr[t / 2]))
	{
		H.arr[t] = H.arr[t] ^ H.arr[t/2];
		H.arr[t/2] = H.arr[t] ^ H.arr[t/2];
		H.arr[t] = H.arr[t] ^ H.arr[t/2];
		t /= 2;
	}
}
int delete()
{
	int x = H.arr[1];
	H.arr[1] = H.arr[H.last];
	H.last--;
	int t = 1;
	int mi;
	while(2*t  <= H.last)
	{
		if(H.last >= 2*t+1)
		{
			if(H.arr[2*t] < H.arr[2*t+1])
				mi = 2*t;
			else 
				mi = 2*t+1;
		}
		else 
			mi = 2*t;
		if(H.arr[t] > H.arr[mi])
		{
			H.arr[t] = H.arr[t] ^ H.arr[mi];
			H.arr[mi] = H.arr[t] ^ H.arr[mi];
			H.arr[t] = H.arr[t] ^ H.arr[mi];
			t = mi;
		}
		else break;
	}
	return x;
}
