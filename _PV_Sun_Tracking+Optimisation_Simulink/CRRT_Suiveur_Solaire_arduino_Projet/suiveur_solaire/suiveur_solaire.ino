#include <Servo.h>

// Declaration des variables
// T:Top - B: Bottom - L:Left - R:righ
int ph_r_TL_v;
int ph_r_TR_v;
int ph_r_BL_v;
int ph_r_BR_v;

// Servo Moteur
Servo servo_vert;
int servoV_ang_pos = 90;
int servoV_limit_high = 120;
int servoV_limit_low = 30;

// Brancements du moteur DC A pour avoir un Rotation Horizontale
int motorH_enA_horiz = 9;
int motorH_in1 = 8;
int motorH_in2 = 7;

int motorH_ang_pos = 80;
int motorHLimitHigh = 120;
int motorHLimitLow = 50;
// Initialise les variable

int PIN_SERVO = 10;

int current_motorH_angle=70;


void setup() {
  // photo resistance
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);

  // moteur DC
  pinMode(motorH_enA_horiz,OUTPUT);
  pinMode(motorH_in1,OUTPUT);
  pinMode(motorH_in2,OUTPUT);

  // Eteindre le Moteur A - etat initial
  motorHStop();
  launchDCMotor(90);
  
  // Servo
  servo_vert.attach(PIN_SERVO);
  servo_vert.write(90);
  Serial.begin(9600);
}


void loop() {
  // Comparer les valeurs calculé pour chaque PhotoResistance
  // et Déplacer le Suiveur vers la Direction des P.R's le moins Resistés
  // En utilisant le Moteur Servo et Moteur CC avec Ponte H

  
  // Le Max difference entre les Valeurs Moy. de PhotoResistances Droit et Gauche 
  int tolerance = 30;
  int delay_time = 10;
  
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

  // Comparison en par calcul des valeurs moyennes 
  int moy_T = (ph_r_TL_v + ph_r_TR_v)/2;
  int moy_B = (ph_r_BL_v + ph_r_BR_v)/2;

  int moy_L = (ph_r_TL_v + ph_r_BL_v)/2;
  int moy_R = (ph_r_TR_v + ph_r_BR_v)/2;

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

  // Verifier si La difference est toleré sinon Change l'angle :

  // Movement Verticale (Servo Motor)
  if ( diff_TB > tolerance || diff_TB < tolerance * -1){
     if (moy_T > moy_B){
        servoV_ang_pos = ++servoV_ang_pos;
        if (servoV_ang_pos > servoV_limit_high) servoV_ang_pos = servoV_limit_high;
     }else if (moy_T <moy_B){
        servoV_ang_pos= --servoV_ang_pos;
        if (servoV_ang_pos < servoV_limit_low) servoV_ang_pos = servoV_limit_low;
     }
     servo_vert.write(servoV_ang_pos);
     
  }

  // Movement Horizontal (motorDC et Ponte H)

  if (diff_LR > tolerance || diff_LR < tolerance * -1){
     if (moy_L >moy_R){
       motorH_ang_pos = ++motorH_ang_pos;
       if (motorH_ang_pos > motorHLimitHigh) motorH_ang_pos = motorHLimitHigh;
       
     }else if (moy_L < moy_R){
       motorH_ang_pos = --motorH_ang_pos;
       if (motorH_ang_pos < motorHLimitLow) motorH_ang_pos =motorHLimitLow;      
     }
     // Paramaters : L'angle de Rotation
     launchDCMotor(motorH_ang_pos);
  }
  delay(500);
}


// Problems : Starting the Moteur Correctly & Battery Consumption 
// translation Horizontal
void launchDCMotor(int angle){

   // on : Distance = rayon*angle
   // temps_delay = distance/vitesse
   // Mapping angle to  rotation_time
   
   // il faut tester combien de temps le motor DC fait une rotation 360 deg avec ce vitesse pour 
   // pour mapper le angle avec le temps de rotation 
   
   int motorSpeed=50;
   if (angle < current_motorH_angle) {
      angle  = current_motorH_angle - angle;
      motorHBackward();
   }else{
      motorHForward();
   }

   
   int delay_rotation = map(angle,0,360,0,1000);
   
   
   // Forward
   analogWrite(motorH_enA_horiz, motorSpeed);
   delay(delay_rotation);
   current_motorH_angle = angle;
   
   motorHStop();
}


void motorHForward() {
  digitalWrite(motorH_in1, HIGH); 
  digitalWrite(motorH_in2, LOW); 
  
}

void motorHBackward() {
  digitalWrite(motorH_in1, LOW); 
  digitalWrite(motorH_in2, HIGH); 
  
}
void motorHStop() {
  digitalWrite(motorH_in1, LOW); 
  digitalWrite(motorH_in2, LOW); 
  
}
