#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <math.h>
using namespace std;

bool work = 1, working = 1;
char change = ' ';
int code;
float step = 1;
double a, b, c, d, x, y, x1, x2;;
int otstup = 120;
int w;
int h;

void Oxy(HDC, int, int);
void control(char);
void menu();
bool debug_cin();

int main()
{
	setlocale(LC_ALL, "");
	HDC hdc = GetDC(GetConsoleWindow());
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hdc, Pen);
	int fun;
	int Ox, Oy;
	HWND hWnd = GetConsoleWindow();
	RECT rc;
	GetClientRect(hWnd, &rc);
	w = rc.right; // ширина рабочей области
	h = rc.bottom;// высота рабочей области
	h /= 20;
	h *= 20;
	w /= 20;
	w *= 20;
	
	while (working)
	{
		do
		{
			cout << "Виберiть який графiк ви хочете побачити:\n\
1) у = ах2 + bх + с\n\
2) у = a * sin(x) + cos(b)\n\
3) y = a + (b / c * x + d)\n\
4) y = ax3 + bx2 + cx + d\n\
5) y = (x^a + b) / (x^c - d)\n\
6) y = ax^b + cx^d\n\
7) y = a * b^x + c\n\
8) y = a * e^(b * x)\n\
9) Дельтоiд (Крива Штейнера)\n\
10) Астроiда\n>";
			cin >> fun;
			system("cls");

		} while (debug_cin());

		if (fun <= 10 && fun > 0)
		{
			do
			{
				do
				{
					cout << "Введiть розмiр поля по координатi Оx: ";
					cin >> Ox;
					cout << "Введiть розмiр поля по координатi Оy: ";
					cin >> Oy;
					system("cls");
				} while (Ox < 0 && Oy < 0);

				cout << "Введiть розмiр вiдрiзка\nвiд х1 - ";
				cin >> x1;
				cout << "до х2 - ";
				cin >> x2;
				system("cls");
				work = 1;
			} while (debug_cin());
		}

		switch (fun)
		{
		case 1:// у = ах2 + bх + с
		{
			do
			{
				cout << "Введiть значення а: ";
				cin >> a;
				cout << "Введiть значення b: ";
				cin >> b;
				cout << "Введiть значення c: ";
				cin >> c;

				system("cls");
			} while (debug_cin());

			while (work)
			{
				system("cls");
				menu();

				cout << "Графiк функцiї: y = " << a << "x^2 + " << b << "x + " << c << "  От х - " << x1 << " до х - " << x2;

				Oxy(hdc, Ox, Oy);

				for (double xi = x1; xi < x2; xi += 0.01f)
				{
					if ((-((h - otstup) / (Oy * 2)) * (a * pow(xi, 2) + b * xi + c) + (h - otstup) / 2) + otstup < h && -((h - otstup) / (Oy * 2)) * (a * pow(xi, 2) + b * xi + c) + (h - otstup) / 2 > 0)
					{
						MoveToEx(hdc, w / 2 + xi * (w / (Ox * 2)), (-((h - otstup) / (Oy * 2)) * (a * pow(xi, 2) + b * xi + c) + (h - otstup) / 2) + otstup, NULL);
						LineTo(hdc, w / 2 + xi * (w / (Ox * 2)), (-((h - otstup) / (Oy * 2)) * (a * pow(xi, 2) + b * xi + c) + (h - otstup) / 2) + otstup);
					}
				}
				control(_getch());
			}
			break;
		}
		case 2: // у = a * sin(x) + cos(b)
		{
			do
			{
				cout << "Введiть значення а: ";
				cin >> a;
				cout << "Введiть значення b: ";
				cin >> b;

				system("cls");
			} while (debug_cin());

			while (work)
			{
				system("cls");
				menu();

				cout << "Графiк функцiї: y = " << a << " * sin(x) + cos(" << b << "). Вiд х - " << x1 << " до х - " << x2;

				Oxy(hdc, Ox, Oy);

				for (double xi = x1; xi < x2; xi += 0.01f)
				{
					if ((-((h - otstup) / (Oy * 2)) * (a * sin(xi) + cos(b)) + (h - otstup) / 2) + otstup < h && (-((h - otstup) / (Oy * 2)) * (a * sin(xi) + cos(b)) + (h - otstup) / 2) > 0)
					{
						MoveToEx(hdc, w / 2 + xi * (w / (Ox * 2)), (-((h - otstup) / (Oy * 2)) * (a * sin(xi) + cos(b)) + (h - otstup) / 2) + otstup, NULL);
						LineTo(hdc, w / 2 + xi * (w / (Ox * 2)), (-((h - otstup) / (Oy * 2)) * (a * sin(xi) + cos(b)) + (h - otstup) / 2) + otstup);
					}
				}
				control(_getch());
			}
			break;
		}
		case 3: // a + (b / (c * x + d)); 
		{
			do
			{
				cout << "Введiть значення а: ";
				cin >> a;
				cout << "Введiть значення b: ";
				cin >> b;
				cout << "Введiть значення c: ";
				cin >> c;
				cout << "Введiть значення d: ";
				cin >> d;

				system("cls");
			} while (debug_cin());

			while (work)
			{
				system("cls");
				menu();

				cout << "Графiк функцiї: y = " << a << " + (" << b << " / " << c << "x + " << d << "). Вiд х - " << x1 << " до х - " << x2;

				Oxy(hdc, Ox, Oy);

				for (double xi = x1; xi < x2; xi += 0.01f)
				{
					if ((-((h - otstup) / (Oy * 2)) * (a + (b / (c * xi + d))) + (h - otstup) / 2) + otstup < h && (-((h - otstup) / (Oy * 2)) * (a + (b / (c * xi + d))) + (h - otstup) / 2) > 0 && c * xi + d != 0)
					{
						MoveToEx(hdc, w / 2 + xi * (w / (Ox * 2)), (-((h - otstup) / (Oy * 2)) * (a + (b / (c * xi + d))) + (h - otstup) / 2) + otstup, NULL);
						LineTo(hdc, w / 2 + xi * (w / (Ox * 2)), (-((h - otstup) / (Oy * 2)) * (a + (b / (c * xi + d))) + (h - otstup) / 2) + otstup);
					}
				}
				control(_getch());
			}
			break;
		}
		case 4: // ax3 + bx2 + cx + d; 
		{
			do
			{
				cout << "Введiть значення а: ";
				cin >> a;
				cout << "Введiть значення b: ";
				cin >> b;
				cout << "Введiть значення c: ";
				cin >> c;
				cout << "Введiть значення d: ";
				cin >> d;

				system("cls");
			} while (debug_cin());

			while (work)
			{
				system("cls");
				menu();

				cout << "Графiк функцiї: y = " << a << "x^3 + " << b << "x^2 + " << c << "x + " << d << ". Вiд х - " << x1 << " до х - " << x2;

				Oxy(hdc, Ox, Oy);

				for (double xi = x1; xi < x2; xi += 0.01f)
				{
					if ((-((h - otstup) / (Oy * 2)) * (a * pow(xi, 3) + b * pow(xi, 2) + c * xi + d) + (h - otstup) / 2) + otstup < h && -((h - otstup) / (Oy * 2)) * (a * pow(xi, 3) + b * pow(xi, 2) + c * xi + d) + (h - otstup) / 2 > 0)
					{
						MoveToEx(hdc, w / 2 + xi * (w / (Ox * 2)), (-((h - otstup) / (Oy * 2)) * (a * pow(xi, 3) + b * pow(xi, 2) + c * xi + d) + (h - otstup) / 2) + otstup, NULL);
						LineTo(hdc, w / 2 + xi * (w / (Ox * 2)), (-((h - otstup) / (Oy * 2)) * (a * pow(xi, 3) + b * pow(xi, 2) + c * xi + d) + (h - otstup) / 2) + otstup);
					}
				}
				control(_getch());
			}
			break;
		}
		case 5: // y = (x^a + b) / (x^c - d)
		{
			do
			{
				cout << "Введiть значення а: ";
				cin >> a;
				cout << "Введiть значення b: ";
				cin >> b;
				cout << "Введiть значення c: ";
				cin >> c;
				cout << "Введiть значення d: ";
				cin >> d;

				system("cls");
			} while (debug_cin());

			while (work)
			{
				system("cls");
				menu();

				cout << "Графiк функцiї: y = (x^" << a << " + " << b << ") / (x^" << c << " - " << d << "). Вiд х - " << x1 << " до х - " << x2;

				Oxy(hdc, Ox, Oy);

				for (double xi = x1; xi < x2; xi += 0.01f)
				{
					if ((-((h - otstup) / (Oy * 2)) * ((pow(xi, a) + b) / (pow(xi, c) - d)) + (h - otstup) / 2) + otstup < h && -((h - otstup) / (Oy * 2)) * ((pow(xi, a) + b) / (pow(xi, c) - d)) + (h - otstup) / 2 > 0 && (pow(xi, c) - d) != 0)
					{
						MoveToEx(hdc, w / 2 + xi * (w / (Ox * 2)), (-((h - otstup) / (Oy * 2)) * ((pow(xi, a) + b) / (pow(xi, c) - d)) + (h - otstup) / 2) + otstup, NULL);
						LineTo(hdc, w / 2 + xi * (w / (Ox * 2)), (-((h - otstup) / (Oy * 2)) * ((pow(xi, a) + b) / (pow(xi, c) - d)) + (h - otstup) / 2) + otstup);
					}
				}
				control(_getch());
			}
			break;
		}
		case 6: // y = ax^b + cx^d
		{
			do
			{
				cout << "Введiть значення а: ";
				cin >> a;
				cout << "Введiть значення b: ";
				cin >> b;
				cout << "Введiть значення c: ";
				cin >> c;
				cout << "Введiть значення d: ";
				cin >> d;

				system("cls");
			} while (debug_cin());

			while (work)
			{
				system("cls");
				menu();

				cout << "Графiк функцiї: y = " << a << "x^" << b << " + " << c << "x^" << d << ". Вiд х - " << x1 << " до х - " << x2;

				Oxy(hdc, Ox, Oy);

				for (double xi = x1; xi < x2; xi += 0.01f)
				{
					if ((-((h - otstup) / (Oy * 2)) * (a * pow(xi, b) + c * pow(xi, d)) + (h - otstup) / 2) + otstup < h && (-((h - otstup) / (Oy * 2)) * (a * pow(xi, b) + c * pow(xi, d)) + (h - otstup) / 2) > 0)
					{
						MoveToEx(hdc, w / 2 + xi * (w / (Ox * 2)), (-((h - otstup) / (Oy * 2)) * (a * pow(xi, b) + c * pow(xi, d)) + (h - otstup) / 2) + otstup, NULL);
						LineTo(hdc, w / 2 + xi * (w / (Ox * 2)), (-((h - otstup) / (Oy * 2)) * (a * pow(xi, b) + c * pow(xi, d)) + (h - otstup) / 2) + otstup);
					}
				}
				control(_getch());
			}
			break;
		}
		case 7: // y = a * b^x + c
		{
			do
			{
				cout << "Введiть значення а: ";
				cin >> a;
				cout << "Введiть значення b: ";
				cin >> b;
				cout << "Введiть значення c: ";
				cin >> c;

				system("cls");
			} while (debug_cin());

			while (work)
			{
				system("cls");
				menu();

				cout << "Графiк функцiї: y = " << a << " * " << b << "^x + " << c << ". Вiд х - " << x1 << " до х - " << x2;

				Oxy(hdc, Ox, Oy);

				for (double xi = x1; xi < x2; xi += 0.01f)
				{
					if ((-((h - otstup) / (Oy * 2)) * (a * pow(b, xi) + c) + (h - otstup) / 2) + otstup < h && (-((h - otstup) / (Oy * 2)) * (a * pow(b, xi) + c) + (h - otstup) / 2) > 0)
					{
						MoveToEx(hdc, w / 2 + xi * (w / (Ox * 2)), (-((h - otstup) / (Oy * 2)) * (a * pow(b, xi) + c) + (h - otstup) / 2) + otstup, NULL);
						LineTo(hdc, w / 2 + xi * (w / (Ox * 2)), (-((h - otstup) / (Oy * 2)) * (a * pow(b, xi) + c) + (h - otstup) / 2) + otstup);
					}
				}
				control(_getch());
			}
			break;
		}
		case 8: // y = a * e^(b * x)
		{
			do
			{
				cout << "Введiть значення а: ";
				cin >> a;
				cout << "Введiть значення b: ";
				cin >> b;

				system("cls");
			} while (debug_cin());

			while (work)
			{
				system("cls");
				menu();

				cout << "Графiк функцiї: y = " << a << " * e^(" << b << " * x). Вiд х - " << x1 << " до х - " << x2;

				Oxy(hdc, Ox, Oy);

				for (double xi = x1; xi < x2; xi += 0.01f)
				{
					if ((-((h - otstup) / (Oy * 2)) * (a * exp(b * xi)) + (h - otstup) / 2) + otstup < h && (-((h - otstup) / (Oy * 2)) * (a * exp(b * xi)) + (h - otstup) / 2) > 0)
					{
						MoveToEx(hdc, w / 2 + xi * (w / (Ox * 2)), (-((h - otstup) / (Oy * 2)) * (a * exp(b * xi)) + (h - otstup) / 2) + otstup, NULL);
						LineTo(hdc, w / 2 + xi * (w / (Ox * 2)), (-((h - otstup) / (Oy * 2)) * (a * exp(b * xi)) + (h - otstup) / 2) + otstup);
					}
				}
				control(_getch());
			}
			break;
		}
		case 9: // x = acos(t) + cos(bt), y = csin(t) − sin(dt)
		{
			do
			{
				cout << "Рекомендованно вводити одноковi значення для всiх параметрiв" << endl;
				cout << "Введiть значення а: ";
				cin >> a;
				cout << "Введiть значення b: ";
				cin >> b;
				cout << "Введiть значення c: ";
				cin >> c;
				cout << "Введiть значення d: ";
				cin >> d;

				system("cls");
			} while (debug_cin());

			x1 = -Ox;
			x2 = Ox;

			while (work)
			{
				system("cls");
				menu();

				cout << "Графiк функцiї: x = " << a << " cos(t) + cos(" << b <<"t) , y = "<< c <<" sin(t) - sin("<< d <<"t). Вiд t - " << x1 << " до t - " << x2;

				Oxy(hdc, Ox, Oy);

				for (double xi = x1; xi < x2; xi += 0.01f)
				{
					if ((-((h - otstup) / (Oy * 2)) * (c * sin(xi) - sin(d * xi)) + (h - otstup) / 2) + otstup < h && (-((h - otstup) / (Oy * 2)) * (c * sin(xi) - sin(d * xi)) + (h - otstup) / 2) > 0)
						if (w / 2 + (a * cos(xi) + cos(b * xi)) * (w / (Ox * 2)) < w && w / 2 + (a * cos(xi) + cos(b * xi)) * (w / (Ox * 2)) > 0)
						{
							MoveToEx(hdc, w / 2 + (a * cos(xi) + cos(b * xi)) * (w / (Ox * 2)), (-((h - otstup) / (Oy * 2)) * (c * sin(xi) - sin(d * xi)) + (h - otstup) / 2) + otstup, NULL);
							LineTo(hdc, w / 2 + (a * cos(xi) + cos(b * xi)) * (w / (Ox * 2)), (-((h - otstup) / (Oy * 2)) * (c * sin(xi) - sin(d * xi)) + (h - otstup) / 2) + otstup);
						}
				}
				control(_getch());
			}
			break;
		}
		case 10: // x = 2(sin(t))^3, y = 2(cos(t))^3
		{
			do
			{
				cout << "Рекомендованно значення а - 2, b - 3, c - 2, d - 3" << endl;
				cout << "Введiть значення а: ";
				cin >> a;
				cout << "Введiть значення b: ";
				cin >> b;
				cout << "Введiть значення c: ";
				cin >> c;
				cout << "Введiть значення d: ";
				cin >> d;

				system("cls");
			} while (debug_cin());

			x1 = -Ox;
			x2 = Ox;

			while (work)
			{
				system("cls");
				menu();

				cout << "Графiк функцiї: x = " << a << " (sin(t))^" << b << ", y = " << c << " (cos(t))^" << d << ". Вiд t - " << x1 << " до t - " << x2;

				Oxy(hdc, Ox, Oy);

				for (double xi = x1; xi < x2; xi += 0.01f)
				{
					if ((-((h - otstup) / (Oy * 2)) * (c * pow(cos(xi), d)) + (h - otstup) / 2) + otstup < h && (-((h - otstup) / (Oy * 2)) * (c * pow(cos(xi), d)) + (h - otstup) / 2) > 0)
						if (w / 2 + (a * pow(sin(xi), b)) * (w / (Ox * 2)) < w && w / 2 + (a * pow(sin(xi), b)) * (w / (Ox * 2)) > 0)
						{
							MoveToEx(hdc, w / 2 +	(a * pow(sin(xi), b)) * (w / (Ox * 2)),		(-((h - otstup) / (Oy * 2)) * (c * pow(cos(xi), d)) + (h - otstup) / 2) + otstup, NULL);
							LineTo(hdc, w / 2 +		(a * pow(sin(xi), b)) * (w / (Ox * 2)),		(-((h - otstup) / (Oy * 2)) * (c * pow(cos(xi), d)) + (h - otstup) / 2) + otstup);
						}
				}
				control(_getch());
			}
			break;
		}
		}
	}
	return 0;
}

