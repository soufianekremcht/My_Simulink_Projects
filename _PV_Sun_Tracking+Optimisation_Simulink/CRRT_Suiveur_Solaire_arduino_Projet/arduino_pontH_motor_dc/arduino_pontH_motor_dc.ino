

//#include <PID>

// Angle Control using DC Motor


// Declaration des variables
// T:Top - B: Bottom - L:Left - R:right
int ph_r_TL_v;
int ph_r_TR_v;
int ph_r_BL_v;
int ph_r_BR_v;

// Brancements du moteur A pour avoir un Rotation Horizontale
int enA_horiz = 3;
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
  pinMode(enA_horiz,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);

  // Eteindre le Moteur A - etat initial
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA_horiz, 100);
  Serial.begin(9600);
}

void loop() {
  // Comparer les valeurs calculé pour chaque PhotoResistance
  // et Déplacer le Suiveur vers la Direction des P.R's le moins Resistés
  // En utilisant le Moteur Servo et Moteur CC avec Ponte H

  int tolerance = 50;
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


  launchDCMotor();
  
  delay(5000);
}


// Problems : Starting the Moteur Correctly & Battery Consumption

void launchDCMotor(){

   int angle = 1;
   // on : Distance = rayon*angle
   // temps_delay = distance/vitesse
   // Mapping from angle to  pulse
   
   int rotation_time = map(angle,0,360,0,1000);

   analogWrite(enA_horiz, 100);
   // Forward
   motorForward();
   delay(500);
    
  // Accélérer les moteurs de la vitesse nulle à la vitesse maximale
  /*
  for (int i = 0; i < 256; i++)
  {
    analogWrite(enA_horiz, i);
    delay(20);
  }
  */

  // Décélérer de la vitesse maximale à zéro
  /*
  for (int i = 255; i >= 0; --i)
  {
    analogWrite(enA_horiz, i);
    delay(20);
  }
  */
  motorStop();
}

void motorForward(){
   digitalWrite(in1, LOW);
   digitalWrite(in2, HIGH);
}

void motorBackward(){
   digitalWrite(in1, HIGH);
   digitalWrite(in2, LOW);
}

void motorStop(){
   digitalWrite(in1, LOW);
   digitalWrite(in2, LOW);
}
