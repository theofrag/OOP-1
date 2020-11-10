#include "hw2.h"



int main(void){

    Student* s[70];
    int count=0;
    for(int i=0;i<35;i++){
        s[i]=new Student("Boy "+ to_string(count),"Boy",1);
        count++;
    }
    count=0;
    for(int i=35;i<70;i++){
        s[i]=new Student("Girl "+ to_string(count),"Girl",1);
        count++;       
    }

    Classroom classroom(10);
    Classroom classroom2(10);
    Classroom classroom3(10);
    Classroom classroom4(10);
    Classroom classroom5(10);
    Classroom classroom6(10);
    Classroom classroom7(10);

    for(int i=0;i<5;i++)
        classroom.place(*(s[i]));
    for(int i=35;i<40;i++)
        classroom.place(*(s[i]));
    
    for(int i=5;i<10;i++)
        classroom2.place(*(s[i]));
    for(int i=40;i<45;i++)
        classroom2.place(*(s[i]));
    
    for(int i=10;i<15;i++)
        classroom3.place(*(s[i]));
    for(int i=45;i<50;i++)
        classroom3.place(*(s[i]));

    for(int i=15;i<20;i++)
        classroom4.place(*(s[i]));
    for(int i=50;i<55;i++)
        classroom4.place(*(s[i]));

    for(int i=20;i<25;i++)
        classroom5.place(*(s[i]));
    for(int i=55;i<60;i++)
        classroom5.place(*(s[i]));

    for(int i=25;i<30;i++)
        classroom6.place(*(s[i]));
    for(int i=60;i<65;i++)
        classroom6.place(*(s[i]));

    for(int i=30;i<35;i++)
        classroom7.place(*(s[i]));
    for(int i=65;i<70;i++)
        classroom7.place(*(s[i]));
    

    classroom.buildSequences();
    classroom2.buildSequences();
    classroom3.buildSequences();
    classroom4.buildSequences();
    classroom5.buildSequences();
    classroom6.buildSequences();
    classroom7.buildSequences();

    classroom.connect(classroom2);
    classroom.connect(classroom3);
    classroom.connect(classroom4);
    classroom.connect(classroom5);
    classroom.connect(classroom6);
    classroom.connect(classroom7);
    classroom.printSequences();
    cout<<"---"<<endl;
    classroom2.printSequences();
    cout<<"---"<<endl;
    classroom3.printSequences();
    cout<<"---"<<endl;
    classroom4.printSequences();
    cout<<"---"<<endl;
    classroom5.printSequences();
    cout<<"---"<<endl;
    classroom6.printSequences();
    cout<<"---"<<endl;
    classroom7.printSequences();
    cout<<"\n\n\n\n"<<endl;

    

    s[0]->make_naughty(true);
    s[35]->make_naughty(true);
    s[1]->make_naughty(true);
    s[36]->make_naughty(true);
    s[2]->make_naughty(true);
    s[37]->make_naughty(true);

    cout<<"\n\n\n\n"<<endl;

    classroom.restoreQuietness();
    cout<<"\n\n\n\n"<<endl;

    classroom.printSequences();
    cout<<"---"<<endl;
    classroom2.printSequences();
    cout<<"---"<<endl;
    classroom3.printSequences();
    cout<<"---"<<endl;
    classroom4.printSequences();
    cout<<"---"<<endl;
    classroom5.printSequences();
    cout<<"---"<<endl;
    classroom6.printSequences();
    cout<<"---"<<endl;
    classroom7.printSequences();



}