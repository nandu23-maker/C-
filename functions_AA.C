#include <stdio.h>

class A
{
   public:
   A()
   {
      printf("A is a constructor\n");
   }
   
   void show(int a,float b)
   {
      printf("%d %.2f\n",a,b);
   }

   void show(float b,int a)
   {
      printf("%.2f %d\n",b,a);
   }
   
   ~A()
   {
       printf("destructor of A\n");
   }
};

class B:public A
{
     public:
   
     B()
    {
        printf("constructor of B\n");
    }
    ~B()
    {
        printf("Destructor of B\n");
    }
};
                                                    
int main()
{
    B obj;
    B *ptr;
    ptr=&obj;
    
    ptr->show(10,2.5);
    ptr->show(2.8,50);
   
    
    return 0;
}
