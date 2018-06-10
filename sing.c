#include <dos.h>
#define INIT_T2 0xb6
#define PORT_T2 0x42
#define CTRL_T 0x43
#define PORT_PB 0x61

#define INIT_1L 0x11ca
#define INIT_2L 0xfda
#define INIT_3L 0xe1f
#define INIT_4L 0xd5a
#define INIT_5L 0xbe3
#define INIT_6L 0xa97
#define INIT_7L 0x96f

#define INIT_1 0x8e9
#define INIT_2 0x7f0
#define INIT_3 0x712
#define INIT_4 0x6ad
#define INIT_5 0x5f1
#define INIT_6 0x54b
#define INIT_7 0x4b7

#define INIT_1H 0x474
#define INIT_2H 0x3f7
#define INIT_3H 0x389
#define INIT_4H 0x356
#define INIT_5H 0x2f8
#define INIT_6H 0x2a5
#define INIT_7H 0x25b
void sing(unsigned int frq,unsigned int ms)
{
	unsigned char value;
	union
	{
		unsigned int divisor;
		unsigned char d[2];
	}tone;
	tone.divisor=frq;
	outportb(CTRL_T,INIT_T2);
	outportb(PORT_T2,tone.d[0]);
	outportb(PORT_T2,tone.d[1]);
	value=inportb(PORT_PB);
	outportb(PORT_PB,(value|0x03));
	delay(ms);
	outportb(PORT_PB,(value&0xfc));
}
void main()
{
	sing(INIT_3,300);
	sing(INIT_2,300);
	sing(INIT_3,300);
	sing(INIT_2,300);
	sing(INIT_3,300);
	sing(INIT_5,300);
	sing(INIT_5,500);
	
	sing(INIT_5,500);
	sing(INIT_5L,300);
	
	sing(INIT_1,400);
	sing(INIT_2,300);
	sing(INIT_2,500);
	sing(INIT_1,300);
	
	sing(INIT_1,500);
	sing(INIT_1,300);
	
	sing(INIT_1,300);
	sing(INIT_2,300);
	sing(INIT_3,300);
	sing(INIT_1,300);
	sing(INIT_1,500);
	sing(INIT_6L,300);
	
	sing(INIT_1,300);
	sing(INIT_2,300);
	sing(INIT_3,300);
	sing(INIT_1,300);
	sing(INIT_1,500);
	sing(INIT_6L,300);
	
	sing(INIT_2,900);
	sing(INIT_3,300);
	sing(INIT_3,900);
	
	sing(INIT_5L,300);
	
	sing(INIT_3,300);
	sing(INIT_2,300);
	sing(INIT_3,300);
	sing(INIT_2,300);
	sing(INIT_3,300);
	sing(INIT_5,300);
	sing(INIT_5,500);
	
	sing(INIT_5,500);
	sing(INIT_5L,300);
	
	sing(INIT_1,400);
	sing(INIT_2,300);
	sing(INIT_2,500);
	sing(INIT_1,300);
	
	sing(INIT_1,500);
	sing(INIT_1,300);
	
	sing(INIT_1,300);
	sing(INIT_2,300);
	sing(INIT_3,300);
	sing(INIT_1,300);
	sing(INIT_1,500);
	sing(INIT_6L,300);
	
	sing(INIT_2,300);
	sing(INIT_2,300);
	sing(INIT_3,300);
	sing(INIT_1,300);
	sing(INIT_1,500);
	sing(INIT_6L,300);
	
	sing(INIT_5,500);
	sing(INIT_3,300);
	sing(INIT_3,500);
	sing(INIT_3,300);
	sing(INIT_4,300);
	
	sing(INIT_5,900);
	sing(INIT_5,300);
	sing(INIT_3H,300);
	sing(INIT_2H,500);
	
	sing(INIT_1H,500);
	sing(INIT_1H,500);
	sing(INIT_1H,300);
	sing(INIT_1H,300);
	sing(INIT_6,300);
	sing(INIT_5,300);
	
	sing(INIT_5H,300);
	sing(INIT_6H,500);
	sing(INIT_6H,300);
	sing(INIT_6H,500);
	sing(INIT_1H,300);
	sing(INIT_2H,300);
	
	sing(INIT_3H,300);
	sing(INIT_5H,500);
	sing(INIT_5H,300);
	sing(INIT_5H,300);
	sing(INIT_5H,300);
	sing(INIT_1H,500);
	sing(INIT_2H,300);
	
	sing(INIT_2H,500);
	sing(INIT_1H,500);
	
	sing(INIT_1H,500);
	sing(INIT_1H,500);
	sing(INIT_1H,300);
	sing(INIT_1H,300);
	sing(INIT_6,300);
	sing(INIT_5,300);
	
	sing(INIT_5H,300);
	sing(INIT_6H,500);
	sing(INIT_6H,300);
	sing(INIT_6H,500);
	sing(INIT_1H,300);
	sing(INIT_2H,300);
	
	sing(INIT_3H,300);
	sing(INIT_5H,500);
	sing(INIT_5H,300);
	sing(INIT_5H,300);
	sing(INIT_5H,300);
	sing(INIT_3H,500);
	sing(INIT_2H,300);
	
	sing(INIT_2H,900);
	sing(INIT_3H,300);
	sing(INIT_2H,500);
	sing(INIT_1H,300);
	
	sing(INIT_1H,500);
	sing(INIT_1H,500);
	sing(INIT_1H,300);
	sing(INIT_1H,300);
	sing(INIT_6,300);
	sing(INIT_5,300);
	
	sing(INIT_5H,300);
	sing(INIT_6H,500);
	sing(INIT_6H,300);
	sing(INIT_6H,500);
	sing(INIT_1H,300);
	sing(INIT_2H,300);
	
	sing(INIT_3H,300);
	sing(INIT_5H,500);
	sing(INIT_5H,300);
	sing(INIT_5H,300);
	sing(INIT_5H,300);
	sing(INIT_1H,500);
	sing(INIT_2H,300);
	
	sing(INIT_2H,500);
	sing(INIT_2H,300);
	sing(INIT_3H,300);
	sing(INIT_1H,300);
	
	sing(INIT_1H,500);
	sing(INIT_1H,500);
	sing(INIT_1H,300);
	sing(INIT_1H,300);
	sing(INIT_6,300);
	sing(INIT_5,300);
	
	sing(INIT_5H,300);
	sing(INIT_6H,500);
	sing(INIT_6H,300);
	sing(INIT_6H,500);
	sing(INIT_1H,300);
	sing(INIT_2H,300);
	
	sing(INIT_3H,300);
	sing(INIT_5H,500);
	sing(INIT_5H,300);
	sing(INIT_5H,300);
	sing(INIT_5H,300);
	sing(INIT_1H,500);
	sing(INIT_2H,300);
	sing(INIT_2H,500);
	
	sing(INIT_1H,500);
	sing(INIT_2H,500);
	sing(INIT_3H,500);
	sing(INIT_1H,500);
	sing(INIT_2H,500);
	sing(INIT_3H,500);
	sing(INIT_5H,500);
	sing(INIT_1H,500);
	sing(INIT_2H,500);
	sing(INIT_3H,500);
	sing(INIT_1H,500);
	sing(INIT_2H,500);
	sing(INIT_3H,500);
	sing(INIT_5H,500);
	
	sing(INIT_3,300);
	sing(INIT_2,300);
	sing(INIT_3,300);
	sing(INIT_2,300);
	sing(INIT_3,300);
	sing(INIT_5,300);
	sing(INIT_5,500);
	
	sing(INIT_5,500);
	sing(INIT_5L,300);
	
	sing(INIT_1,400);
	sing(INIT_2,300);
	sing(INIT_2,500);
	sing(INIT_1,300);
	
	sing(INIT_1,500);
	sing(INIT_1,300);
	
	sing(INIT_1,300);
	sing(INIT_2,300);
	sing(INIT_3,300);
	sing(INIT_1,300);
	sing(INIT_1,500);
	sing(INIT_6L,300);
	
	sing(INIT_1,300);
	sing(INIT_2,300);
	sing(INIT_3,300);
	sing(INIT_1,300);
	sing(INIT_1,500);
	sing(INIT_6L,300);
	
	sing(INIT_2,900);
	sing(INIT_3,300);
	sing(INIT_3,900);
	
	sing(INIT_5L,300);
	
	sing(INIT_3,300);
	sing(INIT_2,300);
	sing(INIT_3,300);
	sing(INIT_2,300);
	sing(INIT_3,300);
	sing(INIT_5,300);
	sing(INIT_5,500);
	
	sing(INIT_5,500);
	sing(INIT_5L,300);
	
	sing(INIT_1,400);
	sing(INIT_2,300);
	sing(INIT_2,500);
	sing(INIT_1,300);
	
	sing(INIT_1,500);
	sing(INIT_1,300);
	
	sing(INIT_1,300);
	sing(INIT_2,300);
	sing(INIT_3,300);
	sing(INIT_1,300);
	sing(INIT_1,500);
	sing(INIT_6L,300);
	
	sing(INIT_2,300);
	sing(INIT_2,300);
	sing(INIT_3,300);
	sing(INIT_1,300);
	sing(INIT_1,500);
	sing(INIT_6L,300);
	
	sing(INIT_5,500);
	sing(INIT_3,300);
	sing(INIT_3,500);
	sing(INIT_3,300);
	sing(INIT_4,300);
	
	sing(INIT_5,900);
	sing(INIT_5,300);
	sing(INIT_3H,300);
	sing(INIT_2H,500);
	
	sing(INIT_1H,500);
	sing(INIT_1H,500);
	sing(INIT_1H,300);
	sing(INIT_1H,300);
	sing(INIT_6,300);
	sing(INIT_5,300);
	
	sing(INIT_5H,300);
	sing(INIT_6H,500);
	sing(INIT_6H,300);
	sing(INIT_6H,500);
	sing(INIT_1H,300);
	sing(INIT_2H,300);
	
	sing(INIT_3H,300);
	sing(INIT_5H,500);
	sing(INIT_5H,300);
	sing(INIT_5H,300);
	sing(INIT_5H,300);
	sing(INIT_1H,500);
	sing(INIT_2H,300);
	
	sing(INIT_2H,500);
	sing(INIT_1H,500);
	
	sing(INIT_1H,500);
	sing(INIT_1H,500);
	sing(INIT_1H,300);
	sing(INIT_1H,300);
	sing(INIT_6,300);
	sing(INIT_5,300);
	
	sing(INIT_5H,300);
	sing(INIT_6H,500);
	sing(INIT_6H,300);
	sing(INIT_6H,500);
	sing(INIT_1H,300);
	sing(INIT_2H,300);
	
	sing(INIT_3H,300);
	sing(INIT_5H,500);
	sing(INIT_5H,300);
	sing(INIT_5H,300);
	sing(INIT_5H,300);
	sing(INIT_3H,500);
	sing(INIT_2H,300);
	
	sing(INIT_2H,900);
	sing(INIT_3H,300);
	sing(INIT_2H,500);
	sing(INIT_1H,300);
	
	sing(INIT_1H,500);
	sing(INIT_1H,500);
	sing(INIT_1H,300);
	sing(INIT_1H,300);
	sing(INIT_6,300);
	sing(INIT_5,300);
	
	sing(INIT_5H,300);
	sing(INIT_6H,500);
	sing(INIT_6H,300);
	sing(INIT_6H,500);
	sing(INIT_1H,300);
	sing(INIT_2H,300);
	
	sing(INIT_3H,300);
	sing(INIT_5H,500);
	sing(INIT_5H,300);
	sing(INIT_5H,300);
	sing(INIT_5H,300);
	sing(INIT_1H,500);
	sing(INIT_2H,300);
	
	sing(INIT_2H,500);
	sing(INIT_2H,300);
	sing(INIT_3H,300);
	sing(INIT_1H,300);
	
	sing(INIT_1H,500);
	sing(INIT_1H,500);
	sing(INIT_1H,300);
	sing(INIT_1H,300);
	sing(INIT_6,300);
	sing(INIT_5,300);
	
	sing(INIT_5H,300);
	sing(INIT_6H,500);
	sing(INIT_6H,300);
	sing(INIT_6H,500);
	sing(INIT_1H,300);
	sing(INIT_2H,300);
	
	sing(INIT_3H,300);
	sing(INIT_5H,500);
	sing(INIT_5H,300);
	sing(INIT_5H,300);
	sing(INIT_5H,300);
	sing(INIT_1H,500);
	sing(INIT_2H,300);
	sing(INIT_2H,500);
	
	sing(INIT_5,300);
	sing(INIT_3H,300);
	sing(INIT_2H,500);
	sing(INIT_1H,500);
	sing(INIT_1H,500);
	sing(INIT_1H,300);
	sing(INIT_1H,300);
	sing(INIT_6,300);
	sing(INIT_5,300);
	
	sing(INIT_5H,300);
	sing(INIT_6H,500);
	sing(INIT_6H,300);
	sing(INIT_6H,500);
	sing(INIT_1H,300);
	sing(INIT_2H,300);
	
	sing(INIT_3H,300);
	sing(INIT_5H,500);
	sing(INIT_5H,300);
	sing(INIT_5H,300);
	sing(INIT_5H,300);
	sing(INIT_3H,500);
	sing(INIT_2H,300);
	
	sing(INIT_2H,900);
	sing(INIT_3H,300);
	sing(INIT_2H,500);
	sing(INIT_1H,300);
	
	sing(INIT_1H,500);
	sing(INIT_1H,500);
	sing(INIT_1H,300);
	sing(INIT_1H,300);
	sing(INIT_6,300);
	sing(INIT_5,300);
	
	sing(INIT_5H,300);
	sing(INIT_6H,500);
	sing(INIT_6H,300);
	sing(INIT_6H,500);
	sing(INIT_1H,300);
	sing(INIT_2H,300);
	
	sing(INIT_3H,300);
	sing(INIT_5H,500);
	sing(INIT_5H,300);
	sing(INIT_5H,300);
	sing(INIT_5H,300);
	sing(INIT_1H,500);
	sing(INIT_2H,300);
	
	sing(INIT_2H,500);
	sing(INIT_2H,300);
	sing(INIT_3H,300);
	sing(INIT_1H,300);
	
	sing(INIT_1H,500);
	sing(INIT_1H,500);
	sing(INIT_1H,300);
	sing(INIT_1H,300);
	sing(INIT_6,300);
	sing(INIT_5,300);
	
	sing(INIT_5H,300);
	sing(INIT_6H,500);
	sing(INIT_6H,300);
	sing(INIT_6H,500);
	sing(INIT_1H,300);
	sing(INIT_2H,300);
	
	sing(INIT_3H,300);
	sing(INIT_5H,500);
	sing(INIT_5H,300);
	sing(INIT_5H,300);
	sing(INIT_5H,300);
	sing(INIT_1H,500);
	sing(INIT_2H,300);
	sing(INIT_2H,500);
	
	sing(INIT_3,300);
	sing(INIT_2,300);
	sing(INIT_3,300);
	sing(INIT_2,300);
	sing(INIT_3,300);
	sing(INIT_5,300);
	sing(INIT_5,500);
	
	sing(INIT_5,500);
	sing(INIT_5L,300);
	
	sing(INIT_1,400);
	sing(INIT_2,300);
	sing(INIT_2,500);
	sing(INIT_1,300);
	
	sing(INIT_1,500);
	sing(INIT_1,300);
	
	sing(INIT_1,300);
	sing(INIT_2,300);
	sing(INIT_3,300);
	sing(INIT_1,300);
	sing(INIT_1,500);
	sing(INIT_6L,300);
	
	sing(INIT_1,300);
	sing(INIT_2,300);
	sing(INIT_3,300);
	sing(INIT_1,300);
	sing(INIT_1,500);
	sing(INIT_6L,300);
	
	sing(INIT_2,900);
	sing(INIT_3,300);
	sing(INIT_3,900);
	
}