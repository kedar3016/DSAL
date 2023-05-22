#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct sll
{
    int data;
    sll *next;
};

class graph
{
    int g[10][10];
    int h[10][10];
    sll *head[10];
    int n;
    int edge;
    int visit[10];
    int visit1[10];
    stack<int> stack;
    queue<int> queue;

public:
    graph()
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                g[i][j] = 0;
                h[i][j] = 0;
            }
        }

        for (int i = 0; i < 10; i++)
        {
            visit[i] = 0;
            head[i] = NULL;
        }

        n = 0;
        edge = 0;
    }

    void create()
    {
        cout << "Enter no of vertices:- ";
        cin >> n;
        cout << "Enter no of edges:- ";
        cin >> edge;
        int j, k;
        for (int i = 1; i <= edge; i++)
        {
            cin >> j >> k;
            create_using_list(j,k);
            g[j][k] = 1;
            g[k][j] = 1;
        }
    }

    void dfs(int v)
    {
        cout << v << "    ";
        visit[v] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (g[v][i] == 1 && visit[i] == 0)
            {
                dfs(i);
            }
        }
    }

    int adjecent_vertices_of_v_is_visited(int v)
    {
        int temp = 0;
        for (int i = 1; i <= n; i++)
        {
            if (g[v][i] == 1 && visit[i] == 0)
            {
                return 0;
            }
        }
        return 1;
    }

    void making_visit_zero()
    {
        for(int i = 0; i<=10; i++)
        {
            visit[i] = 0;
        }
    }

    int select_unvisited_node(int v)
    {
        for (int i = 1; i <= n; i++)
        {
            if (g[v][i] == 1 && visit[i] == 0)
            {
                return i;
            }
        }
    }

    void dfs_non_resursive(int v)
    {
        for (int i = 0; i < 10; i++)
        {
            visit[i] = 0;
        }

        stack.push(v);
        cout << v << "   ";
        visit[v] = 1;
        while (!stack.empty())
        {
            if (adjecent_vertices_of_v_is_visited(v))
            {
               v =  stack.top();
               stack.pop();
            }
            else
            {
                stack.push(v);
                v = select_unvisited_node(v);
                cout << v << "   ";
                visit[v] = 1;
            }
        }
    }

    void create_using_list(int j,int k)
    {
        for (int i = 1; i <= edge; i++)
        {
            sll *node = new sll;
            node->data = k;
            node->next = NULL;
            if (head[j] == NULL)
                head[j] = node;
            else
            {
                sll *temp = head[j];
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = node;
            }

            node = new sll;
            node->data = j;
            node->next = NULL;
            if (head[k] == NULL)
                head[k] = node;
            else
            {
                sll *temp = head[k];
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = node;
            }
        }
    }

    void bfs_using_list(int v)
    {
        queue.push(v);
        visit[v] = 1;
        while (!queue.empty())
        {
            v = queue.front();
            cout << v << "   ";
            queue.pop();
            for (sll *temp = head[v]; temp != NULL; temp = temp->next)
            {
                if (visit[temp->data] == 0)
                {
                    queue.push(temp->data);
                    visit[temp->data] = 1;
                }
            }
        }
    }
};

int main()
{
    graph g;
    int ch;
    while (ch != 5)
    {

        cout << "\n\t\t\t1: Create graph" << endl;
        cout << "\n\t\t\t2: BFS using list" << endl;
        cout << "\n\t\t\t3: DFS recursive" << endl;
        cout << "\n\t\t\t4: DFS non recursive" << endl;
        cout << "\n\t\t\t5: Exit" << endl;
        cin >> ch;
        switch (ch)
        {

        case 1:
            g.create();
            break;
        case 2:
            g.bfs_using_list(1);
            break;
        case 3:
            g.dfs(1);
            break;
        case 4:
            g.dfs_non_resursive(1);
            break;

        default:
            break;
        }
        g.making_visit_zero();
    }

    return 0;
}