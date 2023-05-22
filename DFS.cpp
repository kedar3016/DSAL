#include<iostream>
#include<stdlib.h>

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
        void DFS_rec(int v,int Visit[]);
};

mygraph :: mygraph()
{
   n = 0 ;
}

void mygraph :: DFS_rec(int v,int Visit[])
{
   int w; 
   cout<<"v"<<v"  ";
   Visit[v] = 1;
   for( w = 1 ; w <= n ; w++)
   {
      if(G[v][w] == 1 && Visit[w] == 0)
         DFS_rec(w,Visit);
   }
}
void mygraph :: create_graph()
{
    int e,i,j,v1,v2;
    cout<<"\nEnter the no. of vertices : ";
    cin>>n;
    for( i = 1 ; i <=n ; i++)
    {
       for(j = 1; j <= n ; j++)
       {
          G[i][j] = 0;
       } 
    }
    cout<<"\nEnter the no. of edges : ";
    cin>>e;
    for(i = 1; i<= e; i++)
    {
       cout<<"\nEnter the (vi,vj) for edge"<<i<<" : ";
       cin>>v1>>v2;
       G[v1][v2] = 1;
       G[v2][v1] = 1;
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
          if(G[i][j] == 1)
          {
             cout<<"(v"<<i<<",v"<<j<<"), ";
          }
       } 
    }
    cout<<"\b\b }";
    cout<<"\nAdjacency Matrix is : ";
    cout<<"\n\t";
    for( i = 1 ; i <=n ; i++)
    {
       cout<<"v"<<i<<"  ";
    }
    for( i = 1 ; i <=n ; i++)
    {
       cout<<"\nv"<<i<<"\t";
       for(j = 1; j <= n ; j++)
       {
          cout<<G[i][j]<<"   ";
       } 
    }    
}

int main()
{
    int ch;
    system("clear");
    mygraph g1;
    int sv,Visit[10];
    do
    {
       cout<<"\n\t\t1 : Create Graph";
       cout<<"\n\t\t2 : Display Graph";
       cout<<"\n\t\t7 : Exit";
       cout<<"\n\nEnter ur choice : ";
       cin>>ch;
       switch(ch)
       {
          case 1 : g1.create_graph();
                   break;
          case 2 : g1.display_graph();
                   break;
          case 3 : cout<<"\nenter the starting vertex : ";         
                   cin>>sv;
                   for(int i = 1; i< 10; i++)
                      Visit[i] = 0;
                   cout<<"\nDFS traversal is : ";   
                   g1.DFS_rec(sv,Visit);
                   break;
          case 7 : cout<<"\nEnd of Program\n";
                   break;
          default: cout<<"\nInvalid choice !! Try again\n"; 
       }
    }while(ch != 7);
    return 0;
}
