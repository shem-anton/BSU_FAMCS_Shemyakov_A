#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int m, sum = 0;
    cin>>m;
    _asm
    {
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
		cmp esi, m
        je en
        loop cycle
	en:
		sub sum, esi
		mov eax, m
		cmp sum, eax
		je perfect
		jne not_perfect
    }
perfect:
		{
		cout << m <<" is perfect\n";
		goto final;
		}
not_perfect:
		cout << m <<" is not perfect\n";
	final:
	system("PAUSE");
    return EXIT_SUCCESS;
}
