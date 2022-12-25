#include <iostream>
#include "Labs.h"

using namespace std;

int main()
{
    setlocale(0, "");
    char input;

    Menu: {
        system("cls");
        cout << "Введите номер практической работы, которую вы хотите запустить:\n"
            "1. Типы данных и их внутреннее представление в памяти.\n"
            "2. Одномерные статические массивы.\n"
            "3. Двумерные статические массивы. Указатели.\n"
            "4. Текстовые строки как массивы символов.\n"
            "5. ЗАКРЫТЬ ПРОГРАММУ.\n";
    }
    cin >> input;

    switch (input) {
    case '1': {
        system("cls");
        Lab1();
        system("pause");
        goto Menu;
    }
    case '2': {
        system("cls");
        Lab2();
        system("pause");
        goto Menu;
    }
    case '3': {
        system("cls");
        Lab3();
        system("pause");
        goto Menu;
    }
    case '4': {
        system("cls");
        Lab4();
        system("pause");
        goto Menu;
    }
    default: {
        goto Menu;
    }
    case '5': {
        exit;
    }
    }
}