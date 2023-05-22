#include<iostream>
#define SIZE 10

using namespace std;
typedef struct hash_table
{
   int val;
   int chain;
}htable;
class myhash
{
   private :
         htable HT[SIZE];
   public :
         myhash(); 
         void display_htable();
         void insert_htable();
         void search_htable();
         void delete_htable();

};
myhash :: myhash()
{
  int i;
  for(i = 0;i<SIZE; i++)
  {
      HT[i].val = -1;
      HT[i].chain = -1;
  }
}

void myhash :: display_htable()
{
  int i;
  for(i = 0;i<SIZE; i++)
  {
      if(HT[i].val > -1)
        cout<<"\n\t["<<i<<"] ==>  "<<HT[i].val<<"  "<<HT[i].chain;
      else
       cout<<"\n\t["<<i<<"] ==> Empty "<<HT[i].chain;
  }
}

int get_hash_index(int X)
{
   return(X%SIZE);
}

void myhash :: insert_htable()
{
  int i,hi,li,ri;
  htable X = {-1,-1};
  htable temp;
  cout<<"\nEnter the key to be inserted : ";
  cin>>X.val;
   X.chain = -1;
  hi = get_hash_index(X.val);
  if(HT[hi].val <= -1)
  {
     HT[hi] = X;
     cout<<"\n"<<X.val<<" key inserted successfully without collison at pos "<<hi;
  }
  else
  {
     ri = get_hash_index(HT[hi].val);
     if(hi != ri)
     {
        cout<<"\nReplacement occured";
        temp = HT[hi];
        HT[hi] = X;
        cout<<"\n"<<temp.val<<" key is replaced by key "<<X.val;
        li = ri;
        while(HT[li].chain != hi)
           li = HT[li].chain;
        hi = ri; 
        HT[li].chain = -1;
        X = temp;        
     } 
     li = hi;
     while(HT[li].chain != -1)
     {
         li = HT[li].chain;
     }
     for(i = (li + 1) % SIZE; i != hi; i= (i+1) % SIZE)
     {
        if(HT[i].val <= -1)
        {
          HT[i] = X;
          HT[li].chain = i;  // chaining
          cout<<"\n"<<X.val<<" key inserted successfully with collison at pos "<<i;
          break;
        } 
     }
     if(i == hi)
        cout<<"\n"<<X.val<<" key cannot be inserted as hashtable is full";
  }
}


void myhash :: search_htable()
{
  int i,hi;
  int X;
  cout<<"\nEnter the key to be searched : ";
  cin>>X;
  hi = get_hash_index(X);
  if(HT[hi].val == -1)
  {
     cout<<"\n"<<X<<" key to be searched not present in the table ";
  }
  else
  {
     i = hi; 
          
     do
     {
        if(HT[i].val == X)
        {
          cout<<"\n"<<X<<" key to be searched found at pos "<<i;
          break;
        } 
        i= HT[i].chain;
     }while(i != -1);
     if(i == -1)
        cout<<"\n"<<X<<" key to be searched not present in the table ";
  }
}

void myhash :: delete_htable()
{
  int i,hi,pi,ni;
  int X;
  int flag = 0;
  cout<<"\nEnter the key to be delete : ";
  cin>>X;
  hi = get_hash_index(X);
  if(HT[hi].val == -1)
  {
     cout<<"\n"<<X<<" key to be deleted not present in the table ";
  }
  else
  {
     i = hi; 
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
          {
             ni = HT[i].chain;
             HT[i] = HT[ni];
             HT[ni].val = -1; HT[ni].chain = -1; 
          }
          cout<<"\n"<<X<<" key found and deleted succesfully";
          break;
        } 
        pi = i; 
        i= HT[i].chain;
     }while(i != -1);
     if(i == -1)
        cout<<"\n"<<X<<" key to be deleted not present in the table ";
  }
}

int main()
{
   int ch;
   myhash h;
   do
   {
       cout<<"\n\n\t1: Insert";
       cout<<"\n\t2: Search";
       cout<<"\n\t3: Delete";
       cout<<"\n\t4: Display";
       cout<<"\n\t5: Exit";
       cout<<"\n\nEnter ur choice : ";
       cin>>ch;
       switch(ch)
       {
          case 1 : h.insert_htable();
                   break;
          case 2 : h.search_htable();
                   break;
          case 3 : h.delete_htable();
                   break;
          case 4 : h.display_htable();
                   break;
          case 5 : cout<<"\nEnd of Program\n\n";
                   break;
          default: cout<<"\nPlz try again\n"; 
       }
   }while(ch != 5);
}
