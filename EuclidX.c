
/* Extended Euclid's algorithm to determine the coefficients such that the linear combination produces the gcd. */
#include<stdio.h>

void gcdCoefficient(int, int, int *);

int main(void){
	int num1, num2, temp=0;
	int coefficient[3] = { 0, 0, 0 };

	printf("Insert two integers: ");
	scanf("%d %d", &num1, &num2);

	printf("Before: num1 = %d, num2 = %d\n", num1, num2);
	if(num2>num1){
		temp = num2;
		num2 = num1;
		num1 = temp;
		temp = 1;
	}
	printf("After: num1 = %d, num2 = %d\n", num1, num2);

	getchar();		// Eat up any stray character length input hanging in the stdin.
	fflush(stdin);	// Flush out any unwanted character in the stdin.

	gcdCoefficient(num1, num2, coefficient);

	if(temp == 1){
		printf("For %d and %d; s = %d, t = %d.\n", num2, num1, coefficient[2], coefficient[1]);
		printf("Thus %d.%d + %d.%d = %d\n", num2, coefficient[2], num1, coefficient[1], coefficient[0]);
	} else{
		printf("For %d and %d; s = %d, t = %d.\n", num1, num2, coefficient[1], coefficient[2]);
		printf("Thus %d.%d + %d.%d = %d\n", num1, coefficient[1], num2, coefficient[2], coefficient[0]);
	}

	return 0;
}


void gcdCoefficient(int r1, int r2, int * coefficient){
	int r, q, s, t, s1=1, s2=0, t1=0, t2=1;

	/* The first integer have to be the biggest one for this algorithm to work.
	   So, exchange the integers if the second one is the biggest. */

	while(r!=0){
		// Determining the reminder and the quotient of this round.
		r = r1%r2;
		q = (int)r1/r2;
		
		// Determining the coefficient of this round.
		s = s1 - q*s2;
		t = t1 - q*t2;

		// Update the input for the next round.
		r1 = r2;
		r2 = r;

		s1 = s2;
		s2 = s;

		t1 = t2;
		t2 = t;
	}

	coefficient[0] = r1;	// The greatest common divisor.
	coefficient[1] = s1;		// Coefficient for the first integer.
	coefficient[2] = t1;		// Coefficient for the second integer.
}
