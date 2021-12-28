#include "AVLAgaci.hpp"
#include "Nokta.hpp"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
using namespace std;
AVLAgaci::AVLAgaci()
{
    kok = 0;
}
AVLAgaci::~AVLAgaci()
{
}
void AVLAgaci::ekle(DogruKuyrugu* veri)//Ekleme işlemi başlangıç
{ 
    kok = ekle(veri, kok);  
}
int AVLAgaci::yukseklik() 
{
	return yukseklik(kok);
}
int AVLAgaci::yukseklik(DogruKuyrugu* aktifDugum) 
{
	if(aktifDugum)
    {
        return 1+max(   yukseklik(aktifDugum->sol),
                        yukseklik(aktifDugum->sag));
    }
    return -1;
}
void AVLAgaci::postOrder()
{
    postOrder(kok);
}
void AVLAgaci::postOrder(DogruKuyrugu *kuyruk)
{
    if (kuyruk)
    {

        postOrder(kuyruk->sol);
        postOrder(kuyruk->sag);
        kuyruk->yazdir();
        cout<< "  ";
    }
}

DogruKuyrugu *AVLAgaci::ekle(DogruKuyrugu* veri, DogruKuyrugu *kuyruk)//AVL Ağacı ekleme işlemi
{

    if (kuyruk == 0)
        return veri;

    else if (kuyruk->ToplamMesafe() < veri->ToplamMesafe())
    {
        //cout<<"dd"<<endl;
        kuyruk->sag = ekle(veri, kuyruk->sag);
        if (yukseklik(kuyruk->sag) - yukseklik(kuyruk->sol) > 1)
        {
            if (veri->ToplamMesafe() > kuyruk->sag->ToplamMesafe())
                kuyruk = solaDondur(kuyruk);

            else
            {
                kuyruk->sag = sagaDondur(kuyruk->sag);
                kuyruk = solaDondur(kuyruk);
            }
        }
    }
    else if (kuyruk->ToplamMesafe() >= veri->ToplamMesafe())
    {
        kuyruk->sol = ekle(veri, kuyruk->sol);
        if (yukseklik(kuyruk->sol) - yukseklik(kuyruk->sag) > 1)
        {

            if (veri->ToplamMesafe() < kuyruk->sol->ToplamMesafe())
                kuyruk = sagaDondur(kuyruk);
            else
            {
                kuyruk->sol = solaDondur(kuyruk->sol);
                kuyruk = sagaDondur(kuyruk);
            }
        }
    }
    return kuyruk;
}
DogruKuyrugu *AVLAgaci::solaDondur(DogruKuyrugu *buyukEbeveyn)//Ağaç denge işlemleri
{
    DogruKuyrugu *sagCocuk = buyukEbeveyn->sag;
    buyukEbeveyn->sag = sagCocuk->sol;
    sagCocuk->sol = buyukEbeveyn;
    return sagCocuk;
}
DogruKuyrugu *AVLAgaci::sagaDondur(DogruKuyrugu *buyukEbeveyn)//Ağaç denge işlemleri
{
    DogruKuyrugu *solCocuk = buyukEbeveyn->sol;
    buyukEbeveyn->sol = solCocuk->sag;
    solCocuk->sag = buyukEbeveyn;
    return solCocuk;
}
