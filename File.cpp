/*
Department maintains a student information. The file contains roll number, name, division
and address. Allow user to add, delete information of student. Display information of
particular employee. If record of student does not exist an appropriate message is displayed.
If it is, then the system displays the student details. Use sequential file to main the data.
*/

#include<iostream>
#include<fstream>
#include<stdio.h>
using namespace std;

typedef struct student
{
   int roll;
   char name[20];
   int marks;
}stud;

class myfile
{
   private :
        char fname[20];
   public : 
        myfile();
        void create_file(); 
        void display_file(); 
        void append_file(); 
        void search_file(); 
        void modify_file(); 
        void delete_file(); 
};

myfile :: myfile()
{
   cout<<"\nEnter the filename : ";
   cin>>fname;
}

void myfile :: create_file()
{
   ofstream f1;
   int i,n;
   stud s;
   f1.open(fname,ios::binary | ios :: out);
   if(f1.is_open())
   {
      cout<<"\nEnter the no. of records to add : ";
      cin>>n;
      for(i=0;i<n;i++)
      {
         cout<<"\nEnter the record info (roll,name, marks) : ";
         cin>>s.roll>>s.name>>s.marks;
         f1.write((char *)&s,sizeof(s));
      } 
      f1.close();
      cout<<"\nFile created successfully";
   }
   else
      cout<<"\nError in opening the file for creating";
}



void myfile :: display_file()
{
   ifstream f1;
   int i,n;
   stud s;
   f1.open(fname,ios::binary | ios :: in);
   if(f1.is_open())
   {
      cout<<"\nContents of the file are as : \n";
      while(f1.read((char *)&s,sizeof(s)))       
      {
         cout<<"\n\t"<<s.roll<<"  "<<s.name<<"  "<<s.marks;
      } 
      f1.close();
   }
   else
      cout<<"\nError in opening the file for reading";
}

void myfile :: append_file()
{
   ofstream f1;
   char ans;
   stud s;
   f1.open(fname,ios::binary | ios :: app);
   if(f1.is_open())
   {
      do
      {
         cout<<"\nEnter the record to be appended(roll,name, marks) : ";
         cin>>s.roll>>s.name>>s.marks;
         f1.write((char *)&s,sizeof(s));
         cout<<"\nDo u want to append more(y/n) ? ";
         cin>>ans;
      }while(ans == 'y'); 
      f1.close();
      cout<<"\nRecord inserted successfully";
   }
   else
      cout<<"\nError in opening the file for creating";
}

void myfile :: search_file()
{
   ifstream f1;
   int key;
   int i,n;
   int flag = 0;
   stud s;
   f1.open(fname,ios::binary | ios :: in);
   if(f1.is_open())
   {
      cout<<"\nEnter the roll whose record to be searched : ";
      cin>>key;
      while(f1.read((char *)&s,sizeof(s)))       
      {
         if(s.roll == key)
         {
            cout<<"\nRecord found ";
            cout<<"\n\t"<<s.roll<<"  "<<s.name<<"  "<<s.marks;
            flag = 1;
            break;
         }  
      } 
      if(flag == 0)
         cout<<"\nRecord to be searched not present in the file";
      f1.close();
   }
   else
      cout<<"\nError in opening the file for reading";
}

void myfile :: modify_file()
{
   fstream f1;
   int key;
   int i,n;
   int flag = 0;
   stud s;
   f1.open(fname,ios::binary | ios :: in | ios :: out);
   if(f1.is_open())
   {
      cout<<"\nEnter the roll whose record to be modified: ";
      cin>>key;
      while(f1.read((char *)&s,sizeof(s)))       
      {
         if(s.roll == key)
         {
            cout<<"\nEnter the new info (roll,name, marks) : ";
            cin>>s.roll>>s.name>>s.marks;
            f1.seekp(-(long)sizeof(s),ios::cur); 
            f1.write((char *)&s,sizeof(s));
            cout<<"\nRecord found and modified successfully";
            flag = 1;
            break;
         }  
      } 
      if(flag == 0)
         cout<<"\nRecord to be modified not present in the file";
      f1.close();
   }
   else
      cout<<"\nError in opening the file for modifying";
}

void myfile :: delete_file()
{
   ifstream f1;
   ofstream f2;
   int key;
   int i,n;
   int flag = 0;
   stud s;
   f1.open(fname,ios::binary | ios :: in);
   if(f1.is_open())
   {
      cout<<"\nEnter the roll whose record to be deleted : ";
      cin>>key;
      f2.open("temp.dat",ios::binary|ios::out);
      while(f1.read((char *)&s,sizeof(s)))       
      {
         if(s.roll != key)
            f2.write((char *)&s,sizeof(s));
         else
             flag = 1;         
      } 
      f1.close();
      f2.close();
      if(flag == 0)
      { 
         cout<<"\nRecord to be deleted not present in the file";
         remove("temp.dat"); 
      }
      else
      {
          remove(fname);
          rename("temp.dat",fname);
          cout<<"\nRecord found and deleted successfully";
      } 
   }
   else
      cout<<"\nError in opening the file for reading";
}


int main()
{
   int ch;
   myfile S1;
   do
   {
       cout<<"\n\n\n\t1: Create";
       cout<<"\n\t2: Display";
       cout<<"\n\t3: Append";
       cout<<"\n\t4: Search";
       cout<<"\n\t5: Modify";
       cout<<"\n\t6: Delete";
       cout<<"\n\t7: Exit";
       cout<<"\n\nEnter ur choice : ";
       cin>>ch;
       switch(ch)
       {
          case 1 : S1.create_file();
                   break;
          case 2 : S1.display_file();
                   break;
          case 3 : S1.append_file();
                   break;
          case 4 : S1.search_file();
                   break;
          case 5 : S1.modify_file();
                   break;
          case 6 : S1.delete_file();
                   break;
          case 7 : cout<<"\nEnd of Program\n\n";
                   break;
          default: cout<<"\nPlz try again\n"; 
       }
   }while(ch != 7);
}
