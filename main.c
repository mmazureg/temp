#include <math.h>
#include <stdio.h>
#define EPSX 0.0001
#define EPS0 0.0001

double a=1,b=1,c=1,d=2,e=-1,f=1,g=-3;  //inicjalizacja paramtertow funkcji

double fun(double x); // funkcja zwracajaca wartosc funkcji postaci a*x^b +  c*x^d + e*x^f + g
                      //    w punkcie x

void input(double*, double*); // funkcja wczytujaca i sprawdzajaca poprawnosc przedzialu

int main(){

double x0, x1, x2, xm1, xm2, f0, f1, f2;

puts("Michal Mazurek\n");
puts("Program liczacy miejsca zerowe funkcji postaci a*x^b + c*x^d + e*x^f + g \nmetoda bisekcji\n");
puts("Podaj przedzial poszukiwania x1 i x2\n");
input(&x1,&x2);

xm1 = x1; xm2 = x2;
f1 = fun(x1); f2 = fun(f2);

while( fabs(x1 - x2) >= EPSX) // petla wykonujaca metode bisekcji az
{  x0 = (x1 + x2) / 2.0;           // do przekroczenia jednej z granic dokladnosci
   f0 = fun(x0);

   if(fabs(f0) < EPS0) break;
   if(f1*f0 < 0) x2=x0;
   else {x1=x0; f1=f0;}

}

printf("\nDla punktow poczatkowych x1=%.8lg i x2=%.8lg\nMiejsce zerowe to x0=%.8lg\n", xm1 , xm2, x0);
return 0;
}

double fun(double x)  // funkcja zwracajaca wartosc funkcji postaci a*x^b +  c*x^d + e*x^f + g
{                     //    w punkcie x
    return a * pow(x,b) + c * pow(x,d) + e * pow(x,f) + g;
}

void input(double* x1, double* x2) // funkcja sprawdzajaca poprawnosc danych i zalozenie konieczne przy metodzie bisekcji
{
  while(1)
  {
    if ((scanf(" %lf %lf", x1, x2))!= 2)
    {
        puts("Blad danych, sprobuj ponownie\n");
        while (getchar() != '\n'){} //czyszczenie bufora
        continue;
    }
   if( (fun(*x1)) * (fun(*x2)) >= EPS0)
    {
        puts("Wartosci f1 i f2 musza byc roznych znakow, sprobuj ponownie:");
        while (getchar() != '\n'){}
        continue;
    }
    else break;
  }
}
