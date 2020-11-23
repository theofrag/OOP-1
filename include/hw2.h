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
    ~Student(); 
    string studentName();       //return student's name
    string studentGender();     //return student gender
    int classroomId();          //return student's class
    void make_naughty(bool b){        //make a student naughty
        this->naughty=b;
    }
    bool is_naughty(){          //if student is naughty return true ,else false
        return this->naughty;
    }

    void print_name() const{
        cout<<this->name<<endl;
    }

    void print_class() const{
        cout<<this->classId<<endl;
    }

    void print_gender() const{
        cout<<this->gender<<endl;
    }

    void print_student() const {
        cout<<"Student with name: "<<this->name<<" class:"<<this->classId<<" and gender: "<<this->gender<<endl;
    }         
};

struct Couples{
         Student* s[2];      //array of pointers to store 2 students
};

class Sequence{

private:
    float Tquiet;
    float Tmessy;
    int couplesNumber;  //how many couples are in the sequence
    int id;             //sequence id
    Sequence* next;     //pointer to sequence. Usefull to connect sequences
    Couples* couples;   //pointer to struct couples
    int counterBoy;     //how many boys are in the sequence
    int CounterGirl;    //how many girls are in the sequence
    int tempBoy;        // 0 or 1 that decides the position of the boy
    int tempGirl;       //0 or 1 that decides the position of the girl
    int naughtyCounter;     //measures naughty
    void add_student(Student& s);   //private function ,which adds a student in the sequence
    void restoreQuitness();         //private function ,which is called by public restore function
    void increase_counter(Student& s, int number);
    

public:
    Sequence(Student** students,int number,float Tquiet=0,float Tmessy=0);      //constructor
    ~Sequence();
    void connect(Sequence& sequence);       //connect sequences
    void restore();             //swap naughty kids. This function calls restoreQuitness() private function
    void printSequence();       //print only this sequence
    void print();           //print this sequence and the sequences that are connected with this sequence

};



