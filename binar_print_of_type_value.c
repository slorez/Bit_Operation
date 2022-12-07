/* binar_print_of_type_valye.c -- выводит числа в двоичном виде */

#include <stdio.h>

void bit_char(unsigned char bit);
void bit_short(unsigned short bit);
void bit_int(unsigned int bit);
void bit_long_long(unsigned long long bit);

int main(void)
{
	unsigned char _bit_8 = 93;
	unsigned short _bit_16 = 256;
	unsigned int _bit_32 = 15678963;
	unsigned long long _bit_64 = 3658749465455678963;


/*	for (int i = 0; i <= 255; i++)
	{
		printf("%d\t",i);
		bit_char((unsigned char)i);
		printf("\n");
	}*/

	bit_char(_bit_8);
	bit_short(_bit_16);
	bit_int(_bit_32);
	bit_long_long(_bit_64);

	return 0;
}

void bit_char(unsigned char bit)
{
	for(int i = 0; i < sizeof(char)*8; i++)
	{
		printf("%c", ( bit & 0x80 ) ? '1' : '0');
		bit <<= 1;
	}
	printf(" size: %hd bit\n", sizeof(bit)*8);
}

void bit_short(unsigned short bit)
{
	for(int i = 0; i < sizeof(short)*8; i++)
	{
		printf("%c", ( bit & 0x8000 ) ? '1' : '0');
		bit <<= 1;
	}
	printf(" size: %hd bit\n", sizeof(bit)*8);
}

void bit_int(unsigned int bit)
{
	for(int i = 0; i < sizeof(int)*8; i++)
	{
		printf("%c", ( bit & 0x80000000 ) ? '1' : '0');
		bit <<= 1;
	}
	printf(" size: %hd bit\n", sizeof(bit)*8);
}

void bit_long_long(unsigned long long bit)
{
	for(long i = 0; i < sizeof(long long)*8; i++)
	{
		printf("%c", ( bit & 0x8000000000000000 ) ? '1' : '0');
		bit <<= 1;
	}
	printf(" size: %hd bit\n", sizeof(bit)*8);
}