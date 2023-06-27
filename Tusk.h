#pragma once
#include <iostream>
#include <string>
#include <Windows.h>


class Tusk {
private:
	std::string name;
	std::string data;
	std::string status;
public:
	Tusk() :name(""), data(""), status("") {}
	void setName() {
		std::cin.ignore(32767, '\n');
		std::string t_name;
		std::cout << "����� ����� ��������:"<<std::endl;
		std::getline(std::cin, t_name);
		name = t_name; 
	}
	void setData() {
		std::cin.ignore(32767, '\n');
		std::string t_data;
		std::cout << "����: " << std::endl;
		std::getline(std::cin,t_data);
		data = t_data;
	}
	void setStatus() { 
		int temp;
		std::cout << "������ ������:\n" <<
			"(0) �� ��������\n" <<
			"(1) ��������\n" <<
			"\n���� ��: ";
		std::cin >> temp;
		if (temp == 0) {
			status = "�� ��������";
		}
		else if (temp == 1) {
			status = "��������";
		}
		else {
			std::cout << "������ �������� ��,��������� �� ���!";
		}
 
	}
	void getName() {
		std::cout << name << std::endl;
	}
	void getAll() {
		std::cout << "Tusk name: " <<name<< std::endl;
		std::cout << "Data: " << data << std::endl;
		std::cout << "Status: " << status << std::endl;
	}
	void edit() {
		int temp;
		std::cout << "������ �����:\n" <<
			"(0) �����\n" <<
			"(1) ����\n" <<
			"(2) ������\n" <<
			"\n���� ������: ";
		std::cin >> temp;
		try
		{
			if (temp == 0) {
				setName();
			}
			else if (temp == 1) {
				setData();
			}
			else if (temp == 2) {
				setStatus();
			}
		}
		catch (const std::exception& ex)
		{
			return;
		}
		

	}
	~Tusk() {}
};