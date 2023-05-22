#include<iostream>
#include<stdlib.h>
#define Infinity 32000
 
using namespace std;

class mygraph
{
   private :
        int G[10][10];
        int n;
   public : 
        mygraph();
        void create_graph();
        void display_graph();
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
           if(Visit[x] == 0 && (Dist[v] + G[v][x] < Dist[x]))
           {
               Dist[x] = Dist[v] + G[v][x];
               From[x] = v;
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
void mygraph :: create_graph()
{
    int e,i,j,v1,v2,wt;
    cout<<"\nEnter the no. of vertices : ";
    cin>>n;
    for( i = 1 ; i <=n ; i++)
    {
       for(j = 1; j <= n ; j++)
       {
          G[i][j] = Infinity;
       } 
    }
    cout<<"\nEnter the no. of edges : ";
    cin>>e;
    for(i = 1; i<= e; i++)
    {
       cout<<"\nEnter the (vi,vj,wt) for edge"<<i<<" : ";
       cin>>v1>>v2>>wt;
       G[v1][v2] = wt;
       G[v2][v1] = wt;
    }
    cout<<"\nGraph accepted and stored successfully\n";
}

void mygraph :: display_graph()
{
    int i,j;
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
       for(j = i+1; j <= n ; j++)
       {
          if(G[i][j] != Infinity)
          {
             cout<<"(v"<<i<<",v"<<j<<","<<G[i][j]<<"), ";
          }
       } 
    }
    cout<<"\b\b }";
    cout<<"\nAdjacency Matrix is : ";
    cout<<"\n\t";
    for( i = 1 ; i <=n ; i++)
    {
       cout<<"v"<<i<<"   ";
    }
    for( i = 1 ; i <=n ; i++)
    {
       cout<<"\nv"<<i<<"\t";
       for(j = 1; j <= n ; j++)
       {
          if(G[i][j] == Infinity)
            cout<<"oo"<<"   ";
          else  
            cout<<G[i][j]<<"   ";
       } 
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
