#include "hw2.h"
#include <ctime>
#include <cstdlib>  

#include <sstream>

string int_to_string(const string& str, int number) {
  ostringstream oss;
  oss << str << number;
  return oss.str();
}


int main(int argc, char* argv[]){

    int K=atoi(argv[1]);       
    int L =atoi(argv[2]);
    float Tquiet=atof(argv[3]);
    float Tmessy=atof(argv[4]);

    const int temp=10;
    srand(time(NULL));
    Student*** s;
    
  s= new Student**[K];
    for(int i=0;i<K;i++)
        s[i]=new Student* [temp];


    
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
       seq[i]=new Sequence(s[i],temp,Tquiet,Tmessy);
   }

    for(int i=1;i<K;i++){
        seq[0]->connect(*(seq[i]));
    }

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

    seq[0]->print();
    cout<<endl;

    for(int i=0;i<K;i++){
        for(int j=0;j<temp;j++)
            delete s[i][j];
    }

    for(int i=0;i<K;i++)
        delete [] s[i];
    
    delete [] s;
    for(int i=0;i<K;i++)
        delete  seq[i];

    delete [] seq;


}