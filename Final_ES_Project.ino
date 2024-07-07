#define pull PB_0
#define dir  PB_1

#define TV_1 PA_5
#define TV_2 PA_6
#define TV_3 PA_7
#define RR_1 PC_4
#define RR_2 PC_5
#define RR_3 PC_6
#define IE_1 PE_1
#define IE_2 PE_2
#define IE_3 PE_3

#define L_B PF_2

int main_delay = 0;
int rotation_value = 0;
int forward_delay = 0;
int backward_delay = 0;

int Conditions[27]={100100100,100100010,100100001,
                    100010100,100010010,100010001,
                    100001100,100001010,100001001,
                     10100100, 10100010, 10100001,
                     10010100, 10010010, 10010001,
                     10001100, 10001010, 10001001,
                      1100100,  1100010,  1100001,
                      1010100,  1010010,  1010001,
                      1001100,  1001010,  1001001};

void setup() {
  // Set stepper motor pins as outputs
  pinMode(pull, OUTPUT); //pull
  pinMode(dir,  OUTPUT); //dir
  pinMode(PF_2, OUTPUT);

  Serial.begin(9600);;
  
  // Set button pins as inputs
  pinMode(TV_1, INPUT_PULLUP); //tidal volume 200
  pinMode(TV_2, INPUT_PULLUP); //tidal volume 300
  pinMode(TV_3, INPUT_PULLUP); //tidal volume 400
  pinMode(RR_1, INPUT_PULLUP); //respiratory rate 8
  pinMode(RR_2, INPUT_PULLUP); //respiratory rate 12
  pinMode(RR_3, INPUT_PULLUP); //respiratory rate 16
  pinMode(IE_1, INPUT_PULLUP); //IE ratio 1:2
  pinMode(IE_2, INPUT_PULLUP); //IE ratio 1:3
  pinMode(IE_3, INPUT_PULLUP); //IE ratio 1:4
  
  pinMode(L_B, OUTPUT);
}
                    
