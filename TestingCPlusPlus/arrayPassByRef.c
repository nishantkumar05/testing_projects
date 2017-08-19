#include <stdio.h>

void f(int a[], int l)
{
  printf("Array => ");
  for(int i = 0 ; i < l ;  i++ )
  {
     printf("%d, ", *(a+i));
  }
  printf("\n");
}

int main(int argc, char **argv)
{
  int a[]={1,2,3,4,5};
   f(a, 5);

  return 0;
}
