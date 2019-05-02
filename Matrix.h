# Biblioteka
#pragma once
//ОБЪЯВЛЕНИЕ И ОПИСАНИЕ КЛАССА MATRIX И ЕГО МЕТОДОВ
#include "pch.h"
#include <iostream>
#include <vector>		                         //библиотека для работы с векторами
#include <string>                               //библиотека для работы со строками
using namespace std;

class Matrix
{
public:
	Matrix(int n_rows, int n_columns);			//конструктор, создает матрицу, 
	                                            //входные данные: количество строк и столбцов

	double &operator()(int row, int column);	//возвращается не копия, а ссылка, чтобы была возможность изменить 

	int nRows() const;
	int nColumns() const;
	                                             //nRows() nColumns() - public функции, возвращающие значения
	                                             //защищенных private n_columns и n_rows
private:                                        //n_rows, n_columns - внутри private, только для методов класса
	vector<double> el;                          //создание вектора с элементами типа double 
	                                           //( по сути=массив элементов типа double )
	int n_rows;								   //количество строк
	int n_columns;							  //количество столбцов
};

Matrix operator+(Matrix m1, Matrix m2);					
Matrix operator-(Matrix m1, Matrix m2);						
Matrix operator*(Matrix m, double value);					
Matrix operator*(double value, Matrix m);						
Matrix operator*(Matrix m1, Matrix m2);							
ostream &operator<<(ostream &out, Matrix m);			
