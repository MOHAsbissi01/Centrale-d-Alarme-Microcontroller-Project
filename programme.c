         tempo1();
           void tempo1(void) {
           int ii;
           option_reg=0X85;
           for(ii=0;ii<=4;ii++){
   TMR0=100;
   INTCON.T0IF=0;
      while(INTCON.T0IF==0);}}
        tempo();
           void tempo(void) {

           option_reg=0X85;

   TMR0=100;
   INTCON.T0IF=0;
      while(INTCON.T0IF==0);}
sbit LCD_RS at RD0_bit;
sbit LCD_EN at RD1_bit;
sbit LCD_D4 at RD2_bit;
sbit LCD_D5 at RD3_bit;
sbit LCD_D6 at RD4_bit;
sbit LCD_D7 at RD5_bit;

sbit LCD_RS_Direction at TRISD0_bit;
sbit LCD_EN_Direction at TRISD1_bit;
sbit LCD_D4_Direction at TRISD2_bit;
sbit LCD_D5_Direction at TRISD3_bit;
sbit LCD_D6_Direction at TRISD4_bit;
sbit LCD_D7_Direction at TRISD5_bit;
// End LCD module connections
char txt1[] = "Hello Word";
char txt2[] = "a la banque";
  unsigned int total[4]={1,2,3,4},i,kp,j,col1=0,col2=0,col3=0;
int  anti1=0,anti2=0;
int a=0,b=0,cx=0,P01=0,P02=0,P03=0,P04=0;
 int p0XI , p1XI ,  p2XI , p3XI ;
  int cod;
  unsigned    obj=0;
int x=0,p0=0,p1=0,p2=0,p3=0;
  char read_keypad(){
  kp = 0;
  PORTC=0b00010000;
  if(INTCON.RBIF){
 if(col1!=0)
  { kp=49;
  col1=0;
  }
else  if(col2!=0)
  { kp=50;
  col2=0;
  }
  else  if(col3!=0)
  { kp=51;
  col3=0;
  }
     }
      tempo1();
      PORTC=0b00100000;
               if(INTCON.RBIF){
            if(col1!=0)
  {  kp=52;
  col1=0;
  }
 else if(col2!=0)
  {  kp=53;
  col2=0;
  }
  else  if(col3!=0)
  { kp=54;
  col3=0;
  }
        }
     tempo1();
      PORTC=0b01000000;
          if(INTCON.RBIF){
            if(col1!=0)
  { kp=55;
  col1=0;
  }
 else if(col2!=0)
  { kp=56;
  col2=0;
  }
  else  if(col3!=0)
  { kp=57;
  col3=0;
  }
     }
     tempo1();
      PORTC=0b10000000;
          if(INTCON.RBIF){
            if(col1!=0)
  { kp=42;
  col1=0;
  }
 else if(col2!=0)
  { kp=48;
  col2=0;
  }
 else   if(col3!=0)
  { kp=35;
  col3=0;
  }
      }
     tempo1();

      return(kp);

  }
   saisiecode ();
    int   saisiecode (){
    int il=0,x;
    char txt2[]="Entrer le code:";
     char txt4[]="code Errone";
   char txt5[]="code accepte";
    kp=0 ;  i=0 ; obj=0 ; p0=0 ; p1=0 ;  p2=0 ; p3=0 ;
    Lcd_Cmd(_LCD_CLEAR);

  Lcd_Out(1,1,txt2);              // Cursor off
  i=0;
   P01= EEPROM_Read(0x50);               // Write some data at address 0150
   tempo();
 P02= EEPROM_Read(0x51);
         tempo();
  P03=EEPROM_Read(0x52);
      tempo();
  P04=EEPROM_Read(0x53);
      cod=P01*1000+P02*100+P03*10+P04;
  for( il=0;il <=50; il++)
         {
     kp=0 ;

      kp=read_keypad() ;             // Store key code in kp variable

    if (kp!=0)
          {
          Lcd_Out(1,1,txt2);
        if(i==0)  {
        p0=kp-48;
         Lcd_Chr(2,4+i,kp);
         for(x=0;x <50;x++){
       tempo();
             }
         kp=0 ;
        Lcd_Chr(2,4+i,'*');
        for(x=0;x <50;x++){
       tempo();
             }
             i++;
         goto suina;
        //txt[i]=   kp;
        }
       if(i==1)  {p1=kp-48;
        Lcd_Chr(2,4+i,kp);
         for(x=0;x <50;x++){
       tempo();
             }

        Lcd_Chr(2,4+i,'*');
        for(x=0;x <50;x++){
       tempo();
             }
             i++;
             kp=0 ;
        goto suina;
//txt[i]=   kp;
       }
       if(i==2)  {p2=kp-48;

        Lcd_Chr(2,4+i,kp);
         for(x=0;x <50;x++){
       tempo();
             }
        Lcd_Chr(2,4+i,'*');
        for(x=0;x <50;x++){
       tempo();
             }
             i++;
             kp=0 ;
        goto suina;
       //txt[i]=   kp;
       }
       if(i==3)  {
       p3=kp-48;
         Lcd_Chr(2,4+i,kp);
         for(x=0;x <50;x++){
       tempo();
             }
        Lcd_Chr(2,4+i,'*');
        for(x=0;x <50;x++){
       tempo();
             }
             kp=0 ;
        i++;
          goto comp;
       //txt[i]=   kp;
       }



       }
      if (kp==0)  {
           goto suina;  }

         comp:
        obj=p0*1000+p1*100+p2*10+p3;

             if (obj!=cod)
    {                    portc=0X02;
       Lcd_Out(1,1,txt4);
       for(x=0;x <50;x++){
       tempo();
             }
       i=0;

               Lcd_Cmd(_LCD_CLEAR);

                  goto  suina;
    }
         if (obj==cod)
    {
              portc=0X04;
       Lcd_Out(1,1,txt5);
                   Delay_ms(1500);
          portc=0;
          anti2=0;
            anti1=0;
        return;
    }
      suina:
      tempo();
      }
       portc=0X01;
          Delay_ms(1500);
          portc=0;
          anti2=0;
            anti1=0;
      return;
    }

