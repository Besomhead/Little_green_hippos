#include <windows.h>
#include <conio.h>
#include <iostream> 
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <clocale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	STARTUPINFO startInfoFunc;
	PROCESS_INFORMATION procInfoFunc;
	ZeroMemory(&startInfoFunc, sizeof(STARTUPINFO));
	startInfoFunc.cb = sizeof(STARTUPINFO);

	//------------------------!!!!!!!!!!!!!!!!!!!!!!!----------------------
	/*TCHAR cmd[] = TEXT("Function.exe ");
	lstrcpy(cmd, itoa(GetCurrentProcessId()));*/

	// создаем новый консольный процесс 
	if (!CreateProcessA(
		NULL, // имя не задаем 
		"Function.exe", // командная строка, первая лексема указывает имя программы 
		NULL, // атрибуты защиты процесса устанавливаем по умолчанию 
		NULL, // атрибуты защиты первичного потока по умолчанию 
		FALSE, // дескрипторы текущего процесса не наследуются новым процессом 
		0, // по умолчанию NORMAL_PRIORITY_CLASS 
		NULL, // используем среду окружения вызывающего процесса 
		NULL, // текущий диск и каталог, как и в вызывающем процессе 
		(LPSTARTUPINFOA)&startInfoFunc, // вид главного окна - по умолчанию 
		&procInfoFunc // здесь будут дескрипторы и идентификаторы нового процесса и его первичного потока 
		)){
		_cputs("The new process is not created.\n");
		_cputs("Check a name of the process.\n");
		_cputs("Press any key to finish.\n");
		_getch();
	}

	STARTUPINFO startInfoFile;
	PROCESS_INFORMATION procInfoFile;
	ZeroMemory(&startInfoFile, sizeof(STARTUPINFO));
	startInfoFile.cb = sizeof(STARTUPINFO);

	/*char temp[100];
	int procId = GetCurrentProcessId();
	_itoa_s(procId, temp, 10);
	strcpy_s("PointsFile.exe", temp);
	const char *procFileCmdTemp = temp;
	LPSTR procFileCmd = const_cast<LPSTR>(procFileCmdTemp);*/

	if (!CreateProcessA(NULL, "PointsFile.exe", NULL, NULL, FALSE, 0, NULL, NULL,
		(LPSTARTUPINFOA)&startInfoFile, &procInfoFile))
	{
		cout << "PointsFile isn't running!" << endl;
	}

	Sleep(3000);

	STARTUPINFO startInfoLog;
	PROCESS_INFORMATION procInfoLog;
	ZeroMemory(&startInfoLog, sizeof(STARTUPINFO));
	startInfoLog.cb = sizeof(STARTUPINFO);

	if (!CreateProcessA(NULL, "LogFile.exe", NULL, NULL, FALSE, 0, NULL, NULL, (LPSTARTUPINFOA)&startInfoLog,
		&procInfoLog))
	{
		cout << "LogFile isn't running!" << endl;
	}

	return 0;
}