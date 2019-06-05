#include "filelib.h"

/*
	Función para mostrar el contenido de un archivo
*/
void show_content_of_file(const char * path) {
	// Abrimos el archivo
	FILE * ptr_file = open_file(path);
	// Si el archivo no existe retornamos
	if (ptr_file == NULL)
	{
		printf("%s\n", "El archivo no existe.");
		return;
	}
	printf("%s%s%s\n", "========== Contenido del archivo: ", path, " ==========");
	char c;
	c = fgetc(ptr_file);
	// Mientras que no lleguemos al final del archivo
	while (c != EOF)
	{
		// Escribimos en consola cada carácter del archivo
		printf("%c", c);
		c = fgetc(ptr_file);
	}
	printf("\n");
	// Cerramos el archivo
	fclose(ptr_file);
}

/*
	Función para chequear el contenido de un archivo
*/
bool check_content_of_file(const char * path, const char * find) {

	// Abrimos el archivo
	FILE * ptr_file = open_file(path);
	// Si el archivo no existe retornamos
	if (ptr_file == NULL)
	{
		printf("%s\n", "El archivo no existe.");
		return false;
	}

	bool found = false;
	char * line[1024];

	// Por cada linea del archivo
	while (fgets(line, 1024, ptr_file) != NULL) {
		// Comprobamos si contiene la palabra o frase a buscar
		if ((strstr(line, find)) != NULL) {
			// Si la contiene, seteamos como encontrada y rompemos el bucle
			found = true;
			break;
		}
	}

	// Cerramos el archivo
	fclose(ptr_file);

	// Retornamos found
	return found;
}

/*
	Función para comparar dos archivos, agregar las diferencias a un archivo temporal y aplicarlos al archivo principal
*/
void diff_two_files(const char * path, const char * diff_path) {
	// Abrimos el archivo diff
	FILE * ptr_file_diff = open_file(diff_path);
	// Si el archivo no existe retornamos
	if (ptr_file_diff == NULL)
	{
		printf("%s\n", "El archivo no existe.");
		return;
	}

	// Creamos el archivo temporal
	FILE * ptr_file_tmp = tmpfile();
	// Si el archivo no existe retornamos
	if (ptr_file_tmp == NULL)
	{
		printf("%s\n", "Error al crear el archivo temporal.");
		return;
	}

	char * line[1024];
	
	// Por cada linea del archivo diff
	while (fgets(line, 1024, ptr_file_diff) != NULL) {
		// Comprobamos si contiene el contenido de la linea
		if (!check_content_of_file(path, line)) {
			// La añadimos al archivo temporal
			fputs(line, ptr_file_tmp);
		}
	}
	// Posicionamos el puntero al principio
	fseek(ptr_file_tmp, 0, SEEK_SET);

	// Abrimos el archivo
	FILE * ptr_file = open_file(path);
	// Si el archivo no existe retornamos
	if (ptr_file == NULL)
	{
		printf("%s\n", "El archivo no existe.");
		return;
	}
	// Posicionamos el puntero al final
	fseek(ptr_file, 0, SEEK_END);
	fputs("\n", ptr_file);
	// Por cada linea del archivo 
	while (fgets(line, 1024, ptr_file_tmp) != NULL) {
		// La añadimos al archivo
		fputs(line, ptr_file);
	}

	// Cerramos los archivos
	fclose(ptr_file);
	fclose(ptr_file_diff);
	fclose(ptr_file_tmp); //El archivo temporal se borra solo al cerrarlo
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