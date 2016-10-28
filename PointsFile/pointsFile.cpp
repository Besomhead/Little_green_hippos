#include <Point.h>

using namespace std;

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Rus");

	FILE *pointsFile;

	if (!(pointsFile = fopen("points.txt", "ab")))
	if (!(pointsFile = fopen("points.txt", "wb")))
	{
		cout << "Can't create points file!" << endl;
		exit(1);
	}

	HANDLE pointEvent = OpenEventA(NULL, NULL, "newPointEvent");

	WaitForSingleObject(pointEvent, INFINITE);

//	fprintf(pointsFile, "%d %d\n", newPoint->getX(), newPoint->getY());

	fclose(pointsFile);
	return 0;
}