#include "hw2.h"
#include <ctime>
#include <cstdlib>  

//--------------------------------------------------------------
Student::Student(string name,string gender,int classId){
    this->name=name;    //initialize name
    this->gender=gender;    //initialize gender
    this->classId=classId;  //initialize clasId
    this->naughty=false;    //initialize naughty boolean
    }


string Student::studentName(){
    return this->name;
}

string Student::studentGender(){
    return this->gender;
}

int Student::classroomId(){
    return this->classId;
}
//--------------------------------------------------------------

Classroom::Classroom(int Cclass){
    this->Cclass=Cclass;            //initialize capacity
    this->naughtyCounter=0;         //firstly the counter is zero
    this->students=new Student* [Cclass];       //Array to store students of a classroom
    this->pointer=NULL;                 //no connections
    this->space=0;                      //no one is in the class firstly
    
    int temp=Cclass;                

    if(Cclass%2==0)
        temp=Cclass/2;
    else
        temp=1+Cclass/2;
    
    this->couples= new Couples[temp];   //if the capacity is odd then temp=Cclass/2 else is Cclass/2+1
}

void Classroom::buildSequences(){

    int tempBoy=0;
    int tempGirl=1;
    int counterBoy=0;
    int counterGirl=0;
    for(int i=0;i<this->Cclass;i++){
        if(this->students[i]->studentGender()=="Boy"){

            this->couples[counterBoy++].set_student(*(this->students[i]),tempBoy);
            if(tempBoy==0)
                tempBoy=1;
            else
                tempBoy=0;
        }
        else{

            this->couples[counterGirl++].set_student(*(this->students[i]),tempGirl);
            if(tempGirl==0)
                tempGirl=1;
            else
                tempGirl=0;
            
        }

    }

}

void Classroom::connect(Classroom& classroom){

    Classroom* temp=this->pointer;

    if(this->pointer==NULL){
        this->pointer= &classroom;
        this->pointer->pointer=this;     //circular list
    }
    else{
        while(temp != this)
            temp=temp->pointer;
    temp=&classroom;
    temp->pointer=this;
    }      
        
}

void Classroom::printSequences(){
    
    int temp=0;
    if(this->Cclass%2==0)
        temp=Cclass/2;
    else
        temp=1+Cclass/2;


    for(int i=0;i<temp;i++){
        cout<<this->couples[i].get_student(0).studentName()
        <<"  and  "<<this->couples[i].get_student(1).studentName()<<endl;

    }
}

void Classroom::place(Student& s){
    this->students[this->space]=&s;
    this->space++;
}


