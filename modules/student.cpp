#include "infrastructures.h"



Student::Student(string name,int floorId,int classroomId){
    this->name = name;
    this->floorId=floorId;
    this->classroomId=classroomId;
    this->location = "NULL"; 
    cout<<"A New Student has been created"<<endl;

    cout<<" Name: "<<this->name
    <<" "<<"floorId: "<<this->floorId
    <<" "<<"classrooomId: "<<this->classroomId<<endl;
}

string Student :: getName(){
        return this->name;
    }

string Student::get_location(){
    return this->location;
}

int Student::get_class(){
    return this->classroomId;
    
}

int Student::get_floor(){
    return this->floorId;
}

//--------------------------------------------

