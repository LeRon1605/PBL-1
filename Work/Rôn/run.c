void run(float matrix[50][50],float avgMatrix[50][50], float simMatrixPearson[50][50], float simMatrixCosine[50][50],float resultMatrixCosine[50][50], float resultMatrixPearson[50][50],int arr[], int k, int numberOfUsers, int numberOfItems){
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
        getNeighbor(simMatrixPearson, numberOfUsers, i, k, arr);
        for (int j = 1;j <= numberOfItems;j++){ 
           if (matrix[i][j] == 0) {
                resultMatrixPearson[i][j] = avgRating + getRating(matrix, simMatrixPearson, avgMatrix, numberOfUsers, numberOfItems, k, arr, i, j);
            }else{
                resultMatrixPearson[i][j] = matrix[i][j];
            }
        }
    }
    for (int i = 1;i <= numberOfUsers;i++){
        float avgRating = getAvgRatingOfUser(matrix,i,numberOfItems);
        getNeighbor(simMatrixCosine, numberOfUsers, i, k, arr);
        for (int j = 1;j <= numberOfItems;j++){ 
            if (matrix[i][j] == 0) {
                resultMatrixCosine[i][j] = avgRating + getRating(matrix, simMatrixCosine, avgMatrix, numberOfUsers, numberOfItems, k, arr, i, j);
            }else{
                resultMatrixCosine[i][j] = matrix[i][j];
            }
        }
    }
}