#include <stdio.h>
#include <Windows.h>
void move(int plate, char poleStart, char poleGoal)
{
	static int i = 0;
	printf("[%d]\t%d:%c->%c\n", ++i, plate, poleStart, poleGoal);
}
void hanoi(int n, char poleStart, char poleTemp, char poleGoal)
{
	if (n == 0) return;
	hanoi(n - 1, poleStart, poleGoal, poleTemp);
	move(n, poleStart, poleGoal);
	hanoi(n - 1, poleTemp, poleStart, poleGoal);
}
int main()
{
	hanoi(10, 'A', 'B', 'C');
	system("pause");
	return 0;
}