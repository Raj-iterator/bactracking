#include<iostream>
using namespace std;
#define n 4

bool smu( int maze[n][n],int x , int y, int sol[n][n] );

bool issafe( int maze[n][n],int x,int y)
{
	if( x>=0 && y>=0 && x<n && y<n &&maze[x][y] == 1)
	return true;
	
	return false;
}

void print( int sol[n][n])
{
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		cout<<sol[i][j]<<" ";
		
		cout<<"\n\n";
	}
	
}

bool solvemaze(int maze[n][n])
{
	int sol[4][4]={0};
	if( smu(maze,0,0,sol) == false)
	{
	cout<<"The solution doesnot exists";
	return false;
    }
    print(sol);
    return true;
	
}

bool smu( int maze[n][n],int x ,int y, int sol[n][n])
{
	if( x== n-1 && y==n-1 && maze[x][y] == 1)  // base case
	 {
	 	sol[x][y] = 1;
	 	return true;
	 }
	 
	 if( issafe( maze, x, y) == true )
	 {
	 	 sol[x][y]= 1;
	 	 if( smu(maze,x+1,y,sol) == true)
	 	   return true;
	 	 if( smu(maze,x,y+1,sol) == true)
		  return true;
		  
		  sol[x][y] = 0;
		  return false;  
	 }
	 
	 return false;
}


int main()
{
	int maze[4][4]= { {1,0,0,0},
	                  {1,1,0,1},
					  {0,1,1,0},
					  {1,1,1,1}};
					  
					  
		solvemaze(maze);
		return 0;			  
}