int   alarme (){

 char txt1x[] = "danger";
 char txt2x[] = "anti-intrusion 1";
 char txt3x[] = "anti-intrusion 2";

 Lcd_Cmd(_LCD_CLEAR);
 if(anti1!=0)
          {
           Lcd_Cmd(_LCD_CLEAR);
          Lcd_Out(1,4,txt1x);
  Lcd_Out(2,1,txt2x);
          PORTC=0x04;
          saisiecode();
          anti1=0;
       }
        if(anti2!=0)
          {
          PORTC=0x09;
  Lcd_Out(1,4,txt1x);
  Lcd_Out(2,1,txt3x);
            saisiecode ();
            anti2=0;

       } 
       return(0);}
       
       
     int ij,objX;
     int p0X , p1X ,  p2X , p3X ;
    int    saisie4  (){

            kp=0  ; p0X=0 ; p1X=0 ;  p2X=0 ; p3X=0 ;

         ij=0;
while(ij<4)
      {
      lab:
      kp=0;
      kp=read_keypad() ;             // Store key code in kp variable
       if (kp==0)
          {  goto lab;}
    if (kp!=0)
          {
        if(ij==0)  {
        p0X=kp-48;
        Lcd_Chr(2,4+ij,kp);
                  delay_ms(200);
         Lcd_Chr(2,4+ij,'*');
         
          kp=0 ;
          ij++;
          goto lab;
        }
       if(ij==1) 
        {
        p1X=kp-48;
       Lcd_Chr(2,4+ij,kp);
                  delay_ms(200);
         Lcd_Chr(2,4+ij,'*');
          kp=0 ;
          ij++;
          goto lab;
       }
       if(ij==2)  {
       p2X=kp-48;
       Lcd_Chr(2,4+ij,kp);
                  delay_ms(200);
         Lcd_Chr(2,4+ij,'*');
          kp=0 ;
          ij++;
          goto lab;
       }
       if(ij==3)  {
       p3X=kp-48;
       Lcd_Chr(2,4+ij,kp);
                  delay_ms(200);
         Lcd_Chr(2,4+ij,'*');
         delay_ms(100);
          kp=0 ;
          ij++;
         break ;
       }
       }


      return(0);

     }
          }
          
          
           int code1=0,code2=0;
           

           
           


          
      int    modification  (){
                   char txt1y[] = "Entrer le code:";
                char txt4y[]="code Errone";
   char txt5y[]="code accepte";
  char txt6y[]=" nouveau code ";
   char txt7y[]=" ressaisie code ";
   char txt[6];
              int ij,code1=0,code2=0,objX=0;
              PORTC=0b10000000;
               if(col3==0)
  {return(0);}
   if(col3!=0)
  {
       col3=0;
      Lcd_Cmd(_LCD_CLEAR);
          Lcd_Out(1,1,txt1y);
          delay_ms(500);
            saisie4();
           objX=p0X*1000+p1X*100+p2X*10+p3X;
           P01= EEPROM_Read(0x50);               // Write some data at address 0150
tempo();
 P02= EEPROM_Read(0x51);
 tempo();
  P03=EEPROM_Read(0x52);
  tempo();
  P04=EEPROM_Read(0x53);
  tempo();
  cod=P01*1000+P02*100+P03*10+P04;
            if (objX==cod) {
         Lcd_Cmd(_LCD_CLEAR);
          Lcd_Out(1,1,txt5y);
          PORTC=0X04;
          delay_ms(1000);
          Lcd_Cmd(_LCD_CLEAR);
          Lcd_Out(1,1,txt6y);
                    saisie4();
                    code1=p0X*1000+p1X*100+p2X*10+p3X;

               Lcd_Cmd(_LCD_CLEAR);
          Lcd_Out(1,1,txt7y);
          delay_ms(1000);
          saisie4();
                    code2=p0X*1000+p1X*100+p2X*10+p3X;

               if( code1==code2){
                       Lcd_Cmd(_LCD_CLEAR);
          Lcd_Out(1,1,txt5y);
               PORTC=0X04;
                 EEPROM_Write(0x50,p0X);               // Write some data at address 0150
                 delay_ms(200);
                 EEPROM_Write(0x51,p1X);
                 delay_ms(200);
                  EEPROM_Write(0x52,p2X);
                  delay_ms(200);
                   EEPROM_Write(0x53,p3X);

          delay_ms(200);
          }
          if( code1!=code2){
          Lcd_Cmd(_LCD_CLEAR);
          Lcd_Out(1,1,txt4y);
               PORTC=0X02;
          delay_ms(1000);
          }
          return(0);
          }
             if (objX!=cod) {
         Lcd_Cmd(_LCD_CLEAR);
          Lcd_Out(1,1,txt4y);
          PORTC=0X02;
          delay_ms(2000);
            return(0);
         }

            }

              }
          
          
          
          
