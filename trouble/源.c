#include<stdio.h>
#include<string.h>

/*****************************************************************************************/
//以下容器均为指针数组


char* keywords[5] = { "int","char","float","main","print" };//存储保留字（关键字）的容器

char* operators[5] = { '+','-','*','/','=' };//运算符容器

char* separartors[4] = { '{','}',';','\'' };//界符容器


char id[3][5]  /*= {"a"}*/;//变量容器

char num[4][5];//常量容器


/********************************************************************************************/

void printtable(FILE* outprint)//输出种别编码表
{
	//printf("\n%c\n\n",num[0][2]);
	int i;
	int p=0, q=0;
	fprintf(outprint, "\n种别编码表:\n");
	fprintf(outprint, "单词符号		种别编码		属性值\n");

	printf("\n种别编码表:\n\n");
	printf("单词符号		种别编码		属性值\n");

	for (i = 0; i < 5; i++)
	{
		printf("%s			%d			-\n\n", keywords[i], i + 1);

		fprintf(outprint, "%s			%d			-\n\n", keywords[i], i + 1);
	}



	for (i = 0; i < 5; i++)
	{
		printf("%c			%d			-\n\n", operators[i], i + 6);

		fprintf(outprint, "%c	%d	-\n\n", operators[i], i + 6);
	}

	for (i = 0; i < 4; i++)

	{
		printf("%c			%d			-\n\n", separartors[i], i + 11);


		fprintf(outprint, "%c	%d	-\n\n", separartors[i], i + 11);
	}

	//printf("%s\n\n", *(id+0));
	//printf("%s\n\n", id[0][5]);


	for (i = 0; i < 3; i++)
		if (id[i][0] != NULL)
			p++;

	for (i = 0; i < p; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%c", id[i][j]);
			//fprintf(outprint, "%c	15	%s\n\n", id[i][j], id[i][j]);
		}

		printf("			15			");

		for (int j = 0; j < 5; j++)
		{
			printf("%c", id[i][j]);
			//fprintf(outprint, "%c	15	%s\n\n", id[i][j], id[i][j]);
		}
		printf("\n");
	}
	



	fprintf(outprint, "\n常数表:\n");
	fprintf(outprint, "单词符号		种别编码		属性值\n");
	printf("\n常数表:\n\n");
	printf("单词符号		种别编码		属性值\n");
	for (i = 0; i < 3; i++)
		if (num[i][0] != NULL)
			q++;


	for (i = 0; i < q; i++)
	{
		/*printf("%s			16			%s\n\n", num[i][5], num[i][5]);
		fprintf(outprint, "%s	16	%s\n\n", num[i][5], num[i][5]);*/

		for (int j = 0; j < 5; j++)
		{
			printf("%c", num[i][j]);
			//fprintf(outprint, "%c	15	%s\n\n", id[i][j], id[i][j]);
		}
		printf("			16			");
		for (int j = 0; j < 5; j++)
		{
			printf("%c", num[i][j]);
			//fprintf(outprint, "%c	15	%s\n\n", id[i][j], id[i][j]);
		}
		printf("\n");


	}
}



int letter(char c)//判断是否为字母
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return 1;
	else
		return 0;
}




int digit(char c)//判断是否为数字
{
	if (c >= '0' && c <= '9')
		return 1;
	else
		return 0;
}



int point(char c)//判断是否为小数点
{
	if (c == '.')
		return 1;
	else
		return 0;
}



int getbe(char t)//滤除空格（识别是否是空格、tap、换行）
{
	if (t == ' ' || t == '\t' || t == '\n')
		return 1;
	else
		return 0;
}



//char retract0(FILE* infb)//扫描指针回退一个字符，同时将character置为空白
//{
//	infb--;
//	return infb;
//}

char retract1(char character0)//扫描指针回退一个字符，同时将character置为空白
{
	character0 = '\0';
	return character0;
}



void concatenation(char token0[10], char s0)//将token中的字符串与character中的字符连接并作为token中新的字符串
{
	//printf("\ntoken=%s\n", token0);


	//printf("\ns=%c\n", s0);



	//printf("\ntoken=%s\n", token0);

	//token0[10] = strcat(token0[10], character0);
	int i = strlen(token0);
	//printf("%d\n", i);

	//printf("\ntoken=%s\n", token0);
	//printf("\ns=%c\n", s0);

	token0[i] = s0;
	//printf("%d", i);

	//printf("%s", token0);
	//return token0;
	//printf("\ntoken=%s\n", token0);
	//printf("\ntoken=%s\n", token0);


}



