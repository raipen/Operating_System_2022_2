/*
다음 3개 쓰레드를 이용하여 입력받은 문자(영문)/공백/특수기호를 포함하는 문장을 "순서대로" 출력하는 프로그램 (mystring.c)
  - 쓰레드1 : 문자(영문)만 출력
  - 쓰레드2 : 공백만 출력
  - 쓰레드3 : 특수기호만 출력
  - 입력예시) Hey, watch it! -> 출력) Hey, watch it!
    * 다양한 문장으로 테스트 해볼 것
    * 쓰레드 외부(예: main)에서 문자 체크는 없을 것 (중재자 없어야 함)
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_STR_LEN 100

char str[MAX_STR_LEN];
int str_len;
int cur_idx = 0;

pthread_mutex_t mutex;

void *print_char(void *arg){
    while(1){
        pthread_mutex_lock(&mutex);
        if(cur_idx >= str_len){
            pthread_mutex_unlock(&mutex);
            break;
        }
        if(str[cur_idx] >= 'a' && str[cur_idx] <= 'z'){
            printf("%c", str[cur_idx]);
            cur_idx++;
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void *print_space(void *arg){
    while(1){
        pthread_mutex_lock(&mutex);
        if(cur_idx >= str_len){
            pthread_mutex_unlock(&mutex);
            break;
        }
        if(str[cur_idx] == ' '){
            printf("%c", str[cur_idx]);
            cur_idx++;
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void *print_special(void *arg){
    while(1){
        pthread_mutex_lock(&mutex);
        if(cur_idx >= str_len){
            pthread_mutex_unlock(&mutex);
            break;
        }
        if(str[cur_idx]!=' ' && (str[cur_idx] < 'a' || str[cur_idx] > 'z')){
            printf("%c", str[cur_idx]);
            cur_idx++;
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(){
    pthread_t tid1, tid2, tid3;
    pthread_mutex_init(&mutex, NULL);
    printf("Input a string: ");
    fgets(str, MAX_STR_LEN, stdin);
    str_len = strlen(str);
    pthread_create(&tid1, NULL, print_char, NULL);
    pthread_create(&tid2, NULL, print_space, NULL);
    pthread_create(&tid3, NULL, print_special, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);
    pthread_mutex_destroy(&mutex);
    return 0;
}