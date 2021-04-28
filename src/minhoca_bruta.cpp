#include <bits/stdc++.h> 
#include <time.h>
using namespace std; 
 
double maximum_sum_path(vector<vector<int> > matrix, int n, int m) { 
	int dp[n][m]; 
	dp[0][0] = matrix[0][0]; 

	/* Inicializa primeira linha do array */
	for (int j = 1; j < m; j++) 
		dp[0][j] = dp[0][j-1] + matrix[0][j]; 

	/* Inicializa a primeira coluna da matriz dp que calcula o custo total*/
	for (int i = 1; i < n; i++) 
		dp[i][0] = dp[i-1][0] + matrix[i][0]; 
       
    /* Construir o resto da matriz dp */
	for (int i = 1; i < n; i++){
		for (int j = 1; j < m; j++){
			int a = max(dp[i-1][j], dp[i][j-1]);
			dp[i][j] = matrix[i][j] + max(dp[i-1][j], dp[i][j-1]); 	
		}	
	}
	 
    double g = (double)dp[n-1][m-1];
	return g; 
} 

int main() {     
	int n, m;
	
   	cout << "Entre com a quantidade de linhas" << endl;
    cin >> n;
    
    cout << "Entre com a quantidade de colunas" << endl;
    cin >> m;
    
    vector<vector<int> > matrix(n);
  	for ( int i = 0 ; i < n ; i++ ) {
		matrix[i].resize(m);		
	}
    
    cout << "Entre com o valores da matriz" << endl;
	for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }   
    }
    
    cout << endl;
    cout << "Matriz";
    for(int i = 0; i < n; i++){
    	cout << endl;
        for(int j = 0; j < m; j++){
            cout << matrix[i][j] << " ";
        }   
    }
    cout << endl;
    cout << endl;	
		
    int b = maximum_sum_path(matrix, n, m);
    
    cout << "Minhocas coletadas: ";
	cout << b << endl;
	cout << endl;
	
	return 0; 
}  	