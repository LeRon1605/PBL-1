#include<stdio.h>
void inputMatrix(char fileName[], float matrix[50][50], int &numberOfUsers, int &numberOfItems);
void xuat_matran(float matrix[50][50],int numberOfUsers,int numberOfItems);
float gia_tri_trung_binh(float matrix[50][50],int user,int numberOfItems);
float similarity(float matrix[50][50],float avgMatrix[50][50],int user1,int user2,int numberOfItems);
void outputMatrix(char fileName[],float matrixOut[50][50]);
int main(){
	int numberOfUsers, numberOfItems; 
 	float matrix[50][50];
 	float avgMatrix[50][50];
  float simMatrix[50][50];
  inputMatrix("input.inp", matrix, numberOfUsers, numberOfItems);
  return 0;
}
void inputMatrix(char fileName[],float matrix[50][50], int &numberOfUsers, int &numberOfItems){
	FILE *fptr;
  	fptr = fopen(fileName,"r+");
  	fscanf(fptr,"%d",&numberOfUsers);
  	fscanf(fptr,"%d",&numberOfItems);
  	for (int i = 1;i <= numberOfUsers;i++){
  		for (int j = 1;j <= numberOfItems;j++) fscanf(fptr,"%f",&matrix[i][j]);
  	}
  	fclose(fptr);
}
