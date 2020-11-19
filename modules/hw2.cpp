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

Student::~Student(){
    cout<<"I deleted a student"<<endl;
}


string Student::studentName(){      //just return student's name
    return this->name;
}

string Student::studentGender(){      //just return student's gender  
    return this->gender;
}

int Student::classroomId(){             //just return the ID of the classroom that the student belongs
    return this->classId;
}
//--------------------------------------------------------------

void Sequence::connect(Sequence& sequence){     //connect 2 sequences
      Sequence* temp=this;
      Sequence* link;

    if(this->next==NULL){
        this->next= &sequence;
    }
    else{
        while(temp->next != this)
            temp=temp->next;        //go at the end of the current sequence
    temp->next= &sequence;          //add the new sequence
    }
//Τα παρακάτω βήματα, γίνονται για την περίπτωση που η ακολουθία που μόλις συνδέσαμε να συνδεόταν
//και με άλλες ακολουθίες

    temp=temp->next;                //Πάω στον  πρώτο κόμβο της ακολουθίας που μόλις συνδέθηκε και
    link=temp;                      //κρατάω έναν pointer σε αυτό τον κόμβο
// Αν η ακολουθία που μόλις συνδέθηκε, συνδεόταν και με άλλες ακολουθίες, επείδη εχουμε κυκλικές λίστες
//το τελευταιο της στοιχειο θα έδειχνε την "αρχη" της. Δηλαδή το <link>
    while(temp->next!=NULL && temp->next != link) {  //Αν τελικά το temp->next είναι null σημαίνει ότι η ακολουθία που μόλις
//συνδεθηκε, δεν συνδεοταν με άλλες ακολουθιες,γιατί αν συνδεόταν δεν θα ήταν null, αλλά θα έδειχνε πάλι στην αρχή της.
//Αν το temp->next όμως δείχνει στο <link>, σημαίνει πως η ακολουθία που μόλις συνδέσαμε, συνδεόταν με άλλες ακολουθίες
//για αυτο και σχημάτιζε κυκλική λίστα. Συνεπώς θα πρέπει να κάνουμε το τέλος της, να κοιτάει στην "αρχή" της γενικής ακολουθίας
        temp=temp->next;
    }

    temp->next=this;

//Αν ο αριθμός των αγορίων ή των κοριτσίων είναι κατα ένα μεγαλύτερος
    if(sequence.counterBoy > sequence.CounterGirl){    //if odd number of students     
        temp=this;
        int index=0;
        while(temp->next != this){
            if((temp->counterBoy < temp->CounterGirl) ){
                if(sequence.counterBoy%2==0)
                    index=1;
                temp->add_student(*(sequence.couples[counterBoy].s[index]));
                sequence.counterBoy--;
                sequence.couplesNumber--;
                break;
            }
            temp=temp->next;
        }
    }else if(sequence.counterBoy < sequence.CounterGirl){    //if odd number of students     
        temp=this;
        int index=1;
        while(temp->next != this){
            if((temp->counterBoy > temp->CounterGirl) ){
                if(sequence.CounterGirl%2 == 0)
                    index=0;

                temp->add_student(*(sequence.couples[CounterGirl].s[index]));
                sequence.CounterGirl--;
                sequence.couplesNumber--;
                break;
            }
            temp=temp->next;
        }
    }         
}


void Sequence::add_student(Student& s){
    
    if(s.studentGender()=="Boy"){  //if student that is about to be added is boy
        if(this->counterBoy==this->couplesNumber)   //Αν παμε να βαλουμε περισσοτερα αγορια απο οσα πρεπει
            return;
        this->couples[this->counterBoy].s[this->tempBoy]=&s;    //add him
        if(tempBoy==0)
            this->tempBoy=1;
        else
            this->tempBoy=0;
        (this->counterBoy)++;       //increace counter

    }else{
        if(this->CounterGirl==this->couplesNumber)  //Αν παμε να βαλουμε περισσοτερα κοριτσια απο οσα πρεπει
            return;
        this->couples[this->CounterGirl].s[this->tempGirl]=&s;
        if(tempGirl==0)
            this->tempGirl=1;
        else
            this->tempGirl=0;
        (this->CounterGirl)++;
    }
    
}
Sequence:: ~Sequence(){
    delete [] this->couples;
    
}

