#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#include "gotoxy.h"
#include "pila.h"


#define DIM_TEMPERATURAS 50
#define DIM_FLOAT 20
#define DIM_CHAR 50
#define DIM_LETRAS 100
#define DIM_CAPICUA 30
#define DIM_INVERTIDO 30
#define DIM_SELECCION 100
#define DIM_INSERCION 100


void imprimircabecera(char cabecera[]);
void consolaColor(int color);
char rangoNumeros (int min, int max);
int cargaArrayUser (int t[], int dim, int v, char titulo[]);///<1>
void muestraArray(int t[], int v, char titulo[]);///<2>
int sumaElementosArray (int a[], int v);///<3>
void array2pila(int t[], int v, Pila *p);///<4>
int cargaArrayRandom(int t[], int v,int dim,int cant);
float promedioArray (int a[], int v);
int pila2array(Pila p, int t[], int dim);
void muestraPila (Pila p, char titulo[]);///Muestra los elementos de una Pila
void pasaPila (Pila *origen, Pila *destino);///Pasa los elementos de una Pila a otra
void replicaChar (char c, int cant);
void columna (char c, int cant);
void muestraMenu (char titulo[], int x, int y);
int cargaAFloat (float a[], int dim, char titulo[]);///5)
int cargaAFloatRandom (float a[], int dim, int v);
void muestraAFloat (float a[], int v, char titulo[]);///5)
int cargaAChar (char a[], int dim, char titulo[]);///6)
int cargaACharRandom (char a[], int dim, int v, int cant);
int buscaChar (char a[], int v, char letra);///6)
void buscaCharAUsuario (char a[], int v, char letra);///6)
void muestraAChar (char a[], int v, char titulo[]);///6)
int insertaChar (char a[], int v, int dim, char letra);///7)
char buscaMayorChar (char a[], int v);///8)
int arrayCapicua (int a[], int v);///9)
void invierteArray (int a[], int v);///10)
void ordenaASeleccion (int a[], int v);///11)
void ordenaAInsercion (int a[], int v);



