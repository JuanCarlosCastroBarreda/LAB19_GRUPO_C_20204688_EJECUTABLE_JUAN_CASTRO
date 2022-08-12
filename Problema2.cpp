#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Find{
public:
    string _find;
    void operator = (string dato){
        this->_find = dato;
    }

    vector<int> operator ()(int _ini, int _fin, string buscar){
        vector<int> resultado;
        int ini{_ini-1},fin{_fin-1};
        if (ini<0 || ini>_fin){
            ini = 0;
        }
        if (fin<_ini || fin > this->_find.size()){
            fin = this->_find.size();
        }
        
        int cont{0},ok{0};
        for (int i = ini; i < fin; i++){
            ok = i;
            for (int k = 0, j = i; k < buscar.size(); k++, j++){
                if (buscar[k] == this->_find[j]){
                    cont++;
                }else{
                    break;
                }
            }
            if (cont == buscar.size()){
                resultado.push_back(ok);
                i += buscar.size(); 
            }
            cont = 0;
        }

        return resultado;
    }
};



int main(){
    Find cadena;
    cadena = "La suma de 2 numeros por la resta de los mismos numeros es igual a la diferencia de cuadrados de estos numeros";
    vector<int> vector = cadena(1,130,"numeros");
    cout<<"Las ocurrencias iguales estan en la posicion: ";
    for (int i = 0; i < vector.size(); i++){
        cout<< vector[i]+1<<" ";
    }
    
    return 0;
}