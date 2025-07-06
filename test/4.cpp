#include<iostream>
#include<memory>
using namespace std;
void fun(std::shared_ptr<int> p){
p = std::make_shared<int>(5);
}
int main(){
int avar=6;for(int i=0;i<10000000; i++){
std::shared_ptr<int> p= std::make_shared<int>(avar);fun(p);std::cout <<*p;
return 0;}}