#include<iostream>
#include<vector>
#include<algorithm>
double fdev(double t, std::vector<double> &I, double h);
double euler(double a, double b,double h, std::vector<double> &A);
double w=3;
int main ()
{
  int  N=2;
  std::vector<double> A(N);
  A[0]=0;
  A[1]=2;
  double ta=0;
  double tb=40.04;
  double h=0.00001;
  euler(ta,tb,h,A);

  return 0;
}
double euler(double ta, double tb, double h, std::vector<double> &A)
  {
    std::vector<double> atmp(A.size());
    const int N=(tb-ta)/h;
    for(int nt=0;nt<N;++nt)
      {	double t= ta+h*nt;
	std::copy(A.begin(), A.end(), atmp.begin());
	for( int id=0; id< A.size();++id)
	  {
	    A[id]=A[id]+h*fdev(t,atmp,id);
	  }
	std::cout<<"\t"<<A[0]<<"\t"<<A[1]<<std::endl;
      }
    return 0;
  }
double fdev(double t, std::vector<double> &I, double h)
{
  if(0==h)
    {
      return I[1];
    }
  else
    {
      if(1==h)
	{
	  return -w*w*I[0];
	}
      else
	{
	  std::cerr<<"Error "<<h<<std::endl;
	}
    }
}
  
  
