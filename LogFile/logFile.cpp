#include <Point.h>

using namespace std;

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Rus");

	FILE *logFile;

	if (!(logFile = fopen("points.txt", "wb")))
	{
		cout << "Can't create log file!" << endl;
		exit(1);
	}


	fclose(logFile);
	return 0;
}