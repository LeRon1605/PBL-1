void xuat_matran(float matrix[50][50],int numberOfUsers,int numberOfItems){
	for(int i = 1; i <= numberOfUsers, i++) {
		for ( int j = 0; j <= numberOfItems; j++) printf("%f\t",&matrix[i][j]);
		printf("\n");
	}	
}	