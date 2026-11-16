#include <iostream>
#include <string>
#include "utils.h"

using namespace std;

int main() {

    string nome; //guarda o nome completo que a pessoa digitar
    string email; //guarda o email gerado a partir do nome

    cout << "\nDigite o nome completo: ";
    getline(cin, nome); //getline porque o nome completo tem espaços

    email = gerarEmail(nome); //chama a função do utils.h

    cout << "Email: " << email << endl;

    return 0;
}
