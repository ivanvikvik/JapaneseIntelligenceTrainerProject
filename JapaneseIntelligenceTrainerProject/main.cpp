#include "main.h"

#define MIN_NUMBER 1
#define MAX_NUMBER 9

#define ERROR_INT "ERROR! Wrong int value (ошибка ввода целочисленного значения). Try again..."
#define ERROR_MSG "ERROR! Wrong answer (неправильный ответ). Try again..."

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

	setlocale(LC_ALL, "Rus");

	char yesno;

	do {
		system("cls");

		cout << "Exercises that you perform for just 2-5 minutes every day";
		cout << "\nhelp to actively develop your memory, thinking and attention.";

		cout << "\n\nУпражнения, которые Вы выполняете всего 2-5 минут каждый день,";
		cout << "\nпомогаю активно развивать память, мышление и внимание.\n";

		int number = read_int("\nInput number of exercise (количество решаемых примеров): ");

		cout << "\nLet's do it (сделаем это)!" << endl;
		long start_time = time(NULL);
		cout << "\nSTART time: " + convert_to_string(start_time) << "\n\n";

		int error = 0;
		int count = 0;

		for (int i = 0; i < number; i++)
		{
			int a = rand_number(MIN_NUMBER, MAX_NUMBER);

			int b = rand_number(MIN_NUMBER, MAX_NUMBER);
			while (b == a) {
				b = rand_number(MIN_NUMBER, MAX_NUMBER);
			}
			
			int c = rand_number(MIN_NUMBER, MAX_NUMBER);
			while (c == a || c == b) {
				c = rand_number(MIN_NUMBER, MAX_NUMBER);
			}

			bool operation = rand_operation();

			if (a < b && !operation) {
				int t = a;
				a = b;
				b = t;
			}

			int result = operation ? a + b - c : a - b + c;

			if (result < 0) {
				int t = b;
				b = c;
				c = t;

				result = operation ? a + b - c : a - b + c;
			}

			string msg = to_string(i + 1) + ") ";
			msg += to_string(a);

			if (operation) {
				msg += " + " + to_string(b) + " - ";
			}
			else {
				msg += " - " + to_string(b) + " + ";
			}
			
			msg += to_string(c) + " = ";
			
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

		cout << "\nYour TOTAL time for exercises (Ваше общее время): " + convert_to_string(finish_time - start_time) << endl;

		cin.ignore();
		cout << "\nTry again (попробуем ещё раз)? (y/n)";
		yesno = _getch();

		yesno = tolower(yesno);

	} while (yesno == 'y');

	system("cls");

	cout << "\nDo not forget about daily training to develop your intellect.";
	cout << "\nNo excuses... ";
	cout << "\nНе забывайте о ежедневных тренировках для развития себя и своего интеллекта.";
	cout << "\nНикаких оправданий!";
	cout << "\n\nSee you... :)\n\n";

	return 0;
}
