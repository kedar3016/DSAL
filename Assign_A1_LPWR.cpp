#include<iostream>
#define SIZE 10
using namespace std;

class myhashtable
{
   private :
       int HT[SIZE];
   public : 
       myhashtable();
       void display_hashtable();
       void insert_hashtable();
       void search_hashtable();
       void delete_hashtable();
};

myhashtable :: myhashtable()
{
   int i;
   for(i = 0 ; i < SIZE ;i++)
   {
      HT[i] = -1;
   }
}

void myhashtable :: display_hashtable()
{
   int i;
   cout<<"\nHash table is ";
   for(i = 0 ; i < SIZE ;i++)
   {
      if(HT[i] < 0 )
         cout<<"\n\t["<<i<<"] ==> Empty";
      else   
         cout<<"\n\t["<<i<<"] ==> "<<HT[i];
   }
}

int get_hash_index(int X)
{
   return(X % SIZE);
}

void myhashtable :: insert_hashtable()
{
   int i,hi,ri;
   int X,temp;
   cout<<"\nEnter the identifier to be inserted : ";
   cin>>X;
   hi = get_hash_index(X);
   if(HT[hi] < 0)
   {
      HT[hi] = X;
      cout<<"\nIdentifier "<<X<<" inserted without collision at "<<hi<<" position";
   }
   else
   {
      ri = get_hash_index(HT[hi]);
      if(ri != hi)
      {
         cout<<"\nIdentifier "<<HT[hi]<<" will be replaced by "<<X<<" at "<<hi<<" position";
         temp = HT[hi];
         HT[hi] = X;
         X = temp;
      } 
      for( i = (hi + 1)%SIZE ; i != hi; i = (i +1) %SIZE)
      {
         if(HT[i] < 0)
         {
            HT[i] = X;
            cout<<"\nIdentifier "<<X<<" inserted with collision at "<<i<<" position";
            break;
         }
      }
      if(i == hi)
         cout<<"\nIdentifier "<<X<<" cannot be inserted as hashtable is full";
   }
}

void myhashtable :: search_hashtable()
{
   int i,hi;
   int flag = 0;
   int X;
   cout<<"\nEnter the identifier to be searched : ";
   cin>>X;
   hi = get_hash_index(X);
   if(HT[hi] == -1)
   {
      cout<<"\nIdentifier "<<X<<" not present in the hashtable ";
   }
   else
   {
      i = hi;
      do
      {
          if(HT[i] == X)
          {
             cout<<"\nIdentifier "<<X<<" found at "<<i<<" position";
             flag = 1; 
             break;  
          }
          i = (i + 1) % SIZE;
      }while(i != hi && HT[i] != -1);
      if(flag == 0)
         cout<<"\nIdentifier "<<X<<" not present in the table";
   }
}

void myhashtable :: delete_hashtable()
{
   int i,hi,j;
   int flag = 0;
   int X;
   cout<<"\nEnter the identifier to be deleted : ";
   cin>>X;
   hi = get_hash_index(X);
   if(HT[hi] == -1)
   {
      cout<<"\nIdentifier "<<X<<"to be deleted not present in the hashtable ";
   }
   else
   {
      i = hi;
      do
      {
          if(HT[i] == X)
          {
             cout<<"\nIdentifier "<<X<<" found at "<<i<<" position and deleted succesfully";
             if(i == hi)
             {
                for(j = (hi+1)%SIZE; j != hi && HT[j] != -1; j = (j +1) %SIZE)
                {
                    if(get_hash_index(HT[j]) == hi)
                    {
                       HT[hi] = HT[j];
                       HT[j] = -2;
                       break;
                    }
                }
             }    
             else
                HT[i] = -2;
             flag = 1; 
             break;  
          }
          i = (i + 1) % SIZE;
      }while(i != hi && HT[i] != -1);
      if(flag == 0)
         cout<<"\nIdentifier to be deleted"<<X<<" not found in the table";
   }
}

int main()
{
   int ch;
   myhashtable h1;
   do
   {
      cout<<"\n\t\t1 : Insert";
      cout<<"\n\t\t2 : Search";
      cout<<"\n\t\t3 : Display";
      cout<<"\n\t\t4 : Delete";
      cout<<"\n\t\t5 : Exit";
      cout<<"\n\nEnter ur choice : ";
      cin>>ch;
      switch(ch)
      {
         case 1 : h1.insert_hashtable();
                  break;
         case 2 : h1.search_hashtable();
                  break;
         case 3 : h1.display_hashtable();
                  break;
         case 4 : h1.delete_hashtable();
                  break;
         case 5 : cout<<"\nGood bye\n";
                  break;
         default: cout<<"\nWrong choice !! Try again\n\n";
      }
   }while(ch != 5);
   return 0;
}
