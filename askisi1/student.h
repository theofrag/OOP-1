#include <cstring>
#include <iostream>

using namespace std;

class Student{

private:
    string name,location;   //name of student and his location
    int floorId , classroomId;  //classroom
        

public:
    Student(string name,int floorId,int classroomId);   //constructor
    ~Student();
    void print(){cout<<name<<endl;} //a simple print function
    void setLocation(string location){  //set the location of the student
    
        if(location !="NULL" && location != "schoolYard" && location != "exited_from_schoolYard" && location != "Stairs" &&
        location != "exited_from_stairs" &&  location != "Corridor" && location != "exited_corridor" && location != "Classroom" ){
            cout<<"INVALID LOCATION OF STUDENT   "<<this->name<<endl;
            return;
        }
        this->location=location;   
    }
    string getName();   //function to get the name of a student
    string get_location();  //get the location of the student
    int get_class();   //get his class number
    int get_floor();    //get the floor ,where the class belongs


};

class Teacher{

private: 
  string name;      //teacher's name
  int floorId,classId;  //his class
  bool inClassroom; //if he is in the class

public:
    Teacher(string name,int floorId,int classId);   //constructor
    ~Teacher();
    void set_inClassroom(bool b){   //set if the teacher is at the classroom
        this->inClassroom=b;
    }
    void print(){cout<<"The Teacher is: "<<name<<endl;}     //a simple print method
    void get_data(int& floorId,int& classId){
        floorId=this->floorId;
        classId=this->classId; 
    }
    bool in_classroom();
    string get_name();
};

