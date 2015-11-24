#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// declaration of functions
void rdn_nr(double *x, const int N);
void minmax(double *x, const int N, double &min, double &max);



// main function 
int main()
{
  const int N(100);
  double x[N];
  double min, max;

  srand(time(NULL));

  rdn_nr(x,N);
  minmax(x,N,min,max); // mindmax(n,N,min,max): use everwhere same typ!

  cout << "Minimum:\t" << min << endl;
  cout << "Maximum:\t" << max << endl;
 
  return 0;
}

//----------------------------------------------------
// function: random number

void rdn_nr(double *x , const int N)
{
for(int i = 0; i < N; i++)
     {
       x[i] = (double) rand()/(RAND_MAX); //cout << i <<" " << x[i] << endl;     
     }
}

//----------------------------------------------------
// function: finding minimum and maximum value in array

void minmax(double *x, const int N, double &min, double &max)
{
  // initialize min, max
  min = x[0];
  max = x[0];

  for(int i = 1; i < N; i++)
    {
      (min < x[i]? min : min = x[i]);
      (max > x[i]? max : max = x[i]);
    }
}
