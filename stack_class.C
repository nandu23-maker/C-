#include <stdio.h>

class stack
{
  private:
  int arr[3];
  int i=0;

  public:
  void push(int value)
  {
    if(i>=3)
    {
        printf("stack is full\n");
    }
    else
    {
       arr[i]=value;
       i++;
    }
  }
  
  int pop()
  {
     if(i==0)
     {
         printf("not found\n");
     }
     else
     {
        i--;
     }
  }

  int show()
  {
      for(int j=0;j<i;j++)
      {
          printf("%d\n",arr[j]);
      }
  }
};
  
int main()
{
  stack s;
  
  s.push(40);
  s.push(50);
  s.push(60);
  
  s.show(); 
  s.pop();
  s.show();  
    return 0;
}
