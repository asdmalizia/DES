#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void extendWord(char* word, char* ret){
	char* temp;
	temp = malloc((56*+1)*sizeof(char));
	for (int i = 0; i < 56 - strlen(word); i++){
		temp[i] = '0';
	}
	strcat(temp, word);
	strcpy(ret, temp);
	free(temp);
}

void generateKey(char* word, char* key){
	char byte[9];
	char* temp;
	temp = malloc((64+1)*sizeof(char));
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 7; j++){
			byte[j] = word[i*7+j];
		}
		int count1 = 0;
		for (int k = 0; k < 7; k++){
			if (byte[k] == '1'){
				count1++;
			}
		}
		if (count1 % 2 == 0){
			byte[7] = '1';
		} else {
			byte[7] = '0';
		}
		printf("byte: %s\n", byte);
		strcat(temp, byte);				
	}
	strcpy(key, temp);
	free(temp);
}

int getKey (char *word, char* key){
	// char *word = "1111110101010100"; //FD54
	char *extendedWord;
	// char* key;
	// key = malloc((64+1) * sizeof(char));
	extendedWord = malloc((56+1) * sizeof(char));
	extendWord(word, extendedWord);
	// printf("%s\n", extendedWord);
	// printf("%ld\n", strlen(extendedWord));
	generateKey(extendedWord, key);
	free(extendedWord);
	// printf("%s\n", key);
	// free(key);
  // strcpy();
	return 0;
}