#include <iostream>
#include <string>
#include "utils.h"

using namespace std;

int main() {

    string cpf; //aqui vai ficar guardado o cpf que a pessoa digitar
    bool cpfValido; //guarda se o cpf é valido ou nao

    cout << "Digite o CPF sem pontuacao: ";
    cin >> cpf;

    cpfValido = validarCPF(cpf); //chama a função que está no utils.h

    if (cpfValido == true) {
        cout << "CPF valido." << endl;
    } else {
        cout << "CPF invalido." << endl;
    }

    return 0;
}
