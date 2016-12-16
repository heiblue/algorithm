#include <stdio.h>
#include <string.h>


int list[] = {3,4,1,6,9,2,7,8,5};

int quicksort(int low, int high){
	if(low < high){
		int mark = list[low];
		int i = low, j = high;
		while(i < j){
			while(i < j && list[j] >= mark){
				j--;
			}
			if(i < j){
				list[i++] = list[j];
			}
			while(i < j && list[i] <= mark){
				i++;
			}
			if(i < j){
				list[j--] = list[i];
			}
		}
		list[i] = mark;

		quicksort(low, i-1);
		quicksort(i+1, high);				
	}
}


int main(){
	quicksort(0, 8);
	
	for(int x = 0; x <=8; x++){
		printf("%d", list[x]);
	}

	return 0;
}