int main()
{
    Pila TEMP;
    inicpila(&TEMP);

    srand(time(NULL));

    int temperaturas[DIM_TEMPERATURAS];
    float arrayDecimal[DIM_FLOAT];
    char caracteres [DIM_CHAR];
    char letras[DIM_LETRAS];
    int capicua[DIM_CAPICUA];
    int invertido[DIM_INVERTIDO];
    int seleccion[DIM_SELECCION];
    int insercion[DIM_INSERCION];

    char buscar;
    char mayorChar;

    int valTemp = 0;
    int valFloat = 0;
    int valChar = 0;
    int valLetras = 0;
    int valCapicua = 0;
    int valInvertido = 0;
    int valSeleccion = 0;
    int valInsercion = 0;


    int x = 0;
    int y = 0;


    char opcion = 0;

    do{
        hidecursor(0);
        consolaColor(10);
        system("cls");
        imprimircabecera("TP Arrays");
        replicaChar('=',64);
        printf("\n>>>0)-Funcion que carga aleatoriamente un Array-----------------");
        printf("\n>>>1)-Funcion que permite al usuario cargar un Array------------");
        printf("\n>>>2)-Funcion que muestra un Array Con datos--------------------");
        printf("\n>>>3)-Funcion que suma los elementos de un Array----------------");
        printf("\n>>>4)-Funcion que copia los elementos de un Array en una pila---");
        printf("\n>>>5)-Funcion que carga y muestra un Array de tipo float--------");
        printf("\n>>>6)-Funcion que carga y busca un char en un Array-------------");
        printf("\n>>>7)-Funcion que inserta un caracter en un array seleccion-----");
        printf("\n>>>8)-Funcion que carga un array tipo CHAR y busca el mayor-----");
        printf("\n>>>9)-Funcion que verifica si un array es capicua---------------");
        printf("\n>>>A)-Funcion que invierte un array-----------------------------");
        printf("\n>>>B)-Funcion que ordena un array por seleccion-----------------");
        printf("\n>>>C)-Funcion que ordena un array por insercion-----------------");
        printf("\n");
        replicaChar('=', 64);
        opcion = getch();
        system("cls");

        switch(opcion)
        {
            case '0':
                    if (valTemp != 0)
                        {
                        printf("<ERROR> Ya cargo previamente el Array");
                        muestraArray(temperaturas, valTemp, "Temperaturas");
                        }
                    else
                        {
                        valTemp = cargaArrayRandom(temperaturas, valTemp, DIM_TEMPERATURAS, 30);
                        muestraArray(temperaturas, valTemp, "Se cargo aleatoriamente el Array\n\n\tTemperaturas");
                        }
                break;
            case '1': valTemp = cargaArrayUser(temperaturas, DIM_TEMPERATURAS, valTemp, "----Cargue una temperatura > ");
                      printf("Presione una tecla para continuar...");
                break;
            case '2': if (valTemp == 0)
                        {
                        printf("\n\n<ERROR> El Array no tiene ningun dato.\n\nPor favor cargelo con la opcion <0> o <1>");
                        }
                    else
                        {
                        muestraArray(temperaturas, valTemp, "\tArray de Temperaturas");
                        }
                 break;
            case '3':
                    if (valTemp == 0)
                        {
                        printf("\n\n<ERROR> El Array no tiene ningun dato.\n\nPor favor cargelo con la opcion <0> o <1>");
                        }
                    else{
                        printf("\n\n----La suma de los elementos del array [Temperaturas] es: <%d>", sumaElementosArray(temperaturas, valTemp));
                        }
                break;
            case '4':
                    if (valTemp == 0)
                        {
                        printf("\n\n<ERROR> El Array no tiene ningun dato.\n\nPor favor cargelo con la opcion <0> o <1>");
                        }
                    else if (!pilavacia(&TEMP))
                        {
                        printf("<ERROR> Ya copio los datos del Array a la Pila");
                        muestraPila(TEMP, "Pila [TEMPERATURAS]");
                        }
                    else
                        {
                        muestraArray(temperaturas, valTemp, "Se copiaron los elementos del Array de Temperaturas a una Pila\n\n\tArray [Temperaturas]");
                        array2pila(temperaturas, valTemp, &TEMP);
                        muestraPila(TEMP, "Pila [TEMPERATURAS]");
                        }
                break;
            case '5':
                    valFloat = cargaAFloatRandom(arrayDecimal, 100, valFloat);
                    muestraAFloat(arrayDecimal, valFloat, "Se cargo el Array con numeros con decimal");
                break;
            case '6':
                    valChar = cargaAChar(caracteres, DIM_CHAR, "----Ingrese un caracter >>> ");
                    printf("\n----Ingrese el caracter el caracter a buscar en el Array >>> ");
                    fflush(stdin);
                    scanf("%c", &buscar);
                    buscaCharAUsuario(caracteres, valChar, buscar);
                    muestraAChar(caracteres, valChar, "Caracteres");
                break;
            case '7':
                    valChar = cargaAChar(caracteres, DIM_CHAR, "----Ingrese caracteres de forma alfabetica >>> ");
                    system("cls");
                    if (valChar < DIM_CHAR)
                        {
                        printf("\n----Ingrese un caracter que desea ordenar >>> ");
                        fflush(stdin);
                        scanf("%c", &buscar);
                        valChar = insertaChar(caracteres, valChar, DIM_CHAR, buscar);
                        printf("---Se inserto el caracter %c en el array---", buscar);
                        muestraAChar(caracteres, valChar, "Caracteres");
                        }
                        else
                            {
                            printf("<ERROR> No puede ingresar un caracter al array porque esta LLENO!!");
                            }
                break;
            case '8':
                    valLetras = cargaAChar(letras, DIM_LETRAS, "---Ingrese un caracter al array LETRAS>>> ");
                    mayorChar = buscaMayorChar(letras, valLetras);
                    muestraAChar(letras, valLetras, "Array letras");
                    printf("\n\n");
                    printf("El char de mayor valor es <%c>", mayorChar);
                break;
            case 27: x = 40;
                     y = 10;
                    gotoxy(x, y);
                    color(3);
                    printf("Nos vemos perrin cuidate");
                break;
            case '9':
                    valCapicua = 0;
                    valCapicua = cargaArrayUser(capicua, DIM_CAPICUA, valCapicua, "---Ingrese un numero al Array|>> ");
                    if (arrayCapicua(capicua, valCapicua))
                        {
                        imprimircabecera("El array SI es capicua");
                        muestraArray(capicua, valCapicua, "\tSEEEEEEE");                        }
                        else
                            {
                            imprimircabecera("El array NO es capicua");
                            muestraArray(capicua, valCapicua, "\tNOOOOOOOO");
                            }
                break;
            case 'A':
                    valInvertido = cargaArrayRandom(invertido, valInvertido, DIM_INVERTIDO, 12);
                    muestraArray(invertido, valInvertido, "\tSe cargo el array");
                    printf("\n\n");
                    system("pause");
                    system("cls");
                    invierteArray(invertido, valInvertido);
                    muestraArray(invertido, valInvertido, "\tSe invirtio el array");
                break;
            case 'B':
                    valSeleccion = cargaArrayRandom(seleccion, valSeleccion, DIM_SELECCION, 50);
                    muestraArray(seleccion, valSeleccion, "\tSe cargo el array");
                    printf("\n\n");
                    system("pause");
                    system("cls");
                    ordenaASeleccion(seleccion, valSeleccion);
                    muestraArray(seleccion, valSeleccion, "\tSe ordeno el array por SELECCION");
                break;
            case 'C':
                    valInsercion = cargaArrayRandom(insercion, valInsercion, DIM_INSERCION, 60);
                    muestraArray(insercion, valInsercion, "\t\tSe cargo el array");
                    printf("\n\n");
                    system("pause");
                    system("cls");
                    ordenaAInsercion(insercion, valInsercion);
                    muestraArray(insercion, valInsercion, "\t\tSe ordeno el array por INSERCION");
                break;
            default: printf("\n\n---<ERROR> Ingreso una opcion no valida---");
                break;
        }
        opcion = getch();
        system("cls");
    }while (opcion != 27);

    return 0;
}



