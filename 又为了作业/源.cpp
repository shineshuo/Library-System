//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#define size 256
//#define FIlEName_size 100
//#define N 16
//void save_file(char* zip_Graph, char* filename);
//void read_file(char* zip_Graph, char* filename);
//void str_insect(char* filename);
//void zip(char* zip_Graph);
//int main()
//{
//	char zip_Graph[size + 1];
//	char filename[FIlEName_size];
//
//	read_file(zip_Graph, filename);
//	int i = 0;
//	//测试文件是否读出 
//	for (i = 0; i < size; i++)
//	{
//		printf("%c", zip_Graph[i]);
//	}
//	printf("\n");
//	str_insect(filename);
//
//	save_file(zip_Graph, filename);
//	i = 0;
//
//
//	system("pause");
//	return 0;
//}
//void int_to_char()
//{
//
//}
//void zip(char* zip_Graph)
//{
//	int t = 0;
//	int i = 0;
//	int j = 0;
//	int count = 0;
//	char ch = '0';
//	char str_num[size];
//	printf("%d\n", strlen(zip_Graph));
//	for (; i < strlen(zip_Graph); i++)
//	{
//		if (ch == zip_Graph[i])
//		{
//			count++;
//		}
//		else
//		{
//			if (count == 0)
//			{
//				ch = zip_Graph[i];
//				count++;
//			}
//			else
//			{
//				str_num[t++] = ch;
//				
//					int num = count;
//					int fi=1;
//					while(num > 9)
//					{
//						num /= 10;
//						fi *=10;
//					}
//					while (fi > 0)
//					{
//						str_num[t++] = count/fi+'0';
//						count%=fi;
//					fi /= 10;
//					
//					}
//				count =0;
//				str_num[t++] = ' ';
//				i--;
//			}
//		}
//	}
//	if (count != 0)
//	{
//		str_num[t++] = ch;
//
//		int num = count;
//		int fi = 1;
//		while (num > 9)
//		{
//			num /= 10;
//			fi *= 10;
//		}
//		while (fi > 0)
//		{
//			str_num[t++] = count / fi + '0';
//			count %= fi;
//			fi /= 10;
//
//		}
//		count = 0;
//		str_num[t++] = ' ';
//		i--;
//	}
//	t++;
//	str_num[t++] = '\0';
//	i = 0;
//	
//
//	strcpy(zip_Graph, str_num);
//	for (i = 0; i < strlen(zip_Graph); i++)
//	{
//
//		printf("%c", zip_Graph[i]);
//	}
//}
//
//
//void read_file(char* zip_Graph, char* filename)
//{
//	FILE* fp;
//
//	char fp_Title[N];
//	//让用户输入数据文件名称 
//	printf("请输入文件名，dgb为扩展名:");
//	scanf("%s", filename);
//	fp = fopen(filename, "rb");
//	if (fp == NULL)
//	{
//		printf("打开%s文件失败！\n", filename);
//		exit(0);
//	}
//
//
//	fscanf(fp, "%s\n", fp_Title);
//
//	if (strcmp(fp_Title, "DGB") != 0)
//	{
//		printf("数据格式错，应为DGB格式！\n");
//		exit(0);
//	}
//
//
//	int i, j;
//	for (i = 0; i < size; i++)
//	{
//		zip_Graph[i] = fgetc(fp);
//	}
//	zip_Graph[i] = '\0';
//	fclose(fp);
//
//}
//void save_file(char* zip_Graph, char* filename)
//{
//	FILE* fp;
//	char fp_Title[N];
//	fp = fopen(filename, "wb");
//	if (fp == NULL)
//	{
//		printf("创建%s文件失败！\n", filename);
//		exit(0);
//	}
//	zip(zip_Graph);
//	int i = 0;
//	char 
//	strcpy(fp_Title, "DGB\n");
//	fprintf(fp, "%s", fp_Title);
//
//
//}
//void str_insect(char* filename)
//{
//	char fp_Title[N];
//	strcpy(fp_Title, "dgbz");
//	int i = 0;
//	for (i; i < FIlEName_size; i++)
//	{
//		if (filename[i] == '.')
//		{
//			filename[i + 1] = 'd';
//			filename[i + 2] = 'g';
//			filename[i + 3] = 'b';
//			filename[i + 4] = 'z';
//			filename[i + 5] = '\0';
//		}
//
//	}
//
//
//}
