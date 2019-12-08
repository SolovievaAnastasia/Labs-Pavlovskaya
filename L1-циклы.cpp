#include <iostream>
#include <math.h>
using namespace std;

double f( double a, double b, double c, double x ) 
{
	double f;
	if (x + c < 0 && a != 0 ) 
		f = -a * pow( x, 3 ) - b;
	else 
	{
		if (x + c > 0 && a == 0) 
			f = (x - a) / (x - c);
		else 
			f = x / c + c / x;
	}
	return f;
}

int main()
{
	setlocale( 0, "");
	double a, b, c, x1, xk, dx;
	cout << "Введите Xнач." << endl;
	cin >> x1;
	cout << "Введите Xk." << endl;
	cin >> xk;
	cout << "Введите dX" << endl;
	cin >> dx;
	cout << "Введите a,b,c" << endl;
	cin >> a >> b >> c;
	cout << "\n";
	cout << "x" << "\t\t" << "F" << endl;
	for (x1; x1 <= xk; x1 = x1 + dx)
		cout << x1 << "\t\t" << f(a, b, c, x1) << endl;
	return 0;
}
