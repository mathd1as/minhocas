#include <bits/stdc++.h>
using namespace std;
#define N 100
 
// Namero de linhas e colunas
int n, m;
 
// Declarando o tamanho maximo da matriz
int a[N][N];
 
vector<vector<int> > dp(N, vector<int>(N)),
    visited(N, vector<int>(N));
 
// Guarda o valor da soma corrente
int current_sum = 0;
 
//Guarda o valor da soma total
int total_sum = 0;
 
// Funcao que realiza o input dos dados
void inputMatrix() {
	cout << "Entre com a quantidade de linhas" << endl;
    cin >> n;
    
    cout << "Entre com a quantidade de colunas" << endl;
    cin >> m;
    
    cout << "Entre com o valores da matriz" << endl;
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];	   
		}
	}
	
	cout << endl;
	cout << "Matriz";
    for(int i = 0; i < n; i++){
    	cout << endl;
        for(int j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }   
    }
    cout << endl;
    cout << endl;
}
 
// Funcao que calcula a soma dos caminhos
int maximum_sum_path(int i, int j) {
    // Verifica se esta no range
    if (i == n - 1 && j == m - 1)
        return a[i][j];
 
    // Verificando se a celula ja foi visitada
    if (visited[i][j])
        return dp[i][j];
 
    // Marcando acelula como visitada
    visited[i][j] = 1;
 
    // Atualizando o valor maximo da soma
    int& total_sum = dp[i][j];
 
    /*
	Verifica se a posicao
	nao visitou a ultima linha ou a ultima coluna.
	Fazendo chamadas recursivas para todos os
	movimentos possiveis da colula atual e em seguida, adicionando
	o valor maximo retornado pelas chamadas e atualizando-o.
	*/
     if (i < n - 1 & j < m - 1) {
     	cout << a[i][j] << " ";
        
        int current_sum = max(maximum_sum_path(i, j + 1),
			maximum_sum_path(i + 1, j));
		total_sum = a[i][j] + current_sum;
    }
 
    // Verificando se
    // a posicao foi alcancada na ultima coluna
    else if (i == n - 1)
        total_sum = a[i][j]
                    + maximum_sum_path(i, j + 1);
 
    else
        total_sum = a[i][j]
                    + maximum_sum_path(i + 1, j);
 
    return total_sum;
}
 
int main() {
    
    inputMatrix();
 
    cout << "Caminho do percorrido: ";
    
    int maximum_sum = maximum_sum_path(0, 0);
    
    cout << endl;
    cout << "Minhocas coletadas: ";
    cout << maximum_sum;
    cout << endl;
    
    return 0;
}