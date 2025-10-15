
//function below
    int m = matrix.size();
    int n = m;
for(int i=0; i<m; i++){
  for(int j=i; j<n; j++){
    swap(matrix[i][j], matrix[j][i]);
  }
}

for(int i=0; i<m; i++){
  reverse(matrix[i].begin(), matrix[i].end()}
}
