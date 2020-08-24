#include<stdio.h>
#include<stdlib.h>

void min_heapify(int arr[], int n , int root);
int find_and_move(int *arr[], int x , int size, int *arrays[], int sizes[]);
void swap(int *a, int *b);
int main()
{
//prompt for number of arrays
printf("How many sorted arrays do you want?: ");
 int k;
 scanf("%d",&k);

 int* arrays[k];  //pointers to k-arrays
 int sizes[k];   //sizes of the arrays

 //prompt for the sizes of the arrays
 int i;
 for(i=0;i<k;i++)
 {
  printf("Enter the size of %dth array:", i+1);
  scanf("%d",&sizes[i]);
 }

 //prompt for the elements of the arrays
  for(  i =0; i< k ; i++)
  {
   printf("Enter the elements of arr%d\n",i+1);

   int *index=NULL;
   //malloc space for it
   arrays[i] = (int *)malloc(sizes[i]);
   index = arrays[i];
   for(int j=0; j<sizes[i] ;j++)
    {
     printf("Enter %dth elementh: ",j);
     scanf("%d",index);
     index++;
    }
   }

  //calculate totalsize
  int size=0;
  for(i=0;i<k;i++)
  size = size + sizes[i];

  //initilizing k pointers
  int *kpointers[k];
  for( i=0;i<k;i++)
    kpointers[i] = arrays[i];

   //initilize the min heap
   int minheap[k+1];
   for(i=1;i<k+1;i++)
    minheap[i] = *kpointers[i-1];
        
   //heapify
   for(i= k/2; i>=0; i--)
     min_heapify(minheap, k+1, i);

    int minheapsize = k;

   for(i=0;i<size;i++)
    {
      int min= minheap[1];
      printf("%d ", min);
   //find the array in which min is present and move the pointer to next
            
    int index=  find_and_move(kpointers,min,k,arrays,sizes);

    if(index!=k + 1)   //error check
     {
      int newelement= *kpointers[index]; // insert it to min heap
      minheap[1]= newelement;
      min_heapify(minheap,minheapsize+1,1);
     }
    else
     {
      minheapsize--;
      minheap[1]= minheap[minheapsize+1];
      min_heapify(minheap,minheapsize+1,1);
     }

    }
   printf("\n");

}

void min_heapify(int arr[], int n , int root)
{
    int smallest = root;
    int left = 2*root;
    int right = 2*root +1;

    if(left<n && arr[left]<arr[root])
        smallest = left;

    if(right<n && arr[smallest]>arr[right])
    smallest = right;

    if(smallest!=root)
    {
     swap(&arr[smallest], &arr[root]);
     //min heapify the rest
     min_heapify(arr, n, smallest);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a= *b;
    *b= temp;
}

int find_and_move(int *arr[], int x , int size, int *arrays[], int sizes[])
{
  for(int i=0;i<size;i++)
  {
   if(*arr[i]==x)
   {
     arr[i]++;
     //check if moving the pointer forward is legal
     if(arr[i]-arrays[i]<= sizes[i]-1)
     return i;
     else
     return size + 1;
    }
   }
 return size + 1;
}







