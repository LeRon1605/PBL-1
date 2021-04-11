#include<stdio.h>
Void OutputMatrix(char fileName[], float matrix[50][50], int numberOfUsers, int numberOfItems ){
	for(int i = 0; i <= numberOfUsers, i++) {
		for ( int j = 0; j <= numberOfItems; j++) 
		printf("%f\t",&matrix[i][j]);
		printf("\n");
	}	
}	
