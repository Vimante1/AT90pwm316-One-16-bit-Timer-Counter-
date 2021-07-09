/*
 * One Timer-Counter 16Bit Udovychenko.c
 *
 * Author : BOSS
 */ 

#include <avr/io.h>
#include "avr/interrupt.h"
#define F_CPU 1000000UL // Setting the frequency 
int Value; //Variable for value 
int Mod; //Variable for mod
int main(void)
{
	
  while (1) 
    {
		
    }
}
void Initialization()//Init function
{
	
	sei(); // Interrupt handlers call
	
}
	
void Start()//Starting timer/counter
{
	TCCR1B |= ((1<<CS10)|(1<<CS12));
}
void Stop()//Stopping the timer/counter
{
	TCCR1B = 0b00000000;
}

ISR(TIMER1_COMPA_vect)
{
	Value++;
	if (Value>=1000)
	{
		Value=0;
	}
}

int Get_Value()
{
	return Value;
}

void Set_Value(int Set)
{
	 Value = Set;
}
int Get_Mode()
{
	return Mod;
}
void Set_Mode(int Set)
{
	Set == 1 ? (Mod = 1):(Mod = 0);
}

void Clear() //Clear register
{
	TCNT1H = 0;
	TCNT1L = 0;
}
