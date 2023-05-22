#include <iostream>
using namespace std;

class graph
{
    int g[10][10];
    int n;
    int noedge;
    int visit[10];

public:
    graph()
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                g[i][j] = 999999;
            }
        }

        for (int i = 0; i < 10; i++)
        {
            visit[i] = 0;
        }

        n = 0;
        noedge = 0;
    }

    void create()
    {
        cout << "Enter no of vertices:- ";
        cin >> n;
        cout << "Enter no of edges:- ";
        cin >> noedge;
        int j, k,w;
        for (int i = 1; i <= noedge; i++)
        {
            cin >> j >> k>>w;
            g[j][k] = w;
            g[k][j] = w;
        }
    }

    bool is_valid(int i, int j)
    {
        if(i==j) return false;
        if(visit[i]==0 && visit[j]==0)
        {
            return false;
        }
        else if(visit[i]==1 && visit[j]==1) return false;
        return true;
    }

    void prims_algorithm(int start)
    {
        int visited_edge = 0,min_cost = 0;
        visit[start] = 1;
        while(visited_edge<n-1)
        {
            int min = 999999, a = -1, b = -1;
            for(int i = 1; i<=n; i++)
            {
                for(int j = 1; j<=n; j++)
                {
                    if(g[i][j]<min)
                    {
                        if(is_valid(i,j))
                        {
                            min = g[i][j];
                            a = i;
                            b = j;
                        }
                    }
                }
            }

            if(a!=-1 && b!=-1)
            {
                cout<<"edge : ("<<a<<","<<b<<" )"<<" cost: "<<min<<endl;
                min_cost = min_cost+min;
                visit[a] = 1;
                visit[b] = 1;
                visited_edge++;
            }
        }
    cout<<"Total cost: "<<min_cost<<endl;
    }
};

int main()
{
    graph g;
    g.create();
    g.prims_algorithm(1);
    cout<<endl<<"Enter element to exit: ";
    int kk;
    cin>>kk;
    return 0;
}