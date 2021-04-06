#include<iostream>
using namespace std;

int paths(int m , int n)
{
	if( m == 1 || n == 1)
	 return 1;
	return paths( m , n - 1) + paths( m-1,n);
}

int main()
{
	int m,n,k;
	cin>>m>>n;
	
	k = paths(m,n);
	cout<<k;
}
