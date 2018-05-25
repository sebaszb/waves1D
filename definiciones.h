#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string> //mas importantes para imprimir en cadena
#include <sstream>//mas importantes
using namespace std;

double intensidad[1000], velocidad[1000];                      //declaro el numero de celdas
double copiavelocidad[1000], copiaintensidad[1000];            //declaro el numero de celdas
double oldint[1000], oldvel[1000];                             //declaro el numero de celdas
int    M=1000;                                                 //el numero de celdas (mejor que sea entero)
double distancia=/*0.01*/1;                                            //la distancia de la cuerda
double velocidaddeprop=500/*1*/;                               //voy a suponer que la onda se propaga a 1 metro por segundo
double *c_x=new double[M];                                     //la funcion que determina la velocidad de propagacion de la onda punto a punto (cargar medio)
double densidad=0.000004, tension=1;                           //la densidad y tension de la cuerda, no es importante en el automata, ya que la velocidad de propagación ya se definio anteriormente, solo es importante para determinar las energias
int    iteraciones=/*1000000*/60000;                                    //numero de iteraciones
double dt=distancia/(velocidaddeprop*M*2);                     //el paso del tiempo sera de 0.01
double T=dt*iteraciones/2;                                     //dice el tiempo que ha pasado( y divido por dos (creo que es por que cada dos iteraciones pasa un dt)
double dx=distancia/M;                                         //el largo de una celda
double xreal=0;                                                //dará cuenta de la verdadera distancia del arreglo 
double alfa=/*1*/100000;                                       //el alfa de la ecuación de klein gordon
double beta=/*100000*/0;                                               //el beta de la ecuación de klein gordon
int iter=0;                                                    //esta será una copia de la iteracion en la que se va (para usarlo en cualquier funcion)
int FR;                                                        //dara cuenta de las iteraciones para el forzamiento
int disparador=1;                                              //es para parar el cronometro
double energiap;                                               //da cuenta de la energia potencial
double energiak;                                               //da cuenta de la energia cinetica
double energiat;                                               //da cuenta de la energia total
double energia_t_disp=0;                                       //es el disparador para la energia total
double transformadapreal, transformadapimaginaria;             //las variables pasacalcular la transformada de fourier discreta temporal
int NUMERO=iteraciones/10;                                    //El numero de datos que se van a usar para calcular la transformada de fourier discreta temporal (DIBIDO POR 100 POQUE cada 100 iteraciones tomo un dato) es muy importante notar que realmente estoy tomando un dato cada dos iteraciones, y esto es porque pasa el automata hay un factor de 2 que esta dividiendo al dt
double *entrada=new double[NUMERO];
double *transformada=new double[NUMERO];
int contentradasDFT=0;                                         //es el contador para las entradas de la transformada de fourier
int contcadena=0;                                              //cuenta las entradas al escritor en cadena
//-----------------------------------                                                                          


//-----------------------------------
void condicionesiniciales();                //fijo la forma de la cuerda en t=0 en forma de piramide
void condguitarra2();                       //fija la cuerda como dos piramides con in nodo en la mitad
void condviolin();                          //pone la cuerda como la de una violin
void condiniciales1();                      //ponen la cuerda en 0 ecepto 200 celdas de la mitad
void condiniciales2();                      //aca pongo toda la cuerda en 0 eccepto un extremo que lo pongo en 0.2
void condsenosoidal(int n1);                //pone la cuerda de la forma sin(x) con nodos es sus extremos 
void condiniciales5();                      //pone la cuerda en la forma sin(x) con un nodo en el comienzo y el otro expremo libre
void soliton();                             //pone la cuerda en la forma de un soliton, segun la ecuacion 2 del pdf donde solucionan la ecuacion KB analiticamente
void condinicialescero();                   //pone todas las celdas en 0
void condtodos1();                          //pone todas las celdas en 1
void copiaceldas();                         //copio las celdas
void copioold();                            //copio las velocidades e intensidades anteriores
void automata();                            //se define las interacciones entre celdas
void automataverlet();                      //las reglas de evolucion normales, pero integradas segun velocity verlet
void automataKG();                          //son las reglas de evolucion segun la ecuación de Kein Gordon
void automatanabla();                       //es el automata no lineal (con un termino adicional namla cuadrado)
void automatafijo_libre();                  //un extremo fijo y el otro libre
void resulatdos();                          //se muestran los resultados de las intensidades
void datosencadena();                       //imprime archivos en cadena
void resultadosenergiacinetica();           //muestra la energía cinetica
void resultadosenergiapotencial();          //muestra la energia potencial
void resultadosenergiatotal();              //muestra la suma de la energía potencial y la cinetica
void velocidades();                         //muestra como están las velocidades de cada celda
void forzamiento();                         //hace que un extremos de la cuerda se mueva como sin(x)
void cronometro();                          //mira el tiempo que se demora en llegar una señal  
void DFTcapturadatos(int a);                //captura los datos para calcular la transformada temporal
void DFT();                                 //saca las transformada de discreta de fourier temporal                      
void DFTespacial();                         // ||   ||      ||      ||   ||     ||   ||    espacial
void cargarmedio();                         //define las velocidades de propagación en el medio
//-----------------------------------------------------------------------------
