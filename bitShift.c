/* bitShift.c -- программа демонстрирует операцию поразрядного сдвига влево */
#include <stdio.h>
#include "bitShift.h"

void printBit(uint8_t n){
	for (int i = 0; i < 8; i++){
			if( i == 4 )
				printf(".");
			printf("%c", (n & (0x80>>i)) ? '1' : '0' );
	}
}
void printASCI(void){
	printRowLine('-',104);
	for (uint8_t i = 33; i <= 50; i++){
		for ( int n = 0; n < 2; n++,i++ ){
			printf("| dec: %3d | char: %2c | hex: %#x | bin: ", i, i, i);
			printBit(i);
			printf(" | ");
		}
		printf("\n");
		printRowLine('-',104);
	}
}
void printShiftLeft(void){
	uint8_t bit = 1;
	for ( int i = 0; i < 8; i++ ){
		printf("bit: ");
		printBit(bit);
		printf(" << %d ==> ",i);
		printBit(bit<<i);
		printf("\n");
	}
}
void printShiftRight(void){
	uint8_t bit = 0x80;
	for ( int i = 0; i < 8; i++ ){
		printf("bit: ");
		printBit(bit);
		printf(" >> %d ==> ",i);
		printBit(bit>>i);
		printf("\n");
	}
}
void printRowLine(char a, int count){
	for ( int i = 0; i < count; i++)
		putchar(a);
	printf("\n");
}
void printComp(void){
	uint8_t num[] = {0b11110000,0b00001111,0b00110011,
					 0b11001100,0b10101010,0b01010101,
					 0b11111100,0b00000011};
	for (int i = 0; i < 8; i++)
	{
		printf("bit: ");
		printf(" ~");
		printBit(num[i]);
		printf(" ==> ");
		printBit(~num[i]);
		printf("\n");
	} 
}
void printAnd(void){
	uint8_t num[] = {0b11110000,0b00001111,0b00110011,
				 	 0b11001100,0b10101010,0b01010101,
				 	 0b11111100,0b00000011};
	for (int i = 0; i < 8; i++){
		for (int n = 7; n >= 0; n--){
			printBit(num[i]);
			printf(" & ");
			printBit(num[n]);
			printf(" ==> ");
			printBit(num[i]&num[n]);
			printf("\n");
		}
		printf("\n");
	}
}
void printOr(void){
	uint8_t num[] = {0b11110000,0b00001111,0b00110011,
				 	 0b11001100,0b10101010,0b01010101,
				 	 0b11111100,0b00000011};
	for (int i = 0; i < 8; i++){
		for (int n = 7; n >= 0; n--){
			printBit(num[i]);
			printf(" | ");
			printBit(num[n]);
			printf(" ==> ");
			printBit(num[i]|num[n]);
			printf("\n");
		}
		printf("\n");
	}
}
void printXor(void){
	uint8_t num[] = {0b11110000,0b00001111,0b00110011,
				 	 0b11001100,0b10101010,0b01010101,
				 	 0b11111100,0b00000011};
	for (int i = 0; i < 8; i++){
		for (int n = 7; n >= 0; n--){
			printBit(num[i]);
			printf(" ^ ");
			printBit(num[n]);
			printf(" ==> ");
			printBit(num[i]^num[n]);
			printf("\n");
		}
		printf("\n");
	}
}
void spaceHead(char s, int count){
	for (int i = 0; i < count; i++)
		putchar(s);
}
void printAll(void)
{
	/*Таблица ASCI*/
	printRowLine('=',COUNTLINE);
	H_ASCI;
	printf("%s\n",ASCI);
	printRowLine('=',COUNTLINE);
	printASCI();
	printRowLine('=',COUNTLINE);
	/*Побитовый сдвиг вправо*/
	H_BIT_SHIFT_RIGHT;
	printf("%s\n",BIT_SHIFT_RIGHT);
	printRowLine('=',COUNTLINE);
	printShiftRight();
	printRowLine('=',COUNTLINE);
	/*Побитовый сдвиг влево*/
	H_BIT_SHIFT_LEFT;
	printf("%s\n", BIT_SHIFT_LEFT);
	printRowLine('=',COUNTLINE);
	printShiftLeft();
	printRowLine('=',COUNTLINE);
	/*Поразрядная операция инверсии */
	H_BIT_COMP;
	printf("%s\n", BIT_COMP);
	printRowLine('=',COUNTLINE);
	printComp();
	printRowLine('=',COUNTLINE);	
	/*Поразрядная операция И */
	H_BIT_AND;
	printf("%s\n", BIT_AND);
	printRowLine('=',COUNTLINE);
	printAnd();
	printRowLine('=',COUNTLINE);	
	/*Поразрядная операция ИЛИ */
	H_BIT_OR;
	printf("%s\n", BIT_OR);
	printRowLine('=',COUNTLINE);
	printOr();
	printRowLine('=',COUNTLINE);	
	/*Поразрядная операция иск ИЛИ */
	H_BIT_XOR;
	printf("%s\n", BIT_XOR);
	printRowLine('=',COUNTLINE);
	printXor();
	printRowLine('=',COUNTLINE);
}
/* Information
	*  0 - ( b & 0x80 ) --> 0101 1101 & 1000 0000 = 0
	*  b <<= 1 --> 0101 1101 << 1 = 1011 1010
	*  1 - ( b & 0x80 ) --> 1011 1010 & 1000 0000 = 1
	*  b <<= 1 --> 1011 1010 << 1 = 0111 0100
	*  2 - ( b & 0x80 ) --> 0111 0100 & 1000 0000 = 0
	*  b <<= 1 --> 0111 0100 << 1 = 1110 1000
	*  3 - ( b & 0x80 ) --> 1110 1000 & 1000 0000 = 1
	*  b <<= 1 --> 1110 1000 << 1 = 1101 0000
	*  4 - ( b & 0x80 ) --> 1101 0000 & 1000 0000 = 1
	*  b <<= 1 --> 1101 0000 << 1 = 1010 0000 
	*  5 - ( b & 0x80 ) --> 1010 0000 & 1000 0000 = 1
	*  b <<= 1 --> 1010 0000 << 1 = 0100 0000  
	*  6 - ( b & 0x80 ) --> 0100 0000 & 1000 0000 = 0 
	*  b <<= 1 --> 0100 0000 << 1 = 1000 0000   
	*  7 - ( b & 0x80 ) --> 1000 0000 & 1000 0000 = 1 
	*  b <<= 1 --> 1000 0000 << 1 = 0000 0000    
*/
void printProtocolTransmit(void)
{
	unsigned long code_1 = 5393L;
	unsigned long code_2 = 5396L;
	unsigned int length = 24;
	int nRepeatTransmit = 10;

	for ( int nRepeat = 0, countRepeat = 0; nRepeat < nRepeatTransmit; nRepeat++, countRepeat++ )
	{
		printf("=== %-3d ===\n", countRepeat);
		for ( int i = length-1; i >= 0; i--)
		{
			if (code_1 & (1L << i))
				printf("\t%3d | protocol.one__\n", i);
			else
				printf("\t%3d | protocol.zero__\n", i);
		}
		printf("\tprotocol.syncFactor__\n");
	}

}

