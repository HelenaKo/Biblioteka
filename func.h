# Biblioteka
#pragma once
//ОБЪЯВЛЕНИЕ ФУНКЦИЙ
#include "pch.h"
#include "Matrix.h"
#include <iostream>
#include <vector>																
#include <string>
using namespace std;

//передаем функцию
using Func = double(double);


//Вспомогательные функции
double det(Matrix m);       //определитель матрицы
double vect_norm1(Matrix v);  // 3 нормы вектора
double vect_norm2(Matrix v);
double vect_norm3(Matrix v);
double matr_norm1(Matrix m);  //2 нормы матрицы
double matr_norm2(Matrix m);

// Методы СЛАУ
Matrix jordan_gauss(Matrix a, Matrix b);                        //метод Жордана-Гаусса
Matrix inv_jg(Matrix a);  //метод Жордана-Гаусса обратный           
Matrix jacobi_iter(Matrix m, Matrix b, double eps = 0.0001);	//метод Якоби
double m_iter(Func f, double x, double eps);                    // Методы просты итераций
//Остальное
double newton(Func f, double x, double eps = 0.0001);           //метод Ньютона
double m_hord(Func f, double x, double eps = 0.0000001);        //метод Хорд
double m_iter(Func f, double x, double eps = 0.0001);           //метод простых итераций
