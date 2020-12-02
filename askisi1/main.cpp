#include "infrastructures.h"
#include <ctime>
#include <cstdlib>  
#include <sstream>

const int N=18;    	//σταθερα. Φτιαχνονται 18*Cclass μαθητες και 18 δασκαλοι 
			//καθως έχουμε 18 ταξεις

int main(int argc, char* argv[]){
    int Cclass=atoi(argv[1]); //default ορισματα απο την γραμμη εντολης      
    int Cyard =atoi(argv[2]);
    int Cstair=atoi(argv[3]);
    int Ccorr=atoi(argv[4]);


    srand(time(NULL));	//Αρχικοποιηση γεννητριας τυχαιων αριθμων.
    
    School school(Cclass,Cyard,Cstair,Ccorr);       //create a school
    Student* stud[N*Cclass];                        //create an array to keep students
    Teacher* teachers[18];                          //create an array to keep teachers
    int count=0;                                
    for(int i=0;i<Cclass;i++){                      // create students and save them to an array

        for(int j=0;j<3;j++){	//Δημιουργια μαθητων
            for(int k=0;k<6;k++){
                stud[count]=new Student("Student "+to_string(count),j,k);
                count++;
            }
        }
    }
        count=0;
        for(int j=0;j<3;j++){	//Δημιουργία δασκάλων
            for(int k=0;k<6;k++){
                teachers[count]=new Teacher("Teacher "+ to_string(count),j,k);
                count++;
            }
        }



    int end=Cclass*N;
    int div=18;
    int temp=0;
    int counter=0;
    int i=0;
    Student* s;
    while(end!=0){


        temp=rand()%(Cclass*N);                 //επιλεγω τυχαιο αριθμο που θα μπουνε στο yard

        for(int k=0;k<temp;k++){
            if(counter+Cclass*N==0)             //Αν μπήκαν όλοι οι μαθητες, αυτο θα είναι 0
                break;
            
            i=rand()%(Cclass*N + counter);        //αριθμος μαθητων συνολικος, επιλεγω εναν μαθητη
           
            
                 s=stud[i];
                stud[i]=stud[Cclass*N-1+counter];    //τον βαζω στο τελος για να μην τον ξαναπαρω
                stud[Cclass*N-1+counter]=s;
                counter--;                      //Για κάθε νέο μαθητή που βάζω, το μειώνω ωστε να μην ξανα παρω τον ιδιο μαθητη.
                school.enter(*s);               //βαζω στο yard τον μαθητη αν χωραει
                end--;		//Αν το end γινει 0, σημαινει οτι εχουν εξεταστει όλοι οι μαθητες
                			//και αρα τελειωνει το προγραμμα(βλ README για περισσοτερες λεπτομερειες)
        }

        if(div==0)      //Αν εχουν μπει όλοι οι καθηγητες στην τάξη τους, πρέπει να ελένξουμε και τους μαθητές
            continue;

        i=rand()%2;	//Με πιθανοτητα 50% ή επιλεγω να βαλω καθηγητη στην προκειμενη επαναληψη ή οχι.
        if(i==1 && div>=1){
            int times=rand()%div;	//ποσους καθηγητες θα βαλω.
            for(int k=0;k<=times;k++){
                i=rand()%div;		//Ποιον καθηγητη θα βαλω.
                school.place(*(teachers[i]));
                Teacher* temp= teachers[i];
                teachers[i]=teachers[div-1];	//Ο καθηγητης που κληθηκε απο την place, μπαινει στο τελος του
                teachers[div-1]=temp;		//πινακα των καθηγητων, ωστε να μην ξαναεπιλεχθει.
                div--; 
            }
        }
        
    }



    school.print();  //εκτυπωση σχολικης δομης

//ειναι ευθύνη του χρήστη να αποδεσμεύεσει τους μαθητές και τους δασκάλους
    for(int i=0;i<Cclass*N;i++)
        delete stud[i];
    
    for(int i=0;i<N;i++)
        delete teachers[i];

}
