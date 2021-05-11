#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	srand(0);
	for (int i = 0;i < 9;i++){
		for (int j = 0;j < 9;j++) printf("%d ",0 + rand() % (5 + 1 - 0));
		printf("\n");
	}
	return 0;
}