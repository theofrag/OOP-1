#include "infrastructures.h"
#include <ctime>
#include <cstdlib>  
#include <sstream>


string int_to_string(const string& str, int number) {      
  ostringstream oss;
  oss << str << number;
  return oss.str();
}

const int N=18;     



int main(int argc, char* argv[]){
    int Cclass=atoi(argv[1]);       
    int Cyard =atoi(argv[2]);
    int Cstair=atoi(argv[3]);
    int Ccorr=atoi(argv[4]);


    srand(time(NULL));
    
    School school(Cclass,Cyard,Cstair,Ccorr);       //create a school
    Student* stud[N*Cclass];                        //create an array to keep students
    Teacher* teachers[18];                          //create an array to keep teachers
    int count=0;                                
    for(int i=0;i<Cclass;i++){                      // create students and save them to an array

        for(int j=0;j<3;j++){
            for(int k=0;k<6;k++){
                stud[count]=new Student(int_to_string("Student ",count),j,k);
                count++;
            }
        }
    }
        count=0;
        for(int j=0;j<3;j++){
            for(int k=0;k<6;k++){
                teachers[count]=new Teacher(int_to_string("Student ",count),j,k);
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


        temp=rand()%(Cclass*N);                 //επιλεγω τυχαιο αριθμο που θα μπουνε στο yar

        for(int k=0;k<temp;k++){
            if(counter+Cclass*N==0)
                break;
            
            i=rand()%(Cclass*N + counter);        //αριθμος μαθητων συνολικος επιλεγω εναν μαθητη
           
            
                 s=stud[i];
                stud[i]=stud[Cclass*N-1+counter];    //τον βαζω στο τελος για να μην τον ξαναπαρω
                stud[Cclass*N-1+counter]=s;
                counter--;
                school.enter(*s);               //βαζω στο yard τον μαθητη αν χωραει
                end--;
        }

        if(div==0)      //Αν εχουν μπει όλοι οι καθηγητες στην τάξη τους
            continue;

        i=rand()%2;
        if(i==1 && div>=1){
            int times=rand()%div;
            for(int k=0;k<=times;k++){
                i=rand()%div;
                school.place(*(teachers[i]));
                Teacher* temp= teachers[i];
                teachers[i]=teachers[div-1];
                teachers[div-1]=temp;
                div--; 
            }
        }
        
    }



    school.print();  
        
    for(int i=0;i<Cclass*N;i++)
        delete stud[i];
    
    for(int i=0;i<N;i++)
        delete teachers[i];

}