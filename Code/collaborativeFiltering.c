#include<stdio.h>
#include<math.h>
void xuat_matran(float matrix[50][50],int numberOfUsers,int numberOfItems); // Hàm xuất ma trận
void inputMatrixFromKeyBoard(float matrix[50][50], int &numberOfUsers, int &numberOfItems);
void inputMatrix(char fileName[], float matrix[50][50], int &numberOfUsers, int &numberOfItems); // Hàm đọc giá trị ma trận từ file
void outputMatrix(char fileName[], float matrixOut[50][50], int columns,int rows); // Hàm xuất ma trận ra file
float getAvgRatingOfUser(float matrix[50][50],int user,int numberOfItems); // Hàm lấy giá trị rating trung bình của người dùng
float getSimilarity(float matrix[50][50],float avgMatrix[50][50],int user1,int user2,int numberOfItems); // Hàm lấy giá trị sim giữa hai người dùng 
void getNeighbor(float simMatrix[50][50],int numberOfUsers,int user, int k, int arr[]); // Hàm lấy neighbor
float getRating(float matrix[50][50], float simMatrix[50][50],float avgMatrix[50][50], int numberOfUsers, int numberOfItems, int k, int arr[], int user, int item);
void swap(float *a, float *b);
void saochep(float matrix1[50][50],float matrix2[50][50],int rows,int columns);
int main(){
  int numberOfUsers, numberOfItems; 
  int k;
  int arr[50];
  float matrix[50][50];
  float matrix2[50][50];
  float avgMatrix[50][50];
  float simMatrix[50][50];
  float simMatrix2[50][50];
  //inputMatrix("input.inp", matrix, numberOfUsers, numberOfItems);
  int optionMenu;
  int isInput = 0;
  do{
    system("cls");
    printf("******************************************************************************\n");
    printf("*                                                                            *\n");
    printf("*                      DO AN: LAP TRINH TINH TOAN                            *\n");
    printf("*               DE TAI: DU DOAN DIEM DANH GIA NGUOI DUNG                     *\n");
    printf("*                                                                            *\n");
    printf("******************************************************************************\n");
    printf("\n\n");
    printf("********************************    MENU   ***********************************\n");
    printf("*                                                                            *\n");
    printf("*   1. Input                                                                 *\n");
    printf("*   2. Output ket qua                                                        *\n");
    printf("*   3. Exit                                                                  *\n");
    printf("*                                                                            *\n");
    printf("******************************************************************************\n\n\n\n");
    printf("Nhap lua chon: ");
    scanf("%d",&optionMenu);
    switch(optionMenu){
      case 1:
        int inputOption;
        do {
          system("cls");
          printf("******************************************************************************\n");
          printf("*                                                                            *\n");
          printf("*                      DO AN: LAP TRINH TINH TOAN                            *\n");
          printf("*               DE TAI: DU DOAN DIEM DANH GIA NGUOI DUNG                     *\n");
          printf("*                                                                            *\n");
          printf("******************************************************************************\n");
          printf("\n\n");
          printf("****************************   INPUT MENU  ***********************************\n");
          printf("*                                                                            *\n");
          printf("*   1. Nhap input tu ban phim.                                               *\n");
          printf("*   2. Doc input tu file.                                                    *\n");
          printf("*   3. Exit                                                                  *\n");
          printf("*                                                                            *\n");
          printf("******************************************************************************\n\n\n\n");
          printf("Nhap lua chon: ");
          scanf("%d",&inputOption);
          switch(inputOption){
            case 1:
              system("cls");
              isInput = 1;
              printf("******************************************************************************\n");
              printf("*                                                                            *\n");
              printf("*                        NHAP INPUT TU BAN PHIM                              *\n");
              printf("*                                                                            *\n");
              printf("******************************************************************************\n\n\n");
              inputMatrixFromKeyBoard(matrix,numberOfUsers,numberOfItems);
              saochep(matrix,matrix2,numberOfUsers,numberOfItems);
              k = numberOfUsers/2;
              for (int i = 1;i <= numberOfUsers;i++){
                  float avgRatingOfUser = getAvgRatingOfUser(matrix, i, numberOfItems);
                  for (int j = 1;j <= numberOfItems;j++){
                    if (matrix[i][j] != 0) avgMatrix[i][j] = matrix[i][j] - avgRatingOfUser;
                      else avgMatrix[i][j] = 0;
                  }
              }
              for (int i = 1;i <= numberOfUsers;i++){
                  for (int j = 1;j <= numberOfUsers;j++){
                    simMatrix[i][j] = getSimilarity(matrix, avgMatrix, i, j, numberOfItems);
                  }
              }
              for (int i = 1;i <= numberOfUsers;i++){
                  float avgRating = getAvgRatingOfUser(matrix,i,numberOfItems);
                  getNeighbor(simMatrix, numberOfUsers, i, k, arr);
                  for (int j = 1;j <= numberOfItems;j++){ 
                    if (matrix[i][j] == 0) {
                      matrix[i][j] = avgRating + getRating(matrix, simMatrix, avgMatrix, numberOfUsers, numberOfItems, k, arr, i, j);
                    }
                  }
              }
              printf("\n\n");
              printf("Nhan phim bat ki de thoat.");
              fflush(stdin);
              getchar();
              break;
            case 2:
              system("cls");
              isInput = 1;
              printf("******************************************************************************\n");
              printf("*                                                                            *\n");
              printf("*                             DOC INPUT TU FILE                              *\n");
              printf("*                                                                            *\n");
              printf("******************************************************************************\n\n\n");
              char fileName[30];
              printf("Nhap ten file: ");
              fflush(stdin);
              gets(fileName);
              inputMatrix(fileName, matrix, numberOfUsers, numberOfItems);
              inputMatrix(fileName, matrix2, numberOfUsers, numberOfItems);
              k = numberOfUsers/2;
              for (int i = 1;i <= numberOfUsers;i++){
                  float avgRatingOfUser = getAvgRatingOfUser(matrix, i, numberOfItems);
                  for (int j = 1;j <= numberOfItems;j++){
                    if (matrix[i][j] != 0) avgMatrix[i][j] = matrix[i][j] - avgRatingOfUser;
                      else avgMatrix[i][j] = 0;
                  }
              }
              for (int i = 1;i <= numberOfUsers;i++){
                  for (int j = 1;j <= numberOfUsers;j++){
                    simMatrix[i][j] = getSimilarity(matrix, avgMatrix, i, j, numberOfItems);
                  }
              }for (int i = 1;i <= numberOfUsers;i++){
                  float avgRating = getAvgRatingOfUser(matrix,i,numberOfItems);
                  getNeighbor(simMatrix, numberOfUsers, i, k, arr);
                  for (int j = 1;j <= numberOfItems;j++){ 
                    if (matrix[i][j] == 0) {
                      matrix[i][j] = avgRating + getRating(matrix, simMatrix, avgMatrix, numberOfUsers, numberOfItems, k, arr, i, j);
                    }
                  }
              }
              printf("\n\n");
              printf("Nhan phim bat ki de thoat.");
              fflush(stdin);
              getchar();
              break;
          }
        }while(inputOption != 3);
        break;
      case 2:
        if (isInput == 0) {
          system("cls");
          printf("Input chua duoc doc.\n");
          printf("Nhan phim bat ki de quay lai.\n");
          fflush(stdin);
          getchar();
          break;
        }
        int outputOption;
        do {
          system("cls");
          printf("******************************************************************************\n");
          printf("*                                                                            *\n");
          printf("*                      DO AN: LAP TRINH TINH TOAN                            *\n");
          printf("*               DE TAI: DU DOAN DIEM DANH GIA NGUOI DUNG                     *\n");
          printf("*                                                                            *\n");
          printf("******************************************************************************\n");
          printf("\n\n");
          printf("****************************   OUTPUT MENU  **********************************\n");
          printf("*                                                                            *\n");
          printf("*   1. Hien thi ma tran dau vao.                                             *\n");
          printf("*   2. Hien thi ma tran tuong duong.                                         *\n");
          printf("*   3. Hien thi ket qua ra man hinh.                                         *\n");
          printf("*   4. Ghi ket qua ra file.                                                  *\n");
          printf("*   5. Exit                                                                  *\n");
          printf("*                                                                            *\n");
          printf("******************************************************************************\n\n\n\n");
          printf("Nhap lua chon: ");
          scanf("%d",&outputOption);
          switch(outputOption){
            case 1:
              system("cls");
              printf("******************************************************************************\n");
              printf("*                                                                            *\n");
              printf("*                             MA TRAN DAU VAO                                *\n");
              printf("*                                                                            *\n");
              printf("******************************************************************************\n\n\n");
              xuat_matran(matrix2, numberOfUsers, numberOfItems);
              printf("\n\n\n");
              printf("Nhan phim bat ki de thoat.");
              fflush(stdin);
              getchar();
              break;
            case 2:
              system("cls");
              printf("******************************************************************************\n");
              printf("*                                                                            *\n");
              printf("*                             MA TRAN TUONG DUONG                            *\n");
              printf("*                                                                            *\n");
              printf("******************************************************************************\n\n\n");
              xuat_matran(simMatrix, numberOfUsers, numberOfUsers);
              printf("\n\n\n");
              printf("Nhan phim bat ki de thoat.");
              fflush(stdin);
              getchar();
              break;
            case 3:
              system("cls");
              printf("******************************************************************************\n");
              printf("*                                                                            *\n");
              printf("*                         HIEN THI KET QUA RA MAN HINH                       *\n");
              printf("*                                                                            *\n");
              printf("******************************************************************************\n\n\n");
              xuat_matran(matrix, numberOfUsers, numberOfItems);
              printf("\n\n\n");
              printf("Nhan phim bat ki de thoat.");
              fflush(stdin);
              getchar();
            case 4:
              system("cls");
              printf("******************************************************************************\n");
              printf("*                                                                            *\n");
              printf("*                              GHI KET QUA VAO FILE                          *\n");
              printf("*                                                                            *\n");
              printf("******************************************************************************\n\n\n");
              char fileName[30];
              printf("Nhap ten file: ");
              fflush(stdin);
              gets(fileName);
              outputMatrix(fileName,matrix,numberOfUsers,numberOfItems);
              printf("\n\n\n");
              printf("Nhan phim bat ki de thoat.");
              fflush(stdin);
              getchar();
          }
        }while(outputOption != 5);
    }
  }while(optionMenu != 3);
  return 0;
}
// Hàm xuất ma trận
void saochep(float matrix1[50][50],float matrix2[50][50],int rows,int columns){
  for (int i = 1;i <= rows;i++){
    for (int j = 1;j <= columns;j++) matrix2[i][j] = matrix1[i][j];
  }
}
void xuat_matran(float matrix[50][50],int numberOfUsers,int numberOfItems){
  for(int i = 1; i <= numberOfUsers; i++) {
    for (int j = 1; j <= numberOfItems; j++) printf("%f\t",matrix[i][j]);
    printf("\n");
  } 
} 
void inputMatrixFromKeyBoard(float matrix[50][50], int &numberOfUsers, int &numberOfItems){
  printf("Nhap so luong nguoi dung: ");scanf("%d",&numberOfUsers);
  printf("Nhap so luong san pham: ");scanf("%d",&numberOfItems);
  printf("Nhap vao ma tran.\n");
  for (int i = 1;i <= numberOfUsers;i++){
    for (int j = 1;j <= numberOfItems;j++){
      scanf("%f",&matrix[i][j]);
    }
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
		exit(1);
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