int reserve(char token0[10])//判别是否为保留字
{
	int temp = 0;
	/*if (strcmp(token0, *(keywords + 3)) == 0)
		printf("y");
	else
		printf("n");
*/


	for (int i = 0; i < 5; i++)
	{
		if (strcmp(token0, *(keywords + i)) == 0)
		{
			//printf("y");
			temp = 1;
			break;
		}
	}
	return temp;
}



void buildlistid(char token0[5])
{
	//int t, c = 0;
	//int temp = 0;

	//for (int i = 0; i < 2; i++)
	//	if (*(id + i) != '\0')
	//		temp++;

	//for (t = 0; t < temp; t++)//判断变量中是否已经出现
	//	if (strcmp(token0, *(id+t)) == 0)
	//	{
	//		c = 1;
	//		break;
	//	}
	//if (c == 0)
	//{
	//	id[i] = token0;
	//	i++;
	//}
	//* (id + i) = token0;
	//i++;
	/*int temp = 0;
	int i = 0;
	for (i = 0; i < 2; i++)
		if (*(id+i)!= NULL)
			temp++;
	*(id+temp) = token0;*/
	//strcpy(id[i][5],token0);
	//id[0] = "a";
	//printf("\n#%s#\n", *(id + 1));
	//id[i][5] = token0;
	//printf("\n%s\n", token0);

	static int ipz = 0;//静态
	for (int t = 0; t < 5; t++)
		id[ipz][t] = token0[t];
 	ipz++;
}



void buildlistnum(char token0[])
{
	
	//int q, c = 0;

	//int temp = 0;

	//for (int i = 0; i < 2; i++)
	//	if (*(num + i) != '\0')
	//		temp++;

	////printf("%d", temp);
	//for (q = 0; q < temp; q++)//判断在常量中是否已经出现
	//	if (strcmp(token0, *(num + q)) == 0)
	//	{
	//		c = 1;
	//		break;
	//	}
	//if (c == 0)
	//{
	//	num[p] = token0;
	//	p++;
	//}
	//int temp = 0;

	//int i = 0;
	//for (i = 0; i < 2; i++)
	//	if (*(num + i) != '\0')
	//		temp++;
	//*(num+temp) = token0;

	//printf("\n#%s#\n", *(num + 1));
	/** (num + p) = token0;
	p++;*/
	//num[p][5] = token0;
	//strcpy(num[p][5], token0);
	//printf("\n%s\n", token0);


	static int ipp = 0;//静态
	for (int t = 0; t < 5; t++)
		num[ipp][t] = token0[t];
	ipp++;
}

void error() //            出错处理
{

	printf("\n非法字符，无法识别！\n");
}


