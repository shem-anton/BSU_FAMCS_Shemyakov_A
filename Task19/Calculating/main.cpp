#include <iostream>

int main()
{
	int n /*= 2*/, result1, one;
	double x /*= 1*/, a /*= 3*/, result, result2, trash;
	std::cout << "Enter n, x and a\n";
	std::cin >> n >> x >> a;
	_asm
	{
		mov one, 1
		mov ecx, n
		shl ecx, 1
		finit

		fild one// result

		xor ebx, ebx
		xor eax, eax
		inc eax
		//Set result2 to 1
		fild one//result2
cycle:
		inc ebx//Counter
		mov esi, ebx
		//add esi, n
		mul esi
		mov edx, n
		cmp ebx, edx
		jng cycle

		fld x
		fadd a
		fmul ST(1), ST(0)
		//pop ST(0)
		fstp trash

		mov esi, n
		add esi, n
		add esi, n
		sub esi, ecx
		inc esi
		cmp ebx, esi
		jne cycle

		mov result1, eax
		fild result1
		fdivr ST, ST(1)
		fmul ST, ST(2)
		fxch ST(2)
		//pop stack
		fstp trash

		xor ebx, ebx
		xor eax, eax
		inc eax
		//Set result2 to 1
		fstp trash
		fild one
		loop cycle
		fstp trash
		fst result
	}
	std::cout << result <<"\n";
	system("pause");
	return 0;
}