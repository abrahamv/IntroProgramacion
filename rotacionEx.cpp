/*
  @author         Abraham Mamani Veliz
  @version        1.0  18/05/2018
  @compiler       g++ 5.4
  @description    rotate external border of a matrix

*/
#include<iostream>
#include<cstdlib>

using namespace std;


void llenarMatriz(int *matriz,int tamanio){
  int i,j;
  for(i=0;i<tamanio;i++){
    for(j=0;j<tamanio;j++){
      cin>>matriz[i*tamanio+j];
     
    }
  }
}

void printMatriz(int *matriz,int tamanio){
  int i,j;
  for(i=0;i<tamanio;i++){
    for(j=0;j<tamanio;j++){
      cout<<matriz[i*tamanio+j]<<" ";
    }
    cout<<endl;
  }
  
}

int main(){

  int tamanio,times;
  char direccion;
  int i,j;
  cin>>tamanio;
  cin>>times;
  cin>>direccion;
  int next,curr,curr2;
  
  int matriz[tamanio][tamanio];
  int vector[(tamanio*tamanio)-tamanio];
  llenarMatriz((int *)matriz,tamanio);
  //  printMatriz((int *)matriz,tamanio);
  int ultimo;
  if(direccion=='d'){
    for(int k=0;k<(times*(tamanio-1));k++){
      curr=matriz[0][0];
      int last=matriz[1][0];
      
            
      for(i=0;i<tamanio;i++){
      for(j=0;j<tamanio;j++){
        if(i==0){
          next=matriz[i][j+1];    
          matriz[i][j+1]=curr;
         
        }
        if(j==tamanio-1){
          next=matriz[i+1][j];    
          matriz[i+1][j]=curr;
          ultimo=curr;
        }
        curr=next;
          
      }
     
    }
    

      curr=ultimo;
      for(i=tamanio-1;i>=0;i--){
        for(j=tamanio-2;j>=0;j--){
          
          
          if(i==tamanio-1){
            next=matriz[i][j];    
            
            matriz[i][j]=curr;
            
          }

        
          if(j==0){
            next=matriz[i-1][j];
            matriz[i-1][j]=curr;
            
          }
          
          
          
          curr=next;
          
        }
      }
      matriz[0][0]=last;
      
    }
  }
  else{
    for(int k=0;k<(times*(tamanio-1));k++){
       curr=matriz[0][0];
       int last=matriz[0][1];
      
            
      for(i=0;i<tamanio;i++){
        for(j=0;j<tamanio;j++){
          if(i==0){
             next=matriz[j+1][i];    
             matriz[j+1][i]=curr;
    
          }
          if(j==tamanio-1){
             next=matriz[j][i+1];    
             matriz[j][i+1]=curr;
             ultimo=curr;
    
          }
          curr=next;
          
        }
        
      }
      
      curr=ultimo;
      for(i=tamanio-1;i>=0;i--){
        for(j=tamanio-2;j>=0;j--){
                    
          if(i==tamanio-1){
            next=matriz[j][i];    
            
            matriz[j][i]=curr;
            
          }
          
          curr=next;    
          if(j==0){
            next=matriz[j][i-1];
            matriz[j][i-1]=curr;
            
          }
          
        }
      }

      matriz[0][0]=last;
      
    }
    
  }
  cout<<endl;
  printMatriz((int *)matriz,tamanio);
  return 0;
}
