float Avgmatrix(float matrix[50][50], int numberOfUsers, int numberOfItems){
	int count=0;
	float sum=0;
	int i=numberOfUsers;
	for (int j = 0; j <= numberOfItems; j++){
			if (matrix[i][j] != 0) {
				count++;
				sum += matrix[i][j];
		}
	}
	return sum/count;
}	