Sequence::Sequence(Student** students,int number,float Tquiet/*=0*/,float Tmessy/*=0*/){    

    this->Tmessy=Tmessy;    //initialize values
    this->Tquiet=Tquiet;
    this->naughtyCounter=0;
    this->next=NULL;        //at first sequence does not point to other sequences
    this->id=students[0]->classroomId();    //sequence id, is the id of the first student, who will be added
    this->couples=NULL;
    this->counterBoy=0; //counts how many boys are
    this->CounterGirl=0;    //count how many girls are in the sequence  
    this->tempBoy=0;    
    this->tempGirl=1;
    

    if(number%2==0){    //if the number of students is even
        this->couples=new Couples[number/2];    //allocate space for the couples
        this->couplesNumber=number/2;
    }else{              //if the number of students is odd
        this->couples=new Couples[number/2+1];
        this->couplesNumber=number/2+1;
    }

    for(int i=0;i<this->couplesNumber;i++){ //before the addition of the students initialize the couples array
        this->couples[i].s[0]= NULL;
        this->couples[i].s[1]= NULL;

    }

    for(int i=0;i<number;i++)               //now add all the students
        this->add_student(*(students[i]));
    
}

void Sequence::printSequence(){     //print the current sequence

    for(int i=0;i<this->couplesNumber;i++){
        if(this->couples[i].s[0]==NULL)      //if this place, doesn't point to a student
            cout<<"NULL     ";
        else
            cout<<this->couples[i].s[0]->studentName()<<"  and  ";
        if(this->couples[i].s[1]==NULL)
            cout<<"NULL"<<endl;
        else
            cout<<this->couples[i].s[1]->studentName()<<endl;
    
    }

}


void Sequence::print(){         //print all the sequences that are linked with the current sequence

    Sequence* temp=this;
    for(int i=0;i<this->couplesNumber;i++){
        if(this->couples[i].s[0]==NULL)
            cout<<"NULL     ";
        else
            cout<<this->couples[i].s[0]->studentName()<<"  and  ";
        if(this->couples[i].s[1]==NULL)
            cout<<"NULL"<<endl;
        else
            cout<<this->couples[i].s[1]->studentName()<<endl;
    
    }
    if(this->naughtyCounter <((this->counterBoy+this->CounterGirl)*this->Tquiet))
        cout<< "What a quiet class"<<endl;
    else if(this->naughtyCounter >((this->counterBoy+this->CounterGirl)*this->Tmessy))
        cout<<"What a mess!"<<endl;
    else
        cout<<"Plese be quiet!"<<endl;
    
    if(this->next==NULL)
        return;

    while(temp->next != this){ 
        cout<<endl;
        for(int i=0;i<temp->next->couplesNumber;i++){

            if(temp->next->couples[i].s[0]==NULL)
                cout<<"NULL     ";
            else
                cout<<temp->next->couples[i].s[0]->studentName()<<"  and  ";

            if(temp->next->couples[i].s[1]==NULL)
                cout<<"NULL"<<endl;  
            else
                cout<<temp->next->couples[i].s[1]->studentName()<<endl;
        
        
        }
        if(this->naughtyCounter <((this->counterBoy+this->CounterGirl)*this->Tquiet))
            cout<< "What a quiet class"<<endl;
        else if(this->naughtyCounter >((this->counterBoy+this->CounterGirl)*this->Tmessy))
            cout<<"What a mess!"<<endl;
         else
            cout<<"Please be quiet!"<<endl;
        temp=temp->next;
    }
}

