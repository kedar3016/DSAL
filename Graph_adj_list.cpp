/*
Write a function to get the number of vertices in an undirected graph and its edges. You may assume that no edge is input twice.
i. Use adjacency list representation of the graph and find runtime of the function
ii. Use adjacency matrix representation of the graph and find runtime of the function
*/

#include<iostream>
#include<iomanip>
#define Max 5

using namespace std;
struct SLL
{
   int ver;
   struct SLL *next;
};
typedef struct SLL sll;

class mygraph
{
    private :
           sll *G[Max];
           int n;
    public :
           mygraph();
           void create_graph();
           void display_graph();
           void add_the_edge(int v1,int v2);
};

mygraph :: mygraph()
{
   n = 0;
}

void mygraph :: add_the_edge(int v1,int v2)
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

void mygraph :: create_graph()
{
   int e;
   int i,j,vi,vj;
   cout<<"\nEnter the no. of vertices in the graph : ";
   cin>>n;
   cout<<"\nEnter the no. of edges in the graph : ";
   cin>>e;
   for(i = 1; i<=n ;i++)
   {
          G[i] = NULL;
   }
   for( i = 1 ; i<= e; i++)
   {
      cout<<"\nEnter adjacent vertices ( vi,vj) of edge "<<i<<" : ";
      cin>>vi>>vj;
      add_the_edge(vi,vj);
      add_the_edge(vj,vi);
   }
   cout<<"\nGraph created successfully";
}

void mygraph :: display_graph()
{
   int i;
   sll *temp;
   cout<<"\nGraph G = (V,E)";
   cout<<"\n\tWhere";
   cout<<"\n\t\tV = { ";
   for(i = 1; i<=n ;i++)
      cout<<"V"<<i<<", ";
   cout<<"\b\b }";   
   cout<<"\n\t\tE = { ";
   for(i = 1; i<=n ;i++)
   {
      for(temp = G[i]; temp != NULL; temp = temp->next)
      {
          if(i < temp->ver)
             cout<<"(v"<<i<<",v"<<temp->ver<<"), ";
      }  
   }
   cout<<"\b\b }";   
   cout<<"\nAdjacency List for the Graph is : ";
   cout<<"\n\t\t";
   for(i = 1; i<=n ;i++)
   {
      cout<<"\n\t"<<"V"<<i<<" ==> ";
      for(temp = G[i]; temp != NULL; temp = temp->next)
      {
          cout<<"V"<<temp->ver<<" --> ";
      }  
      cout<<"Null";
   }
}

int main()
{
   int ch;
   mygraph g1;
   do
   {
      cout<<"\n\t\t1 : Accept Graph";
      cout<<"\n\t\t2 : Display Graph";
      cout<<"\n\t\t5 : Exit";
      cout<<"\n\nEnter ur choice : ";
      cin>>ch;
      switch(ch)
      {
        case 1 : g1.create_graph();
                 break;
        case 2 : g1.display_graph();
                 break;
        case 5 : cout<<"\nGood bye\n";
                 break;
        default: cout<<"\nWrong choice !! Try again\n\n";  
      }
   }while(ch != 5);	
   return 0;
}
