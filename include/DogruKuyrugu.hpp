#ifndef queue_hpp
#define queue_hpp
#include "Nokta.hpp"
#include <iostream>
using namespace std;
class DogruKuyrugu
{
public:
    DogruKuyrugu();
    ~DogruKuyrugu();
    void ekle(int x,int y,int z);
    int getir;
    DogruKuyrugu* sag;
    DogruKuyrugu* sol;
    Nokta *enYakinOnceki();
    Nokta *enYakin();
    void enYakinCikar();
    int ToplamMesafe();
    void yazdir();
    int NoktaSayi;
private:
    Nokta* ilk;
    Nokta* son;
};
#endif