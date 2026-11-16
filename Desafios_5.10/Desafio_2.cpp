#include <iostream>
#include <string>
#include "utils.h"

using namespace std;

int main() {

    string data; //guarda a data que a pessoa digitar
    bool dataValida; //guarda se a data é valida ou nao

    cout << "\nDigite a data (dd/mm/aaaa): ";
    cin >> data;

    dataValida = validarData(data); //chama a função do utils.h

    if (dataValida == true) {
        cout << "Data valida" << endl;
    } else {
        cout << "Data invalida" << endl;
    }

    return 0;
}
