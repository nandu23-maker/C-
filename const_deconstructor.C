#include <stdio.h>

class data
{
   protected:
   int x;
  
   public:
   data(int x)
   {
     this->x=x;
     printf("This is a constructor: %d\n",x);
   }

   ~data()
   {
       printf("This is a deconstructor");
   }
};
   int main()
{
   data obj(20);
      
    return 0;
}
