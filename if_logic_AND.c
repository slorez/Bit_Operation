// if_logic_AND.c -- Это программа чтобы посмотреть результат выражения: 
// code & (1L << 1)
// code 5393

#include <stdio.h>
#include <stdbool.h>

void printProtocolTransmit(void);
void decompositionIntToBin(void);

typedef unsigned char byte;


int main(void)
{
	unsigned long testTypebyte = 1L;
	byte b = 93;
	for (int i = 0; i < 8; i++ )
	{
		printf("%c", ( b & 0x1) ? '1' : '0');
		b >>= 1;
	}
	printf("\n");
	printf("value size in bytes : %dbyte this is %d bit", sizeof testTypebyte, sizeof testTypebyte * 8);
	printProtocolTransmit();
	return 0;
}


void decompositionIntToBin()
{

}

