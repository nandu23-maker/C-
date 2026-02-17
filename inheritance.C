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
    child obj1;
    child obj2;
    child obj3;
     
    obj.set(20);
    obj1.set(50);
    obj2.set(30);
    obj3.set(40);
  
    obj.show();
    obj1.show();
    obj2.show();
    obj3.show();
    
    
    return 0;
}
