#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Funcionario {
    string codigo;
    int idade;
    float salario;
};


void cadastrar(vector<Funcionario>& lista) { //cadastra um funcionario novo e coloca no vetor
    Funcionario f; //funcionario temporario, so pra guardar o que for digitado

    cout << "Digite o codigo do funcionario: ";
    cin >> f.codigo;

    cout << "Digite a idade do funcionario: ";
    cin >> f.idade;

    cout << "Digite o salario do funcionario: ";
    cin >> f.salario;

    lista.push_back(f); //adiciona no vetor

    cout << "\nFuncionario registrado\n";
}


void exibirFiltrados(vector<Funcionario> lista) { //mostra quem tem mais de 40 anos e ganha mais de 5000, e no final a quantidade
    int quantidade = 0;

    cout << "Funcionarios que atendem ao criterio:\n";

    for (int i = 0; i < lista.size(); i++) {
        if (lista[i].idade > 40 && lista[i].salario > 5000) {
            cout << "\nCodigo do funcionario: " << lista[i].codigo << endl;
            cout << "Idade do funcionario: " << lista[i].idade << endl;
            cout << "Salario do funcionario: " << lista[i].salario << endl;
            quantidade++; //conta mais um
        }
    }

    if (quantidade == 0) {
        cout << "Nenhum funcionario encontrado.\n";
    } else {
        cout << "\nQuantidade: " << quantidade << endl;
    }
}

int main() {
    vector<Funcionario> funcionarios;
    int opcao;

    do {
        cout << "\n----MENU----\n";
        cout << "1 - Cadastrar funcionario\n";
        cout << "2 - Contar e exibir quantos funcionarios tem mais de 40 anos e ganham mais de R$ 5.000,00\n";
        cout << "3 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrar(funcionarios);
                break;
            case 2:
                exibirFiltrados(funcionarios);
                break;
            case 3:
                cout << "Saindo do programa\n";
                break;
            default:
                cout << "Opcao invalida.\n";
                break;
        }
    } while (opcao != 3);

    return 0;
}
