/*-------------------------------------
Dato de Entrada:  filas, col (int)
Dato de Salida: matriz con el revelado de la imagen de la primera matriz
 */



#include <iostream>
#include <iomanip>
using namespace std;

void llenarMatriz(int ** pM, int filas, int col);
void imprimirMatriz(int ** pM, int filas, int col);
void  imprimiMatrizdeCaracteres(char **pCar, int filas, int col);

int main()
{
   int ** pM1= nullptr;
   int filas, col;

   cout << "Filas: " ; cin >> filas;
   cout << "Columnas : "; cin >> col;

   pM1 = new int*[filas];
   for(int f=0; f<filas; f++)
       pM1[f] = new int[col];

   llenarMatriz(pM1,filas,col);
   imprimirMatriz(pM1,filas,col);
   //--- creamos la segunda matriz
   char **pCar = new char*[filas];
   for(int f=0; f<filas; f++)
       pCar[f] = new char[col];
   //----lenamos la matriz de caracteres
    for(int f=0; f<filas; f++)
        for(int c=0; c<col; c++)
        {
            if( pM1[f][c] ==0 )
                pCar[f][c] = '.';
            if(pM1[f][c]==1 or pM1[f][c]==2 or pM1[f][c]==3  )
                pCar[f][c] = '_';
            if(pM1[f][c]==4 or pM1[f][c]==5 or pM1[f][c]==6  )
                pCar[f][c] = '#';
            if(pM1[f][c]==7 or pM1[f][c]==8 or pM1[f][c]==9  )
                pCar[f][c] = '*';
        }
    cout << "\n\n";
    imprimiMatrizdeCaracteres(pCar, filas, col);
    //--- eliminamos la primera matriz
    for(int f=0 ; f<filas; f++)
        delete []pM1[f];
    delete []pM1;
    pM1 = nullptr;

    //---eliminamos la segunda matriz
    for(int f=0 ; f<filas; f++)
        delete []pCar[f];
    delete []pCar;
    pCar = nullptr;
    
    return 0;
}


void  imprimiMatrizdeCaracteres(char **pCar, int filas, int col) {
    for (int f = 0; f < filas; f++) {
        for (int c = 0; c < col; c++)
            cout << setw(3) << pCar[f][c];
        cout << "\n";
    }
}



void llenarMatriz(int ** pM, int filas, int col)
{
    for(int f=0; f<filas; f++)
        for(int c=0; c<col; c++)
            pM[f][c] = rand() % 10;
}

void imprimirMatriz(int ** pM, int filas, int col)
{
    for (int f = 0; f < filas; f++) {
        for (int c = 0; c < col; c++)
            cout << setw(3) << pM[f][c];
        cout << "\n";
    }
}