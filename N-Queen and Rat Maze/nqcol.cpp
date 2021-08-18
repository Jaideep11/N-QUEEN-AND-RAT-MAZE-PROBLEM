#include<iostream>
using namespace std; 
#define N 4 

void display(int temp[N][N]) 
{ 
	for (int i = 0; i < N; i++) { 
		for (int j = 0; j < N; j++) 
		cout<<" "<<temp[i][j];
		cout<<"\n";
	} 
} 
bool calculate(int temp[N][N], int row, int col) 
{ 
	int i, j; 
	for (i = 0; i < col; i++) 
		if (temp[row][i]) 
		{
			return false; 
		}

	for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
		if (temp[i][j]) 
		{
			return false; 
		}

	for (i = row, j = col; j >= 0 && i < N; i++, j--) 
		if (temp[i][j]) 
		{
			return false; 
		}
	return true; 
} 
bool show(int temp[N][N], int col) 
{ 
	
	if (col >= N) 
		{
		return true; 
		}

	for (int i = 0; i < N; i++) { 
	
		if (calculate(temp, i, col)) { 
        {
			temp[i][col] = 1; 
		}

			if (show(temp, col + 1)) 
		{
				return true; 
		}
			temp[i][col] = 0; 
		} 
	} 
	return false; 
} 
bool fun() 
{ 
	int temp[N][N] = { { 0, 0, 0, 0 }, 
						{ 0, 0, 0, 0 }, 
						{ 0, 0, 0, 0 }, 
						{ 0, 0, 0, 0 } }; 

	if (show(temp, 0) == false) { 
		cout<<"Solution is not possible.";
		return false; 
	} 

	display(temp); 
	return true; 
} 
int main() 
{ 
	fun(); 
} 

