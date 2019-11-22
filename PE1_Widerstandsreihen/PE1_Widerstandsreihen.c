#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int color_ring1[] = {
	/*black =*/ 0,
	/*brown =*/ 1,
	/*red =*/ 2,
	/*orange =*/ 3,
	/*yellow =*/ 4,
	/*green =*/ 5,
	/*blue =*/ 6,
	/*purple =*/ 7,
	/*grey = */8,
	/*white =*/ 9
};

// frage den Benutzer nach gewuenschter E-Reihe

int read_e_series()
{
	while (1)
	{
		int n;
		printf("\n\tBitte geben Sie die Nr. der E-Reihe an: ");
		scanf("%i", &n);
		while (getchar() != '\n');

		if (n == 6 || n == 12 || n == 24 || n == 48 || n == 96 || n == 192) return n;

		printf("\n\nungueltige Eingabe (%i)!\n\n", n);
		printf("gueltige Werte: 6, 12, 24, 48, 96, 192!\n\n");
	}
}

// frage den Benutzer nach gewuenschter Dekade

int read_decade()
{
	int n;
	printf("\n\tBitte geben Sie den Dekadenfaktor an: ");
	scanf("%i", &n);
	while (getchar() != '\n');
	return n;
}

double compute_tolerance(int INPUT_E_SERIES) {
	switch (INPUT_E_SERIES) {
	case 6:
		return 0.20;
	case 12:
		return 0.10;
	case 24:
		return 0.05;
	case 48:
		return 0.02;
	case 96:
		return 0.01;
	case 192:
		return 0.005;
	}
}

char* check_color(int arr[100], int n, int INPUT_E_SERIES) {
	for (size_t i = 0; i < 100; i++)
	{
		if (INPUT_E_SERIES <= 24)
		{
			if (n == 0)
			{//color ring 1
				switch (arr[i])
				{
				case 0: return("\tblack");
				case 1:	return("\tbrown");
				case 2:	return("\tred");
				case 3:	return("\torange");
				case 4:	return("\tyellow");
				case 5:	return("\tgreen");
				case 6:	return("\tblue");
				case 7:	return("\tpurple");
				case 8:	return("\tgrey");
				case 9:	return("\twhite");
				}
			}
			else if (n == 1)
			{//color ring 2
				switch (arr[i])
				{
				case 0: return("\tblack");
				case 1:	return("\tbrown");
				case 2:	return("\tred");
				case 3:	return("\torange");
				case 4:	return("\tyellow");
				case 5:	return("\tgreen");
				case 6:	return("\tblue");
				case 7:	return("\tpurple");
				case 8:	return("\tgrey");
				case 9:	return("\twhite");
				}
			}
		}
		else if (INPUT_E_SERIES > 24)
		{
			if (n == 0) {//color ring 1
				switch (arr[i])
				{
				case 0: return("\tblack");
				case 1:	return("\tbrown");
				case 2:	return("\tred");
				case 3:	return("\torange");
				case 4:	return("\tyellow");
				case 5:	return("\tgreen");
				case 6:	return("\tblue");
				case 7:	return("\tpurple");
				case 8:	return("\tgrey");
				case 9:	return("\twhite");
				}
			}
			else if (n == 1)
			{//color ring 2
				switch (arr[i])
				{
				case 0: return("\tblack");
				case 1:	return("\tbrown");
				case 2:	return("\tred");
				case 3:	return("\torange");
				case 4:	return("\tyellow");
				case 5:	return("\tgreen");
				case 6:	return("\tblue");
				case 7:	return("\tpurple");
				case 8:	return("\tgrey");
				case 9:	return("\twhite");
				}
			}
			else if (n == 2)
			{//color ring 3
				switch (arr[i])
				{
				case 0: return("\tblack");
				case 1:	return("\tbrown");
				case 2:	return("\tred");
				case 3:	return("\torange");
				case 4:	return("\tyellow");
				case 5:	return("\tgreen");
				case 6:	return("\tblue");
				case 7:	return("\tpurple");
				case 8:	return("\tgrey");
				case 9:	return("\twhite");
				}
			}
		}
	}
}

int print_table(double INPUT_TABLE[192][3], int INPUT_E_SERIES, double INPUT_TOLERANCE) {
	printf("\n\t+");
	for (size_t i = 0; i < 44; i++)
	{
		printf("-");
	}
	printf("+\n");

	printf("\t|%28s - %-13d|\n", "Widerstandsreihe E", INPUT_E_SERIES);

	printf("\t+");
	for (size_t i = 0; i < 44; i++)
	{
		printf("-");
	}
	printf("+\n");

	printf("\t|%8c%4.1f%s | %6s %7c %7c%4.1f%s |\n", '-', (INPUT_TOLERANCE * 100), "%", "R", '|', '+', (INPUT_TOLERANCE * 100), "%");

	printf("\t+");
	for (size_t i = 0; i < 44; i++)
	{
		printf("-");
	}
	printf("+\n");

	for (int i = 0; i <= INPUT_E_SERIES - 1; i++) {
		printf("\t| %12.5f | %12.5f | %12.5f |\n", INPUT_TABLE[i][0], INPUT_TABLE[i][1], INPUT_TABLE[i][2]);
	}

	printf("\t+");
	for (size_t i = 0; i < 44; i++)
	{
		printf("-");
	}
	printf("+\n");

	return 0;
}

