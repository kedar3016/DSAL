#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct btree
{
    btree *lc;
    char data;
    btree *rc;
};

btree * create_node(char c)
{
    btree *node;
    node = new btree;
    node->data = c;
    node->lc = NULL;
    node->rc = NULL;
    return node;
}

void postorder(btree *root)
{
    if (root != NULL)
    {  
        postorder(root->lc);
        postorder(root->rc);
        cout << root->data << "  ";
    }
}

int main()
{   stack<btree*> stack,stack1;
    string str;
    cout<<"Enter prefix expression:- ";
    cin >> str;
    int n = str.length();
    int index = 1,flag = 0;
    btree *root = create_node(str[0]);
    btree *tempo = root;
    while (index < n)
    {
        while (str[index] == '+' || str[index] == '-' || str[index] == '/' || str[index] == '*')
        {
            tempo->lc = create_node(str[index++]);
            stack.push(tempo);
            tempo = tempo->lc;
        }
            tempo->lc = create_node(str[index++]);         
            flag = 0;
            while(flag==0)
            {
                tempo->rc = create_node(str[index++]);
                if(str[index-1] != '+' && str[index-1] != '-' && str[index-1] != '/' && str[index-1] != '*' && !stack.empty())
                {  
                    tempo = stack.top();
                    stack.pop(); 
                }
                else
                {
                   flag = 1;
                   tempo = tempo->rc;
                }
            }
    }
    cout<<"Tree is created successfully !!!"<<endl;
    cout<<"Postorder expression is "<<endl;
    cout<<":-   ";
    postorder(root);
    cout<<endl;
    cout<<"press any number to exit:- ";
    int a;
    cin>>a;
    return 0;
}