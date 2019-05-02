// BMBO-01-17Kovalieva program c++.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//РЕАЛИЗАЦИЯ
#include "pch.h"
#include "Matrix.h"
#include "funcs.h";
#include <iostream>
#include <vector>		
using namespace std; 




int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Проверка работы класса и его методов" << endl;
	Matrix A(2, 2);
		A(0, 0) = 1;
		A(0, 1) = 2;
		A(1, 0) = 3;
		A(1, 1) = 4;
	Matrix B(2, 2);
		B(0, 0) = 6;
		B(0, 1) = 7;
		B(1, 0) = 8;
		B(1, 1) = 5;
	Matrix SUM = A + B;
		cout<<"сумма А + В = "<< SUM(1, 0)<< endl;
	Matrix RAZ = A - B;
	    cout<<"разность А - В = "<< RAZ(0, 0) << endl;
	Matrix PROIZVED = A*6;
		cout<<"А*6 = "<<PROIZVED<< endl;
	Matrix MNOJ = A*B;
	    cout<< "произведение матриц А*В = "<<MNOJ<<endl;
		cout << endl;
    cout <<"Проверка работы вспомогательных функций" << endl;
		cout<<"определитель матрицы А = "<<det(A)<<endl;
		cout<<"норма вектора 1 матрицы А = "<<vect_norm1(A)<<endl;  
		cout<<"норма вектора 2 матрицы А = "<<vect_norm2(A)<<endl;
		cout<<"норма вектора 3 матрицы А = "<<vect_norm3(A)<<endl;
		cout<<"норма матрицы 1 матрицы А = "<<matr_norm1(A)<<endl;
		cout<<"норма матрицы 2 матрицы А = "<<matr_norm2(A)<<endl;
		cout << endl;
	cout << "Проверка работы методов" << endl;
	   cout<<"приминение метода Жордана-Гаусса к матрице А и В "<<jordan_gauss(A,B)<<endl;
	   cout<<"применение метода inv_jg к матрице А " << inv_jg(A) << endl;
	   cout << endl;
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.