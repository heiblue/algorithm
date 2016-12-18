#include <stdio.h>
#include <math.h>

int maxnum(int list[]){
	int len = 0, i = 1;
//	int len = sizeof(list)/(sizeof(list[0]));
	while(list[i++] != '\0'){
		len++;
	}
	printf("array length is: %d\n", len);
	i = 0;
	int max = 0;
	for(i; i < len; i++){
		if(list[i] > max){
			max = list[i];
		}
	}
	printf("maxnum is: %d\n", max);
	return max;
}

int getweight(int number){					//count the weishu of the larget numer
	int count = 0;
	while(number != 0){
		number = number/10;
		count++;
	}
	return count;
}


int radixsort(int list[]){
	int loop = getweight(maxnum(list));
	printf("loop is: %d\n", loop);
//	int n = sizeof(list)/sizeof(list[0]);	//array length
	int n = 0, c = 1;
	while(list[c++] != '\0'){
		n++;
	}
	printf("array length is again: %d\n", n);
	int buck[10][20] = {};					//temporay put 20 here, will find other var solution later

	for(int i = 0; i < loop; i++){
		for(int j = 0; j < n; j++){
			int mark = (int)pow(10,i);
			int index = list[j]/mark%10;	//get the number of the weight as index
			for(int k = 0; k < n; k++){
				if(buck[index][k] == '\0'){
					buck[index][k] = list[j];
					break;
				}
			}
		}
		
		int z = 0;
		for(int a = 0; a < 10; a++){
			for(int b = 0; b < n; b++){
				if(buck[a][b] != '\0'){
					list[z] = buck[a][b];
					printf("%d, ", list[z]);
					buck[a][b] = '\0';
					z++;
				}
			}
		}
		
	}
	printf("\n");	
	for(int i = 0; i < n; i++){
		printf("%d, ", list[i]);
	}
	printf("\n");	
}


int main(){
	int array[] = {54,2,54,65,21,59,77,654,418,65};
	radixsort(array);
	
	return 0;
}
