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

    // Operator= (atribuire)
    Computer& operator=(const Computer& other) {
        if (this != &other) {
            brand = other.brand;
            ram = other.ram;
            *storage = *other.storage;
        }
        return *this;
    }

    // Supraincarcare operatori
    bool operator==(const Computer& other) const {
        return brand == other.brand && ram == other.ram && *storage == *other.storage;
    }

    Computer operator+(int extraRam) const {
        return Computer(brand, ram + extraRam, processorSpeed, *storage);
    }

    friend ostream& operator<<(ostream& out, const Computer& comp) {
        out << "Computer " << comp.brand << ", RAM: " << comp.ram << " GB, Procesor: " << comp.processorSpeed << " GHz, Stocare: " << *comp.storage << " GB";
        return out;
    }

    // Get-eri ?i set-eri
    string getBrand() const { return brand; }
    int getRam() const { return ram; }
    double getProcessorSpeed() const { return processorSpeed; }
    int getStorage() const { return *storage; }

    void setBrand(const string& b) { brand = b; }
    void setRam(int r) { ram = r; }
    void setStorage(int s) { *storage = s; }

    // Func?ii statice
    static int getTotalComputers() { return totalComputers; }

    // Afi?are detalii
    void displayDetails() const {
        cout << *this << endl;
    }
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

    // Operator= (atribuire)
    Telefon& operator=(const Telefon& other) {
        if (this != &other) {
            model = other.model;
            ecran = other.ecran;
            *sistemOperare = *other.sistemOperare;
        }
        return *this;
    }

    // Supraincarcare operatori
    bool operator!=(const Telefon& other) const {
        return model != other.model || ecran != other.ecran || *sistemOperare != *other.sistemOperare;
    }

    Telefon operator*(double factor) const {
        return Telefon(model, ecran * factor, baterie, *sistemOperare);
    }

    friend istream& operator>>(istream& in, Telefon& phone) {
        in >> phone.model >> phone.ecran;
        return in;
    }

    // Get-eri ?i set-eri
    string getModel() const { return model; }
    double getEcran() const { return ecran; }
    int getBaterie() const { return baterie; }
    string getSistemOperare() const { return *sistemOperare; }

    void setModel(const string& m) { model = m; }
    void setEcran(double e) { ecran = e; }
    void setSistemOperare(const string& os) { *sistemOperare = os; }

    // Func?ii statice
    static int getTotalTelefoane() { return totalTelefoane; }

    // Afi?are detalii
    void displayDetails() const {
        cout << "Telefon " << model << ", Ecran: " << ecran << " inci, Baterie: " << baterie << " mAh, Sistem de operare: " << *sistemOperare << endl;
    }
};
int Telefon::totalTelefoane = 0;

int main() {
    // Testare Computer
    Computer c1("Lenovo", 8, 3.2, 512);
    Computer c2("Dell", 16, 3.5, 1024);
    c1.displayDetails();
    c2.displayDetails();
    cout << "c1 == c2? " << (c1 == c2) << endl;
    c2 = c1;
    c2.displayDetails();

    // Testare Telefon
    Telefon t1("iPhone", 5.8, 4000, "iOS");
    Telefon t2("Samsung", 6.5, 5000, "Android");
    t1.displayDetails();
    t2.displayDetails();
    cout << "t1 != t2? " << (t1 != t2) << endl;
    t2 = t1;
    t2.displayDetails();

    return 0;
}
