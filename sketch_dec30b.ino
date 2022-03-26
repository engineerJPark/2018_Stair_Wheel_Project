#define DXL_BUS_SERIAL1 1  //Dynamixel on Serial1(USART1)  <-OpenCM9.04
#define DXL_BUS_SERIAL2 2  //Dynamixel on Serial2(USART2)  <-LN101,BT210
#define DXL_BUS_SERIAL3 3  //Dynamixel on Serial3(USART3)  <-OpenCM 485EXP

#define FIRST_ID_NUM 1
#define SECOND_ID_NUM 2
#define THIRD_ID_NUM 3
#define FOURTH_ID_NUM 4

Dynamixel Dxl(DXL_BUS_SERIAL1);

int speed1 [22] = {309, 243, 200, 170, 148, 131, 117, 106, 97, 89, 83, 77, 72, 68, 68,76,86,100,119,146,189,268};
int speed2 [22] = {68,76,86,100,119,146,189,268, 309, 243, 200, 170, 148, 131, 117, 106, 97, 89, 83, 77, 72, 68};
int i = 0;

void setup() {
  // Initialize the dynamixel bus:

  // Dynamixel 2.0 Baudrate -> 0: 9600, 1: 57600, 2: 115200, 3: 1Mbps 
  Dxl.begin(3);
  Dxl.wheelMode(FIRST_ID_NUM); //wheelMode() is to use wheel mode
  Dxl.wheelMode(SECOND_ID_NUM);
  Dxl.wheelMode(THIRD_ID_NUM);
  Dxl.wheelMode(FOURTH_ID_NUM);
}

void loop() {
  i=0;
  
  while(i<=21){
   Dxl.goalSpeed(FIRST_ID_NUM, speed1[i]); //forward
   Dxl.goalSpeed(SECOND_ID_NUM, 1024 + speed1[i]); //reverse
   Dxl.goalSpeed(THIRD_ID_NUM, 1024 + speed2[i]); //forward
   Dxl.goalSpeed(FOURTH_ID_NUM, speed2[i]); //reverse
   delay(100);
   
   i++;
  }
}
