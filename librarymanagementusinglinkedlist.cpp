#include<bits/stdc++.h>
#include <cstdlib>
#include<windows.h>
using namespace std;
int serial_number = 1;
const int monthDays[12] = {31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31};
void gotoxy(int x,int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
//Date
struct date{
    int d;
    int m;
    int y;
};
int noofdays(date d1,date d2)
{
    int i;
    long long day1 = d1.y*365 + d1.d;
    for(i =0 ;i<d1.m -1;i++)
    day1 += monthDays[i];

    long long day2 = d2.y*365 + d2.d;
    for(i =0 ;i<d2.m -1;i++)
    day2 += monthDays[i];

    return day2 - day1;
}
//book
struct book{
    int accNo;
    string title;
    string author;
    int issuedFlag;
    string publication;
    book *nextB;
};

//student
struct student{
    int rollNo;
    string name;
    int bookNo;
    string bookTitle;
    string bookAuthor;
    date issueDate;
    date returnDate;
    student *nextS;
};

class library
{
    book *headB = NULL, *tailB = NULL;
    student *headS = NULL, *tailS = NULL;
public :
    library()
    {
        headB = new book;
        headB->accNo = serial_number++;
        headB->title = "C++";
        headB->author = "CP";
        headB->publication = "Saturn";
        headB->issuedFlag = 0;
        headB->nextB = NULL;
        tailB = headB;

        tailB->nextB = new book;
        tailB->nextB->accNo = serial_number++;
        tailB->nextB->title = "Wings of fire";
        tailB->nextB->author = "APJ";
        tailB->nextB->publication = "Balaji";
        tailB->nextB->issuedFlag = 0;
        tailB->nextB->nextB = NULL;
        tailB = tailB->nextB;

        tailB->nextB = new book;
        tailB->nextB->accNo = serial_number++;
        tailB->nextB->title = "Numerical Methods";
        tailB->nextB->author = "RK Jain";
        tailB->nextB->publication = "Neptune";
        tailB->nextB->issuedFlag = 0;
        tailB->nextB->nextB = NULL;
        tailB = tailB->nextB;

        tailB->nextB = new book;
        tailB->nextB->accNo = serial_number++;
        tailB->nextB->title = "The Coalition Years";
        tailB->nextB->author = "Pranab Mukherjee";
        tailB->nextB->publication = "Harper Collins.";
        tailB->nextB->issuedFlag = 0;
        tailB->nextB->nextB = NULL;
        tailB = tailB->nextB;

        tailB->nextB = new book;
        tailB->nextB->accNo = serial_number++;
        tailB->nextB->title = "Two Lives";
        tailB->nextB->author = "Vikram Seth";
        tailB->nextB->publication = "Hachette Book Group";
        tailB->nextB->issuedFlag = 0;
        tailB->nextB->nextB = NULL;
        tailB = tailB->nextB;
    }
    // Function for adding a new book in the library
    void createBook()
    {
           system("CLS");
            book *newBook;
            newBook = new book;
            cout<<"Enter the details of BOOK "<<serial_number++<<endl;
            cout<<"-----------------------------------";
            cout<<endl;
            cout<<"Enter the AccessionNo of book-";
            cin>>newBook->accNo;
            cout<<"Enter the Title of book-";
            cin>>newBook->title;
            cout<<"Enter the Author of book-";
            cin>>newBook->author;
            cout<<"Enter the name of publication-";
            cin>>newBook->publication;
            cout<<"-----------------------------------\n";
            newBook->nextB = NULL;
            newBook->issuedFlag=0;

            if(headB==NULL)
            {
                headB = newBook;
                tailB = headB;
            }
            else
            {
                tailB->nextB = newBook;
                tailB = newBook;
            }
            system("CLS");
    }
    void displayBooks()
    {
      system("CLS");
      int k=5;
      book *temp = headB;
      system("cls");
      gotoxy(1,2);
      cout << "TITLE";
      gotoxy(30,2);
      cout << "AUTHOR" ;
      gotoxy(50,2);
      cout<< "PUBLICATION";
      gotoxy(70,2);
      cout<< "BOOK NUMBER" << endl;
    while (temp)
    {
         gotoxy(1,k);
         cout<<temp->title;
         gotoxy(30,k);
         cout<<temp->author;
         gotoxy(50,k);
         cout<<temp->publication;
         gotoxy(70,k);
         cout<<temp->accNo<<endl;
       temp = temp->nextB;
       k++;
    }
}

    // Searches a book by it's Book No.(Accession Number)
    book* searchBook(int serialNO)
    {
        book *temp = headB;
        while(temp->accNo!=serialNO)
        {
            temp = temp->nextB;
            if(temp==NULL)
            break;
        }
        if(temp==NULL)
        {
          cout<<"Sorry! We don't have any book of Accession No -"<<serialNO<<endl;
        }
        else
        {
          cout<<"\nDetails of Book of Accession Number- "<<serialNO<<" are:\n";
          cout<<"-----------------------------------\n";
          gotoxy(1,5);
          cout<<"BOOK NUMBER";
          gotoxy(30,5);
          cout<<"TITLE";
          gotoxy(50,5);
          cout<<"AUTHOR";
          gotoxy(70,5);
          cout<<"PUBLICATION";
          gotoxy(90,5);
          cout<<"Issued Flag"<<endl;
          gotoxy(1,7);
          cout<<temp->accNo;
          gotoxy(30,7);
          cout<<temp->title;
          gotoxy(50,7);
          cout<<temp->author;
          gotoxy(70,7);
          cout<<temp->publication;
          gotoxy(90,7);
          cout<<temp->issuedFlag<<endl;
        }
        return temp;
    }
    //Adding the record of student issuing book
    void addStudent()
    {
        book *temp = headB, *t1=NULL;
        string t,a;
        cout<<"Enter the details of book : \nTitle : ";
        cin>>t;
        cout<<"Author :";
        cin>>a;
        while(temp!=NULL)
        {
            if(temp->title==t && temp->author==a && temp->issuedFlag==0)
            {
                t1 = temp;
                break;
            }

            temp = temp->nextB;
        }
        if(t1==NULL)
        {
          cout<<"Sorry! We don't have the book right now -"<<endl;
        }

        else
        {
            int roll;
            string n;
            cout<<"Enter student Roll No : ";
            cin>>roll;
            cout<<"\nEnter the name of student :";
            cin>>n;
            t1->issuedFlag = 1;
            student *newStu = new student;
            newStu->rollNo = roll;
            newStu->name = n;
            newStu->bookTitle = t;
            newStu->bookAuthor = a;
            newStu->bookNo = temp->accNo;
            date s;
            cout<<"Enter today's date : ";
            cout<<"DD :";
            cin>>s.d;
            cout<<"MM :";
            cin>>s.m;
            cout<<"YYYY :";
            cin>>s.y;
            newStu->issueDate = s;
            newStu->returnDate.d = -1;
            newStu->nextS = NULL;
            if(headS==NULL)
            {
                headS = newStu;
                tailS = newStu;
            }
            else
            {
                tailS->nextS = newStu;
                tailS = newStu;
            }
        }


    }
    // Searches a student having given Book No.
    student* searchStudent(student *head,int tempno)
    {
        student *temp = head;
        while(temp){
            if(temp->bookNo == tempno && temp->returnDate.d == -1)
            return temp;
            temp = temp->nextS;
        }
        return NULL;
    }
    //Record the data of student returning book
    void returnBook()
    {
        int tempno;
        cout<<"Enter your Book Number : ";
        cin>>tempno;
        student *temp = searchStudent(headS,tempno);
        if(temp)
        {
            cout<<"Enter Today's Date\nDD : ";
            cin>>temp->returnDate.d;
            cout<<"MM :";
            cin>>temp->returnDate.m;
            cout<<"YYYY :";
            cin>>temp->returnDate.y;
            int days = noofdays(temp->issueDate,temp->returnDate);
            system("cls");
            if(days > 15)
            {
                cout<<"Fine of 100 rs will be imposed"<<endl;

            }
            else
            {
                cout<<"\nYour book have been submitted"<<endl;
            }
            book *tempbook;
            tempbook = searchBook(tempno);
            tempbook->issuedFlag = 0;
        }
    }
    //Showing the record of students as per need
    void displayStudents()
    {
        int k=3;
        int choice;
        cout<<"What type of list is required : \n1.Those who  haven't returned the book yet\n2.Those who returned the book\n";
        cin>>choice;
        switch (choice)
        {
            case 1:
            {
                system("CLS");
                student *temp  = headS;
                gotoxy(1,1);
                cout<<"Roll No";
                gotoxy(21,1);
                cout<<"Name";
                gotoxy(41,1);
                cout<<"Book No";
                gotoxy(61,1);
                cout<<"Issue Date"<<endl;
                if(temp==0)
                    cout<<"NO data";
                while(temp)
                {
                    if(temp->returnDate.d == -1)
                    {
                        gotoxy(1,k);
                        cout<<temp->rollNo;
                        gotoxy(21,k);
                        cout<<temp->name;
                        gotoxy(41,k);
                        cout<<temp->bookNo;
                        gotoxy(61,k);
                        cout<<temp->issueDate.d<<"/"<<temp->issueDate.m<<"/"<<temp->issueDate.y;
                        k++;
                    }
                    temp = temp->nextS;
                }
                break;
            }
            k=3;
            case 2:
            {
               system("CLS");
                student *temp  = headS;
                gotoxy(1,1);
                cout<<"Roll No";
                gotoxy(21,1);
                cout<<"Name";
                gotoxy(41,1);
                cout<<"Book No";
                gotoxy(49,1);
                cout<<"Issue Date";
                gotoxy(61,1);
                cout<<"Return Date";
                cout<<endl;
                if(temp==0)
                cout<<"No data";
                while(temp)
                {
                    if(temp->returnDate.d != -1)
                    {

                        gotoxy(1,k);
                        cout<<temp->rollNo;
                        gotoxy(21,k);
                        cout<<temp->name;
                        gotoxy(41,k);
                        cout<<temp->bookNo;
                        gotoxy(49,k);
                        cout<<temp->issueDate.d<<"/"<<temp->issueDate.m<<"/"<<temp->issueDate.y;
                        gotoxy(61,k);
                        cout<<temp->returnDate.d<<"/"<<temp->returnDate.m<<"/"<<temp->returnDate.y;
                        k++;
                    }
                    temp = temp->nextS;
                }
                break;
            }
        }
    }
};
int main()
{
    library l1;
    int option=0;
    system("CLS");
    while(option!=7)
    {
        cout<<"\nWhat do you want to do :";
        cout<<"\n1.Issue a book to the student";
        cout<<"\n2.Return a book from the student";
        cout<<"\n3.Display all books in the library";
        cout<<"\n4.Display student database as per need";
        cout<<"\n5.Add new Book in the library";
        cout<<"\n6.Search a book by its accession number";
        cout<<"\n7.Exit\n";
        cin>>option;
        switch (option)
        {
            case 1:
            {
                system("CLS");
                l1.addStudent();
                break;
            }
            case 2:
            {
                system("CLS");
                l1.returnBook();
                break;
            }
            case 3:
            {
                system("CLS");
                l1.displayBooks();
                break;
            }
            case 4:
            {
                system("CLS");
                l1.displayStudents();
                break;
            }
            case 5:
            {
                system("CLS");
                l1.createBook();
                break;
            }
            case 6:
            {
                system("CLS");
                int br;
                cout<<"Enter the accession No. of the book to be searched : ";
                cin>>br;
                l1.searchBook(br);
                break;
            }
        }
    }
    return 0;
}