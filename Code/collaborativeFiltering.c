#include<stdio.h>
void inputMatrix(char fileName[],float matrix[50][50]);
void xuat_matran(float matrix[50][50],int numberOfUsers,int numberOfItems);
float gia_tri_trung_binh(float matrix[50][50],int user,int numberOfItems);
float similarity(float matrix[50][50],float avgMatrix[50][50],int user1,int user2,int numberOfItems);
void outputMatrix(char fileName[],float matrixOut[50][50]);
int main(){
  printf("Hello World");
  return 0;
}