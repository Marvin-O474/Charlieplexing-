//you need to define the pins you are using based on your schematic 
#define x1 4
#define x2 5
#define x3 2
#define x4 3
//PIN_CONFIG and PIN_STATE define the two rows in the matrix 
#define PIN_CONFIG 0
#define PIN_STATE 1
#define LED_Num 12 // number of LED's 

//defines a 2x4 matrix 12 times each having diffrent elements depending on pin state 
int matrix[LED_Num][2][4]={
  // PIN_CONFIG      PIN_STATE
  // A B C D         A B C D 
  {{OUTPUT,OUTPUT,INPUT,INPUT},{HIGH,LOW,LOW,LOW}},
  {{OUTPUT,OUTPUT,INPUT,INPUT},{LOW,HIGH,LOW,LOW}},
  {{INPUT,OUTPUT,OUTPUT,INPUT},{LOW,HIGH,LOW,LOW}},
  {{INPUT,OUTPUT,OUTPUT,INPUT},{LOW,LOW,HIGH,LOW}},
  {{INPUT,INPUT,OUTPUT,OUTPUT},{LOW,LOW,HIGH,LOW}},
  {{INPUT,INPUT,OUTPUT,OUTPUT},{LOW,LOW,LOW,HIGH}},
  {{OUTPUT,INPUT,OUTPUT,INPUT},{LOW,LOW,HIGH,LOW}},
  {{OUTPUT,INPUT,OUTPUT,INPUT},{HIGH,LOW,LOW,LOW}},
  {{INPUT,OUTPUT,INPUT,OUTPUT},{LOW,LOW,LOW,HIGH}},
  {{INPUT,OUTPUT,INPUT,OUTPUT},{LOW,HIGH,LOW,LOW}},
  {{OUTPUT,INPUT,INPUT,OUTPUT},{LOW,LOW,LOW,HIGH}},
  {{OUTPUT,INPUT,INPUT,OUTPUT},{HIGH,LOW,LOW,LOW}}
};
// function to set pins state to turn on LED's based on the above matrix. this is done because pin state is not constant 
//repacing PIN_CONFIG and PIN_STATE with the number equvalent will help you understand it better
void LightOn(int led){
  pinMode(x1,matrix[led][PIN_CONFIG][0]);
  pinMode(x2,matrix[led][PIN_CONFIG][1]);
  pinMode(x3,matrix[led][PIN_CONFIG][2]);
  pinMode(x4,matrix[led][PIN_CONFIG][3]);

  digitalWrite(x1,matrix[led][PIN_STATE][0]);
  digitalWrite(x2,matrix[led][PIN_STATE][1]);
  digitalWrite(x3,matrix[led][PIN_STATE][2]);
  digitalWrite(x4,matrix[led][PIN_STATE][3]);
}
// we just include the void setup function because without it the xompiler will spit out an error message 
void setup(){}
//we then call the "LightOn" function we defined in a for loop inside a the loop function and pass "i" to the "LightOn" function as an argument
void loop(){
  for(int i=0;i<LED_Num;i++){
    LightOn(i);

  }
}
  
