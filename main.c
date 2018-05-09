

sbit LCD_RS at Rc5_bit;
sbit LCD_EN at Rc6_bit;
sbit LCD_D4 at Rc1_bit;
sbit LCD_D5 at Rc2_bit;
sbit LCD_D6 at Rc3_bit;
sbit LCD_D7 at Rc4_bit;

sbit LCD_RS_Direction at TRISc5_bit;
sbit LCD_EN_Direction at TRISc6_bit;
sbit LCD_D4_Direction at TRISc1_bit;
sbit LCD_D5_Direction at TRIsc2_bit;
sbit LCD_D6_Direction at TRISc3_bit;
sbit LCD_D7_Direction at TRISc4_bit;

char  keypadPort at PORTB;
  int counter=0;

int i;




char password[4] = {0};
char wrong [] = "Pass Is Wrong ";
char pass [] = "Enter Password :";

char wrong1[]="you are not";
char wrong2[]=  "*Admin*" ;
char user3 []=   " Plz Enter  ID : "  ;
char wel[]="Wlcome" ;
char emp []="Employee" ;
char nice []="Nice day for you " ;
char incor []="Not permitted";

  int count =0;

char get_password()
{
while (1)
{
Lcd_Cmd(_LCD_CLEAR);
   Lcd_Out(1, 1, pass);
   while(1)
   {
     for(i=0;i<3;i++)
     {
           while (password[i] == 0)
           {
            password[i] = Keypad_Key_Click();
           }

          if(password[i]==1)     password[i]  = '7';
          if(password[i]==2)     password[i]  = '8';
          if(password[i]==3)     password[i]  = '9';
          if(password[i]==5)     password[i]  = '4';
          if(password[i]==6)     password[i]  = '5';
          if(password[i]==7)     password[i]  = '6';
          if(password[i]==9)     password[i]  = '1';
          if(password[i]==10)    password[i]  = '2';
          if(password[i]==11)    password[i]  = '3';
          Lcd_Chr(2, i+1,'*');
      }
    if(strcmp(password,"111") == 0)
     { return 1;}
    else
      {


            counter++;
      password[0]=0  ;
      password[1]=0  ;
      password[2]=0  ;
      password[3]=0  ;
      Lcd_Cmd(_LCD_CLEAR);
      Lcd_Out(1, 1, wrong);
      delay_ms(2000);
       Lcd_Cmd(_LCD_CLEAR);
         Lcd_Out(1, 1, pass);
                    if(counter==3){
           Lcd_Cmd(_LCD_CLEAR);
           Lcd_out(1, 4,wrong1);
            Lcd_out(2, 7,wrong2);
            delay_ms(3000);
        Lcd_Cmd(_LCD_CLEAR);
         Lcd_Out(1, 1, pass);
    }
             }
    }
      }       }

 char get_password_id()
{ int j ;   j=0;
   while (1)
   {     for( j=0;j<3 ; j++)
   {
   Lcd_Cmd(_LCD_CLEAR);
   Lcd_Out(1, 1, user3);

     for(i=0;i<3;i++)
     {
           while (password[i] == 0)
           {
            password[i] = Keypad_Key_Click();
           }

          if(password[i]==1)     password[i]  = '7';
          if(password[i]==2)     password[i]  = '8';
          if(password[i]==3)     password[i]  = '9';
          if(password[i]==5)     password[i]  = '4';
          if(password[i]==6)     password[i]  = '5';
          if(password[i]==7)     password[i]  = '6';
          if(password[i]==9)     password[i]  = '1';
          if(password[i]==10)    password[i]  = '2';
          if(password[i]==11)    password[i]  = '3';
          Lcd_Chr(2, i+1,'*');
      }
    lcd_cmd (_lcd_clear);
    lcd_out(1,1,"welcome user");
    
    if(strcmp(password,"222") == 0) {
    lcd_chr(1,14,'1');
    delay_ms(2000);
    return 1;}
    
 if(strcmp(password,"333") == 0) {
    lcd_chr(1,14,'2');
    delay_ms(2000);
    return 1;}

      if(strcmp(password,"444") == 0) {
    lcd_chr(1,14,'3');
    delay_ms(2000);
    return 1;}

     if(strcmp(password,"999") == 0) {
    lcd_chr(1,14,'9');
    delay_ms(2000);
    return 1;}


    else
      {
       count++;
      password[i] = Keypad_Key_Click();
      password[0]=0  ;
      password[1]=0  ;
      password[2]=0  ;
      password[3]=0  ;
     Lcd_Cmd(_LCD_CLEAR);
  Lcd_Out(1, 1, incor);
  delay_ms(3000);
  Lcd_Cmd(_LCD_CLEAR);
if(count==3){
           Lcd_Cmd(_LCD_CLEAR);
           Lcd_out(1, 4,"you are not");
            Lcd_out(2, 7,"*user*");
            delay_ms(3000);
            return 1;
                     }

               }    
                   }

           }

             }


void main()
{
     password[0]=0  ;
      password[1]=0  ;
      password[2]=0  ;
      password[3]=0  ;
    trisc.b0=0;    portc.b0=0;
    Lcd_Init();    keypad_Init();
    Lcd_Cmd(_LCD_CURSOR_OFF);

        while (1)
        {
    lcd_cmd (_lcd_clear);
    get_password();
    lcd_cmd (_lcd_clear);
    lcd_out(1,1,wel);
    delay_ms(1000);
    Lcd_Out(2,3 , emp);
    delay_ms(2000);
    lcd_cmd (_lcd_clear);
    delay_ms(2000);
      password[0]=0  ;
      password[1]=0  ;
      password[2]=0  ;
      password[3]=0  ;
    get_password_id() ;
       delay_ms(1000);
    lcd_cmd (_lcd_clear);
    delay_ms(1000);

    lcd_cmd (_lcd_clear);
     password[0]=0  ;
      password[1]=0  ;
      password[2]=0  ;
      password[3]=0  ;
          }

    }
