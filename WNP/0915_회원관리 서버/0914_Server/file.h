//file.h
/*
* ���α׷� ���۽� �ҷ�����  void con_Run() �Լ��� ��ܿ��� ȣ��, �������κп��� con_printall() ȣ��
* ���α׷� ����� �����ؾ� ������ ����ñ� �Һи�.....
* ȸ������, Ż��ø� ����. void con_InsertMember(), void con_DeleteMember()
*/

#pragma once

void fild_Load(vector<MEMBER>& memberlist);
void file_Save(const vector<MEMBER>& memberlist);
