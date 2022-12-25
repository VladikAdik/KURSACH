#include "Labs.h"
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

void Insertsort(int A[]) {
	int key, j;

	for (int i = 0; i < 100; ++i) {
		key = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > key) {
			A[j + 1] = A[j];
			j -= 1;
		}
		A[j + 1] = key;
	}
}

void Viewmassive(int A[]) {
	for (int i = 0; i < 100; i++)
		cout << A[i] << " ";
	cout << "\n";
}//��� ������� ������ ���������� ������

void Lab2() {
	setlocale(0, "");

	char input = 0;
	int A[100], Ac[100];

	srand(time(0));

	cout << "��������� ������:\n";

	for (int i = 0; i < 100; ++i)
		A[i] = -99 + rand() % 199;//1 ������

	for (int i = 0; i < 100; ++i)
		Ac[i] = A[i];//2 ������

	Viewmassive(A);
	cout << "\n";

	Menu: {
		for (int i = 0; i < 100; ++i)
			A[i] = Ac[i];//������ Ac[] ��������� ��� �����, � ������� ������������ ���������� ������ A[]. ��� ��� ��� ��� �������� ������ ���������������

		cout << "1. ������������� ����� ������\n";
		cout << "2. ������������� ������\n";
		cout << "3. ����� ������������ � ����������� �������� �������\n";
		cout << "4. ����� ������� �������� ������������� � ������������ ��������\n";
		cout << "5. ����� ���������� ��������� ������� ����� X\n";
		cout << "6. ����� ���������� ��������� ������� ����� X\n";
		cout << "7. ����� ����� � �������\n";
		cout << "8. �������� ������� �������� �������\n";
		cout << "9. ��������� ��������� ���������\n";
		cout << "������� ����� ��������, ������� ������ ���������: ";
		cin >> input;
		cout << "\n";
	}

	switch (input) {
		case '1': {
			system("cls");
			cout << "����� ������:\n";
			srand(time(0));
			for (int i = 0; i < 100; ++i)
				Ac[i] = -99 + rand() % 199;
			Viewmassive(A);
			cout << "\n";
			goto Menu;
		}

		case '2': {
			system("cls");
			cout << "��������������� ������:\n";
			Insertsort(A);
			Viewmassive(A);
			cout << "\n";
			goto Menu;
		}

		case '3': {
			Insertsort(A);
			int min = 100, max = -100;
			auto start = chrono::steady_clock::now();
			min = A[0];
			max = A[99];
			auto end = chrono::steady_clock::now();

			cout << "������������ �������: " << max << "\n����������� �������: " << min << "\n";
			cout << "���������������: ";
			cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ����������\n";

			min = 100;
			max = -100;
			start = chrono::steady_clock::now();
			for (int i = 0; i < 100; i++) {
				if (Ac[i] > max)
					max = A[i];
				if (Ac[i] < min)
					min = Ac[i];
			}
			end = chrono::steady_clock::now();

			cout << "�����������������: ";
			cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ����������\n\n";
			goto Menu;
		}

		case '4': {
			Insertsort(A);
			int max = A[99], min = A[0];
			double mid = round((max + min) / 2);
			cout << "������� ��������: " << mid << "\n";

			auto start = chrono::steady_clock::now();
			int count = 0;
			for (int i = 0; i < 100; i++) {
				if (Ac[i] == mid)
					count += 1;
			}
			auto end = chrono::steady_clock::now();

			cout << "������� " << count << " ������� �����. ��� ��������� �� ��������: ";

			for (int i = 0; i < 100; i++) {
				if (Ac[i] == mid)
					cout << i + 1 << " ";
			}
			cout << "\n����� ������: ";
			cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ����������\n\n";

			goto Menu;
		}// ��� ����� ���� ���������� ��� �����, �� ��� ��� ���� �����

		case '5': {
			int x, count = 0;
			cout << "������� ����� X: ";
			cin >> x;

			Insertsort(A);
			for (int i = 0; i < 100; i++) {
				if (A[i] < x)
					count += 1;
			}
			cout << "���-�� ��������� ������� " << x << " = " << count << "\n\n";
			goto Menu;
		}

		case '6': {
			int x, count = 0;
			cout << "������� ����� X: ";
			cin >> x;

			Insertsort(A);
			for (int i = 0; i < 100; i++) {
				if (A[i] > x)
					count += 1;
			}
			cout << "���-�� ��������� ������� " << x << " = " << count << "\n\n";
			goto Menu;
		}

		case '7': {
			Insertsort(A);
			int left = -99, right = 99;
			int mid, key;

			cout << "������� ������� �����: ";
			cin >> key;
			auto start = chrono::steady_clock::now();
			while (left < right) {
				mid = (left + right) / 2;

				if (A[mid] > key)
					right = mid;
				else
					left = mid + 1;
			}
			right -= 1;
			auto end = chrono::steady_clock::now();

			if (A[right] == key)
				cout << "\n����� ����� � ������� ����\n";
			else
				cout << "\n������ ����� � ������� ���\n";// ��� �������� �����

			cout << "����� ������: ";
			cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ����������\n";

			start = chrono::steady_clock::now();
			bool k = false;
			for (int i = 0; i < 100; i++) {
				if (A[i] == key) {
					k = true;
				}
			}// ��� ����� ���������

			end = chrono::steady_clock::now();
			cout << "����� ������ ���������: ";
			cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ����������\n\n";

			goto Menu;
		}

		case '8': {
			int x1, x2;
			cout << "������� 2 ��������, ������� �� ������ �������� �������: ";
			cin >> x1 >> x2;
			cout << "\n";

			auto start = chrono::steady_clock::now();
			swap(Ac[x1 - 1], Ac[x2 - 1]);
			auto end = chrono::steady_clock::now();

			Viewmassive(Ac);

			cout << "�������� ������: ";
			cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ����������\n\n";

			goto Menu;
		}//����� ������ 2 ������� �������� ����

		default: {
			cout << "������, ��� �������� �����. ��������� ������ �����.\n\n";
			goto Menu;
		}

		case '9': {
			exit;
		}
	}
}