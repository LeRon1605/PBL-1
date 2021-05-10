#include<stdio.h>
#include<string.h>
#include<math.h>
void xuat_matran(float matrix[50][50],int hang,int cot); 
void inputMatrix(char fileName[], float matrix[50][50], int &hang, int &cot);
int main(){
  int hang = 3, cot; 
  float matrix[50][50];
  inputMatrix("input.inp", matrix, hang, cot);
  xuat_matran(matrix, hang, cot);
  printf("%d %d",hang,cot);
}
void xuat_matran(float matrix[50][50],int hang,int cot){
  for(int i = 1; i <= hang; i++) {
    for ( int j = 1; j <= cot; j++) printf("%f\t",matrix[i][j]);
    printf("\n");
  } 
}
void inputMatrix(char fileName[], float matrix[50][50], int &hang, int &cot){
  FILE *fptr;
  fptr = fopen(fileName,"r");
  int rows = 1, columns = 0;
  char c;
  if (fptr == NULL){
    printf("Can't open file.");
    exit(1);
  }else{
    fscanf(fptr,"%d",&cot);
    for (int i = 1;i <= hang;i++){
      for (int j = 1;j <= cot;j++){
        fscanf(fptr,"%f",&matrix[i][j]);
      }
    } 
  }
  fclose(fptr);
}