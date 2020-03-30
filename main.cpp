#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <math.h>
using namespace std;

bool work = 1, working = 1;
char change = ' ';
int code;
double a, b, c, x, y, x1, x2;;
int k; 
float scale = 1, step = 1;
int otstup = 12;

void Oxy(HDC, int, int);
void control(char);
void menu();

int main()
{
	setlocale(LC_ALL, "Russian");
	HDC hdc = GetDC(GetConsoleWindow());
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hdc, Pen);
	int fun;
	int Ox, Oy;
	
	while (working)
	{
		cout << "Выберите какой график вы хотите увидеть:\n1) у = ах2 + bх + с\n2) у = a * sin(x) + cos(b)\n>";
		cin >> fun;
		system("cls");
		cout << "Введите размер поля по координате Оx: ";
		cin >> Ox;
		cout << "Введите размер поля по координате Оy: ";
		cin >> Oy;
		system("cls");

		cout << "Введите размер отрезка\nот х - ";
		cin >> x1;
		cout << "до х - ";
		cin >> x2;
		system("cls");
		work = 1;

		switch (fun)
		{
		case 1:// у = ах2 + bх + с
		{
			cout << "Введите значения а: ";
			cin >> a;
			cout << "Введите значения b: ";
			cin >> b;
			cout << "Введите значения c: ";
			cin >> c;

			while (work)
			{
				system("cls");

				menu();

				cout << "График функции: y = " << a << "x^2 + " << b << "x + " << c << "  От х - " << x1 << " до х - " << x2;

				Oxy(hdc, Ox, Oy);

				for (double xi = x1; xi < x2; xi += 0.01f)
				{
					if ((a * pow(xi, 2) + b * xi + c) < Oy && (a * pow(xi, 2) + b * xi + c)  > -Oy)
					{
						MoveToEx(hdc, (10 * xi + Ox * 10) * scale,		(-10 * (a * pow(xi, 2) + b * xi + c) + Oy * 10  + otstup * 10) * scale, NULL);
						LineTo(hdc,   (10 * xi + Ox * 10) * scale,		(-10 * (a * pow(xi, 2) + b * xi + c) + Oy * 10  + otstup * 10) * scale);
					}
				}
				control(_getch());
			}
			break;
		}
		case 2: // у = a * sin(x) + cos(b)
		{
			cout << "Введите значения а: ";
			cin >> a;
			cout << "Введите значения b: ";
			cin >> b;

			while (work)
			{
				system("cls");

				menu();

				cout << "График функции: y = " << a << " * sin(x) + cos(" << b << "). От х - " << x1 << " до х - " << x2;

				Oxy(hdc, Ox, Oy);

				for (double xi = x1; xi < x2; xi += 0.01f)
				{
					if ((a * sin(xi) + cos(b)) < Oy && (a * sin(xi) + cos(b)) > -Oy)
					{
						MoveToEx(hdc,	(10 * xi + Ox * 10) * scale,	(-10 * (a * sin(xi) + cos(b)) + Oy * 10 + otstup * 10) * scale, NULL);
						LineTo(hdc,		(10 * xi + Ox * 10) * scale,	(-10 * (a * sin(xi) + cos(b)) + Oy * 10 + otstup * 10) * scale);
					}
				}
				control(_getch());
			}
			break;
		}
		default:
			cout << "Ошибочный ввод" << endl;
		}
	}
	return 0;
}

void Oxy(HDC hdc, int Ox, int Oy)
{
	MoveToEx(hdc,	0,						(Oy * 10 + otstup * 10) * scale, NULL);//Ox
	LineTo(hdc,		(Ox * 20) * scale,		(Oy * 10 + otstup * 10) * scale);

	MoveToEx(hdc,	(Ox * 10) * scale,		(otstup * 10) * scale, NULL);//Oy
	LineTo(hdc,		(Ox * 10) * scale,		(Oy * 20 + otstup * 10) * scale);

	for (int i = 0; i <= Ox * 2; i += 1)
	{
		MoveToEx(hdc,	(i * 10) * scale,	(Oy * 10 + otstup * 10) * scale, NULL);
		LineTo(hdc,		(i * 10) * scale,	(Oy * 10 - 5 + otstup * 10) * scale);
	}

	for (float j = otstup * scale; j <= (Oy * 2 + otstup) * scale; j += scale)
	{
		MoveToEx(hdc,	(Ox * 10) * scale,		j * 10, NULL);
		LineTo(hdc,		(Ox * 10 + 5) * scale,  j * 10);
	} 
}

void control(char ch)
{
	code = static_cast<int>(ch);
	cout << code;

	switch (code)
	{
	case 80:
		working = 0;
		work = 0;
		system("cls");
		break;
	case 72:
		work = 0;
		system("cls");
		break;
	case 97:
	case 65:
		change = 'a';
		break;
	case 98:
	case 66:
		change = 'b';
		break;
	case 99:
	case 67:
		change = 'c';
		break;
	case 120:
	case 88:
		change = 'x';
		break;
	case 46:
		change = '> b';
		break;
	case 44:
		change = '<';
		break;
	case 110:
		step = 0.1;
		break;
	case 109:
		step = 1;
		break;

	case 77:
		switch (change)
		{
		case 'a':
			a += step;
			break;
		case 'b':
			b += step;
			break;
		case 'c':
			c += step;
			break;
		case 'x':
			scale += step;
			break;
		case '>':
			x2 += step;
			break;
		case '<':
			x1 += step;
			break;
		}
		break;

	case 75:
		switch (change)
		{
		case 'a':
			a -= step;
			break;
		case 'b':
			b -= step;
			break;
		case 'c':
			c -= step;
			break;
		case 'x':
			scale -= step;
			break;
		case '>':
			x2 -= step;
			break;
		case '<':
			x1 -= step;
			break;
		}
		break;
	}
}

void menu()
{
	cout << "Что-бы изенить одну из констант выберите её на клавиатуре." << endl;
	cout << "Для увеличения/уменимьшения маштаба нажмите \"х\". Маштаб - x" << scale << endl;
	cout << "Для изменения начала отрезка нажмите \"<\" а для конца отрезка \">\"" << endl;
	cout << "Сейчас выбрана \"" << change << "\". Шаг - " << step << " ( стрелками в право +1, в лево - 1, N - шаг 0.1, M - шаг 1)" << endl;
	cout << "Что-бы вернуться в меню нажмине стрелку вверх, что-бы закрыть приложение стрелку вниз." << endl;
}
