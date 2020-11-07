#include "infrastructures.h"


Classroom::Classroom(){         //classroom constuctor
    this->floorId=0;            //initialize with zero
    this->classId=0;
    this->capacity=-1;
    this->space=0;              //no one is inside
    this->teacherIn=false;      //no teacher in the classroom
    this->students=NULL;        //no students in the classroom
    this->teacher=NULL;
    cout<<"A new classroom has been created! "<<endl;
}

void Classroom::print(){

    int floorId,classId;
    this->get_ids(floorId,classId);
    cout<<"People in class "<<floorId<<"."<<classId<<" are: "<<endl;


    for(int i=0;i<this->space;i++)
        cout<<students[i]->getName()<<endl;
}

void Classroom::enter(Student& s){

    
    if(this->students==NULL)
        students= new Student*[this->capacity];
    if(this->space==this->capacity || this->teacherIn==true || s.get_location()!="exited_corridor")
        return;
    
    students[space]=&s;
    this->space++;
    cout<<s.getName()<< " enters Classroom!"<<endl;
  
    s.setLocation("Classroom");
}

void Classroom::place(Teacher& t){
    this->teacher=&t;
    this->teacherIn=true;
    t.set_inClassroom(true);
    
}

int Classroom::get_available_space(){
    return this->capacity-this->space;
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

    s.setLocation("schoolYard");
}

Student& Schoolyard::exit(Student& s){
    for(int i=0;i<(this->space);i++){
        if((*(students[i])).getName()== s.getName()){
            students[i]=students[space-1];
            this->space--;

            break;
        }
    }
    cout<<s.getName()<< " Exits Schoolyard!"<<endl;
    s.setLocation("exited_from_schoolYard");
    return s;
}

int Schoolyard::get_available_space(){

    return this->capacity-this->space;
}

void Schoolyard::print(){
    cout<<"People in schoolyard are:  "<<endl;
    for(int i=0;i<this->space;i++){
        if(students!=NULL)
            cout<<students[i]->getName()<<endl;
    }

}
//---------------------------------------------------------------
Stairs::Stairs(){
    this->capacity=-1;
    this->space=0;
    this->students=NULL;
    cout<<"A new Stairs has been created! "<<endl;
}

void Stairs::enter(Student& s){
    if(this->students==NULL){
        students= new Student*[this->capacity];}
    if(this->space==this->capacity){
        return ;}
    if(s.get_location()!= "exited_from_schoolYard")
        return;
        
    students[this->space]= &s;
  
    (this->space)++;
    cout<<s.getName()<< " enters Stairs!"<<endl;
    s.setLocation("Stairs");
}

Student& Stairs::exit(Student& s){
    
    for(int i=0; i<this->space; i++){
        if((*(students[i])).getName()== s.getName()){
            students[i]=students[space-1];
            this->space--;
            break;
        }
    }
    cout<<s.getName()<< " Exit Stairs!"<<endl;
    s.setLocation("exited_from_stairs");
    return s;
}

void Stairs::print(){
    cout<<"People ins stairs are: "<<endl;
    for(int i=0;i< (this->space);i++)
        cout<<students[i]->getName()<<endl;
}
//-----------------------------------------------------
Classroom& Floor::get_classroom(int i){
    return classrooms[i];
}

void Floor::enter(Student& s){
    if((this->corridor.get_available_space() )!= 0 && s.get_location()== "exited_from_stairs"){
        cout<<s.getName()<<" enters Floor"<<endl;  
        this->corridor.enter(s);
    }
    return;
}

Corridor& Floor::get_corridor(){
    return this->corridor;
}


void Floor::print(){
    this->corridor.print();
}

Floor::Floor(){

    // for(int i=0;i<6;i++)
    //     this->classrooms[i].set_ids(2,i);
}

//------------------------------------------------
Corridor::Corridor(){
    this->capacity=-1;
    this->space=0;
    this->students=NULL;
    cout<<"A new Corridor has been created! "<<endl;
}

int Corridor::get_available_space(){
    return this->capacity;
}

void Corridor::enter(Student& s){
    if(this->students==NULL){
        students= new Student*[this->capacity];}
    if(this->space==this->capacity)
        return ;
    students[this->space]= &s;
    if(s.get_location()!= "exited_from_stairs")
        return;
  
    (this->space)++;
    cout<<s.getName()<< " enters Corridor!"<<endl;
    s.setLocation("Corridor");
}

Student& Corridor::exit(Student& s){
    
    for(int i=0;i<this->space;i++){
        if((*(students[i])).getName()== s.getName()){
            students[i]=students[space-1]; 
            this->space--;
            break;
        }
    }
    cout<<s.getName()<< " exits Corridor!"<<endl;
    s.setLocation("exited_corridor");
    return s;
}

void Corridor::print(){
    cout<<"People in corridor are: "<<endl;
    for(int i=0; i<this->space;i++)
        cout<<students[i]->getName()<<endl;
}
//------------------------------------------------

School ::School(int Cclass,int Cyard,int Cstairs, int Ccorr){   //school constuctor
    cout<<"A new school has been created! "<<endl;
    this->Cclass=Cclass;        //capacities 
    this->Cyard=Cyard;
    this->Cstair=Cstairs;
    this->Ccorr=Ccorr;
    
    for(int i=0;i<3;i++){   //set capacity of corridors,id of floors, id of classrooms,capacity of classrooms
        this->floors[i].get_corridor().set_capacity(this->Ccorr);
        floors[i].set_id(i);
        for(int j=0;j<6;j++){
            floors[i].get_classroom(j).set_ids(i,j);
            this->floors[i].get_classroom(j).set_capacity(this->Cclass);}
    
    }
    
    this->schoolyard.set_capacity(this->Cyard);
    this->stairs.set_capacity(this->Cstair);
}

Schoolyard& School::get_schoolyard(){
    return this->schoolyard;
}
Stairs& School::get_stairs(){
    return this->stairs;
}


void School::enter(Student& s){
    if((this->schoolyard.get_available_space())!=0){
        cout<<s.getName()<<" enters school"<<endl;
        schoolyard.enter(s);

    }
}
void School::print(){
    cout<<"School life consists of:  "<<endl;
    this->schoolyard.print();
    this->stairs.print();
    for(int i=0;i< 3;i++){
        cout<<"Floor number "<<i<<"  contains: "<<endl;
        get_floor(i).print();
        for(int j=0;j<6;j++)
            get_floor(i).get_classroom(j).print();
        
    }
}

Floor& School::get_floor(int i){
    return this->floors[i];

}

