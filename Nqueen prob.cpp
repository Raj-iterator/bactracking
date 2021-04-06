#include<iostream>
using namespace std;
int board[20][20];
int n;

int isattack(int i , int j)
{
	int k,l;
	
	for(k=0;k<n;k++)
	{
		if( board[i][k] == 1 ||  board[k][j] == 1)
		  return 1;
	}
	
	if( board[i-1][j-1] == 1)
	  return 1;
	  else if( board[i+1][j+1] == 1)
	   return 1;
	   else if( board[i+1][j-1] == 1)
	    return 1;
	    else if( board[i-1][j+1] == 1)
	     return 1;
	
	return 0;
}

int nqueen(int n1)
{
	  if(n1==0)
	  return 1;
	  
	  for(int i = 0;i<n;i++)
	  {
	  	for(int j = 0;j<n;j++)
	  	{
	  		 if( !isattack(i,j) && board[i][j] != 1)
	  		 {
	  		 	   board[i][j] = 1;
	  		 	   if(nqueen(n1-1) == 1)
	  		   	   {
	  		 		return 1;
				   }
				   board[i][j] = 0;
			 }
		}
	  }
	  return 0;
	  
}

int main()
{
	
	cin>>n;
	
	
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j< n;j++)
		{
			board[i][j]=0;		
		}
   }
nqueen(n);
	
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j< n;j++)
		{
			cout<<board[i][j]<<" " 		;
		}
		cout<<"\n\n";
	}
}
