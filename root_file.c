#include <lpc214x.h>

void initLCD(void);
//void enable(void);
void LCD_Write(unsigned int c);
void LCD_Cmd(unsigned int LCD_Cmd);
void delay(void);
void delay_big(void);
void vote(void);

int candA;
int candB;
int candC;
int candD;

int over = 0;

int main(void)
{

		unsigned char next_per[] = "Next Voter ==>";
    unsigned char new_leader[] = "Your New Leader:";	
		unsigned char ch1[]="Candidate A     ";
	  unsigned char ch2[]="Candidate B     ";
		unsigned char ch3[]="Candidate C     ";
	  unsigned char ch4[]="Candidate D     ";

		
	  unsigned int i;
		initLCD();
    IO1DIR &= ~(1<<16);     // explicitly making P1.16 as Input
    IO0DIR |= (1<<10);        // Configuring P0.10 as Output
		while(over == 0)
		{
				LCD_Cmd(0x01);
				//for(i=0;empty_str[i]!='\0';i++)
				//LCD_Write(empty_str[i]);
			
				vote();
				
				delay();
				delay();
				delay();
				LCD_Cmd(0x01);
				if(over==0)
				{
					for(i=0;next_per[i]!='\0';i++)
					LCD_Write(next_per[i]);				
				}
				delay();
				delay();
				delay();
		}
		

		
		LCD_Cmd(0x01);
		if(candA > candB && candA > candC && candA > candD)
		{
				for(i=0;new_leader[i]!='\0';i++)
				LCD_Write(new_leader[i]);		

				LCD_Cmd(0xc0);
			
				for(i=0;ch1[i]!='\0';i++)
				LCD_Write(ch1[i]);
		}
		else if(candB > candA && candB > candC && candB > candD)
		{
				for(i=0;new_leader[i]!='\0';i++)
				LCD_Write(new_leader[i]);		

				LCD_Cmd(0xc0);
			
				for(i=0;ch2[i]!='\0';i++)
				LCD_Write(ch2[i]);
		}
		else if(candC > candA && candC > candB && candC > candD)
		{
				for(i=0;new_leader[i]!='\0';i++)
				LCD_Write(new_leader[i]);		

				LCD_Cmd(0xc0);
			
				for(i=0;ch3[i]!='\0';i++)
				LCD_Write(ch3[i]);
		}	
		else if(candD > candA && candD > candB && candD > candC)
		{
				for(i=0;new_leader[i]!='\0';i++)
				LCD_Write(new_leader[i]);		

				LCD_Cmd(0xc0);
			
				for(i=0;ch4[i]!='\0';i++)
				LCD_Write(ch4[i]);
		}		
		delay_big();
}


