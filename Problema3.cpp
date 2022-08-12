#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm> 

using namespace std;

class Elementos{
public:
    int a;
    int b;
    void operator ()(){
        auto num_base = chrono::system_clock::now().time_since_epoch().count();
        mt19937 generador(num_base);
        uniform_int_distribution<int>distrib(1,99);
        this->a = distrib(generador);
        this->b = distrib(generador);
    }
};

class Funcion{
public:
    int operator()(Elementos obj1,Elementos obj2){
        return (obj1.a<obj2.b);
    }
};

int main(){
    vector<Elementos> *vector;
    vector = new std::vector<Elementos> (5,Elementos());
    
    cout<<"Lista aleatoria:"<<endl;
    for (int i = 0; i < 20; i++){
        (*vector)[i]();
        cout<<"("<<(*vector)[i].a<<","<<(*vector)[i].b<<");";
    }

    sort(vector->begin(),vector->begin()+20,Funcion());
    cout<<endl;

    cout<<"Lista aleatoria comparando a<b:\n";
    for (int i = 0; i < 20; i++){
        cout<<"("<<(*vector)[i].a<<","<<(*vector)[i].b<<");";
    }
    return 0;
}