#include <iostream>

int main()
{
    int m, sum = 0, two = 2;
	bool result = 0;
    std::cin>>m;
    _asm
    {
	mov eax, m
	mov edx, 0
	div two
	mov ecx, eax
        xor esi, esi
    cycle:
        inc esi
        mov eax, m
        mov edx, 0
        div esi
	cmp edx, 0
        jne nm
        add sum, esi
	nm:
        loop cycle
		mov eax, m
		cmp sum, eax
		jne not_perfect
		mov result, 1
	not_perfect:
    }
	std::cout << result << std::endl;
	system("PAUSE");
    return EXIT_SUCCESS;
}
