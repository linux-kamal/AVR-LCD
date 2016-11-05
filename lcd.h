#ifndef LCD_H
#define	LCD_H
#endif

void Init_Lcd(void);
void send_cmd(unsigned char);
void send_data(unsigned char);
void Lcd_Text(char*);
void Lcd_Integer(unsigned long int);
int Gotoxy(int, int);
