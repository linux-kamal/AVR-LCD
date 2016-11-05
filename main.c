#include "header.h"

int main(void)
{
	DDRD |= (1<<PD7);
	PORTD &= ~(1<<PD7);
	
	Init_Lcd();
	Init_I2C();
	
	//eeprom_write_byte ((uint8_t*) 20, 65);
	
	uint8_t byteRead = eeprom_read_byte((uint8_t*)20);
			
	Gotoxy(2,2);
	Lcd_Text("Hello");
	Gotoxy(3,1);
	Lcd_Text("SU-KAM");
	Gotoxy(8,2);
	Lcd_Integer(byteRead);
	
	while(1);
	unsigned char byte=0;
	while(1)
	{

		I2C_address_match();
		byte = I2C_read();
		Gotoxy(10,1);
		Lcd_Text(byte);
		_delay_ms(50);

	}
	return 0;
}
void delay(int ms)
{
	int i;
	for(i=0;i<ms;i++)
	_delay_us(ms);
}
/*----------------------------------------------------------*/
void Init_I2C(void)
{
	TWAR=0x20;
}
 
void I2C_address_match(void)
{
	while((TWSR & 0xF8)!= 0x60)  // Loop till correct acknoledgement have been received
	{
		//Get acknowlegement, Enable TWI, Clear TWI interrupt flag
		TWCR=(1<<TWEA)|(1<<TWEN)|(1<<TWINT); 
		while (!(TWCR & (1<<TWINT)));  // Wait for TWINT flag
	}
}

char I2C_read(void)
{
	//Clear TWI interrupt flag,Get acknowlegement, Enable TWI
	TWCR= (1<<TWINT)|(1<<TWEA)|(1<<TWEN); 
	while (!(TWCR & (1<<TWINT))); // Wait for TWINT flag
	while((TWSR & 0xF8)!=0x80); // Wait for acknowledgement
	return TWDR;
}
