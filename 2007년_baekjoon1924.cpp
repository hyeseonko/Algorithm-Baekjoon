#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_day(int n)
{
	switch (n % 7) {
	case 0: puts("SUN"); break;
	case 1: puts("MON"); break;
	case 2: puts("TUE"); break;
	case 3: puts("WED"); break;
	case 4: puts("THU"); break;
	case 5: puts("FRI"); break;
	case 6: puts("SAT"); break;
	}
}

int main()
{
	int month, day;
	scanf("%d %d", &month, &day);
	switch (month)
	{
	case 1: print_day(day); break;
	case 2: print_day(day + 3); break;
	case 3: print_day(day + 3); break;
	case 4: print_day(day + 6); break;
	case 5: print_day(day + 8); break;
	case 6: print_day(day + 11); break;
	case 7: print_day(day + 13); break;
	case 8: print_day(day + 16); break;
	case 9: print_day(day + 19); break;
	case 10: print_day(day + 21); break;
	case 11: print_day(day + 24); break;
	case 12: print_day(day + 26); break;
	}
	return 0;
}