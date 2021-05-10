#include<stdio.h>
#include<string.h>
#include<conio.h>
int main()
{ 
	int optionMenu;
	int isInput = 0;
	do{
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
							isInput = 1;
							printf("******************************************************************************\n");
							printf("*                                                                            *\n");
							printf("*                        NHAP INPUT TU BAN PHIM                              *\n");
							printf("*                                                                            *\n");
							printf("******************************************************************************\n\n\n");
							inputMatrixFromKeyBoard(matrix,numberOfUsers,numberOfItems);
							break;
						case 2:
							isInput = 1;
							printf("******************************************************************************\n");
							printf("*                                                                            *\n");
							printf("*                             DOC INPUT TU FILE                              *\n");
							printf("*                                                                            *\n");
							printf("******************************************************************************\n\n\n");
							char fileName[30];
							printf("Nhap ten file: ");
							gets(fileName);
							inputMatrix(fileName, matrix, numberOfUsers, numberOfItems);
							break;
					}
				}while(inputOption != 3);
				break;
			case 2:
				if (isInput == 0) break;
				int outputOption;
				do {
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
				}while(outputOption != 5);

		}
	}while(optionMenu != 3);
 return 0;
}
