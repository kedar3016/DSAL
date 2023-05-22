#include<iostream>
#include<stdlib.h>

using namespace std;

int W[10][10],C[10][10],R[10][10];
int n ;
int P[10],Q[10];
char Identifier[7][20];


void print(int i,int j)
{
   if(i < j)
   {
      int k = R[i][j] ;
      cout<<"\nIdentifier a"<<k<<" = "<<Identifier[k];
      print(i,k-1);
      print(k,j);
   }
}

void display_the_table()
{
   int i,r,j;
   for(r = 0 ; r <= n; r++)
   {
      cout<<"\n\t";
      for(i = 0 , j = r; j <=n; i++,j++)
      {
	 cout<<"W("<<i<<","<<j<<") = "<<W[i][j]<<"   ";
      }
      cout<<"\n\t";
      for(i = 0 , j = r; j <=n; i++,j++)
      {
	 cout<<"C("<<i<<","<<j<<") = "<<C[i][j]<<"   ";
      }
      cout<<"\n\t";
      for(i = 0 , j = r; j <=n; i++,j++)
      {
	 cout<<"R("<<i<<","<<j<<") = "<<R[i][j]<<"   ";
      }
      cout<<"\n";
   }
}

void input_for_OBST()
{
   int i;
   cout<<"\nEnter the no. of identifiers : ";
   cin>>n;
   for(i=1;i<=n;i++)
   {
      cout<<"Enter the Identifier a"<<i<<" : ";
      cin>>Identifier[i];
   }
   cout<<"\nInput the Probabilities of successfull search : \n";
   for(i=1;i<=n;i++)
   {
      cout<<"Enter the value of p"<<i<<" : ";
      cin>>P[i];
   }
   cout<<"\nInput the Probabilities of unsuccessfull search : \n";
   for(i=0;i<=n;i++)
   {
      cout<<"Enter the value of q"<<i<<" : ";
      cin>>Q[i];
   }
}

void find_OBST_dynamic_approach()
{
   int i,j,min,index,k,r;
   // Initialization
   for(i=0;i<=n;i++)
   {
      W[i][i] = Q[i];  C[i][i] = R[i][i] = 0;
   }
   for(r = 1; r<=n; r++)
   {
      for(i=0, j = r; j<=n; i++,j++)
      {
	W[i][j] = P[j] + Q[j] + W[i][j-1];
	min = 32000;
	for(k = i+1; k <=j; k++)
	{
	  if( (C[i][k-1] + C[k][j]) < min)
	  {
	     min = C[i][k-1] + C[k][j];
	     index = k;
	  }
	}
	C[i][j] = min + W[i][j];
	R[i][j] = index;
      }
   }
}

int main()
{
   int ch;

   system("clear");
   do
   {      
      cout<<"\n\t1 : Take the Input for OBST";
      cout<<"\n\t2 : Find the OBST using Dynamic Programming";
      cout<<"\n\t3 : Display the Table and Tree";
      cout<<"\n\t4 : Exit";
      cout<<"\n\nEnter ur choice : ";
      cin>>ch;
      switch(ch)
      {
	case 1 : input_for_OBST();
		 break;
	case 2 : find_OBST_dynamic_approach();
		 break;
	case 3 : display_the_table();
		 cout<<"\nMinimium cost of the OBST : "<<C[0][n];
		 cout<<"\nRoot of the OBST is Identifier a"<<R[0][n]<<" = "<<Identifier[R[0][n]];
		 print(0,n);
		 break;
	case 4 : cout<<"\nEnd of Program";
		 break;
	default : cout<<"\nTry again";
      }    
   }while(ch!=4);
   return 0;
}
