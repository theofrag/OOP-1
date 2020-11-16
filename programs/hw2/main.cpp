#include "hw2.h"
#include <ctime>
#include <cstdlib>  

#include <sstream>

string int_to_string(const string& str, int number) {
  ostringstream oss;
  oss << str << number;
  return oss.str();
}


int main(void){

   Student** s;
    Student** s1;
    Student** s2;
    s1=new Student*[10];
    s2=new Student*[10];
    s=new Student*[10];

    s[0]=new Student("Boy 0","Boy",0);
    s[1]=new Student("Boy 1","Boy",0);
    s[2]=new Student("Boy 2","Boy",0);
    s[3]=new Student("Boy 3","Boy",0);
    s[4]=new Student("Boy 4","Boy",0);

    s[5]=new Student("Girl 0","Girl",0);
    s[6]=new Student("Girl 1","Girl",0);
    s[7]=new Student("Girl 2","Girl",0);
    s[8]=new Student("Girl 3","Girl",0);
    s[9]=new Student("Girl 4","Girl",0);
//----------------
    s1[0]=new Student("Boy 5","Boy",1);
    s1[1]=new Student("Boy 6","Boy",1);
    s1[2]=new Student("Boy 7","Boy",1);
    s1[3]=new Student("Boy 8","Boy",1);
    s1[4]=new Student("Boy 9","Boy",1);

    s1[5]=new Student("Girl 5","Girl",1);
    s1[6]=new Student("Girl 6","Girl",1);
    s1[7]=new Student("Girl 7","Girl",1);
    s1[8]=new Student("Girl 8","Girl",1);
    s1[9]=new Student("Girl 9","Girl",1);
//---------------
    s2[0]=new Student("Boy 10","Boy",2);
    s2[1]=new Student("Boy 11","Boy",2);
    s2[2]=new Student("Boy 12","Boy",2);
    s2[3]=new Student("Boy 13","Boy",2);
    s2[4]=new Student("Boy 14","Boy",2);

    s2[5]=new Student("Girl 10","Girl",2);
    s2[6]=new Student("Girl 11","Girl",2);
    s2[7]=new Student("Girl 12","Girl",2);
    s2[8]=new Student("Girl 13","Girl",2);
    s2[9]=new Student("Girl 14","Girl",2);

    Sequence seq(s,10);
    Sequence seq1(s1,10);
    Sequence seq2(s2,10);


    seq.connect(seq1);
    seq.connect(seq2);
    seq.print();
    cout<<"###################################################"<<endl;

    // s[0]->make_naughty(true);
    // s[1]->make_naughty(true);
    // s[2]->make_naughty(true);

    // s[5]->make_naughty(true);
    // s[6]->make_naughty(true);
    // s[7]->make_naughty(true);



    
    
    // seq.restore();
    // seq.print();
    
    
//     const int temp=10;
//     int L=1;
//     int K=3;
//     srand(time(nullptr));
//     Student*** s;
    
//   s= new Student**[K];
//   for(int i=0;i<K;i++){
//     s[i]=new Student* [temp];}

    
//     int c=0;
//     int count=0;
//     for(int i=0;i<K;i++){
//         for(int j=0;j<temp/2;j++){
//             s[i][j]=new Student("Boy "+to_string(count),"Boy",i);
//             count++;
//         }
//     }
//     count=0;
//     c=0;
//     for(int i=0;i<K;i++){
//         for( int j=temp/2;j<temp;j++){
//             s[i][j]=new Student("Girl "+to_string(count),"Girl",i);
//             count++;
//         }
//     }

    
        

//    Sequence** seq= new Sequence* [K];
//    for(int i=0;i<K;i++){
//        seq[i]=new Sequence(s[i],temp);
//    }

//     for(int i=1;i<K;i++){
//         seq[0]->connect(*(seq[i]));
//     }

//     seq[0]->print();
//     // seq[1]->print();

//    cout<<"----------------------------------"<<endl;
//    cout<<"----------------------------------"<<endl;
//    cout<<"----------------------------------"<<endl;

    
//     int randomGenerator;
//     for(int i=0;i<1;i++){
//         int r1,r2;
//         randomGenerator= rand()%(K*temp);
//         for(int j=0;j<randomGenerator;j++){
//             r1=rand()%K;
//             r2=rand()%temp;
//             if(s[r1][r2]->is_naughty()==true)
//                 continue;

//             s[r1][r2]->make_naughty(true);
//             cout<<" Student :  "<<s[r1][r2]->studentName()<<"  is naughty"<<endl;
//         }
//     cout<<"----------------------------------"<<endl;
//     cout<<"----------------------------------"<<endl;
//     seq[0]->restore();

//     }





}