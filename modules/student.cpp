#include "student.h"



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


//---------------------------------------------

Classroom::Classroom(){
    this->capacity=-1;
    this->space=0;
    cout<<"A new classroom has been created! "<<endl;
}

void Classroom::print(){
    for(int i=this->capacity-1;i>=0;i--)
        cout<<students[i]->getName()<<endl;
}


//------------------------------------------------
Schoolyard::Schoolyard(){
    this->capacity=-1;
    this->space=0;
    this->students=NULL;
    cout<<"A new Schoolyard has been created! "<<endl;
}

void Schoolyard::enter(Student& s){
    if(this->students==NULL){
        students= new Student*[this->capacity];}
    if(this->space==this->capacity)
        return;

    students[space]= &s;
    (this->space)++;
    cout<<s.getName()<< " enters schoolyard!"<<endl;
    s.setLocation("schoolYars");
}

// Student& Schoolyard::exit(){
    
//     Student* temp= students[space];
//     students[space]=students[this->capacity-1];
//     students[this->capacity-1]=NULL;
//     this->space--;
//     cout<< temp->getName() << " exit schoolyard!"<<endl;
//     temp->setLocation("NULL");
//     return *temp;
// }

Student& Schoolyard::exit(Student& s){
    Student* temp;
    for(int i=0;i<this->space;i++){
        if((*(students[i])).getName()== s.getName()){
            temp=  students[i];
            students[i]=students[space];
            students[space]=NULL;

            this->space--;
            break;
        }
    }
    cout<<s.getName()<< " enters Corridor!"<<endl;
    temp->setLocation("NULL");
    return *temp;
}

int Schoolyard::get_capacity(){
    return this->capacity-this->space;
}

void Schoolyard::print(){
    cout<<"People in schoolyard are:  "<<endl;
    for(int i=0;i<=this->space;i++){
        if(students!=NULL)
            cout<<students[i]->getName()<<endl;
    }

}
//------------------------------------------------
Corridor::Corridor(){
    this->capacity=-1;
    this->space=0;
    this->students=NULL;
    cout<<"A new Corridor has been created! "<<endl;
}

int Corridor::get_capacity(){
    return this->capacity;
}

void Corridor::enter(Student& s){
    if(this->students==NULL){
        students= new Student*[this->capacity];}
    if(this->space==this->capacity)
        return ;
    students[this->space]= &s;
  
    (this->space)++;
    cout<<s.getName()<< " enters Corridor!"<<endl;
    s.setLocation("Corridor");
}

Student& Corridor::exit(Student& s){
    Student* temp;
    for(int i=0;i<this->space;i++){
        if((*(students[i])).getName()== s.getName()){
            temp=  students[i];
            students[i]=students[space];
            students[space]=NULL;

            this->space--;
            break;
        }
    }
    cout<<s.getName()<< " enters Corridor!"<<endl;
    temp->setLocation("NULL");
    return *temp;
}

void Corridor::print(){
    cout<<"People in corridor are: "<<endl;
    for(int i=this->capacity-1;i>=0;i--)
        cout<<students[i]->getName()<<endl;
}
//------------------------------------------------
Stairs::Stairs(){
    this->capacity=-1;
    this->space=0;
    this->students=NULL;
    cout<<"A new Stairs has been created! "<<endl;
}

void Stairs::enter(Student& s){
    if(this->students==NULL){
        students= new Student*[this->capacity];}
    if(this->space==this->capacity)
        return ;
    students[this->space]= &s;
  
    (this->space)++;
    cout<<s.getName()<< " enters Stairs!"<<endl;
    s.setLocation("Stairs");
}

Student& Stairs::exit(Student& s){
    Student* temp;
    for(int i=0;i<=this->space;i++){
        if((*(students[i])).getName()== s.getName()){
            temp=  students[i];
            students[i]=students[space];
            students[space]=NULL;
            this->space--;
            break;
        }
    }
    cout<<s.getName()<< " enters Stairs!"<<endl;
    temp->setLocation("NULL");
    return *temp;
}

void Stairs::print(){
    cout<<"People ins stairs are: "<<endl;
    for(int i=this->capacity-1;i>=0;i--)
        cout<<students[i]->getName()<<endl;
}









//------------------------------------------------

School ::School(int Cclass,int Cyard,int Cstairs, int Ccorr){
    cout<<"A new school has been created! "<<endl;
    this->Cclass=Cclass;
    this->Cyard=Cyard;
    this->Cstair=Cstairs;
    this->Ccorr=Ccorr;
    
    for(int i=0;i<3;i++){
        this->floors[i].get_corridor().set_capacity(this->Ccorr);
        for(int j=0;j<6;j++)
            this->floors[i].get_classroom(j).set_capacity(this->Cclass);
        

    
    }
    
    this->schoolyard.set_capacity(this->Cyard);
    this->stairs.set_capacity(this->Cstair);
}

Schoolyard School::get_schoolyard(){
    return this->schoolyard;
}

void School::enter(Student& s){
    cout<<s.getName()<<" enters school"<<endl;
    if((this->schoolyard.get_capacity())!=0){
        schoolyard.enter(s);

    }
}
void School::print(){
    cout<<"School life consists of:  "<<endl;
    this->schoolyard.print();
    this->stairs.print();
    for(int i=0;i<3;i++){
        cout<<"Floor number "<<i<<"contains: "<<endl;
        
    }


}





//-----------------------------------------------------
Classroom Floor::get_classroom(int i){
    return classrooms[i];
}

void Floor::enter(Student& s){
    cout<<s.getName()<<" enters school"<<endl;
    if((this->corridor.get_capacity() )!= 0)
        this->corridor.enter(s);

}

Corridor Floor::get_corridor(){
    return this->corridor;
}

void Floor::print(){
    this->corridor.print();
}

//------------------------------------------------
