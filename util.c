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