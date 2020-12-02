#include "hw2.h"
#include <ctime>
#include <cstdlib>  

//--------------------------------------------------------------
Student::Student(string name,string gender,int classId){
    this->name=name;        //initialize name
    this->gender=gender;    //initialize gender
    this->classId=classId;  //initialize classId
    this->naughty=false;    //initialize naughty boolean
}

Student::~Student(){
    cout<<"I deleted a student"<<endl;
}


string Student::studentName(){          //just return student's name
    return this->name;
}

string Student::studentGender(){        //just return student's gender  
    return this->gender;
}

int Student::classroomId(){             //return the ID of the classroom that the student belongs
    return this->classId;
}
//--------------------------------------------------------------

void Sequence::connect(Sequence& sequence){     //Σύνδεση δυο ακολουθιων, της <this> και της <sequence>
      Sequence* temp=this;
      Sequence* link;

    if(this->next==NULL){                   //Αν η ακολουθία <this> δεν συνδέεται με άλλες ακολουθίες
        this->next= &sequence;              //συνδεω την <sequence> κατευθειαν
    }
    else{             //Αν η <this> συνδέεται με άλλες ακολουθίες, πάω στο τέλος της λίστας και συνδέω την νέα ακολουθια εκει
        while(temp->next != this)   //Ξερουμε τον τελευταιο κόμβο, όταν φτάσουμε στο σημείο που το μέλος next, δειχνει στην παλι στην αρχη
            temp=temp->next;        
    temp->next= &sequence;          
    }   
//Τα παρακάτω βήματα, καλύπτουν και την περίπτωση που η ακολουθία που μόλις συνδέσαμε να συνδεόταν
//και με άλλες ακολουθίες

    temp=temp->next;  //Πάω στον  πρώτο κόμβο της ακολουθίας που μόλις συνδέθηκε <sequence> και κρατάω έναν pointer σε αυτό τον κόμβο
    link=temp;                     
// Αν η ακολουθία που μόλις συνδέθηκε(<sequence>) συνδεόταν και με άλλες ακολουθίες, επείδη εχουμε κυκλικές λίστες,
//το τελευταιο της στοιχειο θα έδειχνε την "αρχη" της. Δηλαδή το <link>
    while(temp->next!=NULL && temp->next != link) {  //Αν τελικά το temp->next είναι null σημαίνει ότι η ακολουθία που μόλις
//συνδεθηκε, δεν συνδεοταν με άλλες ακολουθιες,γιατί αν συνδεόταν δεν θα ήταν null, αλλά θα έδειχνε πάλι στην αρχή της.
//Αν το temp->next όμως δείχνει στο <link>, σημαίνει πως η ακολουθία που μόλις συνδέσαμε, συνδεόταν με άλλες ακολουθίες
//για αυτο και σχημάτιζε κυκλική λίστα. Συνεπώς θα πρέπει να κάνουμε το τέλος της, να κοιτάει στην "αρχή" της γενικής ακολουθίας
        temp=temp->next;
    }

    temp->next=this;

//Αν ο αριθμός των αγορίων ή των κοριτσίων είναι κατα ένα μεγαλύτερος
    if(sequence.counterBoy > sequence.CounterGirl){    //Αν τα αγόρια είναι περισσότερα απο τα κορίτσια    
        temp=this;
        int index=0;
        while(temp->next != this){  //Ψάχνω μια ακολουθια που τα κοριτσια είναι περισσότερα
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
    }else if(sequence.counterBoy < sequence.CounterGirl){         
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
    
    if(s.studentGender()=="Boy"){  //Αν ο μαθητης που θα προσθεσουμε ειναι αγορι
        if(this->counterBoy==this->couplesNumber)   //Αν παμε να βαλουμε περισσοτερα αγορια απο οσα πρεπει
            return;     
        this->couples[this->counterBoy].s[this->tempBoy]=&s;    //Βάζουμε το αγορι
        if(tempBoy==0)  //Αν μπήκε στην θέση 0, το επόμενο αγόρι, θα μπει στην θέση 1
            this->tempBoy=1;
        else            //Αν μπήκε στην θέση 1, το επομενο αγορι θα μπει στην θεση 0
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
    delete [] this->couples;    //delete τον dymanic allocated πίνακα με τα ζευγαρια.
    
}

Sequence::Sequence(Student** students,int number,float Tquiet/*=0*/,float Tmessy/*=0*/){    

    this->Tmessy=Tmessy;    //initialize values
    this->Tquiet=Tquiet;    //ποσοστο Tquiet
    this->naughtyCounter=0; //Αρχικα ο naughtyCounter είναι 0
    this->next=NULL;        //Αρχικα δεν εχουμε αλλες ακολουθιες συνδεδεμενες
    this->id=students[0]->classroomId(); //το id της ακολουθιας ειναι το id του πρώτου μαθητη που θα προστεθει, αφου κάθε πινακας που περναμε αναπαριστα μια ταξη
    this->couples=NULL;    
    this->counterBoy=0;     //counts how many boys are
    this->CounterGirl=0;    //count how many girls are in the sequence  
    this->tempBoy=0;    //Καθε αγόρι αρχίζει απο την θέση 0, ενω καθε κοριτσι απο την θεση 1 ώστε να είναι εναλλαξ.
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
        if(this->couples[i].s[0]==NULL)
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
        cout<<"Please be quiet!"<<endl;
    
    if(this->next==NULL)
        return;

    while(temp->next != this){      //εχουμε κυκλική λίστα, άρα η επανάληψη γίνεται μέχρι να βρεθούμε πάλι στον κόμβο 
        cout<<endl;                                                                                    //που αρχίσαμε
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
        temp=temp->next;                //πήγαινε στον επόμενο κόμβο.
    }
}

void Sequence::restoreQuitness(){  //private function, it swaps students,it is called by restore function
    srand(time(NULL));          //initialize rand
    int counter=-1;             // -1 σημαίνει οτι δεν έχει βρεθει ζευγαρι ακομα.
                                //  0 σημαινει οτι έχουμε διαδοχικα ζευγαρια
                                // 1 σημαινει οτι δεν εχουμε διαδοχικα ζευγαρια

    int tom=0;                  //μετράει το συνολικο πλήθος των ζευγαριων
    int random=0;               //κραταει εναν τυχαιο αριθμο.
    Student* s;                 //κραταει έναν μαθητη
//ελέγχω αν υπάρχουν διαδοχικά ζευγαρια, και γενικα ποσα ζευγαρια υπαρχουν. βλ README
    for(int i=0;i<this->couplesNumber;i++){     //check how many couples are naughty, and if these couples are successively

        if((this->couples[i].s[0]==NULL)||(this->couples[i].s[1]==NULL)){   //Αν πέσαμε σε θέση που είναι null.
            if(counter==0){     //Αν έχουμε βρει ατακτο ζευγάρι πριν
                for(int j=i;j<this->couplesNumber;j++){ 
                    if((this->couples[i].s[0]!=NULL && this->couples[i].s[0]->is_naughty() == true) && (this->couples[i].s[1]!=NULL && this->couples[i].s[1]->is_naughty()==true))
                        counter=1;
                }
            }
            continue;
        }
        
        if(this->couples[i].s[0]->is_naughty()==true && this->couples[i].s[1]->is_naughty()==true ){    //Αν έχω άτακτο ζευγαρι
            if(counter==-1) // Αν ο counter απο -1 γίνει 0, σημαίνει οτι βρήκαμε το ΠΡΩΤΟ ατακτο ζευγάρι
                counter=0;  

            tom++;      //κρατάει πόσα ατακτα ζευγάρια έχουμε βρει συνολικά
        }
        else if((this->couples[i].s[0]->is_naughty()==false && this->couples[i].s[1]->is_naughty()==true)
        ||(this->couples[i].s[0]->is_naughty()==true && this->couples[i].s[1]->is_naughty()==false)
        || (this->couples[i].s[0]->is_naughty()==false && this->couples[i].s[1]->is_naughty()==false)){
//Αν έχω ηδη βρει πριν ατακτο ζευγαρι σημαινει οτι ο counter==0. Επομενως αν βρηκα ΜΗ ΑΤΑΚΤΟ ζευγαρι τώρα, θα πρέπει να ελενξω  αν
// υπαρχει και άλλο άτακτο ζευγαρι στην συνεχεια. Αν υπάρχει, σημαινει οτι δεν έχουμε διαδοχικά ζευγαρια και ο counter γίνεται 1.
            if(counter==0){     //Αν έχουμε βρει ήδη άτακτο ζευγάρι πριν και ο counter ΔΕΝ ΕΙΝΑΙ 1
                for(int j=i;j<this->couplesNumber;j++){ //ελέγχω τα υπολοιπα στοιχεια του πινακα για ατακτο ζευγαρι
                    if((this->couples[i].s[0]!=NULL && this->couples[i].s[0]->is_naughty() == true) && (this->couples[i].s[1]!=NULL && this->couples[i].s[1]->is_naughty()==true))
                        counter=1;  //Αν βρω αργοτερα ατακτο ζευγαρι, σημαινει οτι δεν εχω διαδοχικα ατακτα, αλλα διασπαρτα.
                }
            }           

        }
    }
    if(this->next==NULL && tom >=2)    //ΣΕ ΠΕΡΙΠΤΩΣΗ ΠΟΥ ΕΧΟΥΜΕ ΠΑΝΩ ΑΠΟ ΔΥΟ ΑΤΑΚΤΑ ΖΕΥΓΑΡΙΑ ΣΕ ΜΙΑ ΤΑΞΗ, ΑΛΛΑ ΔΕΝ ΕΧΟΥΜΕ ΑΚΟΛΟΥΘΙΑ ΤΜΗΜΑΤΩΝ
        return;     //ΔΗΛΑΔΗ ΥΠΑΡΧΕΙ ΜΟΝΟ ΜΙΑ ΑΚΟΛΟΥΘΙΑ ΣΥΝΟΛΙΚΑ, ΜΙΑΣ ΚΑΙ ΔΕΝ ΛΕΕΙ ΚΑΤΙ Η ΕΚΦΩΝΗΣΗ, ΚΑΝΩ ΑΠΛΑ RETURN KAI ΔΕΝ ΓΙΝΕΤΑΙ RESTORE
    

    for(int i=0;i<this->couplesNumber;i++){ //κοιταω καθε μαθητη σε καθε ζευγαρι, αν ειναι ατακτος ή αν το ζευγαρι ειναι ατακτο

        if((((this->couples[i].s[1]==NULL) ||this->couples[i].s[1]->is_naughty()==false)) && (this->couples[i].s[0] != NULL &&(this->couples[i].s[0]->is_naughty()==true))){  //Aν ένας απο τους δύο ειναι ατακτος
            cout<<"Student : "<<this->couples[i].s[0]->studentName()<<" changed position"<<endl;    //Εκτυπωσε ποιος ειναι
            random=rand()%this->couplesNumber;     //Διαλεξε εναν τυχαιο μαθητη απο την ιδια ακολουθια, του ιδιου φυλου
            while((random==i) || ((this->couples[random].s[1]==NULL )|| (this->couples[random].s[0]==NULL))) //αν διαλεξες τον ιδιο μαθητη ή διαλεξες θέση απο δεν υπαρχει μαθητης
                random=rand()%this->couplesNumber;  //Διαλεξε αλλον.

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
                s->make_naughty(false); // και τον κάνω ήσυχο

                cout<<"^^^^^^^^^^^^^^^^^^^^"<<endl;
            }
            else{       //αλλιώς κάνω την ίδια διαδικασια με τον άλλον τυχαίο μαθητη
                s=(this->couples[random].s[1]);  
                this->couples[i].s[0]->make_naughty(false);
                this->increase_counter(*(this->couples[i].s[0]),1);
                this->couples[random].s[1]=this->couples[i].s[0];
                this->couples[i].s[0]=s;
                cout<<"--------------------"<<endl;
                this->printSequence();
                if(s->is_naughty()==true){
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
        //Αν υπάρχει ατακτο ζευγαρι, αλλα είναι ή 1 ή 2 κάνω ουσιαστικα ότι και πριν, αλλα και για τους 2 μαθητες.
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
        //Αν υπάρχει ατακτο ζευγαρι, αλλα το συνολο των ατακτων ζευγαριων ειναι πάνω απο 2
        //Κάνω το ίδιο με πριν, με την μόνη διαφορα οτι επιλέγω τυχαιο μαθητη απο την επόμενη ακολουθια
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
        //Αν έχω διαδοχικά ζευγαρια κανω ότι και πριν, αλλα αλλάζω με τυχαιο μαθητη απο τυχαια ακολουθια
        else if((this->couples[i].s[0] !=NULL && this->couples[i].s[0]->is_naughty()==true) &&(tom>2 && counter == 0)){       //Αφου ειναι ζευγαρι δεν εχει σημασια αν θα ειναι ο πρωτος ή ο δευτερος
            
            for(int j=0;j<2;j++){
                int cntr=1; //Μετραει ποσες ακολουθιες συνδεονται με την παρουσα ακολουθια
                int rnd=0;  //κραταει τον τυχαιο αριθμο απο την rands
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
                    this->printSequence();
                    cout<<"--------------------"<<endl;
                    if(s->is_naughty()==true){
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
                    this->printSequence();
                    cout<<"--------------------"<<endl;
                    if(s->is_naughty()==true){
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


void Sequence::restore(){   //Καλει την restoreSequence για κάθε ακολουθία που συνδέεται με την this
    Sequence* temp=this;
    this->restoreQuitness();

    if(this->next==NULL)    //Αν η ακολουθια δεν συνδεοταν με καμια αλλη ακολουθια
        return;

    while(temp->next != this){ //Κάλεσε επαναληπτικα την restoreQuitness() μέχρι να ξαναβρεθεις στον αρχικο κόμβο
        temp->next->restoreQuitness();
        temp=temp->next;
    }
}

void Sequence::increase_counter(Student& s, int number){        //βλ. README
// Απλα μια συναρτηση που αυξανει τον μετρητη naughty counter της ακολουθιας, της ταξης του μαθητη που αντιμετατεθηκε

    Sequence* temp=this;    
    if(this->id == s.classroomId()){    //Αν ο μαθητης που αντιμετατεθηκε ήταν ήδη στην ακολουθια της ταξης του
        this->naughtyCounter=this->naughtyCounter+ number;
        return;
    }
    temp=temp->next;    //Αν δεν ηταν, ψαξε που ειναι
    while(temp != this){
        if(temp->id == s.classroomId()){    //Αν τον βρεις, αυξησε τον μετρητη της ακολουθιας της ταξης του
            temp->naughtyCounter= temp->naughtyCounter+ number;
            return;
        }
        temp=temp->next;    //Αν δεν τον βρεις, ψαξε παρακατω στην λίστα.
    }
    

    return;
}



