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

unsigned intToBinaryChar(char charKey[65], unsigned int k) {
    k = intToBinary(k);
    sprintf(charKey, "%d", k);
    return 0;
}

// int main(){
//   char ans[65];
//   encryptDES("CAMINHOS", "100000001000000010000000100000001000001111101010110010100", ans);

//   // printf("resposta: %s", ans);
//   return 0;
// }

int main(int argc, char **argv){
  char *plainText, *cypherText, *a, *key;
	int keySize, zeroKey = 0, size = 4, myRank, finish = 0, flag = 0;
	unsigned int myKey, thereIsNextKey = 1;
  struct timeval start, end, deltatime;
  // char *charKey, *possibleKey;
  char result[65], harKey[65], possibleKey[65];

  //verificar o que essa flag faz.
  //mudar size para não receber atribuição

  plainText = argv[1];
	cypherText = argv[2];
	a = argv[3];

  keySize = atoi(a);
	// key = (char*)malloc((keySize+1)*sizeof(char));
	
	printf("Buscando a senha que encripta %s em %s\n", plainText, cypherText);
	// gettimeofday(&start, NULL);

	// MPI_Init(&argc, &argv);
	// MPI_Comm_size(MPI_COMM_WORLD, &size);
	// MPI_Comm_rank(MPI_COMM_WORLD, &myRank);

	// -************************* TIRAR ESSE FOR ********************
	for (myRank = 0; myRank < size; myRank++) {
		printf("My Rank: %d\n", myRank);
		myKey = zeroKey + (int)(pow(2, keySize)/size) * myRank;
    
		while (myKey < (int)(pow(2,keySize)/size) * (myRank+1)){
      // charKey = (char *) malloc(65*sizeof(char));
      intToBinaryChar(charKey, myKey);

      // possibleKey = (char*)malloc(65*sizeof(char));
      // result = (char *)malloc(65*sizeof(char));
      // printf("%s",typeof(charKey));
      getKey(charKey, possibleKey);
      printf("possibleKey: %s\n", possibleKey);
      encryptDES(plainText, possibleKey, result);
      // printf("result: %s\n", result);
      
      // //Caso em que encontrou a cifra
      // if (!strcmp(result, cypherText)){
        // thereIsNextKey = 0;
        // finish = 1;
        // for(i=0; i<npes; i++)
				// MPI_Send(&finish, 1, MPI_INT, i, 1, MPI_COMM_WORLD);

        
      // }
      // free(charKey);
      // free(possibleKey);
    
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
  return 0;
}