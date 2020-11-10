#include "infrastructures.h"
#include <ctime>
#include <cstdlib>  




const int N=18;     



int main(int argc, char** argv){
    int Cclass=1;//atoi(argv[1]);
    int Cyard =5;
    int Cstair=17;//atoi(argv[3]);
    int Ccorr=10;//atoi(argv[4]);


    srand(time(nullptr));
    
    School school(Cclass,Cyard,Cstair,Ccorr);
    Student* stud[N*Cclass];
    Teacher* teachers[18];
    int count=0;
    for(int i=0;i<Cclass;i++){

        for(int j=0;j<3;j++){
            for(int k=0;k<6;k++){
                stud[count]=new Student("student "+ to_string(count),j,k);
                count++;}
        }
    }
        count=0;
        for(int j=0;j<3;j++){
            for(int k=0;k<6;k++){
                teachers[count]=new Teacher("Teacher "+ to_string(count),j,k);
                count++;
            }
        }



    int end=2;
    int div=18;
    int temp=0;
    int counter=0;
    int i=0;
    Student* s;
    while(end!=0){
        end=0;

        temp=rand()%(Cclass*N);                 //επιλεγω τυχαιο αριθμο που θα μπουνε στο yar

        for(int k=0;k<temp;k++){
            if(counter+Cclass*N==0)
                break;
            
            i=rand()%(Cclass*N + counter);        //αριθμος μαθητων συνολικος επιλεγω εναν μαθητη
           
            if(school.get_schoolyard().get_available_space()>0){
                 s=stud[i];
                stud[i]=stud[Cclass*N-1+counter];    //τον βαζω στο τελος για να μην τον ξαναπαρω
                stud[Cclass*N-1+counter]=s;
                counter--;
                school.enter(*s);               //βαζω στο yard τον μαθητη αν χωραει
                if(school.get_stairs().get_available_space()>0){
                    s = &(school.get_schoolyard().exit());
                    school.get_stairs().enter(*s);
                    if(school.get_floor(s->get_floor()).get_corridor().get_available_space()>0){
                        s=&(school.get_stairs().exit());
                        school.get_floor(s->get_floor()).enter(*s);
                        if(school.get_floor(s->get_floor()).get_classroom(s->get_class()).get_available_space() >= 0 && school.get_floor(s->get_floor()).get_classroom(s->get_class()).get_teacher_in()==false){
                            s=&(school.get_floor(s->get_floor()).get_corridor().exit());
                            school.get_floor(s->get_floor()).get_classroom(s->get_class()).enter(*s); 
                        }
                    }
                }
            }
            
        }

        for(int i=0;i<3;i++)
            for(int j=0;j<6;j++)
                end += school.get_floor(i).get_classroom(j).get_available_space();
        
        i=rand()%2;
        if(i==1 && div>=1){
            int floorId,classId;
            int times=rand()%div;
            for(int k=0;k<=times;k++){
                i=rand()%div;
                teachers[i]->get_data(floorId,classId);
                school.get_floor(floorId).get_classroom(classId).place(*(teachers[i]));
                Teacher* temp= teachers[i];
                teachers[i]=teachers[div-1];
                teachers[div-1]=temp;
                div--; 
            }
        }
        
    if(div==0)
        break;

    }


    school.print();
    
    // for(int i=0;i<Cclass*N;i++)
    //     delete stud[i];
    
    // for(int i=0;i<N;i++)
    //     delete teachers[i];

    

}