void lexanalyse(FILE* inf, FILE* outf)
{
	char token[10] = { '\0' };
	char character = '\0';
	char s;
	int c, t = 0, p = 0;
	static int keywordsno = 1;
	int keywordsno0;
	int id0no, num0no;
	int temp = 0;
	int temp0 = 0;
	int temp1 = 0;
	int temp2 = 0;
	int clean = 0;


	//character = retract1(character);
	/*s = fgetc(inf);
	printf("%c",s);*/

	while (!feof(inf))//判断是否读到文件结尾
	{
		/*
			if (feof(inf) == 0)
				break;*/
		for (clean = 0; clean < 10; clean++)
			token[clean] = NULL;//对token数组初始化
		/*printf("\ntoken=%s\n", token);
		printf("\ncharacter=%c\n", character);*/
		/*if (inf== EOF)
			break; */
		s = fgetc(inf);//c为读取的一个字符


		while (getbe(s) == 1)
			s = fgetc(inf);//滤除空格

	    //printf("\n(%c)\n", s);


		switch (s)
		{
		case 'a':
		case 'b':
		case 'c':
		case 'd':
		case 'e':
		case 'f':
		case 'g':
		case 'h':
		case 'i':
		case 'j':
		case 'k':
		case 'l':
		case 'm':
		case 'n':
		case 'o':
		case 'p':
		case 'q':
		case 'r':
		case 's':
		case 't':
		case 'u':
		case 'v':
		case 'w':
		case 'x':
		case 'y':
		case 'z':
		{
			/*printf("\ntoken=%s\n", token);
			printf("\ncharacter=%c\n", character);*/
			character = fgetc(inf);//character为当前识别字符的下一个字符
			//printf("\n%c\n", character);

			if (character == '\'')
				goto flash;


			while (letter(character) || digit(character))
			{
				//printf("\n%c\n", character);
				//token[10] = concatenation(token, s);
				//printf("\ntoken=%s\n", token);
				//strcpy(token, concatenation(token, s));//将当前读入的字符送入token数组
				//concatenation("\0", '\0');
				concatenation(token, s);
				//printf("\n%s\n", token);
				//s = '\0';
				s = character;
				//printf("%c", s);
				character = fgetc(inf);
			}
			//printf("\n%c\n", s);
			//token[10] = concatenation(token, s);
			//strcpy(token, concatenation(token, s));
			//concatenation("\0", '\0');
			concatenation(token, s);
			//printf("\ntoken=%s\n", token);
			//character = retract(inf, character);//扫描指针回退一个字符
			//inf = retract0(inf);
			//printf("%c", s);

			//inf --;
			fseek(inf, -1, SEEK_CUR);
			/*s = fgetc(inf);
			printf("%c", s);*/
			//printf("check");
			character = retract1(character);
			//printf("\n#%c#\n", character);
			c = reserve(token);
			//printf("%d",c);
			//printf("%s\n", token);
		/*	if (strcmp(*(id+0), token) == 0)
				printf("yes");
			else
				printf("no");*/
				//printf("%c", *(id + 0));
			if (c == 0)
			{
				/**(id + 0) = "abc";
				id[1] = "bcd";

				if (*(id + 1) == NULL)
					printf("y");
				printf("%s",*(id+0));
				printf("%s", *(id + 1));*/
				for (int i = 0; i < 3; i++)
					if (id[i][0] != NULL)
						temp++;
				for (id0no = 0; id0no < temp; id0no++)
					if (strcmp(id[id0no], token) == 0)
					{
						printf("变量：	%s			15			%s\n\n", token, token);
						fprintf(outf, "变量：	%s			15			%s\n\n", token, token);
						t = 1;
						break;
					}
				if (t == 0)
				{
					buildlistid(token);//将标识符登录到符号表中
					//printf("%s\n\n", id[0][5]);
					printf("变量：	%s			15			%s\n\n", token, token);
					fprintf(outf, "变量：	%s	15	%s", token, token);
				}
			}
			else
			{
				for (keywordsno0 = 0; keywordsno0 < 5; keywordsno0++)
					if (strcmp(*(keywords + keywordsno0), token) == 0)
					{
						printf("保留字:	%s			%d			null\n\n", token, keywordsno0);
						fprintf(outf, "\n保留字：%s	%d	null\n\n", token, keywordsno0);
						break;
					}
			}
			break;
		}
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			character = fgetc(inf);//character为当前识别字符的下一个字符
			while (digit(character))
			{
				//token[10] = concatenation(token, s);
				//strcpy(token, concatenation(token, s));
				concatenation(token, s);
				s = character;
				character = fgetc(inf);
			}
			//token[10] = concatenation(token, s);
			//strcpy(token, concatenation(token, s));
flash:      concatenation(token, s);
			//character = retract(inf, character);//扫描指针回退一个字符
			//inf = retract0(inf);

			//inf--;
			fseek(inf, -1, SEEK_CUR);
			character = retract1(character);

			for (int i = 0; i < 3; i++)
				if (num[i][0] != NULL)
					temp1++;
				//{
				//	if (strcmp(num[i][0], token) != 0)
				//	{
				//		strcpy(num[i][0], token);
				//	}
				//	temp1++;
				//}


			printf("\n%c\n",num[1][0]);

			for (num0no = 0; num0no < temp1; num0no++)
				if (strcmp(num[num0no], token) == 0)
				{
					printf("常量：	%s			16			%s\n\n", token, token);
					fprintf(outf, "常量：	%s	16 %s\n\n", token, token);
					p = 1;
					break;
				}
				else
				{
					if (token[0]>='A'&& token[0] <= 'z')
					{
						p = 0;
						//printf("字符串：	%s			16			%s\n\n", token, token);
						break;
					}
					if (token[0] >= '0' && token[0] <= '9')
					{
						/*printf("数字：	%s			16			%s\n\n", token, token);*/
						p = 0;
						break;
					}

				}
			if (p == 0)
			{
				buildlistnum(token);//将标识符登录到符号表中
				printf("常量：	%s			16			%s\n\n", token, token);
				fprintf(outf, "常量：	%s	16	%s", token, token);
				/*for (num0no = 0; num0no < temp2; num0no++)
					if (strcmp(*(num + num0no), token) == 0)
					{
						printf("常量：	%s			16			%s\n\n", token, token);

						fprintf(outf, "常量：	%s	16	%s", token, token);
						break;
					}*/
			}
			break;
		case '+':
			printf("运算符：+			6			null\n\n");


			fprintf(outf, "运算符：	%c	6	null\n\n", s);
			break;
		case '-':
			fprintf(outf, "运算符：	%c	7	null", s);
			break;
		case '*':
			printf("运算符：*			8			null\n\n");

			fprintf(outf, "运算符：	*			8			null\n\n");
			break;
		case '/':
			fprintf(outf, "运算符：	%c	9	null", s);
			break;
			/*case '<':
				fgetc(inf);
				if (character == '=')
					print(relop, le);
				else
				{
					retract(inf, character);
					print(relop, lt);
				}
				break;
			case '>':
				fgetc(inf);
				if (character == '=')
					print(relop, re);
				else
				{
					retract(inf, character);
					print(relop, rt);
				}
				break;*/
		case '=':
			//character=fgetc(inf);
			//if (character == '=')
			//	print(relop, EQ);
			//else
			//{
			//	retract(inf, character);
			//	print('=', null);
			//}
			printf("运算符：=			10			null\n\n");


			fprintf(outf, "运算符：	%c	10	null\n\n", s);
			break;
		case '{':
			printf("界符：	{			10			null\n\n");
			fprintf(outf, "界符：	{	10	null\n\n");



			break;
		case '}':
			printf("界符：	}			11			null\n\n");
			fprintf(outf, "界符：	}	11	null");
			break;
		case '\'':
			//printf("check\n\n");


			printf("界符：	'			12			null\n\n");

			fprintf(outf, "界符：	\	12	null");
			break;
		case ';':
			printf("界符：	;			13			null\n\n");

			fprintf(outf, "界符：	;	13	null");
			break;
		default:
			if (s != EOF)
				error();
		}

		//printf("%s", *(id + 0));
		/*if (feof(inf) == 0)
			break;*/

	}
	//printf("check");

	/*printf("\n#%s#\n", *(id + 0));
	printf("\n#%s#\n", *(id + 1));
	printf("\n#%s#\n", *(num + 0));
	printf("\n#%s#\n", *(num + 1));*/

	//printf("\n%s\n", *(id + 0));


}





