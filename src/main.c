#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bitShift.h"


int main(int argc, char const *argv[])
{	
	/* Запись лог 1 с обнуления */
	uint8_t b = 0x50;
	printBit(b); 
	b = (1<<7) | (1<<1);
	printf(" b: %#x ", b);
	printBit(b);
	putchar('\n');
	
	/* Запись лог 1 без обнуления */
	b = 0x50;
	printBit(b);
	b |= (1<<7) | (1<<1);
	printf(" b: %#x ", b);
	printBit(b);
	putchar('\n');
	
	/* Запись лог 0 без обнуления */
	b = 0xFF;
	printBit(b);
	b &= ~(1<<7);
	printf(" b: %#x ", b);
	printBit(b);
	putchar('\n');
	
	/* Запись лог 0 с записью остальных разрядов в лог 1 */
	// 1100.0000
	uint8_t dev = (1<<7) | (1<<6);
	// 1101.1101
	b = 0xDD;
	printBit(b);
	// 0011.1111 = 0x3F;
	b = ~(dev);
	printf(" b: %#x ", b);
	printBit(b);
	putchar('\n');

	/* Проверка разряда на наличие лог 0 */
	dev = 0xD0;
	b = 0xFF;
	for (int i = 0; i < 8; i++){
		printRowLine('=',40);
		if ( 0 ==(dev & (1 << i)))
			printf("[TRUE ]:[%#X] & [%#X] == 0\n", (1 << i), dev);
		else
			printf("[FALSE]:[%#X] & [%#X] == 0\n", (1 << i), dev);
		printRowLine('-',40);
		if ( 0 ==(b & (1 << i)))
			printf("[TRUE ]:[%#X] & [%#X] == 0\n", (1 << i), b);
		else
			printf("[FALSE]:[%#X] & [%#X] == 0\n", (1 << i), b);
		printRowLine('=',40);
	}
	for (int i = 0; i < 8; i++){
		printRowLine('=',40);
		if ( ~dev & (1 << i))
			printf("[TRUE ]:[%#X] & ~[%#X]\n", (1 << i), dev);
		else
			printf("[FALSE]:[%#X] & ~[%#X]\n", (1 << i), dev);
		printRowLine('-',40);
		if ( 0 ==(b & (1 << i)))
			printf("[TRUE ]:[%#X] & ~[%#X]\n", (1 << i), b);
		else
			printf("[FALSE]:[%#X] & ~[%#X]\n", (1 << i), b);
		printRowLine('=',40);
	}
	/* Проверка разряда на наличие лог 1 */
	/* Ожидание появления лог 1 в некотором разряде */
	/* Ожидание появления лог 0 в некотором разряде */
	/* Проверка состояния определенных разрядов */
	return 0;
}

