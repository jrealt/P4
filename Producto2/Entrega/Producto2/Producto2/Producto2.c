#include "Producto2.h"
#include "..\filelib\filelib.h"
#include "..\consolelib\consolelib.h"

/*
Carácteres especiales:
Á \-75
É \-112
Í \-42
Ó \-32
Ú \-23
á \240
é \202
í \241
ó \242
ú \243
ñ \244
Ñ \245
*/

/*
	Función main, entry point de la aplicación de consola.
*/
int main()
{
	// Mostramos el menú de la aplicación de consola.
	show_menu();

	system("pause");

    return 0;
}

/*
	Función para construir el menú de la aplicación de consola.
*/
void show_menu() {
	print_msg("============================================");
	print_msg("Especifica que quieres hacer por su numero:");
	print_msg("1. Mostrar el contenido de un archivo.");
	print_msg("2. Guardar como un archivo.");
	print_msg("3. Chequear el contenido de un archivo.");
	// Preguntamos por la opción a ejecutar.
	int selected = ask_for_integer();
	print_msg_int("Has seleccionado: ", selected);
	switch (selected)
	{
	case 1:
		// Mostramos el contenido de un archivo
		show_content_of_file();
		break;
	case 2:
		// Guardamos como, un archivo
		save_file_as();
		break;
	case 3:
		// Chequeamos el contenido de un archivo
		check_content_of_file();
		break;
	default:
		print_msg("La opci\242n seleccionada no es correcta.");
		// Volvemos a mostrar el menú si la opción seleccionada no es correcta
		show_menu();
	}
}