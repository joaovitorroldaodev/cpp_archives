#include <iostream> // biblioteca padrão para mostrar na tela e ter função de input (cout/cin) 

using namespace std; // Para não precisar usar std::cout

// Função principal
int main() {
    int n; // Tamanho das listas

    do {
        cout << "Digite o tamanhos das listas: ";
        cin >> n;
    } while (n<0);

    float v[n],w[n]; // Listas principais
    float listaSoma[n]; // Lista de soma
    float listaSub[n]; // Lista de subtração
    float listaMult[n]; // Lista de multiplicação
    float listaDiv[n]; // Lista de divisão
 
    for (int posicao = 0; posicao < n; posicao++) {
        cout << "Posicao: " << posicao << endl;

        cout << "Digite o n1: ";
        cin >> v[posicao]; 

        cout << "Digite o n2: ";
        cin >> w[posicao]; 

        listaSoma[posicao] = v[posicao] + w[posicao]; // Soma

        listaSub[posicao] = v[posicao] - w[posicao]; // Subtração 

        listaMult[posicao] = v[posicao] * w[posicao]; // Multiplação

        // Divisão
        // Regra matemática: 0 não pode ser dividido
        if (v[posicao] == 0.0) {
            listaDiv[posicao] = 0.0;
        } else {
            listaDiv[posicao] = v[posicao] / w[posicao];
        }
    }

    // Mostrando resultados e números digitado (Em cada posicão)
    for (int i = 0; i < n; i++) {
        cout << endl;
        cout << "Posicao: " << i << endl;

        cout << "Num 1:" << v[i] << endl;
        cout << "Num 2:" << w[i] << endl;

        cout << "Soma:" << listaSoma[i] << endl;
        cout << "Subtração:" << listaSub[i] << endl;
        cout << "Multiplicação:" << listaMult[i] << endl;
        cout << "Divisão:" << listaDiv[i] << endl;
    }

    cout << endl;
    float produtoEscalar = 0.0;

    // Produto escalar é a soma de todas as multiplicações 
    //         n=tam da lista | n=1  |      n=2     |     n=(...)
    // Fórmula geral: P(n) = (V1 * W1) + (V2 * W2) ... (Vn * Wn)
    for (int j = 0; j < n; j++) {
        produtoEscalar += listaMult[j];
    }

    cout << "Produto escalar:" << produtoEscalar << endl;

    return 0; // Retorno padrão para indicar que terminou em sucesso
}