#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include "./include/util.h"


///////////////////////////////////////////////
//   Global Variable
///////////////////////////////////////////////

// 서빙 로봇의 상태 정의
typedef enum {
    STATE_IDLE,      // 대기 상태
    STATE_DRIVING,   // 주행 상태
    STATE_ERROR      // 오류 상태
} RobotState;

// 서빙 로봇의 이벤트 정의
typedef enum {
    EVENT_START,        // 주행 시작
    EVENT_STOP,         // 주행 정지
    EVENT_OBSTACLE,     // 장애물 감지
    EVENT_IMU,          // 저전압 감지
    EVENT_LOWBAT,       // 저전압 감지
    EVENT_IMU_ERR,      // 저전압 감지
} RobotEvent;

pthread_mutex_t mutex;




///////////////////////////////////////////////
//   Global Variable
///////////////////////////////////////////////
// 현재 상태와 이벤트에 따른 다음 상태를 결정하는 상태머신 함수
RobotState stateMachine(RobotState currentState, RobotEvent event) {
    pthread_mutex_lock(&mutex); // 뮤텍스 잠금

    switch (currentState) {
        case STATE_IDLE:
            if (event == EVENT_START)
                currentState =  STATE_DRIVING;
            break;

        case STATE_DRIVING:
            if (event == EVENT_STOP)
                currentState =  STATE_IDLE;
            else if (event == EVENT_OBSTACLE)
                currentState =  STATE_ERROR;
            break;

        case STATE_ERROR:
            // 오류 상태에서는 다른 이벤트를 처리하지 않고 오류를 해결해야 함
            break;

        default:
            break;
    }
    pthread_mutex_unlock(&mutex); // 뮤텍스 해제
    return currentState;
}


int chekDeviceStatus() {
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
    // Check communication with Motor    
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



int main() {
    pthread_t tBtn, tIMU, tUS, tBatMon, tMotor;

    // init value
    RobotState currentState = STATE_IDLE;

    // Check Device Status
    if ( chekDeviceStatus() == 1 ) {
        printf("Device Status Error\n");
        return 0;
    }



    // 스레드 생성
    pthread_create(&tBtn, currentState, btnHandler, (void*)&currentState);
    pthread_create(&tIMU, currentState, imuHandler, (void*)&currentState);
    pthread_create(&tUS, NULL, usHandler,  (void*)&currentState);
    pthread_create(&tBatMon, NULL, batMonHandler, (void*)&currentState);
    pthread_create(&tMotor, NULL, motorHandler, (void*)&currentState);

    // 각 스레드가 실행을 완료할 때까지 대기
    pthread_join(tBtn, NULL);
    pthread_join(tIMU , NULL);
    pthread_join(tUS, NULL);
    pthread_join(tBatMon, NULL);
    pthread_join(tMotor, NULL);        

    printf("Main thread: All threads completed.\n");

    return 0;
}