#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000;


// Function to find the nearest '1'
void nearestOne(int mat[][MAX], int m, int n)
{
	//top to bottom and left to right
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(mat[i][j]==0)
			{
				int top=i-1>=0 ? mat[i-1][j]:MAX;
					int left=j-1>=0? mat[i][j-1]:MAX;
					mat[i][j]=min(top,left)+1;
			}
			//As distance between cell having 1 with nearest cell 1 is 0
			else
			{
				mat[i][j]=0;
			}
		}
	}
	//bottom to top and right to left
		for(int i=m-1;i>=0;i--)
		{
			for(int j=n-1;j>=0;j--)
			{
				int bottom=i+1<m? mat[i+1][j]:MAX;
				int right=j+1<n? mat[i][j+1]:MAX;
				mat[i][j]=min(mat[i][j],min(bottom,right)+1);
			}
		}
	return;
}


int main()
{
	int m = 3, n = 4;
	int mat[][MAX] = {{0, 0, 0, 1},
		{0, 0, 1, 1},
		{0, 1, 1, 0}
	};

	// solution distance is updated in mat[][]
	nearestOne(mat, m, n);
	// print distance
	for (int i=0; i<m; i++)
	{
		for (int j=0; j<n; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
	return 0;
}
