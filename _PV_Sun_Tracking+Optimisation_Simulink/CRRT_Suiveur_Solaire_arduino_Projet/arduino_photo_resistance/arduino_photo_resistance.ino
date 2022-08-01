
int ph_r_TL_v;
int ph_r_TR_v;
int ph_r_BL_v;
int ph_r_BR_v;


void setup() {
  // put your setup code here, to run once:
    // photo resistance
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);

  Serial.begin(9600);
  
}

void loop() {

  Serial.println(" photo resistance: ");

  
  // put your main code here, to run repeatedly:
  ph_r_TL_v = analogRead(A0);
  ph_r_TR_v = analogRead(A1);
  ph_r_BL_v = analogRead(A2);
  ph_r_BR_v = analogRead(A3);

    // Afficher Les Valeurs de photoResistances
  Serial.println(" Ph_res  Values (TL TR BL BR) : ");
  Serial.println(ph_r_TL_v);
  Serial.println(ph_r_TR_v);
  Serial.println(ph_r_BL_v);
  Serial.println(ph_r_BR_v);
  Serial.println(" ");
  delay(3000);

}
