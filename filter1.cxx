#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// declacaration of functions
void rd_data(double* const p, const int N, const string fname);
void filter(double* p, const int N);
void out_print(double* const p, const int N);


// main function: reading, filtering, printing filtered in ext_file
int main(void)
{
  const int N = 237; 
  const string filename = "noisy.txt"; 
  double* p = new double[N]; 

  string name = "filtered";
  stringstream s;

  rd_data(p,N,filename);

  filter(p,N);

  // APPLYING THE FILTER MORE THAN ONCE:

  // int no = 0;
  //  cout << "Number of applying the filter\t" << endl;
  //  cin >> no;
 
  //  if (no < 0) // alternative: use case // proof:# applyied filter
  //   {
  //      cout << "Too small" << endl;
  //   }
  //  else
  //     {
  //      for(int i=0; i<no; i++)
  //     	{
  //               (no == 0)? rd_data(p,N,filename) : filter(p,N);     
  //            }
  //     }

  out_print(p,N);

  delete[] p;

  return 0;
}

//-----------------------------------------------------------------
// Reading data out from noisy.txt
void rd_data(double* const p, const int N, const string fname)
{
  ifstream in(fname.c_str());
  
  for(int i=0; i<N; i++)
    {
      in >> p[i];
    }
  in.close();
}

//----------------------------------------------------------------
// Reducing the noise by replacing every value in p-array with local
// average (written a bit too complicated!)

void filter(double* p, const int N)
{
  double p_0 = p[0];
  double p_end;
  double temp_p1 = 0;
  double temp_p2 = 0;
  
  p[0]  = (p_0 + p[1] + p[N-1]); // p[N-1]+p[0]+p[1], p[N]=p[0]
  p[0] /= 3.0; // in respect to the boundary at p[0]

  p_end  = p[N-2] + p[N-1] + p_0 ; // p[N-2]+p[N-1]+p[N], p[N]=p[0]
  p_end /= 3.0; // in respect to the boundary at p[N-1

  for(int i=1; i<N-1; i++)
    {      
      temp_p1 = p_0; // p[i-1]
      temp_p2 = p[i]; // p[i]

      p[i]  = temp_p1 + temp_p2 + p[i+1]; //p[i-1]+p[i]+p[i+1]
      p[i] /= 3.0; // reducing the noise by function till p[N-2]

      temp_p1 = temp_p2; // p[i] = p[i-1]
      temp_p2 = p[i+1]; // p[i+1] = p[i]              
    }
  
  p[N-1] = p_end;
}
 
//-------------------------------------------------------
// Writing data in an extra functions
void out_print(double* const p, const int N)
{
  ofstream out("filtered.txt");
  
  for(int i=0; i<N; i++)
    {
      out << p[i] << endl;
    }

  out.close();
}