unsigned int count(unsigned int i) {
	unsigned int ret = 1;
	while (i /= 10) ret++;
	return ret;
}

int print_digits(double table[192][3], double INPUT_E_SERIES) {
	int num = (int)table[16][1]; //for example
	int dig = count(num);
	int arr[100];

	while (dig--) {
		arr[dig] = num % 10;
		num /= 10;
		printf("\n%d \tZahlenstelle: %d", arr[dig], dig + 1);
		if (INPUT_E_SERIES <= 24) {
			if (dig == 0/*Erste Ziffer*/) {
				printf("\t%s", check_color(arr, 0, INPUT_E_SERIES));
			}
			else if (dig == 1/*Zweite Ziffer*/) {
				printf("\t%s", check_color(arr, 1, INPUT_E_SERIES));
				/*test_function(arr[1]);*/
			}
			else if (dig == 2/*Dritte Ziffer*/) {
			}
			else if (dig == 3/*Vierte Ziffer*/) {
			}
		}
		else if (INPUT_E_SERIES > 24) {
			if (dig == 0/*Erste Ziffer*/) {
				printf("\t%s", check_color(arr, 0, INPUT_E_SERIES));
			}
			else if (dig == 1/*Zweite Ziffer*/) {
				printf("\t%s", check_color(arr, 1, INPUT_E_SERIES));
			}
			else if (dig == 2/*Dritte Ziffer*/) {
				printf("\t%s", check_color(arr, 1, INPUT_E_SERIES));
			}
			else if (dig == 3/*Vierte Ziffer*/) {
			}
		}
	}

	//int size = sizeof(arr) / sizeof(arr[0]);//Method
	//printf("\nSize of Array: %d", size);
}

char* getToleranceRing(int INPUT_E_SERIES) {
	printf("\n\tTolerance Ring:");
	switch (INPUT_E_SERIES)
	{
	case 12:
		return "\tsilver";
	case 24:
		return "\tyellow";
	case 48:
		return "\tred";
	case 96:
		return "\tbrown";
	default:
		break;
	}
}

int getMultiplierRing(int INPUT_decade) {
	printf("\n\tMultiplier Ring:");
	switch (INPUT_decade)
	{
	case 0:
		printf("\tBlack");
		break;
	case 1:
		printf("\tBrown");
		break;
	case 2:
		printf("\tRed");
		break;
	case 3:
		printf("\torange");
		break;
	case 4:
		printf("\tyellow");
		break;
	case 5:
		printf("\tgreen");
		break;
	case 6:
		printf("\tblue");
		break;
	}

	return 0;
}

// Konstanten fuer den Zugriff in der Tabelle
// 1. Spalte: Nennwert-Toleranz
// 2. Spalte: Nennwert
// 3. Spalte: Nennwert+Toleranz
#define LOWER_BOUND 0
#define SET_VALUE 1
#define UPPER_BOUND 2

double compute_values(double e_series, int decade, double tolerance, double table[192][3]) {
	for (int i = 0; i <= e_series; i++) {
		table[i][SET_VALUE] = (pow(pow(10, 1 / e_series), i)) * (pow(10, decade));
		table[i][LOWER_BOUND] = table[i][SET_VALUE] - (table[i][SET_VALUE] * tolerance);
		table[i][UPPER_BOUND] = table[i][SET_VALUE] + (table[i][SET_VALUE] * tolerance);
	}
	return 0;
}

int test_function(int faktor) {
	double runde_zahl_auf = faktor;
	double neue_runde_zahl = runde_zahl_auf;

	while (neue_runde_zahl <= runde_zahl_auf + 1)
	{
		neue_runde_zahl = neue_runde_zahl + 0.00001;
	}

	printf("\n\t%d", (int)neue_runde_zahl);
	return 0;
}

int main()
{
	do
	{
		printf("\n\n\tProgramm zur Berechnung von Widerstandsreihen\n");
		printf("\t--------------------------------------------------------\n");

		// lese gewuenschte E-Reihe und Dekade
		double e_series = read_e_series();
		int decade = read_decade();

		// bestimme erste die Toleranz und dann die Werte der Tabelle -
		// in jeder Zeile jeweils untere Grenze, Sollwert und obere Grenze
		double table[192][3];
		double tolerance = compute_tolerance(e_series);

		if (compute_values(e_series, decade, tolerance, table) != 0) {
			printf("[FEHLER] Es gab ein Problem bei der Berechnung der Werte f�r die Tabelle!");
		}

		if (print_table(table, e_series, tolerance) != 0) {
			printf("[FEHLER] Die Tabelle konnte nicht angezeigt werden!");
		}

		// bestimme die Farbcodierung eines gewaehlten Widerstands
		char coding[80];
		/*int n = read_list_number(e_series);
		compute_coding(e_series, table[n][SET_VALUE], tolerance, coding);
		printf("Die Farbcodierung dieses Widerstands ist: %s\n", coding);*/

		print_digits(table, e_series);

		getMultiplierRing(decade, e_series);

		printf("%s", getToleranceRing(e_series));

		printf("\n\n\terneute Berechnung? (j/n)\n\t");
	} while (getchar() == 'j' || getchar() == 'J');
}