#include <iostream>

using namespace std;

int main()
{
	const int m = 5, n = 5;
	int temp;
	int matrix[m][n];
	//cout << "Enter the matrix\n";
	for(int i = 0; i<m; ++i)
		for(int j = 0; j<n; ++j)
			//cin >> matrix[i][j];
			matrix[i][j] = 10+j+i*n;

	for(int i = 0; i<m; ++i)
	{
		for(int j = 0; j<n; ++j)
			cout << matrix[i][j] << "  ";
		cout << endl;
	}

	cout << endl;

	_asm
	{
		xor ecx, ecx//ecx contains i
		mov esi, m
		cmp esi, n
		jl cycle
		mov esi, n//esi = min(m,n)
cycle:		
		mov eax, n
		mul ecx
		add eax, ecx
		mov ebx, matrix[eax*4]//four lines to find left cell
		mov edi, eax//edi = left cell index
		mov temp, ebx 
		
		sub eax, ecx
		sub eax, ecx
		add eax, n
		dec eax

		mov ebx, matrix[eax*4]
		mov matrix[edi*4], ebx//left cell = right one
		mov ebx, temp
		mov matrix[eax*4], ebx

		inc ecx
		cmp ecx, esi
		jne cycle
	}

	for(int i = 0; i<m; ++i)
	{
		for(int j = 0; j<n; ++j)
			cout << matrix[i][j] << "  ";
		cout << endl;
	}

	system("PAUSE");
	return 0;
}