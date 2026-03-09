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
   child obj[3];
   
   obj[0].set(10);
   obj[1].set(20);
   obj[2].set(30);

   obj[0].show();
   obj[1].show();
   obj[2].show();

    return 0;
}
