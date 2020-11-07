#include "infrastructures.h"
#include <ctime>
#include <cstdlib> 

const int N=40;



int main(void){
    srand(time(nullptr));
    
    School school(10,10,10,10);
    Student* stud[N];

    for(int i=0;i<N;i++){
        stud[i]= new Student("student "+ to_string(i),rand()%3,rand()%6);
    }

    for(int j=0;j<5000;j++){
        int i=rand()%40;

        if(stud[i]->get_location()=="NULL")
            school.enter(*(stud[i]));
        
        else if(stud[i]->get_location()=="schoolYard")
            school.get_stairs().enter(school.get_schoolyard().exit(*(stud[i]))); 

        else if(stud[i]->get_location()=="Stairs")
            school.get_floor(stud[i]->get_floor()).enter(school.get_stairs().exit(*(stud[i])));  

        else if(stud[i]->get_location()=="Corridor")
            school.get_floor(stud[i]->get_floor()).get_classroom(stud[i]->get_class()).enter(school.get_floor(stud[i]->get_floor()).get_corridor().exit(*(stud[i])));  
    }


    school.print();
    
    



}