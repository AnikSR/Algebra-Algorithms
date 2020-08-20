#include<stdio.h>

// Three elementary row operation.
void row_exchange(float *, int, int, int);
void multiply_rowwide(float *, int, int, float);
void row_arithmetic(float *, int, int, int, float);

// Bringing the elementary row operations together.
void Gaus_Jordan(float *, int, int);

// Auxilary functions.
void print_matrix(float *, int, int);
int icalc(int, int, int);
int min(int, int);


int main(){
	float mtrx[6*3] = { 0, 5, 6, 1, 0, 0,   7, 3, 0, 0, 1, 0,   6, 9, 2, 0, 0, 1 };

	puts("Input Matrix:");
	print_matrix(mtrx, 6, 3);

	// Run the matrix through Gaus-Jordan algorithm:
	Gaus_Jordan(mtrx, 6, 3);

	puts("\nOutput Matrix:");
	print_matrix(mtrx, 6, 3);

	return 0;
}


/*****************************************************************
 * Function Name: 	Index calcultor.			 *
 * Description	: 	Matrix can be adeuately represented by   *
 *		  	2d arrays. But referencing 2d arrays is  *
 *			quarky in C. So rather matrix are here   *
 *			represented by 1d array. Hence the index *
 *			calculated manually.			 *
 *****************************************************************/
int icalc(int row_number, int row_length, int member_number){
	return row_number*row_length+member_number;
}


void print_matrix(float *mtrx, int rowlen, int columnlen){
	for(int i=0; i<columnlen; i++){
		for(int j=0; j<rowlen; j++)
			printf("\t%f", mtrx[icalc(i, rowlen, j)]);
		puts("");
	}
}


/*  Rank of a matrix is the highest number of linearly independent vectors
	that can be formed from the rows/columns of a matrix. However, rank
	of the input matrix is taken as the minimal of the number of row and
	the number of column of this matrix. This huristic will cause erronious
	result for some inputs as the rank of a matrix can be equal of less than
	the number determined here. */
int min(int num1, int num2){
	if(num1 < num2)
		return num1;
	
	return num2;
}


/****************************************************************************************
 * Following three function performs three elementary row operations. 			*
 * 1. Function		: multiply_rowwide.						*
 *	  Description	: Multiplies the specified row with a scalar.			*
 *											*
 * 2. Function		: row_exchange.							*
 *	  Description	: Exchange two rows with one another.				*
 *											*
 * 3. Function		: row_arithmetic.						*
 *    Description	: Add scalar multiple of one row with another.			*
 ****************************************************************************************/
void multiply_rowwide(float *mtrx, int row_num, int row_len, float scalar){
	for(int i=0; i<row_len; i++)
		mtrx[icalc(row_num, row_len, i)] *= scalar;
}


void row_arithmetic(float *mtrx, int row_len, int target_row, int add_row, float scalar){
	for(int i=0; i<row_len; i++){
		float B = mtrx[icalc(add_row, row_len, i)]*scalar;
		mtrx[icalc(target_row, row_len, i)] -= B;
	}
}


void row_exchange(float *mtrx, int row1, int row2, int rowlength){
	float temp = 0;
	
	for(int i=0; i<rowlength; i++){
		temp = mtrx[icalc(row1, rowlength, i)];
		mtrx[icalc(row1, rowlength, i)] = mtrx[icalc(row2, rowlength, i)];
		mtrx[icalc(row2, rowlength, i)] = temp;
	}
}


/* Combining all three elementary row operation for Gaus-Jordn elemination. */
void Gaus_Jordan(float *mtrx, int row_len, int column_len){
	int rank = min(row_len, column_len);

	for(int i=0; i<rank; i++){
		// If the leading element of a row is 0, exchange the row with the row bellow it.
        	for(int j=1; mtrx[icalc(i, row_len, i)] == 0 || i+j<column_len; j++)
            		row_exchange(mtrx, i, i+j, row_len);

		// If the leading element is not 1, then divide the row with the leading element.
		multiply_rowwide(mtrx, i, row_len, 1/mtrx[icalc(i, row_len, i)]);

		// Multiply the current row with the leading element of subsequent rows and substracts it from them.
		for(int j=0; j<column_len; j++)
			if(i != j)
				row_arithmetic(mtrx, row_len, j, i, mtrx[icalc(j, row_len, i)]);
	}
}
