#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#include "./include/main.h"


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
    while (true) {
        delay(100); // 100 ms 대기

        // 예시로 장애물을 랜덤하게 감지하는 가정
        if (rand() % 17 == 0) {
            // MPU-6050 IMU에서 오류가 발생한 것으로 가정
            *currentState = stateMachine(*currentState, EVENT_IMU_ERR);
        }
    }
}

void usHandler(RobotState* currentState) {
    while (true) {
        delay(100); // 100 ms 대기

        if (rand() % 18 == 0) {
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
