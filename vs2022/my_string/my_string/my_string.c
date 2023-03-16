#include "my_string.h"

//字符串长度计算不统计结尾标志
size_t my_strlen(const char* str) {
	const char* ptr = str;
	while (*str != '\0') {
		++str;//str向后移动直到遇到结尾标志时跳出循环
	}
	return str - ptr;//两个指针相减得到的是两个指针之间间隔的元素个数
}

char* my_strcpy(char* dest, const char* src) {
	//将src空间的字符串拷贝到dest指向的空间中，包含结尾标志在内
	assert(src != NULL);
	assert(dest != NULL);
	char* ptr = dest;//将dest空间地址赋值给ptr，让ptr也指向这块空间
	while (*ptr++ = *src++);//逐字符赋值，等价于 *ptr=*src; ++ptr; ++src;
	return dest;//返回起始地址
}

char* my_strcat(char* dest, const char* src) {
	assert(dest != NULL);
	assert(src != NULL);
	char* ptr = dest;
	while (*ptr != '\0') {
		++ptr;	//ptr向后移动直到遇到结尾标志时退出循环，此时ptr指向dest的'\0'处

	}while (*ptr++ = *src++);//逐字符赋值
	return dest;//返回起始地址
}

int my_strcmp(const char* str1, const char* str2) {
	assert(str1 != NULL);
	assert(str2 != NULL);
	while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2) {//只要任意字符串没有达到结尾并且两个字符串的字符相同就一直循环向后
		++str1;
		++str2;
	}
	//跳出循环：任意一个字符串到达结尾了或者两个字符串的字符不相等了
	return *str1 - *str2;
}

char* my_strncpy(char* dest, char* src, int n) {//从src字符串中拷贝n个字符到dest中
	assert(dest != NULL);
	assert(src != NULL);
	char* ptr = dest;
	while ((*ptr = *src) && (n--)) {//字符串拷贝直到\0结尾或者n为0，也就是拷贝了指定长度
		++ptr;
		++src;
	}
	//当拷贝完成，有可能因为n为0跳出循环，此时dest末尾并不是结尾标志
	*ptr = '\0';//将dest末尾设置为结尾标志
	return dest;
}

char* my_strncat(char* dest, char* src, int n) {
	assert(dest != NULL);
	assert(src != NULL);
	char* ptr = dest;
	while (*ptr != '\0') {
		++ptr;//ptr向后移动直到指到结尾标志结束
	}
	while ((*ptr = *src) && (n--)) {//从结尾标志起逐字符从src向dest拷贝
		++ptr;
		++src;
	}
	//当拷贝完成，有可能因为n为0跳出循环，此时dest末尾并不是结尾标志
	*ptr = '\0';//将dest末尾设置为结尾标志
	return dest;
}

int my_strncmp(char* str1, char* str2, int n) {
	assert(str1 != NULL);
	assert(str2 != NULL);
	//指针向后移动的次数是n-1次，所以条件为n>1
	while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2 && n>1) {
		++str1;
		++str2;
		--n;
	}
	return *str1 - *str2;
}

const char* my_strchr(const char* src, char ch) {
	assert(src != NULL);
	const char* ptr = src;
	while (*ptr != '\0') {
		if (ch == *ptr) {
			return ptr;//ptr指向的字符就是ch则返回这个位置的地址
		}
		++ptr;
	}
	return NULL;
}

const char* my_strstr(const char* str1, char* str2) {
	while (*str1 != '\0') {
		const char* s1 = str1;//str1保存当前遍历的位置，让s1也指向这个位置
		char* s2 = str2;//让s2指向str2起始位置
		//进行相同判断的时候用s1和s2是为了避免丢失str2的起始地址
		//从s1开始如果相同，则连续进行字符比较
		while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
			//跳出循环的时候要不就是s1s2指向的字符不同，要不就是s1或者s2走到结尾了
			++s1;
			++s2;
		}
			if (*s2 == '\0')
				return str1;//当s2走到结尾，则表示找到了对应的字符串
			if (*s1 == '\0')
				break;//当s1走到结尾，表示str1已经查找完了
		++str1;//当前位置字符与查找字符串起始位置字符不同，则向后移动，进行下一个字符的判断
	}
	return NULL;
}

char* my_strtok(char* str, char* sep) {
	static char* start;
	if (str != NULL) {
		start = str;//如果外界传入的不是空，则保存传入字符串的起始地址
	}
	char* ptr = start;
	char* res = start;
	if (*start == '\0')
		return NULL;//当某一次分割时发现start已经到达了字符串末尾，则返回NULL
	while (*ptr != '\0') {
		for (int i = 0; sep[i] != '\0'; ++i) {
			if (*ptr == sep[i]) {
				if (ptr == start) {//当前start所指位置就是一个间隔符
					start = ptr + 1;
					res = start;//重置ptr和res的值，然后从下一个位置重新查找间隔符
					break;
				}
				*ptr = '\0';//将间隔符替换为字符串结尾标志
				start = ptr + 1;//让start指向当前间隔符下一个位置
				return res;//返回本次子串的起始地址
			}
		}
		++ptr;
	}
	start = ptr;//当跳出循环意味着ptr走到了结尾处,意味着字符串扫面完了，要将start设置为末尾
	return res;
}