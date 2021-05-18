#include "key_generator.h"
#include <stdio.h>
#include <stdlib.h>
// #include <mpi.h>
#include <sys/time.h>
#include <math.h>
#include "des.h"

unsigned intToBinary(unsigned int k) {
    if (k == 0) return 0;
    if (k == 1) return 1;
    return (k % 2) + 10 * intToBinary(k / 2);
}

unsigned intToBinaryChar(char *charKey, unsigned int k) {
    k = intToBinary(k);
    sprintf(charKey, "%d", k);
    return 0;
}

int main(int argc, char **argv){
  char *plainText, *cypherText, *a, *key;
	int keySize, zeroKey = 0, size = 4, myRank, finish = 0, flag = 0;
	unsigned int myKey, thereIsNextKey = 1;
  struct timeval start, end, deltatime;

  //verificar o que essa flag faz.
  //mudar size para não receber atribuição

  plainText = argv[1];
	cypherText = argv[2];
	a = argv[3];

  keySize = atoi(a);
	key = (char*)malloc((keySize+1)*sizeof(char));

  printf("%d\n", keySize);

	
	printf("Buscando a senha que encripta %s em %s\n", plainText, cypherText);
	// gettimeofday(&start, NULL);

	// MPI_Init(&argc, &argv);
	// MPI_Comm_size(MPI_COMM_WORLD, &size);
	// MPI_Comm_rank(MPI_COMM_WORLD, &myRank);

	// -************************* TIRAR ESSE FOR ********************
	for (myRank = 0; myRank < size; myRank++) {
		// printf("My Rank: %d\n", myRank);
		// myKey = zeroKey + (int)(pow(2, keySize)/size) * myRank;
    
		while (myKey < (int)(pow(2,keySize)/size) * (myRank+1)){
      char *charKey;
      charKey = malloc(65*sizeof(char));
      intToBinaryChar(charKey, myKey);
      char *possibleKey;
      possibleKey = malloc(65*sizeof(char));
      char *result;
      result = (char *)malloc(65*sizeof(char));
      // printf("%s",typeof(charKey));
      getKey(charKey, possibleKey);
      encryptDES(plainText, possibleKey, result);
      printf("result: %s\n", result);
      
      //Caso em que encontrou a cifra
      // if (!strcmp(result, cypherText)){
        // thereIsNextKey = 0;
        // finish = 1;
        // for(i=0; i<npes; i++)
				// MPI_Send(&finish, 1, MPI_INT, i, 1, MPI_COMM_WORLD);

        
      // }
    
			myKey++;
		}
		// printf("chave: %d\n", ++myKey);

		// do {

		// } while(thereIsNextKey)
	}

//   gettimeofday(&end, NULL);
//deltatime = end - start;
//  printf("senconds: %ld\nmicro seconds : %ld", deltatime.tv_sec, deltatime.tv_usec);


	// char *key = malloc((64+1)*sizeof(char));
	// getKey(plainText, key);
	// printf("plainText: %s\n", plainText);
	// printf("key: %s\n", key);
	// free(key);
  return 0;
}