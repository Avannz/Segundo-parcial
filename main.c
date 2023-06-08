#include <stdio.h>
#include <stdlib.h>

typedef  struct
{
    char marca[30];
    char modelo[30];
    int precio;

} stAutomovil;

const int filas = 3;
const int colum = 3;

int cargarAutomovil (stAutomovil autos[], int dim);
void mostrarArreglo(stAutomovil autos[], int validos);
int cargarMatriz(int matriz[filas][colum]);
void mostrarMatriz(int matriz[filas][colum]);
void pasarArchivo(stAutomovil autos[], int validos);
void mostrarArchivo ();

int main()
{
    stAutomovil autos[30];
    int matriz [filas][colum];
    int validos;

    validos = cargarAutomovil(autos, 30);
    mostrarArreglo(autos, validos);

    cargarMatriz(matriz);
    mostrarMatriz(matriz);

    pasarArchivo(autos, validos);
    mostrarArchivo();

}

int cargarAutomovil (stAutomovil autos[], int dim)
{

    int i = 0;
    char letra = 's';

    while(i < dim && letra == 's')
    {

        printf("Ingresa la marca del auto: ");
        fflush(stdin);
        gets(autos[i].marca);

        printf("Ingresa el modelo del auto: ");
        fflush(stdin);
        gets(autos[i].modelo);

        printf("Ingresa el precio del auto: ");
        fflush(stdin);
        scanf("%i", &autos[i].precio);


        printf("Presiona 's' para continuar: ");
        fflush(stdin);
        scanf("%c", &letra);

        i++;

    }

    return i;
}

void mostrarArreglo(stAutomovil autos[], int validos)
{

    int i = 0;

    while(i < validos)
    {

        printf("\n===========================\n");
        printf("Marca: %s  \n", autos[i].marca);
        printf("Modelo: %s \n", autos[i].modelo);
        printf("Precio: %i \n", autos[i].precio);
        printf("===========================\n");

        i++;
    }
}

int cargarMatriz(int matriz[filas][colum])
{

    int i = 0;
    int j = 0;

    for(i = 0; i < filas; i++)
    {
        printf("Fila numero: %i \n", i+1);

        for(j = 0; j < colum; j++)
        {

            printf("\nIngresa un numero a la matriz: ");
            fflush(stdin);
            scanf("%i", &matriz[i][j]);

        }
    }
}

void mostrarMatriz(int matriz[filas][colum])
{

    int i = 0;
    int j = 0;

    for(i = 0; i < filas; i++)
    {
        printf("\n");
        for(j = 0; j < colum; j++)
        {

            printf("| %d |", matriz[i][j]);

        }
    }
}

void pasarArchivo(stAutomovil autos[], int validos)
{

    FILE *archivo;
    archivo = fopen("miArchivo.bin", "ab");

    stAutomovil aux;

    int i = 0;

    if(archivo != NULL)
    {

        while(i < validos)
        {

            aux = autos[i];
            fwrite(&aux, sizeof(stAutomovil), 1, archivo);

            i++;

        }
        fclose(archivo);
    }
}

void mostrarArchivo ()
{

    FILE *archivo;
    archivo = fopen("miArchivo.bin", "rb");


    if(archivo != NULL)
    {

        stAutomovil autoo;
        while(!feof(archivo))
        {

            fread(&autoo, sizeof(stAutomovil), 1, archivo);

            if(!feof(archivo))
            {


            modMostrar(autoo);

            }

        }

    }
    else
    {

        printf("El archivo no se ha encontrado :c");

    }
}

void modMostrar(stAutomovil autoo)
{

    stAutomovil autoInd;

    printf("===================");
    printf("\nMarca: %s", autoo.marca);
    printf("\nModelo: %s", autoo.modelo);
    printf("\nPrecio: %d", autoo.precio);
    printf("===================");

}
