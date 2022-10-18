/*funcall.c
- 호출할 함수/생성할 thread 개수 정의 예 : #define FUNC_THREAD_NUM 100000
- 공유변수 value를 전역변수로 정의 (초기값 ‘0’)
- add() 함수 : value를 1씩 증가, 증가된 value 값 출력
- sub() 함수 : value를 1씩 감소, 감소된 value 값 출력

- main() 함수
    함수 호출 버전 : funcall.c
    - add, sub 각각의 함수를 100000번 호출 (FUNC_THREAD_NUM 정의된 값)
    - 모든 동작 종료 후 최종 value 값 출력 (1번)
  */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <string.h>

#define FUNC_THREAD_NUM 100000

int value = 0;

void add(){
    value++;
    printf("add : %d\n", value);
}

void sub(){
    value--;
    printf("sub : %d\n", value);
}

int main(){
    int i;
    for(i=0; i<FUNC_THREAD_NUM; i++){
        add();
        sub();
    }
    printf("value : %d\n", value);
    return 0;
}