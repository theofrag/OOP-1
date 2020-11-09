#include "hw2.h"



int main(void){

    Student* s[20];
    int count=0;
    for(int i=0;i<10;i++){
        s[i]=new Student("Boy "+ to_string(count),"Boy",1);
        count++;
    }
    count=0;
    for(int i=10;i<20;i++){
        s[i]=new Student("Girl "+ to_string(count),"Girl",1);
        count++;       
    }

    Classroom classroom(10);
    Classroom classroom2(10);
    for(int i=0;i<5;i++)
        classroom.place(*(s[i]));
    for(int i=10;i<15;i++)
        classroom.place(*(s[i]));
    
    for(int i=5;i<10;i++)
        classroom2.place(*(s[i]));
    for(int i=15;i<20;i++)
        classroom2.place(*(s[i]));
    

    classroom.buildSequences();
    classroom2.buildSequences();
    classroom.connect(classroom2);
    classroom.printSequences();
    cout<<"---"<<endl;
    classroom2.printSequences();

    s[0]->make_naughty(true);
    s[10]->make_naughty(true);
    s[1]->make_naughty(true);
    s[11]->make_naughty(true);
    s[3]->make_naughty(true);
    s[13]->make_naughty(true);
    cout<<"------------------"<<endl;
    cout<<"------------------"<<endl;
    classroom.restoreQuietness();
    classroom.printSequences();
    cout<<"---"<<endl;
    classroom2.printSequences();



}