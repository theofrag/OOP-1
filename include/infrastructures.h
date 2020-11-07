#include "student.h"

class Classroom{

private:
    int floorId,classId;  //classroom data     
    int capacity,space;     //capacity is the max number of students and space show how many students are in the classroom
    Student** students;     //pointer to an array of pointers, that point to  student classes
    bool teacherIn;         //if teacher is in class
    Teacher* teacher;

public:
    Classroom();        //constructor
    void set_ids(int floorId,int classId){      //set data
        this->floorId=floorId;
        this->classId=classId;
    }
    void set_capacity(int capacity){    //PRACTICALLY THE USER CANNOT USE THIS FUNCTION
        if(this->capacity ==-1)
            this->capacity=capacity;
    }

    void get_ids(int& floorId,int& classId){    //Get data
        floorId = this->floorId;
        classId = this->classId;
    }

    void enter(Student& );  //host a student in the classroom
    void place(Teacher& );  //place a teacher to the classroom
    void print();
    int get_available_space();     //get capacity shows how much space lefts;  

};

//---------------------------------------------------------------
class Corridor{ 

private:
    int capacity,space;     //data
    Student** students;     //array of students

public:
    Corridor();     //constructor
    void set_capacity(int capacity){    
        if(this->capacity ==-1)
            this->capacity=capacity;

    }
    void print();
    void enter(Student &s);
    Student& exit(Student &s);      //expell a student from the corridor
    int get_available_space();     //how muck space lefts

};
//----------------------------------------------------------------

class Floor{

private:
    Classroom classrooms[6];    //array of classrooms
    Corridor corridor;  //the corridor of the floor
    int floorId;        //
public:
    Floor();         //   constructor
    void set_id(int floorId){   //set the number of floor
        this->floorId = floorId;
    }
    Classroom& get_classroom(int);      //take data of the classroom
    Corridor& get_corridor();   //<<              >>
    void enter(Student& s);
    void print();

};

//-------------------------------------------------------------------------

class Schoolyard{

private:
    int capacity;   //capacity shows the maximum number of students,each yard can host
    int space;      //Space shows how many students are in the yard. Space is increasing
    Student** students;     //array of students

public:
    Schoolyard();   //constructor
    void set_capacity(int capacity){
        if(this->capacity ==-1)
            this->capacity=capacity;
    }
    void enter(Student& s);
    Student& exit(Student &s);
    int get_available_space(); //how much space is available in the yard
    void print();
};
//---------------------------------------------
class Stairs{

private:
    int capacity,space;
    Student** students;

public:
    Stairs();
    void set_capacity(int capacity){
        if(this->capacity ==-1)
            this->capacity=capacity;
    }
    void enter(Student &s);
    Student& exit(Student &s);
    void print();
};


//----------------------------------------------

class School{

private:
    int Cclass,Cyard,Cstair,Ccorr;
    Schoolyard schoolyard;
    Floor floors[3];
    Stairs stairs;
    
public:
    School(int,int,int,int);
    void enter(Student& s);
    Floor& get_floor(int i);
    Schoolyard& get_schoolyard();
    Stairs& get_stairs();
    void print();

};