#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
//int main()
//{
//	ContactBook cb;//定义一个通讯录
//	ContactBookInit(&cb);
//	Contact con1;
//	strcpy(con1._address, "西安市长安区王曲街道");
//	strcpy(con1._name, "小猫");
//	strcpy(con1._tel, "18937710107");
//	con1._age = 18;
//
//	Contact con2;
//	strcpy(con2._address, "西安市长安区西安财经大学");
//	strcpy(con2._name, "小狗");
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
	//char x[16] = "小猫";
	ContactBookInit(&cb);
	ContactBookLoad(&cb, "柳阿九的通讯录.txt");
	////ContactPrint(&cb);
	//ContactBookFind(&cb, &x, "contactbookbin.txt");
	//ContactBookDestory(&cb);
	int option = -1;
	while (option != 0)
	{
		menu();
		scanf("%d", &option);
		if (option == 1)//添加联系人
		{
			Contact con;
			printf("===========================================\n");
			printf("请依次输入：姓名、电话、家庭住址、年龄。\n");
			printf("===========================================\n");
			scanf("%s", con._name);
			scanf("%s", con._tel);
			scanf("%s", con._address);
			scanf("%d", &con._age);
			ContactBookAppend(&cb, &con);
			printf("===========================================\n");
			printf("保存成功!\n");
			printf("===========================================\n");
		}
		else if (option == 2)//删除联系人
		{
			const char name1[24];			
			printf("===========================================\n");
			printf("请输入所要删除联系人的姓名：\n");
			printf("===========================================\n");
			scanf("%s", name1);
			ContactBookDelete(&cb, name1);
		}
		else if (option == 3)//查找联系人
		{
			const char name2[24];
			printf("===========================================\n");
			printf("请输入所要查找联系人的姓名：\n");
			printf("===========================================\n");
			scanf("%s", name2);
			Contact* pcon = ContactBookFind(&cb, name2);
			if (pcon == NULL)
			{
				printf("===========================================\n");
				printf("该联系人不存在。\n");
				printf("===========================================\n");
			}
			else
			{
				printf("===========================================\n");
				printf("姓名：%s\n", pcon->_name);
				printf("电话号码：%s\n",pcon->_tel);
				printf("地址：%s\n", pcon->_address);
				printf("年龄：%d\n",pcon->_age);
				printf("===========================================\n");
			}
		}
		else if (option == 4)//修改联系人
		{
		}
		else if (option == 5)//保存到文件中
		{
			ContactBookSave(&cb, "柳阿九的通讯录.txt");
		}
		else if (option == 6)//从文件中加载
		{
			ContactBookLoad(&cb, "柳阿九的通讯录.txt");
		}
		else if (option == 7)//启动打印菜单
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