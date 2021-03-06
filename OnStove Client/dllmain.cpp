// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include <Windows.h>
#include <stdio.h>
#include <iostream>

BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{

	if (fdwReason == DLL_PROCESS_ATTACH)
	{
		AllocConsole();
		SetConsoleTitle(L"OnStove Client");
		AttachConsole(GetCurrentProcessId());

		FILE* pFile = nullptr;
		freopen_s(&pFile, "CON", "r", stdin);
		freopen_s(&pFile, "CON", "w", stdout);
		freopen_s(&pFile, "CON", "w", stderr);

		DisableThreadLibraryCalls(hinstDLL);
	}
	else if (fdwReason == DLL_PROCESS_DETACH)
	{
		FreeConsole();
	}

	return TRUE;
}