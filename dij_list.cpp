#include<iostream>
#include<stdlib.h>
#define Infinity 32000
 
using namespace std;
struct SLL
{
   int vertex;
   int wt;
   struct SLL *next;
};
typedef struct SLL sll;

class mygraph
{
   private :
        sll *G[10];
        int n;
   public : 
        mygraph();
        void create_graph();
        void display_graph();
        void insert_vertex_into_adjacency_list(int,int ,int);
        void dijkstra_shortest_path_algo();
};



mygraph :: mygraph()
{
   n = 0 ;
}


int find_unvisited_vertex_with_dist(int V[],int D[],int n)
{
    int i, v = -1,min;
    min = Infinity + 1;
    for(i = 1; i<= n ; i++)
    {
       if(V[i] == 0 && D[i] < min)
       {
          min = D[i];
          v = i;
       }
    }
    return v;
}


void mygraph :: dijkstra_shortest_path_algo()
{
    int s,d,i,x;
    int v;
    sll *temp;
    int wt;
    int Path[20],k;
    int Visit[20],From[20], Dist[20];
    cout<<"\nEnter source and destination vertex : ";
    cin>>s>>d;
    for(i = 1; i<=n;i++)
    {
       Visit[i] = 0;
       From[i] = Infinity;
       Dist[i] = Infinity;
    }
    Dist[s] = 0;
    From[s] = s;
    do
    {   
       v = find_unvisited_vertex_with_dist(Visit,Dist,n);
       Visit[v] = 1;
       if(v == d)
          break;
       for(x = 1; x <= n; x++)
       {
           if(Visit[x] == 0 )
           {
               wt = Infinity;
               for(temp = G[v]; temp!=NULL; temp = temp->next)
               {
                  if(temp->vertex == x)
                     wt = temp->wt;
               }
               if(Dist[v] + wt < Dist[x])
               {
                  Dist[x] = Dist[v] + wt;
                  From[x] = v;
               }   
           }
       }   
    }while(1); 
    cout<<"\nShortest distance from "<<s<<" to "<<d<<" vertex = "<<Dist[d];    
    k = 0;
    v = d;
    Path[k++] = d;
    while(v != s)
    {
       v = From[v];
       Path[k++] = v;
    }
    cout<<"\nShortest route from "<<s<<" to "<<d<<" is : ";
    for(k = k - 1; k >= 0; k--)
      cout<<"v"<<Path[k]<<" --> ";
    cout<<"\b\b\b\b   ";      
}

void mygraph :: insert_vertex_into_adjacency_list(int v1,int v2,int wt)
{
   sll *node,*last;
   node = new sll;
   node->vertex = v2;
   node->wt = wt;
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
    int e,i,j,v1,v2,wt;
    sll *temp;
    cout<<"\nEnter the no. of vertices : ";
    cin>>n;
    for( i = 1 ; i <=n ; i++)
        G[i] = NULL;
    cout<<"\nEnter the no. of edges : ";
    cin>>e;
    for(i = 1; i<= e; i++)
    {
       cout<<"\nEnter the (vi,vj,wt) for edge"<<i<<" : ";
       cin>>v1>>v2>>wt;
       insert_vertex_into_adjacency_list(v1,v2,wt);
       insert_vertex_into_adjacency_list(v2,v1,wt);       
    }
    cout<<"\nGraph accepted and stored successfully\n";
}

void mygraph :: display_graph()
{
    int i,j;
    sll * temp;
    cout<<"\n\tGraph G = (V,E)";
    cout<<"\n  Where ";
    cout<<"\n\tV = {";
    for(i = 1 ; i <=n ; i++)
    {
       cout<<"v"<<i<<", ";
    }
    cout<<"\b\b }";
    cout<<"\n\tE = {";
    for( i = 1 ; i <=n ; i++)
    {
       for(temp = G[i];temp != NULL ; temp = temp->next)
       {
          cout<<"(v"<<i<<",v"<<temp->vertex<<","<<temp->wt<<"), ";          
       } 
    }
    cout<<"\b\b }";
    cout<<"\nAdjacency List is : ";
    cout<<"\n\t";
    for( i = 1 ; i <=n ; i++)
    {
       cout<<"\nv"<<i<<" ==> ";
       for(temp = G[i]; temp != NULL ; temp = temp->next)
       {
          cout<<"(v"<<temp->vertex<<","<<temp->wt<<") -> ";
       } 
       cout<<" Null";
    }    
}

int main()
{
    int ch;
    system("clear");
    mygraph g1;
    int h = 236;
    
    int sv,Visit[10];
    
    do
    {
       cout<<"\n\t\t1 : Create Graph";
       cout<<"\n\t\t2 : Display Graph";
       cout<<"\n\t\t3 : Shortest path alogrithm";
       cout<<"\n\t\t7 : Exit";
       cout<<"\n\nEnter ur choice : ";
       cin>>ch;
       switch(ch)
       {
          case 1 : g1.create_graph();
                   break;
          case 2 : g1.display_graph();
                   break;
          case 3 : g1.dijkstra_shortest_path_algo();
                   break;
          case 7 : cout<<"\nEnd of Program\n";
                   break;
          default: cout<<"\nInvalid choice !! Try again\n"; 
       }
    }while(ch != 7);
    return 0;
}
