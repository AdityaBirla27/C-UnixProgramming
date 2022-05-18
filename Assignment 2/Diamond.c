#include<stdio.h>
int diamond( int n); //prototype 
int main(){ // Main Function
    diamond(15); //Calling Function 
}

int diamond(int n){ 
    n=n/2+1; //Convert number of elements to number of rows

    int i,j;
    int space = n-1;

    /* Code For incressing number of stars*/
    for (i=0;i<n-1;i++)//Loop for number of row
    {
        for (j=0;j<space;j++)//Loop for spaces
            printf(" ");

        for (j=0;j<=2*i;j++)//Loop to print *
            printf("*");

        printf("\n");// Go to next line
        space--;
    }

    /* Code For incressing number of stars*/
    space=0;
    for (i=n; i>0;i--)//Loop for number of row
    {
        for (j=0; j<space;j++)//Loop for spaces
            printf(" ");

        for (j=0;j<2*i-1;j++)//Loop to print *
            printf("*");

        printf("\n");// Go to next line
        space++;
    }
}
