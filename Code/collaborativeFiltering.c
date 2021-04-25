#include<stdio.h>
#include<math.h>
void xuat_matran(float matrix[50][50],int numberOfUsers,int numberOfItems); // Hàm xuất ma trận
void inputMatrix(char fileName[], float matrix[50][50], int &numberOfUsers, int &numberOfItems); // Hàm đọc giá trị ma trận từ file
void outputMatrix(char fileName[], float matrixOut[50][50], int columns,int rows); // Hàm xuất ma trận ra file
float getAvgRatingOfUser(float matrix[50][50],int user,int numberOfItems); // Hàm lấy giá trị rating trung bình của người dùng
float getSimilarity(float matrix[50][50],float avgMatrix[50][50],int user1,int user2,int numberOfItems); // Hàm lấy giá trị sim giữa hai người dùng 
void getNeighbor(float simMatrix[50][50],int numberOfUsers,int user, int k, int arr[]); // Hàm lấy neighbor
float getRating(float matrix[50][50], float simMatrix[50][50],float avgMatrix[50][50], int numberOfUsers, int numberOfItems, int k, int arr[], int user, int item);
void swap(float *a, float *b);
int main(){
  int numberOfUsers, numberOfItems; 
  float matrix[50][50];
  float avgMatrix[50][50];
  float simMatrix[50][50];
  float simMatrix2[50][50];
  inputMatrix("input.inp", matrix, numberOfUsers, numberOfItems);
  int k = numberOfUsers/2;
  int arr[k + 1];
  //printf("Input matrix\n");
  xuat_matran(matrix, numberOfUsers, numberOfItems);
  outputMatrix("output.out", matrix, numberOfUsers, numberOfItems);
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

  // Gán giá trị sim vào ma trận
  for (int i = 1;i <= numberOfUsers;i++){

    for (int j = 1;j <= numberOfUsers;j++){
      simMatrix[i][j] = getSimilarity(matrix, avgMatrix, i, j, numberOfItems);
    }
  }  
  xuat_matran(simMatrix, numberOfUsers, numberOfUsers); 
  for (int i = 1;i <= numberOfUsers;i++){
    float avgRating = getAvgRatingOfUser(matrix,i,numberOfItems);
    getNeighbor(simMatrix, numberOfUsers, i, k, arr);
    for (int j = 1;j <= numberOfItems;j++){ 
      if (matrix[i][j] == 0) {
        matrix[i][j] = avgRating + getRating(matrix, simMatrix, avgMatrix, numberOfUsers, numberOfItems, k, arr, i, j);
      }
    }
  }
  printf("\n");
  xuat_matran(matrix, numberOfUsers, numberOfItems);
  /*
  printf("******************************************************************************\n");
  printf("*                                                                            *\n");
  printf("*                      DO AN: LAP TRINH TINH TOAN                            *\n");
  printf("*               DE TAI: DU DOAN DIEM DANH GIA NGUOI DUNG                     *\n");
  printf("*                                                                            *\n");
  printf("******************************************************************************\n");
  printf("\n\n");
  printf("********************************  MENU   *************************************\n");
  printf("*                                                                            *\n");
  printf("*   1. Doc du lieu tu file                                                   *\n");
  */
  return 0;
}
// Hàm xuất ma trận
void xuat_matran(float matrix[50][50],int numberOfUsers,int numberOfItems){
  for(int i = 1; i <= numberOfUsers; i++) {
    for (int j = 1; j <= numberOfItems; j++) printf("%f\t",matrix[i][j]);
    printf("\n");
  } 
} 
 // Hàm đọc giá trị ma trận từ file
void inputMatrix(char fileName[], float matrix[50][50], int &numberOfUsers, int &numberOfItems){
  FILE *fptr;
  fptr = fopen(fileName,"r");
  int rows = 1, columns = 0;
  char c;
  if (fptr == NULL){
    printf("Can't open file.");
    exit(1);
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
// Ghi kết quả ma trận ra file
void outputMatrix(char fileName[], float matrix[50][50], int rows, int columns){
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
void swap(float *a, float *b){
  float temp = *a;
  *a = *b;
  *b = temp;
}
void getNeighbor(float simMatrix[50][50],int numberOfUsers,int user, int k, int arr[]) {
  int n = numberOfUsers;
  int q = 1;
  float simMatrix2[numberOfUsers + 1][numberOfUsers + 1];
  for (int j = 1;j <= numberOfUsers;j++){
      simMatrix2[user][j] = simMatrix[user][j];
  }
  for (int i = 1;i <= k;i++){
    float maxRating = (user == 1) ? simMatrix2[user][2] : simMatrix2[user][1];
    int index = (user == 1) ? 2 : 1;
    for (int j = 1;j <= n;j++){
        if (simMatrix2[user][j] > maxRating && simMatrix2[user][j] != 1){
          maxRating = simMatrix2[user][j];
          index = j;
        }
    }
    arr[q++] = index;
    swap(&simMatrix2[user][index], &simMatrix2[user][n]);
    n--;
  }
}
float getRating(float matrix[50][50], float simMatrix[50][50],float avgMatrix[50][50], int numberOfUsers, int numberOfItems, int k, int arr[], int user, int item){
  float tuSo = 0;
  float mauSo = 0;
  for (int i = 1;i <= k;i++){
     tuSo += simMatrix[arr[i]][user]*avgMatrix[arr[i]][item];
     mauSo += abs(simMatrix[arr[i]][user]);
  }
  return (tuSo/mauSo);
}