#include "infrastructures.h"


Classroom::Classroom(int Cclass,int floorId,int classId){         //classroom constuctor
    this->floorId=floorId;
    this->classId=classId;
    this->capacity=Cclass;
    this->space=0;              //no one is inside
    this->teacherIn=false;      //no teacher in the classroom
    this->students=NULL;        //no students in the classroom
    this->teacher=NULL;
    
    cout<<"A new classroom has been created! "<<endl;
}

Classroom::~Classroom(){        //free memory
    cout<<"Classroom to be destroyed"<<endl;
    delete [] students;
}


void Classroom::print(){

    cout<<"People in class "<<this->floorId<<"."<<this->classId<<" are: "<<endl;


    for(int i=0;i<this->space;i++)  //print students
        cout<<students[i]->getName()<<endl;
    if(this->teacherIn==true)   //print teacher
        cout<<"The teacher is: "<<this->teacher->get_name()<<endl;
}

void Classroom::enter(Student& s){

    if(this->students==NULL)    //if there is no allocated space already
        students= new Student*[this->capacity];

    if(this->space==this->capacity || this->teacherIn==true || s.get_location()!="exited_corridor")
        return;
    
    students[space]=&s;
    this->space++;
    cout<<s.getName()<< " enters Classroom!"<<endl;
  
    s.setLocation("Classroom");     //update student location
}

void Classroom::place(Teacher& t){
    this->teacher=&t;
    this->teacherIn=true;
    t.set_inClassroom(true);
    
    
}

int Classroom::get_available_space(){
    return this->capacity-this->space;
}

bool Classroom::get_teacher_in(){       //if teacher is in the classroom or not
    return this->teacherIn;
}

//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------

Schoolyard::Schoolyard(int Cyard){
    this->capacity=Cyard;      //initialize values
    this->space=0;
    this->students=NULL;
    cout<<"A new Schoolyard has been created! "<<endl;
}

Schoolyard::~Schoolyard(){
    cout<<"A schoolyard to be destroyed..."<<endl;
    delete [] students;
}

void Schoolyard::enter(Student& s){
    if(this->students==NULL){       //if space is not allocated
        students= new Student*[this->capacity];}
    if(this->space==this->capacity)
        return;
    
     
    students[space]= &s;
    (this->space)++;
    cout<<s.getName()<< " enters schoolyard!"<<endl;

    s.setLocation("schoolYard");
}

Student& Schoolyard::exit(Student& s){
    
    for(int i=0;i<(this->space);i++){       //find student
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
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
Stairs::Stairs(int Cstairs){
    this->capacity=Cstairs;
    this->space=0;
    this->students=NULL;
    cout<<"A new Stairs has been created! "<<endl;
}

Stairs::~Stairs(){
    cout<<"Stairs to be destroyed"<<endl;
    delete [] students;
}

void Stairs::enter(Student& s){
    if(this->students==NULL){       //if no space is allocated
        students= new Student*[this->capacity];}
    if(this->space==this->capacity)
        return ;
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

int Stairs::get_available_space(){
    return this->capacity-this->space;
}
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//-----------------------------------------------------
Classroom& Floor::get_classroom(int i){
    return *(this->classrooms[i]);
}

void Floor::enter(Student& s){
    if((this->corridor->get_available_space() )> 0 && s.get_location()== "exited_from_stairs"){
        cout<<s.getName()<<" enters Floor"<<endl;  
        this->corridor->enter(s);
    }
    return;
}

Corridor& Floor::get_corridor(){
    return *(this->corridor);
}


void Floor::print(){
    this->corridor->print();
}

Floor::Floor(int Ccorr,int Cclass,int floorId){
    this->Ccorr=Ccorr;
    this->Cclass=Cclass;
    this->corridor=new Corridor(Cclass);
    
    int k=0;
    for(int i=0;i<6;i++)
        this->classrooms[i]=new Classroom(this->Cclass,k++,i);
    
}

Floor::~Floor(){

    cout<<"A floor to be destroyed"<<endl;

    for(int i=0;i<6;i++)
        delete  (this->classrooms[i]);
    delete this->corridor;
}

//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//------------------------------------------------
Corridor::Corridor(int Ccorr){
    this->capacity=Ccorr;
    this->space=0;
    this->students=NULL;
    cout<<"A new Corridor has been created! "<<endl;
}

Corridor::~Corridor(){
    cout<<"Corridor to be destroyed"<<endl;
    delete [] students;
}

int Corridor::get_available_space(){
    return this->capacity-this->space;
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
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//------------------------------------------------

School ::School(int Cclass,int Cyard,int Cstairs, int Ccorr){   //school constuctor
    cout<<"A new school has been created! "<<endl;
    this->Cclass=Cclass;        //capacities 
    this->Cyard=Cyard;
    this->Cstair=Cstairs;
    this->Ccorr=Ccorr;

    for(int i=0;i<3;i++)
        this->floors[i]=new Floor(Cstairs, Cclass,i);

    this->schoolyard=new Schoolyard(Cyard);
    this->stairs=new Stairs(Cstairs);
}

School::~School(){
    cout<<"A school to be destroyed"<<endl;

    for(int i=0;i<3;i++)
        delete this->floors[i];

    delete this->stairs;
    delete this->schoolyard;
}

Schoolyard& School::get_schoolyard(){
    return *(this->schoolyard);
}
Stairs& School::get_stairs(){
    return *(this->stairs);
}


void School::enter(Student& s){
    if((this->schoolyard->get_available_space())!=0){
        cout<<s.getName()<<" enters school"<<endl;
        schoolyard->enter(s);

    }
}
void School::print(){
    cout<<"School life consists of:  "<<endl;
    this->schoolyard->print();
    this->stairs->print();
    for(int i=0;i< 3;i++){
        cout<<"Floor number "<<i<<"  contains: "<<endl;
        get_floor(i).print();
        for(int j=0;j<6;j++)
            get_floor(i).get_classroom(j).print();
            
        
    }
}

Floor& School::get_floor(int i){
    return *(this->floors[i]);

}

//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
