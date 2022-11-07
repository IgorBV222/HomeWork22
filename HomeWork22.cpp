#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//Заполнение массива случайными числами
template <typename T>
void fill_arr(T arr[], const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (end - begin) + begin;
}
//Вывод массива в консоль
template <typename T>
void show_arr(T arr[], const int length) {
	cout << '[';
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}
//Меняем местами четные и нечетные элементы массива
template <typename T>
void arr_pswap(T *arr, const int length) {
	cout << "Итоговый массив:\n";
	cout << '[';
	for (int i = 0; i < length; i += 2) {
		int tmp = *(arr + i);
		*(arr + i) = *((arr + i) + 1);
		*((arr + i) + 1) = tmp;

		cout << *(arr + i) << ", " << *((arr + i) + 1) << ", ";
	}
	cout << "\b\b]\n";
}

//Возведение числа в степень 
void func(int* num1, int num2) {
	int res = 1;
	for (int i = 1; i <= num2; i++) {
		res *= *num1;		
	}
	*num1 = res;
}

//Возведение числа в степень v2
void func2(int* num1, int *num2) {
	int res = 1;
	for (int i = 1; i <= *num2; i++) {
		res *= *num1;		
	}
	*num1 = res;
}



int main() {
	setlocale(LC_ALL, "Russian");	

	// Задача 22.1.
	cout << "Задача 22.1. Вариант 1.\nИзначальный массив: \n";
	const int size = 10;
	int mass[size];
	
	fill_arr(mass, size, 1, 11);
	show_arr(mass, size);
	cout << "Итоговый массив:\n";
	cout << '[';
	for (int i = 0; i < size; i += 2) {
		int tmp = *(mass + i);
		*(mass + i) = *((mass + i) + 1);
		*((mass + i) + 1) = tmp;

		cout << *(mass + i) << ", " << *((mass + i) + 1) << ", ";
	}
	cout << "\b\b]\n";

	cout << "\nЗадача 22.1. Вариант 2.\nИзначальный массив: \n";
	const int size2 = 10;
	int mass2[size2] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	cout << '[';
	for (int i = 0; i < size2; i++)
		cout << mass2[i] << ", ";
	cout << "\b\b]\n";
	
	int* pmass = &mass2[0];
	cout << "Итоговый массив:\n";
	cout << '[';
	for (int i = 0; i < size2; i+=2) {
		int tmp = *(pmass + i);
		*(pmass + i) = *((pmass+i) + 1);
		*((pmass+i) + 1) = tmp;

		cout << *(pmass + i) << ", " << *((pmass + i) + 1) << ", ";
	}
	cout << "\b\b]\n";

	cout << "\nЗадача 22.1. Вариант 3.\nИзначальный массив: \n";
	const int size3 = 10;
	int mass3[size3];
	fill_arr(mass3, size3, 1, 11);
	show_arr(mass3, size3);
	arr_pswap(mass3, size3);
	
	// Задача 22.2.
	cout << "\nЗадача 22.2.Вариант 1.\n";
	int n = 10;	
	func(&n, 3);
	cout << "Результат = " << n << "\n\n";

	cout << "\nЗадача 22.2.Вариант 2.\nВведите число: ";
	int x;
	cin >> x;
	cout << "\nВведите степень, в которую хотите возвести число: ";
	int y;
	cin >> y;
	func2(&x, &y);
	cout << "Результат = " << x << "\n\n";


	return 0;
}