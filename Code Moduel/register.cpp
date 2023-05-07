#include"register.h"
 bool user::registerNuser() {
	//注册一个新的用户
	FILE* fp = fopen("register.txt", "a");
	printf("请输入注册账户：");
	scanf("%s", this->account);
	printf("请输入设置密码：");
	scanf("%s", this->password);
	if (fprintf(fp, "%s %s\n", account, password)>0) {
		printf("注册成功！\n");
		fclose(fp);
		system("pause");
		return true;
	}
	else{
		printf("Errorn\n");
		fclose(fp);
		system("pause");
		return false;
	}
	
}
bool user::nomal_login() {
	//对于普通用户的登录检测，需要输入账户和密码
	FILE* fp = fopen("register.txt", "r");
	char str[60];
	char taccount[20];//文本中的账户
	char tpassword[20];//文本中的密码
	char laccount[20];
	char lpassword[20];
	printf("请输入账号：");
	scanf("%s",laccount);
	getchar();
	printf("请输入密码：");
	scanf("%s", lpassword);
	getchar();
A:	while (fgets(str, 60, fp) != NULL) {
	//逐行查找账户，密码，相同则登录成功
	sscanf(str, "%s %s", taccount, tpassword);
	
	if (strcmp(laccount, taccount) == 0 && strcmp(lpassword, tpassword) == 0) {
		printf("登录成功！\n");
		strcpy(account, taccount);
		strcpy(password, tpassword);
		fclose(fp);
		return true;
	}
}
if (fgets(str, 60, fp) == NULL) {
	printf("登录失败，请检查账户或密码！\n");
	system("pause");
	system("cls");
}
}
bool user::super_login() {
	//对于管理员的登录检测，只需输入密码
		printf("请输入密码：");
	scanf("%s", this->password);
	if (strcmp(this->password, this->key) == 0) {
		printf("登录成功！");
		return true;
	}
	else {
		printf("密码错误\n");
		system("pause");
		
		return false;
	}
}

