// ConsoleApplication127.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

class Organ {
public:
	virtual void improve() = 0;
	virtual void replace() = 0;
	virtual void cut_out() = 0;
	//virtual void narcoz() = 0;
};

class Pechen_Liver : public Organ {
	void improve() {
		cout << "The operation began" << endl;
	}
	/*void narcoz() {
		cout << "Narcoz vveli" << endl;
	}*/
	void replace() {
		cout << "Liver has been cured" << endl;
	}
	void cut_out() {
		cout << "During the procedure liver has been stolen :(" << endl;
	}
};

class Pochka_Kidney : public Organ {
	void improve() {
		cout << "The operation began" << endl;
	}
	/*void narcoz() {
		cout << "Narcoz vveli" << endl;
	}*/
	void replace() {
		cout << "Kidney has been cured" << endl;
	}
	void cut_out() {
		cout << "During the procedure kidney has been stolen :(" << endl;
	}
};

class Heart_serdce : public Organ {
	void improve() {
		cout << "The operation began" << endl;
	}
	/*void narcoz() {
		cout << "Narcoz vveli" << endl;
	}*/
	void replace() {
		cout << "Hearth has been cured" << endl;
	}
	void cut_out() {
		cout << "During the procedure heart has been stolen :(" << endl;
	}
};

class Mozg_brain : public Organ {
	void improve() {
		cout << "The operation began" << endl;
	}
	/*void narcoz() {
		cout << "Narcoz vveli" << endl;
	}*/
	void replace() {
		cout << "Brain has been cured" << endl;
	}
	void cut_out() {
		cout << "During the procedure brain has been stolen :(" << endl;
	}
};

class organ_createtor {
public:
	virtual Organ *make_organ_better(string  a) = 0;
	virtual Organ *robb_organ(string  a) = 0;
};

class medic_in_India : organ_createtor {
public:
	medic_in_India() {
		cout << "your medic is Indian" << endl;
	}
	Organ *make_organ_better(string  a) {
		if (a =="Mozg") {
			return new Mozg_brain;
		}
		if (a == "Heart") {
			return new Heart_serdce;
		}
	}

	Organ *robb_organ(string  a) {
		Organ *organ = make_organ_better(a);
			organ->improve();
			//organ->narcoz();
			organ->replace();


		organ->cut_out();
		return organ;
	}
};

class medic_in_Burma: organ_createtor {
public:
	medic_in_Burma() {
		cout << "your medic is Birmanian" << endl;
	}
	Organ *make_organ_better(string a) {

		if (a == "Kidney") {
			return new Pochka_Kidney;
		}
		if (a == "Liver") {
			return new Pechen_Liver;
		}
	}

	Organ *robb_organ(string a) {
		Organ *organ = make_organ_better(a);

			organ->improve();
			//organ->narcoz();
			organ->replace();


			organ->cut_out();
		return organ;
	}
};

void main() {
	medic_in_India i;
	medic_in_Burma b;
	i.robb_organ("Mozg");
	i.robb_organ("Heart");
	b.robb_organ("Kidney");
	b.robb_organ("Liver");




}