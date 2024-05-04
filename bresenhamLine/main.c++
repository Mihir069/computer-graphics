#include <iostream>
#include <iomanip>
#include <math.h>
#include <graphics.h>

using namespace std;

void BresenhamLine(int x1, int y1, int x2, int y2)
{
  int win = initwindow(700, 500, "Bresenham Line Drawing Algorithm Example");
  setcurrentwindow(win);

  int x_origin = getwindowwidth() / 2;
  int y_origin = getwindowheight() / 2;

  double dx = x2 - x1;
  double dy = y2 - y1;
  double a = 2*dy;
  double b = -2*dx;

  double d = 2*dy - dx;

  putpixel(x1 + x_origin, -y1 + y_origin, 15);

  cout << "\ni\tPixel\td\tPlotted Values" << endl;
  cout << "-------------------------------------" << endl;
  cout << "0\t  \t  \t" << "(" << round(x1) << "," << round(y1) << ")" << endl;

  double x = x1;
  double y = y1;

  string pixel = "";

  for(int i = 1; ; i++) {
    double d_temp = d;

    if (d>0){
      d = d + a + b;
      x = x + 1;
      y = y + 1;
      pixel = "NE";
    } 
    else {
      d = d + a;
      x = x + 1;
      pixel = "E";
    }
    if (x > x2 || y > y2) break;

    putpixel(x + x_origin, -y + y_origin, 15);

    cout << i << "\t" << pixel << "\t" <<  d_temp << "\t" << "(" << round(x) << "," << round(y) << ")" << endl;
  }

  getch();
  closegraph();

  cout << endl;
}

int main()
{
  int x1 = -200;
  int y1 = -100;
  int x2 = 200;
  int y2 = 180;
  BresenhamLine(x1, y1, x2, y2);

  return 0;
}

