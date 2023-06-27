#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include "Tusk.h"

class Table {
private:
	std::vector<Tusk> table;
public:
	void Meny() {//Стартове меню программи
		int answ;
		std::cout << "Розпочнемо!" << std::endl;
		std::cout << "Будь-ласка,оберіть дію:\n" <<
			"(0) Переглянути завдання\n" <<
			"(1) Створити нове завдання\n" <<
			"(2) Редагувати завдання\n" <<
			"(3) Видалити завдання\n" <<
			"(4) Завершити роботу\n" <<
			"\nВаш вибір: ";
			std::cin >> answ;
			if (answ >=0 && answ<=4 ) {
				Answ(answ);
			}
			else {
				Eror();
			}
	}

	void Answ(int answ) {
		if (answ == 0) {//Вивести все на екран
			system("cls");
			for (int i = 0; i < table.size(); i++) {
				std::cout << "Завдання " << i << ": ";
				table[i].getAll();
			}
			system("pause");
			system("cls");
			Meny();
		}
		else if (answ == 1) {// Додати завдання на дошку
			system("cls");
			Tusk myTusk;
			myTusk.setName();
			myTusk.setData();
			myTusk.setStatus();
			table.push_back(myTusk);
			system("pause");
			system("cls");
			Meny();
		}
		else if (answ == 2) {//Редагувати завдання на дошці
			system("cls");
			int temp;
			std::cout << "Оберіть завдання: \n";
			for (int i = 0; i < table.size(); i++) {
				std::cout << "Завдання " << i << ": "<<std::endl;
				table[i].getName();
			}
			std::cout << "Ваш вибір: ";
			std::cin >> temp;
			try {
				table[temp].edit();
			}
			catch (const std::exception& ex) {
				Eror();
			}
			system("pause");
			system("cls");
			Meny();
		}
		else if (answ == 3) {//Видалити завдання
			system("cls");
			int temp;
			std::cout << "Оберіть завдання: \n";
			for (int i = 0; i < table.size(); i++) {
				std::cout << "Завдання " << i << ": ";
				table[i].getName();
			}
			std::cout << "Ваш вибір: ";
			std::cin >> temp;
			try {
				table.erase(table.begin()+temp);
			}
			catch (const std::exception& ex) {
				Eror();
			}
			system("pause");
			system("cls");
			Meny();
		}
		else if (answ == 4) {//Вийти з программи
			system("cls");
			std::cout << "Всього найкращого!";
			return;
		}
		else {
			system("cls");
			Eror();
			system("pause");
			system("cls");

		}
	}
	void Eror() {//Функція яка виводе помилку
		system("cls");
		std::cout << "Увага!\nОбрана неіснуюча дія,будь-ласка спробуйте ще раз" << std::endl;
		system("pause");
		system("cls");
	}
	
};
