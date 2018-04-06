/*
autor:Ing.Abraham Mamani Veliz
*/
#include<stdio.h>

int numePos(int numero,int pos){
  int i;
  int res;
  
  for(i=1;i<pos;i++){
    numero=numero/10;
  }
  res=numero%10;
  
  return res;
}

int main(){
  int numero;
  int pos;
  
  puts("Ingrese un numero:");
  scanf("%d",&numero);
  puts("Ingrese la posicion:");
  scanf("%d",&pos);

  printf("el numero en la posicion es %d del numero %d\n",numePos(numero,pos),numero);
  return 0;
}
