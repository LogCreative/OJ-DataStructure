#include<iostream>
class Base {public:Base(){ std::cout << "p";}~Base(){ std::cout <<"p"; }
};
class Sub : public Base {
    public:
     Sub(){ std::cout <<"s"; }
        ~Sub(){ std::cout <<"s"; }
    private:Base b;
};
int main(){Sub s;return 0;}