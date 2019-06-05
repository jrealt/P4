#include "consolelib.h"

/*
	Función para escribir por consola un salto de línea
*/
void print_line_break() {
	printf("\n");
}

/*
	Función para escribir por consola un carácter
*/
void print_char(char c) {
	printf("%c", c);
}

/*
	Función para escribir por consola una cadena de caracteres
*/
void print_msg(const char * msg) {
	printf("%s\n", msg);
}

/*
	Función para escribir por consola una cadena de caracteres seguida de un entero
*/
void print_msg_int(const char * msg, int integer) {
	printf("%s%d\n", msg, integer);
}

/*
	Función para obtener un entero por consola
*/
int ask_for_integer() {
	int integer;
	scanf_s("%d", &integer);
	return integer;
}

/*
	Función para obtener una cadena de caracteres por consola
*/
int read_string(char *cad, int n) {

	int i, c;

	c = getchar();

	if (c == EOF) {
		cad[0] = '\0';
		return 0;
	}

	if (c == '\n')
		i = 0;

	else {
		cad[0] = c;
		i = 1;
	}

	for (; i < n - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		cad[i] = c;

	cad[i] = '\0';

	if (c != '\n' && c != EOF)
		while ((c = getchar()) != '\n' && c != EOF);
	return 1;
};