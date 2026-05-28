#include <iostream>

using namespace std;

#define qtyMax 3

int main () {
    string alunos[qtyMax];

    float n1, n2, media = 0.0;
    string name;

    for (int i = 0; i < qtyMax; i++) {
        cout << "\nDigite o nome do aluno[" << i << "]: ";
        getline(cin,name);

        cout << "Digite a nota 1: ";
        cin >> n1;
        
        cout << "Digite a nota 2: ";
        cin >> n2;

        media = (n1+n2) / 2;

        cin.ignore();

        alunos[i] = "Aluno: " + name + " | Nota 1: " + to_string(n1) + " | Nota 2: " + to_string(n2) + " | Média: " + to_string(media);
    }

    cout << endl;

    for (int i = 0; i < qtyMax; i++) {
        cout << alunos[i] << endl;
    }

    cout << "\nFinalizando o programa . . .\n" << endl;

    return 0;
};