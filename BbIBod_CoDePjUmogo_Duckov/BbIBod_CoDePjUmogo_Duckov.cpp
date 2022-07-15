#pragma once
//#define _CRT_SECURE_NOWARNINS
#include <iostream>
#include <fstream>
#include <iostream>
#include <Windows.h>
#include <string.h>
#include <string>
#include <cstdio>
#include <direct.h>
#include <io.h>
#include "Windows.h"

using namespace std;
void DiskContents(string disk)
{
	std::locale::global(std::locale("rus"));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	//_finddata_t  возвращают сведения о файле
	_finddata_t data;
	//intptr_t  является знаковым целочисленным memsize-типом и способен 
	//безопасно хранить в себе указатель в независимости от разрядности платформы
	//_findfirst предоставляет сведения о первом экземпляре имени файла

	//cin.ignore();
	string path1;
	cout << "Введи имя диска о котормо хочешь узнать иформацию.\n";
	cout << "Пример: C:\\* \n";
	cout << "Ввод: ";
	getline(cin, path1);
	const char* path2 = &path1[0];

	intptr_t handle = _findfirst(path2, &data);
	if (_findfirst(path2, &data) !=  _set_errno(0))
	{
		do
		{
			//width() устанавливает ширину поля и возвращает текущую ширину
			cout.width(30);
			//_A_SUBDIR Подкаталог. Значение: 0x10
			if (data.attrib & _A_SUBDIR)
			{
				cout << data.name << "\t[папка]" << endl;
			}
			else
			{
				cout << data.name << "\t[фаил]\t" << data.size / 1024 << "KB\t" << endl;
			}
			//_findnext находит следующее имя, если таковое имеется
		} while (_findnext(handle, &data) == 0);
	
	//_findclose закрывает указанный дескриптор поиска и освобождает все связанные ресурсы 
	_findclose(handle);
	system("pause");
	system("cls");
    }
	else
	{
		cout << "Ошибка ";
	}
}

int main()
{
	string diskC;
	DiskContents(diskC);
}

