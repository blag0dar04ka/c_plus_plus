#include "stdafx.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h>
#include <mutex>

using namespace std;

class vodi4ka {
private:
	int hot, cold, duration,time,sum=0,sum_w=0;
	mutex mtx;
	void setParams(int &time) {
		cout << "\Enter debits of hot/cold water: ";
		cin >> hot >> cold;
		time = 0;
		
	}
public:	
	vodi4ka() : hot(0), cold(0) {}

	void showRes() {
		cout << "The temperature of hot water is 50C and cold one is 10C " << endl;
		time = 0;
		int a = 0;
		int b = 0;
		int tmp = 0;
		int temp = 0;
		int was_set = 0;
		while (this->duration != 0) {
					this_thread::sleep_for(chrono::seconds(1));
					mtx.lock();
					this->duration -= 1;
					time += 1;
					sum = this->hot * 50*time  + this->cold * 10*time;
					sum_w= this->hot*time + this->cold*time;
					if (time == 1 && (was_set))
					{
						a += temp;
						b += tmp;
						temp = 0;
						tmp = 0;

					}
						if ((this->hot + this->cold)!=0) {
							cout << "Time till end: " << duration << " temperature: " << (a+sum) / (b+sum_w) << "C\n";
						}
						else {
							if (b!=0)
								cout << "Time till end: " << duration << " temperature: " << a/b << "C\n";
							else cout << "Time till end: " << duration << " temperature: " << 0 << "C\n";
						}
					
						temp = this->hot * 50 * time + this->cold * 10 * time;
						tmp = this->hot*time + this->cold*time;
					mtx.unlock();
					was_set = 1;
		}
	}
	void runvodi4ka() {
		cout << "Enter a number of time for confluence of threads of water: ";
		cin >> duration;
		setParams(time);
		thread t(&vodi4ka::showRes, this);
		while (1) {
			mtx.lock();
			if (duration == 0) {
				mtx.unlock();
				break;
			}
			mtx.unlock();
			if (_kbhit())
			{
				int c = _getch();
				if (c == 0x1B)
				{
					mtx.lock();
					setParams(time);
					mtx.unlock();
				}
			}
		}
		t.join();
	}
};

int main() {
	cout << "Press ESC for changings" << endl;
	vodi4ka a;
	a.runvodi4ka();
	return 0;
}
