#ifndef COMPUTADORA_H
#endif
#define COMPUTADORA_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class Computadora 
{
    string Os;
    int Ram;
    string Cpu;
    string Gpu;
public:
    Computadora();
    Computadora(const string &Os,
                const int Ram, 
                const string &Cpu,
                const string &Gpu);
void setOs(const string &v);
string getOs();
void setRam(const int v);
int getRam();
void setCPU(const string &v);
string getCPU();
void setGPU(const string &v);
string getGPU();

friend ostream& operator<<(ostream &out, const Computadora &c)
{
    out << left ;
    out << setw(10) << c.Os ;
    out << setw(5) << c.Ram;
    out << setw(10) << c.Cpu;
    out << setw(15) << c.Gpu; 
    out << endl; 
    return out;
}

friend istream& operator>>(istream &in, Computadora &c)
{
    cout << "Os: ";
    getline(cin, c.Os);

    cout << "Ram: ";
    cin >> c.Ram;

    cin.ignore();
    cout << "Cpu: ";
    getline(cin,c.Cpu);

    cout << "Gpu: ";
    getline(cin, c.Gpu);
     
    return in;
}

bool operator==(const Computadora& c){
        return Os == c.Os;
    }

bool operator==(const Computadora& c) const {
        return Os == c.Os;
}

};