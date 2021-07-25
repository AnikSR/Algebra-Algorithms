
#include<stdio.h>

/* Following three function performs three elementary row operations. 					*/
/****************************************************************************************
 * 1. Function		: multiply_rowwide.													*
 *	  Description	: Multiplies the specified row with a scalar.						*
 ****************************************************************************************/
// Prototype:
void multiply_rowwide(float *, int, int, float);

/****************************************************************************************
 * 2. Function		: row_exchange.														*
 *	  Description	: Exchange two rows with one another.								*
 ****************************************************************************************/
// Prototype:
void row_exchange(float *, int, int, int);

 /***************************************************************************************
 * 3. Function		: row_arithmetic.													*
 *    Description	: Add scalar multiple of one row with another.						*
 ****************************************************************************************/
//Prototype:
void row_arithmetic(float *, int, int, int, float);



/* Bringing the elementary row operations together to performa Gaus-Jordan Elimination.*/
void Gaus_Jordan(float *, int, int);




/* Auxilary functions:
 * These functions perform operations like calculating the index, determining the rank, inputing matrices or printing them etc. */

/*************************************************************
 * Function Name:	Index calcultor.						 *
 * Description	:	Matrix can be adeuately represented by   *
 *					2d arrays. But referencing 2d arrays is  *
 *					quarky in C. So rather matrix are here   *
 *					represented by 1d array. Hence the index *
 *					calculated manually.					 *
 *************************************************************/
//Prototype:
int icalc(int, int, int);


/*  Rank of a matrix is the highest number of linearly independent vectors
	that can be formed from the rows/columns of a matrix. However, rank of
	the input matrix is taken as the minimal of the number of row and the
	number of column of this matrix. This huristic will cause erronious
	result for some inputs as the rank of a matrix can be equal of less than
	the number determined here. */
// Prototype:
int min(int, int);


// Print a matrix as a table of numbers.
void print_matrix(float *, int, int);
