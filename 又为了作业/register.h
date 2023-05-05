#pragma once
//用户结构体(包含普通用户和超管)
//封装有函数注册和登录
//完成人：赵恩烁
#include<iostream>
struct user {
	char account[20];
	char password[20];
	char key[20];					//管理员登录所需的密钥
	virtual bool registerNuser();	//注册普通用户
	virtual bool nomal_login();		//普通用户登录
	virtual bool super_login();		//超管登录
	user() {
		strcpy(this->key, "abcd");
	}
};
