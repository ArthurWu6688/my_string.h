#include "my_string.h"

int main() {

	//printf("len:%d\n", my_strlen("hello world!"));

	//char buf[32];
	////char* buf="nihaoa !" buf保存的是字面常量的字符串的空间地址 使用my_strcpy会导致内存访问错误
	//char* data = "hello";
	//my_strcpy(buf, data);
	//printf("%s\n", buf);

	/*char buf[32] = "hello";
	char* str = "World";
	my_strcat(buf, str);
	printf("%s", buf);*/

	/*char* str1 = "hello";
	char* str2 = "world";
	int ret = my_strcmp(str1, str2);
	printf("%d\n", ret);*/

	/*char buf[32] = "nihao";
	char* str = "Hello World!";

	my_strncpy(buf, str, 5);
	printf("[%s]\n", buf);*/

	/*char buf[32] = "hello";
	char* str = "hello World!";

	int ret = my_strncmp(buf, str, 1);
	printf("%d", ret);*/

	/*char* s1 = "hello world";
	const char* ret = my_strchr(s1, 'e');
	printf("%s", ret);*/

	/*char* s1 = "hello nihaoa xiaoming";
	char* s2 = "nihaoa";
	const char* ret = my_strstr(s1, s2);
	printf("%s", ret);*/

	char str[] = "ni hao,peng  , .     you!!";
	char* ptr = my_strtok(str, " ");

	if (ptr != NULL)
		printf("[%s]\n", ptr);

	while ((ptr = my_strtok(NULL, ",. ")) != NULL) {
		printf("[%s]\n", ptr);
	}

	return 0;
}