#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Studant {
    public:
        string name;
        int age;

    Studant(string nm, int old_age) : name(nm), age(old_age) {}
};

int main() {
    vector<Studant> studants;
    bool repeat = true;
    int age;
    string name;
    char resp;

    do { 
        name = "";
        age = 0;

        cout << "Nome do aluno: ";
        getline(cin, name);

        cout << "Digite a idade de " << name << ": ";
        cin >> age;
        cin.ignore();

        if (age == 18 || age > 20) {
            studants.push_back(Studant(name, age));
        }

        
        do {
            cout << "Continuar ? (S/N)";
            resp = toupper(cin.get());
            cin.ignore();
        } while (resp != 'S' && resp != 'N');

        if (resp == 'N') {
            repeat = false;
        }
        
        cout << endl;
    } while (repeat == true);

    
    for (int i = 0; i < size(studants); i++) {
        cout << "Nome: " << studants[i].name << ", Idade: " << studants[i].age << endl;
    };
    
    return 0;
}