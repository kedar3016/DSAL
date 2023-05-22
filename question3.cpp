#include <iostream>
#include<stack>
#include<queue>
using namespace std;

struct btree
{
    btree *lc;
    char data;
    btree *rc;
};
class binary_tree
{
    btree *root;
    stack <btree*> s;
    stack<int> t;
    queue<btree*> q;


public:
binary_tree() {root = NULL;}
    btree *create()
    {
        int n;
        char c;
        btree *node;
        cout << "enter number of nodes:- ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter the data:- "<< "of " << i + 1<<" :- ";
            cin >> c;
            node = new btree;
            node->data = c;
            node->lc = NULL;
            node->rc = NULL;
            if (root == NULL)
            {
                root = node;
                cout << "Element is placed at root!" << endl;
            } 
            else
            {
                btree *res = root;
                while (1)
                {
                    char dis;
                    cout << " where to place :- (l/r) of  " << res->data<<" :- ";
                    cin >> dis;
                    if (dis == 'l')
                    {
                        if (res->lc == NULL)
                        {
                            res->lc = node;
                            cout << "Element is placed !" << endl;
                            break;
                        }
                        else
                        {
                            res = res->lc;
                        }
                    }
                    if (dis == 'r')
                    {
                        if (res->rc == NULL)
                        {
                            res->rc = node;
                            break;
                            cout << "Element is placed !" << endl;
                        }
                        else
                        {
                            res = res->rc;
                        }
                    }
                }
            }
        }
        return root;
    }

    void NO_inorder()
    {
        btree * temp = root;
        while(!s.empty() || temp!=NULL)
        {
            while(temp!=NULL)
            {
                s.push(temp);
                temp = temp->lc;
            }
            temp = s.top();
            s.pop();
            cout<<temp->data<<" ";
            temp = temp->rc;
        }
    }

    void NO_preorder()
    {
        btree * temp = root;
        while(!s.empty() || temp!=NULL)
        {
            while(temp!=NULL)
            {
                s.push(temp);
            cout<<temp->data<<" ";
                temp = temp->lc;
            }
            temp = s.top();
            s.pop();
            temp = temp->rc;
        }
    }

    void NO_postorder()
    {
        s.push(root);
        t.push(0);
        while(!s.empty())
        {
            // cout<<1<<endl;
            int test = t.top();
            btree* node = s.top();
            t.pop();
            s.pop();
            switch (test)
            {
            case 0:
                // cout<<"case 0"<<endl;
                s.push(node);
                t.push(1);
                if(node->lc!=NULL)
                {
                    s.push(node->lc);
                    t.push(0);
                }
                break;
            case 1:
                // cout<<"case 1"<<endl;
                s.push(node);
                t.push(2);
                if(node->rc!=NULL)
                {
                    s.push(node->rc);
                    t.push(0);
                }
                break;
            case 2:
                // cout<<"case 2"<<endl;
                cout<<node->data<<" ";
                break;
            }
        }
    }

    void NO_levelOrder()
    {
        q.push(root);
        while(!q.empty())
        {
            btree * temp = q.front();
            q.pop();
            cout<<temp->data<<" ";
            if(temp->lc!=NULL)
            {
                q.push(temp->lc);
            }
            if(temp->rc!=NULL)
            {
                q.push(temp->rc);
            }

        }
    }

    void level_wise_printing()
    {
        q.push(root);
        q.push(NULL);
        btree * temp = NULL;
        while(!q.empty())
        {  
            temp = q.front();
            q.pop();
            if(temp!=NULL)
            {
                cout<<temp->data<<" ";
                if(temp->lc!=NULL)
                {
                    q.push(temp->lc);
                }
                if(temp->rc!=NULL)
                {
                    q.push(temp->rc);
                }
            }
            else if(temp==NULL)
            {
                cout<<endl;
                q.push(NULL);
            }
        }
    }

};

void preorder(btree *node)
{
    if (node != NULL)
    {
        cout << node->data << " ";
        preorder(node->lc);
        preorder(node->rc);
    }
}
void postorder(btree *node)
{
    if (node != NULL)
    {
        postorder(node->lc);
        postorder(node->rc);
        cout << node->data << " ";
    }
}
void inorder(btree *node)
{
    if (node != NULL)
    {
        inorder(node->lc);
        cout << node->data << " ";
        inorder(node->rc);
    }
}

int main()
{

    binary_tree b;
    btree *tree = b.create();
    cout<<"Preorder"<<endl;
    preorder(tree);
    cout<<endl;
    cout<<"postorder"<<endl;
    postorder(tree);
    cout<<endl;
    cout<<"Inorder"<<endl;
    inorder(tree);
    cout<<endl;
    cout<<"Non recursive inorder"<<endl;
    b.NO_inorder();
    cout<<endl;
    cout<<"Non resursive preorder"<<endl;
    b.NO_preorder();
    cout<<endl;
    cout<<"Non resursive postorder"<<endl;
    b.NO_postorder();
    cout<<endl;
    cout<<"Level order"<<endl;
    b.NO_levelOrder();
    cout<<endl;
    cout<<"Enter any element to exit:- ";
    int kk;
    cin>>kk;


    return 0;
}