void main() {
    INTCON.GIE = 1;                 // Activation des interruptions globales
    INTCON.RBIE = 1;                // Activation des interruptions sur changement d'etat des ports B
    INTCON.INTE = 1;                // Activation des interruptions sur front montant de INT
    option_reg.INTEDG = 0;          // Definition du front montant pour les interruptions externes
    TRISB = 0xFF;                   // Definition des ports B comme entrees
    TRISA = 0xFF;                   // Definition des ports A comme entrees
    TRISC = 0;                      // Definition des ports C comme sorties
    PORTC = 0;                      // Initialisation du port C a 0
    p0XI = 1;                       // Initialisation de p0XI a 1
    p1XI = 1;                       // Initialisation de p1XI a 1
    p2XI = 1;                       // Initialisation de p2XI a 1
    p3XI = 1;                       // Initialisation de p3XI a 1
    EEPROM_Write(0x50, p0XI);       // ecriture de donnees a l'adresse 0150 dans l'EEPROM
    delay_ms(20);                   // Attente de 20 millisecondes
    EEPROM_Write(0x51, p0XI);       // ecriture de donnees a l'adresse 0151 dans l'EEPROM
    delay_ms(20);                   // Attente de 20 millisecondes
    EEPROM_Write(0x52, p0XI);       // ecriture de donnees a l'adresse 0152 dans l'EEPROM
    delay_ms(20);                   // Attente de 20 millisecondes
    EEPROM_Write(0x53, p0XI);       // ecriture de donnees a l'adresse 0153 dans l'EEPROM

    PORTC.F3 = 0;                   // Mise a  0 du bit 3 du port C
    Lcd_Init();                     // Initialisation de l'a ecran LCD
    Lcd_Cmd(_LCD_CLEAR);            // Effacement de l'affichage
    Lcd_Cmd(_LCD_CURSOR_OFF);       // Desactivation du curseur
    while (1) {                     // Boucle infinie
        modification();             // Appel de la fonction modification()
        alarme();                   // Appel de la fonction alarme()
    }
}




void interrupt()
    {
    if(INTCON.RBIF){
    if(portb.f4==1)
    {
      col1++;
    }
     if(portb.f5==1)
    {
        col2++;
    }
    if(portb.f6==1)
    {

         col3++;
     }

   if(portb.f7==0)
      {
      anti2++;

    }
 intcon.RBIF=0;
}

     if(INTCON.INTF){
          anti1++;
         INTCON.INTF=0;
         }
}