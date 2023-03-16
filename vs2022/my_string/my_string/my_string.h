#pragma once

#include <stdio.h>
#include <assert.h>

size_t my_strlen(const char* str);
char* my_strcpy(char* dest, const char* src);
char* my_strcat(char* dest, const char* src);
int my_strcmp(const char* str1, const char* str2);
char* my_strncpy(char* dest, char* src,int n);
char* my_strncat(char* dest, char* src, int n);
int my_strncmp(char* str1, char* str2, int n);
const char* my_strchr(const char* str, char ch);
const char* my_strstr(const char* str1, char* str2);
char* my_strtok(char* str, char* sep);