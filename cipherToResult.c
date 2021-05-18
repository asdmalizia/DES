#include <math.h>
void cipherToResult(int* cipher, char* result){//arrumar pra ponteiros
int k;
int value;
  for(k=0;k<61;k=k+4){
    //calcula de quatro em quatro bits o valor correspondente
    value = pow(2,0)*cipher[k] + pow(2,1)*cipher[k+1] + pow(2,2)*cipher[k+2] + pow(2,3)*cipher[k+3];

    //analisa o valor de value para virar hexa mas char
    if (value<9){
      result[k/4] = value + '0';  
    }

    result[k/4] = 'a';
  }


}
