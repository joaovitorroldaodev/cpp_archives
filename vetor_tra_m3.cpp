#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    const int numMaxMed = 50;          

    string nomes[numMaxMed];           
    int quantidades[numMaxMed];     
    double precos[numMaxMed];          

    int total = 0;               
    int opcao;

    cout << fixed << setprecision(2);

    do {
        cout << "\n===== FÁRMACIA - ESTOQUE E VENDAS =====\n";
        cout << "1 - Cadastrar medicamento\n";
        cout << "2 - Atualizar estoque\n";
        cout << "3 - Buscar medicamento\n";
        cout << "4 - Vender medicamentos\n";
        cout << "5 - Listar medicamentos cadastrados\n";
        cout << "6 - Sair\n";

        cout << "\nEscolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                if (total >= numMaxMed) {
                    cout << "\nLimite de " << numMaxMed << " medicamentos atingido.\n";
                } else {
                    string nome;
                    cout << "\nNome do medicamento: ";
                    cin >> nome;

                    int pos = -1;
                    for (int i = 0; i < total; i++) {
                        if (nomes[i] == nome) {
                            pos = i;
                        }
                    }

                    if (pos != -1) {
                        cout << "Medicamento já cadastrado!\n";
                    } else {
                        int qtd;
                        cout << "Quantidade em estoque: ";
                        cin >> qtd;
                        while (qtd < 0) {     
                            cout << "Quantidade inválida! Digite um valor não negativo: ";
                            cin >> qtd;
                        }

                        double preco;
                        cout << "Preço unitário: ";
                        cin >> preco;
                        while (preco <= 0) {  
                            cout << "Preço inválido! Digite um valor positivo: ";
                            cin >> preco;
                        }

                        nomes[total]       = nome;
                        quantidades[total] = qtd;
                        precos[total]      = preco;
                        total++;

                        cout << "Medicamento cadastrado com sucesso!\n";
                    }
                }
                break;
            }
            case 2: {
                string nome;
                cout << "\nNome do medicamento: ";
                cin >> nome;

                int pos = -1;
                for (int i = 0; i < total; i++) {
                    if (nomes[i] == nome) {
                        pos = i;
                    }
                }

                if (pos == -1) {
                    cout << "Medicamento não cadastrado\n";
                } else {
                    int qtdAdd;
                    cout << "Quantidade a adicionar: ";
                    cin >> qtdAdd;
                    while (qtdAdd <= 0) {
                        cout << "Quantidade inválida! Digite um valor positivo: ";
                        cin >> qtdAdd;
                    }
                    quantidades[pos] += qtdAdd;
                    cout << "Estoque atualizado\n";
                }
                break;
            }
            case 3: {
                string nome;
                cout << "\nNome do medicamento: ";
                cin >> nome;

                int pos = -1;
                for (int i = 0; i < total; i++) {
                    if (nomes[i] == nome) {
                        pos = i;
                    }
                }

                if (pos == -1) {
                    cout << "Medicamento não cadastrado\n";
                } else {
                    cout << "Nome: "  << nomes[pos] << "\n";
                    cout << "Estoque: " << quantidades[pos] << "\n";
                    cout << "Preço unitário: R$ " << precos[pos] << "\n";
                }
                break;
            }
            case 4: {
                if (total == 0) {
                    cout << "\nNenhum medicamento cadastrado.\n";
                } else {
                    double totalVenda = 0.0;
                    char continuar;

                    do {
                        string nome;
                        cout << "\nNome do medicamento: ";
                        cin >> nome;

                        int pos = -1;
                        for (int i = 0; i < total; i++) {
                            if (nomes[i] == nome) {
                                pos = i;
                            }
                        }

                        if (pos == -1) {
                            cout << "Medicamento não cadastrado\n";
                        } else {
                            int qtdVenda;
                            cout << "Quantidade desejada: ";
                            cin >> qtdVenda;
                            while (qtdVenda <= 0) {
                                cout << "Quantidade inválida! Digite um valor positivo: ";
                                cin >> qtdVenda;
                            }

                            while (qtdVenda > quantidades[pos]) {
                                cout << "Quantidade insuficiente\n";
                                cout << "Digite nova quantidade: ";
                                cin >> qtdVenda;
                                while (qtdVenda <= 0) {
                                    cout << "Quantidade inválida! Digite um valor positivo: ";
                                    cin >> qtdVenda;
                                }
                            }

                            quantidades[pos] -= qtdVenda;
                            totalVenda += qtdVenda * precos[pos];
                            cout << "Baixa realizada no estoque.\n";
                        }

                        cout << "Outro medicamento? S/N: ";
                        cin >> continuar;

                    } while (continuar == 'S' || continuar == 's');

                    cout << "Valor total da venda: R$ " << totalVenda << "\n";
                    cout << "Venda finalizada\n";
                }
                break;
            }
            case 5: {
                if (total == 0) {
                    cout << "\nNenhum medicamento cadastrado.\n";
                } else {
                    double totalEstoque = 0.0;
                    cout << "\n----- MEDICAMENTOS CADASTRADOS -----\n";
                    for (int i = 0; i < total; i++) {
                        cout << "Nome: " << nomes[i] << " | Estoque: " << quantidades[i] << " | Preço: R$ " << precos[i] << "\n";
                        totalEstoque += quantidades[i] * precos[i];
                    }
                    cout << "Valor total do estoque: R$ " << totalEstoque << "\n";
                }
                break;
            }
            case 6:
                cout << "\nEncerrando o sistema...\n";
            break;
            default:
                cout << "\nOpcao inválida! Tente novamente.\n";
        }

    } while (opcao != 6);

    return 0;
}