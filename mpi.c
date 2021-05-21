// #include "key_generator.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <mpi.h>
// #include <sys/time.h>
// #include <math.h>
// #include "des.h"

// unsigned long long int intToBinary(unsigned long long int k) {
//     if (k == 0) return 0;
//     if (k == 1) return 1;
//     return (k % 2) + 10 * intToBinary(k / 2);
// }

// unsigned int intToBinaryChar(char charKey[65], unsigned long long int k) {
//     k = intToBinary(k);
//     sprintf(charKey, "%lld", k);
//     return 0;
// }

// int main(int argc, char **argv){
// 	char *plainText, *cipherText, *a, *key;
// 	int keySize, zeroKey = 0, size, myRank, finish = 0, flag = 0;
// 	unsigned long long int myKey;
// 	MPI_Request request;

// 	// unsigned int thereIsNextKey = 1;

// 	struct timeval start, end, deltatime;
// 	char result[65], charKey[65], possibleKey[65];

// 	//verificar o que essa flag faz.long long long long 
// 	//mudar size para não receber atribuição

// 	plainText = argv[1];
// 	cipherText = argv[2];
// 	a = argv[3];

// 	keySize = atoi(a);

// 	printf("Buscando a senha que encripta %s em %s\n", plainText, cipherText);
// 	gettimeofday(&start, NULL);

// 	MPI_Init(&argc, &argv);
// 	MPI_Comm_size(MPI_COMM_WORLD, &size);
// 	MPI_Comm_rank(MPI_COMM_WORLD, &myRank);

// 	// -************************* TIRAR ESSE FOR ********************
// 	// for (myRank = 0; myRank < size; myRank++) {
// 	// printf("My Rank: %d\n", myRank);
// 	myKey = zeroKey + (int)(pow(2, keySize)/size) * myRank;

// 	while (myKey < (int)(pow(2,keySize)/size) * (myRank+1)){

// 		intToBinaryChar(charKey, myKey);
// 		getKey(charKey, possibleKey);
// 		encryptDES(plainText, possibleKey, result);

// 		if (!strcmp(result, cipherText)){
// 			printf("O processo %d encontrou a chave: %s\n", myRank, possibleKey);
// 			finish = 1;
// 			for (int i= 0; i < size; i++){
// 				//Ver se o rank se auto bloqueia
// 				MPI_Send(&finish, 1, MPI_INT, i, 1, MPI_COMM_WORLD);
// 			}
// 		}

// 		MPI_Irecv(&finish, 1, MPI_INT, MPI_ANY_SOURCE, 1, MPI_COMM_WORLD, &request);
// 		if (finish){
// 			break;
// 		}


// 		// //Caso em que encontrou a cifra
// 		// if (!strcmp(result, cypherText)){
// 		// thereIsNextKey = 0;
// 		// finish = 1;
// 		// for(i=0; i<npes; i++)
// 		// MPI_Send(&finish, 1, MPI_INT, i, 1, MPI_COMM_WORLD);


// 		// }
// 		// free(charKey);
// 		// free(possibleKey);

// 		myKey++;
// 	}
// 	// }

// 	gettimeofday(&end, NULL);

// 	printf("O processo %d levou %ld segundos para concluir\n", myRank, ((end.tv_sec) -
// 	(start.tv_sec)));
// 	// printf("levou %ld microsegundos para concluir\n", ((end.tv_sec * 1000000 + end.tv_usec) -
// 	//   (start.tv_sec * 1000000 + start.tv_usec)));
// 	//deltatime = end - start;
// 	//  printf("senconds: %ld\nmicro seconds : %ld", deltatime.tv_sec, deltatime.tv_usec);

//   return 0;
// }