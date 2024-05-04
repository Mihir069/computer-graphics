#include <iostream>
#include <iomanip>
#include <math.h>
#include <graphics.h>

using namespace std;

void DDALine(double x1, double y1, double x2, double y2)
{
  int win = initwindow(400, 250, "DDA Line");
  setcurrentwindow(win);

  int x_origin = getwindowwidth() / 2;
  int y_origin = getwindowheight() / 2;

  putpixel(x1 + x_origin, -y1 + y_origin, 15);

  cout << "\nCalculated Values\tPrinted Values" << endl;
  cout << "-------------------------------------" << endl;
  cout << "(" << x1 << "," << y1 << ")" << setw(15) << setfill(' ') << "(" << round(x1) << "," << round(y1) << ")" << endl;

  double m = (y2 - y1) / (x2 - x1);

  double x_i = x1;
  double y_i = y1;

	while (true)
  {
    if (m <= 1)
    {
      if (x1 < x2)
      {
        x_i = x_i + 1;
        y_i = y_i + m;
      }
      if (x1 > x2)
      {
        x_i = x_i - 1;
        y_i = y_i - m;
      }
    }

    else
    {
      if (x1 < x2)
      {
        x_i = x_i + 1 / m;
        y_i = y_i + 1;
      }
      if (x1 > x2)
      {
        x_i = x_i - 1 / m;
        y_i = y_i - 1;
      }
    }

    if (x_i > x2 || y_i > y2) break;

    putpixel(x_i + x_origin, -y_i + y_origin, 15);

    cout << "(" << x_i << "," << y_i << ")" << setw(15) << setfill(' ') << "(" << round(x_i) << "," << round(y_i) << ")" << endl;
	}

  getch();
  closegraph();

  cout << endl;
}

int main()
{
  int x1 = 2;
  int y1 = 20;
  int x2 = 100;
  int y2 = 80;
  DDALine(x1, y1, x2, y2);

  return 0;
}