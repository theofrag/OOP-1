#include "infrastructures.h"


Classroom::Classroom(int Cclass,int floorId,int classId){         //classroom constuctor
    this->floorId=floorId;      //represents the floot(from 0-2)
    this->classId=classId;      //repressents the number of the class (from 0-5)
    this->capacity=Cclass;
    this->space=0;              //no one is inside
    this->teacherIn=false;      //no teacher in the classroom
    this->students=NULL;        //no students in the classroom
    this->teacher=NULL;
    
    cout<<"A new classroom has been created! "<<endl;
}

Classroom::~Classroom(){        //free memory
    cout<<"Classroom to be destroyed"<<endl;
    delete [] students;         //delete students array, NOT STUDENTS
}


void Classroom::print() const{

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
    
    s.setLocation("Classroom");   //update student location
}



int Classroom::get_available_space() const{
    return this->capacity-this->space;
}

bool Classroom::get_teacher_in() const{       //if teacher is in the classroom or not
    return this->teacherIn;
}

//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------

Schoolyard::Schoolyard(int Cyard){
    this->capacity=Cyard;      //initialize values
    this->space=0;              //no one is in the schoolyard at first, so space is zero
    this->students=NULL;
    cout<<"A new Schoolyard has been created! "<<endl;
}

Schoolyard::~Schoolyard(){
    cout<<"A schoolyard to be destroyed..."<<endl;
    delete [] students;
}

void Schoolyard::enter(Student& s){
    if(this->students==NULL){      //if space is not allocated, create the array that holds students depending on the capacity
        students= new Student*[this->capacity];}
    if(this->space==this->capacity)     //if there is not available space
        return;
    
     
    students[space]= &s;    //add student at the end
    (this->space)++;        //increase the counter, that holds information about the current number of students on the yard
    cout<<s.getName()<< " enters schoolyard!"<<endl;

    s.setLocation("schoolYard");        //set the location of the student, to be "Schoolyard"
}

Student& Schoolyard::exit(){
    Student* s;
    s=this->students[space-1];      //take the last student from the array
    this->students[space-1]=NULL;   //now the array points to nothing
    --(this->space);                //decrease space counter
    cout<<s->getName()<< " Exits Schoolyard!"<<endl;
    s->setLocation("exited_from_schoolYard");       //This is a temp location. Stairs can add ONLY students which have exited from yard
    return *s;
    
}

int Schoolyard::get_available_space() const{      

    return this->capacity-this->space;  //if the function return 0, then there is no available space
}

void Schoolyard::print() const{
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
    if(s.get_location()!= "exited_from_schoolYard") //A student can go on stairs,only if he was at the yard previously
        return;
        
    students[this->space]= &s;
  
    (this->space)++;
    cout<<s.getName()<< " enters Stairs!"<<endl;
    s.setLocation("Stairs");
}

Student& Stairs::exit(){
        
    Student* s;
    s=this->students[space-1];  //take the last student
    this->students[space-1]=NULL; 
    (this->space)--;

    cout<<s->getName()<< " Exit Stairs!"<<endl;
    s->setLocation("exited_from_stairs");
    return *s;
}

void Stairs::print() const{
    cout<<"People ins stairs are: "<<endl;
    for(int i=0;i< (this->space);i++)
        cout<<students[i]->getName()<<endl;
}

int Stairs::get_available_space() const{
    return this->capacity-this->space;
}
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//-----------------------------------------------------


void Floor::enter(Student& s){

    if((this->corridor->get_available_space() )> 0 && s.get_location()== "exited_from_stairs"){ //a student can enter in the floor, if
        cout<<s.getName()<<" enters Floor"<<endl;                                                         //he was in stairs previously
        this->corridor->enter(s);
        if(this->classrooms[s.get_class()]->get_available_space()>0 && this->classrooms[s.get_class()]->get_teacher_in()==false){   //add only if there is available space, and no teacher is in classroom
            Student& stud=(this->corridor->exit());
            this->classrooms[s.get_class()]->enter(stud);
        }
    }
    return;
}

void Floor::place(Teacher& s){
    int floorId,classId;
    s.get_data(floorId,classId);
    this->classrooms[classId]->place(s);    //place teacher in his classroom    
}



void Floor::print() const{
    cout<<"Floor number "<<this->floorId<<"  contains: "<<endl;
    this->corridor->print();
    for(int i=0;i<6;i++)
        this->classrooms[i]->print();
}

Floor::Floor(int Ccorr,int Cclass,int floorId){
    this->Ccorr=Ccorr;
    this->Cclass=Cclass;
    this->floorId=floorId;

    for(int i=0;i<6;i++)
        this->classrooms[i]=new Classroom(this->Cclass,this->floorId,i);

    
    this->corridor=new Corridor(Cclass);
    cout<<"A new Floor has been created! "<<endl;
    
}

Floor::~Floor(){

    cout<<"A floor to be destroyed"<<endl;

    for(int i=0;i<6;i++)
        delete  (this->classrooms[i]);
    delete this->corridor;
}

int Floor::get_available_space() const{
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

int Corridor::get_available_space() const{
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

void Corridor::print() const {
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
    this->Cclass=Cclass;        // initialize capacities 
    this->Cyard=Cyard;
    this->Cstair=Cstairs;
    this->Ccorr=Ccorr;

    for(int i=0;i<3;i++)            //create floors
        this->floors[i]=new Floor(Cstairs, Cclass,i);   //το <i> συμβολίζει τον όροφο(0->πρωτος,1->δευτερος, 2->τριτος)

    this->stairs=new Stairs(Cstairs);   //create stairs
    this->schoolyard=new Schoolyard(Cyard); //create schoolyard
    cout<<"A new school has been created! "<<endl;
}

School::~School(){      //destructor
    cout<<"A school to be destroyed"<<endl;

    for(int i=0;i<3;i++)    //destroy each floor
        delete this->floors[i];

    delete this->stairs;       //destroy stairs
    delete this->schoolyard;    //destroy schoolyard
}




void School::enter(Student& s){     //enter takes 1 student, if there is no capacity, nothing will hapen

    if((this->schoolyard->get_available_space())>0){    //if there is space in scoolyard, add student in school
        cout<<s.getName()<<" enters school"<<endl;
        schoolyard->enter(s);
        if(this->stairs->get_available_space()>0){      //if student is in schoolyard, and there is space in stairs
            Student& stud=(this->schoolyard->exit());
            this->stairs->enter(stud);
            if(this->floors[stud.get_floor()]->get_available_space()>0){   //if student is in stairs and there is space in the floor.
                Student& stud=(this->stairs->exit());                               //where his class belongs
                this->floors[stud.get_floor()]->enter(stud);              //add him in the floor.
            }
            
        }

    }
    return;
}

void School::enter(Student** array, int length){
    int i=0;
    for(i=0;i<length;i++)
        this->enter(*(array[i]));

    return;
}

void School::place(Teacher& t){     //place teacher instantly in his classroom
    int floorId, classId;
    t.get_data(floorId,classId);     //in which class the teacher does belongs
    this->floors[floorId]->place(t);    //first place him in the floor, where his class belongs. Place function from floor, will place him
}                                           //in his classroom

void School::print() const{
    cout<<"School life consists of:  "<<endl;
    this->schoolyard->print();
    this->stairs->print();
    for(int i=0;i< 3;i++)
        this->floors[i]->print();  
    
}

//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