void vote(void)
{
		unsigned char defmessage[] = "Pick Your Leader";
		unsigned char you_select[] = "You Selected :  ";
		unsigned char ch1[]="Candidate A     ";
	  unsigned char ch2[]="Candidate B     ";
		unsigned char ch3[]="Candidate C     ";
	  unsigned char ch4[]="Candidate D     ";
		unsigned int i;
	
		unsigned char zero[] = "0 vote          ";
		unsigned char one[] = "1 vote          ";
		unsigned char two[] = "2 votes         ";
		unsigned char three[] = "3 votes         ";
		unsigned char four[] = "4 votes         ";
		unsigned char five[] = "5 votes         ";
		unsigned char six[] = "6 votes         ";
		unsigned char seven[] = "7 votes         ";
		unsigned char eight[] = "8 votes         ";
		unsigned char nine[] = "9 votes         ";
		unsigned char ten[] = "10 votes         ";
	
		unsigned char await[]="The most awaited";
		unsigned char are_here[]="results are here";
	
		for(i=0;defmessage[i]!='\0';i++)
		LCD_Write(defmessage[i]);
	
    while(1)
		{
			if(!(IO1PIN & (1<<16))) // Evaluates to True for a 'LOW' on P1.16
			{
				candA++;
				LCD_Cmd(0x01);
				
				for(i=0;you_select[i]!='\0';i++)//aravind dmk\0
				LCD_Write(you_select[i]);
				
				LCD_Cmd(0xc0);
				
				for(i=0;ch1[i]!='\0';i++)
				LCD_Write(ch1[i]);
				delay();
				delay();
				break;
			}
			else if(!(IO1PIN & (1<<17))) // Candidate 2
			{
				candB++;
				LCD_Cmd(0x01);
				
				for(i=0;you_select[i]!='\0';i++)
				LCD_Write(you_select[i]);
				
				LCD_Cmd(0xc0);
				
				for(i=0;ch2[i]!='\0';i++)
				LCD_Write(ch2[i]);
				delay();
				delay();
				break;
			}
			
			else if(!(IO1PIN & (1<<18))) // Candidate 3
			{
				candC++;
				LCD_Cmd(0x01);
				
				for(i=0;you_select[i]!='\0';i++)
				LCD_Write(you_select[i]);
				
				LCD_Cmd(0xc0);
				
				for(i=0;ch3[i]!='\0';i++)
				LCD_Write(ch3[i]);
				delay();
				delay();
				break;
			}
			else if(!(IO1PIN & (1<<19))) // Candidate 4
			{
				candD++;
				LCD_Cmd(0x01);
				
				for(i=0;you_select[i]!='\0';i++)
				LCD_Write(you_select[i]);
				
				LCD_Cmd(0xc0);
				
				for(i=0;ch4[i]!='\0';i++)
				LCD_Write(ch4[i]);
				delay();
				delay();
				break;
			}
			else if(!(IO1PIN & (1<<20))) // Status
			{
				LCD_Cmd(0x01);
				for(i=0;await[i]!='\0';i++)
				LCD_Write(await[i]);	
		
				LCD_Cmd(0xc0);	
		
				for(i=0;are_here[i]!='\0';i++)
				LCD_Write(are_here[i]);

				delay();
				
				over = 1;
				
	
				//candidate A
				LCD_Cmd(0x01);
				for(i=0;ch1[i]!='\0';i++)
				LCD_Write(ch1[i]);				

				if(candA==1)
				{
					LCD_Cmd(0xc0);
					for(i=0;one[i]!='\0';i++)
					LCD_Write(one[i]);					
				}
				else if(candA==2)
				{
					LCD_Cmd(0xc0);
					for(i=0;two[i]!='\0';i++)
					LCD_Write(two[i]);					
				}
				else if(candA==3)
				{
					LCD_Cmd(0xc0);
					for(i=0;three[i]!='\0';i++)
					LCD_Write(three[i]);					
				}
				else if(candA==4)
				{
					LCD_Cmd(0xc0);
					for(i=0;four[i]!='\0';i++)
					LCD_Write(four[i]);					
				}
				else if(candA==5)
				{
					LCD_Cmd(0xc0);
					for(i=0;five[i]!='\0';i++)
					LCD_Write(five[i]);					
				}
				else if(candA==6)
				{
					LCD_Cmd(0xc0);
					for(i=0;six[i]!='\0';i++)
					LCD_Write(six[i]);					
				}
				else if(candA==7)
				{
					LCD_Cmd(0xc0);
					for(i=0;seven[i]!='\0';i++)
					LCD_Write(seven[i]);					
				}
				else if(candA==8)
				{
					LCD_Cmd(0xc0);
					for(i=0;eight[i]!='\0';i++)
					LCD_Write(eight[i]);					
				}
				else if(candA==9)
				{
					LCD_Cmd(0xc0);
					for(i=0;nine[i]!='\0';i++)
					LCD_Write(nine[i]);					
				}
				else if(candA==10)
				{
					LCD_Cmd(0xc0);
					for(i=0;ten[i]!='\0';i++)
					LCD_Write(ten[i]);					
				}				
				else if(candA==0)
				{
					LCD_Cmd(0xc0);
					for(i=0;zero[i]!='\0';i++)
					LCD_Write(zero[i]);
				}
				delay();
				delay();				
				
				
				//candidate B
				LCD_Cmd(0x01);
				for(i=0;ch2[i]!='\0';i++)
				LCD_Write(ch2[i]);
				
				if(candB==1)
				{
					LCD_Cmd(0xc0);
					for(i=0;one[i]!='\0';i++)
					LCD_Write(one[i]);					
				}
				else if(candB==2)
				{
					LCD_Cmd(0xc0);
					for(i=0;two[i]!='\0';i++)
					LCD_Write(two[i]);					
				}
				else if(candB==3)
				{
					LCD_Cmd(0xc0);
					for(i=0;three[i]!='\0';i++)
					LCD_Write(three[i]);					
				}
				else if(candB==4)
				{
					LCD_Cmd(0xc0);
					for(i=0;four[i]!='\0';i++)
					LCD_Write(four[i]);					
				}
				else if(candB==5)
				{
					LCD_Cmd(0xc0);
					for(i=0;five[i]!='\0';i++)
					LCD_Write(five[i]);					
				}
				else if(candB==6)
				{
					LCD_Cmd(0xc0);
					for(i=0;six[i]!='\0';i++)
					LCD_Write(six[i]);					
				}
				else if(candB==7)
				{
					LCD_Cmd(0xc0);
					for(i=0;seven[i]!='\0';i++)
					LCD_Write(seven[i]);					
				}
				else if(candB==8)
				{
					LCD_Cmd(0xc0);
					for(i=0;eight[i]!='\0';i++)
					LCD_Write(eight[i]);					
				}
				else if(candB==9)
				{
					LCD_Cmd(0xc0);
					for(i=0;nine[i]!='\0';i++)
					LCD_Write(nine[i]);					
				}
				else if(candB==10)
				{
					LCD_Cmd(0xc0);
					for(i=0;ten[i]!='\0';i++)
					LCD_Write(ten[i]);					
				}	
				else if(candB==0)
				{
					LCD_Cmd(0xc0);
					for(i=0;zero[i]!='\0';i++)
					LCD_Write(zero[i]);
				}				
				delay();
				delay();
				
				//candidate C
				LCD_Cmd(0x01);
				for(i=0;ch3[i]!='\0';i++)
				LCD_Write(ch3[i]);
				
				if(candC==1)
				{
					LCD_Cmd(0xc0);
					for(i=0;one[i]!='\0';i++)
					LCD_Write(one[i]);					
				}
				else if(candC==2)
				{
					LCD_Cmd(0xc0);
					for(i=0;two[i]!='\0';i++)
					LCD_Write(two[i]);					
				}
				else if(candC==3)
				{
					LCD_Cmd(0xc0);
					for(i=0;three[i]!='\0';i++)
					LCD_Write(three[i]);					
				}
				else if(candC==4)
				{
					LCD_Cmd(0xc0);
					for(i=0;four[i]!='\0';i++)
					LCD_Write(four[i]);					
				}
				else if(candC==5)
				{
					LCD_Cmd(0xc0);
					for(i=0;five[i]!='\0';i++)
					LCD_Write(five[i]);					
				}
				else if(candC==6)
				{
					LCD_Cmd(0xc0);
					for(i=0;six[i]!='\0';i++)
					LCD_Write(six[i]);					
				}
				else if(candC==7)
				{
					LCD_Cmd(0xc0);
					for(i=0;seven[i]!='\0';i++)
					LCD_Write(seven[i]);					
				}
				else if(candC==8)
				{
					LCD_Cmd(0xc0);
					for(i=0;eight[i]!='\0';i++)
					LCD_Write(eight[i]);					
				}
				else if(candC==9)
				{
					LCD_Cmd(0xc0);
					for(i=0;nine[i]!='\0';i++)
					LCD_Write(nine[i]);					
				}
				else if(candC==10)
				{
					LCD_Cmd(0xc0);
					for(i=0;ten[i]!='\0';i++)
					LCD_Write(ten[i]);					
				}				
				else if(candC==0)
				{
					LCD_Cmd(0xc0);
					for(i=0;zero[i]!='\0';i++)
					LCD_Write(zero[i]);
				}
				delay();
				delay();		

				//candidate D
				LCD_Cmd(0x01);
				for(i=0;ch4[i]!='\0';i++)
				LCD_Write(ch4[i]);
				
				if(candD==1)
				{
					LCD_Cmd(0xc0);
					for(i=0;one[i]!='\0';i++)
					LCD_Write(one[i]);					
				}
				else if(candD==2)
				{
					LCD_Cmd(0xc0);
					for(i=0;two[i]!='\0';i++)
					LCD_Write(two[i]);					
				}
				else if(candD==3)
				{
					LCD_Cmd(0xc0);
					for(i=0;three[i]!='\0';i++)
					LCD_Write(three[i]);					
				}
				else if(candD==4)
				{
					LCD_Cmd(0xc0);
					for(i=0;four[i]!='\0';i++)
					LCD_Write(four[i]);					
				}
				else if(candD==5)
				{
					LCD_Cmd(0xc0);
					for(i=0;five[i]!='\0';i++)
					LCD_Write(five[i]);					
				}
				else if(candD==6)
				{
					LCD_Cmd(0xc0);
					for(i=0;six[i]!='\0';i++)
					LCD_Write(six[i]);					
				}
				else if(candD==7)
				{
					LCD_Cmd(0xc0);
					for(i=0;seven[i]!='\0';i++)
					LCD_Write(seven[i]);					
				}
				else if(candD==8)
				{
					LCD_Cmd(0xc0);
					for(i=0;eight[i]!='\0';i++)
					LCD_Write(eight[i]);					
				}
				else if(candD==9)
				{
					LCD_Cmd(0xc0);
					for(i=0;nine[i]!='\0';i++)
					LCD_Write(nine[i]);					
				}
				else if(candD==10)
				{
					LCD_Cmd(0xc0);
					for(i=0;ten[i]!='\0';i++)
					LCD_Write(ten[i]);					
				}		
				else if(candD==0)
				{
					LCD_Cmd(0xc0);
					for(i=0;zero[i]!='\0';i++)
					LCD_Write(zero[i]);
				}				
				delay();
				delay();				
				break;
			}
		}	
}
void initLCD(void)
{
    IO0DIR = 0x0FFFF00;
    delay(); //Initial Delay
    LCD_Cmd(0x38);
		LCD_Cmd(0x01);
		LCD_Cmd(0x0c);
		LCD_Cmd(0x83);
		LCD_Cmd(0x80);
}

void LCD_Write(unsigned int c)
{
    IO0PIN = (c<<16)|(1<<10); 
    delay(); //Pulse Enable to process it
}
       
void LCD_Cmd(unsigned int LCD_Cmd)
{
    IO0PIN = (LCD_Cmd<<16)|(0<<10);
    delay(); //Pulse Enable to process it
}

void delay(void)
{
    int i=0,x=0;
	  IO0PIN|=(1<<13);
    for(i=0; i<19999; i++)
    { 
			x++; 
		}
			IO0PIN&=~(1<<13);
}

void delay_big(void)
{
	int i;
	for(i=0;i<100000000;i++);
}
