#include "Computadora.h"

Computadora::Computadora()
{

}
Computadora::Computadora(const string &Os,const int Ram, const string &Cpu,const string &Gpu)
{
    this->Os = Os;
    this->Ram = Ram;
    this->Cpu = Cpu;
    this->Gpu = Gpu;
}

void Computadora::setOs(const string &v)
{
    Os = v;
}

string Computadora::getOs()
{
    return Os;
}


void Computadora::setRam(const int v)
{
    Ram = v;
}

int Computadora::getRam()
{
    return Ram;
}


void Computadora::setCPU(const string &v)
{
    Cpu = v;
}

string Computadora::getCPU()
{
    return Cpu;
}


void Computadora::setGPU(const string &v)
{
    Gpu = v;
}

string Computadora::getGPU()
{
    return Gpu;
}