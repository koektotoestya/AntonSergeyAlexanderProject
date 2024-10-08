﻿#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

void add_note() {
	string file, line;
	cout << "Enter note name" << endl;
	cin >> file;
	ofstream out(file + ".txt", std::ios::app);
	out << file << endl;
	cout << "Enter today's date" << endl;
	cin >> line;
	out << line << endl;
	cout << "Enter description" << endl;
	cin >> line;
	out << line << endl;
	out << "0";
	out.close();
}

void is_complete() {
	string file, line;
	cout << "Enter note name" << endl;
	cin >> file;
	file += ".txt";
	ifstream in(file);
	if (in.is_open())
	{
		while (getline(in, line))
		{
		}
	}

	if (line == "1") {
		cout << "Task completed" << endl;
	}
	else if (line == "0") {
		cout << "Task isn't complete" << endl;
	}
	in.close();
}

void edit_mainBody() {
	string file, line, buf;
	buf = "buf.txt";
	cout << "Enter note name" << endl;
	cin >> file;
	file += ".txt";
	ifstream in(file);
	if (in.is_open()) {
		ofstream out("buf.txt", std::ios::app);
		for (int i = 0; i < 2; i++) {
			getline(in, line);
			out << line << endl;
		}
		cout << "Enter new note description" << endl;
		cin >> line;
		out << line << endl;
		while (1) {
			cout << "Is your task completed?(write 1, if your task is completed, or write 0, if not" << endl;
			cin >> line;
			if ((line == "1") || (line == "0"))
			{
				break;
			}
		}
		out << line;
		in.close();
		out.close();
		remove(file.c_str());
		rename(buf.c_str(), file.c_str());
	}
}

void delete228() {
	string file;
	cout << "Enter note name" << endl;
	cin >> file;
	file += ".txt";
	remove(file.c_str());
}

void show_note() {
	string file, line;
	cout << "Enter note name" << endl;
	cin >> file;
	file += ".txt";
	ifstream in(file);
	for (int i = 0; i < 3;i++) {
		getline(in, line);
		cout << line << endl;
	}
	in.close();
}

int main() {
	cout << "List of commands:" << endl;
	cout << "add_note" << endl;
	cout << "is_complete" << endl;
	cout << "edit_mainbody" << endl;
	cout << "delete" << endl;
	cout << "show_note" << endl;
	string userCommand, line, fileName;
	cin >> userCommand;
	if ((userCommand == "add_note") || (userCommand == "Add_note")) {
		add_note();
	}
	else if ((userCommand == "is_complete") || (userCommand == "Is_complete")) {
		is_complete();
	}
	else if ((userCommand == "edit_mainbody") || (userCommand == "Edit_mainbody")) {
		edit_mainBody();
	}
	else if ((userCommand == "delete") || (userCommand == "Delete")) {
		delete228();
	}
	else if ((userCommand == "show_note") || (userCommand == "Show_note")) {
		show_note();
	}
}