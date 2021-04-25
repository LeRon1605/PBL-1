#include<stdio.h>
#include<conio.h>
int main()
{ 
	int option;
	do {
			printf("============================================================\n");
			printf("==                                                        ==\n");
			printf("==            DO AN: LAP TRINH TINH TOAN                  ==\n");
			printf("==         DE TAI: DU DOAN DIEM DANH GIA NGUOI DUNG       ==\n");
			printf("==                                                        ==\n");
			printf("============================================================\n");
			printf("==========================MENU==============================\n");
			printf("==   1. DOC DU LIEU TU FILE                               ==\n");
			printf("==   2. NHAP INPUT                                        ==\n");
			printf("==   3. HIEN THI INPUT                                    ==\n");
			printf("==   4. HIEN THI MA TRAN TUONG DUONG                      ==\n");
			printf("==   5. HIEN THI HANG XOM                                 ==\n");
			printf("==   6. GHI MA TRAN KET QUA RA FILE                       ==\n");
			printf("==   7. IN KET QUA RA MAN HINH                            ==\n");
			printf("==   8. KET THUC CHUONG TRINH                             ==\n");
			printf("============================================================\n");
			
			printf("NHAP CHON:\n");
			scanf("%d", &option);
			switch(option)
			{
			case 1:  
				printf("DOC DU LIEU TU FILE \n");

				break;
			case 2: 
			    printf("NHAP INPUT \n");
				break;
			case 3: 
			    printf("HIEN THI INPUT \n");
				break;
			case 4: 
			    printf("HIEN THI MA TRAN TUONG DUONG \n");
				break;
			case 5: 
			    printf("HIEN THI HANG XOM \n");
				break;
			case 6: 
			    printf("GHI MA TRAN RA MAN HINH \n");
				break;
			case 7: 
			    printf("IN KET QUA RA MAN HINH \n");
				break;
			case 8: 
			    printf("KET THUC CHUONG TRINH \n");
				break;
			default:
			    printf("NHAP SAI!!! MOI CHON LAI MENU.\n");
			}
    }while (option != 8) ;
 return 0;
}
