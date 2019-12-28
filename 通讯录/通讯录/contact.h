#define _CRT_SECURE_NO_WARNINGS 1
#pragma once //避免同一个头文件被多次包含
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
typedef struct Contact//定义一个联系人的结构体
{
	char _name[24];
	char _tel[16];
	char _address[64];
	int _age;
}Contact;
//typedef struct Contact Contact;//结构体重命名

typedef struct ContactBook//定义一个通讯录
{
	Contact *_con_array;//便于容量动态开辟
	size_t _size;//实际存在的联系人个数
	size_t _capacity;//容量
}ContactBook;

void ContactBookInit(ContactBook* pbook);//初始化
void ContactBookDestory(ContactBook* pbook);//销毁
void ContactBookAppend(ContactBook* pbook,Contact *pcon);//添加联系人pcon到pbook中
void ContactBookDelete(ContactBook* pbook, const char* name);//通过姓名删除联系人
Contact* ContactBookFind(ContactBook* pbook, const char* name);//通过姓名查找联系人
void ContactBookSave(ContactBook* pbook, const char* file);//持久化（将通讯录写到文件中）
void ContactBookLoad(ContactBook* pbook, const char* file);//从文件中将其读出来
void ContactPrint(ContactBook* pbook);//打印通讯录
void menu();//菜单



