# Biblioteka
#include "funcs.h";
#include "pch.h"
#include "Matrix.h"
#include <iostream>
#include <vector>															
#include <string>
using namespace std;

using Func = double(double);
using Func2 = double(double, double);
using my_int = int;
using dvect = vector<double>;

//Определение вспомогательных функций
double det(Matrix m)
{
	for (int i = 0; i < m.nRows() - 1; i++)
	{
		for (int j = i + 1; j < m.nRows(); j++)
		{
			double coeff = m(j, i) / m(i, i);
			for (int k = i; k < m.nColumns(); k++)
			{
				m(j, k) = m(j, k) - coeff * m(i, k);
			}

		}


	}

	double result = 1;
	for (int i = 0; i < m.nRows(); i++)
	{
		result *= m(i, i);
	}
	return result;

}
double vect_norm1(Matrix v)
{
	double result = 0;
	for (int i = 0; i < v.nRows(); i++)
	{ 
		for (int j = 0; j < v.nColumns(); j++)
		{
			if (abs(v(i,j)) > result)
			{
				result = abs(v(i,j));
			}
		}
	}
	return result;
};
double vect_norm2(Matrix v)
{
	double result = 0;
	for (int i = 0; i < v.nRows(); i++)
		for (int j = 0; j < v.nColumns(); j++)
		{ 
			{
				result += abs(v(i,j));
			}
		}
	return result;
};
double vect_norm3(Matrix v)
{
	double result = 0;
	for (int i = 0; i < v.nRows(); i++)
		for (int j = 0; j < v.nColumns(); j++)
		{ 
			{
				result += pow(v(i,j), 2);
			}
		}
	return sqrt(result);
};
double matr_norm1(Matrix m)
{
	double result = 0;
	for (int i = 0; i < m.nRows(); i++)
	{
		double sum = 0;
		for (int j = 0; j < m.nColumns(); j++)
		{
			sum += abs(m(i, j));
		}
		if (result < sum)
		{
			result = sum;
		}
	}
	return result;
};
double matr_norm2(Matrix m)
{
	double result = 0;
	for (int j = 0; j < m.nColumns(); j++)
	{
		double sum = 0;
		for (int i = 0; i < m.nRows(); i++)
		{
			sum += abs(m(i, j));
		}
		if (result < sum)
		{
			result = sum;
		}
	}
	return result;
};

//МЕТОДЫ
//Методы СЛАУ
Matrix jordan_gauss(Matrix a, Matrix b)
{
	int n = a.nRows();
	for (int i = 0; i < n - 1; i++)						//ведущая строка
	{
		for (int j = i + 1; j < n; j++)					//текущая строка
		{
			double coeff = a(j, i) / a(i, i);				    //коэффициент
			for (int k = i; k < a.nColumns(); k++)
			{
				a(j, k) = a(j, k) - coeff * a(i, k);
			}

		}


	}

	for (int i = n - 1; i >= 1; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			double coeff = a(j, i) / a(i, i);
			a(j, i) = a(j, i) - coeff * a(i, i);
			b(j, 0) = b(j, 0) - coeff * b(i, i);
		}
	}

	for (int i = 0; i < a.nRows(); i++)
	{
		b(i, 0) = b(i, 0) / a(i, i);
		a(i, i) = 1;
	}

	return b;

	//X = jordan_gauss(a, b)
	//для проверки считаем A*X, должно получиться B
};
Matrix inv_jg(Matrix a)
{

	if (a.nRows() != a.nColumns())
		throw string("Matrix is not square");

	if (abs(det(a)) < 0.00000000000001)										//вещественное число
		throw string(" Det cannot be equal to 0");

	Matrix result(a.nRows(), a.nColumns());
	for (int i = 0; i < a.nRows(); i++)
	{
		result(i, i) = 1;													//единичная матрица
	}






	for (int i = 0; i < a.nRows() - 1; i++)					//ведущая строка
	{
		for (int j = i + 1; j < a.nRows(); j++)				//текущая строка
		{
			double coeff = a(j, i) / a(i, i);				//коэффициент
			for (int k = i; k < a.nColumns(); k++)
			{
				a(j, k) = a(j, k) - coeff * a(i, k);
			}
			for (int k = 0; k < a.nColumns(); k++)
			{
				result(j, k) = result(j, k) - coeff * result(i, k);
			}


		}


	}

	for (int i = a.nRows() - 1; i >= 1; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			double coeff = a(j, i) / a(i, i);
			a(j, i) = a(j, i) - coeff * a(i, i);
			for (int k = 0; k < a.nColumns(); k++)
			{
				result(j, k) = result(j, k) - coeff * result(i, k);
			}

		}
	}

	for (int i = 0; i < a.nRows(); i++)
	{
		for (int k = 0; k < a.nColumns(); k++)
		{
			result(i, k) /= a(i, i);
		}
		a(i, i) = 1;
	}

	return result;

};
Matrix jacobi_iter(Matrix m, Matrix b, double eps = 0.0001)
{
	Matrix result = b;
	for (int k = 0; k < m.nColumns(); k++)
		{ for (int j = 0; k < m.nRows(); j++)
		
			{
				b(k,j) /= m(k, k);
			}
		}

	for (int i = 0; i < m.nRows(); i++)
	{
		for (int k = 0; k < m.nColumns(); k++)
		{
			if (k == i)
			{
				continue;
			}

			m(i, k) /= -m(i, i);
		}

		m(i, i) = 0;

	}


	while (42)
	{
		Matrix last = result;
		result = m * last + b;							//метод простых итерация
		if (vect_norm1(result - last) < eps)
		{
			break;
		}
	}


	return result;
};
//Методы
double m_iter(Func f, double x, double eps)
{

	//f(x) = 0; -> x = g(x);
	double a = x - eps;
	while (42)
	{

		double last = x;

		x = last + f(x);

		if (abs(x - last) < eps)
		{
			break;
		}
	}
	//cout << n << endl;
	return x;
};
double newton(Func f, double x, double eps)
{
	//x = x - df(x) / f;


	while (42)
	{
		//int n = 0;
		double last = x;
		double df = (f(x + eps) - f(x)) / eps;
		x = last - f(x) / df;
		//n++;
		if (abs(x - last) < eps)
		{
			break;
		}
	}
	//cout << n << endl;
	return x;
};
double m_hord(Func f, double x, double eps)
{
	//x_k+1 x_k-f(x_k) / ( f(a) - (f(x_k)*(a-x_k));

	double a = x - eps;
	while (42)
	{
		//int n = 0;
		double last = x;
		//double df = (f(x + eps) - f(x)) / eps;
		x = last - f(last) * (a - last) / (f(a) - f(last));
		//n++;
		if (abs(x - last) < eps)
		{
			break;
		}
	}
	//cout << n << endl;
	return x;
};

