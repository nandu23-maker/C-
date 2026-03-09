#include <stdio.h>

class data
{
    public:
    void show(int a,float b )
    {
       printf("%d %.2f\n",a,b);
    }

     void show(float a,int b)
    {
       printf("%.2f %d",a,b);
    }
       
};       
int main()
{
    data obj;
   
    obj.show(20,2.3);
    obj.show(2.9,80);  
    
    return 0;
}