void Sequence::restoreQuitness(){       //private function, it swaps students, called by restore function
    srand(time(NULL));       //initialize rand
    int counter=-1;
    int tom=0;
    int random=0;
    Student* s;
//Στις γραμμές 226-257 ελέγχω αν υπάρχουν διαδοχικά ζευγαρια, και γενικα ποσα ζευγαρια υποαρχουν. βλ README
    for(int i=0;i<this->couplesNumber;i++){     //first check how many couples are naughty, and if these couples are successively

        if((this->couples[i].s[0]==NULL)||(this->couples[i].s[1]==NULL)){
            if(counter==0){
                for(int j=i;j<this->couplesNumber;j++){
                    if(this->couples[j].s[0]->is_naughty()==true && this->couples[j].s[1]->is_naughty()==true )
                        counter=1;
                }
            }
            continue;
        }
        
        if(this->couples[i].s[0]->is_naughty()==true && this->couples[i].s[1]->is_naughty()==true ){    //if both members of a couple are naughty
            if(counter==-1) //practically this condition checks if the naughty couples are serial
                counter=0;  
                  //αν εχουμε συνεχομενες ακολουθιες που κανουν αταξιες
            tom++;      //counts naughty couples
        }
        else if((this->couples[i].s[0]->is_naughty()==false && this->couples[i].s[1]->is_naughty()==true)
        ||(this->couples[i].s[0]->is_naughty()==true && this->couples[i].s[1]->is_naughty()==false)
        || (this->couples[i].s[0]->is_naughty()==false && this->couples[i].s[1]->is_naughty()==false)){
            if(counter==0){     //if a there is already a naugthy couple
                for(int j=i;j<this->couplesNumber;j++){
                    if(this->couples[j].s[0]->is_naughty()==true && this->couples[j].s[1]->is_naughty()==true )
                        counter=1;
                }
            }           

        }
    }
    if(this->next==NULL && tom >=2)    //ΣΕ ΠΕΡΙΠΤΩΣΗ ΠΟΥ ΕΧΟΥΜΕ ΠΑΝΩ ΑΠΟ ΔΥΟ ΑΤΑΚΤΑ ΖΕΥΓΑΡΙΑ ΣΕ ΜΙΑ ΤΑΞΗ, ΑΛΛΑ ΔΕΝ ΕΧΟΥΜΕ ΑΚΟΛΟΥΘΙΑ ΤΜΗΜΑΤΩΝ
        return;     //ΔΗΛΑΔΗ ΥΠΑΡΧΕΙ ΜΟΝΟ ΜΙΑ ΑΚΟΛΟΥΘΙΑ ΣΥΝΟΛΙΚΑ, ΜΙΑΣ ΚΑΙ ΔΕΝ ΛΕΕΙ ΚΑΤΙ Η ΕΚΦΩΝΗΣΗ, ΚΑΝΩ ΑΠΛΑ RETURN KAI ΔΕΝ ΓΙΝΕΤΑΙ RESTORE
    

    for(int i=0;i<this->couplesNumber;i++){ //κοιταω καθε μαθητη σε καθε ζευγαρι, αν ειναι ατακτος
                                            //ή αν το ζευγαρι ειναι ατακτο
        if((((this->couples[i].s[1]==NULL) ||this->couples[i].s[1]->is_naughty()==false)) && (this->couples[i].s[0] != NULL &&(this->couples[i].s[0]->is_naughty()==true))){  //if one out of two kids is naughty
            cout<<"Student : "<<this->couples[i].s[0]->studentName()<<" changed position"<<endl;    //print msg
            random=rand()%this->couplesNumber;     //choose a random,same gender kid to swap
            while((random==i) || ((this->couples[random].s[1]==NULL )|| (this->couples[random].s[0]==NULL))) 
                random=rand()%this->couplesNumber;

            //Αν το φυλο του τυχαιου μαθητη στην θεση 0 του πινακα, είναι ίδιο με το φύλο του ατακτου μαθητη
            if(this->couples[random].s[0]->studentGender()==this->couples[i].s[0]->studentGender()){
                s=(this->couples[random].s[0]);  //αποθηκευω τον τυχαιο μαθητη
                this->couples[i].s[0]->make_naughty(false); //κανω τον ατακτο, ησυχο
                this->increase_counter(*(this->couples[i].s[0]),1); //αυξανω τον naughty counter, της τάξης του ατακτου μαθητη κατα 1
                this->couples[random].s[0]=this->couples[i].s[0];   //αλλαζω τις θεσεις τους
                this->couples[i].s[0]=s;
                cout<<"--------------------"<<endl;
                this->printSequence();  //εκτυπωνω την ακολουθια που επηρεαστηκε
                if(s->is_naughty()==true){  //αν ο τυχαιος μαθητης που αλλαξε ηταν ατακτος
                        this->increase_counter(*s,1); //αυξανω τον naughty counter της ταξης του κατα 1
                        cout<<"Student : "<<s->studentName()<<" was naughty and changed position after replace with a naughty kid"<<endl;
                }
                s->make_naughty(false); // τον κάνω ήσυχο

                cout<<"^^^^^^^^^^^^^^^^^^^^"<<endl;
            }
            else{       //αλλιώς κάνω την ίδια διαδικασια με τον άλλον τυχαίο μαθητη
                s=(this->couples[random].s[1]);  
                this->couples[i].s[0]->make_naughty(false);
                this->increase_counter(*(this->couples[i].s[0]),1);
                this->couples[random].s[1]=this->couples[i].s[0];
                this->couples[i].s[0]=s;
                // this->naughtyCounter++;
                cout<<"--------------------"<<endl;
                this->printSequence();
                if(s->is_naughty()==true){
                        // this->naughtyCounter++;
                        this->increase_counter(*s,1);
                        cout<<"Student : "<<s->studentName()<<" was naughty and changed position after replace with a naughty kid"<<endl;
                }
                s->make_naughty(false);

                cout<<"^^^^^^^^^^^^^^^^^^^^"<<endl;
            }
            continue;
        }
        //Όμοια με το προηογουμενο
        else if((( (this->couples[i].s[0]==NULL) ||this->couples[i].s[0]->is_naughty()==false)) && (this->couples[i].s[1] != NULL &&(this->couples[i].s[1]->is_naughty()==true))){  //if one out of two kids is naughty
            cout<<"Student : "<<this->couples[i].s[1]->studentName()<<" changed position"<<endl;
            random=rand()%this->couplesNumber;     //choose a random,same gender kid to swap
            while((random==i) || (this->couples[random].s[0]==NULL) || (this->couples[random].s[1]==NULL))
                random=rand()%this->couplesNumber;
            
            if(this->couples[random].s[0]->studentGender()==this->couples[i].s[1]->studentGender()){
                s=(this->couples[random].s[0]);  

                this->couples[i].s[1]->make_naughty(false);
                this->increase_counter(*(this->couples[i].s[1]),1);
                this->couples[random].s[0]=this->couples[i].s[1];
                this->couples[i].s[1]=s;

                // this->naughtyCounter++;
                cout<<"--------------------"<<endl;
                this->printSequence();
                if(s->is_naughty()==true){
                        // this->naughtyCounter++;
                        this->increase_counter(*s,1);
                        cout<<"Student : "<<s->studentName()<<" was naughty and changed position after replace with a naughty kid"<<endl;
                }
                s->make_naughty(false);
                cout<<"^^^^^^^^^^^^^^^^^^^^"<<endl;
            }
            else{
                s=(this->couples[random].s[1]);  

                this->couples[i].s[1]->make_naughty(false);
                this->increase_counter(*(this->couples[i].s[1]),1);
                this->couples[random].s[1]=this->couples[i].s[1];
                this->couples[i].s[1]=s;

                // this->naughtyCounter++;
                cout<<"--------------------"<<endl;
                this->printSequence();  
                if(s->is_naughty()==true){
                        // this->naughtyCounter++;
                        this->increase_counter(*s,1);
                        cout<<"Student : "<<s->studentName()<<" was naughty and changed position after replace with a naughty kid"<<endl;
                }
                s->make_naughty(false);

                cout<<"^^^^^^^^^^^^^^^^^^^^"<<endl;
            }
            continue;
        }
        //Ιf there is a naughty couple, but the total of naughty couples is less or equal than 2
        else if((tom>0 &&tom<=2 )&& ((this->couples[i].s[0]!=NULL && this->couples[i].s[0]->is_naughty() == true) && (this->couples[i].s[1]!=NULL && this->couples[i].s[1]->is_naughty()==true))){
            for(int j=0;j<2;j++){
                cout<<"Student : "<<this->couples[i].s[j]->studentName()<<" changed position"<<endl;
                
                random=rand()%this->couplesNumber;
                while((random==i) || (this->couples[random].s[0]==NULL) || (this->couples[random].s[1]==NULL))
                    random=rand()%this->couplesNumber;

                if(this->couples[random].s[0]->studentGender()==this->couples[i].s[j]->studentGender()){
                    s=(this->couples[random].s[0]);  
                    this->couples[i].s[j]->make_naughty(false);
                    this->increase_counter(*(this->couples[i].s[j]),1);
                    this->couples[random].s[0]=this->couples[i].s[j];
                    this->couples[i].s[j]=s;
                    if(s->is_naughty()==true){
                        this->increase_counter(*s,1);
                        cout<<"Student : "<<s->studentName()<<" was naughty and changed position after replace with a naughty kid"<<endl;
                    }
                    s->make_naughty(false);
                    cout<<"--------------------"<<endl;
                    this->printSequence();
                    cout<<"^^^^^^^^^^^^^^^^^^^^"<<endl;
                }
                else{
                    s=(this->couples[random].s[1]);  
                    this->couples[i].s[j]->make_naughty(false);
                    this->increase_counter(*(this->couples[i].s[j]),1);
                    this->couples[random].s[1]=this->couples[i].s[j];
                    this->couples[i].s[j]=s;

                    if(s->is_naughty()==true){
                        this->increase_counter(*s,1);
                        cout<<"Student : "<<s->studentName()<<" was naughty and changed position after replace with a naughty kid"<<endl;
                    }
                    s->make_naughty(false);
                    cout<<"--------------------"<<endl;
                    this->printSequence();
                    cout<<"^^^^^^^^^^^^^^^^^^^^"<<endl;
                }

            }
       
            
        }
        //if there is naughty couple, but the total of naughty couples is 3 or more
        //the onlu difference is that we change with students from the next sequence
        else if((tom>2 && counter==1) && ((this->couples[i].s[0]!=NULL && this->couples[i].s[0]->is_naughty() == true) && (this->couples[i].s[1]!=NULL && this->couples[i].s[1]->is_naughty()==true))){ 

            for(int j=0;j<2;j++){
                cout<<"Student : "<<this->couples[i].s[j]->studentName()<<" changed position with the next sequence"<<endl;
                random=rand()%this->next->couplesNumber;
                while((this->next->couples[random].s[0]==NULL) || (this->next->couples[random].s[1]==NULL))                                                                                  
                    random=rand()%this->next->couplesNumber;
                if(this->couples[random].s[0]->studentGender()==this->couples[i].s[j]->studentGender()){
                    s=(this->next->couples[random].s[0]);

                    this->couples[i].s[j]->make_naughty(false);
                    this->increase_counter(*(this->couples[i].s[j]),2);
                    this->next->couples[random].s[0]=this->couples[i].s[j];
                    this->couples[i].s[j]=s;
                    // this->naughtyCounter=this->naughtyCounter+2;
                    this->printSequence();
                    cout<<"--------------------"<<endl;
                    if(s->is_naughty()==true){
                        // this->next->naughtyCounter=this->next->naughtyCounter+2;
                        this->increase_counter(*s,2);
                        cout<<"Student : "<<s->studentName()<<" changed position after replace from a different classroom"<<endl;
                    }
                    s->make_naughty(false);
                    this->next->printSequence();
                    cout<<"^^^^^^^^^^^^^^^^^^^^"<<endl;
                }else{
                    s=(this->next->couples[random].s[1]);  

                    this->couples[i].s[j]->make_naughty(false);
                    this->increase_counter(*(this->couples[i].s[j]),2);
                    this->next->couples[random].s[1]=this->couples[i].s[j];
                    this->couples[i].s[j]=s;
                    // this->naughtyCounter=this->naughtyCounter+2;
                    this->printSequence();
                    cout<<"--------------------"<<endl;
                    if(s->is_naughty()==true){
                        // this->next->naughtyCounter=this->next->naughtyCounter+2;
                        this->increase_counter(*s,2);
                        cout<<"Student : "<<s->studentName()<<" changed position after replace from a different classroom"<<endl;
                    }
                    s->make_naughty(false);
                    this->next->printSequence();
                    cout<<"^^^^^^^^^^^^^^^^^^^^"<<endl;
                }

            }     
           

        }

        else if((this->couples[i].s[0] !=NULL && this->couples[i].s[0]->is_naughty()==true) &&(tom>2 && counter == 0)){       //Αφου ειναι ζευγαρι δεν εχει σημασια αν θα ειναι ο πρωτος ή ο δευτερος
            
            for(int j=0;j<2;j++){
                int cntr=1;
                int rnd=0;
                Sequence* pointer;
                pointer=this->next;
                while(pointer->next != this){       //μετραω το πληθος των ακολουθιων
                    pointer=pointer->next;
                    cntr++;
                }
                pointer=this->next; //produce a random number
                rnd=rand()%(cntr+1);
            
                if(cntr != 1){
                    while(rnd == 0)
                        rnd=rand()%(cntr+1); //poia thesi stin lista

                    while((rnd--) != 1 )
                        pointer=pointer->next;
                }
                
                
                random=rand()%pointer->couplesNumber;
                while((pointer->couples[random].s[0]==NULL) || (pointer->couples[random].s[1]==NULL))                                                                                  
                    random=rand()%pointer->couplesNumber;

                cout<<"Student : "<<this->couples[i].s[j]->studentName()<<" changed position with a random sequence"<<endl;
                if(pointer->couples[random].s[0]->studentGender()==this->couples[i].s[j]->studentGender()){
                    s=(pointer->couples[random].s[0]);  
                    this->couples[i].s[j]->make_naughty(false);
                    this->increase_counter(*(this->couples[i].s[j]),2);
                    pointer->couples[random].s[0]=this->couples[i].s[j];
                    this->couples[i].s[j]=s;
                    // this->naughtyCounter=this->naughtyCounter+2;
                    this->printSequence();
                    cout<<"--------------------"<<endl;
                    if(s->is_naughty()==true){
                        // pointer->naughtyCounter=pointer->naughtyCounter+2;
                        this->increase_counter(*s,2);
                        cout<<"Student : "<<s->studentName()<<" changed position after replace from a different classroom"<<endl;
                    }
                    s->make_naughty(false);
                    pointer->printSequence();
                    cout<<"^^^^^^^^^^^^^^^^^^^^"<<endl;
                }
                else{
                    s=(pointer->couples[random].s[1]);  
                    this->couples[i].s[j]->make_naughty(false);
                    this->increase_counter(*(this->couples[i].s[j]),2);
                    pointer->couples[random].s[1]=this->couples[i].s[j];
                    this->couples[i].s[j]=s;
                    // this->naughtyCounter=this->naughtyCounter+2;
                    this->printSequence();
                    cout<<"--------------------"<<endl;
                    if(s->is_naughty()==true){
                        // pointer->naughtyCounter=pointer->naughtyCounter+2;
                        this->increase_counter(*s,2);
                        cout<<"Student : "<<s->studentName()<<" changed position after replace from a different classroom"<<endl;
                    }
                    s->make_naughty(false);
                    pointer->printSequence();
                    cout<<"^^^^^^^^^^^^^^^^^^^^"<<endl;
                    
                }
                
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

void Sequence::increase_counter(Student& s, int number){

    Sequence* temp=this;
    if(this->id == s.classroomId()){
        this->naughtyCounter=this->naughtyCounter+ number;
        return;
    }
    temp=temp->next;
    while(temp != this){
        if(temp->id == s.classroomId()){
            temp->naughtyCounter= temp->naughtyCounter+ number;
            return;
        }
        temp=temp->next;
    }
    

    return;
}



