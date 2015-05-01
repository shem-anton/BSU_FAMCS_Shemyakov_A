#include <iostream>


int main()
{
	int siz, min_neg[2]={1,1}, max_neg[3]={-2147483648, -2147483648, -2147483648}, max_pos[3]={-1,-1,-1}, result;
	std::cout << "Enter the size of array\n";
	std::cin >> siz;
	int *array = new int[siz];
	for(int i=0; i<siz; i++)
		std::cin >> array[i];
	_asm
	{
		mov ebx, array
 		mov ecx, siz
cycle1:
		xor eax, eax
		cmp [ebx], eax
		jg positive// positive/negative check
//minimal negative:
		mov eax, [min_neg]
		cmp [ebx], eax
		jg neg_min_second
		//move first to second, [ebx] to first
		mov eax, [min_neg]
		mov [min_neg+4], eax
		mov eax, [ebx]
		mov [min_neg], eax
		jmp next_neg
neg_min_second:
		mov eax, [min_neg+4]
		cmp [ebx], eax
		jg next_neg
		//move [ebx] to second
		mov eax, [ebx]
		mov [min_neg+4], eax
		jmp next_neg
next_neg:

//maximal negative
		mov eax, [max_neg]
		cmp [ebx], eax
		jl neg_max_second
		//move second to third, first to second, [ebx] to first
		mov eax, [max_neg+4]
		mov [max_neg+8], eax
		mov eax, [max_neg]
		mov [max_neg+4], eax
		mov eax, [ebx]
		mov [max_neg], eax
		jmp next
neg_max_second:
		mov eax, [max_neg+4]
		cmp [ebx], eax
		jl neg_max_third
		//move second to third, [ebx] to second
		mov [max_neg+4], eax
		mov eax, [max_neg+8]
		mov eax, [ebx]
		mov [max_neg+4], eax
		jmp jump
		//long cycle
cycle:
		jmp cycle1;
jump:
		jmp next
neg_max_third:
		mov eax, [max_neg+8]
		cmp [ebx], eax
		jl next
		//move [ebx] to third
		mov eax, [ebx]
		mov [max_neg+8], eax

positive:
		mov eax, [max_pos]
		cmp [ebx], eax
		jl pos_second
		//move second to third, first to second, [ebx] to first
		mov eax, [max_pos+4]
		mov [max_pos+8], eax
		mov eax, [max_pos]
		mov [max_pos+4], eax
		mov eax, [ebx]
		mov [max_pos], eax
		jmp next
pos_second:
		mov eax, [max_pos+4]
		cmp [ebx], eax
		jl pos_third
		//move second to third, [ebx] to second
		mov eax, [max_pos+4]
		mov [max_pos+8], eax
		mov eax, [ebx]
		mov [max_pos+4], eax
		jmp next
pos_third:

		mov eax, [max_pos+8]
		cmp [ebx], eax
		jl next
		//move [ebx] to third
		mov eax, [ebx]
		mov [max_pos+8], eax
next:
		add ebx, 4 //next element
		loop cycle

		//end of cycle

		xor eax, eax
		cmp max_pos, eax
		jnl there_is_positive
		mov eax, [max_neg]
		xor edx, edx
		mul [max_neg+4]
		mul [max_neg+8]
		mov result, eax
		jmp end
there_is_positive:
		mov eax, [min_neg]
		xor edx, edx
		xor ebx, ebx
		cmp eax, ebx
		je is_zero
		dec edx
is_zero:
		mul [min_neg+4]
		mov ebx, eax// product of two smallest negative numbers
		xor eax, eax
		dec eax
		cmp [max_pos+8], eax
		je neg_greater
		mov eax, [max_pos+4]
		xor edx, edx
		mul [max_pos+8]// product of second and third biggest positive numbers
		cmp eax, ebx
		jl neg_greater
		mul [max_pos]
		mov result, eax
		jmp end
neg_greater:
		mov eax, ebx
		xor edx, edx
		mul [max_pos]
		mov result, eax
end:
	} 
	//std::cout << min_neg[0] <<" "<< min_neg[1]<<std::endl<<max_neg[2]<<" "<<max_neg[1]<<" "<<max_neg[0]<<std::endl<<max_pos[2]<<" "<<max_pos[1]<<" "<<max_pos[0] << std::endl;
	std::cout<< result<< "\n";
	system("pause");
	return 0;
}