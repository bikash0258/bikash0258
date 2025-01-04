#include <iostream>
#include<fstream>
#include <string.h>
#include <iomanip>


using namespace std;
int size;
struct lists    
{
   string name;
   string branch;
   int roll_no, sem;
} s[50];
void Entry_records()
{
   cout << "***************ATTENDANCE MANAGEMENT SYSTEM*****************" << endl;
   cout << endl;
   cout << "| Enter the total no of students you want to create records |" << endl;
   cin >> size;
   cout << endl;
   cout << "Enter the students details for " << size << " students " << endl;
   cout << endl;
   cout << endl;
   for (int i = 0; i < size; i++)
   {
      cout << "Enter the name of the student " << endl;
      cin.ignore();
      getline(cin, s[i].name);
      cout << "Enter the roll no of a student " << endl;
      cin >> s[i].roll_no;
      cout << "Enter the branch of a student " << endl;
      cin >> s[i].branch;
      cout << "Enter the semester of a student " << endl;
      cin >> s[i].sem;
      cout << endl;
   }
}
void show_details()
{
   cout << "STUDENTS LIST ARE " << endl;
   cout << endl;
   cout << "  NAME " << setw(25) << "BRANCH" << setw(25) << "SEM" << setw(25) << "ROLL\n";
   cout << "_______________________________________________________________________________\n"
        << endl;
   for (int i = 0; i < size; i++)
   {

      cout << i + 1 << ". " << s[i].name << setw(20) << s[i].branch << setw(20) << s[i].sem << setw(20) << s[i].roll_no << "\n";
   }
   cout<<endl;
}
void delete_record()
{
   int pos;
   cout << "Enter the position " << endl;
   cin >> pos;
   if(pos<=0 || pos>size){
      cout<<"Invalid serial number "<<endl;
   }
   else{
   for (int i = pos - 1; i < size - 1; i++)
   {

      s[i] = s[i + 1];
   }
   size--;
   }
cout<<endl;
}
void search()
{
   int x=0;
   string str;
   cout << "Enter the name  of a student  you want to search in the record " << endl;
   cin.ignore();
   getline(cin, str);
   for (int i = 0; i < size; i++)
   {
      if (str.compare(s[i].name) == 0)
      {
         cout << "Yes student is available " << endl;
         cout << "Roll no is " << s[i].roll_no << endl;
         cout << "Branch is " << s[i].branch << endl;
         x=1;
         break;
      }
   }
   if(x==0){
      cout<<"No student found "<<endl;
   }
   cout<<endl;
}
void give_attendance(){
   string name;
   int roll;
   string x;
   cout<<"Enter the name "<<endl;
   cin.ignore();
   getline(cin,name);
   cout<<"Enter roll no : "<<endl;
   cin>>roll;
   cout<<"Present (y/n) "<<endl;
   cin.ignore();
   getline(cin,x);


   ofstream out("Attendance_record.txt");
   out<<name<<endl;
   out<<roll<<endl;
   out<<x<<endl;

}
int main()
{
   Entry_records();
   show_details();
   delete_record();
   show_details();
   search();
   give_attendance();
   return 0;
}
