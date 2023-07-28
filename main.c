#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>


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
    EVENT_START,     // 주행 시작
    EVENT_STOP,      // 주행 정지
    EVENT_OBSTACLE   // 장애물 감지
} RobotEvent;

pthread_mutex_t mutex;


// 밀리초 단위로 딜레이를 수행하는 함수
void delay(int milliseconds) {
    clock_t start_time = clock(); // 현재 CPU 시간 측정
    clock_t delay_time = milliseconds * CLOCKS_PER_SEC / 1000;

    while (clock() < start_time + delay_time) {
        // 딜레이를 위해 빈 루프를 실행
    }
}

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




// 스케쥴러를 이용하여 Fail Safe Function 주기적으로 실행
void btnHandler(RobotState* currentState) {
    // 주기적으로 상태를 체크하여 Fail Safe Function을 실행하는 로직을 구현
    while (true) {
        // 1초마다 상태를 확인하고, 상태에 따라 필요한 동작을 수행
        // (실제로는 하드웨어 타이머 인터럽트 또는 스레드를 사용해야 함)
        delay(1000); // 1초 대기

        // 예시로 장애물을 랜덤하게 감지하는 가정
        if (rand() % 10 == 0) {
            *currentState = stateMachine(*currentState, EVENT_OBSTACLE);
        }
    }
}

void imuHandler(RobotState* currentState) {
    // 주기적으로 상태를 체크하여 Fail Safe Function을 실행하는 로직을 구현
    while (true) {
        // 1초마다 상태를 확인하고, 상태에 따라 필요한 동작을 수행
        // (실제로는 하드웨어 타이머 인터럽트 또는 스레드를 사용해야 함)
        delay(1000); // 1초 대기

        // 예시로 장애물을 랜덤하게 감지하는 가정
        if (rand() % 10 == 0) {
            *currentState = stateMachine(*currentState, EVENT_OBSTACLE);
        }
    }
}

void usHandler(RobotState* currentState) {
    // 주기적으로 상태를 체크하여 Fail Safe Function을 실행하는 로직을 구현
    while (true) {
        // 1초마다 상태를 확인하고, 상태에 따라 필요한 동작을 수행
        // (실제로는 하드웨어 타이머 인터럽트 또는 스레드를 사용해야 함)
        delay(1000); // 1초 대기

        // 예시로 장애물을 랜덤하게 감지하는 가정
        if (rand() % 10 == 0) {
            *currentState = stateMachine(*currentState, EVENT_OBSTACLE);
        }
    }
}


void batMonHandler(RobotState* currentState) {
    // 주기적으로 상태를 체크하여 Fail Safe Function을 실행하는 로직을 구현
    while (true) {
        // 1초마다 상태를 확인하고, 상태에 따라 필요한 동작을 수행
        // (실제로는 하드웨어 타이머 인터럽트 또는 스레드를 사용해야 함)
        delay(1000); // 1초 대기

        // 예시로 장애물을 랜덤하게 감지하는 가정
        if (rand() % 10 == 0) {
            *currentState = stateMachine(*currentState, EVENT_OBSTACLE);
        }
    }
}

void motorHandler(RobotState* currentState) {
    // 주기적으로 상태를 체크하여 Fail Safe Function을 실행하는 로직을 구현
    while (true) {
        // 1초마다 상태를 확인하고, 상태에 따라 필요한 동작을 수행
        // (실제로는 하드웨어 타이머 인터럽트 또는 스레드를 사용해야 함)
        delay(1000); // 1초 대기

        // 예시로 장애물을 랜덤하게 감지하는 가정
        if (rand() % 10 == 0) {
            *currentState = stateMachine(*currentState, EVENT_OBSTACLE);
        }
    }
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

int sendMsgToAP(char *msg) {
    // AP로 메시지를 전송하고, 문제가 있으면 1을 반환
    printf("%s\n", msg);
    return 0;
}

int sendMsgToMotor(char *msg) {
    printf("%s\n", msg);
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