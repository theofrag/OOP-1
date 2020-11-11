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

// Classroom::Classroom(int Cclass){
//     this->Cclass=Cclass;            //initialize capacity
//     this->naughtyCounter=0;         //firstly the counter is zero
//     this->students=new Student* [Cclass];       //Array to store students of a classroom
//     this->pointer=NULL;                 //no connections
//     this->space=0;                      //no one is in the class firstly
    
//     int temp=Cclass;                

//     if(Cclass%2==0)
//         temp=Cclass/2;
//     else
//         temp=1+Cclass/2;
    
//     this->couples= new Couples[temp];   //if the capacity is odd then temp=Cclass/2 else is Cclass/2+1
// }

// void Classroom::buildSequences(){

//     int tempBoy=0;
//     int tempGirl=1;
//     int counterBoy=0;
//     int counterGirl=0;
//     for(int i=0;i<this->Cclass;i++){
//         if(this->students[i]->studentGender()=="Boy"){

//             this->couples[counterBoy++].set_student(*(this->students[i]),tempBoy);
//             if(tempBoy==0)
//                 tempBoy=1;
//             else
//                 tempBoy=0;
//         }
//         else{

//             this->couples[counterGirl++].set_student(*(this->students[i]),tempGirl);
//             if(tempGirl==0)
//                 tempGirl=1;
//             else
//                 tempGirl=0;
            
//         }

//     }

// }

// void Classroom::connect(Classroom& classroom){

//     Classroom* temp=this;

//     if(this->pointer==NULL){
//         this->pointer= &classroom;
//         this->pointer->pointer=this;     //circular list
//     }
//     else{
//         while(temp->pointer != this)
//             temp=temp->pointer;
//     temp->pointer= &classroom;
//         temp->pointer->pointer=this;     //circular list
//     }      
        
// }

// void Classroom::printSequences(){
    
//     int temp=0;
//     if(this->Cclass%2==0)
//         temp=Cclass/2;
//     else
//         temp=1+Cclass/2;


//     for(int i=0;i<temp;i++){
//         cout<<this->couples[i].get_student(0).studentName()
//         <<"  and  "<<this->couples[i].get_student(1).studentName()<<endl;

//     }
// }

// void Classroom::place(Student& s){
//     this->students[this->space]=&s;
//     this->space++;
// }


// void Classroom::restoreQuietness(){ 
//      srand(time(nullptr));
//     int counter=0;
//     int seq=0;
//     int tom=0;
//     int temp=0;
//     int random=0;
//     Student* s;
//     if(this->Cclass%2==0)
//         temp=Cclass/2;
//     else
//         temp=1+Cclass/2;

//     for(int i=0;i<temp;i++){
//         if(this->couples[i].get_student(0).is_naughty()==true && this->couples[i].get_student(1).is_naughty()==true ){
//             seq++;      //αν εχουμε συνεχομενες ακολουθιες που κανουν αταξιες
//             tom++;
//         }
//         else if((this->couples[i].get_student(0).is_naughty()==false && this->couples[i].get_student(1).is_naughty()==true)
//         ||(this->couples[i].get_student(0).is_naughty()==true && this->couples[i].get_student(1).is_naughty()==false))
//             seq=0;
        
//     }


//     for(int i=0;i<temp;i++){        //check every couple

//         if(this->couples[i].get_student(0).is_naughty()==true && this->couples[i].get_student(1).is_naughty()==false){  //if one out of two kids is naughty
            
//             random=rand()%temp;     //choose a random,same gender kid to swap
//             while(random==i)
//                 random=rand()%temp;
            
//             if(this->couples[random].get_student(0).studentGender()==this->couples[i].get_student(0).studentGender()){
//                 s=&(this->couples[random].get_student(0));  cout<<"RANDOM/SAME: "<<random<<endl;
//                 this->couples[i].get_student(0).make_naughty(false);
//                 this->couples[random].set_student(this->couples[i].get_student(0),0);
//                 this->couples[i].set_student(*s,0);
//                 s->make_naughty(false);
//             }
//             else{
//                 s=&(this->couples[random].get_student(1));
//                 cout<<"RANDOM/SAME: "<<random<<endl;
//                 this->couples[i].get_student(0).make_naughty(false);
//                 this->couples[random].set_student(this->couples[i].get_student(0),1);
//                 this->couples[i].set_student(*s,0);
//                 s->make_naughty(false);
//             }          
//             continue;
//         }else if(this->couples[i].get_student(1).is_naughty()==true && this->couples[i].get_student(0).is_naughty()==false){
//              random=rand()%temp;
//             while(random==i)
//                 random=rand()%temp;
            
