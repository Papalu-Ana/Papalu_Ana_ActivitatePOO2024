#include <iostream>
#include <string>
using namespace std;

// Clasa 1: Computer
class Computer {
public:
    string brand;
    int ram;
    const double processorSpeed;
    static int totalComputers;
    int* storage;

    // Constructor implicit
    Computer() : processorSpeed(2.5) {
        brand = "Generic";
        ram = 4;
        storage = new int(256);
        totalComputers++;
    }

    // Constructor cu 2 parametri
    Computer(string b, int r) : processorSpeed(2.5) {
        brand = b;
        ram = r;
        storage = new int(256);
        totalComputers++;
    }

    // Constructor complet
    Computer(string b, int r, double p, int s) : processorSpeed(p) {
        brand = b;
        ram = r;
        storage = new int(s);
        totalComputers++;
    }

    ~Computer() {
        delete storage;
    }

    static void afiseazaTotalComputere() {
        cout << "Total computere: " << totalComputers << endl;
    }

    void afiseazaDetalii() {
        cout << "Computer " << brand << ", RAM: " << ram << " GB, Procesor: " << processorSpeed << " GHz, Stocare: " << *storage << " GB" << endl;
    }
};
int Computer::totalComputers = 0;

// Clasa 2: Telefon
class Telefon {
public:
    string model;
    double ecran;
    const int baterie;
    static int totalTelefoane;
    string* sistemOperare;

    // Constructor implicit
    Telefon() : baterie(4000) {
        model = "Generic";
        ecran = 6.0;
        sistemOperare = new string("Android");
        totalTelefoane++;
    }

    // Constructor cu 2 parametri
    Telefon(string m, double e) : baterie(4000) {
        model = m;
        ecran = e;
        sistemOperare = new string("Android");
        totalTelefoane++;
    }

    // Constructor complet
    Telefon(string m, double e, int b, string os) : baterie(b) {
        model = m;
        ecran = e;
        sistemOperare = new string(os);
        totalTelefoane++;
    }

    ~Telefon() {
        delete sistemOperare;
    }

    static void afiseazaTotalTelefoane() {
        cout << "Total telefoane: " << totalTelefoane << endl;
    }

    void afiseazaDetalii() {
        cout << "Telefon " << model << ", Ecran: " << ecran << " inci, Baterie: " << baterie << " mAh, Sistem de operare: " << *sistemOperare << endl;
    }
};
int Telefon::totalTelefoane = 0;

// Clasa 3: Imprimanta
class Imprimanta {
public:
    string tip;
    int viteza;
    const bool color;
    static int totalImprimante;
    string* conexiune;

    // Constructor implicit
    Imprimanta() : color(false) {
        tip = "Laser";
        viteza = 20;
        conexiune = new string("USB");
        totalImprimante++;
    }

    // Constructor cu 2 parametri
    Imprimanta(string t, int v) : color(false) {
        tip = t;
        viteza = v;
        conexiune = new string("USB");
        totalImprimante++;
    }

    // Constructor complet
    Imprimanta(string t, int v, bool c, string conn) : color(c) {
        tip = t;
        viteza = v;
        conexiune = new string(conn);
        totalImprimante++;
    }

    ~Imprimanta() {
        delete conexiune;
    }

    static void afiseazaTotalImprimante() {
        cout << "Total imprimante: " << totalImprimante << endl;
    }

    void afiseazaDetalii() {
        cout << "Imprimanta " << tip << ", Viteza: " << viteza << " pagini/min, Color: " << (color ? "Da" : "Nu") << ", Conexiune: " << *conexiune << endl;
    }
};
int Imprimanta::totalImprimante = 0;

int main() {
    // Testare clase

    // Obiecte Computer
    Computer c1;
    Computer c2("Lenovo", 8);
    Computer c3("Dell", 16, 3.5, 512);

    c1.afiseazaDetalii();
    c2.afiseazaDetalii();
    c3.afiseazaDetalii();
    Computer::afiseazaTotalComputere();

    // Obiecte Telefon
    Telefon t1;
    Telefon t2("iPhone", 5.8);
    Telefon t3("Samsung", 6.7, 5000, "Android");

    t1.afiseazaDetalii();
    t2.afiseazaDetalii();
    t3.afiseazaDetalii();
    Telefon::afiseazaTotalTelefoane();

    // Obiecte Imprimanta
    Imprimanta i1;
    Imprimanta i2("Inkjet", 15);
    Imprimanta i3("Laser", 30, true, "WiFi");

    i1.afiseazaDetalii();
    i2.afiseazaDetalii();
    i3.afiseazaDetalii();
    Imprimanta::afiseazaTotalImprimante();

    return 0;
}
