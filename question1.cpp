/*
Consider telephone book database of N clients. Make use of a hash table implementation to quickly look up client‘s telephone number. Make use of two collision handling techniques and compare them using number of comparisons required to find a set of telephone numbers
*/

#include <iostream>
#include <string>
using namespace std;
int size;

struct h
{
    string name;
    long long number;
};

class hashTable
{

    h A[20];
    string temp;

public:
    hashTable()
    {
        A[size];
        for (int i = 0; i < size; i++)
        {
            A[i].number = 0000000000;
        }
        for (int i = 0; i < size; i++)
        {
            A[i].name = "null";
        }
    }

    int hashfunction(long long numb)
    {
        return numb % size;
    }

    void insert_data()
    {
        long long temp;
        cout << "Enter number:- ";
        cin >> temp;
        int hash = hashfunction(temp);

        if (A[hash].name == "null")
        {
            A[hash].number = temp;
            cout << "Enter name:- ";
            cin >> A[hash].name;
            cout << "\n\t\tNumber is placed without any collision" << endl;
            return;
        }
        cout << "collision is occuring.\n use one of the collosion handling method from following:-  1: linear method \n\t\t\t\t\t\t\t    2: quadratic method" << endl;
        int choice;
        cout << "Enter your choice:- ";
        cin >> choice;
        if (choice == 1)
        {
            // linear collision handling
            for (int i = (hash + 1) % size; i != hash; i = (i + 1) % size)
            {
                if (A[i].name == "null")
                {
                    A[i].number = temp;
                    cout << "Enter name:- ";
                    cin >> A[i].name;
                    cout << "\n\t\tNumber is placed with collision" << endl;
                    break;
                }
            }
        }
        else if (choice == 2)
        {
            int j = 1;
            for (int i = (hash + (j * j)) % size; i != hash; i = ( j * j) % size)
            {
                if (A[i].name == "null")
                {
                    A[i].number = temp;
                    cout << "Enter name:- ";
                    cin >> A[i].name;
                    cout << "\n\t\tNumber is placed with collision" << endl;
                    break;
                }
                j++;
            }
            // quadratic collision handling
        }
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << A[i].name << " = " << A[i].number << endl;
        }
    }

    void search_number()
    {
        long long n;
        cout << "Enter the  number that you want to search :- ";
        cin >> n;
        int hash = hashfunction(n);

        int linear = 1;
        int quadratic = 1;

        if (A[hash].number == n)
        {
            cout << "Found with name " << A[hash].name << endl;
            cout << "linear comparision:- " << linear << endl
                 << "Quadratic comparision:- " << quadratic << endl;
        }
        else
        {
            // linear collision handling
            int i;
            for (i = (hash + 1) % size; i != hash; i = (i + 1) % size)
            {
                linear++;
                if (A[i].number == n)
                {
                    cout << "Found with name " << A[i].name << endl;
                    cout << "linear comparision:- " << linear << endl;
                break;
                }
            }
            if (i == hash)
            {
                cout << "not found in the data base. " << endl;
            }

            if (i != hash)
            {
                int j = 1;
                for (int i = (hash + (j * j)) % size; ; i = (i + j * j) % size)
                {
                    quadratic++;
                    if (A[i].number == n)
                    {
                        cout << "Quadratic comparision:- " << quadratic << endl;
                        break;
                    }
                    j++;
                }
            }
        }
    }
};

int main()
{
    cout << "Enter the number size of data base:- ";
    cin >> size;
    cout << size << endl;

    int ch;
    hashTable phone;
    while (ch != 4)
    {
        cout <<"\n\t\t\t1: Insert";
        cout <<"\n\t\t\t2: Display";
        cout <<"\n\t\t\t3: Search number";
        cout <<"\n\t\t\t4: Exit";
        cout<<"\nEnter your Choice:-";
        cin >> ch;
        switch (ch)
        {
        case 1:
            phone.insert_data();
            break;

        case 2:
            phone.display();
            break;
        case 3:
            phone.search_number();
            break;

        default:
            break;
        }
    }

    return 0;
}
