
/* Extended Euclid's algorithm to determine the coefficients such that the linear combination produces the gcd. */
#include<stdio.h>

void EuclidX(int, int, int *);

int main(void){
	int num1, num2, temp=0;
	int coefficient[3] = { 0, 0, 0 };

	puts("\n");
	puts("This program calculates the gcd and the smallest coefficient satisfying Bezout's identity ps + qt = gcd(p,q)");
	puts("In the output:");
	puts("The 's' stands for the coefficient of the first number inserted.");
	puts("The 't' stands for the coefficient of the second number inserted.");
	puts("==============================================================================================================");

	printf("Insert two integers: ");
	scanf("%d %d", &num1, &num2);

	if(num2>num1){
		temp = num2;
		num2 = num1;
		num1 = temp;
		temp = 1;
	}

	getchar();		// Eat up any stray character length input hanging in the stdin.
	fflush(stdin);	// Flush out any unwanted character in the stdin.

	EuclidX(num1, num2, coefficient);

	if(temp == 1){
		printf("\ngcd(%d, %d) = %d with s = %d, t = %d\n", num1, num2, coefficient[0], coefficient[1], coefficient[2]);
		printf("Thus %d.%d + %d.%d = %d\n", num2, coefficient[2], num1, coefficient[1], coefficient[0]);
	} else{
		printf("\ngcd(%d, %d) = %d with s = %d, t = %d\n", num2, num1, coefficient[0], coefficient[2], coefficient[1]);
		printf("Thus %d.%d + %d.%d = %d\n", num1, coefficient[1], num2, coefficient[2], coefficient[0]);
	}

	return 0;
}


void EuclidX(int r1, int r2, int * coefficient){
	int r, q, s, t, s1=1, s2=0, t1=0, t2=1;
	int step_no = 1;

	/* The first integer have to be the biggest one for this algorithm to work.
	   So, exchange the integers if the second one is the biggest. */

	puts("\nThe complete coefficient table:");
	printf("First number, r1 =\t%d\nSecond number, r2 =\t%d\n\n", r1, r2);

	while(r!=0){
		// Determining the reminder and the quotient of this round.
		r = r1%r2;
		q = (int)r1/r2;
		
		// Determining the coefficient of this round.
		s = s1 - q*s2;
		t = t1 - q*t2;

		if(r!=0)
			printf("Step %d: r=%d\ts=%d\tt=%d\n", step_no, r, s, t);

		// Update the input for the next round.
		r1 = r2;
		r2 = r;

		s1 = s2;
		s2 = s;

		t1 = t2;
		t2 = t;

		step_no++;
	}

	coefficient[0] = r1;	// The greatest common divisor.
	coefficient[1] = s1;	// Coefficient for the first integer.
	coefficient[2] = t1;	// Coefficient for the second integer.
}
