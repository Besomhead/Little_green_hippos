#include "Point.h"

using namespace std;

const int MIN_X = -50;
const int MAX_X = 51;

int nextY(int);

void main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Rus");

	//int procId = atoi(argv[1]);

	/*HANDLE process = OpenProcess(PROCESS_QUERY_INFORMATION | SYNCHRONIZE, FALSE, procId);
	if (!process) cout << "Function: Ошибка при открытии процесса\n";
	cout.flush();

	cout << GetCurrentProcessId() << endl;

	if (WaitForSingleObject(process, INFINITE) == STATUS_WAIT_0)
		cout << "Function: Main завершил работу\n";
	else
		cout << "Function: Незнакомая ошибка\n";

	TerminateProcess(process, 0);*/
	HANDLE pointEvent = CreateEventA(NULL, TRUE, FALSE, "newPointEvent");

	for (int x = MIN_X; x < MAX_X; x++)
	{
		int y = nextY(x);
		//newPoint = new Point(x, y);
		SetEvent(pointEvent);
		//cout << newPoint->getX() << " " << newPoint->getY() << endl;
		Sleep(10);
		//newPoint.release();
		ResetEvent(pointEvent);
	}


	exit(0);
}

int nextY(int x)
{
	return pow(x, 3);
}