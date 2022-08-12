#include <iostream>
#include <vector>

using namespace std;

class Sumatoria_x{
public:
    int operator()(vector<int>& x){
        int resultado{0};
        for (int i = 0; i < x.size(); i++){
            resultado += x[i];
        }
        return resultado;
    }
};

class Sumatoria_y{
public:
    int operator()(vector<int>& y){
        int resultado{0};
        for (int i = 0; i < y.size(); i++){
            resultado += y[i];
        }
        return resultado;
    }
};

class Sumatoria_xx{
public:
    int operator()(vector<int>& x){
        int resultado{0};
        for (int i = 0; i < x.size(); i++){
            resultado += (x[i]*x[i]);
        }
        return resultado;
    }
};

class Sumatoria_xy
{
public:
    int operator()(vector<int>& x,vector<int>& y){
        int resultado{0};
        for (int i = 0; i < x.size(); i++){
            resultado += (x[i]*y[i]);
        }
        return resultado;
    }
};

class Regresion{
public:
    void operator()(vector<int>& x,vector<int>& y){
        if (x.size() != y.size()){
            cout<<"Datos con tamaños diferentes"<<endl;
            return;
        }

        Sumatoria_x X;
        Sumatoria_y Y;
        Sumatoria_xy XY;
        Sumatoria_xx XX;

        auto sumatoria_x{(float)X(x)};
        auto sumatoria_y{(float)Y(y)};
        auto sumatoria_xy{(float)XY(x,y)};
        auto sumatoria_xx{(float)XX(x)};
        auto n = (float)x.size();

        auto b = ((n*sumatoria_xy)-(sumatoria_x*sumatoria_y))/
                ((n*sumatoria_xx)-(sumatoria_x*sumatoria_x));
        auto a = ((sumatoria_y)-(b*sumatoria_x))/(n);

        cout<<"La ecuacion es: y = "<<a<<" + "<<b<<"(x)";
    }
};



int main(){
    vector<int> Vy = {3,5,9,10,20,21,24,24,27,35};
    vector<int> Vx = {100,90,80,45,50,50,60,40,25,20};

    cout<<"y = a + bx"<<endl;

    Regresion R;
    R(Vx,Vy);

    return 0;
}