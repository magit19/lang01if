#include <stdio.h>
#include <locale.h>

int main() {
	int x,y;
	int result = -1;

	setlocale(LC_ALL, "ru");

	printf("������� ���������� x,y: ");
	scanf("%d %d", &x, &y);
	_asm {
		mov ecx, dword ptr [x];
		mov edx, dword ptr [y];

		cmp ecx, 2;
		jge inside;
		mov eax, 0
		jmp end;

	  inside:
		mov eax, 1;
		jmp end;

	  end:
		mov dword ptr [result], eax;
		}

	if (result==1) 
		printf("����� ��������� � �������");
	else
		printf("����� �� ��������� � �������");

	return 0;
}