void consolaColor(int colorin)
{
    int x = 0;
    int y = 0;

    while (x<200)
            {
            gotoxy(x, y);
            color(colorin);
            x++;
            }
        while (y < 200)
            {
            gotoxy(x, y);
            color(colorin);
            y++;
            }
}


void imprimircabecera(char cabecera[])
{
    int i;
    printf("%c", 201);
    for (i=0;i<50;i++)
        {
        printf("%c", 205);
        }
    printf("%c\n", 187);
    printf("%c%32s%19c\n", 186, cabecera,186);
    printf("%c", 200);

    for (i=0;i<50;i++)
        {
        printf( "%c", 205);
        }
    printf("%c",188);
}

/** \brief Crea numeros aleatorios en un cierto rango de numeros
 *
 * \param El numero minimo
 * \param El numero maximo
 * \return Numero aleatorio
 *
 */
char rangoNumeros (int min, int max)
{
    return (char) rand() / (max-min) + min;
}


///1)
/** \brief Pide al usuario que cargue un array de tipo int
 *
 * \param Un array de tipo int
 * \param La dimension del array
 * \param Los validos del array
 * \param Una cadena de caracteres
 * \return Los validos del array
 *
 */
int cargaArrayUser (int t[], int dim, int validos, char titulo[])
{
    char opcion = 0;

    while (validos < dim && opcion != 27)
        {
        printf("\n%s", titulo);
        scanf("%d", &t[validos]);
        printf("\n\n---Presione <ESC> para salir o calquier tecla para continuar---");
        opcion = getch();
        system("cls");
        validos++;
        }
        return validos;
}



///2)
/** \brief Muestra por pantalla un array
 *
 * \param Un array con datos
 * \param Una variable que Funcione como validos del Array
 * \param Una cadena de caracteres
 * \return No return
 *
 */
void muestraArray(int t[], int validos, char titulo[])
{
    printf("\n\n%s", titulo);
    for(int i=0;i<validos;i++)
        {
        if (i % 15 == 0)
            {
            printf("\n\n");
            }
            printf(" [%02d] ~", t[i]);
            }
}



///3)
/** \brief Suma los numeros de un array
 *
 * \param Un array de tipo int
 * \param Los validos del array
 * \return La suma de los numeros
 *
 */
int sumaElementosArray (int a[], int validos)
{
    int suma = 0;

    for (int i=0;i<validos;i++)
        {
        suma += a[i];
        }
    return suma;
}



/** \brief Carga un array con numeros int aleatorios
 *
 * \param Un array
 * \param Cantidad de elementos
 * \return Los validos del array
 *
 */
int cargaArrayRandom(int t[], int v,int dim,int cant)
{
    while (v<cant && v<dim)
        {
        t[v] = rand()%50;
        v++;
        }
        return v;
}



