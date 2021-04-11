float similarity(float matrix[50][50],float avgMatrix[50][50],int user1,int user2,int numberOfItems){
  float tuSo = 0;
  float sumOfUser1 = 0;
  float sumOfUser2 = 0;
  for (int i = 1;i <= numberOfItems;i++){
    if (avgMatrix[user1][i] * avgMatrix[user2][i] != 0){
      tuSo += avgMatrix[user1][i]*avgMatrix[user2][i];
      sumOfUser1 += pow(avgMatrix[user1][i], 2);
      sumOfUser2 += pow(avgMatrix[user2][i], 2);
    }
  }
  return (tuSo/(sqrt(sumOfUser1)*sqrt(sumOfUser2)));
}