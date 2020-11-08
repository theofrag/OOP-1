class A{
    private:
        int number;
    public:
    A(int i);
};



A::A(int i){
    this->number=i;
}

class B{
    private:
        A* ptr;
        int num;
    public:
    B();
};

B::B(){
    ptr= new A(1);
    num=0;
}

int main(void){
    B test();
}