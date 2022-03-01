///Estudiante: Chambilla Choquecota Drake Leonel
///Codigo: 181986

#include<iostream>
using namespace std;

void ComplementoUno(int n[]){
    for(int i=0; i<8; i++){
        if(n[i] == 0){
            n[i] = 1;
        }else{
            n[i] = 0;
        }
    }
}

void ComplementoDos(int n[]){
    for(int i=7; i>=0; i--){
        if(n[i] == 0){
            n[i] = 1;
            break;
        }else if(n[i] == 1){
            n[i] = 0;
        }
    }
}

void MostrarN(int n[]){
    for(int i=0; i<8; i++){
        cout<<n[i];
    }
}


int main(){

    ///numeros a multiplicar con rango hasta 255
    int n1[] = {0,0,0,0,1,0,0,0};  ///3 en binario
    int n2[] = {0,0,0,0,1,0,0,0};  ///5 en binario


    cout<<"         ";MostrarN(n1);
    cout<<"   X";
    cout<<endl;
    cout<<"         ";MostrarN(n2);
    cout<<endl;
    cout<<"------------------"<<endl;

    int Cn1[8];
    for(int i=0; i<8; i++){
        Cn1[i] = n1[i];
    }

    ComplementoUno(Cn1);
    ComplementoDos(Cn1);

    int matriz[3][17] = { {0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0},   //P
                          {0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0},   //S
                          {0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0} }; //T

    ///insertando datos a la matriz
    for(int i=0; i<8; i++){
        matriz[0][i] = n1[i];
    }
    for(int i=0; i<8; i++){
        matriz[1][i] = Cn1[i];
    }
    for(int i=8; i<16; i++){
        matriz[2][i] = n2[i-8];
    }

    ///Empezando las ejecuciones del Algoritmo de Booth con sus reglas
    for(int i=0; i<8; i++){

        if(matriz[2][15] == 0 && matriz[2][16] == 1){ /// T = T + P
            //Suma
            for(int i=16; i>=0; i--){
                matriz[2][i] = matriz[2][i] + matriz[0][i];
                if(matriz[2][i] == 2){
                    matriz[2][i] = 0;
                    if(i != 0){
                        matriz[2][i-1] = matriz[2][i-1] + 1;
                    }
                }
                if(matriz[2][i] == 3){
                    matriz[2][i] = 1;
                    if(i != 0){
                        matriz[2][i-1] = matriz[2][i-1] + 1;
                    }
                }
            }
            //Rotacion Derecha
            for(int i=16; i>=0; i--){
                if(i != 0){
                   matriz[2][i] = matriz[2][i-1];
                }
            }

        }else if(matriz[2][15] == 1 && matriz[2][16] == 0){ /// T = T + S

            for(int i=16; i>=0; i--){
                matriz[2][i] = matriz[2][i] + matriz[1][i];
                if(matriz[2][i] == 2){
                    matriz[2][i] = 0;
                    if(i != 0){
                        matriz[2][i-1] = matriz[2][i-1] + 1;
                    }
                }
                if(matriz[2][i] == 3){
                    matriz[2][i] = 1;
                    if(i != 0){
                        matriz[2][i-1] = matriz[2][i-1] + 1;
                    }
                }
            }
            ///Rotacion Derecha
            for(int i=16; i>=0; i--){
                if(i != 0){
                   matriz[2][i] = matriz[2][i-1];
                }
            }

        }else{  /// CASOS 0 0 Y 1 1
            ///Rotacion Derecha
            for(int i=16; i>=0; i--){
                if(i != 0){
                   matriz[2][i] = matriz[2][i-1];
                }
            }
        }

    }

    ///Ultima Rotacion Derecha
    for(int i=16; i>=0; i--){
        if(i != 0){
        matriz[2][i] = matriz[2][i-1];
        }
    }

    ///Imprimir Respuesta
    for(int j=0; j<17; j++){
        cout<<matriz[2][j];
    }

return 0;
}
