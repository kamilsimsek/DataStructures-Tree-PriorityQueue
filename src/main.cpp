#include "DogruKuyrugu.hpp"
#include "AVLAgaci.hpp"
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string dot1;
    string dot2;
    string dot3;
    int a, b, c;
    AVLAgaci* avl = new AVLAgaci();
    string cdata;
    ifstream fileRead;
    int count = 0;
    int count2 = 0;
    fileRead.open("Noktalar.txt");
    while (getline(fileRead, cdata))
    {

        for (int i = 0; i < cdata.length(); i++)
        {
            if (cdata[i] == ' ')
            {
                count2++;
            }
        }
        stringstream ss(cdata);
        DogruKuyrugu *ab = new DogruKuyrugu();
        count2 = count2 / 3;
        for (int i = 0; i < count2; i++)
        {
            if (count % 3 == 0)
            {
                ss >> dot1;
                a = stoi(dot1);
                count++;
            }
            if (count % 3 == 1)
            {
                ss >> dot2;
                b = stoi(dot2);
                count++;
            }
            if (count % 3 == 2)
            {
                ss >> dot3;
                c = stoi(dot3);
                count++;
            }
            ab->ekle(a, b, c);
        }
        count2 = 0;
        ab->ToplamMesafe();
        
        avl->ekle(ab);

    }
    fileRead.close();
    avl->postOrder();
}