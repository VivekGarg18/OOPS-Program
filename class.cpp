#include<iostream>
#include<string>
using namespace std;

class Student{
public:
      
    string name;
    int roll;
    string subject;
    float marks;

    //Constructor --> Parameterized Constructor
    Student(string name, int roll, string subject, float marks){

        cout<<"Hi,I am constructor."<<endl;

        this -> name=name;
        this -> roll=roll;
        this -> subject=subject;
        this -> marks=marks;

    }

    //Constructor --> Copy Constructor
    Student(Student &cop){

        this -> name=cop.name;
        this -> roll=cop.roll;
        this -> subject=cop.subject;
        this -> marks=cop.marks;

    }
      
    //Destructor
    ~ Student(){

        cout<<"Hi,I am destructor."<<endl;

    }

    void Info(){

        cout<<"Name of student :"<<name<<endl;
        cout<<"Roll of student :"<<roll<<endl;
        cout<<"Subject of student :"<<subject<<endl;
        cout<<"Marks of student :"<<marks<<endl;       
    }


};

//Inheritance --> Parent,Base Class 
class Person{
public:

    string name;
    int age;

    Person(string name, int age){

          this -> name=name;
          this -> age=age;
    }
};

//Inheritance --> Child,Derived class 
//Single-level Inheritance(Inherits from Person class)
class Student1 : public Person{
public:

   int roll;
                           
   //Call Base Class Constructor
   Student1(string name, int age, int roll) : Person( name, age){

           this -> roll=roll;

   }

   void Display(){

           cout<<"Name of student :"<<name<<endl;
           cout<<"Age of student :"<<age<<endl;
           cout<<"Roll of student :"<<roll<<endl;
   }
};

//Multi-level Inheritance(Inherits from Student1 class)
class Gradstudent : public Student1 {
public:
      
      string researcharea;

      //Call Student1 class Construcor
      Gradstudent(string name, int age, int roll, string researcharea) : Student1(name,age,roll){

                 this -> researcharea=researcharea;
      }

    void Getinfo(){
          
         cout<<"Name of student :"<<name<<endl;
         cout<<"Age of student :"<<age<<endl;
         cout<<"Roll of student :"<<roll<<endl;
         cout<<"Researcharea of student :"<<researcharea<<endl;

    }
};

//Base class
class Research{
public:

       string project;


       Research(string project){

               this -> project=project;
       }

};

//Base class
class Employee{
public:
       
      int Id;
      float salary;


      Employee(int Id, float salary){

               this -> Id=Id;
               this -> salary=salary;

      }

};

//Multiple Inheritance(Inherits from Gradstudent , Research , Employee classes)
class TeachingAssistant : public Gradstudent, public Research, public Employee {
public:
 
      string subject;


      //Call Gradstudent class constructor , Research class constructor, Employee class construcor
      TeachingAssistant(string name, int age, int roll, string researcharea, string project, string subject, int Id, float salary) : Gradstudent(name, age, roll, researcharea), Research(project), Employee(Id, salary){

                        this -> subject=subject;

      }

    void Getdata(){

         cout<<"Name of student :"<<name<<endl;
         cout<<"Age of student :"<<age<<endl;
         cout<<"Roll of student :"<<roll<<endl;
         cout<<"Researcharea of student :"<<researcharea<<endl;
         cout<<"Project of research :"<<project<<endl;
         cout<<"Subject that teaching of student :"<<subject<<endl;
         cout<<"Id of TeacherAssistant :"<<Id<<endl;
         cout<<"Salary of teaching :"<<salary<<endl;



    }

};

//Hierarchical Inheritance
//First Derived class(Inherits from Person class)
class SchoolStudent : public Person{
public:
 
      int standard;

      //Call Person class constructor
      SchoolStudent(string name, int age, int standard) : Person(name,age){

                   this -> standard=standard;

      }

    void showschoolstudent(){

         cout<<"Name of student :"<<name<<endl;
         cout<<"Age of student :"<<age<<endl;
         cout<<"Standard of student :"<<standard<<endl;

    }

};

//Second Derived class(Inherits from Person class)
class CollegeStudent : public Person{
public:
 
      string course;

      //Call Person class constructor
      CollegeStudent(string name, int age, string course) : Person(name,age){

                    this -> course=course;

      }

    void showcollegestudent(){

         cout<<"Name of student :"<<name<<endl;
         cout<<"Age of student :"<<age<<endl;
         cout<<"Course of student :"<<course<<endl;

    }

};

//Base class
class Sports{
public:

      string sports;

      Sports(string sports){

            this -> sports=sports;

      }

};

//Hybrid INheritance
//Hierarchical + Multiple Inheritance
class SportsStudent : public CollegeStudent, public Sports{
public:

      //Call CollegeStudent class constructor and Sports class constructor
      SportsStudent(string name, int age, string course, string sports) : CollegeStudent(name,age,course),Sports(sports){


      }


    void showsports(){

         cout<<"Name of student :"<<name<<endl;
         cout<<"Age of student :"<<age<<endl;
         cout<<"Course of student :"<<course<<endl;
         cout<<"Sports in which student enroll :"<<sports<<endl;

    }

      
};

//Base class
class Parent{
public:
      
      //Virtual Function
      virtual void Getinfo(){

           cout<<"Hello from Parent class."<<endl;

      }

};

//Derived class
class Child : public Parent{
public:
 
      //Overriding the virtual function
      void Getinfo(){

           cout<<"Hello from Child class."<<endl;

      }

};

int main()
{
    //Student s1("Vivek",18,"Programming",85.18);
    //Student s2(s1);
    //s1.Info();
    //s2.Info();

    //Student1 v("Vivek",18,269);
    //v.Display();

    //Gradstudent g("Vivek",18,85,"Quantum Computer");
    //g.Getinfo();

    //Research r("Quantum Computing Research");

    //Employee e(18,85000);

    //TeachingAssistant ta("Vivek",25,269,"Quantum Computer","Quantum Computing Research","Computer Science",18,85000);
    //ta.Getdata();

    //SchoolStudent school("Vivek",18,10);
    //school.showschoolstudent();

    //CollegeStudent college("Vivek",18,"BCA");
    //college.showcollegestudent();

    //SportsStudent ss("Vivek",18,"BCA","Cricket");
    //ss.showsports();

    Child c1;
    c1.Getinfo();
    
    return 0;

}