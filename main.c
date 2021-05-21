#include "key_generator.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
#include "des.h"

unsigned long long int intToBinary(unsigned long long int k) {
    if (k == 0) return 0;
    if (k == 1) return 1;
    return (k % 2) + 10 * intToBinary(k / 2);
}

unsigned int intToBinaryChar(char charKey[65], unsigned long long int k) {
    k = intToBinary(k);
    sprintf(charKey, "%lld", k);
    return 0;
}

void keyToHexa(char* key, char* result){
  int k;
  int value=0;
  for(k=0;k<61;k=k+4){
    //calcula de quatro em quatro bits o valor correspondente
    value = pow(2,3)*(key[k]-48) + pow(2,2)*(key[k+1]-48) + pow(2,1)*(key[k+2]-48) + pow(2,0)*(key[k+3]-48);

    sprintf(&result[k/4],"%X",value);
    value=0;
  }
  result[17] = '\0';

}

int main(int argc, char **argv){
  char *plainText, *cipherText, *a;
	int keySize, zeroKey = 0, size = 1, myRank, finish = 0, flag = 0;
  unsigned long long int myKey;
  unsigned int thereIsNextKey = 1;
  struct timeval start, end, deltatime;
  char result[65], charKey[65], possibleKey[65], key[17];

  plainText = argv[1];
	cipherText = argv[2];
	a = argv[3];

  keySize = atoi(a);
	
	gettimeofday(&start, NULL);

	// MPI_Init(&argc, &argv);
	// MPI_Comm_size(MPI_COMM_WORLD, &size);
	// MPI_Comm_rank(MPI_COMM_WORLD, &myRank);

	// -************************* TIRAR ESSE FOR ********************
	for (myRank = 0; myRank < size; myRank++) {
		myKey = zeroKey + (int)(pow(2, keySize)/size) * myRank;
    printf("meu rank: %d\n", myRank);
    
		while (myKey < (int)(pow(2,keySize)/size) * (myRank+1)){
      
      intToBinaryChar(charKey, myKey);
      getKey(charKey, possibleKey);
      encryptDES(plainText, possibleKey, result);

      if (!strcmp(result, cipherText)){
        keyToHexa(possibleKey, key);
        printf("encontrou a chave: %s\n", key);
        break;
      }
      
      
      // //Caso em que encontrou a cifra
      // if (!strcmp(result, cypherText)){
        // thereIsNextKey = 0;
        // finish = 1;
        // for(i=0; i<npes; i++)
				// MPI_Send(&finish, 1, MPI_INT, i, 1, MPI_COMM_WORLD);

        
      // }
    
			myKey++;
		}
	}

  gettimeofday(&end, NULL);

  printf("levou %ld segundos para concluir\n", ((end.tv_sec) -
    (start.tv_sec)));
    
    
  return 0;
}