/*              KONTROL  MONOEGONKORRA

  Hurrengo programak pultsagailu baten irakurketa egiten du eta Irteera bat kontrolatzen du era monoegonkorrean
   Ondoren Serie Monitorean idazten ditu balioak.
   Modified By Axpi 2017
   CC. Creatives Commons.
*/

// Aldagaien deklarazioa

int botoiaD = 5;
int botoiaB = 3;
int botoiaA = 2;
int y = 1;
int relayA = 11;
int relayB = 12;
int relayC = 13;

// Sarrera-Irteeren Inizializazioa

void setup()
{
  Serial.begin (9600);
  pinMode (botoiaD, INPUT);
  pinMode (botoiaB, INPUT);
  pinMode (botoiaA, INPUT);
  pinMode (y, INPUT);
  pinMode (relayA, OUTPUT);
  pinMode (relayB, OUTPUT);
  pinMode (relayC, OUTPUT);
  digitalWrite (relayA, HIGH);
  digitalWrite (relayB, HIGH);
  digitalWrite (relayC, HIGH);
  Serial.println ("Hondeamakina arizolaristi V1.0");
}

// Programa nagusia

void loop()
{
  y = analogRead(1);
  Serial.print ("Y ardatza= ");
  Serial.println (y);
  
  botoiaB = digitalRead (3);
  Serial.print ("B botoia= ");
  Serial.println (botoiaB);
  
  botoiaD = digitalRead (5);
  Serial.print ("D botoia= ");
  Serial.println (botoiaD);

   botoiaA = digitalRead (2);
  Serial.print ("A botoia= ");
  Serial.println (botoiaA);
  Serial.println ("");
  delay(0);
  
  if (y > 350) {
    digitalWrite (relayA, LOW);
  }
    else if (y < 350){
    digitalWrite (relayA, HIGH);
  }

  if (botoiaD == 0) {
    digitalWrite (relayB, LOW);
  }
    else if (botoiaD == 1){
    digitalWrite (relayB, HIGH);
  }

  if (botoiaB == 0) {
    digitalWrite (relayC, LOW);
  }
  else if (botoiaB == 1){
    digitalWrite (relayC, HIGH);
  }
    if (botoiaA == 0) {
    digitalWrite (relayC, LOW);
    digitalWrite (relayB, LOW);
    digitalWrite (relayA, LOW);
    }
  
}
