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

void Sequence::connect(Sequence& sequence){
      Sequence* temp=this;

    if(this->next==NULL){
        this->next= &sequence;
        this->next->next=this;     //circular list
    }
    else{
        while(temp->next != this)
            temp=temp->next;
    temp->next= &sequence;
        temp->next->next=this;     //circular list
    }      
}


void Sequence::add_student(Student& s){
    
    if(s.studentGender()=="Boy"){
        this->couples[this->counterBoy].s[this->tempBoy]=&s;
        if(tempBoy==0)
            this->tempBoy=1;
        else
            this->tempBoy=0;
        (this->counterBoy)++;

    }else{
        this->couples[this->CounterGirl].s[this->tempGirl]=&s;
        if(tempGirl==0)
            this->tempGirl=1;
        else
            this->tempGirl=0;
        (this->CounterGirl)++;
    }
    
}


Sequence::Sequence(Student** students,int number,float Tquiet/*=0*/,float Tmessy/*=0*/){    

    this->Tmessy=Tmessy;
    this->Tquiet=Tquiet;
    this->naughtyCounter=0;
    this->next=NULL;
    this->id=students[0]->classroomId();
    this->couples=NULL;
    this->counterBoy=0;
    this->CounterGirl=0;
    this->tempBoy=0;
    this->tempGirl=1;
    

    if(number%2==0){
        this->couples=new Couples[number/2];
        this->couplesNumber=number/2;
    }else{
        this->couples=new Couples[number/2+1];
        this->couplesNumber=number/2+1;
    }

    for(int i=0;i<number;i++)
        this->add_student(*(students[i]));
    
}

void Sequence::printSequence(){

    for(int i=0;i<this->couplesNumber;i++){
        cout<<this->couples[i].s[0]->studentName()<<"  and  "<<this->couples[i].s[1]->studentName()<<endl;}
}


void Sequence::print(){
    Sequence* temp=this;
    cout<<"counter is: "<<this->naughtyCounter<<endl;
    for(int i=0;i<this->couplesNumber;i++){
        cout<<this->couples[i].s[0]->studentName()<<"  and  "<<this->couples[i].s[1]->studentName()<<endl;}
    
    if(this->next==NULL)
        return;

    while(temp->next != this){ 
        cout<<endl;
        for(int i=0;i<temp->next->couplesNumber;i++)
            cout<<temp->next->couples[i].s[0]->studentName()<<"  and  "<<temp->next->couples[i].s[1]->studentName()<<endl;
        temp=temp->next;
    }
}

