#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
//int main()
//{
//	ContactBook cb;//����һ��ͨѶ¼
//	ContactBookInit(&cb);
//	Contact con1;
//	strcpy(con1._address, "�����г����������ֵ�");
//	strcpy(con1._name, "Сè");
//	strcpy(con1._tel, "18937710107");
//	con1._age = 18;
//
//	Contact con2;
//	strcpy(con2._address, "�����г����������ƾ���ѧ");
//	strcpy(con2._name, "С��");
//	strcpy(con2._tel, "18937710108");
//	con2._age = 18;
//
//	
//	ContactBookAppend(&cb, &con1);
//	ContactBookAppend(&cb, &con2);
//	ContactPrint(&cb);
//	//ContactBookSave(&cb, "contactbookbin.txt");
//	ContactBookDestory(&cb);
//
//	system("pause");
//	return 0;
//}
int main()
{
	ContactBook cb;
	//char x[16] = "Сè";
	ContactBookInit(&cb);
	ContactBookLoad(&cb, "�����ŵ�ͨѶ¼.txt");
	////ContactPrint(&cb);
	//ContactBookFind(&cb, &x, "contactbookbin.txt");
	//ContactBookDestory(&cb);
	int option = -1;
	while (option != 0)
	{
		menu();
		scanf("%d", &option);
		if (option == 1)//�����ϵ��
		{
			Contact con;
			printf("===========================================\n");
			printf("���������룺�������绰����ͥסַ�����䡣\n");
			printf("===========================================\n");
			scanf("%s", con._name);
			scanf("%s", con._tel);
			scanf("%s", con._address);
			scanf("%d", &con._age);
			ContactBookAppend(&cb, &con);
			printf("===========================================\n");
			printf("����ɹ�!\n");
			printf("===========================================\n");
		}
		else if (option == 2)//ɾ����ϵ��
		{
			const char name1[24];			
			printf("===========================================\n");
			printf("��������Ҫɾ����ϵ�˵�������\n");
			printf("===========================================\n");
			scanf("%s", name1);
			ContactBookDelete(&cb, name1);
		}
		else if (option == 3)//������ϵ��
		{
			const char name2[24];
			printf("===========================================\n");
			printf("��������Ҫ������ϵ�˵�������\n");
			printf("===========================================\n");
			scanf("%s", name2);
			Contact* pcon = ContactBookFind(&cb, name2);
			if (pcon == NULL)
			{
				printf("===========================================\n");
				printf("����ϵ�˲����ڡ�\n");
				printf("===========================================\n");
			}
			else
			{
				printf("===========================================\n");
				printf("������%s\n", pcon->_name);
				printf("�绰���룺%s\n",pcon->_tel);
				printf("��ַ��%s\n", pcon->_address);
				printf("���䣺%d\n",pcon->_age);
				printf("===========================================\n");
			}
		}
		else if (option == 4)//�޸���ϵ��
		{
		}
		else if (option == 5)//���浽�ļ���
		{
			ContactBookSave(&cb, "�����ŵ�ͨѶ¼.txt");
		}
		else if (option == 6)//���ļ��м���
		{
			ContactBookLoad(&cb, "�����ŵ�ͨѶ¼.txt");
		}
		else if (option == 7)//������ӡ�˵�
		{
			ContactPrint(&cb);
		}
		else if (option == 0)
		{
			break;
		}
	}
	system("pause");
	return 0;
}