#include <iostream>
#include<stack>
using namespace std;

struct btree
{
    btree *lc;
    int data;
    btree *rc;
};

class bst
{
    btree *root;
    int n;

public:
    bst()
    {
        root = NULL;
    }

    btree *create()
    {
        
        btree *node;
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
                        temp->lc = node;
                        break;
                    }
                    else if (temp->data < node->data && temp->rc == NULL)
                    {
                        temp->rc = node;
                        break;
                    }
                }
            }
        }
        return root;
    }

    void insert()
    {
        int t;
        btree *node = new btree;
        node->lc = NULL;
        node->rc = NULL;
        cout << "Enter the data:- ";
        cin >> node->data;
        if (root == NULL)
        {
            root = node;
            cout << "Node inserted at the root!" << endl;
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
                    temp->lc = node;
                    cout << "Node inserted !" << endl;
                    break;
                }
                else if (temp->data < node->data && temp->rc == NULL)
                {
                    temp->rc = node;
                    cout << "Node inserted !" << endl;
                    break;
                }
            }
        }
    }

    void search()
    {
        btree *temp = root;
        cout << "Enter the data to be search:- ";
        int n;
        cin >> n;
        while (temp!=NULL)
        {
            if (temp->data==n)
            {
                cout<<"Found!"<<endl;
                return;
            }   
            else if (temp->data >=n)
                temp = temp->lc;
            else if(temp->data < n)
                temp = temp->rc;
        }
        cout<<"Not found"<<endl;
    }

    void minimum_number()
    {
        btree * temp = root;
        while(temp->lc!=NULL)
        {
            temp = temp->lc;
        }
        cout<<temp->data<<endl;
    }

    void inorder(btree *node)
    {
        if (node != NULL)
        {
            inorder(node->lc);
            cout << node->data << "  ";
            inorder(node->rc);
        }
    }

    int finding_no_of_nodes_in_max_path(btree * temp)
    {
        if(temp==NULL)
        {
           return 0;
        }
        else{
            int lc =  finding_no_of_nodes_in_max_path(temp->lc);
            int rc = finding_no_of_nodes_in_max_path(temp->rc);
            return (max(lc,rc) +1); 
        }
    }

    void change_a_tree(btree * temp)
    {
        if(temp!=NULL)
        {
            btree*node;
            node = temp->lc;
            temp->lc = temp->rc;
            temp->rc = node;
            change_a_tree(temp->lc);
            change_a_tree(temp->rc);
        }
    }
};

int main()
{
    btree *head;
    int height;
    bst t1;
    head = t1.create();
    int ch;
    while (ch != 7)
    {
        cout << "\n\t\t\t1: Insert a node" << endl;
        cout << "\n\t\t\t2: Find no of nodes in longest path" << endl;
        cout << "\n\t\t\t3: Minimum data value found in a tree" << endl;
        cout << "\n\t\t\t4: Changing a tree" << endl;
        cout << "\n\t\t\t5: Search a value" << endl;
        cout << "\n\t\t\t6: Display in inorder" << endl;
        cout << "\n\t\t\t7: Exit" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            t1.insert();
            break;

        case 2:
            height = t1.finding_no_of_nodes_in_max_path(head);
            break;
        case 3:
            t1.minimum_number();
            break;
        case 4:
            t1.change_a_tree(head);
            break;
        case 5:
            t1.search();
            break;
        case 6:
            t1.inorder(head);
            break;

        default:
            break;
        }
        if(ch==2) cout<<"No of nodes in longest path is:- "<<height<<endl;
    }

    return 0;
}