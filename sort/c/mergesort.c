#include <stdio.h>

int merge(int startIndex, int endIndex, int midIndex, int listIn[]){
	int templist[30];
	int i = startIndex, j = midIndex+1, k = startIndex; //k is index of templist
	
	while(i <= midIndex && j <= endIndex){
		if(listIn[i] < listIn[j]){
			templist[k++] = listIn[i++];
		}else{
			templist[k++] = listIn[j++];
		}
	}
	while(i <= midIndex){
		templist[k++] = listIn[i++];
	}
	while(j <= endIndex){
		templist[k++] = listIn[j++];
	}
	
	for(int z = startIndex; z <= endIndex; z++){
		listIn[z] = templist[z];
		printf("%4d", listIn[z]);
	}
	printf("\n");
}

int mergesort(int low, int high, int list[]){
	int mid;
	if(low < high){
		mid = (low+high)/2;
		mergesort(low, mid, list);
		mergesort(mid+1, high, list);
		merge(low, high, mid, list);
	}
}


int main(){
//	int arr[] = {3,5,7,4,8,2,9,1,6};
	int arr[] = {84,535,7,53,24,8,62,35,899,523,25};
	int arrlen = sizeof(arr)/sizeof(arr[0]);
	printf("len = %d\n", arrlen);
	mergesort(0, arrlen-1, arr);
	
	for(int x; x< arrlen; x++){
		printf("%4d", arr[x]);
	}
	printf("\n");
	return 0;
}



