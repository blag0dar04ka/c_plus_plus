#include "stdafx.h"
#include <iostream>
#include <vector>


using namespace std;


class Beer
{
public:
	virtual void descr() = 0;
	virtual int price() = 0;
	virtual void hangover() = 0;
	//virtual ~Killer() {}
};

class Samogon
{
public:
	virtual void descr() = 0;
	virtual int price() = 0;
	virtual void hangover() = 0;
	//virtual ~Killer() {}
};

class Vodka
{
public:
	virtual void descr() = 0;
	virtual int price() = 0;
	virtual void hangover() = 0;
	//virtual ~Killer() {}
};


class SET_1_Beer : public Beer
{
public:
	void descr() {
		cout << "Vi zakazali ohota krepkoye" << endl;
	}
	int price() {
		return 50;
	}
	void hangover(){
		cout << "Vsego lish Odna butilka == vertoleti" << endl;
		cout << endl;
	}
};

class SET_1_Vodka : public Vodka
{
public:
	void descr() {
		cout << "Vi zakazali Talku" << endl;
	}
	int price() {
		return 650;
	}
	void hangover() {
		cout << "V sredmen 1.5 litra == belochka" << endl;
		cout << endl;
	}
};

class SET_1_Samogon : public Samogon
{
public:
	void descr() {
		cout << "Vi zakazali Samogon kak u deda v derevne" << endl;
	}
	int price() {
		return 1;
	}
	void hangover() {
		cout << "Ot odnogo zapaha uzhe p'yaneesh" << endl;
		cout << endl;
	}
};


class SET_2_Beer : public Beer
{
public:
	void descr() {
		cout << "Vi zakazali English El'" << endl;
	}
	int price() {
		return 650;
	}
	void hangover() {
		cout << "8 pint piva ~= nemnogo pohmel'ya" << endl;
		cout << endl;
	}
};

class SET_2_Vodka : public Vodka
{
public:
	void descr() {
		cout << "Vi zakazali vodka Absolut" << endl;
	}
	int price() {
		return 1550;
	}
	void hangover() {
		cout << "Pollitra vodki i uzhe ploho" << endl;
		cout << endl;
	}
};

class SET_2_Samogon : public Samogon
{
public:
	void descr() {
		cout << "Vi zakazali Samogon s fabricki" << endl;
	}
	int price() {
		return 800;
	}
	void hangover() {
		cout << "Dazhe ot s 10 razha ne p'yaneesh" << endl;
		cout << endl;
	}
};


class Factory_Bar
{
public:
	virtual Beer* _Beer() = 0;
	virtual Vodka* _Vodka() = 0;
	virtual Samogon* _Samogon() = 0;
	//virtual ~ArmyFactory() {}
};


class Factory_Set_1 : public Factory_Bar
{
public:
	Beer* _Beer() {
		return new SET_1_Beer;
	}
	Vodka* _Vodka() {
		return new SET_1_Vodka;
	}
	Samogon* _Samogon() {
		return new SET_1_Samogon;
	}
};


class Factory_Set_2 : public Factory_Bar
{
public:
	Beer* _Beer() {
		return new SET_2_Beer;
	}
	Vodka* _Vodka() {
		return new SET_2_Vodka;
	}
	Samogon* _Samogon() {
		return new SET_2_Samogon;
	}
};


class In_the_bar
{public:
	vector<Beer*> b;
	vector<Vodka*> v;
	vector<Samogon*> s;
};


class BAR
{
public:
	In_the_bar* drink(Factory_Bar& factory) {
		In_the_bar* napitcki = new In_the_bar;
		napitcki->b.push_back(factory._Beer());
		napitcki->v.push_back(factory._Vodka());
		napitcki->s.push_back(factory._Samogon());
		return napitcki;
	}
};


int main()
{
	int i = 0;
	BAR dark_horse;


	Factory_Set_1 set_1;
	Factory_Set_2 set_2;

	In_the_bar * qwerty = dark_horse.drink(set_1);
	In_the_bar * zxcvbn = dark_horse.drink(set_2);
	cout << "Quick brief of the first set:" << endl;
	//cout<<qwerty->b
	for (i = 0; i < qwerty->b.size(); ++i) 
	{   qwerty->b[i]->descr(); 
	    cout <<"cena= "<< qwerty->b[i]->price() << endl;
	    qwerty->b[i]->hangover();

	}
	for (i = 0; i < qwerty->v.size(); ++i)
	{
		qwerty->v[i]->descr();
		cout << "cena= " << qwerty->v[i]->price() << endl;
		qwerty->v[i]->hangover();

	}
	for (i = 0; i < qwerty->s.size(); ++i)
	{
		qwerty->s[i]->descr();
		cout << "cena= " << qwerty->s[i]->price() << endl;
		qwerty->s[i]->hangover();

	}
	cout << endl;
	cout << "Quick brief of the second set:" << endl;


	for (i = 0; i < zxcvbn->b.size(); ++i)
	{
		zxcvbn->b[i]->descr();
		cout << "cena= " << zxcvbn->b[i]->price() << endl;
		zxcvbn->b[i]->hangover();

	}
	for (i = 0; i < zxcvbn->v.size(); ++i)
	{
		zxcvbn->v[i]->descr();
		cout << "cena= " << zxcvbn->v[i]->price() << endl;
		zxcvbn->v[i]->hangover();

	}
	for (i = 0; i < zxcvbn->s.size(); ++i)
	{
		zxcvbn->s[i]->descr();
		cout << "cena= " << zxcvbn->s[i]->price() << endl;
		zxcvbn->s[i]->hangover();

	}




	return 0;
}