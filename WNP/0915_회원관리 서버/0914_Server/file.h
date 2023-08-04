//file.h
/*
* 프로그램 시작시 불러오기  void con_Run() 함수의 상단에서 호출, 마지막부분에서 con_printall() 호출
* 프로그램 종료시 저장해야 하지만 종료시기 불분명.....
* 회원가입, 탈퇴시만 저장. void con_InsertMember(), void con_DeleteMember()
*/

#pragma once

void fild_Load(vector<MEMBER>& memberlist);
void file_Save(const vector<MEMBER>& memberlist);