void Oxy(HDC hdc, int Ox, int Oy)
{
	MoveToEx(hdc, 0, h / 2 + otstup / 2, NULL);//Ox
	LineTo(hdc, w, h / 2 + otstup / 2);

	MoveToEx(hdc, w / 2, otstup, NULL);//Oy
	LineTo(hdc, w / 2, h);

	for (int i = 0; i <= w; i += w / (Ox * 2))
	{
		MoveToEx(hdc, i, h / 2 + otstup / 2, NULL);
		LineTo(hdc, i, (h / 2 - 10) + otstup / 2);
	}

	for (float j = otstup; j <= h; j += (h - otstup) / (Oy * 2))
	{
		MoveToEx(hdc, w / 2, j, NULL);
		LineTo(hdc, (w / 2 + 10), j);
	}
}

void control(char ch)
{
	code = static_cast<int>(ch);

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
	case 100:
	case 68:
		change = 'd';
		break;
	case 46:
		change = '>';
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
	case 79:
		step = 10;
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
		case 'd':
			d += step;
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
		case 'd':
			d -= step;
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
	cout << "Щоб змiнити одну з констант виберiть її на клавiатурi." << endl;
	cout << "Для змiни початку вiдрiзка натиснiть \"<\" а для кiнця вiдрiзка \">\"" << endl;
	cout << "Зараз обрана \"" << change << "\". Крок - " << step << " (стрiлками вправо +1, влiво - 1, N - крок 0.1, M - крок 1)" << endl;
	cout << "Що-б повернутися в меню натиснiть стрiлку вгору, щоб закрити програму стрiлку вниз." << endl;
	cout << "Для того щоб обновити графiк натисніт пробiл" << endl;
}

bool debug_cin()
{
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(200000, '\n');
		cout << "Не коректне введення! Спробуйте ще раз.\n\n";
		return true;
	}
	else
	{
		return false;
	}
}