/****************************************************************************************/


//main函数

int main()
{
	FILE* input, * output;  //定义两个指针，读入文件、写入文件

	input = fopen("input.c", "r");//打开文件（文件操作）
	output = fopen("output.txt", "w+");

	//if ((input = fopen("input.c", "r")) == NULL) {//测试文件是否打开成功
	//	printf("Cannot find the file!\nStrike any key to exit!\n");
	//	system("pause");
	//	exit(1);
	//}
	//else
	//	printf("open file successfully!\n");

	//if (output)
	//{
	//	printf("output check success");
	//}

	//fputs("分析过程\n",output);
	//printf("%c\n\n\n",'\'');

	printf("分析过程:\n\n\n");
	printf("	单词符号		种别编码		属性值\n\n");
	fprintf(output, "分析过程:\n\n\n");
	fprintf(output, "	单词符号		种别编码		属性值\n");


	//fclose(input);
	//fclose(output);

	lexanalyse(input, output);//分析函数
	//printf("%s", *(id + 0));



	printtable(output);//输出种别编码表

	fclose(input);// 关闭文件（文件操作）
	fclose(output);

	printf("\nLexical Analyzer has finished the analyzation!\nFor more information please see the file output.txt.\n");
	//词法分析已经完成，详情请见外部输出文件

	system("pause");
}










