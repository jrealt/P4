#include "..\filelib\filelib.h"
#include "..\consolelib\consolelib.h"

/*
Función main, entry point de la aplicación de consola.
*/
int main()
{
	printf("%s\n", "============================================");
	printf("%s\n", "Introduce la ruta del archivo hosts.");
	const char * path[255];
	// Obtenemos mediante consola, la ruta del archivo
	read_string(path, 255);
	// Mostramos el contenido del archivo por consola
	show_content_of_file(path);

	printf("%s\n", "============================================");
	printf("%s\n", "Introduce la ruta del archivo pares.");
	const char * diff_path[255];
	// Obtenemos mediante consola, la ruta del archivo
	read_string(diff_path, 255);
	// Hacemos la comparación de los dos archivos y copiamos la diferencia
	diff_two_files(path, diff_path);
	// Mostramos el contenido del archivo por consola
	show_content_of_file(path);
	
	system("pause");
    return 0;
}

