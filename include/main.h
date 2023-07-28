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
