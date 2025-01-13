//TASK 1 SUPLIMENTAR

#include <iostream>
#include <string>
using namespace std;

// Structura pentru a reprezenta un bloc
struct Bloc {
    string strada;
    int numar;
    int scari;
    int apartamente;
    string administrator;

    // Func?ie pentru citirea valorilor unui bloc
    void citeste() {
        cout << "Introduceti strada: ";
        cin.ignore(); // pentru a cur??a bufferul de intrare
        getline(cin, strada);

        cout << "Introduceti numarul: ";
        cin >> numar;

        cout << "Introduceti numarul de scari: ";
        cin >> scari;

        cout << "Introduceti numarul de apartamente: ";
        cin >> apartamente;

        cout << "Introduceti numele administratorului: ";
        cin.ignore();
        getline(cin, administrator);
    }

    // Func?ie pentru afi?area detaliilor unui bloc
    void afiseaza() const {
        cout << "Blocul de pe strada " << strada
            << ", numarul " << numar
            << ", are " << scari << " scari si un numar total de "
            << apartamente << " apartamente. Administratorul este "
            << administrator << "." << endl;
    }
};

int main() {
    // Array de 10 blocuri
    Bloc blocuri[10];

    // Citirea a 10 blocuri
    for (int i = 0; i < 10; ++i) {
        cout << "\nCititi datele pentru blocul " << i + 1 << ":\n";
        blocuri[i].citeste();
    }

    // Afi?area informa?iilor despre toate blocurile
    cout << "\nInformatii despre toate blocurile:\n";
    for (int i = 0; i < 10; ++i) {
        cout << "Bloc " << i + 1 << ": ";
        blocuri[i].afiseaza();
    }

    return 0;
}
