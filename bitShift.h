#ifndef _bitShift_h
#define _bitShift_h
#include <inttypes.h>
#include <string.h>

#define SPACE ' '
#define COUNTLINE 140

#define BIT_COMP 		 "| (~) Побитовая инверсия |"
#define BIT_AND 		 "| (&) Побитовая И |"
#define BIT_OR 		 	 "| (|) Побитовая ИЛИ |"
#define BIT_XOR 		 "| (^) Побитовая Иск ИЛИ |"
#define BIT_SHIFT_LEFT   "| ( n << номер_разряда ) Побитовая сдвиг влево |"
#define BIT_SHIFT_RIGHT  "| ( n >> номер_разряда ) Побитовая сдвиг вправо |"
#define ASCI             "| Таблица кодировки ASCI |"

/*strlen(cirilica) one char - 2byte ==> (strlen return: len*2)*/
#define	H_ASCI 				spaceHead(SPACE, (COUNTLINE - (strlen(ASCI)/2))/2)
#define	H_BIT_SHIFT_RIGHT 	spaceHead(SPACE, (COUNTLINE - (strlen(BIT_SHIFT_RIGHT)/2))/2)
#define	H_BIT_SHIFT_LEFT 	spaceHead(SPACE, (COUNTLINE - (strlen(BIT_SHIFT_LEFT)/2))/2)
#define	H_BIT_XOR 			spaceHead(SPACE, (COUNTLINE - (strlen(BIT_XOR)/2))/2)
#define	H_BIT_OR 			spaceHead(SPACE, (COUNTLINE - (strlen(BIT_OR)/2))/2)
#define	H_BIT_AND 			spaceHead(SPACE, (COUNTLINE - (strlen(BIT_AND)/2))/2)
#define	H_BIT_COMP 			spaceHead(SPACE, (COUNTLINE - (strlen(BIT_COMP)/2))/2)


void printBit(uint8_t a);
void printASCI(void);
void printShiftLeft(void);
void printShiftRight(void);
void printRowLine(char a, int count);
void printProtocolTransmit(void);
void printComp(void);
void printAnd(void);
void printOr(void);
void printXor(void);
void spaceHead(char s, int count);
void printAll(void);

#endif