/*
Write a function to get the number of vertices in an undirected graph and its edges. You may assume that no edge is input twice.
i. Use adjacency list representation of the graph and find runtime of the function
ii. Use adjacency matrix representation of the graph and find runtime of the function
*/

#include<iostream>
#include<iomanip>
#define Max 15

using namespace std;
class mygraph_Adj_Matrix
{
   private :
   	int G[Max][Max];
   	int n;
   public :
        mygraph_Adj_Matrix();   
        void create_graph();
        void display_graph();
};

mygraph_Adj_Matrix :: mygraph_Adj_Matrix()
{
    n = 0;
}


void mygraph_Adj_Matrix :: create_graph()
{
   int i,j,e,v1,v2;
   cout<<"\nEnter the no. of vertices in the graph : ";
   cin>>n;
   for( i= 1; i<= n; i++)
   {
      for(j = 1; j<= n;j++)
      {
          G[i][j] = 0;
      }
   }
   cout<<"\nEnter the no. of edges in the graph : ";
   cin>>e;
   for(i = 1; i<= e; i++)
   {
      cout<<"\nEnter the adjacent vertices for edge " << i<<" : ";
      cin>>v1>>v2;
      G[v1][v2] = 1;
      G[v2][v1] = 1;      
   }
   cout<<"\nGraph created successfully";
}

void mygraph_Adj_Matrix :: display_graph()
{
   int i,j;
   cout<<"\nGraph G = (V,E) ";
   cout<<"\n\tWhere";
   cout<<"\n\t\tV = { ";
   for( i= 1; i<= n; i++)
     cout<<"v"<<i<<", ";
   cout<<"\b\b }";  

   cout<<"\n\t\tE = { ";
   for( i= 1; i<= n; i++ )
   {
      for(j = i+1; j<= n;j++)
      {
          if(G[i][j] == 1)
             cout<<"(v"<<i<<",v"<<j<<"), ";
      }
   }
   cout<<"\b\b }";  

   cout<<"\n\n\tAdjacency Matrix for the Graph G is : ";
   cout<<"\n\t\t";
   for( i= 1; i<= n; i++)
     cout<<"v"<<i<<"\t";

   for( i= 1; i<= n; i++)
   {
      cout<<"\n\t"<<"v"<<i<<"\t";
      for(j = 1; j<= n;j++)
      {
          cout<<G[i][j]<<"\t";
      }
   }
}

struct SLL
{
   int ver;
   struct SLL *next;
};
typedef struct SLL sll;

class mygraph_Adj_list
{
   private :
   	sll *G[Max];
   	int n;
   public :
        mygraph_Adj_list();   
        void add_edge_into_sll(int v1,int v2);
        void create_graph();
        void display_graph();
};

mygraph_Adj_list :: mygraph_Adj_list()
{
    n = 0;
}


void mygraph_Adj_list :: add_edge_into_sll(int v1,int v2)
{
   sll *node,*last;
   node = new sll;
   node->ver = v2;
   node->next = NULL;
   if(G[v1] == NULL)
      G[v1] = node;
   else
   {
     last = G[v1];
     while(last->next != NULL)
        last = last->next;
     last->next = node;   
   }   
}
void mygraph_Adj_list :: create_graph()
{
   int i,j,e,v1,v2;
   cout<<"\nEnter the no. of vertices in the graph : ";
   cin>>n;
   for( i= 1; i<= n; i++)
   {
     G[i] = NULL;
   }
   cout<<"\nEnter the no. of edges in the graph : ";
   cin>>e;
   for(i = 1; i<= e; i++)
   {
      cout<<"\nEnter the adjacent vertices for edge " << i<<" : ";
      cin>>v1>>v2;
      add_edge_into_sll(v1,v2);
      add_edge_into_sll(v2,v1);
   }
   cout<<"\nGraph created successfully";
}

void mygraph_Adj_list :: display_graph()
{
   int i;
   sll *temp;
   cout<<"\nGraph G = (V,E) ";
   cout<<"\n\tWhere";
   cout<<"\n\t\tV = { ";
   for( i= 1; i<= n; i++)
     cout<<"v"<<i<<", ";
   cout<<"\b\b }";  

   cout<<"\n\t\tE = { ";
   for( i= 1; i<= n; i++ )
   {
      for(temp = G[i] ; temp != NULL; temp = temp->next)
      {
          if(i  < temp->ver)
             cout<<"(v"<<i<<",v"<<temp->ver<<"), ";
      }
   }
   cout<<"\b\b }";  

   cout<<"\n\n\tAdjacency List for the Graph G is : ";
   for( i= 1; i<= n; i++)
   {
      cout<<"\n\t"<<"v"<<i<<" ==> ";
      for(temp = G[i] ; temp != NULL; temp = temp->next)
      {
          cout<<"v"<<temp->ver<<" --> ";
      }
      cout<<"Null";
   }
}

int main()
{
   int ch;
   mygraph_Adj_Matrix g1;
   mygraph_Adj_list g2;

   do
   {
      cout<<"\n\t\t1 : Accept Graph using Adjacency Matrix";
      cout<<"\n\t\t2 : Display Graph using Adjacency Matrix";
      cout<<"\n\t\t3 : Accept Graph using Adjacency List";
      cout<<"\n\t\t4 : Display Graph using Adjacency List";
      cout<<"\n\t\t5 : Exit";
      cout<<"\n\nEnter ur choice : ";
      cin>>ch;
      switch(ch)
      {
        case 1 : g1.create_graph();
                 break;
        case 2 : g1.display_graph();
                 break;
        case 3 : g2.create_graph();
                 break;
        case 4 : g2.display_graph();
                 break;
        case 5 : cout<<"\nGood bye\n";
                 break;
        default: cout<<"\nWrong choice !! Try again\n\n";  
      }
   }while(ch != 5);	
   return 0;
}
