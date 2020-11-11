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

struct Couples{
         Student* s[2];      //array to store 2 students
};

class Sequence{

private:
    float Tquiet;
    float Tmessy;
    int couplesNumber;
    int id;
    Sequence* next;
    Couples* couples;
    int counterBoy;
    int CounterGirl;
    int tempBoy;
    int tempGirl;
    int naughtyCounter;
    void add_student(Student& s);
    void restoreQuitness();
    

public:
    Sequence(Student** students,int number,float Tquiet=0,float Tmessy=0);
    void connect(Sequence& sequence);
    void restore();
    void printSequence();
    void print();   

};