//             if(this->couples[random].get_student(0).studentGender()==this->couples[i].get_student(1).studentGender()){
//                 s=&(this->couples[random].get_student(0));cout<<"RANDOM/SAME: "<<random<<endl;
//                 this->couples[i].get_student(1).make_naughty(false);
//                 this->couples[random].set_student(this->couples[i].get_student(1),0);
//                 this->couples[i].set_student(*s,1);
//                 s->make_naughty(false);
//             }
//             else{
//                 s=&(this->couples[random].get_student(1));
//                 cout<<"RANDOM/SAME: "<<random<<endl;
//                 this->couples[i].get_student(1).make_naughty(false);
//                 this->couples[random].set_student(this->couples[i].get_student(1),1);
//                 this->couples[i].set_student(*s,1);
//                 s->make_naughty(false);
//             }      
//             continue;    
//         }else if((tom>0 &&tom<=2 )&& (this->couples[i].get_student(0).is_naughty()==true &&this->couples[i].get_student(1).is_naughty()==true)){
//             random=rand()%temp;
//             while(random==i)
//                 random=rand()%temp;

//             if(this->couples[random].get_student(0).studentGender()==this->couples[i].get_student(0).studentGender()){
//                 s=&(this->couples[random].get_student(0));cout<<"RANDOM/SAME: "<<random<<endl;
//                 this->couples[i].get_student(0).make_naughty(false);
//                 this->couples[random].set_student(this->couples[i].get_student(0),0);
//                 this->couples[i].set_student(*s,0);
//                 s->make_naughty(false);
//             }
//             else{
//                 s=&(this->couples[random].get_student(1));
//                 cout<<"RANDOM/SAME: "<<random<<endl;
//                 this->couples[i].get_student(0).make_naughty(false);
//                 this->couples[random].set_student(this->couples[i].get_student(0),1);
//                 this->couples[i].set_student(*s,0);
//                 s->make_naughty(false);
//             }

//             random=rand()%temp;
//             while(random==i)
//                 random=rand()%temp;
//             if(this->couples[random].get_student(0).studentGender()==this->couples[i].get_student(1).studentGender()){
//                 s=&(this->couples[random].get_student(0));cout<<"RANDOM/SAME: "<<random<<endl;
//                 this->couples[i].get_student(1).make_naughty(false);
//                 this->couples[random].set_student(this->couples[i].get_student(1),0);
//                 this->couples[i].set_student(*s,1);
//                 s->make_naughty(false);
//             }
//             else{
//                 s=&(this->couples[random].get_student(1));
//                cout<<"RANDOM/SAME: "<<random<<endl;
//                 this->couples[i].get_student(1).make_naughty(false);
//                 this->couples[random].set_student(this->couples[i].get_student(1),1);
//                 this->couples[i].set_student(*s,1);
//                 s->make_naughty(false);
//             }
//         }else if((tom>2 && seq==0) && (this->couples[i].get_student(0).is_naughty()==true &&this->couples[i].get_student(1).is_naughty()==true)){
//             random=rand()%temp;


//             if(this->pointer->couples[random].get_student(0).studentGender()==this->couples[i].get_student(0).studentGender()){
//                 s=&(this->pointer->couples[random].get_student(0));
//                 cout<<"RANDOM/DIFF: "<<random<<endl;
//                 this->couples[i].get_student(0).make_naughty(false);
//                 this->pointer->couples[random].set_student(this->couples[i].get_student(0),0);
//                 this->couples[i].set_student(*s,0);
//                 s->make_naughty(false);
//             }
//             else{
//                 s=&(this->pointer->couples[random].get_student(1));
//                 cout<<"RANDOM/DIFF: "<<random<<endl;
//                 this->couples[i].get_student(0).make_naughty(false);
//                 this->pointer->couples[random].set_student(this->couples[i].get_student(0),1);
//                 this->couples[i].set_student(*s,0);
//                 s->make_naughty(false);
//             }

