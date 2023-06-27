#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include "Tusk.h"

class Table {
private:
	std::vector<Tusk> table;
public:
	void Meny() {//�������� ���� ���������
		int answ;
		std::cout << "����������!" << std::endl;
		std::cout << "����-�����,������ ��:\n" <<
			"(0) ����������� ��������\n" <<
			"(1) �������� ���� ��������\n" <<
			"(2) ���������� ��������\n" <<
			"(3) �������� ��������\n" <<
			"(4) ��������� ������\n" <<
			"\n��� ����: ";
			std::cin >> answ;
			if (answ >=0 && answ<=4 ) {
				Answ(answ);
			}
			else {
				Eror();
			}
	}

	void Answ(int answ) {
		if (answ == 0) {//������� ��� �� �����
			system("cls");
			for (int i = 0; i < table.size(); i++) {
				std::cout << "�������� " << i << ": ";
				table[i].getAll();
			}
			system("pause");
			system("cls");
			Meny();
		}
		else if (answ == 1) {// ������ �������� �� �����
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
		else if (answ == 2) {//���������� �������� �� �����
			system("cls");
			int temp;
			std::cout << "������ ��������: \n";
			for (int i = 0; i < table.size(); i++) {
				std::cout << "�������� " << i << ": "<<std::endl;
				table[i].getName();
			}
			std::cout << "��� ����: ";
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
		else if (answ == 3) {//�������� ��������
			system("cls");
			int temp;
			std::cout << "������ ��������: \n";
			for (int i = 0; i < table.size(); i++) {
				std::cout << "�������� " << i << ": ";
				table[i].getName();
			}
			std::cout << "��� ����: ";
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
		else if (answ == 4) {//����� � ���������
			system("cls");
			std::cout << "������ ����������!";
			return;
		}
		else {
			system("cls");
			Eror();
			system("pause");
			system("cls");

		}
	}
	void Eror() {//������� ��� ������ �������
		system("cls");
		std::cout << "�����!\n������ �������� ��,����-����� ��������� �� ���" << std::endl;
		system("pause");
		system("cls");
	}
	
};
