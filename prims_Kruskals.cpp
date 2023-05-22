#include<iostream>
#include<stdlib.h>
#define size 30
#define Infinity 32000
 
using namespace std;

//min heap
struct edge 
{
   int v1;
   int v2;
   int wt;
};
class mypriorityQ
{
   private :
        struct edge A[size];
        int hs;
   public : 
        mypriorityQ();
        void insert_PQ(struct edge);
        struct edge delete_PQ();
        void heapify(int i);
        int isEmpty();
};

int mypriorityQ :: isEmpty()
{
   if(hs == 0)
      return 1;
   else
      return 0;   
}
mypriorityQ :: mypriorityQ()
{
   hs = 0;
}

void mypriorityQ :: heapify(int i)
{
    int lc,rc,small;
    struct edge temp;
    
    lc = 2*i;
    rc = lc + 1;
    if(lc <= hs && A[lc].wt < A[i].wt)
       small = lc;
    else
       small = i;
    if(rc <= hs && A[rc].wt < A[small].wt)
       small = rc;
    if(small != i)
    {
       temp = A[i];
       A[i] = A[small];
       A[small] = temp;
       heapify(small);
    }
}

void mypriorityQ :: insert_PQ(struct edge X)
{
   int i;
   hs = hs + 1;
   i = hs;
   while(i > 1 && X.wt < A[i/2].wt)
   {
     A[i] = A[i/2];
     i = i/2;
   }  
   A[i] = X;
}

struct edge  mypriorityQ :: delete_PQ()
{
   struct edge X;
   if(hs < 1)
     cout<<"Error !!! heap underflow";
   X = A[1];
   A[1] = A[hs];
   hs = hs  -1;
   heapify(1);
   return(X);  
}

class mygraph
{
   private :
        int G[10][10];
        int n;
   public : 
        mygraph();
        void create_graph();
        void display_graph();
        void prims_algo();
        void Kruskals_algo();
};



mygraph :: mygraph()
{
   n = 0 ;
}


void mygraph :: Kruskals_algo()
{
   struct edge X;
   mypriorityQ p1;
   int i,j,e,v,u;
   int cost = 0;
   int Cluster[20];
   for(i = 1; i <= n ;i++)
      Cluster[i] = i;
   for(i = 1 ; i <=n ; i++)
      for(j = i+1; j <= n ; j++)
          if(G[i][j] != Infinity)
          {  
             X.v1 = i; X.v2 = j; X.wt = G[i][j];
             p1.insert_PQ(X);
          }   
   e = 0 ;
   while( e < n - 1 && !p1.isEmpty())
   {
      X = p1.delete_PQ();
      v = X.v1; u = X.v2;
      if(Cluster[v] != Cluster[u])
      {
          cout<<"\nStep "<<e + 1<<" : "<<"v"<<v<<" ---- v"<<u<<" edge added with wt "<<X.wt;
          e++;
          cost = cost + X.wt;
          for(i = 1 ; i<=n;i++)
          {
             if(Cluster[i] == Cluster[u])
                Cluster[i] = Cluster[v];
          }
      }
   }  
   cout<<"\nCost of minimum spanning tree is "<<cost;    

}

void mygraph :: prims_algo()
{
   int Visit[20];
   int v,u,vi,vj,e,i,s;
   int cost = 0,min;
   int T[20],nt = 0;
   for(i = 1; i<= n;i++)
     Visit[i] = 0;
   cout<<"\nEnter the starting vertex : ";
   cin>>s;
   T[nt++] = s;
   Visit[s] = 1;
   cout<<"\nStep 1 : v"<<s<<" vertex selected";
   for(e = 1 ; e < n ; e++)
   {
      min = Infinity + 1;
      for(i = 0 ; i < nt; i++)
      {
         vi = T[i];
         for(vj = 1; vj <= n; vj++)
         {
            if(Visit[vj] == 0 && G[vi][vj] < min)
            {
               v = vi;
               u = vj;
               min = G[vi][vj];
            }
         }
         
      } 
      cout<<"\nStep "<<e + 1<<" : "<<"v"<<v<<" ---- v"<<u<<" edge added with wt "<<min;
      Visit[u] = 1;
      T[nt++] = u;
      cost = cost + min;
   }
   cout<<"\nCost of minimum spanning tree is "<<cost;
   
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
       cout<<"\n\t\t3 : Prims alogrithm";
       cout<<"\n\t\t4 : Kruskals alogrithm";
       cout<<"\n\t\t7 : Exit";
       cout<<"\n\nEnter ur choice : ";
       cin>>ch;
       switch(ch)
       {
          case 1 : g1.create_graph();
                   break;
          case 2 : g1.display_graph();
                   break;
          case 3 : g1.prims_algo();
                   break;
          case 4 : g1.Kruskals_algo();
                   break;
          case 7 : cout<<"\nEnd of Program\n";
                   break;
          default: cout<<"\nInvalid choice !! Try again\n"; 
       }
    }while(ch != 7);
    return 0;
}
