#include<stdio.h>
#include<string.h>
#include<math.h>
void xuat_matran(float matrix[50][50],int numberOfUsers,int numberOfItems); 
void inputMatrix(char fileName[], float matrix[50][50], int &numberOfUsers, int &numberOfItems);
int main(){
  int numberOfUsers, numberOfItems; 
  float matrix[50][50];
  inputMatrix("input.inp", matrix, numberOfUsers, 
  numberOfItems);xuat_matran(matrix, numberOfUsers, numberOfItems);
  printf("%d %d",numberOfUsers,numberOfItems);
}
void xuat_matran(float matrix[50][50],int numberOfUsers,int numberOfItems){
  for(int i = 1; i <= numberOfUsers; i++) {
    for ( int j = 1; j <= numberOfItems; j++) printf("%f\t",matrix[i][j]);
    printf("\n");
  } 
}
void inputMatrix(char fileName[], float matrix[50][50], int &numberOfUsers, int &numberOfItems){
   FILE *fptr;
   fptr = fopen(fileName,"r");
   int rows = 1, columns = 0;
   char c;
   	while((c = fgetc(fptr)) != EOF){
   		if (c == '\n'){
   			rows += 1;
   			columns = 1;
   		}else{
   			fseek(fptr, -1, SEEK_CUR);
   			columns += 1;
   		}
   		fscanf(fptr,"%f",&matrix[rows][columns]);
   }
   numberOfUsers = rows;
   numberOfItems = columns;
   fclose(fptr);
}