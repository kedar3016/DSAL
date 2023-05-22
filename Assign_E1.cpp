/*
Read the marks obtained by students of second year in an online examination of particular subject. Find out maximum and minimum marks obtained in that subject. Use heap data structure. Analyze the algorithm.*/

#include<iostream>
using namespace std;

class student
{
   private :
       int Marks[20];
       int n;
       int hs;
   public : 
       student();
       void Max_heapify(int);
       void build_Max_heap();
       void Min_heapify(int);
       void build_Min_heap();
       void accept_student_info();
       void display_student_info();
       void find_Max_Min_marks_of_student();
};

student :: student()
{
   n = 0;
   hs = 0;
}

void student :: accept_student_info()
{
   int i;
   cout<<"\nEnter the total no. of students : ";
   cin>>n;
   for(i=1;i<=n;i++)
   {
      cout<<"\nEnter the DSA online marks of Student "<<i<<" : ";
      cin>>Marks[i];
   }
   cout<<"\nInformation accepted successfully\n";
}

void student :: display_student_info()
{
   int i;
   cout<<"\nTotal no. of students : "<<n;
   cout<<"\nMarks obtained in DSA Online Exam";
   for(i=1;i<=n;i++)
   {
      cout<<"\n\tStudent "<<i<<" : "<<Marks[i];
   }
}

void student :: Max_heapify(int i)       
{
   int big,lc,rc,temp;
   lc = 2*i;
   rc = 2*i + 1;
   if(lc <= hs && Marks[lc] > Marks[i])
      big = lc;
   else
      big = i;
   if(rc <= hs && Marks[rc] > Marks[big])
      big = rc;
   if(big != i)
   {
       temp = Marks[i];
       Marks[i] = Marks[big];
       Marks[big] = temp;
       Max_heapify(big);
   }      
}

void student :: build_Max_heap()
{
   int i;
   hs = n;
   for(i = n/2 ; i>= 1; i--)
   {
      Max_heapify(i);  
   }
}

void student :: Min_heapify(int i)       
{
   int small,lc,rc,temp;
   lc = 2*i;
   rc = 2*i + 1;
   if(lc <= hs && Marks[lc] < Marks[i])
      small = lc;
   else
      small = i;
   if(rc <= hs && Marks[rc] < Marks[small])
      small = rc;
   if(small != i)
   {
       temp = Marks[i];
       Marks[i] = Marks[small];
       Marks[small] = temp;
       Min_heapify(small);
   }      
}

void student :: build_Min_heap()
{
   int i; 
   hs = n;
   for(i = n/2 ; i>= 1; i--)
   {
      Min_heapify(i);  
   }
}

void student :: find_Max_Min_marks_of_student()
{
   build_Max_heap();
   cout<<"\nMaximum marks obtained in DSA Online exam is : "<<Marks[1];
   build_Min_heap();
   cout<<"\nMinimum marks obtained in DSA Online exam is : "<<Marks[1];
}


int main()
{
   int ch;
   student s1;
   do
   {
      cout<<"\n\t\t1 : Accept Student Info";
      cout<<"\n\t\t2 : Display Sttudent Info";
      cout<<"\n\t\t3 : Display Max & Min Marks";
      cout<<"\n\t\t4 : Exit";
      cout<<"\n\nEnter ur choice : ";
      cin>>ch;
      switch(ch)
      {
         case 1 : s1.accept_student_info();
                  break;
         case 2 : s1.display_student_info();
                  break;
         case 3 : s1.find_Max_Min_marks_of_student();
                  break;
         case 4 : cout<<"\nGood bye\n";
                  break;
         default: cout<<"\nWrong choice !! Try again\n\n";
      }
   }while(ch != 4);
   return 0;
}
