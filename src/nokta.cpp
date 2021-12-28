#include "nokta.hpp"
#include <cmath>
using namespace std;
Nokta::Nokta(int x, int y, int z)
{
    this->veri = veri;
    this->x = x;
    this->y = y;
    this->z = z;
    sonraki = 0;
    onceki = 0;
}
Nokta::~Nokta()
{
}
int Nokta::orjinUzaklik(int x, int y, int z)//Noktaların 0(orjin)'a olan uzaklıkları hesaplayan fonksiyon
{
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}
