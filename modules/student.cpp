#include "infrastructures.h"



Student::Student(string name,int floorId,int classroomId){
    this->name = name;      //Student name
    this->floorId=floorId;  //In which floor, his classroom belongs
    this->classroomId=classroomId;  //Wich number is his class
    this->location = "NULL";        //outside of the school
    cout<<"A New Student has been created"<<endl;

    cout<<" Name: "<<this->name     //print name and classroom
        <<" "<<"floorId: "<<this->floorId
        <<" "<<"classrooomId: "<<this->classroomId<<endl;
}

Student::~Student(){
    cout<<"A student to be destroyed whith name: "<<this->name<<" classroom: "
        <<this->floorId <<"."<<this->classroomId<<" and location: "<<this->location<<endl;
}


string Student :: getName(){        //get student name
        return this->name;
    }

string Student::get_location(){     //get student current location
    return this->location;
}

int Student::get_class(){           //get student class number
    return this->classroomId;
    
}

int Student::get_floor(){           //in which floor student's classroom belongs    
    return this->floorId;
}

//--------------------------------------------

Teacher::Teacher(string name,int floorId,int classId){      //constructor
    this->inClassroom=false;    
    this->floorId=floorId;
    this->classId=classId;
    this->name=name;
    cout<<"A New Teacher has been created!"<<endl;
    
    cout<<" Name: "<<this->name     //print name and classroom
        <<" "<<"floorId: "<<this->floorId
        <<" "<<"classrooomId: "<<this->classId<<endl;
}

Teacher:: ~Teacher(){

    cout<<"A teacher to be destroyed whith name: "<<this->name<<" classroom: "
        <<this->floorId <<"."<<this->classId<<endl;
}

bool Teacher::in_classroom(){
    return this->inClassroom;
}

string Teacher::get_name(){
    return this->name;
}