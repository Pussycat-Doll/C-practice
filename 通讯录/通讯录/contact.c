#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

void ContactBookInit(ContactBook* pbook)//初始化
{
	assert(pbook);
	pbook->_con_array = (Contact*)malloc(sizeof(Contact)* 8);//强转与编译器有关
	if (pbook->_con_array == NULL)//检验新空间是否开辟成功
	{
		printf("===========================================\n");
		printf("malloc error\n");
		printf("===========================================\n");
		exit(-1);//退出整个程序，终止进程，并返回-1给操作系统
	}
	pbook->_size = 0;
	pbook->_capacity = 8;
}

void ContactBookDestory(ContactBook* pbook)//销毁
{
	assert(pbook);
	free(pbook->_con_array);//释放空间
	pbook->_con_array = NULL;//指针置为空
	pbook->_size = pbook->_capacity = 0;//数据容量初始化
}

void ContactBookAppend(ContactBook* pbook, Contact *pcon)//添加联系人pcon到pbook中
{
	assert(pbook && pcon);
	if (pbook->_size >= pbook->_capacity)//容量不够了
	{
		Contact* newarray = (Contact*)realloc(pbook->_con_array, sizeof(pbook->_con_array)*pbook->_capacity * 2);//检验新空间是否开辟成功
		if (newarray == NULL)
		{
			printf("===========================================\n");
			printf("realloc error\n");
			printf("===========================================\n");
			exit(-1);
		}
		pbook->_con_array = newarray;//将开辟的新空间地址传过去
	}
	Contact* array = pbook->_con_array;
	size_t i = pbook->_size;
	strcpy(array[i]._name, pcon->_name);
	strcpy(array[i]._tel, pcon->_tel);
	strcpy(array[i]._address, pcon->_address);//添加新的联系人的信息
	array[i]._age = pcon->_age;

	pbook->_size++;//联系人个数+1
}
void ContactPrint(ContactBook* pbook)//打印通讯录
{
	for (size_t i = 0; i < pbook->_size; i++)
	{
		printf("===========================================\n");
		printf("姓名：%s\n", pbook->_con_array[i]._name);
		printf("电话号码：%s\n", pbook->_con_array[i]._tel);
		printf("地址：%s\n", pbook->_con_array[i]._address);
		printf("年龄：%d\n", pbook->_con_array[i]._age);
		printf("===========================================\n");
	}
}

void ContactBookSave(ContactBook* pbook, const char* file)//持久化（将通讯录写到文件中）
{
	FILE* fp = fopen(file, "a");//追加写方式打开文件
	if (fp == NULL)
	{
		printf("===========================================\n");
		printf("打开文件失败\n");
		printf("===========================================\n");
		exit(-1);
	}
	Contact* array = pbook->_con_array;
	for (size_t i = 0; i < pbook->_size; i++)
	{
		/*fwrite(&(pbook->_con_array[i]), sizeof(Contact), 1, fp);*/
		fprintf(file, "%s%s%s%d", array[i]._name, array[i]._tel, array[i]._address, array[i]._tel);
	}
	fclose(fp);
}

void ContactBookLoad(ContactBook* pbook, const char* file)//从文件中将pbook读出来
{
	FILE* fp = fopen(file, "w");//只读方式打开文本文件
	if (fp == NULL)
	{
		printf("===========================================\n");
		printf("读取文件失败\n");
		printf("===========================================\n");
		exit(-1);
	}
	Contact con;//创建一个临时联系人的空间
	//while (fread(&con, sizeof(Contact), 1, fp) == 1)//将读取到的联系人放到上面创建的临时空间中
	//{
	//	ContactBookAppend(pbook, &con);//将其添加到pbook中
	//}
	while (fscanf(file, "%s%s%s%d",con._name,con._tel,con._address,&con._age )!=EOF)
	{
		ContactBookAppend(pbook, &con);
	}
	fclose(fp);//记得关闭文件夹
}
Contact* ContactBookFind(ContactBook* pbook, const char* name)//查找联系人
{
	assert(pbook && name);
	for (size_t i = 0; i < pbook->_size; i++)//遍历通讯录
	{
		if (strcmp(pbook->_con_array[i]._name, name) == 0)//进行比较
		{
			return &pbook->_con_array[i];
		}
	}
	return NULL;
}

void ContactBookDelete(ContactBook* pbook, const char* name)//通过姓名删除联系人
{
	Contact* pcon = ContactBookFind(pbook, name);
	if (pcon == NULL)
	{
		printf("===========================================\n");
		printf("该联系人不存在，无法删除该联系人\n");
		printf("===========================================\n");
		return;
	}
	while (pcon < pbook->_con_array + (pbook->_size-1))//
	{
		memcpy(pcon, pcon+1, sizeof(Contact));//将后面信息前移
		pcon++;
	}
	pbook->_size--;//成功删除一个人后，人数-1
	printf("===========================================\n");
	printf("删除成功!\n");
	printf("===========================================\n");
}

void menu()
{
	printf("*******************************************\n");
	printf("**********      1.添加联系人      *********\n");
	printf("**********      2.删除联系人      *********\n");
	printf("**********      3.查找联系人      *********\n");
	printf("**********      4.修改联系人      *********\n");
	printf("**********      5.保存到文件      *********\n");
	printf("**********      6.从文件加载      *********\n");
	printf("**********      7.打印通讯录      *********\n");
	printf("**********      0.退出通讯录      *********\n");
	printf("*******************************************\n");
}
