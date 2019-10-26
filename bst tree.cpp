//bst tree
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *left,*right;
}tree; 



void preorder(node *T)
{
	if(T!=NULL)
	{
		printf("%d ",T->data);
		preorder(T->left);
		preorder(T->right);
	}
	
}


void postorder(node *T)
{
	if(T!=NULL)
	{
		postorder(T->left);
		postorder(T->right);
		printf("%d ",T->data);
	}
	
}


void inorder(node *T)
{
	if(T!=NULL)
	{
		inorder(T->left);
		printf("%d ",T->data);
		inorder(T->right);
	}
	
}


tree * insert(tree *T,int x)
{
	if(T==NULL)
	{
		T=(tree *)malloc(sizeof(tree));
		T->data=x;
		T->left=T->right=NULL;
	     return(T);
	}
	else if(x>T->data)
	{
	    T->right=insert(T->right,x);	
	}
	
	else if(x<T->data)
	{
		T->left=insert(T->left,x);
	}
	
	 return (T);
} 

int find_min(tree *T)
{
	while(T->left!=NULL)
	T=T->left;
	return(T->data);
}

tree * del(tree *T,int x)
{
	if(T==NULL)
	{
		printf("tree is empty");
		return(T);
		
	}
	
	else if(x<T->data)
	{
		T->left=del(T->left,x);
	     return(T);
	}
	
	else if(x>T->data)
	{
		T->right=del(T->right,x);
		return(T);
	}
	
	if(T->left==NULL&&T->right==NULL)
	{
		tree* temp;
		temp=T;
		free(temp);
		return(NULL);
	}
	
	if(T->left==NULL)
	{
		tree* temp;
		temp=T;
		T=T->right;
		free(temp);
		return(T);
	}
	
	if(T->right==NULL)
	{
		tree* temp;
		T=T->left;
		free(temp);
		return(T);
	}
	
	
	if(T->right!=NULL&&T->left!=NULL)
	{
		int temp;
		temp=find_min(T->right);
		T->data=temp;
		T->right=del(T->right,temp);
		return(T);
	}
	
}



void display(tree *T)
{
	preorder(T);
	printf("\n");
	inorder(T);
	printf("\n");
	postorder(T);
}

int main()
{
  int i,j,n,num,dat,dele;
  char ch='y';
  tree *t;
  t=NULL;
  
  printf("1:insert\n");
  printf("2:delete\n");
  printf("3:display\n");
  
  while(ch=='y'||ch=='Y')
  { 
     printf("\n enter your choice:");
  	scanf("%d",&n);
  	
  	switch(n)
  	{
  		
  	case 1:
	  printf("enter the number of nodes yu want to insert:");
	  scanf("%d",&num);
	  printf("\nenter your data:");
	  for(i=0;i<num;i++)
	  { 
	     scanf("%d",&dat);
	  	  t=insert(t,dat);
      
	  }	
  	       break;	
    
	case 2:
	 printf("enter the data yu want to delete\n");
	 scanf("%d",&dele);  		
  		
  	 t=del(t,dele);	
  	   break;
	  
	  case 3:printf("your tree is:\n");
	  display(t);
	  	
	}
  }
  
  	return 0;
	
}
