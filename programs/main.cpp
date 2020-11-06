#include <iostream>
#include "student.h"

using namespace std;



int main(void){

    School sh(5,5,5,5);
    Student s("theo",1,1);
    // s.enter();
    sh.enter(s);
    cout<<"\n\n\n\n\n\n\n\\n\n\n\n"<<endl;
    sh.print();
    // Schoolyard sc= sh.get_schoolyard();
    // sc.enter(s);

    


    return 0;
}