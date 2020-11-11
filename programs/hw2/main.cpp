#include "hw2.h"
#include <ctime>
#include <cstdlib>  



int main(void){
    const int temp=10;
    int L=1;
    int K=5;
    srand(time(nullptr));
    Student*** s;
    
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

    
    int randomGenerator;
    for(int i=0;i<L;i++){
        int r1,r2;
        randomGenerator= rand()%(K*temp);
        for(int j=0;j<randomGenerator;j++){
            r1=rand()%K;
            r2=rand()%temp;
            if(s[r1][r2]->is_naughty()==true)
                continue;

            s[r1][r2]->make_naughty(true);
            cout<<" Student :  "<<s[r1][r2]->studentName()<<"  is naughty"<<endl;
        }
    cout<<"----------------------------------"<<endl;
    cout<<"----------------------------------"<<endl;
    seq[0]->restore();

    }





//    s[0]->make_naughty(true);
//    s[7]->make_naughty(true);
//    s[21]->make_naughty(true);
//    s[35]->make_naughty(true);
//    s[42]->make_naughty(true);
//    s[56]->make_naughty(true);
//    sequence.restore();
//    sequence.print();




}