#include <dos.h>
#define INIT_T2 0xb6
#define PORT_T2 0x42
#define CTRL_T 0x43
#define PORT_PB 0x61
#define INIT_1 0x11ca
#define INIT_2 0xfda
#define INIT_3 0xe1f
#define INIT_4 0xd5a
#define INIT_5 0xbe3
#define INIT_6 0xa97
#define INIT_7 0x96f
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
	int i=0;
	int song[200]={ 3,2,3,2,3,5,5,5,0,0,0,5,1,2,2,1,1,0,0,0,1,
					1,2,3,1,1,0,6,1,2,3,1,1,0,6,2,3,3,0,0,0,0,0,5,
					3,2,3,2,3,5,5,5,0,0,0,5,1,2,2,1,1,0,0,0,1,
					2,2,3,1,1,0,6,2,2,3,1,1,0,6,5,3,3,3,5,5,0,5,3,2,
					1,1,1,1,6,5,5,6,6,6,1,2,3,5,5,5,1,2,2,0,1,0,
					0,1,1,1,1,6,5,5,6,6,6,1,2,3,5,5,5,3,2,2,0,3,2,1,
					1,1,1,1,6,5,5,6,6,6,1,1,2,3,5,5,5,1,2,2,0,0,2,3,1,
					1,1,1,1,6,5,6,6,6,1,2,3,5,5,5,3,2,2,0,0,0};
	int Tone[7]={INIT_1,INIT_2,INIT_3,INIT_4,INIT_5,INIT_6,INIT_7};
	for(i=0;i<180;i++)
		if(song[i]==0)
			delay(50);
		else
			sing(Tone[song[i]-1],250);	
}