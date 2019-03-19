	// ConsoleApplication136.cpp : Defines the entry point for the console application.
	//

	#include"stdafx.h"
	#include <iostream>
	#include <vector>
	#include <string>
	using namespace std;

	class Ukraina
	{
	public:
		vector <int> dolg;
		void Create()
		{
			cout << "Ukraina was created" << endl;
		}
		void Add(int amount)
		{
			if (dolg.size() != 0)
			{
				dolg.push_back(dolg.back() + amount);
					cout << "GOSDOLD VIROS NA " << amount << " GRIVEN!!!!" << endl;
			}
			else
			{
				dolg.push_back(amount);
				cout << "CONGRATS ETO VASH PERVII DOLG NA UKRAINE!!!" << endl;
			}

		}
		void Inc(int amount)
		{
			if (dolg.size() != 0)
			{
				dolg.push_back(dolg.back() - amount);
				cout << "GOSDOLD UMENSHILSYA NA " << amount << " GRIVEN!!!!" << endl;
			}
			else
			{
				dolg.push_back(amount);
				cout << "erorr!!!!!!" << endl;
			}

		}
		void Cntr_z()
		{
			if (dolg.size()!=0)
			{
				dolg.pop_back();
				cout << "Otmena poslednego kredita" <<endl;
			}
			else
				cout << "erorr!!!!!!" << endl;
		}

		void Show()
		{
			for (int i = 0; i<dolg.size(); ++i)
			{
				cout << i + 1 << ". " << dolg[i] << endl;
			}
		}
		void Show_last()
		{
			cout <<"Itogo dolg sostavil:  "<<dolg.back()<<endl;
		}
	};

	class Komanda
	{
	public:
		Ukraina * ukraina;
		virtual void Execute() = 0;
		virtual void Undo() = 0;
		void fit(Ukraina * ukr)
		{
			ukraina = ukr;
		}
	};

	class Add_class : public Komanda
	{
	public:
		int GOS_DOLG;
		Add_class(int _GOS_DOLG) : GOS_DOLG(_GOS_DOLG) {}
		void Execute()
		{
			ukraina->Add(GOS_DOLG);
		}
		void Undo()
		{
			ukraina->Cntr_z();
		}
	};
	class Inc_class : public Komanda
	{
	public:
		int GOS_DOLG;
		Inc_class(int _GOS_DOLG) : GOS_DOLG(_GOS_DOLG) {}
		void Execute()
		{
			ukraina->Inc(GOS_DOLG);
		}
		void Undo()
		{
			ukraina->Cntr_z();
		}
	};

	class Poluchatel
	{
	public:
		vector<Komanda*> Komands;
		Ukraina ukraina;
		Komanda* komand;
		void ADD(int GOS_DOLG)
		{
			komand = new Add_class(GOS_DOLG);
			komand->fit(&ukraina);
			komand->Execute();
			Komands.push_back(komand);
		}
		void INC(int GOS_DOLG)
		{
			komand = new Inc_class(GOS_DOLG);
			komand->fit(&ukraina);
			komand->Execute();
			Komands.push_back(komand);
		}
		void UNDO()
		{
			if (Komands.size() == 0)
			{
				cout << "DOLGA NET!!!!!!" << endl;
			}
			else
			{
				komand = Komands.back();
				Komands.pop_back();
				komand->Undo();
				delete komand;
			}
		}

		void Show()
		{
			ukraina.Show();
		}

		void Show_last()
		{
			ukraina.Show_last();
		}
	};

	int main()
	{
		Poluchatel ukr;
		char s='1';
		int gos_dolg;
		while (s!='4')
		{
			cout << "What to do: \n1.Dobavit' dolg \n2.Viplatit' dolg \n3.Otmenit' poslednee deistvie \n4.Vihod " << endl;
			cin >> s;
			switch (s)
			{
			case '1':
				{	cout << "Na skolko uvelichit'?: ";
					cin >> gos_dolg;
					ukr.ADD(gos_dolg);
					break;
				}
			case '3':
				{
					ukr.UNDO();
					break;
				}
			case '2':
				{
					cout << "Kakova viplata?: ";
					cin >> gos_dolg;
					ukr.INC(gos_dolg);
					break;
				}
			case '4':
				{	
					break;
				}
			}
			if (s != '4')
			{
				cout << "----------------" << endl;
				ukr.Show();
				cout << "----------------" << endl;
			}
			else 
				ukr.Show_last();

		}
	
	}