void loop() {
  // put your main code here, to run repeatedly: 
  int a = 0;
  int b = 0;
  int c = 0;
  while(a==0 && b==0 && c==0){
    a = !digitalRead(TV_1);
    b = !digitalRead(TV_2);
    c = !digitalRead(TV_3);
    delay(10);
    Serial.println("1");
  }
  int d = 0;
  int e = 0;
  int f = 0;
  while(d==0 && e==0 && f==0){
    d = !digitalRead(RR_1);
    e = !digitalRead(RR_2);
    f = !digitalRead(RR_3);
    delay(10);
    Serial.println("2");
  }
  int g = 0;
  int h = 0;
  int i = 0;
  while(g==0 && h==0 && i==0){
    g = !digitalRead(IE_1);
    h = !digitalRead(IE_2);
    i = !digitalRead(IE_3);
    delay(10);
    Serial.println("3");
  }
  int lst[9] = {a,b,c,d,e,f,g,h,i};
//  int arr[9];
//  for (int i = 0; i < 9; i++)
//  {
//    if (lst[i] == HIGH){
//      arr[i] = 1;
//    }
//    else{
//      arr[i] = 0;
//    }
//  }
//  int m = 100000000;
  int num =0 ;
//  for(int i = 0; i < 9 ; i++)
//  {
//    num += arr[i]*m;
//    m /= 10;
//  }
num = lst[8]+lst[7]*10+lst[6]*100+lst[5]*1000+lst[4]*10000+lst[3]*100000+lst[2]*1000000+lst[1]*10000000+lst[0]*100000000;
//  for(int i=0; i<9; i++){
//    num += lst[8-i]*pow(10,i);
//  }
  Serial.println(num);
  
  if (num && Conditions[1]){
    main_delay = 250;
    rotation_value = 500;
    forward_delay = 500;
    backward_delay = 1000;
    digitalWrite(PF_2, HIGH);
    delay(500);
    digitalWrite(PF_2, LOW);
    delay(500);
    
    goto code;
  }
  else if (num && Conditions[2]){
    main_delay = 200;
    rotation_value = 500;
    forward_delay = 500;
    backward_delay = 1000;
    digitalWrite(PF_2, HIGH);
    delay(500);
    digitalWrite(PF_2, LOW);
    delay(500);
    goto code;
  }
  else if (num && Conditions[3]){
    main_delay = 150;
    rotation_value = 500;
    forward_delay = 500;
    backward_delay = 1000;
    digitalWrite(PF_2, HIGH);
    delay(500);
    digitalWrite(PF_2, LOW);
    delay(500);
    goto code;
  }
  else if (num && Conditions[4]){
    main_delay = 250;
    rotation_value = 500;
    forward_delay = 500;
    backward_delay = 1500;
    digitalWrite(PF_2, HIGH);
    delay(500);
    digitalWrite(PF_2, LOW);
    delay(500);
    goto code;
  }
  else if (num && Conditions[5]){
    main_delay = 200;
    rotation_value = 500;
    forward_delay = 500;
    backward_delay = 1500;
    digitalWrite(PF_2, HIGH);
    delay(500);
    digitalWrite(PF_2, LOW);
    delay(500);
    goto code;
  }
  else if (num && Conditions[6]){
    main_delay = 150;
    rotation_value = 500;
    forward_delay = 500;
    backward_delay = 1500;
    digitalWrite(PF_2, HIGH);
    delay(500);
    digitalWrite(PF_2, LOW);
    delay(500);
    goto code;
  }
  else if (num && Conditions[7]){
    main_delay = 250;
    rotation_value = 500;
    forward_delay = 500;
    backward_delay = 2000;
    digitalWrite(PF_2, HIGH);
    delay(500);
    digitalWrite(PF_2, LOW);
    delay(500);
    goto code;
  }
  else if (num && Conditions[8]){
    main_delay = 200;
    rotation_value = 500;
    forward_delay = 500;
    backward_delay = 2000;
    digitalWrite(PF_2, HIGH);
    delay(500);
    digitalWrite(PF_2, LOW);
    delay(500);
    goto code;
  }
  else if (num && Conditions[9]){
    main_delay = 150;
    rotation_value = 500;
    forward_delay = 500;
    backward_delay = 2000;
    goto code;
  }
  else if (num && Conditions[10]){
    main_delay = 250;
    rotation_value = 800;
    forward_delay = 500;
    backward_delay = 1000;
    digitalWrite(PF_2, HIGH);
    delay(500);
    digitalWrite(PF_2, LOW);
    delay(500);
    goto code;
  }
  else if (num && Conditions[11]){
    main_delay = 200;
    rotation_value = 800;
    forward_delay = 500;
    backward_delay = 1000;
    digitalWrite(PF_2, HIGH);
    delay(500);
    digitalWrite(PF_2, LOW);
    delay(500);
    goto code;
  }
  else if (num && Conditions[12]){
    main_delay = 150;
    rotation_value = 800;
    forward_delay = 500;
    backward_delay = 1000;
    digitalWrite(PF_2, HIGH);
    delay(500);
    digitalWrite(PF_2, LOW);
    delay(500);
    goto code;
  }
  else if (num && Conditions[13]){
    main_delay = 250;
    rotation_value =800;
    forward_delay = 500;
    backward_delay = 1500;
    digitalWrite(PF_2, HIGH);
    delay(500);
    digitalWrite(PF_2, LOW);
    delay(500);
    goto code;
  }
  else if (num && Conditions[14]){
    main_delay = 200;
    rotation_value = 800;
    forward_delay = 500;
    backward_delay = 1500;
    digitalWrite(PF_2, HIGH);
    delay(500);
    digitalWrite(PF_2, LOW);
    delay(500);
    goto code;
  }
  else if (num && Conditions[15]){
    main_delay = 150;
    rotation_value = 800;
    forward_delay = 500;
    backward_delay = 1500;
    digitalWrite(PF_2, HIGH);
    delay(500);
    digitalWrite(PF_2, LOW);
    delay(500);
    goto code;
  }
  else if (num && Conditions[16]){
    main_delay = 250;
    rotation_value = 800;
    forward_delay = 500;
    backward_delay = 2000;
    digitalWrite(PF_2, HIGH);
    delay(500);
    digitalWrite(PF_2, LOW);
    delay(500);
    goto code;
  }
  else if (num && Conditions[17]){
    main_delay = 200;
    rotation_value = 800;
    forward_delay = 500;
    backward_delay = 2000;
    digitalWrite(PF_2, HIGH);
    delay(500);
    digitalWrite(PF_2, LOW);
    delay(500);
    goto code;
  }
  else if (num && Conditions[18]){
    main_delay = 150;
    rotation_value = 800;
    forward_delay = 500;
    backward_delay = 2000;
    digitalWrite(PF_2, HIGH);
    delay(500);
    digitalWrite(PF_2, LOW);
    delay(500);
    goto code;
  }
  else if (num && Conditions[19]){
    main_delay = 250;
    rotation_value = 1000;
    forward_delay = 500;
    backward_delay = 1000;
    digitalWrite(PF_2, HIGH);
    delay(500);
    digitalWrite(PF_2, LOW);
    delay(500);
    goto code;
  }
  else if (num && Conditions[20]){
    main_delay = 200;
    rotation_value = 1000;
    forward_delay = 500;
    backward_delay = 1000;
    digitalWrite(PF_2, HIGH);
    delay(500);
    digitalWrite(PF_2, LOW);
    delay(500);
    goto code;
  }
  else if (num && Conditions[21]){
    main_delay = 150;
    rotation_value = 1000;
    forward_delay = 500;
    backward_delay = 1000;
    digitalWrite(PF_2, HIGH);
    delay(500);
    digitalWrite(PF_2, LOW);
    delay(500);
    goto code;
  }
  else if (num && Conditions[22]){
    main_delay = 250;
    rotation_value = 1000;
    forward_delay = 500;
    backward_delay = 1500;
    digitalWrite(PF_2, HIGH);
    delay(500);
    digitalWrite(PF_2, LOW);
    delay(500);
    goto code;
  }
  else if (num && Conditions[23]){
    main_delay = 200;
    rotation_value = 1000;
    forward_delay = 500;
    backward_delay = 1500;
    digitalWrite(PF_2, HIGH);
    delay(500);
    digitalWrite(PF_2, LOW);
    delay(500);
    goto code;
  }
  else if (num && Conditions[24]){
    main_delay = 150;
    rotation_value = 1000;
    forward_delay = 500;
    backward_delay = 1500;
    digitalWrite(PF_2, HIGH);
    delay(500);
    digitalWrite(PF_2, LOW);
    delay(500);
    goto code;
  }
  else if (num && Conditions[25]){
    main_delay = 250;
    rotation_value = 1000;
    forward_delay = 500;
    backward_delay = 2000;
    digitalWrite(PF_2, HIGH);
    delay(500);
    digitalWrite(PF_2, LOW);
    delay(500);
    goto code;
  }
  else if (num && Conditions[26]){
    main_delay = 200;
    rotation_value = 1000;
    forward_delay = 500;
    backward_delay = 2000;
    digitalWrite(PF_2, HIGH);
    delay(500);
    digitalWrite(PF_2, LOW);
    delay(500);
    goto code;
  }
  else if (num && Conditions[27]){
    main_delay = 150;
    rotation_value = 1000;
    forward_delay = 500;
    backward_delay = 2000;
    digitalWrite(PF_2, HIGH);
    delay(500);
    digitalWrite(PF_2, LOW);
    delay(500);
    goto code;
  }
//  else{
//    while(1);
//  }
  
  code:
  
  // Set the direction of rotation
  digitalWrite(dir, HIGH); // Set HIGH for clockwise rotation
  digitalWrite(L_B, HIGH);
  
  // Rotate the motor at full speed
  for (int i = 0; i < rotation_value; i++) { // Assuming 200 steps per revolution
    digitalWrite(pull, HIGH);
    delayMicroseconds(forward_delay); // Adjust the delay to control the speed
    digitalWrite(pull, LOW);
    delayMicroseconds(forward_delay); // Adjust the delay to control the speed
  }
  delay(main_delay); // Wait for 1 second before changing direction
  
  // Set the direction of rotation
  digitalWrite(dir, LOW); // Set LOW for counterclockwise rotation
  digitalWrite(L_B, LOW);
  
  // Rotate the motor at full speed
  for (int i = 0; i < rotation_value; i++) { // Assuming 200 steps per revolution
    digitalWrite(pull, HIGH);
    delayMicroseconds(backward_delay); // Adjust the delay to control the speed
    digitalWrite(pull, LOW);
    delayMicroseconds(backward_delay); // Adjust the delay to control the speed
  }
  delay(main_delay); // Wait for 1 second before repeating the loop
}
