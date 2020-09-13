#include <iostream>

int search(int mat[4][4], int n, int x){
	if(n == 0){
		return -1;
	}
	int smallest = mat[0][0];
	int largest = mat[n-1][n-1];

	if( x < smallest || x > largest){
		return -1;
	}

	int i = 0, j = n - 1;
	while(i < n && j >= 0){
		if(mat[i][j] == x){
			std::cout << "n found at " << i << ", " << j << std::endl;
			return 1;
		}
		if(mat[i][j] > x){
			j--;
		}else{
			i++;
		}
	}
	std::cout << "n element not found" << std::endl;
	return 0;
}

int main(){

	int mat[4][4] = { {10, 20, 30, 40},
			  {15, 25, 35, 45},
			  {27, 29, 37, 48},
			  {32, 33, 39, 50}};

	search(mat, 4, 29);

	return 0;
}
