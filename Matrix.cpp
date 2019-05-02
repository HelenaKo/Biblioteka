# Biblioteka
#include "pch.h"
//ОПИСАНИЕ МЕДОДОВ КЛАССА  MATRIX:
//1)...|
#include "Matrix.h"
#include <iostream>
#include <vector>		                         //библиотека для работы с векторами
#include <string>                               //библиотека для работы со строкамиusing namespace std;


Matrix::Matrix(int n_rows, int n_columns)
{
	if (n_rows < 1 || n_columns < 1)
		throw string("Wrong number of rows and columns");	//проверка на дурака 
															//this-> указатель на объект класса
	this->n_rows = n_rows;
	this->n_columns = n_columns;
	el.resize(n_rows * n_columns);                         //размер вектора колво строк*колво столбцов
};
/* n_rows(n_rows), n_columns(n_columns),
   el(n_rows * n_columns)*/

int Matrix::nRows() const
{
	return n_rows;
};

int Matrix::nColumns() const
{
	return n_columns;
};

double &Matrix::operator()(int row, int column)				//выражаем матрицу в виде вектора
{
	/*
	234
	567
	108
	(2,3,4,5,6,7,1,0,8)
	*/

	if (row < 0 || row >= n_rows)
		throw string("Wrong row index");
	if (column < 0 || column >= n_columns)
		throw string("Wrong column index");
	return el[n_columns * row + column];
};

Matrix add(Matrix m1, Matrix m2, int sign)				//сложение-вычитание матриц, при sight=-1 -вычитание
                                                       //будет использоваться долее для переопределения операторов + и -
{
	Matrix result(m1.nRows(), m1.nColumns());
	for (int i = 0; i < m1.nRows(); i++)
	{
		for (int j = 0; j < m1.nColumns(); j++)
		{
			result(i, j) = m1(i, j) + sign * m2(i, j);
		}
	}
	return result;
};

Matrix operator+(Matrix m1, Matrix m2)					//сложение матриц
{
	return add(m1, m2, +1);
};

Matrix operator-(Matrix m1, Matrix m2)					//вычитание матриц
{
	return add(m1, m2, -1);
};

Matrix operator*(Matrix m, double value)				//умножение матрицы на константу
{
	Matrix result(m.nRows(), m.nColumns());
	for (int i = 0; i < m.nRows(); i++)
	{
		for (int j = 0; j < m.nColumns(); j++)
		{
			result(i, j) = value * m(i, j);
		}
	}
	return result;
};

Matrix operator*(double value, Matrix m)				//умножение константы на матрицу
{
	return m * value;
};

Matrix operator*(Matrix m1, Matrix m2)					//умножение матрицы на матрицу
{
	Matrix result(m1.nRows(), m2.nColumns());
	for (int i = 0; i < m1.nRows(); i++)
	{

		for (int j = 0; j < m2.nColumns(); j++)
		{
			double tmp = 0;
			for (int k = 0; k < m2.nRows(); k++)
			{
				tmp += m1(i, k) * m2(k, j);
			}
			result(i, j) = tmp;
		}
	}
	return result;
};
ostream &operator<<(ostream &out, Matrix m)				//вывод матрицы
{
	for (int i = 0; i < m.nRows(); i++)
	{
		for (int j = 0; j < m.nColumns(); j++)
		{
			out << m(i, j) << "";
		}
		out << endl;
	}
	return out;
};
