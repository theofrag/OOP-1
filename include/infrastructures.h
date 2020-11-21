#include "student.h"

class Classroom{

private:
    int floorId,classId;    //classroom data     
    int capacity,space;     //capacity is the max number of students and space show how many students are in the classroom
    Student** students;     //pointer to an array of pointers, which points to  student classes
    bool teacherIn;         //if teacher is in class bool== true
    Teacher* teacher;       // Pointer to a teacher

public:
    Classroom(int Cclass,int floorId,int classId);
    ~Classroom();
    bool get_teacher_in() const;          //if teacher is in the classroom
    int get_available_space() const;     //get capacity shows how much space lefts;  
    void enter(Student& );          //host a student in the classroom
    void place(Teacher& teacher){
        this->teacher=&teacher;
        this->teacherIn=true;
    }
    
    void print() const;                   //print teacher and students
};
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------

class Corridor{ 

private:
    int capacity,space;     //data
    Student** students;     //array of students

public:
    // Corridor();     //constructor
    Corridor(int Ccorr);
    ~Corridor();
    int get_available_space() const;      //how much space lefts
    void enter(Student &s);         //enter a student in the corridor
    Student& exit();      //expell a student from the corridor
    void print() const;
};
//----------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------

class Floor{

private:
    int Ccorr,Cclass;              //holds information about the capacity of the corridor and the capacity of classes
    Classroom* classrooms[6];       //each floor, forms from 6 classes
    Corridor* corridor;          //the corridor of the floor
    int floorId;                //floor number(=0,1,2)
public:
    void place(Teacher& teacher);
    Floor(int Ccorr,int Cclass,int floorId);
    ~Floor();
    void enter(Student& s);
    void print() const ;
    int get_available_space() const;      //how much space lefts
};

//-------------------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------

class Schoolyard{

private:
    int capacity;   //capacity shows the maximum number of students,each yard can host
    int space;      //Space shows how many students are in the yard. Space is increasing
    Student** students;     //array of students

public:
    Schoolyard(int Cstairs);   //constructor
    ~Schoolyard();
    int get_available_space() const; //how much space is available in the yard
    void enter(Student& s);
    Student& exit();
    void print() const;
};
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------
class Stairs{

private:
    int capacity,space;
    Student** students;

public:
    Stairs(int Cstairs);
    ~Stairs();
    void enter(Student &s);
    Student& exit();
    int get_available_space() const;
    void print() const;
};

//----------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
class School{

private:
    int Cclass,Cyard,Cstair,Ccorr;  //χωρητικότητες καθε χωρου
    Schoolyard* schoolyard;         //δεικτης σε προαυλιο
    Floor* floors[3];               //πίνακας 3 δεικτών σε ορόφους
    Stairs* stairs;                 //δείκτης σε σκάλες
    
public:
    School(int,int,int,int);        //constructor
    ~School();                      //destrucot
    void enter(Student& s);         //βάζει έναν μαθητή στο σχολείο
    void enter(Student** array, int length);    //παίρνει έναν πίνακα μαθητών και τον βάζει στο σχολείο
    void place(Teacher& );          //place a teacher to the classroom
    void print() const;             //

};
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
