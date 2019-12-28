#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

void ContactBookInit(ContactBook* pbook)//��ʼ��
{
	assert(pbook);
	pbook->_con_array = (Contact*)malloc(sizeof(Contact)* 8);//ǿת��������й�
	if (pbook->_con_array == NULL)//�����¿ռ��Ƿ񿪱ٳɹ�
	{
		printf("===========================================\n");
		printf("malloc error\n");
		printf("===========================================\n");
		exit(-1);//�˳�����������ֹ���̣�������-1������ϵͳ
	}
	pbook->_size = 0;
	pbook->_capacity = 8;
}

void ContactBookDestory(ContactBook* pbook)//����
{
	assert(pbook);
	free(pbook->_con_array);//�ͷſռ�
	pbook->_con_array = NULL;//ָ����Ϊ��
	pbook->_size = pbook->_capacity = 0;//����������ʼ��
}

void ContactBookAppend(ContactBook* pbook, Contact *pcon)//�����ϵ��pcon��pbook��
{
	assert(pbook && pcon);
	if (pbook->_size >= pbook->_capacity)//����������
	{
		Contact* newarray = (Contact*)realloc(pbook->_con_array, sizeof(pbook->_con_array)*pbook->_capacity * 2);//�����¿ռ��Ƿ񿪱ٳɹ�
		if (newarray == NULL)
		{
			printf("===========================================\n");
			printf("realloc error\n");
			printf("===========================================\n");
			exit(-1);
		}
		pbook->_con_array = newarray;//�����ٵ��¿ռ��ַ����ȥ
	}
	Contact* array = pbook->_con_array;
	size_t i = pbook->_size;
	strcpy(array[i]._name, pcon->_name);
	strcpy(array[i]._tel, pcon->_tel);
	strcpy(array[i]._address, pcon->_address);//����µ���ϵ�˵���Ϣ
	array[i]._age = pcon->_age;

	pbook->_size++;//��ϵ�˸���+1
}
void ContactPrint(ContactBook* pbook)//��ӡͨѶ¼
{
	for (size_t i = 0; i < pbook->_size; i++)
	{
		printf("===========================================\n");
		printf("������%s\n", pbook->_con_array[i]._name);
		printf("�绰���룺%s\n", pbook->_con_array[i]._tel);
		printf("��ַ��%s\n", pbook->_con_array[i]._address);
		printf("���䣺%d\n", pbook->_con_array[i]._age);
		printf("===========================================\n");
	}
}

void ContactBookSave(ContactBook* pbook, const char* file)//�־û�����ͨѶ¼д���ļ��У�
{
	FILE* fp = fopen(file, "a");//׷��д��ʽ���ļ�
	if (fp == NULL)
	{
		printf("===========================================\n");
		printf("���ļ�ʧ��\n");
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

void ContactBookLoad(ContactBook* pbook, const char* file)//���ļ��н�pbook������
{
	FILE* fp = fopen(file, "w");//ֻ����ʽ���ı��ļ�
	if (fp == NULL)
	{
		printf("===========================================\n");
		printf("��ȡ�ļ�ʧ��\n");
		printf("===========================================\n");
		exit(-1);
	}
	Contact con;//����һ����ʱ��ϵ�˵Ŀռ�
	//while (fread(&con, sizeof(Contact), 1, fp) == 1)//����ȡ������ϵ�˷ŵ����洴������ʱ�ռ���
	//{
	//	ContactBookAppend(pbook, &con);//������ӵ�pbook��
	//}
	while (fscanf(file, "%s%s%s%d",con._name,con._tel,con._address,&con._age )!=EOF)
	{
		ContactBookAppend(pbook, &con);
	}
	fclose(fp);//�ǵùر��ļ���
}
Contact* ContactBookFind(ContactBook* pbook, const char* name)//������ϵ��
{
	assert(pbook && name);
	for (size_t i = 0; i < pbook->_size; i++)//����ͨѶ¼
	{
		if (strcmp(pbook->_con_array[i]._name, name) == 0)//���бȽ�
		{
			return &pbook->_con_array[i];
		}
	}
	return NULL;
}

void ContactBookDelete(ContactBook* pbook, const char* name)//ͨ������ɾ����ϵ��
{
	Contact* pcon = ContactBookFind(pbook, name);
	if (pcon == NULL)
	{
		printf("===========================================\n");
		printf("����ϵ�˲����ڣ��޷�ɾ������ϵ��\n");
		printf("===========================================\n");
		return;
	}
	while (pcon < pbook->_con_array + (pbook->_size-1))//
	{
		memcpy(pcon, pcon+1, sizeof(Contact));//��������Ϣǰ��
		pcon++;
	}
	pbook->_size--;//�ɹ�ɾ��һ���˺�����-1
	printf("===========================================\n");
	printf("ɾ���ɹ�!\n");
	printf("===========================================\n");
}

void menu()
{
	printf("*******************************************\n");
	printf("**********      1.�����ϵ��      *********\n");
	printf("**********      2.ɾ����ϵ��      *********\n");
	printf("**********      3.������ϵ��      *********\n");
	printf("**********      4.�޸���ϵ��      *********\n");
	printf("**********      5.���浽�ļ�      *********\n");
	printf("**********      6.���ļ�����      *********\n");
	printf("**********      7.��ӡͨѶ¼      *********\n");
	printf("**********      0.�˳�ͨѶ¼      *********\n");
	printf("*******************************************\n");
}
