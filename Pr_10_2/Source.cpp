#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

int FindindexFirst(string& s) {
	int indexFirst = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			indexFirst = i;
			break;
		}
	}
	return indexFirst;
}

int FindindexLast(string& s) {
	int indexLast = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ')') {
			indexLast = i;
		}
	}
	return indexLast;
}

bool FindToDo(string& s) {
	int k = 0;
	bool answer;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == '(' || s[i] == ')') {
			k++;
		}

	if (k > 2) {
		answer = false;
	}
	else
		answer = true;

	return answer;
}

string Delete(string& s) {
	size_t pos = 0;

	string first = "(";
	string last = ")";

	int indexFirst = FindindexFirst(s);
	int indexLast = FindindexLast(s);
	int k = 0;

	bool answer = FindToDo(s);

	if (answer == false) {
		return "Error.";
	}
	else {
		int length = indexLast - indexFirst + 1;
		pos = indexFirst;
		s = s.erase(pos, length);
		return s;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	fstream f1;
	fstream f2;

	f1.open("t1.txt");
	f2.open("t2.txt");

	char line[80];

	f1.getline(line, sizeof(line));

	string convert = line;
	string converted = Delete(convert);

	cout << " Початковий рядок у файлі 't1.txt': " << line << endl;
	cout << " Змінений рядок, який буде записано у файл 't2.txt': " << Delete(convert) << endl;
	f2 << converted;

	f2.close();
	f1.close();
	return 0;
}