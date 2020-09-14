#include <iostream>
#include <cmath>

#define MAX_SIZE 2

int binary_search( int v[], int first, int last, int x);

int minimum_local_in_array(int v[], int first, int last);

int minimum_local_in_matrix(int v[][2], int first, int last);

int bitonic_search(int v[], int first, int last);

int binary_search_duplicates(int v[], int first, int last, int x);

int *floor_ceiling(int v[], int first, int last, int x, int arr[]);

int identity(int v[], int first, int last);

int search_sorted_rotated(int v[], int first, int last, int x);

int main(){

//	int v[]{2,3,4,10,40,41,45,49,59,69,70,71};
//	int v[]{2,3,4,10,40,41,45,49,59,69,70,71};
//	int v[]{8,7,6,5,4,3,2};
	int v[]{2};
	int x{2};
	int n{sizeof(v)/sizeof(v[0])};
	int result = binary_search(v, 0, n-1, x);
	(result == -1) ? std::cout <<"element is not present in array" << std::endl
			:std::cout <<"find in v[" << result << "]: " << v[result] << std::endl;

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
	
	int v_5[]{4,9,11};
	int key_5{6};
	int size_5{sizeof(v_5)/sizeof(v_5[0])};
	int n_5[]{0,0};
	floor_ceiling(v_5, 0, size_5 - 1, key_5, n_5);
	(n_5[0] == -1)?	std::cout << "dont find the floor" << std::endl:
			std::cout << "the floor is: " << n_5[0] << std::endl;
	(n_5[1] == -1)?	std::cout << "dont find the ceiling" << std::endl:
			std::cout << "the ceiling is: " << n_5[1] << std::endl;

//	int v_6[]{0,2,3,4,5,6,7};
	int v_6[]{0,1};
//		  00 01 02 03 04 05 06
	int size_6{sizeof(v_6)/sizeof(v_6[0])};
	int n_6 = identity(v_6, 0, size_6 - 1);
	(n_6 == -1) ?	std::cout << "dont find identity" << std::endl:
			std::cout << "the identity is v[" << n_6 << "]:" << v_6[n_6] << std::endl;
	
//	int v_7[]{10,12,15,36,40,1,7,9};
//	int v_7[]{21,34,35,37,40,14,15,16,20};
	int v_7[]{4,5,6};
	int key_7{6};
	int size_7{sizeof(v_7)/sizeof(v_7[0])};
	int n_7 = search_sorted_rotated(v_7, 0, size_7 - 1, key_7);
	(n_7 == -1) ?	std::cout << "dont the key in sorted rotated array" << std::endl:
			std::cout << "find value in v[" << n_7 << "]:" << v_7[n_7] << std::endl;

	return 0;
}

int search_sorted_rotated(int v[], int first, int last, int x){

	if(first == last){
		return 0;
	}
	while(first <= last){
		int middle = (first + last) / 2;

		if((last - first) == 1){
			std::cout << first << " first|last " << last << std::endl;
			return binary_search(v, first, last, x);
/*			if(v[first] < v[last]){
				std::cout << "teste_1\n";
				return binary_search(v, first, last, x);
//				return last;
			}else if(v[first] > v[last]){
				std::cout << "teste_2\n";
				return binary_search(v, first, last, x);
//				return first;
			}*/
		}

		if(v[middle - 1] < v[middle] && v[middle + 1] < v[middle]){
//			return binary_search(middle;
			if(x < v[0]){
				std::cout << "x<v[0]\n";
				return binary_search(v, middle, last, x);
			}else if(x > v[0]){
				std::cout << "x>v[0]\n";
				return binary_search(v, first, middle, x);

			}/*else{
				return 0;
			}*/
			/*else if(x > v[middle]){
				binary_search(v, 
			}*/
		}else if(v[middle] < v[first]){
			last = middle;
		}else if(v[middle] > v[first]){
			first = middle;
		}
		/*if(middle < v[0]){
			first = middle;
		}else if(middle > v[0]){
			first = middle;
		}*/
	}
	return -1;
}

int identity(int v[], int first, int last){
	while(first <= last){
		int middle = (first + last) / 2;

		if(middle < v[middle]){
			last = middle - 1;
		}else if(middle > v[middle]){
			first = middle + 1;
		}else{
			return middle;
		}
	}
	return -1;
}

int *floor_ceiling(int v[], int first, int last, int x, int arr[]){
	arr[0] = -1;
	arr[1] = -1;
	if(first == last){
		if(v[first] < x){
			arr[0] = v[first];
		}else if(v[first] > x){
			arr[1] = v[first];
		}else{
			arr[0] = v[first];
			arr[1] = v[first];
		}
		return arr;
	}
	while(first <= last){
		int middle = (first + last) / 2;

		if((last - first) == 1){
			if(v[first] <= x && x <= v[last]){
				arr[0] = v[first];
				arr[1] = v[last];
			}else if(v[first] < x && v[last] < x){
				arr[0] = v[last];
			}else if(v[first] > x && v[first] < v[last]){
				arr[1] = v[first];
			}
			return arr;
		}
		if(x < v[middle]){
			last = middle;
		}else if(x > v[middle]){
			first = middle;
		}else{
			if(x >= v[middle - 1] && x <= v[middle + 1]){
				arr[0] = v[middle - 1];
				arr[1] = v[middle + 1];
				return arr;
			}
		}

	}
	return arr;
}


int binary_search_duplicates(int v[], int first, int last, int x){
	while(first <= last){
		int middle = (first + last) / 2;
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
