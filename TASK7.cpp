#include<iostream>
#include<string>
using namespace std;




class Laptop : public Computer {
private:
    int autonomieBaterie; // în ore

public:
    // Constructor
    Laptop(std::string procesor, int ram, int stocare, int autonomieBaterie)
        : Computer(procesor, ram, stocare), autonomieBaterie(autonomieBaterie) {}

    // Getteri ?i setteri
    int getAutonomieBaterie() const { return autonomieBaterie; }
    void setAutonomieBaterie(int autonomieBaterie) { this->autonomieBaterie = autonomieBaterie; }

    // Metod? suplimentar?
    void afisareDetaliiLaptop() const {
        std::cout << "Laptop cu " << getProcesor() << ", " << getRam() << "MB RAM, "
            << getStocare() << "GB stocare, autonomie baterie: " << autonomieBaterie << " ore.\n";
    }

};
    class Smartphone : public Telefon {
    private:
        int capacitateBaterie; // în mAh

    public:
        // Constructor
        Smartphone(std::string marca, std::string model, double pret, int capacitateBaterie)
            : Telefon(marca, model, pret), capacitateBaterie(capacitateBaterie) {}

        // Getteri ?i setteri
        int getCapacitateBaterie() const { return capacitateBaterie; }
        void setCapacitateBaterie(int capacitateBaterie) { this->capacitateBaterie = capacitateBaterie; }

        // Metod? suplimentar?
        void afisareDetaliiSmartphone() const {
            std::cout << "Smartphone " << getMarca() << " " << getModel() << " cu pretul de " << getPret()
                << " lei, capacitate baterie: " << capacitateBaterie << "mAh.\n";
        }
    }

};
int main() {
    // Crearea unui obiect de tip Laptop
    Laptop laptop1("Intel Core i9", 32, 1024, 10);
    laptop1.afisareDetaliiLaptop();

    // Crearea unui obiect de tip Smartphone
    Smartphone smartphone1("Samsung", "Galaxy S22", 3000.0, 5000);
    smartphone1.afisareDetaliiSmartphone();

    // Upcasting: Convertirea unui obiect de tip Laptop la pointer de tip Computer
    Computer* pc = &laptop1;  // Upcasting implicit
    std::cout << "Detalii Laptop prin upcasting la Computer:\n";
    std::cout << "Procesor: " << pc->getProcesor() << "\n";
    std::cout << "RAM: " << pc->getRam() << "MB\n";

    // Upcasting: Convertirea unui obiect de tip Smartphone la pointer de tip Telefon
    Telefon* telefon = &smartphone1;  // Upcasting implicit
    std::cout << "Detalii Smartphone prin upcasting la Telefon:\n";
    std::cout << "Marca: " << telefon->getMarca() << "\n";
    std::cout << "Model: " << telefon->getModel() << "\n";

    return 0;
}
