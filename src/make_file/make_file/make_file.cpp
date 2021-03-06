// make_file.cpp : définit les fonctions exportées pour l'application DLL.
//

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>

extern "C"
{
	__declspec (dllexport) void __stdcall RVExtension(char *output, int outputSize, const char *function);
}

void __stdcall RVExtension(char *output, int outputSize, const char *function)
{
	FILE* fichier = NULL;
	fopen_s(&fichier, "file.hpp", "w+");
	fputs(function, fichier);
	fclose(fichier);
	strncpy_s(output, outputSize, "OK!", _TRUNCATE);
}