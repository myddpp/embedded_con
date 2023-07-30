// 밀리초 단위로 딜레이를 수행하는 함수
void delay(int milliseconds);

// AP로 메시지를 전송하고, 문제가 있으면 1을 반환
int sendMsgToAP(char *msg);
int sendMsgToMotor(char *msg);

void delay(int milliseconds);


int chekDeviceStatus();
int chekCommWithOthers();
int chkBattery(); 

int stopMoving();
int dumpInfo(); 
int playBuzzer(int freq, int duration);

