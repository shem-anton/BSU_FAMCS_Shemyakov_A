#include <iostream>

int main()
{
	int siz, num;
	std::cout << "Enter the size of array\n";
	std::cin >> siz;
	//siz = 5;
	int *array = new int[siz];
	std::cout<<"Enter the sorted array\n";
	for(int i=0; i<siz; i++)
	std::cin >> array[i];
		//array[i] = i+1;
	std::cout << "Enter the element to find\n";
	std::cin >> num;
	//num = 2;
	int index;
	_asm
	{
		//ebx contains current pointer
		//ecx contains current length of step in !!bytes*4!!
		xor esi, esi
		mov ebx, array
		mov ecx, siz
		dec ecx
step_right:
		shr ecx, 1
		jnc int_division1
		cmp ecx, 0
		je situation1
		jmp inc1
situation1:
		cmp esi, 1
		je int_division1
		inc esi
inc1:
		inc ecx
int_division1:
		shl ecx, 2
		add ebx, ecx
		shr ecx, 2
		jmp cycle
step_left:
		shr ecx, 1
		jnc int_division2
		cmp ecx, 0
		je situation2
		jmp inc2
situation2:
		cmp esi, 1
		je int_division2
		inc esi
inc2:
		inc ecx
int_division2:
		shl ecx, 2
		sub ebx, ecx
		shr ecx, 2
cycle:

		mov eax, 1
		cmp ecx, eax
		jl not_found//not found, step is less than int

		mov eax, [ebx]
		cmp eax, num
		je end//exact location
		jl step_right//less then needed
		jg step_left//more than needed
not_found:
		mov eax, [ebx]
		cmp num, eax
		jl first
		add ebx, 4
first:
end:
		sub ebx, array
		shr ebx, 2
		mov index, ebx
	}
	std::cout << index << "\n";
	system("PAUSE");
	return 0;
}