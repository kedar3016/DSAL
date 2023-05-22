#include<iostream>
#include<stdlib.h>
#define size 30

using namespace std;

struct AVL
{
  struct AVL *lc;
  int data;
  int bf;
  struct AVL *rc;
};
typedef struct AVL avl;

class mystack
{
   private :
       avl * A[size];
       int top;
   public : 
       mystack();
       int isEmpty();
       int isFull();
       void push(avl *);
       avl * pop();
};
mystack :: mystack()
{
   top = -1;
}

int mystack :: isEmpty()
{
   if(top == -1)
      return 1;
   else
      return 0;
}

int mystack :: isFull()
{
   if(top == size-1)
      return 1;
   else
      return 0;
}

void mystack :: push(avl * X)
{
   if(!isFull())
   {
      top++;
      A[top] = X;
   }
   else
      cout<<"\nError !!! Stack Overflow\n";
}
avl * mystack :: pop()
{
   avl * X;
   if(!isEmpty())
   {
      X = A[top];
      top--;
      return(X);
   }
   else
      return(NULL);
}


class myavl
{
   private :
       avl *root;
   public :
       myavl();    
       void traversals_avl();
       void apply_LL(avl *par,avl *t1,avl *t2);
       void apply_RR(avl *par,avl *t1,avl *t2);
       void apply_LR(avl *par,avl *t1,avl *t2,avl *t3);
       void apply_RL(avl *par,avl *t1,avl *t2,avl *t3);
       void insert_avl(avl *node);
       void create_avl();
};

myavl :: myavl()
{
   root = NULL;
}

void inorder(avl *temp)
{
   if(temp != NULL)
   {
      inorder(temp->lc);
      cout<<temp->data<<" ";
      inorder(temp->rc);
   }
}
void preorder(avl *temp)
{
   if(temp != NULL)
   {
      cout<<temp->data<<" ";
      preorder(temp->lc);      
      preorder(temp->rc);
   }
}


void postorder(avl *temp)
{
   if(temp != NULL)
   {      
      postorder(temp->lc);      
      postorder(temp->rc);
      cout<<temp->data<<" ";
   }
}

void myavl :: traversals_avl()
{
   if(root == NULL)
      cout<<"\nAVL tree is Empty\n";
   else
   {
      cout<<"\nInorder Traversal is : ";
      inorder(root);
      cout<<"\nPreorder Traversal is : ";
      preorder(root);
      cout<<"\nPostorder Traversal is : ";
      postorder(root);
   }
}
void myavl :: apply_LL(avl *par,avl *t1,avl *t2)
{
   t1->bf = 0;
   t2->bf = 0;
   t1->lc = t2->rc;
   t2->rc = t1;
   if(t1 == root) // par == NULL
      root = t2;
   else
   {
      if(par->lc == t1)
	 par->lc = t2;
      else
	par->rc = t2;
   }   
}

void myavl :: apply_RR(avl *par,avl *t1,avl *t2)
{
   t1->bf = 0;
   t2->bf = 0;
   t1->rc = t2->lc;
   t2->lc = t1;
   if(t1 == root) // par == NULL
      root = t2;
   else
   {
      if(par->lc == t1)
	 par->lc = t2;
      else
	par->rc = t2;
   }   
}

void myavl :: apply_LR(avl *par,avl *t1,avl *t2,avl *t3)
{
   avl *lt3,*rt3;

   lt3 = t3->lc;
   rt3 = t3->rc;

   t3->lc = t2;
   t3->rc = t1;

   t2->rc = lt3;
   t1->lc = rt3;

   if(t3->bf == 1)
   {
     t3->bf = 0;
     t1->bf = -1;
     t2->bf = 0;
   }
   else
   {
      if(t3->bf == -1)
      {
	t3->bf = 0;
	t1->bf = 0;
	t2->bf = 1;
      }
      else
      {
	 t1->bf = 0;
	 t2->bf = 0;
      }
   }

   if(t1 == root) // par == NULL
   {
      root = t3;
   }
   else
   {
      if(par->lc == t1)
	 par->lc = t3;
      else
	par->rc = t3;
   }
}
void myavl :: apply_RL(avl *par,avl *t1,avl *t2,avl *t3)
{

   avl *lt3,*rt3;

   lt3 = t3->lc;
   rt3 = t3->rc;

   t3->lc = t1;
   t3->rc = t2;

   t1->rc = lt3;
   t2->lc = rt3;

   if(t3->bf == 1)
   {
     t3->bf = 0;
     t1->bf = 0;
     t2->bf = -1;
   }
   else
   {
      if(t3->bf == -1)
      {
	t3->bf = 0;
	t1->bf = 1;
	t2->bf = 0;
      }
      else
      {
	 t1->bf = 0;
	 t2->bf = 0;
      }
   }

   if(t1 == root) // par == NULL
   {
      root = t3;
   }
   else
   {
      if(par->lc == t1)
	 par->lc = t3;
      else
	par->rc = t3;
   }   
}

