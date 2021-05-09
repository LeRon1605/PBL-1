#include<stdio.h>
#include<math.h>
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
int main(){
	float matrix[50][50] = {{}, {3,0 ,5 3}, {3 , 5, 3, 5}};
	printf("%f",getSimilarityCosine(matrix,1,2,4));
	printf("%f",pow(-1,2));
	return 0;
}