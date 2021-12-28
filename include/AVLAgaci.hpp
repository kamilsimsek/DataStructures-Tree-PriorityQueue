#ifndef AVLAgaci_hpp
#define AVLAgaci_hpp
#include<iostream>
#include "DogruKuyrugu.hpp"
using namespace std;

class AVLAgaci
{
public:

	AVLAgaci();

	~AVLAgaci();
	void ekle(DogruKuyrugu* kuyruk);
	int yukseklik();
	void postOrder();

private:
	DogruKuyrugu* solaDondur(DogruKuyrugu* DogruKuyrugu);
	DogruKuyrugu* sagaDondur(DogruKuyrugu* DogruKuyrugu);
	void postOrder(DogruKuyrugu* index);
	int yukseklik(DogruKuyrugu* aktifDogruKuyrugu);
	DogruKuyrugu* ekle(DogruKuyrugu* veri,DogruKuyrugu* aktifDogruKuyrugu);
	DogruKuyrugu* kok;
};
//diger fonksiyonlar eklenecek
#endif