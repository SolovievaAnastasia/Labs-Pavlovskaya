#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
	setlocale(0, "");
	size_t size;
	cout << "Введите размерность массива: ";
	cin>> size;
	vector<int> array(size);
	//Ввод массива
	for (size_t i = 0; i<size; i++)
	{
		cout << "a[" << i << "]=";
		cin >> array[i];
	}
	//Вывод исходного массива
	cout << "Массив" << endl;
	for (size_t i = 0; i<size; i++)
		cout << i << '\t' << array[i] << endl;
	//Поиск кол-во эл-ов =0
	int kol = 0;
	for (size_t i = 0; i < size; i++)
		if (array[i] == 0) kol++;
	cout << "Кол-во эл-ов равных 0 = " << kol << endl;
	//Поиск мин эл-та
	int min, pr;
	int nmin = 0;
	for (int i = 0, min = array[0]; i<size; i++)
		if (min>array[i]) {
			min = array[i];
			nmin = i;
		}
	//Поиск суммы эл-ов после мин эл-та ="
    	if (nmin+1 == size) pr=0; 
		else{
			pr = array[nmin + 1];
			for (size_t i = nmin + 2; i < size; i++)
				pr = pr + array[i];
		}
	cout << "Сумма эл-ов после мин эл-та =" << pr << endl;
	// Вывод массива по возрастанию модулей
	for (size_t j = 0; j<size; j++)
		for (size_t i = 0; i<size - 1; i++)
			if (abs(array[i])<abs(array[i + 1]))
				swap(array[i+1], array[i]);
	for (size_t i = 0; i<size; i++)
		cout << i << '\t' << array[i] << endl;
	return 0;
}
