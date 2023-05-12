// *****UNIVERSIDAD LAICA ELOY ALFARO DE MANABI*****
// *Facultad de Ciencias de la Vida y Tecnologias*
// Carrera:    Ingenieria de TI
// Materia:    Modelamiento y Simulacion
// Autores:    Ávila Macias Esleiter Didier
//             Figueroa Briones Anthony Saúl
//             Laínez Tomalá Joffre Alex
// Tema:       Metodo de Biseccion en C++


// llamamos a las librerias necesarias,
// definimos precision de decimales y 
// creamos el namespace
#include <iostream>
#include <iomanip> 
#include <cmath>
#define PRECISION 6
using namespace std;

//se llama funcion ImprimePuntos
double f(double x);
void imprimePuntos(double a, double b);

//se crea el main
int main()
{
   //se establece la suprecio, en este caso asignamos el valos ya estable cido en la linea
   cout << setprecision(PRECISION); // Establecemos la precisión
   
   //se declaran variables a usarse
   double a, b, tolerancia;
   
   //primera interfaz para que se ingrese por teclado el intervalo a analizarse
   cout << "\nCalculo de las raices de una funcion aplicando el metodo de la biseccion" << endl;
   cout << "\nIngrese el intervalo inicial [a, b]" << endl;
   cout << "\na = ";
   cin >> a;
   
   cout << "b = ";
   cin >> b;
   
   //se imprime el resultado del intervalo agregado anteriormente
   imprimePuntos(a, b);
   
   //segun los resultados anteriores se analiza y escoje los mejores puntos para el metodo
   cout << "\nEscoja el intervalo adecuado" << endl;
   cout << "\na = ";
   cin >> a;
   
   cout << "b = ";
   cin >> b;
   
   // [a, b]

   //se declara variable que sera la raiz de la funcion
   float xr; 
   
   /*
   cout << "\nf(" << a << ") = " << f(a) << endl;
   cout << "f(" << b << ") = " << f(b) << endl;
   */


   // se validan los intervalos seleccionados para validar o no la realizacion del metodo en ese
   if (f(a) * f(b) > 0) {
      
      cout << "\nNo se puede aplicar el metodo de la biseccion\n";
      cout << "porque f(" << a << ") y f(" << b << ") tienes el mismo signo" << endl;
      
   } else {
      cout << "Tolerancia = ";
      cin >> tolerancia;
      cout << "\na\tb\tx\tf(a)\t\tf(b)\t\tf(x)\n" << endl;
      do {
         xr = (a + b) / 2.0;
         cout << a << "\t" << b << "\t" << xr << "\t";
         cout << f(a) << "\t" << f(b) << "\t" << f(xr) << endl;

         // Vemos si cumple o no cumple con la tolerancia ingresada
         if (abs(f(xr)) <= tolerancia) { // xr sería la raiz de la funcion

            //en caso se valide con la tolerancia se imprimen resultados
            cout << "\n\nPara una tolerancia " << tolerancia << " la raiz de f es " << xr << endl;
         
            break;

            //caso contrario seguira calculando resultados
         } else {
            if (f(xr) * f(a) > 0) {
               a = xr;
            } else if (f(xr) * f(b) > 0) {
               b = xr;
            }
         }
         
      } while (1);
   }
   
   cin.get();
   cin.get();
   return 0;
}

//aqui ingresamos la funcion a resolver
//solo se puede una a la vez
//se agrego tres para probar la 
//funcionalidad y versatibilidad del programa
double f(double x) 
{
   //return exp(-1 * x) - cos(3 * x) - 0.5;
   return pow(x,4) + 3*pow(x,3)-2;
   //return exp(x) - x - 2;
}

//metodo de imprimir y limitar los intervalos
//para identificar cual sera la mejor seleccion
//de puntos para empezar la biseccion
#define INTERVALOS 10
void imprimePuntos(double a, double b)
{
   int puntos = INTERVALOS + 1;
   
   double ancho = (b - a) / INTERVALOS;
   
   cout << "\n";
   cout << "\tx\tf(x)\n" << endl;
   for (int i = 0; i < puntos; i++) {
      cout << "\t" << a << "\t" << f(a) << endl;
      a = a + ancho;
   }
}