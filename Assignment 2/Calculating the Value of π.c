#include <stdio.h>
int pie(float lower, float upper); //Prototype 

int main(){
	printf("First closest value to: 3.14\n");
	pie(3.139,3.141);

	printf("First closest value to: 3.141\n");
	pie(3.1409,3.1411);

	printf("First closest value to: 3.1415\n");
	pie(3.14149,3.14151);

	printf("First closest value to: 3.14159\n");
	pie(3.141589,3.141591);
}

int pie(float lower, float upper)// Function for finding the closest value
{
	unsigned long int i=1; // Its possible we could get big value 
	double p = 0; // Use to save value for the equation For decimal points
	int j=1; //Flag for the  loop
while (j!=0){

	if ( i % 2 == 0) { //For positive integers based on series
		p = p - (4.0 / (2 * i - 1));
	}

	else {
		p = p + (4.0 / (2 * i - 1));//For negitive integers based on series
	}

	if ( p > lower && p < upper){ //conditon to find the closest value
		printf( "%ld\t%lf\t\n",i, p ); //print outputs
		j=0;
	}
	i=i+1;
    }
}