///4)
/** \brief Copia los numeros de un array a una pila
 *
 * \param Un array tipo int
 * \param Los validos del array
 * \param Una pila (destino)
 * \return No return
 *
 */
void array2pila(int t[], int validos, Pila *p)
{
    for(int i=0;i<validos;i++)
        {
        apilar(p, t[i]);
        }
}




/** \brief Pasa los numeros de una pila a un array
 *
 * \param Una pila cargada
 * \param Un array de tipo int
 * \param Los validos del array
 * \return Los validos del array
 *
 */
int pila2array(Pila p, int t[], int dim)
{
    Pila AUX;
    inicpila(&AUX);

    int i=0;
    while (!pilavacia(&p) && i<dim)
        {
        t[i] = desapilar(&p);
        i++;
        }
    return i;
}



/** \brief Saca el promedio de los numeros de un array
 *
 * \param Un array de tipo int
 * \param Los validos del array
 * \return El promedio del array
 *
 */
float promedioArray (int a[], int v)
{
    return (float) sumaElementosArray(a, v) / v;
}



 /** \brief Pasa elementos de una pila a otra
  *
  * \param Puntero a una pila cargada (ORIGEN)
  * \param Puntero a una pila vacia o no (DESTINO)
  * \return No return
  *
  */
void pasaPila (Pila *origen, Pila *destino)
{
    while (!pilavacia(origen))
        {
        apilar(destino, desapilar(origen));
        }
}



/** \brief Muestra una pila por pantalla
 *
 * \param Una pila
 * \param Un string como titulo
 * \return No return
 *
 */
void muestraPila (Pila p, char titulo[])
{
    Pila AUX;

    inicpila(&AUX);
    int i = 0;

    pasaPila(&p, &AUX);

    printf("\n\n\t\t%s", titulo);
    printf("\n");
    while (!pilavacia(&AUX))
        {
            {
            printf(" %02d |", tope(&AUX));
            apilar(&p, desapilar(&AUX));

        i++;
        if (i%12 == 0)
            {
            printf("\n");
            }
        }
}
  printf("\n");
}




void replicaChar (char c, int cant)
{
    printf("\n");
    for (int i=0;i<cant;i++)
        {
        printf("%c", c);
        }
    printf("\n");
}
void columna (char c, int cant)
{
    for (int i=0;i<cant;i++)
        {
        printf("\n%c", c);
        }
}
void muestraMenu (char titulo[], int x, int y)
{
    gotoxy (x, y);
    printf("%s", titulo);
}



///5)
/** \brief Carga un Array con numeros float
 *
 * \param Un array de tipo float
 * \param La dimension de dicho array
 * \param Un titulo para la carga de datos
 * \return No return
 *
 */
int cargaAFloat (float a[], int dim, char titulo[])
{
    char opcion;
    int v=0;
    while (v<dim && opcion != 27)
        {
        printf("\n%s", titulo);
        scanf("%f", &a[v]);
        printf("\n\n---Presione <ESC> para salir o calquier tecla para continuar---");
        opcion = getch();
        system("cls");
        v++;
        }
    return v;
}
/** \brief Carga aleatoriamente un Array de tipo float
 *
 * \param Un Array tipo float
 * \param La dimension del Array
 * \param Los validos del Array
 * \return Los nuevos validos
 *
 */

int cargaAFloatRandom (float a[], int dim, int v)
{
    int i;
    for (i=v;i<dim;i++)
        {
        a[i] = (float)((rand()%10) +1) / 1.3;
        }
    return i;
}
/** \brief Muestra los datos de un array tipo float
 *
 * \param Un array de tipo float
 * \param Los validos del array
 * \param Un titulo para mostrar
 * \return No return
 *
 */
void muestraAFloat (float a[], int v, char titulo[])
{
    printf("%s", titulo);

    for (int i=0;i<v;i++)
        {
        if (i%12 == 0)
            {
            printf("\n\n");
            }
        printf(" [%02.2f] -", a[i]);

        }
}



///6)
/** \brief Carga un Array de tipo char
 *
 * \param Un array tipo char
 * \param Dimension del array
 * \param Un titulo de lo que se requiera cargar
 * \return Validos
 *
 */
