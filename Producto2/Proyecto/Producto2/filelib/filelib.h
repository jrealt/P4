#pragma once

#include <stdio.h>

void show_content_of_file();
void save_file_as();
void check_content_of_file();

FILE* open_file(const char * filename);
FILE* create_file(const char * filename);

typedef enum { FALSE, TRUE } bool; /*  tipo booleano  */