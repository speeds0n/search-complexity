#include <iostream>
#include <cmath>

#define MAX_SIZE 2

int binary_search( int v[], int first, int last, int x);

int minimum_local_in_array(int v[], int first, int last);

int minimum_local_in_matrix(int v[][2], int first, int last);

int bitonic_search(int v[], int first, int last);

int binary_search_duplicates(int v[], int first, int last, int x);

int main(){

//	int v[]{2,3,4,10,40,41,45,49,59,69,70,71};
//	int v[]{2,3,4,10,40,41,45,49,59,69,70,71};
	int v[]{8,7,6,5,4,3,2};
	int x{3};
	int n{sizeof(v)/sizeof(v[0])};
	int result = binary_search(v, 0, n-1, x);
	(result == -1) ? std::cout <<"element is not present in array" << std::endl
			:std::cout <<"element is present at index: " << result << std::endl;

//	int v_1[]{3,5,7,4,6};
//	int v_1[]{15, 16,18,17};
	int v_1[]{1, 2};
	int size_1{sizeof(v_1)/sizeof(v_1[0])};
	int minimum_local = minimum_local_in_array(v_1, 0, size_1 - 1);
//	int minimun_local = m(v_1, 0, n_1-1);
	(minimum_local == -1) ? std::cout << "dont have minimum local" << std::endl:
				std::cout << "Minimum at : V[" << minimum_local <<"] and is: " << v_1[minimum_local] << std::endl;

/*	int v_2[][4] = {{17, 18, 13, 16},
		    	{15, 11, 14, 17},
		    	{20, 19, 25, 30},
			{31, 32, 33, 34}};*/
	int v_2[][2] = {{ 8, 9},
		        {10,11}};
	int n_2 = minimum_local_in_matrix(v_2, 0, 1);
	(n_2 == -1) ?	std::cout << "dont have minimum local" << std::endl:
			std::cout << "Minimum is: " << n_2 << std::endl;

	int v_3[]{6,7,8,9,10,11,5,4,3,2,1,0,-1};
	int size_3{sizeof(v_3)/sizeof(v_3[0])};
	int n_3 = bitonic_search(v_3, 0, size_3 - 1);
	(n_3 == -1) ?	std::cout << "dont have bitonic number" << std::endl:
			std::cout << "Bitonic number is: " << n_3 << std::endl;
	int v_4[]{4,5,6,8};
	int key_4{8};
	int size_4{sizeof(v_4)/sizeof(v_4[0])};
	int n_4 = binary_search_duplicates(v_4, 0, size_4 - 1, key_4);
	(n_4 == -1) ?	std::cout << "dont find the key" << std::endl:
			std::cout << "The key is: " << v_4[n_4] << " index: " << n_4 << std::endl;
	return 0;
}

int binary_search_duplicates(int v[], int first, int last, int x){
	while(first <= last){
		int middle = (first + last ) / 2;
		if( x < v[middle]){
			last = middle - 1;
		}else if(x > v[middle]){
		//	std::cout << first << " first|last " << last << std::endl;
			first = middle + 1;
		}else{/*x == v[middle]*/
			if(x == v[middle - 1]){
				int aux = binary_search(v, first, middle - 1, x);
				if(aux == -1){
					return middle;
				}else{
					return aux;
				}
			}else{
				return middle;
//				binary_search(v, first, last, x);
			}
		}
	}
	return -1;
}

int bitonic_search(int v[], int first, int last){

	while(first <= last){
		int middle = (first + last) / 2;

		if(last == first){
			return v[first];
		}
		if((last - first) == 1){
			if(v[first] > v[last]){ return v[first]; }
			else{/*v[first] < v[last]*/ return v[last];}
		}
		if(v[middle] > v[middle - 1] && v[middle] > v[middle + 1]){
			return v[middle];
		}else if(v[middle - 1] > v[middle + 1]){
			last = middle - 1;
		}else{//v[middle + 1] > v[middle - 1]
			first = middle + 1;
		}
	}
	return -1;
}

int minimum_local_in_matrix(int v[][2], int first, int last){
	
	int mid = (first + last) / 2;
	int a = minimum_local_in_array(v[mid], 0, 1);

	if(a == -1){
		return -1;
	}
	if(last == 0 && last == first){
		return 0;
	}
	while(first <= last){
		int middle = (first + last) / 2;
		if((last - first) == 1){
//			if(v[a][first] < v[a][last]){
			if(v[first][a] < v[last][a]){
//				std::cout << "v[a][f]:" << v[a][first] << std::endl;
//				return v[a][first];
//				std::cout << "v[a][f]:" << v[a][first] << std::endl;
				return v[first][a];
			}else{/**/
//				return v[a][last];
//				std::cout << "v[a][l]:" << v[a][last] << std::endl;
				return v[last][a];
			}
		}
//		if(v[a][middle] < v[a][middle - 1] && v[a][middle + 1]){
		if(v[middle][a] < v[middle - 1][a] && v[middle][a] < v[middle + 1][a]){
//			return v[a][middle];
			std::cout << "v[middle][a]: " << v[middle][a] << std::endl;
			return v[middle][a];
//		}else if(v[a][middle - 1] < v[a][middle + 1]){
		}else if(v[middle - 1][a] < v[middle + 1][a]){
			last = middle;
		}else{/*v[a][middle - 1] > v[a][middle + 1]*/
			first = middle;
		}
	}
	return -1;
}

int minimum_local_in_array(int v[], int first, int last){
//int m(int v[], int first, int last){

	/*Quando o array tem apenas 1 elemento não vazio, o proprio elemento do vetor é minimo local*/
	if(last == first){
		return 0;
	}
	while(first <= last){

		int middle = (first + last) / 2;
		/*Quando o array eh menor que 3,nao podemos verificar v[i-1]>v[i]<v[i+1] sem exeder os limites do array, 
		entao verificamos qual "borda" eh menor e a retornamos como o menor elemento*/
		if((last - first) == 1){
			if(v[first] < v[last]){ return first; }
			else{/*v[first] > v[last]*/ return last;}
		}

		if(v[middle] < v[middle - 1] && v[middle] < v[middle + 1]){
			return middle;
		}else if(v[middle - 1] < v[middle + 1]){
			last = middle;
		}else{//v[middle - 1] > v[middle + 1]
			first = middle;
		}
	}
	return -1;
}
int binary_search(int v[], int first, int last, int x){
	while(first <= last){
		int middle = (first + last) / 2;
		if( x < v[middle]){
			last = middle - 1;
		}else if(x > v[middle]){
			first = middle + 1;
		}else{
			return middle;
		}
	}
	return -1;
}
