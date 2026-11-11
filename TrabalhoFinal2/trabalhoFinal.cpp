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
    string *vetor = (string *)malloc(sizeof(string) * 3); //alocando um vetor de string com 3 posições
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
        vetor = split(linha,";");
        dados.push_back({vetor[0],vetor[1]}); //push_back=adicionar dados no vetor
	}

	procuradorArquivo.close();

}

void listar(vector<Telefone> dados){
    
}

int main() {
    vector<Telefone> listaSessoes;
    int opcao;
    leituraArquivo("telephony_sessions.txt",listaSessoes); //populando o vetor
    //método que carrega a base de telefonia e armazena numero de celular e dados de sessao no vector listaSessoes

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

            

                //metodo que lista somente os numeros de celular um abaixo do outro e no final mostra a quantidade de celulares exibidos

                break;
            case 2:
                //metodo que o usuario digita um numero de celular, o sistema o localiza e se localizado, mostra seus dados de sessao
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