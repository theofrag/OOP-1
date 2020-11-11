#include "hw2.h"



int main(void){
    const int temp=10;

    
    Student*** s;
    int K=5;
  s= new Student**[K];
  for(int i=0;i<K;i++){
    s[i]=new Student* [temp];}

    
    int c=0;
    int count=0;
    for(int i=0;i<K;i++){
        for(int j=0;j<temp/2;j++){
            s[i][j]=new Student("Boy "+to_string(count),"Boy",i);
            count++;
        }
    }
    count=0;
    c=0;
    for(int i=0;i<K;i++){
        for( int j=temp/2;j<temp;j++){
            s[i][j]=new Student("Girl "+to_string(count),"Girl",i);
            count++;
        }
    }

    
        

   Sequence** seq= new Sequence* [K];
   for(int i=0;i<K;i++){
       seq[i]=new Sequence(s[i],temp);
   }

    for(int i=1;i<K;i++){
        seq[0]->connect(*(seq[i]));
    }

    seq[0]->print();
    // seq[1]->print();

   cout<<"----------------------------------"<<endl;
   cout<<"----------------------------------"<<endl;
   cout<<"----------------------------------"<<endl;
   cout<<"----------------------------------"<<endl;
   cout<<"----------------------------------"<<endl;
    // s[0][0]->make_naughty(true);
    // s[0][5]->make_naughty(true);

    s[0][1]->make_naughty(true);
    s[0][6]->make_naughty(true);

    s[0][3]->make_naughty(true);
    s[0][8]->make_naughty(true);



    seq[0]->restore();
//    s[0]->make_naughty(true);
//    s[7]->make_naughty(true);
//    s[21]->make_naughty(true);
//    s[35]->make_naughty(true);
//    s[42]->make_naughty(true);
//    s[56]->make_naughty(true);
//    sequence.restore();
//    sequence.print();




}