#include <iostream>
#include <cstring>

using namespace std;


//--------------------------------------------------------------

class Student{

private:
    string name;        //student name
    int classId;        //student class
    string gender;      //student gender
    bool naughty;       

public:
    Student(string name,string gender,int classId);     //constructor
    string studentName();       //return student's name
    string studentGender();     //return student gender
    int classroomId();          //return student's class
    void make_naughty(bool b){        //make a student naughty
        this->naughty=b;
    }
    bool is_naughty(){          //if student is naughty or not
        return this->naughty;
    }
    // ~Student();              

};
//--------------------------------------------------------------

struct Couples{

private:
    Student* s[2];      //array to store 2 students
    
public:
    void set_student(Student& s, int pos){      //set students, pos must be either 0 or 1
        this->s[pos]=&s;
    }

    Student& get_student(int pos);              //get student from the position given(0 or 1)
};
//--------------------------------------------------------------

class Classroom{

private:
    int naughtyCounter;         //counter 
    Student** students;         //array to store students
    int Cclass;                 //classroom capacity
    int id;                     //classroom id
    Couples* couples;           //array from couples
    Classroom* pointer; //point to an other classroom, usefull for sequences        //connections with the classroom
    int space;                  //how many students are in the class

public:
    Classroom(int Cclass);      //constructor
    // ~Classroom();
    void buildSequences();  //Build sequences among students
    void connect(Classroom& classroom); //Connect classrooms
    void restoreQuietness();    //restore quietness
    void printSequences();      //print sequences
    void place(Student& s);     //place students to their classroom


};
//--------------------------------------------------------------

