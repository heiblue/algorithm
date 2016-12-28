#include <stdio.h>
#include <math.h>

void printHeap();

void heapAjust(int list[], int i, int listLen){	//i is the subroot index to be ajusted
	int nodeL, nodeR;							//left node and right node of subroot
	int max, temp;									//max is the index of the largest number(root or nodeL or nodeR)
	
	for( ; 2*i+1 < listLen; i = max){
		temp = list[i];
		nodeL = 2*i+1;
		nodeR = 2*i+2;
		if(nodeR < listLen){
			max = nodeR;
			if(list[nodeL] > list[nodeR]){
				max = nodeL;
			}		
		}else{
			max = nodeL;
		}
		if(list[i] >= list[max]){
			break;
		}
		
		list[i] = list[max];
		list[max] = temp;
	}
//	printHeap(list, listLen);

}

void printHeap(int list[], int listLen){	//to Print array in heap graphic
	int n = 0, sum = 0;	
	while(sum < listLen){
		sum += pow(2, n);
		n++;
	}										//this is to get the line of heap based on the arrya length
	int rulurN = 2*pow(2, n-1);				//this is the rulur of each line
	
	int line = 0;
	int elementN, halfLine, i = 0, j;		//elementN is element number of each line, halfLine is the position of the number
	while(line < n){
		elementN = pow(2, line);
		halfLine = rulurN/(2*elementN);
		while(elementN > 0 && i < listLen){
			for(j = 0; j < halfLine-1; j++ ){
				printf("   ");
			}
			printf("%03d", list[i++]);
			for(j = 0; j < halfLine; j++ ){
				printf("   ");
			}
			elementN--;
		}
		printf("\n\n");
		line ++;
	}
}

void heapSort(int list[], int listLen){
	int temp;							//temp is for swap the first and the last
	for(int i = listLen-1; i > 0; i--){
		temp = list[i];
		list[i] = list[0];
		list[0] = temp;	
		
		heapAjust(list, 0, i);
	}
}



int main(){
//	int list[] = {5,4,65,3,54,6,5,3,1,7,645,67};
	int list[] = {43,6,4,356,567,4,34,45,7,34,3,264,765,76,8,56,53,4,26,57,63,453,455,4,25};
	int listLen = sizeof(list)/sizeof(list[0]);	
	printf("\nOriginal Array is:\n");
	printHeap(list, listLen);
	printf("\n");	
//	heapAjust(list, listLen/2-1, listLen);
	printf("\nAjust heap first time to:\n");
	for(int i = listLen/2-1; i >= 0; i--){ //Ajust the heap to dadingdui, i is the subroot to be ajusted
		heapAjust(list, i, listLen);
	}
	printHeap(list, listLen);
	printf("\n");
	heapSort(list, listLen);
	printf("\nSorted Array is:\n");
	printHeap(list, listLen);
	
	return 0;
}
