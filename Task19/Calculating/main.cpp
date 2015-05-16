#include <iostream>

int main()
{
	int n = 2, temp;
	double x = 1, a = 3, result;
	//std::cout << "Enter n, x and a\n";
	//std::cin >> n >> x >> a;
	_asm
	{
		fld1// result
		fld1// temp numerator
		fld1// temp denominator

		mov ecx, n
		shl ecx, 1//ecx = 3n

		xor ebx, ebx

cycle:
		
		inc ebx//i = ebx
		mov temp, ebx
		fild temp
		fmulp ST(1), ST(0)
		cmp ebx, n
		jng cycle

		fld x
		fadd a
		fmulp ST(2), ST(0)

		fxch ST(2)
		fmul ST(0), ST(1)
		fdiv ST(0), ST(2)
		fxch ST(2)

		loop cycle

		fxch ST(2)
		fst result
	}
	std::cout << result <<"\n";
	system("pause");
	return 0;
}