#include <cstring>
#include <ctype.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>
#include <fstream>

using namespace std;

typedef struct {
    string numeroCelular;
    string dadosSessao; //guardando infos do telefone
} Telefone;

string *split(string frase, string delimitador = " ") // separando os números do celular dos dados da sessão

{
    string *vetor = new string[3]; //alocando um vetor de string com 3 posições (new em vez de malloc, porque o string precisa ser criado direito)
    int inicio = 0; //começa na posição zero
    int fim = frase.find(delimitador); // ele vai terminar de quando encontrar o último ";"
    int i = 0;
    while (fim != -1) {
        vetor[i] = frase.substr(inicio, fim - inicio);
        inicio = fim + delimitador.size();
        fim = frase.find(delimitador, inicio);
        i++;
    }
    vetor[i] = frase.substr(inicio, fim - inicio);

    return vetor;
}

void leituraArquivo(string arq, vector<Telefone>& dados) {

    ifstream procuradorArquivo; //procurarAquivos é quem vai fazer a ação de ler
    procuradorArquivo.open(arq);

    if (!procuradorArquivo) {
        cout << "Arquivo não localizado. Programa encerrado." << endl;
        exit(0);
    }

	string linha;
    string *vetor;
	while (!procuradorArquivo.eof()) { //enquanto não chegou no fim do arquivo, quem cuida disso é o método oef() e segue fazendo a leitura das linhas
		getline(procuradorArquivo,linha); //variavel auxiliar porque tenho que ler e tratar  (slitar)
        if (linha != "") { //só split se a linha não estiver vazia (a última leitura do eof pode vir vazia)
            vetor = split(linha,";");
            dados.push_back({vetor[0],vetor[1]}); //push_back=adicionar dados no vetor
        }
	}

	procuradorArquivo.close();

}

void listar(vector<Telefone> dados){
    
    for (int i = 0; i < dados.size(); i++) {
        cout << dados[i].numeroCelular << endl; //vai percorre o vetor inteiro mostrando só o número de cada telefone
    }
    
    cout << "Quantidade de celulares: " << dados.size() << endl;
}

void pesquisar(vector<Telefone> dados){
    string numero;
    bool achou = false; 

    cout << "Digite o numero do celular: ";
    cin >> numero;

    
    for (int i = 0; i < dados.size(); i++) { 
        if (dados[i].numeroCelular == numero) {
            cout << "Numero: " << dados[i].numeroCelular << endl;
            cout << "Dados da sessao: " << dados[i].dadosSessao << endl;
            achou = true;
        }
    }

    if (!achou) {
        cout << "Telefone nao encontrado!" << endl;
    }
}

int main() {
    vector<Telefone> listaSessoes;
    int opcao;
    leituraArquivo("telephony_sessions.txt",listaSessoes); //populando o vetor
    

    do {
        cout << "MENU\n";
        cout << "1 - Listar telefones\n";
        cout << "2 - Pesquisar telefone e dados de sessao\n";
        cout << "3 - Finalizar\n";
        cout << "Opcao: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao) {

            case 1:
                listar(listaSessoes);
                

                break;
            case 2:
                pesquisar(listaSessoes);
               
                break;
            case 3:
                cout << "Obrigado por usar o sistema\n";
                break;
            default:
                cout << "Opcao invalida!\n";
                break;
        }
    } while (opcao != 3);

    return 1;
}
