#include <stdio.h>

class B;
class A
{
  int x;
  
  public:
  A(int x)
  {
    this->x=x;
  }
friend void add(A a,B b);
};

class B
{
  int y;

  public:
  B(int y)
  {
    this->y=y;
  }
friend void add(A a,B b);
};

void add(A a,B b)
{
   printf("%d",a.x + b.y);
};

int main()
{
   A a(20);
   B b(60);
  
   add(a,b);

      return 0;
}
