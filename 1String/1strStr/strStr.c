#include <stdio.h>
#include <string.h>
#include <malloc.h>

int strStryj(char *source, char *target){
	if(source == NULL || target == NULL){
		return -1;
	}
	int	slen = strlen(source);	
	int	tlen = strlen(target);
	for(int i = 0; i < (slen - tlen + 1); i++){
		int j = 0;
		for(; j < tlen; j++){
			if(source[i+j] != target[j]){
					break;
				}
		}
		if(j == tlen){
			return i;
		}
	}
	return -1;
}

int main(){
	char *s;
	char *t;
	s = (char *)malloc(100);
	t = (char *)malloc(100);

	printf("Please give source string:");
	scanf("%s", s);
	printf("Please give target string:");
	scanf("%s", t);
	int z = strStryj(s, t);
	printf("%d", z);
	free(s);
	free(t);
	return 0;
}
