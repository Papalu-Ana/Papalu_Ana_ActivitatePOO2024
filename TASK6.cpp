#include <iostream>
#include<string>
using namespace std;


class BirouDeLucru {
private:
    Computer computer;
    Telefon telefon;
    int numarAngajati;
    double suprafata; // în metri p?tra?i

public:
    // Constructor
    BirouDeLucru(Computer computer, Telefon telefon, int numarAngajati, double suprafata)
        : computer(computer), telefon(telefon), numarAngajati(numarAngajati), suprafata(suprafata) {}

    // Getteri ?i setteri
    Computer getComputer() const { return computer; }
    void setComputer(const Computer& computer) { this->computer = computer; }

    Telefon getTelefon() const { return telefon; }
    void setTelefon(const Telefon& telefon) { this->telefon = telefon; }

    int getNumarAngajati() const { return numarAngajati; }
    void setNumarAngajati(int numarAngajati) { this->numarAngajati = numarAngajati; }

    double getSuprafata() const { return suprafata; }
    void setSuprafata(double suprafata) { this->suprafata = suprafata; }

    // Metod? pentru a descrie biroul de lucru
    void descriereBirou() const {
        cout << "Birou de lucru cu " << numarAngajati << " angajati si suprafata de "
            << suprafata << " metri patrati." << endl;
        cout << "Computer: " << computer.getProcesor() << ", RAM: "
            << computer.getRam() << "MB, Stocare: " << computer.getStocare() << "GB" << endl;
        cout << "Telefon: " << telefon.getMarca() << " " << telefon.getModel()
            << ", Pret: " << telefon.getPret() << " lei" << endl;
    }

    // Operator + pentru a ad?uga angaja?i
    BirouDeLucru operator+(int angajati) {
        BirouDeLucru temp = *this;
        temp.numarAngajati += angajati;
        return temp;
    }

    // Operator == pentru compararea birourilor pe baza num?rului de angaja?i
    bool operator==(const BirouDeLucru& other) {
        return this->numarAngajati == other.numarAngajati;
    }

    // Operator << pentru afi?area informa?iilor despre birou
    friend std::ostream& operator<<(std::ostream& os, const BirouDeLucru& b) {
        os << "Birou de lucru cu " << b.numarAngajati << " angajati, suprafata de "
            << b.suprafata << " metri patrati." << endl;
        os << "Detalii Computer: " << b.computer.getProcesor() << ", "
            << b.computer.getRam() << "MB RAM, " << b.computer.getStocare() << "GB" << endl;
        os << "Detalii Telefon: " << b.telefon.getMarca() << " " << b.telefon.getModel()
            << ", Pret: " << b.telefon.getPret() << " lei." << endl;
        return os;
    }
};

