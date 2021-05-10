float getAvgRating(float matrix[50][50],int user,int numberOfItems);{
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
