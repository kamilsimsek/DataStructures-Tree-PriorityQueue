#include "DogruKuyrugu.hpp"
#include <math.h>
DogruKuyrugu::DogruKuyrugu()//Kurucu Fonksiyon
{
    ilk = 0;
    son = 0;
    sag=0;
    sol=0;
    NoktaSayi = 0;
}
DogruKuyrugu::~DogruKuyrugu()//Yıkıcı Fonksiyon
{
    while (ilk != 0)
    {
        Nokta *gec = ilk;
        ilk = ilk->sonraki;
        delete gec;
    }
}
void DogruKuyrugu::yazdir()
{
    Nokta* gec=ilk;
    for (int i = 0; i < NoktaSayi; i++)
    {
        cout<<enYakin()->orjinUzaklik(enYakin()->x,enYakin()->y,enYakin()->z) << " ";
        enYakinCikar();
    }
    cout<<endl;
    
}
void DogruKuyrugu::ekle(int x,int y,int z)
{
    Nokta *koordinat = new Nokta(x,y,z);
    if (ilk == 0)
    {
        ilk = koordinat;
        son = koordinat;
    }
    else
    {
        Nokta *yeni = koordinat;
        son->sonraki = yeni;
        son = yeni;
    }
    NoktaSayi++;
}
Nokta *DogruKuyrugu::enYakinOnceki()
{
    {
        if (ilk == 0)
            return 0;
        Nokta *temp = ilk;
        Nokta *onceki = 0;
        int enYakinNokta = temp->orjinUzaklik(temp->x, temp->y, temp->z);
        while (temp->sonraki != 0)
        {
            if (temp->sonraki->orjinUzaklik(temp->x, temp->y, temp->z) < enYakinNokta)
            {
                enYakinNokta = temp->sonraki->orjinUzaklik(temp->x, temp->y, temp->z);
                onceki = temp;
            }
            temp = temp->sonraki;
        }
        return onceki;
    }
}
void DogruKuyrugu::enYakinCikar()
{
    Nokta *onceki = enYakinOnceki();
    if (onceki)
    {
        if (onceki->sonraki == son)
            son = onceki;
        Nokta *sil = onceki->sonraki;
        onceki->sonraki = sil->sonraki;
        delete sil;
    }
    else
    {
        if (ilk == 0)
            return;
        Nokta *sil = ilk;
        ilk = ilk->sonraki;
        delete sil;
    }
}
Nokta *DogruKuyrugu::enYakin()
{
    Nokta *onceki = enYakinOnceki();
    if (onceki)
        return onceki->sonraki;
    if (ilk != 0)
        return ilk;
}
int DogruKuyrugu::ToplamMesafe()
{
    int a = 0;
    Nokta *n1 = ilk;
    Nokta *n2 = ilk->sonraki;
     do
     {

        a += sqrt(abs(pow(n1->x - n2->x, 2)) + abs(pow(n1->y - n2->y, 2)) + abs(pow(n1->z - n2->z, 2)));
        n1 = n1->sonraki;
        n2 = n2->sonraki;

    int uzunluk = 0;

 
    } while (n2 != 0);

    return a;
}