#include "student.h"

class Classroom{

private:
    int floorId,classId;
    int capacity,space;
    Student** students;
    bool teacherIn;

public:
    void set_ids(int floorId,int classId){
        this->floorId=floorId;
        this->classId=classId;
    }
    Classroom();
    void set_capacity(int capacity){
        if(this->capacity ==-1)
            this->capacity=capacity;
    }

    void get_ids(int& floorId,int& classId){
        floorId = this->floorId;
        classId = this->classId;
    }
    void enter(Student& );
    void print();

};

//---------------------------------------------------------------
class Corridor{

private:
    int capacity,space;
    Student** students;

public:
    Corridor();
    void set_capacity(int capacity){
        // if(this->capacity ==-1)
            this->capacity=capacity;

    }
    void print();
    void enter(Student &s);
    Student& exit(Student &s);
    int get_capacity();

};
//----------------------------------------------------------------

class Floor{

private:
    Classroom classrooms[6];
    Corridor corridor;
    int floorId;
public:
    Floor();
    void set_id(int floorId){
        this->floorId = floorId;
    }
    Classroom& get_classroom(int);
    Corridor& get_corridor();
    void enter(Student& s);
    void print();

};

//-------------------------------------------------------------------------

class Schoolyard{

private:
    int capacity;   //capacity shows the maximum number of students,each yard can host
    int space;      //Space shows how many students are in the yard. Space is increasing
    Student** students;

public:
    Schoolyard();
    void setCapacity(int);
    void set_capacity(int capacity){
        if(this->capacity ==-1)
            this->capacity=capacity;
    }
    void enter(Student& s);
    Student& exit(Student &s);
    int get_capacity();
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