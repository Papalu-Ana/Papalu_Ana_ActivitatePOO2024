#include <iostream>
#include <string>
using namespace std;

// Clasa 1: Computer
class Computer {
private:
    string brand;
    int ram;
    const double processorSpeed;
    static int totalComputers;
    int* storage;

public:
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

    // Constructor de copiere
    Computer(const Computer& other) : processorSpeed(other.processorSpeed) {
        brand = other.brand;
        ram = other.ram;
        storage = new int(*other.storage);
        totalComputers++;
    }

    // Destructor
    ~Computer() {
        delete storage;
    }

    // Get-eri
    string getBrand() const { return brand; }
    int getRam() const { return ram; }
    double getProcessorSpeed() const { return processorSpeed; }
    int getStorage() const { return *storage; }

    // Set-eri
    void setBrand(const string& b) { brand = b; }
    void setRam(int r) { ram = r; }
    void setStorage(int s) { *storage = s; }

    // Func?ii statice
    static int getTotalComputers() { return totalComputers; }

    // Afi?are detalii
    void displayDetails() const {
        cout << "Computer " << brand << ", RAM: " << ram << " GB, Procesor: " << processorSpeed << " GHz, Stocare: " << *storage << " GB" << endl;
    }

    // Func?ie prieten?
    friend void upgradeComputer(Computer& comp, int extraRam);
};
int Computer::totalComputers = 0;

// Clasa 2: Telefon
class Telefon {
private:
    string model;
    double ecran;
    const int baterie;
    static int totalTelefoane;
    string* sistemOperare;

public:
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

    // Constructor de copiere
    Telefon(const Telefon& other) : baterie(other.baterie) {
        model = other.model;
        ecran = other.ecran;
        sistemOperare = new string(*other.sistemOperare);
        totalTelefoane++;
    }

    // Destructor
    ~Telefon() {
        delete sistemOperare;
    }

    // Get-eri
    string getModel() const { return model; }
    double getEcran() const { return ecran; }
    int getBaterie() const { return baterie; }
    string getSistemOperare() const { return *sistemOperare; }

    // Set-eri
    void setModel(const string& m) { model = m; }
    void setEcran(double e) { ecran = e; }
    void setSistemOperare(const string& os) { *sistemOperare = os; }

    // Func?ii statice
    static int getTotalTelefoane() { return totalTelefoane; }

    // Afi?are detalii
    void displayDetails() const {
        cout << "Telefon " << model << ", Ecran: " << ecran << " inci, Baterie: " << baterie << " mAh, Sistem de operare: " << *sistemOperare << endl;
    }

    // Func?ie prieten?
    friend void updateOS(Telefon& phone, const string& newOS);
};
int Telefon::totalTelefoane = 0;

// Func?ie prieten? pentru Computer
void upgradeComputer(Computer& comp, int extraRam) {
    comp.ram += extraRam;
}

// Func?ie prieten? pentru Telefon
void updateOS(Telefon& phone, const string& newOS) {
    *phone.sistemOperare = newOS;
}

int main() {
    // Testare Computer
    Computer c1("Lenovo", 8, 3.2, 512);
    c1.displayDetails();
    upgradeComputer(c1, 4);
    c1.displayDetails();
    cout << "Total computere: " << Computer::getTotalComputers() << endl;

    // Testare Telefon
    Telefon t1("iPhone", 5.8, 4000, "iOS");
    t1.displayDetails();
    updateOS(t1, "iOS 15");
    t1.displayDetails();
    cout << "Total telefoane: " << Telefon::getTotalTelefoane() << endl;

    return 0;
}

  