void Classroom::restoreQuietness(){ 
     srand(time(nullptr));
    int counter=0;
    int seq=0;
    int tom=0;
    int temp=0;
    int random=0;
    Student* s;
    if(this->Cclass%2==0)
        temp=Cclass/2;
    else
        temp=1+Cclass/2;

    for(int i=0;i<temp;i++){
        if(this->couples[i].get_student(0).is_naughty()==true && this->couples[i].get_student(1).is_naughty()==true ){
            seq++;
            tom++;
        }
        else if((this->couples[i].get_student(0).is_naughty()==false && this->couples[i].get_student(1).is_naughty()==true)
        ||(this->couples[i].get_student(0).is_naughty()==true && this->couples[i].get_student(1).is_naughty()==false))
            seq=0;
    }


    for(int i=0;i<temp;i++){        //check every couple

        if(this->couples[i].get_student(0).is_naughty()==true && this->couples[i].get_student(1).is_naughty()==false){
            
            random=rand()%temp;
            while(random==i)
                random=rand()%temp;
            
            if(this->couples[random].get_student(0).studentGender()==this->couples[i].get_student(0).studentGender()){
                s=&(this->couples[random].get_student(0));
                this->couples[i].get_student(0).make_naughty(false);
                this->couples[random].set_student(this->couples[i].get_student(0),0);
                this->couples[i].set_student(*s,0);
                s->make_naughty(false);
            }
            else{
                s=&(this->couples[random].get_student(1));
                
                this->couples[i].get_student(0).make_naughty(false);
                this->couples[random].set_student(this->couples[i].get_student(0),1);
                this->couples[i].set_student(*s,0);
                s->make_naughty(false);
            }          
            return;
        }else if(this->couples[i].get_student(1).is_naughty()==true && this->couples[i].get_student(0).is_naughty()==false){
             random=rand()%temp;
            while(random==i)
                random=rand()%temp;
            
            if(this->couples[random].get_student(0).studentGender()==this->couples[i].get_student(1).studentGender()){
                s=&(this->couples[random].get_student(0));
                this->couples[i].get_student(1).make_naughty(false);
                this->couples[random].set_student(this->couples[i].get_student(1),0);
                this->couples[i].set_student(*s,1);
                s->make_naughty(false);
            }
            else{
                s=&(this->couples[random].get_student(1));
                
                this->couples[i].get_student(1).make_naughty(false);
                this->couples[random].set_student(this->couples[i].get_student(1),1);
                this->couples[i].set_student(*s,1);
                s->make_naughty(false);
            }      
            return;    
        }else if((tom>0 &&tom<=2 )&& (this->couples[i].get_student(0).is_naughty()==true &&this->couples[i].get_student(1).is_naughty()==true)){
            random=rand()%temp;
            while(random==i)
                random=rand()%temp;

            if(this->couples[random].get_student(0).studentGender()==this->couples[i].get_student(0).studentGender()){
                s=&(this->couples[random].get_student(0));
                this->couples[i].get_student(0).make_naughty(false);
                this->couples[random].set_student(this->couples[i].get_student(0),0);
                this->couples[i].set_student(*s,0);
                s->make_naughty(false);
            }
            else{
                s=&(this->couples[random].get_student(1));
                
                this->couples[i].get_student(0).make_naughty(false);
                this->couples[random].set_student(this->couples[i].get_student(0),1);
                this->couples[i].set_student(*s,0);
                s->make_naughty(false);
            }

            random=rand()%temp;
            while(random==i)
                random=rand()%temp;
            if(this->couples[random].get_student(0).studentGender()==this->couples[i].get_student(1).studentGender()){
                s=&(this->couples[random].get_student(0));
                this->couples[i].get_student(1).make_naughty(false);
                this->couples[random].set_student(this->couples[i].get_student(1),0);
                this->couples[i].set_student(*s,1);
                s->make_naughty(false);
            }
            else{
                s=&(this->couples[random].get_student(1));
                
                this->couples[i].get_student(1).make_naughty(false);
                this->couples[random].set_student(this->couples[i].get_student(1),1);
                this->couples[i].set_student(*s,1);
                s->make_naughty(false);
            }
        }else if((tom>2) && (this->couples[i].get_student(0).is_naughty()==true &&this->couples[i].get_student(1).is_naughty()==true)){
            random=rand()%temp;


            if(this->pointer->couples[random].get_student(0).studentGender()==this->couples[i].get_student(0).studentGender()){
                s=&(this->pointer->couples[random].get_student(0));
                this->couples[i].get_student(0).make_naughty(false);
                this->pointer->couples[random].set_student(this->couples[i].get_student(0),0);
                this->couples[i].set_student(*s,0);
                s->make_naughty(false);
            }
            else{
                s=&(this->pointer->couples[random].get_student(1));
                
                this->couples[i].get_student(0).make_naughty(false);
                this->pointer->couples[random].set_student(this->couples[i].get_student(0),1);
                this->couples[i].set_student(*s,0);
                s->make_naughty(false);
            }

            random=rand()%temp;
 
            if(this->pointer->couples[random].get_student(0).studentGender()==this->couples[i].get_student(1).studentGender()){
                s=&(this->pointer->couples[random].get_student(0));
                this->couples[i].get_student(1).make_naughty(false);
                this->pointer->couples[random].set_student(this->couples[i].get_student(1),0);
                this->couples[i].set_student(*s,1);
                s->make_naughty(false);
            }
            else{
                s=&(this->pointer->couples[random].get_student(1));
                
                this->couples[i].get_student(1).make_naughty(false);
                this->pointer->couples[random].set_student(this->couples[i].get_student(1),1);
                this->couples[i].set_student(*s,1);
                s->make_naughty(false);
            }



        }

        




    }






    return;
}





//--------------------------------------------------------------

Student& Couples::get_student(int pos){
    return *(this->s[pos]);
}



