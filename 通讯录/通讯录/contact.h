#define _CRT_SECURE_NO_WARNINGS 1
#pragma once //����ͬһ��ͷ�ļ�����ΰ���
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
typedef struct Contact//����һ����ϵ�˵Ľṹ��
{
	char _name[24];
	char _tel[16];
	char _address[64];
	int _age;
}Contact;
//typedef struct Contact Contact;//�ṹ��������

typedef struct ContactBook//����һ��ͨѶ¼
{
	Contact *_con_array;//����������̬����
	size_t _size;//ʵ�ʴ��ڵ���ϵ�˸���
	size_t _capacity;//����
}ContactBook;

void ContactBookInit(ContactBook* pbook);//��ʼ��
void ContactBookDestory(ContactBook* pbook);//����
void ContactBookAppend(ContactBook* pbook,Contact *pcon);//�����ϵ��pcon��pbook��
void ContactBookDelete(ContactBook* pbook, const char* name);//ͨ������ɾ����ϵ��
Contact* ContactBookFind(ContactBook* pbook, const char* name);//ͨ������������ϵ��
void ContactBookSave(ContactBook* pbook, const char* file);//�־û�����ͨѶ¼д���ļ��У�
void ContactBookLoad(ContactBook* pbook, const char* file);//���ļ��н��������
void ContactPrint(ContactBook* pbook);//��ӡͨѶ¼
void menu();//�˵�



