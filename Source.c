#define _USE_MATH_DEFINES 
#define M_PI 3.14159265358979323846
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>
#include <locale.h>

int Task1();
int Task2();
int Task3();

double Home(double x_, double y_, double z_);

int main()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");

	double x, y, z, a;
	x = 3.981e-2;
	y = -1.625e3;
	z = 0.5;
	a = Home(x, y, z);

	printf("  x = %.5f (%.3e)\n", x, x);
	printf("  y = %.1f (%.3e)\n", y, y);
	printf("  z = %.3f\n", z);

	printf("\nРезультат вычислений:\n");
	printf("  a = %.5f\n", a);
	printf("Ожидаемый ответ из таблицы:\n");
	printf("  a = 1.26185\n");


	return 0;
}


int Task1()
{
	double gra;
	printf("Введите значение угла в градусах: ");
	if (scanf("%lf", &gra) != 1) {
		printf("Ошибка\n");
		return 1;
	}
	double rad = gra * M_PI / 180;
	double result = sin(rad);
	printf("%.6f\n", result);
	return 0;
}

int Task2()
{
	double t = 0.3;
	double x;
	double a, b, y;

	printf("Введём x: ");
	if (scanf("%lf", &x) != 1) {
		printf("Ошибка ввода.\n");
		return 1;
	}

	b = x * pow(t, 2) + sqrt(x);
	a = log10(fabs(t * x + pow(t, 2)));
	y = log(pow(a, 2) / (a + b));

	printf("b = %lf\n", b);
	printf("a = %lf\n", a);
	printf("y = %lf\n", y);

	printf("\nКонстанта t = %.1f\n", t);
	printf("x = %.1f\n", x);
	printf("y = %.2f\n", y); 

	return 0;
}

int Task3()
{
	double a = 4.5;
	double b = 7.1;
	double y = 9.9;

	int A = (int)a;
	int B = (int)b;
	int C = (int)y;

	int ATest = (A % 2 == 0) != (B % 2 == 0);
	int BTest = (A % 3 == 0) && (B % 3 == 0) && (C % 3 == 0);

	printf("А истинно 1 - да, 0 - нет): %d\n", ATest);
	printf("Б истинно 1 - да, 0 - нет): %d\n", BTest);
	return 0;
}

double Home(double x_, double y_, double z_)
{
	double a;
	double part1, part2, part3;
	part1 = pow(2.0, -x_);
	part2 = sqrt(x_ + pow(fabs(y_), 0.25));
	part3 = cbrt(exp(x_ - 1.0 / sin(z_)));
	a = part1 * part2 * part3;

	return a;
}