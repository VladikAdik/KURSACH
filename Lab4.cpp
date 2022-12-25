#include "Labs.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string text;

void DeleteSpace(string txt) {
    for (int i = 0; i < txt.size(); i++) {
        if (txt[i] == ' ' && txt[i + 1] == ' ')
            while (txt[i + 1] == ' ')
                txt.erase((i + 1), 1);
    }
    text = txt;
}

void DeleteSign(string txt) {
    for (int i = 0; i <= txt.size(); i++) {
        if ((txt[i] == '.' || txt[i] == ',' || txt[i] == ';' || txt[i] == ':' || txt[i] == '!' || txt[i] == '?') && (txt[i + 1] == '.' || txt[i + 1] == ',' || txt[i + 1] == ';' || txt[i + 1] == ':' || txt[i + 1] == '!' || txt[i + 1] == '?'))
            if (txt[i] == '.' && txt[i + 1] == '.' && txt[i + 2] == '.' && txt[i + 3] == ' ')
                i += 3;
            else {
                while (txt[i + 1] == '.' || txt[i + 1] == ',' || txt[i + 1] == ';' || txt[i + 1] == ':' || txt[i + 1] == '!' || txt[i + 1] == '?')
                    txt.erase((i + 1), 1);
            }
    }
    text = txt;
}

void Register(string txt) {
    for (int i = 0; i < txt.size(); i++) {
        if (txt[i] == ' ')
            i += 2;
        txt[i] = tolower(txt[i]);
    }
    text = txt;
}

void UpFirst(string txt) {
    txt[0] = toupper(txt[0]);
    for (int i = 0; i < txt.size(); i++) {
        if (txt[i] == ' ')
            txt[i + 1] = toupper(txt[i + 1]);
    }
    text = txt;
}

void Search(string txt) {
    string key;
    bool check;
    int count = 0;

    cin >> key;

    for (int i = 0; i < txt.size(); i++) {
        if (txt[i] == key[0]) {
            check = true;
            for (int j = 1; j < key.size(); j++) {
                if (txt[i + j] != key[j]) {
                    check = false;
                }
            }
            if (check == true) {
                count++;
                cout << "������� " << i << "\n";
            }
        }
    }
    if (count == 0) {
        cout << "�� ������� ������ �� �������";
    }
    else {
        cout << "����� ������� " << count << " ������������";
    }
}

void Lab4() {
    setlocale(0, "");

    /*  1 �������  */ {
        char input;
    Menu: {
        cout << "�������� ����� ��� ��������� ��� � �����?\n"
            "1. ��������\n"
            "2. ��������� � �����\n";
        cin >> input;
        }
    if (input == '1') { // ������������ ��� ������ �����
        cin.ignore();
        getline(cin, text);
    }
    else if (input == '2') { // ������������ ��������� ����
        ifstream in("D:\\ProgrammingShit\\C\\KURSACH\\test.txt");
        if (in.is_open())
            getline(in, text);
        in.close();
    }
    else {
        system("cls");
        goto Menu;
    }

    cout << "1) �������� ������: " << text << "\n";
    }

    /*  2 �������  */ {
        DeleteSpace(text);
        DeleteSign(text);
        Register(text);

        cout << "2) ����������������� ������: " << text << "\n";
    }

    /*  3 �������  */ {
        cout << "3) C����� � �������� �������: ";
        int a = 0;
        text += " ";

        for (int i = text.length(); i >= 0; i--) {
            if (text[i] == ' ') {
                for (int k = i + 1; k <= (i + a); k++) {
                    cout << text[k];
                }
                a = 0;
            }
            a++;
        }
        for (int i = 0; i < text.length(); i++) {
            if (text[i] == ' ') break;
            cout << text[i];
        }
    }

    /*  4 �������  */ {
        UpFirst(text);

        cout << "\n4) ��� ����� � ��������� �����: " << text << "\n";
    }

    /*  5 �������  */ {
        cout << "5) ������� ���������, ������� �� ������ ����� (������, ��� ����� ����� ����������� � �������� ������ �� �������� ������)\n";
        Search(text);
    }

    cout << "\n";
}