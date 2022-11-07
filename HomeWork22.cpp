#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//���������� ������� ���������� �������
template <typename T>
void fill_arr(T arr[], const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (end - begin) + begin;
}
//����� ������� � �������
template <typename T>
void show_arr(T arr[], const int length) {
	cout << '[';
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}
//������ ������� ������ � �������� �������� �������
template <typename T>
void arr_pswap(T *arr, const int length) {
	cout << "�������� ������:\n";
	cout << '[';
	for (int i = 0; i < length; i += 2) {
		int tmp = *(arr + i);
		*(arr + i) = *((arr + i) + 1);
		*((arr + i) + 1) = tmp;

		cout << *(arr + i) << ", " << *((arr + i) + 1) << ", ";
	}
	cout << "\b\b]\n";
}

//���������� ����� � ������� 
void func(int* num1, int num2) {
	int res = 1;
	for (int i = 1; i <= num2; i++) {
		res *= *num1;		
	}
	*num1 = res;
}

//���������� ����� � ������� v2
void func2(int* num1, int *num2) {
	int res = 1;
	for (int i = 1; i <= *num2; i++) {
		res *= *num1;		
	}
	*num1 = res;
}



int main() {
	setlocale(LC_ALL, "Russian");	

	// ������ 22.1.
	cout << "������ 22.1. ������� 1.\n����������� ������: \n";
	const int size = 10;
	int mass[size];
	
	fill_arr(mass, size, 1, 11);
	show_arr(mass, size);
	cout << "�������� ������:\n";
	cout << '[';
	for (int i = 0; i < size; i += 2) {
		int tmp = *(mass + i);
		*(mass + i) = *((mass + i) + 1);
		*((mass + i) + 1) = tmp;

		cout << *(mass + i) << ", " << *((mass + i) + 1) << ", ";
	}
	cout << "\b\b]\n";

	cout << "\n������ 22.1. ������� 2.\n����������� ������: \n";
	const int size2 = 10;
	int mass2[size2] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	cout << '[';
	for (int i = 0; i < size2; i++)
		cout << mass2[i] << ", ";
	cout << "\b\b]\n";
	
	int* pmass = &mass2[0];
	cout << "�������� ������:\n";
	cout << '[';
	for (int i = 0; i < size2; i+=2) {
		int tmp = *(pmass + i);
		*(pmass + i) = *((pmass+i) + 1);
		*((pmass+i) + 1) = tmp;

		cout << *(pmass + i) << ", " << *((pmass + i) + 1) << ", ";
	}
	cout << "\b\b]\n";

	cout << "\n������ 22.1. ������� 3.\n����������� ������: \n";
	const int size3 = 10;
	int mass3[size3];
	fill_arr(mass3, size3, 1, 11);
	show_arr(mass3, size3);
	arr_pswap(mass3, size3);
	
	// ������ 22.2.
	cout << "\n������ 22.2.������� 1.\n";
	int n = 10;	
	func(&n, 3);
	cout << "��������� = " << n << "\n\n";

	cout << "\n������ 22.2.������� 2.\n������� �����: ";
	int x;
	cin >> x;
	cout << "\n������� �������, � ������� ������ �������� �����: ";
	int y;
	cin >> y;
	func2(&x, &y);
	cout << "��������� = " << x << "\n\n";


	return 0;
}