#include <iostream>

using namespace std;

/*
    cout << -> Saída de dados (escreva | visualg)
    cin >> -> Entrada de dados (leia | visualg)
   
    while () {}; -> Loop (enquanto faça | visualg)
    do {} while (); -> Loop (repita até | visualg)
    for () {}; -> Loop (Para faça | visualg)

    < -> Menor que 
    > -> Maior que
    <= ->  Menor ou igual a
    >= ->  Maior ou igual a
    != -> Diferente de
    == -> Igual a 
    = -> Recebe / Atribuição

    + -> Soma
    - -> Subtração
    / -> Divisão
    % -> Resto de divisão
    * -> Multiplicação
    pow(numero, expoente) -> Potênciação
    sqrt(numero) -> Raiz quadrada

    && -> E (true e true)
    || -> OU (true ou true)
    ! -> Oposto (!true = false)
*/

int main() {
   int total, count, num;
   bool repita = true;

   count = 0;
   total = 0;

   while (repita == true)
   {
        num = 0;

        // Equanto for menor ou igual a 0, repetimos até termos um valor válido
        do {
            cout << "Digite um número: ";
            cin >> num;
            cin.ignore();
        } while (num <= 0);
        
        // Consideramos apenas os número pares
        if (num % 2 == 0) {
            total = total + num;
            count = count + 1;
        }

        // Mostramos a média, total de números digitados e a soma total destas médias
        cout << "Números pares digitados: " << count << " Total: " << total << " Média: " << total / count << endl;
      
        // Não deixamos o usuário sair ou continuar até obtermos um valor válido
        do {
            cout << "Deseja continuar? [0 - Não | 1 - Sim] ";
            cin >> num;
            cin.ignore();
        } while (num != 0 && num != 1);

        if (num == 0) {
            repita = false;
        }
   };
   
    
    return 0;
}