void Sequence::restoreQuitness(){
    srand(time(nullptr));
    int counter=-1;
    int seq=0;
    int tom=0;
    int temp=0;
    int random=0;
    Student* s;
    int break_sequence=0;

    for(int i=0;i<this->couplesNumber;i++){
        if(this->couples[i].s[0]->is_naughty()==true && this->couples[i].s[1]->is_naughty()==true ){
            if(counter==-1)
                counter=0;
                  //αν εχουμε συνεχομενες ακολουθιες που κανουν αταξιες
            tom++;
        }
        else if((this->couples[i].s[0]->is_naughty()==false && this->couples[i].s[1]->is_naughty()==true)
        ||(this->couples[i].s[0]->is_naughty()==true && this->couples[i].s[1]->is_naughty()==false)
        || (this->couples[i].s[0]->is_naughty()==false && this->couples[i].s[1]->is_naughty()==false)){
            if(counter==0){
                for(int j=i;j<this->couplesNumber;j++){
                    if(this->couples[j].s[0]->is_naughty()==true && this->couples[j].s[1]->is_naughty()==true )
                        counter=1;
                }
            }
            

        }
    }

    for(int i=0;i<this->couplesNumber;i++){

        if(this->couples[i].s[0]->is_naughty()==true && this->couples[i].s[1]->is_naughty()==false){  //if one out of two kids is naughty
            
            random=rand()%this->couplesNumber;     //choose a random,same gender kid to swap
            while(random==i)
                random=rand()%this->couplesNumber;
            
            if(this->couples[random].s[0]->studentGender()==this->couples[i].s[0]->studentGender()){
                s=(this->couples[random].s[0]);  
                cout<<"RANDOM/SAME: "<<random<<endl;
                this->couples[i].s[0]->make_naughty(false);
                this->couples[random].s[0]=this->couples[i].s[0];
                this->couples[i].s[0]=s;
                s->make_naughty(false);
                this->naughtyCounter++;
                this->printSequence();
                cout<<"--------------------"<<endl;
            }
            else{
                s=(this->couples[random].s[1]);  
                cout<<"RANDOM/SAME: "<<random<<endl;
                this->couples[i].s[0]->make_naughty(false);
                this->couples[random].s[1]=this->couples[i].s[0];
                this->couples[i].s[0]=s;
                s->make_naughty(false);
                this->naughtyCounter++;
                this->printSequence();
                cout<<"--------------------"<<endl;
            }
            continue;
        }
        else if(this->couples[i].s[1]->is_naughty()==true && this->couples[i].s[0]->is_naughty()==false){  //if one out of two kids is naughty
            
            random=rand()%this->couplesNumber;     //choose a random,same gender kid to swap
            while(random==i)
                random=rand()%this->couplesNumber;
            
            if(this->couples[random].s[0]->studentGender()==this->couples[i].s[1]->studentGender()){
                s=(this->couples[random].s[0]);  

                this->couples[i].s[1]->make_naughty(false);
                this->couples[random].s[0]=this->couples[i].s[1];
                this->couples[i].s[1]=s;
                s->make_naughty(false);
                this->naughtyCounter++;
                this->printSequence();
                cout<<"--------------------"<<endl;
            }
            else{
                s=(this->couples[random].s[1]);  

                this->couples[i].s[1]->make_naughty(false);
                this->couples[random].s[1]=this->couples[i].s[1];
                this->couples[i].s[1]=s;
                s->make_naughty(false);
                this->naughtyCounter++;
                this->printSequence();  
                cout<<"--------------------"<<endl;
            }
            continue;
        }
        else if((tom>0 &&tom<=2 )&& (this->couples[i].s[0]->is_naughty()==true &&this->couples[i].s[1]->is_naughty()==true)){

            random=rand()%this->couplesNumber;
            while(random==i)
                random=rand()%this->couplesNumber;

            if(this->couples[random].s[0]->studentGender()==this->couples[i].s[0]->studentGender()){
                s=(this->couples[random].s[0]);  

                this->couples[i].s[0]->make_naughty(false);
                this->couples[random].s[0]=this->couples[i].s[0];
                this->couples[i].s[0]=s;
                s->make_naughty(false);
                this->naughtyCounter++;
                this->printSequence();
                cout<<"--------------------"<<endl;
            }
            else{
                s=(this->couples[random].s[1]);  

                this->couples[i].s[0]->make_naughty(false);
                this->couples[random].s[1]=this->couples[i].s[0];
                this->couples[i].s[0]=s;
                s->make_naughty(false);
                this->naughtyCounter++;
                this->printSequence();
                cout<<"--------------------"<<endl;
            }

            random=rand()%this->couplesNumber;
            while(random==i)
                random=rand()%this->couplesNumber;

            if(this->couples[random].s[0]->studentGender()==this->couples[i].s[1]->studentGender()){
                s=(this->couples[random].s[0]);  

                this->couples[i].s[1]->make_naughty(false);
                this->couples[random].s[0]=this->couples[i].s[1];
                this->couples[i].s[1]=s;
                s->make_naughty(false);
                this->naughtyCounter++;
                this->printSequence();
                cout<<"--------------------"<<endl;
            }
            else{
                s=(this->couples[random].s[1]);  

                this->couples[i].s[1]->make_naughty(false);
                this->couples[random].s[1]=this->couples[i].s[1];
                this->couples[i].s[1]=s;
                s->make_naughty(false);
                this->naughtyCounter++;
                this->printSequence(); 
                cout<<"--------------------"<<endl; 
            }
            
        }
        else if((tom>2 && counter==1) && (this->couples[i].s[0]->is_naughty()==true &&this->couples[i].s[1]->is_naughty()==true)){      //ΔΕΝ ΔΟΥΛΕΥΕΥ Η ΣΥΝΘΗΚΗ( tom>2 && seq==0)
           cout<<"############################################33"<<endl;
            random=rand()%this->next->couplesNumber;                                                                                    //ΠΡΟΣΟΧΗ

            if(this->couples[random].s[0]->studentGender()==this->couples[i].s[0]->studentGender()){
                s=(this->next->couples[random].s[0]);  

                this->couples[i].s[0]->make_naughty(false);
                this->next->couples[random].s[0]=this->couples[i].s[0];
                this->couples[i].s[0]=s;
                s->make_naughty(false);
                this->naughtyCounter=this->naughtyCounter+2;
                this->printSequence();
                cout<<"--------------------"<<endl;
                this->next->printSequence();
            }
            else{
                s=(this->next->couples[random].s[1]);  

                this->couples[i].s[0]->make_naughty(false);
                this->next->couples[random].s[1]=this->couples[i].s[0];
                this->couples[i].s[0]=s;
                s->make_naughty(false);
                this->naughtyCounter=this->naughtyCounter+2;
                this->printSequence();
                cout<<"--------------------"<<endl;
                this->next->printSequence();
            }

            random=rand()%this->next->couplesNumber;

            if(this->couples[random].s[0]->studentGender()==this->couples[i].s[1]->studentGender()){
                s=(this->next->couples[random].s[0]);  

                this->couples[i].s[1]->make_naughty(false);
                this->next->couples[random].s[0]=this->couples[i].s[1];
                this->couples[i].s[1]=s;
                s->make_naughty(false);
                this->naughtyCounter=this->naughtyCounter+2;
                this->printSequence();
                cout<<"--------------------"<<endl;
                this->next->printSequence();
            }
            else{
                s=(this->next->couples[random].s[1]);  

                this->couples[i].s[1]->make_naughty(false);
                this->next->couples[random].s[1]=this->couples[i].s[1];
                this->couples[i].s[1]=s;
                s->make_naughty(false);
                this->naughtyCounter=this->naughtyCounter+2;
                this->printSequence();
                cout<<"--------------------"<<endl;
                this->next->printSequence();
            }

        }
        else if((tom>2 && counter == 0)&& this->couples[i].s[0]->is_naughty()==true){       //Αφου ειναι ζευγαρι δεν εχει σημασια αν θα ειναι ο πρωτος ή ο δευτερος
        cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@2"<<endl;
            int cntr=1;
            int rnd=0;
            Sequence* pointer;
            pointer=this->next;
            while(pointer->next != this){       //μετραω το πληθος των ακολουθιων
                pointer=pointer->next;
                cntr++;
            }

            pointer=this->next;
            rnd=rand()%cntr;
            while(rnd == 0)
                rnd=rand()%cntr; //poia thesi stin lista
     
            while((rnd--) != 1 )
                pointer=pointer->next;
            
            random=rand()%pointer->couplesNumber;
            
            if(pointer->couples[random].s[0]->studentGender()==this->couples[i].s[0]->studentGender()){
                s=(pointer->couples[random].s[0]);  

                this->couples[i].s[0]->make_naughty(false);
                pointer->couples[random].s[0]=this->couples[i].s[0];
                this->couples[i].s[0]=s;
                s->make_naughty(false);
                this->naughtyCounter=this->naughtyCounter+2;
                this->printSequence();
                cout<<"--------------------"<<endl;
                pointer->printSequence();
            }
            else{
                s=(pointer->couples[random].s[1]);  

                this->couples[i].s[0]->make_naughty(false);
                pointer->couples[random].s[1]=this->couples[i].s[0];
                this->couples[i].s[0]=s;
                s->make_naughty(false);
                this->naughtyCounter=this->naughtyCounter+2;
                this->printSequence();
                cout<<"--------------------"<<endl;
                pointer->printSequence();
            }

             pointer=this->next;
            rnd=rand()%cntr;
            while(rnd == 0)
                rnd=rand()%cntr;

            while((rnd--) != 1 )
                pointer=pointer->next;
            
            random=rand()%pointer->couplesNumber;

            if(pointer->couples[random].s[0]->studentGender()==this->couples[i].s[1]->studentGender()){
                s=(pointer->couples[random].s[0]);  

                this->couples[i].s[1]->make_naughty(false);
                pointer->couples[random].s[0]=this->couples[i].s[1];
                this->couples[i].s[1]=s;
                s->make_naughty(false);
                this->naughtyCounter=this->naughtyCounter+2;
                this->printSequence();
                cout<<"--------------------"<<endl;
                pointer->printSequence();
            }
            else{
                s=(pointer->couples[random].s[1]);  

                this->couples[i].s[1]->make_naughty(false);
                pointer->couples[random].s[1]=this->couples[i].s[1];
                this->couples[i].s[1]=s;
                s->make_naughty(false);
                this->naughtyCounter=this->naughtyCounter+2;
                this->printSequence();
                cout<<"--------------------"<<endl;
                pointer->printSequence();
            }



        }

    }
    
}


void Sequence::restore(){
    Sequence* temp=this;
    this->restoreQuitness();

    if(this->next==NULL)
        return;

    while(temp->next != this){ 
        temp->next->restoreQuitness();
        temp=temp->next;
    }
 


}