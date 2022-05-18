#include<stdio.h>
 
int seq(int); //Prototype
 
int main()
{
   int n, i = 1, c;
    printf("Enter a number less then 50: ")
    scanf("%d",&n); 
    for ( c = 1 ; c <= n ; c++ )
    {
      printf("%d\n", seq(i));
      i++; 
    }
 
    return 0;
}
 
int seq(int n)
{
   if ( n == 0 )
      return 0;
   else if ( n == 1 ) //When n ==1 seq output is 1
      return 1;
    else if (n==2)//When n ==2 seq output is 1
        return 1;
    else if (n==3) //When n ==3 seq output is 2
        return 2;
   else
      return (2*seq(n-1) + 3*seq(n-2)+seq(n-3) ); //Recrusive Formula
} 