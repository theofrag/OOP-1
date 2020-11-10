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
    if(this->students==NULL){      //if space is not allocated
        students= new Student*[this->capacity];}
    if(this->space==this->capacity)
        return;
    
     
    students[space]= &s;
    (this->space)++;
    cout<<s.getName()<< " enters schoolyard!"<<endl;

    s.setLocation("schoolYard");
}

Student& Schoolyard::exit(){
    Student* s;
    s=this->students[space-1];
    this->students[space-1]=NULL; 
    --(this->space);
    cout<<s->getName()<< " Exits Schoolyard!"<<endl;
    s->setLocation("exited_from_schoolYard");
    return *s;
    
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

Student& Stairs::exit(){
        
    Student* s;
    s=this->students[space-1];
    this->students[space-1]=NULL; 
    (this->space)--;

    cout<<s->getName()<< " Exit Stairs!"<<endl;
    s->setLocation("exited_from_stairs");
    return *s;
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


void Floor::enter(Student& s){
    Student* stud;
    if((this->corridor->get_available_space() )> 0 && s.get_location()== "exited_from_stairs"){
        cout<<s.getName()<<" enters Floor"<<endl;  
        this->corridor->enter(s);
        if(this->classrooms[s.get_class()]->get_available_space()>0 && this->classrooms[s.get_class()]->get_teacher_in()==false){
            stud=&(this->corridor->exit());
            this->classrooms[s.get_class()]->enter(*stud);
        }
    }
    return;
}

void Floor::place(Teacher& s){
    int floorId,classId;
    s.get_data(floorId,classId);
    this->classrooms[classId]->place(s);
}



void Floor::print(){
    this->corridor->print();
    for(int i=0;i<6;i++)
        this->classrooms[i]->print();
}

Floor::Floor(int Ccorr,int Cclass,int floorId){
    this->Ccorr=Ccorr;
    this->Cclass=Cclass;
    int k=0;
    for(int i=0;i<6;i++)
        this->classrooms[i]=new Classroom(this->Cclass,k++,i);
    
    this->corridor=new Corridor(Cclass);
    
}

Floor::~Floor(){

    cout<<"A floor to be destroyed"<<endl;

    for(int i=0;i<6;i++)
        delete  (this->classrooms[i]);
    delete this->corridor;
}

int Floor::get_available_space(){
    return this->corridor->get_available_space();
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

Student& Corridor::exit(){
    
    Student* s;
    s=this->students[space-1];
    this->students[space-1]=NULL; 
    (this->space)--;
    cout<<s->getName()<< " exits Corridor!"<<endl;
    s->setLocation("exited_corridor");
    return *s;
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
    this->Cclass=Cclass;        //capacities 
    this->Cyard=Cyard;
    this->Cstair=Cstairs;
    this->Ccorr=Ccorr;

    for(int i=0;i<3;i++)
        this->floors[i]=new Floor(Cstairs, Cclass,i);

    this->stairs=new Stairs(Cstairs);
    this->schoolyard=new Schoolyard(Cyard);
    cout<<"A new school has been created! "<<endl;
}

School::~School(){
    cout<<"A school to be destroyed"<<endl;

    for(int i=0;i<3;i++)
        delete this->floors[i];

    delete this->stairs;
    delete this->schoolyard;
}




void School::enter(Student& s){
    Student* stud;
    if((this->schoolyard->get_available_space())>0){
        cout<<s.getName()<<" enters school"<<endl;
        schoolyard->enter(s);
        if(this->stairs->get_available_space()>0){
            stud=&(this->schoolyard->exit());
            this->stairs->enter(*stud);
            if(this->floors[stud->get_floor()]->get_available_space()>0){
                stud=&(this->stairs->exit());
                this->floors[stud->get_floor()]->enter(*stud);
            }
            
        }

    }
}

void School::place(Teacher& t){
    int floorId, classId;
    t.get_data(floorId,classId);
    this->floors[floorId]->place(t);  
}
void School::print(){
    cout<<"School life consists of:  "<<endl;
    this->schoolyard->print();
    this->stairs->print();
    for(int i=0;i< 3;i++){
        cout<<"Floor number "<<i<<"  contains: "<<endl;
        this->floors[i]->print();  
    }
}

//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