//             random=rand()%temp;
 
//             if(this->pointer->couples[random].get_student(0).studentGender()==this->couples[i].get_student(1).studentGender()){
//                 s=&(this->pointer->couples[random].get_student(0));
//                 cout<<"RANDOM/DIFF: "<<random<<endl;
//                 this->couples[i].get_student(1).make_naughty(false);
//                 this->pointer->couples[random].set_student(this->couples[i].get_student(1),0);
//                 this->couples[i].set_student(*s,1);
//                 s->make_naughty(false);
//             }
//             else{
//                 s=&(this->pointer->couples[random].get_student(1));
//                 cout<<"RANDOM/DIFF: "<<random<<endl;
//                 this->couples[i].get_student(1).make_naughty(false);
//                 this->pointer->couples[random].set_student(this->couples[i].get_student(1),1);
//                 this->couples[i].set_student(*s,1);
//                 s->make_naughty(false);
//             }



//         }else if(seq!=0 && this->couples[i].get_student(0).is_naughty()==true){     //Αφου ειναι ζευγαρι δεν εχει σημασια αν θα ειναι ο πρωτος ή ο δευτερος
//             int cntr=1;
//             int rnd=0;
//             Classroom* next;
//             next=this->pointer;
//             while(next->pointer != this){
//                 next=next->pointer;
//                 cntr++;
//             }
//             next=this->pointer;
//             cout<<"cntr is: "<<cntr<<endl;
//             rnd=rand()%cntr;
//             while(rnd == 0)
//                 rnd=rand()%cntr;
//             cout<<"RND IS*****************************>>>"<<rnd<<endl;
//             while((rnd--) != 1 )
//                 next=next->pointer;           


//             random=rand()%temp;

//             if(next->couples[random].get_student(0).studentGender()==this->couples[i].get_student(0).studentGender()){
//                 s=&(next->couples[random].get_student(0));
//                 cout<<"RANDOM/DIFF: "<<random<<endl;
//                 this->couples[i].get_student(0).make_naughty(false);
//                 next->couples[random].set_student(this->couples[i].get_student(0),0);
//                 this->couples[i].set_student(*s,0);
//                 s->make_naughty(false);
//             }
//             else{
//                 s=&(next->couples[random].get_student(1));
//                 cout<<"RANDOM/DIFF: "<<random<<endl;
//                 this->couples[i].get_student(0).make_naughty(false);
//                 next->couples[random].set_student(this->couples[i].get_student(0),1);
//                 this->couples[i].set_student(*s,0);
//                 s->make_naughty(false);
//             }
            
//             next=this->pointer;
//             rnd=rand()%cntr;
//             while(rnd == 0)
//                 rnd=rand()%cntr;
//             cout<<"RND IS*****************************>>>"<<rnd<<endl;
//             while((rnd--) != 1 )
//                 next=next->pointer;

//             random=rand()%temp;
 
//             if(next->couples[random].get_student(0).studentGender()==this->couples[i].get_student(1).studentGender()){
//                 s=&(next->couples[random].get_student(0));
//                 cout<<"RANDOM/DIFF: "<<random<<endl;
//                 this->couples[i].get_student(1).make_naughty(false);
//                 next->couples[random].set_student(this->couples[i].get_student(1),0);
//                 this->couples[i].set_student(*s,1);
//                 s->make_naughty(false);
//             }
//             else{
//                 s=&(next->couples[random].get_student(1));
//                 cout<<"RANDOM/DIFF: "<<random<<endl;
//                 this->couples[i].get_student(1).make_naughty(false);
//                 next->couples[random].set_student(this->couples[i].get_student(1),1);
//                 this->couples[i].set_student(*s,1);
//                 s->make_naughty(false);
//             }


//         }

        


//     cout<<"==========================================="<<endl;
//     this->printSequences();
//     cout<<"==========================================="<<endl;

