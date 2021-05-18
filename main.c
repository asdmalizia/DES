#include "key_generator.h"
#include <stdio.h>
#include <stdlib.h>
// #include <mpi.h>
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
    // printf("k do int to binary char %ld\n", k);
    sprintf(charKey, "%lld", k);
    return 0;
}

// char *decimal_to_binary(char p[65], int n)
// {
//   int c, d, t;

//   t = 0;

//   // if (p == NULL)
//   //   exit(EXIT_FAILURE);

//   for (c = 31 ; c >= 0 ; c--)
//   {
//     d = n >> c;

//     if (d & 1)
//       *(p+t) = 1 + '0';
//     else
//       *(p+t) = 0 + '0';

//     t++;
//   }
//   *(p+t) = '\0';

//   return  p;
// }


int main(int argc, char **argv){
  char *plainText, *cipherText, *a, *key;
	int keySize, zeroKey = 0, size = 4, myRank, finish = 0, flag = 0;
  unsigned long long int myKey;
  unsigned int thereIsNextKey = 1;
  struct timeval start, end, deltatime;
  char result[65], charKey[65], possibleKey[65];

  //verificar o que essa flag faz.long long long long 
  //mudar size para não receber atribuição

  plainText = argv[1];
	cipherText = argv[2];
	a = argv[3];

  keySize = atoi(a);
	// key = (char*)malloc((keySize+1)*sizeof(char));
	
	printf("Buscando a senha que encripta %s em %s\n", plainText, cipherText);
	// gettimeofday(&start, NULL);

	// MPI_Init(&argc, &argv);
	// MPI_Comm_size(MPI_COMM_WORLD, &size);
	// MPI_Comm_rank(MPI_COMM_WORLD, &myRank);

	// -************************* TIRAR ESSE FOR ********************
	for (myRank = 0; myRank < size; myRank++) {
		printf("My Rank: %d\n", myRank);
		myKey = zeroKey + (int)(pow(2, keySize)/size) * myRank;
    
		while (myKey < (int)(pow(2,keySize)/size) * (myRank+1)){
      
      intToBinaryChar(charKey, myKey);

      // printf("mykey = %ld\n", myKey);
      // printf("charkey = %s\n", charKey);
      getKey(charKey, possibleKey);
      // printf("possibleKey: %s\n", possibleKey);
      encryptDES(plainText, possibleKey, result);
      // printf("valor do result na main: %s\n", result);
      // printf("valor da cifra certa: %s", cipherText);

      if (!strcmp(result, cipherText)){
        printf("encontrou a chave: %s\n", possibleKey);
      }
      
      
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