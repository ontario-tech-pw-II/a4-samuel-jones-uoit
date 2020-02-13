#include <iostream>
using namespace std;
const double PI = 3.14159;
class Circle {
  private:  
    int x,y;      // center of circle
    double r;    // radius of circle

  public:
   
    Circle(int =0,int=0, double =1.0);
    void print() const;
    double area() const;

    double operator+(const Circle &) const;

    Circle & operator++(); // prefix
    Circle operator++(int); // postfix

  friend ostream & operator<<(ostream &out, const Circle &);
  friend istream & operator>>(istream &in, Circle &);
};

Circle::Circle(int x,int y, double r)
{
  this->x = x;
  this->y = y;
  this->r = r;
}

double Circle::area() const {
  return PI * r * r;
}

double Circle::operator+(const Circle & c) const
{
   // + Return the area of two circles  
  return PI * (r * r + c.r * c.r);
}

Circle & Circle::operator++()
{
  // Increment the radius by 1
  r++;

  return *this;
}

Circle Circle::operator++(int)
{
  Circle temp = *this;
  
  //increment the radius by 1
  r++;

  return temp;
}

ostream & operator<<(ostream &out, const Circle &c)
{

  // print a circle in the out stream (the format is the same as print())
  out << "Circle = (" << c.x << "," << c.y << "," << c.r << ")" << "\n";
  return out;
}

istream & operator>>(istream &in, Circle &c)
{
 
 // Read a circle information from the in stream
  int tmp_x;
  int tmp_y;
  double tmp_r;
  cout << "x:";
  in >> tmp_x;
  cout << "y:";
  in >> tmp_y;
  cout << "r:";
  in >> tmp_r;
  c = Circle(tmp_x, tmp_y, tmp_r);
  return in;
}


void Circle::print() const
{
  cout << "Circle =(" << x << "," << y << "," << r << ")" << endl;
}



int main()
{
  Circle a;
  Circle b(2,3,3.0);

  a.print();
  b.print();
  
  cout << "The area a + b is: " << a+b << endl;
  ++a;
  a.print();

  a++;
  a.print();

  cout << a;

  cin >> a;
  cout <<a;

  return 0;

}
