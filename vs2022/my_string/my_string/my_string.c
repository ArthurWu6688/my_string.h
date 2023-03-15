#include "my_string.h"

//�ַ������ȼ��㲻ͳ�ƽ�β��־
size_t my_strlen(const char* str) {
	const char* ptr = str;
	while (*str != '\0') {
		++str;//str����ƶ�ֱ��������β��־ʱ����ѭ��
	}
	return str - ptr;//����ָ������õ���������ָ��֮������Ԫ�ظ���
}

char* my_strcpy(char* dest, const char* src) {
	//��src�ռ���ַ���������destָ��Ŀռ��У�������β��־����
	assert(src != NULL);
	assert(dest != NULL);
	char* ptr = dest;//��dest�ռ��ַ��ֵ��ptr����ptrҲָ�����ռ�
	while (*ptr++ = *src++);//���ַ���ֵ���ȼ��� *ptr=*src; ++ptr; ++src;
	return dest;//������ʼ��ַ
}

char* my_strcat(char* dest, const char* src) {
	assert(dest != NULL);
	assert(src != NULL);
	char* ptr = dest;
	while (*ptr != '\0') {
		++ptr;	//ptr����ƶ�ֱ��������β��־ʱ�˳�ѭ������ʱptrָ��dest��'\0'��

	}while (*ptr++ = *src++);//���ַ���ֵ
	return dest;//������ʼ��ַ
}

int my_strcmp(const char* str1, const char* str2) {
	assert(str1 != NULL);
	assert(str2 != NULL);
	while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2) {//ֻҪ�����ַ���û�дﵽ��β���������ַ������ַ���ͬ��һֱѭ�����
		++str1;
		++str2;
	}
	//����ѭ��������һ���ַ��������β�˻��������ַ������ַ��������
	return *str1 - *str2;
}

char* my_strncpy(char* dest, char* src, int n) {//��src�ַ����п���n���ַ���dest��
	assert(dest != NULL);
	assert(src != NULL);
	char* ptr = dest;
	while ((*ptr = *src) && (n--)) {//�ַ�������ֱ��\0��β����nΪ0��Ҳ���ǿ�����ָ������
		++ptr;
		++src;
	}
	//��������ɣ��п�����ΪnΪ0����ѭ������ʱdestĩβ�����ǽ�β��־
	*ptr = '\0';//��destĩβ����Ϊ��β��־
	return dest;
}

char* my_strncat(char* dest, char* src, int n) {
	assert(dest != NULL);
	assert(src != NULL);
	char* ptr = dest;
	while (*ptr != '\0') {
		++ptr;//ptr����ƶ�ֱ��ָ����β��־����
	}
	while ((*ptr = *src) && (n--)) {//�ӽ�β��־�����ַ���src��dest����
		++ptr;
		++src;
	}
	//��������ɣ��п�����ΪnΪ0����ѭ������ʱdestĩβ�����ǽ�β��־
	*ptr = '\0';//��destĩβ����Ϊ��β��־
	return dest;
}

int my_strncmp(char* str1, char* str2, int n) {
	assert(str1 != NULL);
	assert(str2 != NULL);
	//ָ������ƶ��Ĵ�����n-1�Σ���������Ϊn>1
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
			return ptr;//ptrָ����ַ�����ch�򷵻����λ�õĵ�ַ
		}
		++ptr;
	}
	return NULL;
}

const char* my_strstr(const char* str1, char* str2) {
	while (*str1 != '\0') {
		const char* s1 = str1;//str1���浱ǰ������λ��
		char* s2 = str2;
		//��s1��ʼ�����ͬ�������������ַ��Ƚ�
		while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
			//����ѭ����ʱ��Ҫ������s1s2ָ����ַ���ͬ��Ҫ������s1����s2�ߵ���β��
			++s1;
			++s2;
		}
			if (*s2 == '\0')
				return str1;//��s2�ߵ���β�����ʾ�ҵ��˶�Ӧ���ַ���
			if (*s1 == '\0')
				break;//��s1�ߵ���β����ʾstr1�Ѿ���������
		++str1;//��ǰλ���ַ�������ַ�����ʼλ���ַ���ͬ��������ƶ���������һ���ַ����ж�
	}
	return NULL;
}