void myavl :: insert_avl(avl *node)
{
  mystack s1;
  avl *par,*p,*t1,*t2,*t3;
   int flag = 0;
   if(root == NULL)
   {
     root = node;
     cout<<"\nTree is balanced ";
   }  
   else
   {
     par = root;
     while(flag == 0)
     {
	if(node->data < par->data)
	{
	   if(par->lc == NULL)
	   {
	       par->lc = node;
	       par->bf++;
	       flag = 1;
	   }
	   else
	   {
	       s1.push(par);
	       par = par->lc;
	   }
	}
	else
	{
	   if(par->rc == NULL)
	   {
	      par->rc = node;
	      par->bf--;
	      flag = 1;
	   }
	   else
	   {
	      s1.push(par);
	      par = par->rc;
	   }
	}
     }	 
     while(!s1.isEmpty() && par->bf != 2 && par->bf != -2 && par->bf != 0)
     {
	node = par;   
	par = s1.pop();
	if(par->lc == node)
	   par->bf++;
	else
	   par->bf--;	
     }
     
     if(par->bf == 2 || par->bf == -2)
     {
	cout<<"\nTree is imbalanced !!! Rotation required ";
	t1 = par;  t2 = node;
	p = s1.pop();
	if(t1->bf == 2 && t2->bf == 1)
	{
	    cout<<"\nNeed 2 apply LL Rotations";
	    apply_LL(p,t1,t2);
	}
	else
	{
	   if(t1->bf == -2 && t2->bf == -1)
	   {
	      cout<<"\nNeed 2 apply RR Rotations";
	      apply_RR(p,t1,t2);
	   }
	   else
	   {
	      if(t1->bf == 2 && t2->bf == -1)
	      {
		cout<<"\nNeed 2 apply LR Rotations";
		apply_LR(p,t1,t2,t2->rc);
	      }
	      else
	      {
		  cout<<"\nNeed 2 apply RL Rotations";
		  apply_RL(p,t1,t2,t2->lc);
	      }
	   }
	}
     }
     else
	cout<<"\nTree is balanced ";
   }
}

void myavl :: create_avl()
{
   avl *node;
   int d[30],i,n;
   cout<<"\nEnter the no. of elements to be inserted : ";
   cin>>n;
   cout<<"\nEnter the elements : ";
   for(i=0;i<n;i++)
   {
     cout<<"\nStep "<<i+1<<" : ";
     node = new avl;
     node->lc = NULL;  
     node->rc = NULL;
     node->bf = 0;
     cout<<"\nEnter the element to be inserted : ";
     cin>>node->data;     
     insert_avl(node);
     cout<<"\nNode Inserted successfully into the avl\n\n";
   }
}

int main()
{
    int ch;
    myavl a1;
    system("clear");
    do
    {
       cout<<"\n\t\t1 : Create AVL tree";
       cout<<"\n\t\t2 : Traversals of AVL";
       cout<<"\n\t\t3 : Exit";
       cout<<"\n\nEnter ur choice : ";
       cin>>ch;
       switch(ch)
       {
          case 1 : a1.create_avl();
                   break;
          case 2 : a1.traversals_avl();
                   break;
          case 3 : cout<<"\nEnd of Program\n";
                   break;
          default: cout<<"\nInvalid choice !! Try again\n"; 
       }
    }while(ch != 3);
    return 0;
}

