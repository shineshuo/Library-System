#include"register.h"
 bool user::registerNuser() {
	//ע��һ���µ��û�
	FILE* fp = fopen("register.txt", "a");
	printf("������ע���˻���");
	scanf("%s", this->account);
	printf("�������������룺");
	scanf("%s", this->password);
	if (fprintf(fp, "%s %s\n", account, password)>0) {
		printf("ע��ɹ���\n");
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
	//������ͨ�û��ĵ�¼��⣬��Ҫ�����˻�������
	FILE* fp = fopen("register.txt", "r");
	char str[60];
	char taccount[20];//�ı��е��˻�
	char tpassword[20];//�ı��е�����
	char laccount[20];
	char lpassword[20];
	printf("�������˺ţ�");
	scanf("%s",laccount);
	getchar();
	printf("���������룺");
	scanf("%s", lpassword);
	getchar();
A:	while (fgets(str, 60, fp) != NULL) {
	//���в����˻������룬��ͬ���¼�ɹ�
	sscanf(str, "%s %s", taccount, tpassword);
	
	if (strcmp(laccount, taccount) == 0 && strcmp(lpassword, tpassword) == 0) {
		printf("��¼�ɹ���\n");
		strcpy(account, taccount);
		strcpy(password, tpassword);
		fclose(fp);
		return true;
	}
}
if (fgets(str, 60, fp) == NULL) {
	printf("��¼ʧ�ܣ������˻������룡\n");
	system("pause");
	system("cls");
}
}
bool user::super_login() {
	//���ڹ���Ա�ĵ�¼��⣬ֻ����������
		printf("���������룺");
	scanf("%s", this->password);
	if (strcmp(this->password, this->key) == 0) {
		printf("��¼�ɹ���");
		return true;
	}
	else {
		printf("�������\n");
		system("pause");
		
		return false;
	}
}

