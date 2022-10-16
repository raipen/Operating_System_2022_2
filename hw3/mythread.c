/*mythread.c
- 호출할 함수/생성할 thread 개수 정의 예 : #define FUNC_THREAD_NUM 100000
- 공유변수 value를 전역변수로 정의 (초기값 ‘0’)
- add() 함수 : value를 1씩 증가, 증가된 value 값 출력
- sub() 함수 : value를 1씩 감소, 감소된 value 값 출력

- main() 함수
    thread 버전 : mythread.c
    - add, sub 각각의 100000개 thread 생성 (FUNC_THREAD_NUM 정의된 값)
    - thread_join 으로 모든 thread들의 종료 기다림
    - 모든 동작 종료 후 최종 value 값 출력 (1번)
  */

#include <stdio.h>
#include <pthread.h>

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

void *add_thread(void *arg){
    add();
    return NULL;
}

void *sub_thread(void *arg){
    sub();
    return NULL;
}

int main(){
    int i;

    pthread_t add_thread_id[FUNC_THREAD_NUM];
    pthread_t sub_thread_id[FUNC_THREAD_NUM];
    for(i=0; i<FUNC_THREAD_NUM; i++){
        pthread_create(&add_thread_id[i], NULL, add_thread, NULL);
        pthread_create(&sub_thread_id[i], NULL, sub_thread, NULL);
    }
    for(i=0; i<FUNC_THREAD_NUM; i++){
        pthread_join(add_thread_id[i], NULL);
        pthread_join(sub_thread_id[i], NULL);
    }
    printf("value : %d\n", value);
    return 0;
}