/*
  @author         Abraham Mamani Veliz
  @version        1.0  18/05/2018
  @since          g++
  @description    game similar to sudoku that work in console

*/

#include<iostream>
#include<cstdlib>

using namespace std;
void menu(){
   system("clear");
   cout<<"1.Jugar"<<endl;
   cout<<"0.Salir"<<endl;
}
int generarRandom(int min,int max){
  static bool first = true;
  if (first) 
    {  
      srand( time(NULL) ); 
      first = false;
    }
  return min + rand() % (( max + 1 ) - min);  
}

int getLevelSize(int level){
  int sizeMtr;
  
  switch(level){
  case 1:
    sizeMtr=generarRandom(2,3);
    break;
  case 2:
    sizeMtr=generarRandom(4,5);
    break;
  case 3:
    sizeMtr=generarRandom(6,7);
    break;
  defult:
    sizeMtr=generarRandom(7,8);
    break;
  }
  return sizeMtr;
}
void llenarMatriz(int *matriz,int sizeM,int limSup){
  int i,j;
  for(i=0;i<sizeM;i++){
    for(j=0;j<sizeM;j++){
      matriz[i*sizeM+j]=generarRandom(1,limSup);
     
    }
  }
}

int llenarMatrizCopia(int *matriz,int sizeM,int *copia){
  int i,j,x,y,sumaFila;
  int asterisco=0;
  
  for(i=0;i<sizeM;i++){
    y=generarRandom(0,sizeM-1);   
    for(j=0;j<sizeM;j++){
          
      if( y==j ){
        copia[i*sizeM+j]=0;
        asterisco++;
      }else{
        copia[i*sizeM+j]=matriz[i*sizeM+j];
      }
      
    }
  }
  return asterisco;
}



void mostrarMatriz(int *matriz,int sizeM,int *copia){
  int i,j,sumaFila;
  
  system("clear");
  for(i=0;i<sizeM;i++){
    sumaFila=0;
    for(j=0;j<sizeM;j++){
      
      if(copia[i*sizeM+j]==0  ){
        cout<<"  [*]\t";
        sumaFila+=matriz[i*sizeM+j];
    
      }else{
        cout<<"  ["<<matriz[i*sizeM+j]<<"]\t";
        sumaFila+=matriz[i*sizeM+j];
      }
      
      if(j==sizeM-1){
        cout<<"\t=+fil("<<i<<")="<<sumaFila;
      }
    }
    cout<<endl;
  }
   cout<<"================================================================"<<endl;
   
   for(i=0;i<sizeM;i++){
     sumaFila=0;
     for(j=0;j<sizeM;j++){

      sumaFila+=matriz[j*sizeM+i];

      if(j==sizeM-1){
        cout<<" +Col("<<i<<")="<<sumaFila<<" ";
      }
    }

  }


}

void jugar(){
  int vidas=3;
  int nivel=1;
  int sizeMtr;
  int estrella;
  int x,y,valor;
  do{
    sizeMtr=getLevelSize(nivel);
    int matriz[sizeMtr][sizeMtr];
    int copia[sizeMtr][sizeMtr];
    llenarMatriz(matriz[0],sizeMtr,nivel*10);
    estrella=llenarMatrizCopia(matriz[0],sizeMtr,copia[0]); 

    mostrarMatriz(matriz[0],sizeMtr,copia[0]);
  

    do{
      cout<<endl<<"--------------------------------------------------------------"<<endl;
    cout<<"ingrese fila columa separados por un espacio:"<<endl;
    cin>>x>>y;
    cout<<"Ingrese valor: "<<endl;
    cin>>valor;
    if(copia[x][y]==0){
      if(matriz[x][y]==valor){
        estrella--;
        cout<<endl<<"Correcto!!!!"<<endl;
      }else{
        cout<<"valor incorrecto"<<endl;
        cout<<"Intente de nuevo!!"<<endl;
        vidas--;
        cout<<vidas<<" vidas"<<endl;
      }
    }else{
      cout<<"coordenadas incorrectas"<<endl;
      vidas--;
      cout<<vidas<<" vidas"<<endl;
    }
  }while(estrella!=0 && vidas!=0);

    if(estrella==0){
      nivel++;
      vidas++;
      cout<<"Completaste el nivel!!!!"<<endl;
      cout<<"ganaste una vida mas"<<endl;
      cout<<vidas<<" vidas"<<endl;
      cout<<nivel<<" nivel"<<endl;
    }
  }while(vidas!=0);
}
int main(){
  int op;
  do{
    menu();
    cin>>op;
    switch(op){
    case 1:
      jugar();
      break;
    case 0:
      break;
    default:
      cout<<"fuera de rango"<<endl;
    }
  }while(op!=0);
  
  return 0;
}
