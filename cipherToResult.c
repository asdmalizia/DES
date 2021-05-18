// #include <math.h>
// #include <stdlib.h>
// #include <stdio.h>
// void cipherToResult(int* cipher, char* result){//arrumar pra ponteiros
// int k;
// int value=0;
//   for(k=0;k<61;k=k+4){
//     //calcula de quatro em quatro bits o valor correspondente
//     value = pow(2,3)*cipher[k] + pow(2,2)*cipher[k+1] + pow(2,1)*cipher[k+2] + pow(2,0)*cipher[k+3];

//    // itoa(value,&result[k/4],16);  
//     sprintf(&result[k/4],"%X",value);

//     value =0;
//   }

// }

// #include <stdio.h>

// #include <math.h>
// #include <stdlib.h>
// int main(){//arrumar pra ponteiros
// int k;
// char *result;
// int cipher[16] = {1,1,1,1, 0,0,0,0 ,1,0,1,0, 1,0,1,1}; 
// int value=0;
// result = (char*)malloc(4*sizeof(char));
//   for(k=0;k<13;k=k+4){
//     //calcula de quatro em quatro bits o valor correspondente
//     value = pow(2,3)*cipher[k] + pow(2,2)*cipher[k+1] + pow(2,1)*cipher[k+2] + pow(2,0)*cipher[k+3];
//     printf("%d\  %d\n",k,value);

//    // itoa(value,&result[k/4],16);  
//     sprintf(&result[k/4],"%X",value);

//     value =0;
//   }

// printf("%s\n",result);
// }