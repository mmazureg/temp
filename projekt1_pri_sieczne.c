#include <math.h>
#include <stdio.h>
#define EPSX 0.0001
#define EPS0 0.0001

double a=1,b=1,c=5,d=3,e=1,f=1,g=2;  //inicjalizacja paramtertow funkcji

double fun(double x)  // funkcja zwracajaca wartosc funkcji postaci a*x^b + c*cos(d) + e*x^f + g
{                     //    w punkcie x
    return a*pow(x,b) + e*pow(x,f) + c*cos(d) + g;
}

int main(){

double x0, x1, x2, xm1, xm2, f0, f1, f2;
int i;

puts("Michal Mazurek, Grupa I2\n");
puts("Program liczacy miejsca zerowe funkcji postaci a*x^b + c*cos(d) + e*x^f + g metoda siecznych\n");
puts("Podaj punkty poczatkowe x1, x2 oraz liczbe iteracji\n");

while(1) // petla sprawdzajaca poprawnosc danych i zalozenie konieczne przy metodzie siecznych
{ if ((scanf(" %lf %lf %d", &x1, &x2,&i))!= 3)
    {
        puts("Blad danych, sprobuj ponownie");
        getchar();
        continue;
    }
   if( (f1=fun(x1)) * (f2=fun(x2)) >= EPS0)
    {
        puts("Wartosci f1 i f2 musza byc roznych znakow, sprobuj ponownie");
        getchar();
        continue;
    }
    else break;
}

xm1=x1; xm2=x2;

while(i>0 && fabs(x1-x2)>= EPSX && (fabs(f1-f2)) >= EPS0) // petla wykonujaca metode siecznych az
{x0=x1-(f1*(x1-x2))/(f1-f2);                    // do przekroczenia granic dokladnosci lub liczby iteracji
 f0=fun(x0);
 if(f0==0){break;}
 x2=x1; x1=x0;
 f2=f1; f1=f0;
 i--;
}

if(i==0){
    puts("Nie znaleziono miejsca zerowego");
    return 1;
    }

printf("Dla punktow poczatkowych x1=%.8lg i x2=%.8lg\nMiejsce zerowe to x0=%.8lg\n", xm1 , xm2, x0);
return 0;
}
