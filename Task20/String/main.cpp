#include <iostream>

using namespace std;

int main()
{
	char st1[100]="ccat", st2[100]="concatenation", temp[50]={};
	int result, counter = 0;//counter contains top of temp
	//cout << "Enter two strings\n";
	//cin >> st1 >> st2;
	_asm
	{
		xor edx, edx

		cld
		lea ebx, st1
		dec ebx

		lea eax, st2

		xor esi, esi
st2length:
		cmp [eax+esi], 0
		je cycle
		inc esi
		jmp st2length// esi - st2's length
cycle:
		inc ebx
		cmp [ebx], 0
		je endofline
		
		mov ecx, counter
		mov al, [ebx]
		lea edi, temp
		repnz scasb
		dec edi

		push eax
		mov eax, [edi]
		pop eax

		cmp [edi], al
		je cycle
		cmp ecx, 0
		jne cycle

		mov ecx, esi
		lea edi, st2
		mov eax, [ebx]
		repne scasb

		cmp ecx, 0
		je cycle

		inc edx
		mov eax, counter
		push edx
		mov edx, [ebx]
		mov temp[eax], dl
		pop edx
		inc eax
		mov counter, eax

		jmp cycle
endofline:
		mov result, edx
	}
	cout << temp << endl;
	return 0;
}