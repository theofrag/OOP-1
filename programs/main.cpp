#include "infrastructures.h"
#include <ctime>
#include <cstdlib>  




const int N=18;     



int main(int argc, char** argv){
    int Cclass=1;//atoi(argv[1]);
    int Cyard =1;
    int Cstair=1;//atoi(argv[3]);
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



    int end=1;
    int div=18;
    int b=0;


    while(end!=0){
        end=0;
        int i=rand()%(Cclass*N);

        if(stud[i]->get_location()=="NULL"){
            if(school.get_schoolyard().get_available_space()>0)
                school.enter(*(stud[i]));
        }
        
        else if(stud[i]->get_location()=="schoolYard"){
            if(school.get_stairs().get_available_space()>0)
                school.get_stairs().enter(school.get_schoolyard().exit(*(stud[i]))); 
        }

        else if(stud[i]->get_location()=="Stairs"){
            if(school.get_floor(stud[i]->get_floor()).get_corridor().get_available_space()>0)
                school.get_floor(stud[i]->get_floor()).enter(school.get_stairs().exit(*(stud[i]))); 
        } 

        else if(stud[i]->get_location()=="Corridor"){
            if(school.get_floor(stud[i]->get_floor()).get_classroom(stud[i]->get_class()).get_available_space() > 0 && school.get_floor(stud[i]->get_floor()).get_classroom(stud[i]->get_class()).get_teacher_in()==false)
                school.get_floor(stud[i]->get_floor()).get_classroom(stud[i]->get_class()).enter(school.get_floor(stud[i]->get_floor()).get_corridor().exit(*(stud[i]))); 
        } 
       
        for(int i=0;i<3;i++)
            for(int j=0;j<6;j++)
                end += school.get_floor(i).get_classroom(j).get_available_space();
        
        i=rand()%2;
        
        if(i=1 && div>=1){
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
    
    for(int i=0;i<Cclass*N;i++)
        delete stud[i];
    
    for(int i=0;i<N;i++)
        delete teachers[i];

    

}