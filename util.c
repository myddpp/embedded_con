#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void delay(int milliseconds) {
    clock_t start_time = clock(); // 현재 CPU 시간 측정
    clock_t delay_time = milliseconds * CLOCKS_PER_SEC / 1000;

    while (clock() < start_time + delay_time) {
        ;
    }
}

int sendMsgToAP(char *msg) {
    printf("AP : %s\n", msg);
    return 0;
}

int sendMsgToMotor(char *msg) {
    printf("motor : %s\n", msg);
    return 0;
}


int chekDeviceStatus() {
    int ans =0;
    // 장치 상태를 확인하고, 문제가 있으면 1을 반환
    // Check communication with IMU
    // Check communication with US
    // Check communication with BatMon
    // Check communication with Button
    // Check communication with LED
    // Check communication with Buzzer
    // Check communication with LCD
    // Check communication with Camera
    // Check communication with Speaker
    // Check communication with Encoder
    // Check communication with Servo
    if (rand() % 10 == 0) {
        ans=1;
    }    
    return ans;
}

int chekCommWithOthers() {
    int ans =0;
    // 장치 상태를 확인하고, 문제가 있으면 1을 반환
    // Check communication with AP
    // Check communication with Motor
    if (rand() % 10 == 0) {
        ans=1;
    }     
    return ans;
}

int stopMoving() {
   printf("Stop Robot Moving. \n");
   sendMsgToMotor("stop");
    return 0;
}

int dumpInfo() {
    printf("Print All info for Debugging\n");
    sendMsgToAP("dump");
    return 0;
}

int playBuzzer(int freq, int duration) {
    printf("Buzzer: %dHz, %dms\n", freq, duration);
    return 0;
}

int chkBattery() {
    // 배터리 상태를 확인하고, 문제가 있으면 1을 반환
    return 0;
}