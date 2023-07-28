# 컴파일러 설정
CC = gcc

# 컴파일러 옵션
CFLAGS = -Wall -Wextra

# 컴파일 대상 파일 및 실행 파일 이름
TARGET = main

# 헤더 파일이 있는 디렉토리 경로
INCLUDES = -I./include

# 소스 파일들
SRC = main.c util.c handler.c

# 기본 규칙 (all) 설정
all: $(TARGET)

# 실행 파일 생성 규칙
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# 정리(clean) 규칙 설정
clean:
	rm -f $(TARGET)