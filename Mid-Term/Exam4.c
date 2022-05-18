#include<stdio.h>
#include<math.h>
     
int main()
{
    int i,N,sum;
    printf("Enter an integer less than 50: ");
    scanf("%d",&N);
    sum=0;
     
    //calculate sum of the series
    for(i=1;i<=N;i++)
        sum= sum+ (pow(i,3)/i); //Power fuction that to calculate the power 
     
    printf("Sum of the series is: %d\n",sum);//print
     
    return 0;
}