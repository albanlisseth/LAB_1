#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12, 13); //Pines donde va conectada la pantalla la pantalla (RS, rw, E, D4, D5, D6, D7)
String mensaje = "BIENVENIDO ";   //Escriba aqui el texto a mostrar
int conta = 0;
int ca = 0;
int ja = 0;
int aj = 0;
String clave = "";
String dato = "";
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);      //Inicializa la pantalla
  lcd.setCursor(0, 0);  //Posiciona el cursor en la posicion (0,0)
  lcd.print("INGRESE CLAVE");
  // initialize the serial communications:
  lcd.setCursor(0, 1);
  Serial.begin(9600);
  delay(500);
  pinMode(3,INPUT);   // PIN 0 COMO ENTRADA
}

void loop() {
int pin3=digitalRead(3);
if(pin3==1)
  {
    Serial.println("");
    Serial.println("ASISTENCIA");
    Serial.print("CARLOS ARIAS ");
    if(ca == 1)
    Serial.println("ASISTE");
    else
    Serial.println("NO ASISTE");
    Serial.print("ANDRES JUAREZ ");
    if(aj == 1)
    Serial.println("ASISTE");
    else
    Serial.println("NO ASISTE");
     Serial.print("JAVIER ANDRADE ");
    if(ja == 1)
    Serial.println("ASISTE");
    else
    Serial.println("NO ASISTE");
    delay(500);
  }

  // when characters arrive over the serial port...
  if (Serial.available() > 0)
  {
    dato = Serial.readString();
    dato.toLowerCase();
    clave = clave + dato;
    conta++;
    
    lcd.print("*");
    if (conta == 8)
    {
      lcd.clear();
      if (clave == "ca900813" )
      {
        mensaje = mensaje + "CARLOS ARIAS";
        ca = 1;

      }
      else if (clave == "aj881112")
      {
        mensaje = mensaje + "ANDRES JUAREZ";
        aj = 1;

      }
      else if (clave == "ja890109")
      {
        mensaje = mensaje + "JAVIER ANDRADE";
        ja = 1;

      }
      else
      {
        mensaje = "CLAVE ERRONEA";
      }
      
            int longitud_texto = mensaje.length();  //Obtiene y almacena la longitud del texto
            lcd.print(mensaje);    //Muestra el mensaje
            delay (300);
            for (int posicion = 0; posicion <= longitud_texto; posicion++)
            {
              lcd.scrollDisplayLeft();
              delay(300);
            }
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("INGRESE CLAVE");
            lcd.setCursor(0, 1);
            delay(300);
            conta=0;
            clave = "";
            mensaje = "BIENVENIDO ";
            Serial.println("");
    }

  }
}
