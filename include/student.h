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
    int get_class();
    int get_floor();


};

class Teacher{

private: 
  string name;
  int floorId,classroomIds;
  bool inClassroom;

public:
    void place();
    Teacher(string name,int floorId,int classroomId);
    void print(){cout<<"The Teacher is: "<<name<<endl;}
};

