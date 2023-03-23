#include "main.h"
#include "Windows.h"

#define MIN_NUMBER 0
#define MAX_NUMBER 9

#define ERROR_INT "ERROR! Wrong int value. Try again..."
#define ERROR_MSG "ERROR! Wrong answer. Try again..."


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

string convert_to_string(long time) {
	int hour = time / 3600 % 24;
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


int main() {
	srand(time(NULL));

	int number = read_int("Input number of exercise: ");
	
	cout << "\nLet's do it... " << endl;
	long start_time = time(NULL);
	cout << "\nSTART time: " + convert_to_string(start_time) << endl;
	
	int error = 0;
	int count = 0;

	for (int i = 0; i < number; i++)
	{
		int a = rand_number(MIN_NUMBER, MAX_NUMBER);
		int b = rand_number(MIN_NUMBER, MAX_NUMBER);
		
		bool operation = rand_operation();
				
		if (a < b && !operation) {
			int t = a;
			a = b;
			b = t;
		}

		string msg = to_string(i + 1) + ") ";
		msg += to_string(a);
		msg += operation ? " + " : " - ";
		msg += to_string(b) + " = ";

		int result = operation ? a + b : a - b;
		int answer;

		do {
			answer = read_int(msg);
			if (answer != result) {
				cout << ERROR_MSG << endl;
			}
		} while (answer != result);
	}


	long finish_time = time(NULL);
	cout << "\nFINISH time: " + convert_to_string(finish_time) << endl;

	cout << "\nYour TOTAL time for exercises: " + convert_to_string(finish_time - start_time) << endl;

	return 0;
}
