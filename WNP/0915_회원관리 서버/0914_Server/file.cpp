//file.cpp

#include "std.h"

void fild_Load(vector<MEMBER>& memberlist)
{
	FILE* fp;
	int retval =fopen_s(&fp, "memberlist.ccm", "rb");  //read+binary
	if (retval != 0)
	{
		printf("파일 오픈 에러\n");
		return;
	}

	int size;
	fread((char*)&size, sizeof(int), 1, fp);
	for (int i = 0; i < size; i++)
	{
		MEMBER mem;
		fread((char*)&mem, sizeof(mem), 1, fp);
		mem.islogin = false;						//false 로 변경
		memberlist.push_back(mem);
	}

	fclose(fp);
}

void file_Save(const vector<MEMBER>& memberlist)
{
	FILE* fp;
	int retval = fopen_s(&fp, "memberlist.ccm", "wb");  //write+binary
	if (retval != 0)
	{
		printf("파일 오픈 에러\n");
		return;
	}

	//파일[4byte크기의 개수가 3개라면] [65byte mem]이 3개
	//개수 저장
	int size = memberlist.size();
	fwrite((char*)&size, sizeof(int), 1, fp);
	for (int i = 0; i < (int)memberlist.size(); i++)
	{
		MEMBER mem = memberlist[i];
		fwrite((char*)&mem, sizeof(mem), 1, fp);
	}

	fclose(fp);
}