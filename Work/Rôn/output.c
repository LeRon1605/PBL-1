#include<stdio.h>
#include<string.h>
void inputMatrix(char fileName[], float matrix[50][50], int &numberOfUsers, int &numberOfItems){
  FILE *fptr;
  fptr = fopen(fileName,"r");
  int rows = 1, columns = 0;
  char c;
  if (fptr == NULL){
    printf("Can't open file.");
    //exit(1);
  }else{
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
  }
  numberOfUsers = rows;
  numberOfItems = columns;
  fclose(fptr);
}
void outputMatrix(char fileName[], float matrix[50][50], int columns,int rows){
  FILE *fptr = fopen(fileName,"w");
  if (fptr == NULL){
    printf("Can't open file.");
    //exit(1);
  }else{
    for (int i = 1;i <= rows;i++){
      for (int j = 1;j <= columns;j++) fprintf(fptr, "%2.2f\t", matrix[i][j]);
      fprintf(fptr, "\n" );
    }
  }
  fclose(fptr);
}
int main(){
	int numberOfUsers, numberOfItems; 
 	float matrix[50][50];
 	inputMatrix("input.inp", matrix, numberOfUsers, numberOfItems);
 	outputMatrix("output.out", matrix,numberOfItems, numberOfUsers);
}