#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>

#define ERROR_INT "ERROR! Wrong int value (ошибка ввода целочисленного значения). Try again..."

using namespace std;

int rand_number(int a, int b) {
	if (a > b) {
		int t = a;
		a = b;
		b = t;
	}
	return rand() % (b + 1 - a) + a;
}

bool rand_operation() {
	return rand() % 2;
}

string convert_to_string(long time, bool flag) {
	int hour = (time / 3600 + (flag ? 3 : 0)) % 24;
	int min = time % 3600 / 60;
	int sec = time % 60;

	string stime = to_string(hour);
	stime += (min > 9 ? ":" : ":0") + to_string(min);
	stime += (sec > 9 ? ":" : ":0") + to_string(sec);

	return stime;
}

int read_int(string prompt) {
	string input;

	while (true) {
		bool flag = true;

		cout << prompt;
		cin >> input;

		for (int i = 0; i < input.size(); i++)
		{
			if (!isdigit(input[i])) {
				cout << ERROR_INT << endl;
				flag = false;
				break;
			}
		}

		if (flag) {
			break;
		}
	}

	return stoi(input);
}
