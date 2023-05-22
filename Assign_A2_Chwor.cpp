#include<iostream>
#define SIZE 10
using namespace std;

typedef struct hashtable
{
    int val;
    int chain;
}htable;
class myhash
{
   private :
         htable HT[SIZE];
   public :
         myhash();  // initialize
         void display_htable();
         void insert_htable();
         void search_htable();
         void delete_htable();

};

myhash :: myhash()
{
   int i;
   for(i=0;i<SIZE;i++)
   {
        HT[i].val = -1;
        HT[i].chain = -1;
   }
}

void myhash :: display_htable()
{
   int i;
   for(i=0;i<SIZE;i++)
   {
       if(HT[i].val >= 0 )
           cout<<"\n\t["<<i<<"] ==>   "<<HT[i].val<<"    "<<HT[i].chain;
       else
          cout<<"\n\t["<<i<<"] ==> Empty"<<"    "<<HT[i].chain; 
   }
}

int get_hash_index(int X)
{
   return (X % SIZE);
}

void myhash :: insert_htable()
{
   int i,hi,li;
   int X;
   cout<<"\nEnter the identifier to be inserted : ";
   cin>>X;
   hi = get_hash_index(X);    
   if(HT[hi].val < 0)
   {
       HT[hi].val = X;
       cout<<"\nIdentifier inserted without collision at pos "<<hi;
   }
   else
   {
       li = hi;
       while(HT[li].chain != -1)
       {
           li = HT[li].chain;
       } 
       for(i= (li+1) % SIZE; i != hi ; i = (i + 1) % SIZE)
       {
            if(HT[i].val < 0)
            {
                HT[i].val = X;
                HT[li].chain = i; 
                cout<<"\nIdentifier inserted with collision at pos "<<i;
                break;
            } 
       }
       if(i == hi)
          cout<<"\nIdentifier cannot be inserted as hashtable is full\n";
   }
}

void myhash :: search_htable()
{
   int i,hi;
   int X;
   cout<<"\nEnter the identifier to be Searched : ";
   cin>>X;
   hi = get_hash_index(X);    
   if(HT[hi].val == -1)
   {
       cout<<"\nIdentifier to be searched NOT present in hash table";
   }
   else
   {
       i= hi; 
       do
       {
            if(HT[i].val == X)
            {
                cout<<"\nIdentifier found at pos "<<i;               
                break; 
            } 
            i = HT[i].chain; 
       }while(i != -1);
       if(i == -1)
          cout<<"\nIdentifier to be searched not present in hashtable\n";
   }
}


void myhash :: delete_htable()
{
   int i,hi,pi;
   int X;
   cout<<"\nEnter the identifier to be deleted : ";
   cin>>X;
   hi = get_hash_index(X);    
   if(HT[hi].val == -1)
   {
       cout<<"\nIdentifier to be deleted NOT present in hash table";
   }
   else
   {
       i= hi; 
       pi = -1;  
       do
       {
            if(HT[i].val == X)
            {
               if(HT[i].chain == -1)
               {
                  if(pi != -1)
                     HT[pi].chain = -1;
                  HT[i].val = -1;
               }  
               else
                HT[i].val = -2;  // delete indicator
              
                cout<<"\nIdentifier found and deleted successfully ";              break;  
            }
            pi = i;  
            i = HT[i].chain; 
       }while(i != -1);
       if(i == -1 )
          cout<<"\nIdentifier to be deleted not present in hashtable\n";
   }
}

int main()
{
   int ch;
   myhash h;
   do
   {
       cout<<"\n\n\n\t1: Display";
       cout<<"\n\t2: Insert";
       cout<<"\n\t3: Search";
       cout<<"\n\t4: Delete";
       cout<<"\n\t5: Exit";
       cout<<"\n\nEnter ur choice : ";
       cin>>ch;
       switch(ch)
       {
          case 1 : h.display_htable();
                   break;
          case 2 : h.insert_htable();
                   break;
          case 3 : h.search_htable();
                   break;
          case 4 : h.delete_htable();
                   break;
          case 5 : cout<<"\nEnd of Program\n\n";
                   break;
          default: cout<<"\nPlz try again\n"; 
       }
   }while(ch != 5);
}
