/*
Implement all the functions of a dictionary (ADT) using hashing and handle collisions
using chaining with / without replacement.
Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable,
Keys must be unique. Standard Operations: Insert(key, value), Find(key), Delete(key)
*/

#include <iostream>
#include <string>
using namespace std;
int size;
struct dic
{
    int marks;
    string students;
    int chain;
};

class dictionary
{
    dic array[10];
    int n;

public:
    dictionary()
    {
        array[size];
        for (int i = 0; i < size; i++)
        {
            array[i].marks = -1;
            array[i].students = "null";
            array[i].chain = -1;
        }
    }

    int hash_function(int key)
    {
        return key % size;
    }

    void insert()
    {
        int n;
        cout << "Enter the key(marks) :- ";
        cin >> n;
        int hash = hash_function(n);
        if (array[hash].marks == -1)
        {
            string name;
            cout << "Enter the value (name):- ";
            cin >> name;
            array[hash].marks = n;
            array[hash].students = name;
        }
        else
        {
            if (array[hash].chain == -1)
            {
                for (int i = (hash + 1) % size; i != hash; i = (++i) % size)
                {
                    if (array[i].marks == -1)
                    {
                        string name;
                        cout << "Enter the value (name):- ";
                        cin >> name;
                        array[i].marks = n;
                        array[i].students = name;
                        array[hash].chain = i;
                        break;
                    }
                }
            }
            else
            {
                int i = hash;
                while (array[i].chain != -1)
                {
                    i = array[i].chain;
                    cout << i << endl;
                }

                for (int j = (hash + 1) % size; j != hash; j = (++j) % size)
                {
                    cout << "run" << endl;
                    cout << j << endl;
                    if (array[j].marks == -1)
                    {
                        string name;
                        cout << "Enter the value (name):- ";
                        cin >> name;
                        array[j].marks = n;
                        array[j].students = name;
                        array[i].chain = j;
                        break;
                    }
                }
            }
        }
    }

    void search()
    {
        int n;
        cout << "Enter the key(marks) that you want to search:- " << endl;
        cin >> n;
        int hash = hash_function(n);
        if (array[hash].marks != -1)
        {
            while (1)
            {
                if (array[hash].marks == n)
                {
                    cout << array[hash].students << endl;
                    break;
                }
                hash = array[hash].chain;
            }
        }
        else
            cout << "Not found" << endl;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << array[i].students << " :- " << array[i].marks << "     " << array[i].chain << endl;
        }
    }

    void delete_entry()
    {
        int n;
        int backtrack = 0;
        cout << "Enter the key (marks) that you want to delete:- ";
        cin >> n;
        int hash = hash_function(n);
        if (array[hash].marks != -1)
        {
            while (1)
            {
                if (array[hash].marks == n)
                {
                    if (hash == hash_function(n) && array[hash].chain == -1)
                    {
                        array[hash].marks = -1;
                        array[hash].students = "null";
                        cout<<"Element deleted !"<<endl;
                        break;
                    }
                    if(array[hash].chain==-1)
                    {
                        array[backtrack].chain=-1;
                        cout<<backtrack<<endl;
                        array[hash].marks = -1;
                        array[hash].students = "null";
                        cout<<"Element deleted !"<<endl;
                        break;
                    }

                    if(array[hash].chain!=-1)
                    {
                        array[hash].students = array[array[hash].chain].students;
                        array[hash].marks = array[array[hash].chain].marks;
                        array[hash].chain = array[array[hash].chain].chain;
                        hash = array[hash].chain;
                        array[hash].marks = -1;
                        array[hash].students = "null";
                        array[hash].chain = -1;
                        cout<<"Element deleted !"<<endl;
                        break;
                    }
                    break;
                }
                backtrack = hash;
                hash = array[hash].chain;
            }
        }
        else
            cout << "Not found" << endl;
    }
};

int main()
{

    cout << "Enter the size of dictionary :-  ";
    cin >> size;
    dictionary dc;
    int ch;
    while (ch != 5)
    {
        cout << "\n\t\t\t1: Insert" << endl;
        cout << "\n\t\t\t2: Display" << endl;
        cout << "\n\t\t\t3: Search number" << endl;
        cout << "\n\t\t\t4: Delete" << endl;
        cout << "\n\t\t\t5: Exit" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            dc.insert();
            break;

        case 2:
            dc.display();
            break;
        case 3:
            dc.search();
            break;
        case 4:
            dc.delete_entry();
        default:
            break;
        }
    }

    return 0;
}
