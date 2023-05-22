#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct btree
{
    char lt;
    btree *lc;
    int data;
    btree *rc;
    char rt;
};

class bst
{
    btree *head;
    btree *root;
    int n;
    vector<btree *> array;

public:
    bst()
    {
        root = NULL;
    }

    btree *create()
    {

        btree *node;
        head = new btree;
        cout << "Enter number of nodes:- ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int t;
            node = new btree;
            node->lc = NULL;
            node->rc = NULL;
            cin >> node->data;
            if (root == NULL)
            {
                root = node;
            }
            else
            {
                btree *temp = root;
                while (true)
                {
                    if (temp->data < node->data && temp->rc != NULL)
                        temp = temp->rc;
                    else if (temp->data >= node->data && temp->lc != NULL)
                        temp = temp->lc;
                    else if (temp->data >= node->data && temp->lc == NULL)
                    {
                        temp->lt = 't';
                        temp->lc = node;
                        break;
                    }
                    else if (temp->data < node->data && temp->rc == NULL)
                    {
                        temp->rt = 't';
                        temp->rc = node;
                        break;
                    }
                }
            }
        }

        head ->lc= root;
        return root;
    }

    void inorder(btree *root)
    {
        if (root != NULL)
        {
            inorder(root->lc);
            array.push_back(root);
            inorder(root->rc);
        }
    }

    void display()
    {
        int n = array.size();
        for (int i = 0; i < n; i++)
        {
            cout << array[i]->data << "   ";
        }
    }

    void converting_into_thread()
    {
        int n = array.size();
        for (int i = 0; i < n - 1; i++)
        {
            cout << i << endl;
            if (array[i]->rt != 't')
            {
                array[i]->rc = array[i + 1];
                array[i]->rt = 'f';
            }
        }

        if(array[n-1]->rt!='t') array[n-1]->rc = head;
    }

    void inorder_traversal()
    {
        btree *temp = head->lc;
        while (temp!=head)
        {
            while (temp->lt == 't')
            {   
                
                temp = temp->lc;
            }
            cout << temp->data <<"   ";
            while(temp->rt!='t' && temp->rc!=head)
            {
                temp = temp->rc;
                cout<<temp->data<<"  ";
            }
            temp = temp->rc;
            

        }
    }
};

int main()
{
    bst t;
    btree *root = t.create();
    t.inorder(root);
    // t.display();
    t.converting_into_thread();
    cout<<"Inorder traversal is:- "<<endl;
    t.inorder_traversal();
    cout<<endl;
    cout<<"Enter any element for exit:- ";
    int kkj;
    cin>>kkj;
    return 0;
}
