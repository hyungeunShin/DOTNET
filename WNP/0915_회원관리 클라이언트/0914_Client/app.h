//app.h
#pragma once

/* 
* [프로그램 흐름]
* 초기화(init) : 프로시작 시 한번만 실행하면 되는 코드!
* 엔진(run)    : 반복적으로 실행되는 코드!
* 종료(exit)   : 프로그램 종료 시 한번만 실행하면 되는 코드 
*/

void app_init();
void app_run();
void app_exit();

void logo();
void menuprint();
void ending();
