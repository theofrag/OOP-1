#include "hw2.h"



int main(void){

    Student** s;
    s= new Student*[70];
    int count=0;
    int j=0;
    for(int i=0;i<35;i++){

        
        if(j==7)
            j=0;
        
        s[i]=new Student("Boy "+ to_string(count),"Boy",j);
        j++;
        count++;
    }
    count=0;
    j=0;
    for(int i=35;i<70;i++){
        
        if(j==7)
            j=0;

        s[i]=new Student("Girl "+ to_string(count),"Girl",j);
        count++;   
        j++;  
    }

   Sequence sequence(s,70,7);

   cout<<"----------------------------------"<<endl;
   sequence.print();
   cout<<"----------------------------------"<<endl;
   cout<<"----------------------------------"<<endl;
   cout<<"----------------------------------"<<endl;
   cout<<"----------------------------------"<<endl;

   s[0]->make_naughty(true);
   s[7]->make_naughty(true);
   s[14]->make_naughty(true);
   s[35]->make_naughty(true);
   s[42]->make_naughty(true);
   s[49]->make_naughty(true);
   sequence.restore();
   sequence.print();




}