//     }






//     return;
// }





//--------------------------------------------------------------

// Student& Couples::get_student(int pos){
//     return *(this->s[pos]);
// }

//-----------------------------------------------------------

int** Sequence::make_array(Student** students,int capacity,int number){

     int** array=new int* [2];
    for(int i=0;i<2;i++)
        array[i]=new int[number];

    for(int i=0;i<2;i++){
        for(int j=0;j<number;j++)
            array[i][j]=-1;
    }

  
    for(int i=0;i<capacity;i++){
        int tempCounter=0;
        int temp=students[i]->classroomId(); 
        for(int j=0;j<number;j++){
            if(array[0][j]==-1)
                break;
            if(temp != array[0][j])
                tempCounter++;
            else
                break;
        }
        array[0][tempCounter]=temp;
        (array[1][tempCounter])++;
        tempCounter=0;
    }

    return array;
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


Sequence::Sequence(Student** students, int capacity,int number){    
    
   int** array=this->make_array(students,capacity,number);
   
    this->next=NULL;
    this->id=array[0][0];
    this->couples=NULL;
    this->counterBoy=0;
    this->CounterGirl=0;
    this->tempBoy=0;
    this->tempGirl=1;
    

    if(array[1][0]%2==0){
        this->couples=new Couples[array[1][0]/2];
        this->couplesNumber=array[1][0]/2;
    }else{
        this->couples=new Couples[array[1][0]/2+1];
        this->couplesNumber=array[1][0]/2+1;
    }


    Sequence* temp=this;
    this->id=students[0]->classroomId();
    for(int i=0;i<capacity;i++){
        temp=this;
        if(students[i]->classroomId() != this->id){
            if(this->next==NULL){
                int tempCounter=0;
                for(int j=0;j<number;j++){
                    if(students[i]->classroomId() != array[0][j])
                        tempCounter++;
                    else
                        break;
                }
                this->next=new Sequence(array[1][tempCounter]);
                this->next->add_student(*(students[i]));
                this->next->id= array[0][tempCounter];
                this->next->next=this;                
            }
            
            
            else{

                while((temp->next != this )){
                    if((temp->id == students[i]->classroomId())){
                        break;}
                    temp=temp->next;
                }
                if((temp->next == this) && (temp->id != students[i]->classroomId())){
                    
                    int tempCounter=0; 
                    for(int j=0;j<number;j++){
                        if(students[i]->classroomId() != array[0][j])
                            tempCounter++;
                        else
                            break;
                    }
                    temp->next= new Sequence(array[1][tempCounter]);
                    temp=temp->next; 
                    temp->next=this; //circular list
                    temp->add_student(*(students[i]));
                    temp->id=array[0][tempCounter];
                }else{
                    temp->add_student(*(students[i]));
                    
                }     
            } 
        }
        else{
            this->add_student(*(students[i]));
        }        

    }
    
}

Sequence::Sequence(int number){

    if(number%2==0){
        this->couples=new Couples[number/2];
        this->couplesNumber=number/2;
    }else{
        this->couples=new Couples[number/2+1];
        this->couplesNumber=number/2+1;
    }

    this->tempBoy=0;
    this->tempGirl=1;
    this->couples=NULL;
    this->counterBoy=0;
    this->CounterGirl=0;
    this->id=-1;
    this->couples= new Couples[number];
    this->next=NULL;
}


void Sequence::print(){
    Sequence* temp=this;

    for(int i=0;i<this->couplesNumber;i++){
        cout<<this->couples[i].s[0]->studentName()<<"  and  "<<this->couples[i].s[1]->studentName()<<endl;}
    
    while(temp->next != this){ 
        cout<<endl;
        for(int i=0;i<temp->next->couplesNumber;i++)
            cout<<temp->next->couples[i].s[0]->studentName()<<"  and  "<<temp->next->couples[i].s[1]->studentName()<<endl;
        temp=temp->next;
    }
}

void Sequence::restoreQuitness(){
    
}


void Sequence::restore(){
      srand(time(nullptr));
    int counter=0;
    int seq=0;
    int tom=0;
    int temp=0;
    int random=0;
    Student* s;

    for(int i=0;i<this->couplesNumber;i++){
        if(this->couples[i].s[0]->is_naughty()==true && this->couples[i].s[1]->is_naughty()==true ){
            seq++;      //αν εχουμε συνεχομενες ακολουθιες που κανουν αταξιες
            tom++;
        }
        else if((this->couples[i].s[0]->is_naughty()==false && this->couples[i].s[1]->is_naughty()==true)
        ||(this->couples[i].s[0]->is_naughty()==true && this->couples[i].s[1]->is_naughty()==false))
            seq=0;
    }
cout<<seq<<endl;

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
            }
            else{
                s=(this->couples[random].s[1]);  
                cout<<"RANDOM/SAME: "<<random<<endl;
                this->couples[i].s[0]->make_naughty(false);
                this->couples[random].s[1]=this->couples[i].s[0];
                this->couples[i].s[0]=s;
                s->make_naughty(false);
            }
            continue;
        }
        else if(this->couples[i].s[1]->is_naughty()==true && this->couples[i].s[0]->is_naughty()==false){  //if one out of two kids is naughty
            
            random=rand()%this->couplesNumber;     //choose a random,same gender kid to swap
            while(random==i)
                random=rand()%this->couplesNumber;
            
            if(this->couples[random].s[0]->studentGender()==this->couples[i].s[1]->studentGender()){
                s=(this->couples[random].s[0]);  
                cout<<"RANDOM/SAME: "<<random<<endl;
                this->couples[i].s[1]->make_naughty(false);
                this->couples[random].s[0]=this->couples[i].s[1];
                this->couples[i].s[1]=s;
                s->make_naughty(false);
            }
            else{
                s=(this->couples[random].s[1]);  
                cout<<"RANDOM/SAME: "<<random<<endl;
                this->couples[i].s[1]->make_naughty(false);
                this->couples[random].s[1]=this->couples[i].s[1];
                this->couples[i].s[1]=s;
                s->make_naughty(false);
            }
            continue;
        }
        else if((tom>0 &&tom<=2 )&& (this->couples[i].s[0]->is_naughty()==true &&this->couples[i].s[1]->is_naughty()==true)){
            random=rand()%this->couplesNumber;
            while(random==i)
                random=rand()%this->couplesNumber;

            if(this->couples[random].s[0]->studentGender()==this->couples[i].s[0]->studentGender()){
                s=(this->couples[random].s[0]);  
                cout<<"RANDOM/SAME: "<<random<<endl;
                this->couples[i].s[0]->make_naughty(false);
                this->couples[random].s[0]=this->couples[i].s[0];
                this->couples[i].s[0]=s;
                s->make_naughty(false);
            }
            else{
                s=(this->couples[random].s[1]);  
                cout<<"RANDOM/SAME: "<<random<<endl;
                this->couples[i].s[0]->make_naughty(false);
                this->couples[random].s[1]=this->couples[i].s[0];
                this->couples[i].s[0]=s;
                s->make_naughty(false);
            }

            random=rand()%temp;
            while(random==i)
                random=rand()%temp;

            if(this->couples[random].s[0]->studentGender()==this->couples[i].s[1]->studentGender()){
                s=(this->couples[random].s[0]);  
                cout<<"RANDOM/SAME: "<<random<<endl;
                this->couples[i].s[1]->make_naughty(false);
                this->couples[random].s[0]=this->couples[i].s[1];
                this->couples[i].s[1]=s;
                s->make_naughty(false);
            }
            else{
                s=(this->couples[random].s[1]);  
                cout<<"RANDOM/SAME: "<<random<<endl;
                this->couples[i].s[1]->make_naughty(false);
                this->couples[random].s[1]=this->couples[i].s[1];
                this->couples[i].s[1]=s;
                s->make_naughty(false);
            }
            
        }
        else if((tom>2 && seq==0) && (this->couples[i].s[0]->is_naughty()==true &&this->couples[i].s[1]->is_naughty()==true)){      //ΔΕΝ ΔΟΥΛΕΥΕΥ Η ΣΥΝΘΗΚΗ( tom>2 && seq==0)
            random=rand()%this->next->couplesNumber;                                                                                    //ΠΡΟΣΟΧΗ

            if(this->couples[random].s[0]->studentGender()==this->couples[i].s[0]->studentGender()){
                s=(this->next->couples[random].s[0]);  
                cout<<"RANDOM/DIFF: "<<random<<endl;
                this->couples[i].s[0]->make_naughty(false);
                this->next->couples[random].s[0]=this->couples[i].s[0];
                this->couples[i].s[0]=s;
                s->make_naughty(false);
            }
            else{
                s=(this->next->couples[random].s[1]);  
                cout<<"RANDOM/DIFF: "<<random<<endl;
                this->couples[i].s[0]->make_naughty(false);
                this->next->couples[random].s[1]=this->couples[i].s[0];
                this->couples[i].s[0]=s;
                s->make_naughty(false);
            }

            random=rand()%this->next->couplesNumber;

            if(this->couples[random].s[0]->studentGender()==this->couples[i].s[1]->studentGender()){
                s=(this->next->couples[random].s[0]);  
                cout<<"RANDOM/DIFF: "<<random<<endl;
                this->couples[i].s[1]->make_naughty(false);
                this->next->couples[random].s[0]=this->couples[i].s[1];
                this->couples[i].s[1]=s;
                s->make_naughty(false);
            }
            else{
                s=(this->next->couples[random].s[1]);  
                cout<<"RANDOM/SAME: "<<random<<endl;
                this->couples[i].s[1]->make_naughty(false);
                this->next->couples[random].s[1]=this->couples[i].s[1];
                this->couples[i].s[1]=s;
                s->make_naughty(false);
            }

        }
        else if(seq!=0 && this->couples[i].s[0]->is_naughty()==true){       //Αφου ειναι ζευγαρι δεν εχει σημασια αν θα ειναι ο πρωτος ή ο δευτερος
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
                rnd=rand()%cntr;
            cout<<"RND IS*****************************>>>"<<rnd<<endl;      //poia thesi stin lista
            while((rnd--) != 1 )
                pointer=pointer->next;
            
            random=rand()%pointer->couplesNumber;
            
            if(pointer->couples[random].s[0]->studentGender()==this->couples[i].s[0]->studentGender()){
                s=(pointer->couples[random].s[0]);  
                cout<<"RANDOM/DIFF: "<<random<<endl;
                this->couples[i].s[0]->make_naughty(false);
                pointer->couples[random].s[0]=this->couples[i].s[0];
                this->couples[i].s[0]=s;
                s->make_naughty(false);
            }
            else{
                s=(pointer->couples[random].s[1]);  
                cout<<"RANDOM/DIFF: "<<random<<endl;
                this->couples[i].s[0]->make_naughty(false);
                pointer->couples[random].s[1]=this->couples[i].s[0];
                this->couples[i].s[0]=s;
                s->make_naughty(false);
            }

             pointer=this->next;
            rnd=rand()%cntr;
            while(rnd == 0)
                rnd=rand()%cntr;
            cout<<"RND IS*****************************>>>"<<rnd<<endl;
            while((rnd--) != 1 )
                pointer=pointer->next;
            
            random=rand()%pointer->couplesNumber;

            if(pointer->couples[random].s[0]->studentGender()==this->couples[i].s[1]->studentGender()){
                s=(pointer->couples[random].s[0]);  
                cout<<"RANDOM/SAME: "<<random<<endl;
                this->couples[i].s[1]->make_naughty(false);
                pointer->couples[random].s[0]=this->couples[i].s[1];
                this->couples[i].s[1]=s;
                s->make_naughty(false);
            }
            else{
                s=(pointer->couples[random].s[1]);  
                cout<<"RANDOM/SAME: "<<random<<endl;
                this->couples[i].s[1]->make_naughty(false);
                pointer->couples[random].s[1]=this->couples[i].s[1];
                this->couples[i].s[1]=s;
                s->make_naughty(false);
            }



        }
    
            cout<<"==========================================="<<endl;
    this->print();
    cout<<"==========================================="<<endl;
    }


}