int cargaAChar (char a[], int dim, char titulo[])
{
    int v=0;
    char opcion;

    while (v<dim && opcion != 27)
        {
        printf("\n%s", titulo);
        fflush(stdin);
        scanf("%c", &a[v]);
        printf("Presione <ESC> para salir o cualquier tecla para continuar----");
        opcion = getch();
        system("cls");
        v++;
        }
    return v;
}
int cargaACharRandom (char a[], int dim, int v, int cant)
{
    while (v<dim && v<cant)
        {
        a[v] =  rangoNumeros(40, 60);
        v++;
        }
    return v;
}
/** \brief Busca un caracter en un array tipo char
 *
 * \param Un array de tipo char
 * \param Los validos
 * \param El caracter a buscar
 * \return Flag
 *
 */
int buscaChar (char a[], int v, char letra)
{
    int flag = 0;
    int i=0;
    while (!flag && i<v)
        {
        if (a[i] == letra)
            {
            flag = 1;
            }
        else
            {
            i++;
            }
        }
    return flag;
}
/** \brief Le muestra al usuario si el caracter se encontraba en el array
 *
 * \param Un array tipo char
 * \param Los validos del array
 * \param El caracter a buscar
 * \return No return
 *
 */
void buscaCharAUsuario (char a[], int v, char letra)
{
    if(buscaChar(a, v, letra))
        {
        printf("\n\nEl caracter '%c' se encuentra en el Array", letra);
        }
    else
        {
        printf("\n\nEl caracter '%c' no se encuentra en el Array", letra);
        }
}
/** \brief Muestra un Array tipo char
 *
 * \param Un Array tipo char
 * \param Los validos
 * \param Lo que quiera informar por pantalla
 * \return No return
 *
 */
void muestraAChar (char a[], int v, char titulo[])
{
    printf("\n\t\t%s", titulo);
    for (int i=0;i<v;i++)
        {
        if (i%15 == 0)
            {
            printf("\n");
            }
        printf(" [%c] ~", a[i]);
        }
}


///7)
/** \brief Inserta un elemento en un Array tipo char
 *
 * \param Un Array tipo char
 * \param Los validos
 * \param La dimension del array
 * \param El char que quiera insertar
 * \return Los validos
 *
 */
int insertaChar (char a[], int v, int dim, char letra)
{
    int e = v;
    int i = v-1;
        if (v+1 < dim)
            {
            while (i>=0 && a[i] > letra)
                {
                a[e] = a[i];
                i--;
                e--;
                }
            a[i+1] = letra;
            }
    return v+1;
}


///8)
/** \brief Busca el caracter de mayor valor en un Array tipo char
 *
 * \param Un array tipo char
 * \param Los validos
 * \return Char de mayor valor
 *
 */
char buscaMayorChar (char a[], int v)
{
    char mayor = 0;

    for (int i=0;i<v;i++)
        {
        if (a[i] > mayor)
            {
            mayor = a[i];
            }
        }
    return mayor;
}


///9)
/** \brief Verifica si un array es capicua
 *
 * \param Array de tipo int
 * \param Los validos
 * \return Flag
 *
 */
int arrayCapicua (int a[], int v)
{
    int i=0;
    int j=v-1;
    int flag = 0;

    while (i < j && j > i && a[i] == a[j])
        {
        i++;
        j--;
        }

    if (a[i] == a[j])
        {
        flag = 1;
        }
    return flag;
}



///10)
/** \brief Invierte un array
 *
 * \param Un array tipo int
 * \param Los validos
 * \return No return
 *
 */
void invierteArray (int a[], int v)
{
    int aux;
    int i = 0;
    int j = v-1;

    while (i < j && j > i)
        {
        aux = a[i];
        a[i] = a[j];
        a[j] = aux;
        i++;
        j--;
        }
}




///11)
/** \brief Ordena un array por seleccion
 *
 * \param Un array tipo int
 * \param Los validos
 * \return No return
 *
 */
void ordenaASeleccion (int a[], int v)
{
    int i;
    int j;
    int aux;

    for (i=0;i<v;i++)
        {
        for (j=0;j<v;j++)
            {
            if(a[j] > a[i])
                {
                aux = a[j];
                a[j] = a[i];
                a[i] = aux;
                }
            }
        }
}


void inserta (int a[], int v, int dato)
{
    int aux = a[v];
    int i = v-1;

    while (i >= 0 && a[i] > a[i-1])
        {
        a[i+1] = a[i];
        i--;
        }
}


void ordenaAInsercion (int a[], int v)
{
    int i=0;
    int j=0;
    while(i<v-1)
        {
        inserta(a, i, a[i+1]);
        i++;
        }
}
