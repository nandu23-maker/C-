#include <stdio.h>

class parent
{
   protected:
   int x;

   public:
   void set(int value)
   {
       x=value;
   }
};

class child:public parent
{
   public:
   int show()
   {
      printf("%d\n",x);
   }
};

int main()
{
  child obj;
  child *ptr;
  ptr=&obj;

  ptr->set(10);
  ptr->show();  
  return 0;
}
