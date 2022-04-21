#include <iostream>
using namespace std;

double f(double x)
{
	return x * x + 6 * x + 13;
}
int main()
{
	double a_start = -6, b_end = 4; // Интервал неопределенности
	double eps = 0.5; // Эпсилон
	double sigm = 0.2; // Сигма
	double l = 2 * eps; // Точность l
	double k = 0; // Предположение
	double y, z;
	int fn, N, t, u;
	double f0, f1;
	double fy;
	double fz;

	setlocale(LC_ALL, "Russian");
	cout << "Шаг 1. Зададим начальный интервал неопределенности L0=[a0,b0]" << endl;
	cout << "L0 = ["<<a_start<<", "<<b_end<<"]"<< endl;
	cout << "Зададим допустимую и предельную погрешность." << endl;
	cout << "Eps = " << eps << endl;
	cout << "Sigma = " << sigm << endl;
	cout << "Точность l = " << l << endl;
	cout << endl;

	cout << "Шаг 2. Найдем количество N вычислений функции как наименьшее целое число" << endl;
	fn = (b_end - a_start) / l;
	f0 = f1 = 1;
	N = 1;

	while (f1 < fn)
	{
		N++;
		t = f0;
		f0 = f1;
		f1 += t;
	}

	cout << "N = " << N << endl;
	cout << "f0 = " << f0 << endl;
	cout << "f1 = " << f1 << endl;
	cout << endl;

	cout << "Шаг 3. Положим k = " << k << endl;
	cout << endl;

	cout << "Шаг 4. Вычислм У0, Z0: " << endl;
	y = a_start + ((f1 - f0) / f1) * (b_end - a_start);
	z = a_start + f0 / f1 * (b_end - a_start);
	u = f1 - f0;
	f1 = f0;
	f0 = u;
	cout << "y0 = " << y << "; z0 = " << z << endl;
	cout << endl;
	while ((b_end - a_start) > l)
	{

		fy = f(y);
		fz = f(z);
		cout << "Шаг 5. Вычислм Уk, Zk: " << endl;
		cout << "f(y) = " << fy << " " << "f(z) =  " << fz << endl;
		cout << endl;

		cout << "Шаг 6. Сравним f(Ук) с f(Zк):" << endl;
		if (fy <= fz)
		{
			cout << "Условие а) выполняется! f(y) <= f(z)" << endl;
			a_start = a_start;
			b_end = z;
			cout << "a = " << a_start << endl;
			cout << "b = " << b_end << endl;
			z = y;
			y = a_start + (f1 - f0) / f1 * (b_end - a_start);
			cout << "y = " << y << endl;
			cout << "z = " << z << endl;
			u = f1 - f0;
			f1 = f0;
			f0 = u;
			cout << endl;
		}
		else
		{
			cout << "Условие б) выполняется! f(y) > f(z)" << endl;
			a_start = y;
			b_end = b_end;
			cout << "a = " << a_start << endl;
			cout << "b = " << b_end << endl;
			y = z;
			z = a_start + f0 / f1 * (b_end - a_start);
			cout << "y = " << y << endl;
			cout << "z = " << z << endl;
			u = f1 - f0;
			f1 = f0;
			f0 = u;
			cout << endl;
		}

		cout << "Шаг 7. Проверим условия окончания и в случае необходимости сделаем заключительно N-е вычисление функции для получения решения:" << endl;
		if (k != N - 3)
		{
			cout << "Условие а) выполняется! k != N - 3" << endl;
			k++;
			cout << "k = " << k << endl;
			cout << endl;
		}
		else
		{
			cout << "Условие б) выполняется! k = N - 3" << endl;
			y = z;
			z = y + sigm;
			cout << "y = " << y << endl;
			cout << "z = " << z << endl;
			cout << "В точках у и z вычислим значения функции и найдем границы конечного интервала неопределенности:" << endl;
			if (f(y) <= f(z))
			{
				cout << "a = " << a_start << ", b = " << z << endl;
			}
			else
			{
				cout << "a = " << y << ", b = " << b_end << endl;
			}
			break;
		}
	}
	cout << endl;
	cout << "Процесс поиска завершен." << endl;
	cout << "Точка минимума принадлежит интервалу: [" << a_start << " ; " << b_end << "] " << endl;
	cout << "Точка минимума функции равна : " << (a_start + b_end) / 2 << " +- " << (b_end - a_start) / 2 << endl;
	cout << "Локальный минимум =" << f((a_start + b_end) / 2) << endl;
	system("pause");
	return 0;
}