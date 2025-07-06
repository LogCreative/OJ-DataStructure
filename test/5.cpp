class A {
    ~A(){delete b;}
    void release(){delete b;}
    void do_something();
    B* b;
    };
    void A::do_something(){
    if (b != nullptr){
    release();}
    }