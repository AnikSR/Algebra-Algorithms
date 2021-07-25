#include "Algebra.h"

extern int r1, r2, *coefficient;

/* Extended Euclid's algorithm to determine the coefficients such that the linear combination produces the gcd. */
void gcdCoefficient(int r1, int r2, int * coefficient){
	int r, q, s, t, s1=1, s2=0, t1=0, t2=1;
	int setp_no = 1;

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



/* Good old Euclid's algorithms of determining gcd of two numbers. */
int gcdEuclid(int r1, int r2){
	int r;

	while(r!=0){
		r = r1%r2;
		r1 = r2;
		r2 = r;
	}

	return r1;
}
