#include<avr/io.h>
#include<util/delay.h>
#include<avr/eeprom.h>
#include<stdio.h>
#include<avr/fuse.h>

#include "lcd.h"

#define DATA_PORT	PORTA
#define RS	PORTA
#define EN	PORTA

void delay(int);

void Init_I2C(void);
void I2C_address_match(void);
char I2C_read(void);

