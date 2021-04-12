#include<stdio.h>
#include<math.h>
void xuat_matran(float matrix[50][50],int numberOfUsers,int numberOfItems); // Hàm xuất ma trận
void inputMatrix(char fileName[], float matrix[50][50], int &numberOfUsers, int &numberOfItems); // Hàm đọc giá trị ma trận từ file
float getAvgRatingOfUser(float matrix[50][50],int user,int numberOfItems); // Hàm lấy giá trị rating trung bình của người dùng
float getSimilarity(float matrix[50][50],float avgMatrix[50][50],int user1,int user2,int numberOfItems); // Hàm lấy giá trị sim giữa hai người dùng 
void outputMatrix(char fileName[],float matrixOut[50][50]); // Hàm ghi ma trận kết quả ra file


int main(){
  int numberOfUsers, numberOfItems; 
  float matrix[50][50];
  float avgMatrix[50][50];
  float simMatrix[50][50];
  inputMatrix("input.inp", matrix, numberOfUsers, numberOfItems);
  xuat_matran(matrix, numberOfUsers, numberOfItems);
  printf("\n\n\n");
  //
  for (int i = 1;i <= numberOfUsers;i++){
    float avgRatingOfUser = getAvgRatingOfUser(matrix, i, numberOfItems);
    for (int j = 1;j <= numberOfItems;j++){
      if (matrix[i][j] != 0) avgMatrix[i][j] = matrix[i][j] - avgRatingOfUser;
        else avgMatrix[i][j] = 0;
    }
  }
  // Trừ giá trị rating cho rating trung bình lưu vào ma trận avgMatrix
  xuat_matran(avgMatrix, numberOfUsers, numberOfItems);
  printf("\n\n\n");
  return 0;
}

// Hàm xuất ma trận
void xuat_matran(float matrix[50][50],int numberOfUsers,int numberOfItems){
  for(int i = 1; i <= numberOfUsers; i++) {
    for ( int j = 1; j <= numberOfItems; j++) printf("%f\t",matrix[i][j]);
    printf("\n");
  } 
} 
 // Hàm đọc giá trị ma trận từ file
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
// Hàm lấy giá trị sim giữa hai người dùng 
float getAvgRatingOfUser(float matrix[50][50],int user,int numberOfItems){
  int count = 0;
  float sum = 0;
  for (int j = 1;j <= numberOfItems;j++){
    if (matrix[user][j] != 0) {
      count++;
      sum += matrix[user][j];
    }
  }
  return (sum/count);
} 
// Hàm lấy giá trị sim giữa hai người dùng 
float getSimilarity(float matrix[50][50],float avgMatrix[50][50],int user1,int user2,int numberOfItems){
  float tuSo = 0;
  float sumOfUser1 = 0;
  float sumOfUser2 = 0;
  for (int i = 1;i <= numberOfItems;i++){
    if (matrix[user1][i] * matrix[user2][i] != 0){
      tuSo += avgMatrix[user1][i]*avgMatrix[user2][i];
      sumOfUser1 += pow(avgMatrix[user1][i], 2);
      sumOfUser2 += pow(avgMatrix[user2][i], 2);
    }
  }
  return (tuSo/(sqrt(sumOfUser1)*sqrt(sumOfUser2)));
}