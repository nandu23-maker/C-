#include <stdio.h>

class A
{
   int i;

   public:
   A(int i)
   {
      this->i=i;
   }
  friend void show(A obj);
};
void show(A obj)
{
   printf("%d",obj.i);
};

int main()
{
   A obj(20);
   show(obj);
              
    return 0;
}
