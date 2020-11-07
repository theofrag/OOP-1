#include "infrastructures.h"
#include <ctime>
#include <cstdlib> 

const int N=10;



int main(void){
    srand(time(nullptr));
    
    School school(10,100,100,100);
    Student* stud[18*N];
    int count=0;
    for(int i=0;i<N;i++){

        for(int j=0;j<3;j++){
            for(int k=0;k<6;k++){
                stud[count]=new Student("student "+ to_string(count),j,k);
                count++;}
        }


        // stud[i]= new Student("student "+ to_string(i),2,rand()%6);
    }
    int end=1;
    while(end!=0){
        end=0;
        int i=rand()%180;

        if(stud[i]->get_location()=="NULL")
            school.enter(*(stud[i]));
        
        else if(stud[i]->get_location()=="schoolYard")
            school.get_stairs().enter(school.get_schoolyard().exit(*(stud[i]))); 

        else if(stud[i]->get_location()=="Stairs")
            school.get_floor(stud[i]->get_floor()).enter(school.get_stairs().exit(*(stud[i])));  

        else if(stud[i]->get_location()=="Corridor")
            school.get_floor(stud[i]->get_floor()).get_classroom(stud[i]->get_class()).enter(school.get_floor(stud[i]->get_floor()).get_corridor().exit(*(stud[i])));  
       
        for(int i=0;i<3;i++)
            for(int j=0;j<6;j++)
                end += school.get_floor(i).get_classroom(j).get_available_space();
        
        


        
    cout<<"--------------------->"<<end<<endl;
    
    }


    school.print();
    
    



}