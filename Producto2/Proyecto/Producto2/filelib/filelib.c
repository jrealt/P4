#include "filelib.h"
#include "..\consolelib\consolelib.h"

/*
	Función para mostrar el contenido de un archivo
*/
void show_content_of_file() {
	print_msg("============================================");
	print_msg("Introduce la ruta del archivo a leer:");
	const char * path[255];
	// Obetenemos mediante consola, la ruta del archivo
	read_string(path, 255);

	// Abrimos el archivo
	FILE * ptr_file = open_file(path);
	// Si el archivo no existe retornamos
	if (ptr_file == NULL)
	{
		print_msg("El archivo no existe.");
		return;
	}
	print_msg("========== Contenido del archivo: ==========");
	char c;
	c = fgetc(ptr_file);
	// Mientras que no lleguemos al final del archivo
	while (c != EOF)
	{
		// Escribimos en consola cada carácter del archivo
		print_char(c);
		c = fgetc(ptr_file);
	}
	print_line_break();
	// Cerramos el archivo
	fclose(ptr_file);
}

/*
	Función para guardar como, un archivo
*/
void save_file_as() {
	print_msg("============================================");
	print_msg("Introduce la ruta del archivo a copiar:");
	const char * path[255];
	// Obetenemos mediante consola, la ruta del archivo origen
	read_string(path, 255);

	// Abrimos el archivo
	FILE * ptr_file = open_file(path);
	// Si el archivo no existe retornamos
	if (ptr_file == NULL)
	{
		print_msg("El archivo no existe.");
		return;
	}

	print_msg("Introduce la ruta del archivo destino:");
	const char * path_cp[255];
	// Obetenemos mediante consola, la ruta del archivo destino
	read_string(path_cp, 255);

	// Creamos el archivo
	FILE * ptr_file_cp = create_file(path_cp);
	// Si ha habido error al crear el archivo retornamos
	if (ptr_file_cp == NULL)
	{
		print_msg("Error al crear el archivo.");
		return;
	}

	print_msg("Archivo destino creado.");

	char c;
	c = fgetc(ptr_file);
	// Mientras que no lleguemos al final del archivo
	while (c != EOF)
	{
		// Copiamos cada carácter del archivo origen, en el archivo destino
		fputc(c, ptr_file_cp);
		c = fgetc(ptr_file);
	}
	print_line_break();
	// Cerramos el archivo origen
	fclose(ptr_file);
	// Borramos el archivo origen
	if (remove(path) != 0)
		print_msg("No se pudo eliminar el archivo de origen.");
	else
		print_msg("Archivo origen eliminado.");
	// Cerramos el archivo destino
	fclose(ptr_file_cp);
}

/*
	Función para chequear el contenido de un archivo
*/
void check_content_of_file() {
	print_msg("============================================");
	print_msg("Introduce la ruta del archivo a buscar:");
	const char * path[255];
	// Obetenemos mediante consola, la ruta del archivo
	read_string(path, 255);

	// Abrimos el archivo
	FILE * ptr_file = open_file(path);
	// Si el archivo no existe retornamos
	if (ptr_file == NULL)
	{
		print_msg("El archivo no existe.");
		return;
	}

	print_msg("Introduce la palabra o frase a buscar:");
	const char * word[255];
	// Obetenemos mediante consola, la palabra o frase a buscar
	read_string(word, 255);

	char c;
	c = fgetc(ptr_file);
	bool found = FALSE;
	char line[1024];

	// Por cada linea del archivo
	while (fgets(line, 1024, ptr_file) != NULL) {
		// Comprobamos si contiene la palabra o frase a buscar
		if ((strstr(line, word)) != NULL) {
			// Si la contiene, seteamos como encontrada y rompemos el bucle
			found = TRUE;
			break;
		}
	}

	// Cerramos el archivo
	fclose(ptr_file);

	// Mostramos en consola el resultado
	if (found) {
		print_msg("Palabra encontrada!");
	}
	else {
		print_msg("Palabra no encontrada.");
	}
}

/*
	Función para abrir un archivo
*/
FILE* open_file(const char * filename) {
	return fopen(filename, "r+");
}

/*
	Función para crear un archivo
*/
FILE* create_file(const char * filename) {
	return fopen(filename, "w");
}