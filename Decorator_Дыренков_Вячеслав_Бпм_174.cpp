// ConsoleApplication124.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
//виртуальный класс
class Hearthstone {
public:

	virtual int VVinrate() = 0;
	virtual int Tir() = 0;
	virtual void Name() = 0;
};

class Mage : public Hearthstone {
public:
	virtual int VVinrate() {
		return 56;
	}
	virtual int Tir()
	{
		return 10;
	}

	virtual void Name() {
		cout << "Play as a mage: "<<endl;
	}
};

class Hunt : public Hearthstone {
public:
	virtual int VVinrate() {
		return 76;
	}
	virtual int Tir()
	{
		return 1;
	}

	virtual void Name() {
		cout << "Play as a hunter: " << endl;
	}
};

class Droud : public Hearthstone {
public:
	virtual int VVinrate() {
		return 35;
	}
	virtual int Tir()
	{
		return 100;
	}

	virtual void Name() {
		cout << "Play as a druid: " << endl;
	}
};
//декоратор
class HearthstoneDec : public Hearthstone {
public:
	HearthstoneDec(Hearthstone& decorator) :dec(decorator) { }
	virtual void Name() {
		dec.Name();
	}
	virtual int VVinrate() {
		return dec.VVinrate();
	}
	virtual int Tir() {
		return dec.Tir();
	}
	Hearthstone& dec;
};

class With_NZtoth : public HearthstoneDec {
public:
	With_NZtoth(Hearthstone& decorator) : HearthstoneDec(decorator) { }
	virtual void Name() {
		HearthstoneDec::Name();
		cout << " With_NZtoth is kind of bad " << endl;
	}
	virtual int Tir() {
		return HearthstoneDec::Tir()+150;
	}
	virtual int VVinrate() {
		return HearthstoneDec::VVinrate()/2;
	}

};

class In_wild : public HearthstoneDec {
public:
	In_wild(Hearthstone& decorator) : HearthstoneDec(decorator) { }
	virtual void Name() {
		HearthstoneDec::Name();
		cout << " But In wild the deck is stronger " << endl;
	}
	virtual int Tir() {
		return HearthstoneDec::Tir()/2-1;
	}
	virtual int VVinrate() {
		return HearthstoneDec:: VVinrate()*2 -10* 2;
	}

};


int main() {
	Hearthstone* M = new Mage();
	Hearthstone* H = new Hunt();
	Hearthstone* D = new Droud();

	Hearthstone* M_M = new With_NZtoth(*M);
	Hearthstone* M_M_M = new In_wild(*M_M);

	Hearthstone* H_H = new With_NZtoth(*H);
	Hearthstone* H_H_H = new In_wild(*H_H);

	Hearthstone* D_D = new With_NZtoth(*D);
	Hearthstone* D_D_D = new In_wild(*D_D);

	D_D->Name();
	cout <<"tir=" <<D_D->Tir() << endl;
	cout << "VVinrate=" << D_D->VVinrate() << endl;

	D_D_D->Name();
	cout << "tir=" <<D_D_D->Tir()<<endl;
	cout << "VVinrate=" << D_D_D->VVinrate() << endl;

	H_H_H->Name();
	cout << "tir=" << H_H_H->Tir() << endl;
	cout << "VVinrate=" << H_H_H->VVinrate() << endl;

	H_H->Name();
	cout << "tir=" << H_H->Tir() << endl;
	cout << "VVinrate=" << H_H->VVinrate() << endl;

	M_M_M->Name();
	cout << "tir=" << M_M_M->Tir() << endl;
	cout << "VVinrate=" << M_M_M->VVinrate() << endl;

	M_M->Name();
	cout << "tir=" << M_M->Tir() << endl;
	cout << "VVinrate=" << M_M->VVinrate() << endl;



	return 0;
}

