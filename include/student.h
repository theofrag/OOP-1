#include <cstring>
#include <iostream>

using namespace std;

class Student{

private:
    string name,location;
    int floorId , classroomId;

public:
    Student(string name,int floorId,int classroomId);
    void print(){cout<<name<<endl;}
    void setLocation(string location){
        this->location=location;   
    }
    string getName();
    void enter();
    string get_location();


};

class Teacher{

private: 
  string name;
  int floorId,classroomIds;
  bool inClassroom;

public:
    Teacher(string name,int floorId,int classroomId);
    void print(){cout<<"The Teacher is: "<<name<<endl;}
};

///----------------------------------------------------------------

class Classroom{

private:
    int capacity,space;

public:
    Student** students;
    Classroom();
    void set_capacity(int capacity){
        if(this->capacity !=-1)
            this->capacity=capacity;
    }
    void print();

};

//---------------------------------------------------------------
class Corridor{

private:
    int capacity,space;

public:
    Student** students;
    Corridor();
    void setCapacity(int);
    void set_capacity(int capacity){
        if(this->capacity !=-1)
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
    int id;
    Classroom classrooms[6];
    Corridor corridor;
public:
    Classroom get_classroom(int);
    Corridor get_corridor();
    void enter(Student& s);
    void print();

};

//-------------------------------------------------------------------------

class Schoolyard{

private:
    int capacity;   //capacity shows the maximum number od students,each yard can host
    int space;      //Space shows how many students are in the yard. Space is increasing

public:
    Student** students;
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

public:
    Student** students;
    Stairs();
    void setCapacity(int);
    void set_capacity(int capacity){
        if(this->capacity !=-1)
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
    Floor floors[3];
    Schoolyard schoolyard;
    Stairs stairs;
    
public:
    School(int,int,int,int);
    void enter(Student& s);
    Classroom get_floor(int i);
    Schoolyard get_schoolyard();
    void print();

};












//---------------------------------------------------