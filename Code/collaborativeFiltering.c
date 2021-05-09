#include<stdio.h>
#include<math.h>
void xuat_matran(float matrix[50][50],int numberOfUsers,int numberOfItems); // Hàm xuất ma trận
void inputMatrixFromKeyBoard(float matrix[50][50], int &numberOfUsers, int &numberOfItems);
void inputMatrix(char fileName[], float matrix[50][50], int &numberOfUsers, int &numberOfItems); // Hàm đọc giá trị ma trận từ file
void outputMatrix(char fileName[], float matrixOut[50][50], int columns,int rows); // Hàm xuất ma trận ra file
float getAvgRatingOfUser(float matrix[50][50],int user,int numberOfItems); // Hàm lấy giá trị rating trung bình của người dùng
float getSimilarityPearson(float matrix[50][50],float avgMatrix[50][50],int user1,int user2,int numberOfItems); // Hàm lấy giá trị sim giữa hai người dùng 
float getSimilarityCosine(float matrix[50][50],int user1,int user2,int numberOfItems);
void getNeighbor(float simMatrix[50][50],int numberOfUsers,int user, int k, int arr[]); // Hàm lấy neighbor
float getRating(float matrix[50][50], float simMatrix[50][50],float calMatrix[50][50], int numberOfUsers, int numberOfItems, int k, int arr[], int user, int item);
void swap(float *a, float *b);
void run(float matrix[50][50],float avgMatrix[50][50], float simMatrixPearson[50][50], float simMatrixCosine[50][50],float resultMatrixCosine[50][50], float resultMatrixPearson[50][50],int arrPearson[], int arrCosine[], int k, int numberOfUsers, int numberOfItems);
int main(){
  int numberOfUsers, numberOfItems; 
  int k;
  int arrPearson[50];
  int arrCosine[50];
  float matrix[50][50];
  float avgMatrix[50][50];
  float resultMatrixPearson[50][50];
  float resultMatrixCosine[50][50];
  float simMatrixPearson[50][50];
  float simMatrixCosine[50][50];
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
              k = numberOfUsers/2;
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

              k = numberOfUsers/2;
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
        }else{
          run(matrix,avgMatrix, simMatrixPearson, simMatrixCosine,resultMatrixCosine,  resultMatrixPearson, arrPearson,arrCosine,  k,  numberOfUsers,  numberOfItems);
        }
        int outputOption;
        do {
          system("cls");
          printf("\n");
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
          printf("*   2. Hien thi ma tran tuong duong pearson                                  *\n");
          printf("*   3. Hien thi ma tran tuong duong cosine                                   *\n");
          printf("*   4. Hien thi ket qua theo ham pearson ra man hinh.                        *\n");
          printf("*   5. Hien thi ket qua theo ham cosine ra man hinh.                         *\n");
          printf("*   6. Ghi ket qua ra file.                                                  *\n");
          printf("*   7. Exit                                                                  *\n");
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
              xuat_matran(matrix, numberOfUsers, numberOfItems);
              printf("\n\n\n");
              printf("Nhan phim bat ki de thoat.");
              fflush(stdin);
              getchar();
              break;
            case 2:
              system("cls");
              printf("******************************************************************************\n");
              printf("*                                                                            *\n");
              printf("*                        MA TRAN TUONG DUONG PEARSON                         *\n");
              printf("*                                                                            *\n");
              printf("******************************************************************************\n\n\n");
              xuat_matran(simMatrixPearson, numberOfUsers, numberOfUsers);
              printf("\n\n\n");
              printf("Nhan phim bat ki de thoat.");
              fflush(stdin);
              getchar();
              break;
            case 3:
              system("cls");
              printf("******************************************************************************\n");
              printf("*                                                                            *\n");
              printf("*                        MA TRAN TUONG DUONG COSINE                          *\n");
              printf("*                                                                            *\n");
              printf("******************************************************************************\n\n\n");
              xuat_matran(simMatrixCosine, numberOfUsers, numberOfUsers);
              printf("\n\n\n");
              printf("Nhan phim bat ki de thoat.");
              fflush(stdin);
              getchar();
              break;
            case 4:
              system("cls");
              printf("******************************************************************************\n");
              printf("*                                                                            *\n");
              printf("*                HIEN THI KET QUA THEO HAM PEARSON RA MAN HINH               *\n");
              printf("*                                                                            *\n");
              printf("******************************************************************************\n\n\n");
              xuat_matran(resultMatrixPearson, numberOfUsers, numberOfItems);
              printf("\n\n\n");
              printf("Nhan phim bat ki de thoat.");
              fflush(stdin);
              getchar();
              break;
            case 5:
              system("cls");
              printf("******************************************************************************\n");
              printf("*                                                                            *\n");
              printf("*                HIEN THI KET QUA THEO HAM COSINE RA MAN HINH               *\n");
              printf("*                                                                            *\n");
              printf("******************************************************************************\n\n\n");
              xuat_matran(resultMatrixCosine, numberOfUsers, numberOfItems);
              printf("\n\n\n");
              printf("Nhan phim bat ki de thoat.");
              fflush(stdin);
              getchar();
              break;
            case 6:
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
              break;
          }
        }while(outputOption != 7);
    }
  }while(optionMenu != 3);
  return 0;
}
// Hàm xuất ma trận
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
// Hàm lấy giá trị sim giữa hai người dùng Pearson
float getSimilarityPearson(float matrix[50][50],float avgMatrix[50][50],int user1,int user2,int numberOfItems){
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
// Hàm lấy giá trị sim giữa hai người dùng Cosine
float getSimilarityCosine(float matrix[50][50],int user1,int user2,int numberOfItems){
  float tuSo = 0;
  float sumOfUser1 = 0;
  float sumOfUser2 = 0;
  for (int i = 1;i <= numberOfItems;i++){
    if (matrix[user1][i] * matrix[user2][i] != 0){
      tuSo += matrix[user1][i]*matrix[user2][i];
      sumOfUser1 += pow(matrix[user1][i], 2);
      sumOfUser2 += pow(matrix[user2][i], 2);
    }
  }
  return tuSo/(sqrt(sumOfUser1)*sqrt(sumOfUser2));
}
void swap(float *a, float *b){
  float temp = *a;
  *a = *b;
  *b = temp;
}
void getNeighbor(float simMatrix[50][50],int numberOfUsers,int user, int k, int arr[]) {
  // Đưa giá trị min về cuối mảng
  int n = numberOfUsers;
  float simMatrix_Copy[numberOfUsers + 1][numberOfUsers + 1];
  for (int j = 1;j <= numberOfUsers;j++){
      simMatrix_Copy[user][j] = simMatrix[user][j];
      arr[j] = j;
  }
  swap(&simMatrix_Copy[user][user],&simMatrix_Copy[user][n]);
  int temp = arr[user];
  arr[user] = arr[n];
  arr[n] = temp;
  for (int i = 1;i < numberOfUsers;i++){
    float minRating = (user == 1) ? simMatrix_Copy[user][2] : simMatrix_Copy[user][1];
    int index = (user == 1) ? 2 : 1;
    for (int j = 1;j < n;j++){
        if (simMatrix_Copy[user][j] < minRating){
          minRating = simMatrix_Copy[user][j];
          index = j;
        }
    }
    swap(&simMatrix_Copy[user][index], &simMatrix_Copy[user][n - 1]);
    int temp = arr[index];
    arr[index] = arr[n - 1];
    arr[n - 1] = temp;
    n--;
  }
}
float getRating(float matrix[50][50], float simMatrix[50][50],float calMatrix[50][50], int numberOfUsers, int numberOfItems, int k, int arr[], int user, int item){
  float tuSo = 0;
  float mauSo = 0;
  for (int i = 1;i <= k;i++){
     tuSo += simMatrix[arr[i]][user]*calMatrix[arr[i]][item];
     mauSo += abs(simMatrix[arr[i]][user]);
  }
  return (tuSo/mauSo);
}
void run(float matrix[50][50],float avgMatrix[50][50], float simMatrixPearson[50][50], float simMatrixCosine[50][50],float resultMatrixCosine[50][50], float resultMatrixPearson[50][50],int arrPearson[],int arrCosine[], int k, int numberOfUsers, int numberOfItems){
    for (int i = 1;i <= numberOfUsers;i++){
        float avgRatingOfUser = getAvgRatingOfUser(matrix, i, numberOfItems);
            for (int j = 1;j <= numberOfItems;j++){
                if (matrix[i][j] != 0) avgMatrix[i][j] = matrix[i][j] - avgRatingOfUser;
                else avgMatrix[i][j] = 0;
            }
    }
    for (int i = 1;i <= numberOfUsers;i++){
        for (int j = 1;j <= numberOfUsers;j++){
            simMatrixPearson[i][j] = getSimilarityPearson(matrix, avgMatrix, i, j, numberOfItems);
            simMatrixCosine[i][j] = getSimilarityCosine(matrix, i, j, numberOfItems);
        }
    }
    for (int i = 1;i <= numberOfUsers;i++){
        float avgRating = getAvgRatingOfUser(matrix,i,numberOfItems);
        getNeighbor(simMatrixPearson, numberOfUsers, i, k, arrPearson);
        for (int j = 1;j <= numberOfItems;j++){ 
           if (matrix[i][j] == 0) {
              resultMatrixPearson[i][j] = avgRating + getRating(matrix, simMatrixPearson, avgMatrix, numberOfUsers, numberOfItems, k, arrPearson, i, j);
            }else{
              resultMatrixPearson[i][j] = matrix[i][j];
            }
        }
    }
    for (int i = 1;i <= numberOfUsers;i++){
        getNeighbor(simMatrixCosine, numberOfUsers, i, k, arrCosine);
        for (int j = 1;j <= numberOfItems;j++){ 
            if (matrix[i][j] == 0) {
                resultMatrixCosine[i][j] = getRating(matrix, simMatrixCosine, matrix, numberOfUsers, numberOfItems, k, arrCosine, i, j);
            }else{
                resultMatrixCosine[i][j] = matrix[i][j];
            }
        }
    }
}