#include<bits/stdc++.h>
using namespace std;

class name{

	public:
	int real;
	int imaginary;

	name(int a,int b)
	{
	  real=a;
	  imaginary=b;
	}
	void print()
	{
	 cout<<real<<" + "<<imaginary<<"i"<<endl;
	}
	void additio(name const two)
	{
       int re=(real+two.real);
       int im=(imaginary+two.imaginary);
       real=re;
       imaginary=im;
       cout<<real<<" + ""i"<<imaginary<<endl;
	}
	void multiply(name const two){
		int re=(real*two.real)-(imaginary*two.imaginary);
		int im=(real*two.imaginary)+(two.real*imaginary);
		real=re;
		imaginary=im;
		cout<<real<<" + "<<"i"<<imaginary<<endl;
	}

};
int main()
{
	int a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	name one(a,b);
	one.print();
	name two(c,d);
	two.print();
	if(e==1)
	one.additio(two);
    else
	one.multiply(two);
	return 0;
}