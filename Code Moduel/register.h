#pragma once
//�û��ṹ��(������ͨ�û��ͳ���)
//��װ�к���ע��͵�¼
//����ˣ��Զ�˸
#include<iostream>
struct user {
	char account[20];
	char password[20];
	char key[20];					//����Ա��¼�������Կ
	virtual bool registerNuser();	//ע����ͨ�û�
	virtual bool nomal_login();		//��ͨ�û���¼
	virtual bool super_login();		//���ܵ�¼
	user() {
		strcpy(this->key, "abcd");
	}
};
