#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* lptr;
    struct node* rptr;
}node;

node* root= NULL; //create empty BST

node* insert(int x, node*ptr);

node* createnode(int x);

void inorder(node* ptr);



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

//initilizing k pointers
 int *kpointers[k];
 for( i=0;i<k;i++)
   kpointers[i] = arrays[i];
        
  while(1)
  {
   for(int j=0;j<k;j++)
    {
     if(kpointers[j]-arrays[j]<=sizes[j]-1)
      {
       root=insert(*kpointers[j], root);
       kpointers[j]++;
      }

    }
   if(root!=NULL)
    {
     inorder(root);
     root=NULL;
    }
   else
     exit(0);
   }
  printf("\n");

}


node* createnode(int x)
{
  node* temp = (node*) malloc(sizeof(node));
  temp->data= x;
  temp->lptr= NULL;
  temp->rptr= NULL;
 return temp;
}

node* insert(int x, node*ptr)
{
  if(ptr==NULL)
    ptr= createnode(x);

  else if(ptr->data > x)
    ptr->lptr = insert(x,ptr->lptr);

  else
    ptr->rptr= insert(x,ptr->rptr);

 return ptr;
}


void inorder(node* ptr)
{
  if(ptr!=NULL)
  {
   inorder(ptr->lptr);
   printf("%d ",ptr->data);
   inorder(ptr->rptr);
   }
}










