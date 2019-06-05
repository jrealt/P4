#pragma once

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void show_content_of_file(const char * path);
bool check_content_of_file(const char * path, const char * find);
void diff_two_files(const char * path, const char * diff_path);

FILE* open_file(const char * filename);
FILE* create_file(const char * filename);