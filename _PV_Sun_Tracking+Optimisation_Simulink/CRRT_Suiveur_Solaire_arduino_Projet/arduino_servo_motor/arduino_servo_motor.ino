#include <Servo.h>

// Declaration des variables
// T:Top - B: Bottom - L:Left - R:righ
int ph_res_TL_v;
int ph_res_TR_v;
int ph_res_BL_v;
int ph_res_BR_v;

Servo servo_vert;
int servoV_ang_pos = 45;
int servoVLimitHigh = 65;
int servoVLimitLow = 30;

// Brancements du moteur A pour avoir un Rotation Horizontale
int enA_horiz = 9;
int in1 = 8;
int in2 = 7;

int motorH_ang_pos = 90;
int motorHLimitHigh = 180;
int motorHLimitLow = 60;
// Initialise les variable



void setup() {
  // photo resistance
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);

  // moteur à CC
  //pinMode(enA_horiz,OUTPUT);
  //pinMode(in1,OUTPUT);
  //pinMode(in2,OUTPUT);

  // Eteindre le Moteur A - etat initial
  //digitalWrite(in1, LOW);
  //digitalWrite(in2, LOW);
  //launchDCMotor(180);
  // Servo
  servo_vert.attach(10);
  Serial.begin(9600);
}


void loop() {
  // Comparer les valeurs calculé pour chaque PhotoResistance
  // et Déplacer le Suiveur vers la Direction des P.R's le moins Resistés
  // En utilisant le Moteur Servo et Moteur CC avec Ponte H

  int tolerance = 50;
  int delay_time = 10;
  
  ph_res_TL_v = analogRead(A0);
  ph_res_TR_v = analogRead(A1);
  ph_res_BL_v = analogRead(A2);
  ph_res_BR_v = analogRead(A3);

  // Afficher Les Valeurs de photoResistances
  Serial.println(" Ph_res  Values (TL TR BL BR) : ");
  Serial.println(ph_res_TL_v);
  Serial.println(ph_res_TR_v);
  Serial.println(ph_res_BL_v);
  Serial.println(ph_res_BR_v);
  Serial.println(" ");

  // Comparison en par calcul des valeurs moyennes 
  int moy_T = (ph_res_TL_v + ph_res_TR_v)/2;
  int moy_B = (ph_res_BL_v + ph_res_BR_v)/2;

  int moy_L = (ph_res_TL_v + ph_res_BL_v)/2;
  int moy_R = (ph_res_TR_v + ph_res_BR_v)/2;

  // calcul la diff entre Haut et Bas & Gauche et Droit
  int diff_TB = moy_T - moy_B;
  int diff_LR = moy_L - moy_R;

  // Afficher les valeurs calculé
  Serial.println(" Ph_res Average Values (TL TR BL BR) : ");
  Serial.println(moy_T);
  Serial.println(moy_B);
  Serial.println(moy_L);
  Serial.println(moy_R);
  Serial.println(" ");

  Serial.println(" Ph_res Diff Top - Bottom && Left - Right Values  : ");
  Serial.println(diff_TB);
  Serial.println(diff_LR);
  Serial.println(" ");

  // Testing Servo


  
  for (int i=0;i<180;i=i+10){
    servo_vert.write(i);
    delay(15);
  }

  delay(4000);
}
