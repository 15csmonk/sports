#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#include <direct.h> //文件夹的创建 
#define STULEN sizeof(struct student)
#define PROLEN sizeof(struct project)
#define COLLEN sizeof(struct college)
#define STUFORMAT "%-8d%-10s%-8s%-12d%-8d%-10d%-8d%-10d\n"
#define STUDATA stu[i].num,stu[i].name,stu[i].sex,stu[i].college_num,stu[i].pro1_num,stu[i].pro1_grade,stu[i].pro2_num,stu[i].pro2_grade
#define PROFORMAT "%-12s%-12d%-13s%-13d%-12d%-10d\n"
#define PRODATA pro[i].name,pro[i].num,pro[i].place,pro[i].placeNum,pro[i].unit,pro[i].time 
#define COLFORMAT "%-12s%-12d%-12d\n"
#define COLDATA col[i].name,col[i].num,col[i].score
  

struct project
{
	char name[10];
	int num;
	char place[10];
	int placeNum;
	int unit;//1表示时间秒  2表示长度米
	int time;//单位分 
};

struct aa{
		int time;
		char name[20];
		char place[20];
		int placenum;
	}a1[10],a2[10];

struct college
{
	char name[10];
	int num;
	int score;
};

struct student/*定义学生成绩结构体*/
{ 
	int num;
	char name[15];
	char sex[4];
	int college_num;
	int score;
	int pro_num;
	double pro_grade;
	int pro_score;//毫秒，厘米  
};


struct student stu[100];/*定义结构体数组*/
struct project pro[100];
struct college col[20];

/************************菜单栏部分********************************/
void menu();//主菜单 
void menu1();//比赛信息查询菜单 
void messageMenu();//比赛信息查询 
void menu2();//管理员菜单 
void adminMenu();//管理员
void menu3();//项目管理菜单 
void projectMenu();//项目管理 
void menu4();//学院管理菜单 
void collegeMenu();//学院管理 
void menu5();//运动员信息管理菜单 
void studentMenu();// 运动员信息管理 
/************************菜单栏部分结束********************************/



/************************项目信息管理********************************/
void inProject();
void delProject();
void modProject();
void showProject();
/************************项目信息管理结束********************************/


/************************学院信息管理********************************/
void inCollege();//增加 
void delCollege();//删除
void modCollege();//修改 
void showCollege();//查询
/************************学院信息管理结束********************************/


/************************运动员信息管理********************************/
int getMessage(int num);//传入项目编号num，返回该项目人数 
void saveMessage(int m,int num);//传入项目编号num，该项目人数m
void inStudent();//增加 
void delStudent();//删除
void modStudent();//修改 
void showStudent(int num);//查询
void inScore();//录入成绩 

/************************运动员信息管理结束********************************/

/************************排名管理********************************/
void projectRank(int num);
void showProjectRank(int num);
void showStudent1(int num);//查询
void collegeRank();
void showCollegeRank();
void showCollege1();
/************************排名管理结束********************************/
void getorder();


/************************菜单栏部分********************************/
void menu()/*自定义函数实现菜单功能*/
{
	system("cls");
	printf("================================================================================");
	printf("                   欢 迎 您 进 入 学 生 成 绩 管 理 系 统 \n");
	printf("================================================================================\n");
	printf("\n\n\n");
	printf("\t\t|--------------------welcome--------------------|\n");
	printf("\t\t|\t 1. 比赛项目公布                        |\n");
	printf("\t\t|\t 2. 比赛信息查询                        |\n");
	printf("\t\t|\t 3. 比赛日程公布                        |\n");
	printf("\t\t|\t 4. 管理员登录                          |\n");
	printf("\t\t|\t 0. 退出                                |\n");
	printf("\t\t|-----------------------------------------------|\n\n");
	printf("\t\t\tchoose(0-4):");
}

void menu1()
{
	system("cls");
	printf("================================================================================");
	printf("                   欢 迎 您 进 入 学 生 成 绩 管 理 系 统 \n");
	printf("================================================================================\n");
	printf("\n\n\n");
	printf("\t\t|--------------------welcome--------------------|\n");
	printf("\t\t|\t 1. 参赛信息                            |\n");
	printf("\t\t|\t 2. 项目排名                            |\n");
	printf("\t\t|\t 3. 学院排名                            |\n");
	printf("\t\t|\t 0. 返回                                |\n");
	printf("\t\t|-----------------------------------------------|\n\n");
	printf("\t\t\tchoose(0-3):");
}

void messageMenu()
{
	int n,a; //选择菜单编号 
	menu1();
	scanf("%d",&n);
	while(n!=0)
	{
		switch(n)
		{
			case 1:   
				showProject(); 
				printf("请输入要查看的项目编号：");
				scanf("%d",&a);
				system("cls");
				showStudent(a);//查询
				getch();
				break;
			case 2:
				showProject(); 
				printf("请输入要查看的项目编号：");
				scanf("%d",&a);
				system("cls");
				showProjectRank(a);//项目排名 
				getch();
				break;
			case 3:
				system("cls");
				showCollegeRank();//学院排名 
				getch();
				break;
			default:break;
		}
		menu1();
		scanf("%d",&n);
	}
	return;
}

void menu2()
{
	system("cls");
	printf("================================================================================");
	printf("                   欢 迎 您 进 入 学 生 成 绩 管 理 系 统 \n");
	printf("================================================================================\n");
	printf("\n\n\n");
	printf("\t\t|---------------------admin---------------------|\n");
	printf("\t\t|\t 1. 项目信息管理                        |\n");
	printf("\t\t|\t 2. 学院信息管理                        |\n");
	printf("\t\t|\t 3. 运动员信息管理                      |\n");
	printf("\t\t|\t 4. 秩序册生成                          |\n");
	printf("\t\t|\t 0. 返回                                |\n");
	printf("\t\t|-----------------------------------------------|\n\n");
	printf("\t\t\tchoose(0-4):");
}
void adminMenu()
{
	char psw[9]={"Ab123456"};
	char input[9]={NULL};
	int i,n; //选择菜单编号 
	printf("请输入管理员密码:");
	for(i=0;i<8;i++)
	{
		input[i]=getch();
		printf("*");
	}
	input[i]='\0';
	if(strcmp(input,psw)!=0)
	{
		printf("\n密码错误！\n");
		printf("按任意键返回...");
		getch();
		return;
	}
	menu2();
	scanf("%d",&n);
	while(n!=0)
	{
		switch(n)
		{
			case 1:   
				projectMenu();//项目信息管理 
				break;
			case 2:
				collegeMenu();//学院信息管理 
				break;
			case 3:
				studentMenu();//运动员信息管理 
				break;
			case 4:
				getorder();//秩序册 
				break;
			default:break;
		}
		menu2();
		scanf("%d",&n);
	}
	return;
}

void menu3()
{
	system("cls");
	printf("================================================================================");
	printf("                   欢 迎 您 进 入 学 生 成 绩 管 理 系 统 \n");
	printf("================================================================================\n");
	printf("\n\n\n");
	printf("\t\t|---------------------admin---------------------|\n");
	printf("\t\t|\t 1. 录入项目信息                        |\n");
	printf("\t\t|\t 2. 删除项目信息                        |\n");
	printf("\t\t|\t 3. 修改项目信息                        |\n");
	printf("\t\t|\t 4. 查询项目信息                        |\n");
	printf("\t\t|\t 0. 返回                                |\n");
	printf("\t\t|-----------------------------------------------|\n\n");
	printf("\t\t\tchoose(0-4):");
}
void projectMenu()
{
	int n; //选择菜单编号 
	menu3();
	scanf("%d",&n);
	while(n!=0)
	{
		switch(n)
		{
			case 1:   
				inProject();//增加 
				break;
			case 2:
				delProject();//删除
				break;
			case 3:
				modProject();//修改 
				break;
			case 4:
				showProject();//查询
				getch();
				break;
			default:break;
		}
		menu3();
		scanf("%d",&n);
	}
	return;
}

void menu4()
{
	system("cls");
	printf("================================================================================");
	printf("                   欢 迎 您 进 入 学 生 成 绩 管 理 系 统 \n");
	printf("================================================================================\n");
	printf("\n\n\n");
	printf("\t\t|---------------------admin---------------------|\n");
	printf("\t\t|\t 1. 录入学院信息                        |\n");
	printf("\t\t|\t 2. 删除学院信息                        |\n");
	printf("\t\t|\t 3. 修改学院信息                        |\n");
	printf("\t\t|\t 4. 查询学院信息                        |\n");
	printf("\t\t|\t 0. 返回                                |\n");
	printf("\t\t|-----------------------------------------------|\n\n");
	printf("\t\t\tchoose(0-4):");
}
void collegeMenu()
{
	int n; //选择菜单编号 
	menu4();
	scanf("%d",&n);
	while(n!=0)
	{
		switch(n)
		{
			case 1:   
				inCollege();//增加 
				break;
			case 2:
				delCollege();//删除
				break;
			case 3:
				modCollege();//修改 
				break;
			case 4:
				showCollege();//查询
				getch();
				break;
			default:break;
		}
		menu4();
		scanf("%d",&n);
	}
	return;
}

void menu5()
{
	system("cls");
	printf("================================================================================");
	printf("                   欢 迎 您 进 入 学 生 成 绩 管 理 系 统 \n");
	printf("================================================================================\n");
	printf("\n\n\n");
	printf("\t\t|---------------------admin---------------------|\n");
	printf("\t\t|\t 1. 录入运动员信息                      |\n");
	printf("\t\t|\t 2. 删除运动员信息                      |\n");
	printf("\t\t|\t 3. 修改运动员信息                      |\n");
	printf("\t\t|\t 4. 查询运动员信息                      |\n");
	printf("\t\t|\t 5. 录入运动员成绩                      |\n");
	printf("\t\t|\t 0. 返回                                |\n");
	printf("\t\t|-----------------------------------------------|\n\n");
	printf("\t\t\tchoose(0-5):");
}
void studentMenu()
{
	int n; //选择菜单编号 
	int a;
	menu5();
	scanf("%d",&n);
	while(n!=0)
	{
		switch(n)
		{
			case 1:   
				inStudent();//增加 
				break;
			case 2:
				delStudent();//删除
				break;
			case 3:
				modStudent();//修改 
				break;
			case 4:
				showProject(); 
				printf("请输入要查看的项目编号：");
				scanf("%d",&a);
				system("cls");
				showStudent(a);//查询
				getch();
				break;
			case 5:
				inScore();//录入成绩 
				break;
			default:break;
		}
		menu5();
		scanf("%d",&n);
	}
	return;
}
/****************************菜单栏部分结束****************************/



/****************************项目信息管理****************************/
void inProject()//录入项目信息
{
	int i,m=0;/*m是记录的条数*/
	char ch[2];
	FILE *filepro;/*定义文件指针*/
	FILE *fp;
	if((filepro=fopen("projectdata","ab+"))==NULL)/*打开指定文件*/
	{ 
		printf("can not open\n");
		return;
	}
	while(!feof(filepro)) 
	{ 
		if(fread(&pro[m] ,PROLEN,1,filepro)==1)
			m++;/*统计当前记录条数*/
	}
	fclose(filepro);
	system("cls");
	showProject();/*调用show函数，显示原有信息*/


	if((filepro=fopen("projectdata","wb"))==NULL)
	{ 
		printf("can not open\n");
		return;
	}
	for(i=0;i<m;i++) 
		fwrite(&pro[i] ,PROLEN,1,filepro);/*向指定的磁盘文件写入信息*/

	ch[0]='y';
    while(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)/*判断是否要录入新信息*/
	{
		printf("project name:");
		scanf("%s",&pro[m].name);
		
		printf("project num:");
		scanf("%d",&pro[m].num);
		
		printf("place:");
		scanf("%s",&pro[m].place);
		
		printf("place num:");
		scanf("%d",&pro[m].placeNum);
		
		printf("unit(1.秒  2.米):");
		scanf("%d",&pro[m].unit);
		
		printf("time(min):");
		scanf("%d",&pro[m].time);
			
		if(fwrite(&pro[m],PROLEN,1,filepro)!=1)/*将新录入的信息写入指定的磁盘文件*/
		{
			printf("can not save!"); 
			getch(); 
		}
		else
		{ 
			printf("%s saved!\n",pro[m].name);
			m++;
		}
			printf("继续输入吗?(y/n):");/*询问是否继续*/
			scanf("%s",ch);
	}
	fclose(filepro);
	
	_mkdir("xiangmu");
	
	for(int i=0;i<m;i++)
	{
		char root[20]={"xiangmu\\\\"};
		strcat(root,pro[i].name);
		if((fp=fopen(root,"ab+"))==NULL)
		{ 
			printf("gg\n");
			return;
		}
		fclose(fp);
	}
	
	printf("OK!\n");
	return;
}

void delProject()
{	
	FILE *filepro;
	int snum,i,m=0;
	char ch[2];
	
	if((filepro=fopen("projectdata","ab+"))==NULL)
	{ 
		printf("can not open\n");
		printf("按任意键返回...");
		getch();
		return;
	}
	while(!feof(filepro))  
		if(fread(&pro[m],PROLEN,1,filepro)==1) 
			m++;
	fclose(filepro);
	
	if(m==0) 
	{
		printf("no record!\n");
		printf("按任意键返回...");
		getch();
		return;
	}
	else
	{
		system("cls");
		showProject();/*调用show函数，显示原有信息*/
	}
	printf("请输入项目编号:");
	scanf("%d",&snum);
	for(i=0;i<m;i++)
		if(snum==pro[i].num)
			break;
 	if(i==m)
	{
		printf("can not find！");
		printf("按任意键返回...");
		getch();
		return;
	}
		
	printf("找到了，确定删除吗？(y/n)");
	scanf("%s",ch);
	if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)/*判断是否要进行删除*/
	{
		for(int j=i;j<m;j++)
			pro[j]=pro[j+1];/*将后一个记录移到前一个记录的位置*/
			m--;/*记录的总个数减1*/
			printf("删除成功!\n");
	}
	if((filepro=fopen("projectdata","wb"))==NULL)
	{ 
		printf("can not open\n");
		printf("按任意键返回...");
		getch();
		return;
	}
	for(int j=0;j<m;j++)/*将更改后的记录重新写入指定的磁盘文件中*/
		if(fwrite(&pro[j] ,PROLEN,1,filepro)!=1)
		{ 
			printf("can not save!\n");
			printf("按任意键返回...");
			getch();
			return;
		}
	fclose(filepro);
	return;			
} 

void modProject()
{
	FILE *filepro;
	FILE *fp;
	int i,j,m=0,snum,n;
	if((filepro=fopen("projectdata","ab+"))==NULL)
	{ 
		printf("can not open\n");
		return;
	}
	while(!feof(filepro))  
		if(fread(&pro[m],PROLEN,1,filepro)==1) 
			m++;
		
	if(m==0)
	{
		printf("no record!\n");
		fclose(filepro);
		printf("按任意键返回...");
		getch();
		return;
	}
	else
	{
		system("cls");
		showProject();/*调用show函数，显示原有信息*/
	}
		
	printf("请输入项目编号!\n");
	scanf("%d",&snum);
	for(i=0;i<m;i++)
		if(snum==pro[i].num)/*检索记录中是否有要修改的信息*/
			break;
	if(i<m)
	{	
		printf("找到了! \n");
		system("cls");
		printf("name      number      place      placeNum        unit       time\t\n");
		printf(PROFORMAT,PRODATA);/*将查找出的结果按指定格式输出*/
		printf("想修改那一部分呢?(1.name 2.number 3.place 4.placeNum 5.unit  6.time):");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("project name:");
				scanf("%s",&pro[i].name);/*输入项目姓名*/
				break;
			case 2:
				printf("project number:");
				scanf("%d",&pro[i].num);/*输入项目编号*/
				break;
			case 3:
				printf("place:");
				scanf("%s",&pro[i].place);/*输入项目地点*/
				break;
			case 4:
				printf("place number:");
				scanf("%d",&pro[i].placeNum);/*输入项目地点编号*/
				break;
			case 5:
				printf("unit(1.秒 2.米):");
				scanf("%d",&pro[i].unit);/*输入项目地点编号*/
				break;
			case 6:
				printf("time(min):");
				scanf("%d",&pro[i].time);/*输入项目地点编号*/
				break;
				default:break;
		}
	}
	else 
	{
		printf("can not find!");
		printf("按任意键返回...");
		getch();
		return;
	}
	if((filepro=fopen("projectdata","wb"))==NULL)
	{
		printf("can not open\n");
		printf("按任意键返回...");
		getch();
		return;
	}
	for(j=0;j<m;j++)/*将新修改的信息写入指定的磁盘文件中*/
		if(fwrite(&pro[j] ,PROLEN,1,filepro)!=1)
		{ 
			printf("can not save!"); 
			getch(); 
		}
	fclose(filepro);
	for(int i=0;i<m;i++)
	{
		char root[20]={"xiangmu\\\\"};
		strcat(root,pro[i].name);
		if((fp=fopen(root,"wb"))==NULL)
		{ 
			printf("gg\n");
			return;
		}
		fclose(fp);
	}
	return;
}

void showProject()
{
	FILE *filepro;
	int m=0;
	filepro=fopen("projectdata","ab+");
	while(!feof(filepro))
	{
		if(fread(&pro[m] ,PROLEN,1,filepro)==1) 
			m++;
	}  
	fclose(filepro);
	if(m==0)
	{
		printf("no record!\n");
	}
	else
	{
		printf("name      number      place      placeNum        unit       time\t\n");
		for(int i=0;i<m;i++)
		{ 
			printf(PROFORMAT,PRODATA);/*将信息按指定格式打印*/
		}
	}
	return;
}
/****************************项目信息管理结束****************************/




/****************************学院信息管理****************************/
void inCollege()//录入项目信息
{
	int i,m=0;/*m是记录的条数*/
	char ch[2];
	FILE *filecol;/*定义文件指针*/
	if((filecol=fopen("collegedata","ab+"))==NULL)/*打开指定文件*/
	{ 
		printf("can not open\n");
		printf("按任意键返回...");
		getch();
		return;
	}
	while(!feof(filecol)) 
	{ 
		if(fread(&col[m] ,COLLEN,1,filecol)==1)
			m++;/*统计当前记录条数*/
	}
	fclose(filecol);
	system("cls");
	showCollege();/*调用show函数，显示原有信息*/
	
	if((filecol=fopen("collegedata","wb"))==NULL)
	{ 
		printf("can not open\n");
		return;
	}
	for(i=0;i<m;i++) 
		fwrite(&col[i] ,COLLEN,1,filecol);/*向指定的磁盘文件写入信息*/
	ch[0]='y';
	
    while(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)/*判断是否要录入新信息*/
	{
		printf("college name:");
		scanf("%s",&col[m].name);
		
		printf("college num:");
		scanf("%d",&col[m].num);
		
			
		if(fwrite(&col[m],COLLEN,1,filecol)!=1)/*将新录入的信息写入指定的磁盘文件*/
		{
			printf("can not save!"); 
			getch(); 
		}
		else
		{ 
			printf("%s saved!\n",col[m].name);
			m++;
		}
			printf("继续输入吗?(y/n):");/*询问是否继续*/
			scanf("%s",ch);
	}
	fclose(filecol);
	
	printf("OK!\n");
	return;
}

void delCollege()
{	
	FILE *filecol;
	int snum,i,m=0;
	char ch[2];
	if((filecol=fopen("collegedata","ab+"))==NULL)
	{ 
		printf("can not open\n");
		printf("按任意键返回...");
		getch();
		return;
	}
	while(!feof(filecol))  
		if(fread(&col[m],COLLEN,1,filecol)==1) 
			m++;
	fclose(filecol);
	if(m==0) 
	{
		printf("no record!\n");
		printf("按任意键返回...");
		getch();
		return;
	}
	else
	{
		system("cls");
		showCollege();/*调用show函数，显示原有信息*/
	}
	
	printf("请输入学院编号:");
	scanf("%d",&snum);
	for(i=0;i<m;i++)
		if(snum==col[i].num)
			break;
 	if(i==m)
	{
		printf("can not find！");
		printf("按任意键返回...");
		getch();
		return;
	}
	printf("找到了，确定删除吗？(y/n)");
	scanf("%s",ch);
	if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)/*判断是否要进行删除*/
	{
		for(int j=i;j<m;j++)
			col[j]=col[j+1];/*将后一个记录移到前一个记录的位置*/
			m--;/*记录的总个数减1*/
			printf("删除成功!\n");
	}
	if((filecol=fopen("collegedata","wb"))==NULL)
	{ 
		printf("can not open\n");
		printf("按任意键返回...");
		getch();
		return;
	}
	for(int j=0;j<m;j++)/*将更改后的记录重新写入指定的磁盘文件中*/
		if(fwrite(&col[j] ,COLLEN,1,filecol)!=1)
		{ 
			printf("can not save!\n");
			printf("按任意键返回...");
			getch();
			return;
		}
	fclose(filecol);
	return;
} 

void modCollege()
{
	FILE *filecol;
	int i,j,m=0,snum,n;
	if((filecol=fopen("collegedata","ab+"))==NULL)
	{ 
		printf("can not open\n");
		return;
	}
	while(!feof(filecol))  
		if(fread(&col[m],COLLEN,1,filecol)==1) 
			m++;
		
	if(m==0)
	{
		printf("no record!\n");
		fclose(filecol);
		printf("按任意键返回...");
		getch();
		return;
	}
	else
	{
		system("cls");
		showCollege();/*调用show函数，显示原有信息*/
	}
		
	printf("请输入学院编号!\n");
	scanf("%d",&snum);
	for(i=0;i<m;i++)
		if(snum==col[i].num)/*检索记录中是否有要修改的信息*/
			break;
	if(i<m)
	{	
		printf("找到了! \n");
		system("cls");
		printf("name      number      score\t\n");
		printf(COLFORMAT,COLDATA);/*将查找出的结果按指定格式输出*/
		printf("想修改那一部分呢?(1.name 2.number):");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("college name:");
				scanf("%s",&col[i].name);/*输入项目姓名*/
				break;
			case 2:
				printf("college number:");
				scanf("%d",&col[i].num);/*输入项目编号*/
				break;
				default:break;
		}
	}
	else 
	{
		printf("can not find!");
		printf("按任意键返回...");
		getch();
		return;
	}
	if((filecol=fopen("collegedata","wb"))==NULL)
	{
		printf("can not open\n");
		printf("按任意键返回...");
		getch();
		return;
	}
	for(j=0;j<m;j++)/*将新修改的信息写入指定的磁盘文件中*/
		if(fwrite(&col[j] ,COLLEN,1,filecol)!=1)
		{ 
			printf("can not save!"); 
			getch(); 
		}
	fclose(filecol);
	return;
}


void showCollege()
{
	FILE *filecol;
	int m=0;
	filecol=fopen("collegedata","ab+");
	while(!feof(filecol))
	{
		if(fread(&col[m] ,COLLEN,1,filecol)==1) 
			m++;
	}  
	fclose(filecol);
	if(m==0)
	{
		printf("no record!\n");
	}
	else
	{
		printf("name      number      score\t\n");
		for(int i=0;i<m;i++)
		{ 
			printf(COLFORMAT,COLDATA);/*将信息按指定格式打印*/
		}
	}
	return;
}

/****************************学院信息管理结束****************************/


/****************************运动员信息管理****************************/
int getMessage(int num){//获取项目的人数,并且将学生信息存到全局变量stu里面 
	int i,n=0,m1=0;
	char root[30]={"xiangmu\\\\"};
	FILE *filepro,*fp;
	filepro=fopen("projectdata","ab+");
	if(filepro==NULL){printf("can not open!");return -1;}
	while(!feof(filepro)){
		if(fread(&pro[m1],PROLEN,1,filepro)==1)
		m1++;
	}
	fclose(filepro);
	for(i=0;i<m1;i++){
		if(num==pro[i].num){
			strcat(root,pro[i].name);
			break;
		}
	}
	fp=fopen(root,"ab+");
	if(fp==NULL){printf("can not open!");return -1;}
	while(!feof(fp)){
		if(fread(&stu[n],STULEN,1,fp)==1)
		n++;
	}
	fclose(fp);
	return n;
}

void saveMessage(int m,int num){//传入stu长度m，将stu重新存回项目编号为num的文件里面 
	int i,m1=0;
	char root[30]={"xiangmu\\\\"};
	FILE *filepro,*fp;
	filepro=fopen("projectdata","ab+");
	if(filepro==NULL){printf("can not open!");return;}
	while(!feof(filepro)){
		if(fread(&pro[m1],PROLEN,1,filepro)==1)
		m1++;
	}
	fclose(filepro);
	for(i=0;i<m1;i++){
		if(num==pro[i].num){
			strcat(root,pro[i].name);
			break;
		}
	}
	fp=fopen(root,"wb");
	if(fp==NULL){printf("can not open!");return;}
	for(int j=0;j<m;j++)
	{
		fwrite(&stu[j],STULEN,1,fp);
	}
	
	fclose(fp);
	printf("%s save!\n",pro[i].name);
	return;
}
void inStudent()/*录入学生信息*/
{ 
	int num,m=0;//num项目编号,m是现有的运动员个数 
	int ch;
	
    while(true)//不断录入直到退出 
	{
		system("cls");
		showProject();
		printf("\n报名哪个项目？(0退出)：");
		scanf("%d",&num);
		if(num==0)//输入0时退出 
		{
			break; 
		} 
		m=getMessage(num);
		if(m==-1)
		{
			printf("读取文件出错!\n");
			printf("按任意键返回...");
			getch();
			return; 
		}
		ch=1;
		while(ch==1)/*判断是否要录入新信息*/
		{
			system("cls");
			printf("学号:");
			scanf("%d",&stu[m].num);/*输入学生学号*/
			printf("姓名:");
			scanf("%s",&stu[m].name);/*输入学生姓名*/
			printf("性别:");
			scanf("%s",&stu[m].sex);/*输入学生sex*/
			showCollege();
			printf("\n学院:");
			scanf("%d",&stu[m].college_num);/*输入学生所在学院*/
			stu[m].pro_num=num;/*输入项目编号*/
			m++;
			printf("continue?(1/0):");/*询问是否继续*/
			scanf("%d",&ch);	
		}
		saveMessage(m,num);
		printf("按任意键继续...");
		getch(); 
	}
	printf("OK!\n");
	return;
}

void inScore()/*录入学生成绩*/
{ 
	int num,m=0,m1=0,i;//num项目编号,m是现有的运动员个数 
	int ch;
	int min,sec,mm; 
	FILE *filepro;
	filepro=fopen("projectdata","ab+");
	if(filepro==NULL){printf("can not open!");return;}
	while(!feof(filepro)){
		if(fread(&pro[m1],PROLEN,1,filepro)==1)
		m1++;
	}
	fclose(filepro);
    while(true)//不断录入直到退出 
	{
		system("cls");
		showProject();
		printf("\n录入哪个项目？(0退出)：");
		scanf("%d",&num);
		if(num==0)//输入0时退出 
		{
			break; 
		} 
		m=getMessage(num);
		
		for(i=0;i<m1;i++){
			if(num==pro[i].num){
				break;
			}
		}
		
		if(m==-1)
		{
			printf("读取文件出错!\n");
			printf("按任意键返回...");
			getch();
			return; 
		}
		switch(pro[i].unit)
		{
			case 1:
				for(int j=0;j<m;j++)
				{
					printf("%s\t\t成绩（分 秒 毫秒）：",stu[j].name);
					scanf("%d%d%d",&min,&sec,&mm);/*输入学生学号*/
					stu[j].pro_grade=60*min+sec+(mm/100.0);
				}
				break;
			case 2:
				for(int j=0;j<m;j++)
				{
					printf("%s\t\t成绩（米）：",stu[j].name);
					scanf("%lf",&stu[j].pro_grade);
				}
				break;
			default:break;
		}
		
				
		saveMessage(m,num);
		printf("按任意键继续...");
		getch(); 
	}
	printf("OK!\n");
	return;
}

void delStudent()/*自定义删除函数*/
{
	
	FILE *fp;
	int snum,i,j,m=0;
	int num;
	int ch;
	showProject(); 
	printf("请输入要删除的运动员项目编号：");
	scanf("%d",&num);
	m=getMessage(num);
	system("cls");
	showStudent(num); 
	printf("请输入运动员学号:");
	scanf("%d",&snum);
	for(i=0;i<m;i++)
		if(snum==stu[i].num)
		{
			break;
		}
		
	if(i==m)
	{
 		printf("can not find");
		getchar();
		return;
	}
	printf("找到了，确定删除？(1/0)");
	scanf("%d",&ch);
	if(ch==1)/*判断是否要进行删除*/
	{
		for(j=i;j<m;j++)
			stu[j]=stu[j+1];/*将后一个记录移到前一个记录的位置*/
		m--;/*记录的总个数减1*/
		printf("delete successfully!\n");
	}
	saveMessage(m,num);
	printf("按任意键返回...");
	getch();
	return;
				
}

void modStudent()/*自定义删除函数*/
{
	
	FILE *fp;
	int snum,i,j,n,m=0,m1=0,a;
	int min,sec,mm;
	int num;
	int ch;
	FILE *filepro;
	filepro=fopen("projectdata","ab+");
	if(filepro==NULL){printf("can not open!");return;}
	while(!feof(filepro)){
		if(fread(&pro[m1],PROLEN,1,filepro)==1)
		m1++;
	}
	fclose(filepro);
	showProject(); 
	printf("请输入要修改的运动员项目编号：");
	scanf("%d",&num);
	m=getMessage(num);
	for(a=0;a<m1;a++){
		if(num==pro[a].num){
			break;
		}
	}
	system("cls");
	showStudent(num); 
	printf("请输入运动员学号:");
	scanf("%d",&snum);
	for(i=0;i<m;i++)
		if(snum==stu[i].num)
		{
			break;
		}
		
	if(i==m)
	{
 		printf("can not find");
		getchar();
		return;
	}
	printf("你想修改哪一部分呢?(1.姓名 2.性别 3.学院 4.学号 5.成绩 )");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			printf("姓名:");
			scanf("%s",&stu[i].name);/*输入学生姓名*/
			break;
		case 2:
			printf("性别:");
			scanf("%s",&stu[i].sex);/*输入学生sex*/
			break;
		case 3:
			showCollege();
			printf("学院编号:");
			scanf("%d",&stu[i].college_num);/*输入学生所在学院*/
			break;
		case 4:
			printf("学号:");
			scanf("%d",&stu[i].num);/*输入学生所在学院*/
			break;
		case 5:
			switch(pro[a].unit)
				{
					case 1:
							printf("成绩（分 秒 毫秒）：");
							scanf("%d%d%d",&min,&sec,&mm);
							stu[i].pro_grade=60*min+sec+(mm/100.0);
						break;
					case 2:
							printf("成绩（米）：");
							scanf("%lf",&stu[i].pro_grade);
							printf("%f",stu[i].pro_grade);
						break;
					default:break;
				}
			break;
			default:break;
	}
	saveMessage(m,num);
	printf("按任意键返回...");
	getch();
	return;
				
}

void showStudent(int num)
{
	FILE *filecol,* filepro;
	int m=0,m1=0,m2=0;
	int a;
	int s=0;
	double h;
	filecol=fopen("collegedata","ab+");
	while(!feof(filecol))
	{
		if(fread(&col[m1],COLLEN,1,filecol)==1)
		m1++;
	}
	fclose(filecol);
	filepro=fopen("projectdata","ab+");
	while(!feof(filepro))
	{
		if(fread(&pro[m2],PROLEN,1,filepro)==1)
		m2++;
	}
	fclose(filepro);
	for(a=0;a<m1;a++){
		if(num==pro[a].num){
			break;
		}
	}
	m=getMessage(num);
	printf("学号         姓名         性别          学院          成绩\n");
	if(pro[a].unit==1)
	{
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<m1;j++)
			{
				if(stu[i].college_num==col[j].num)
				{
					s=(int)stu[i].pro_grade/60;
					h=(int)stu[i].pro_grade%60+stu[i].pro_grade-(int)stu[i].pro_grade;
					printf("%-12d%-15s%-12s%-14s%d分%.2lf秒\n",stu[i].num,stu[i].name,stu[i].sex,col[j].name,s,h);
					break;
				}
				
			}
		}
		return;
	}
	else
	{
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<m1;j++)
			{
				if(stu[i].college_num==col[j].num)
				{
					printf("%-12d%-15s%-12s%-14s%.2lf米\n",stu[i].num,stu[i].name,stu[i].sex,col[j].name,stu[i].pro_grade);
					break;
				}
			}
		}
		return;
	}
	return;
}
void showStudent1(int num)
{
	FILE *filecol,* filepro;
	int m=0,m1=0,m2=0;
	int a;
	int s=0;
	double h;
	filecol=fopen("collegedata","ab+");
	while(!feof(filecol))
	{
		if(fread(&col[m1],COLLEN,1,filecol)==1)
		m1++;
	}
	fclose(filecol);
	filepro=fopen("projectdata","ab+");
	while(!feof(filepro))
	{
		if(fread(&pro[m2],PROLEN,1,filepro)==1)
		m2++;
	}
	fclose(filepro);
	for(a=0;a<m1;a++){
		if(num==pro[a].num){
			break;
		}
	}
	m=getMessage(num);
	printf("名次      学号       姓名       性别        学院         成绩         积分\n");
	if(pro[a].unit==1)
	{
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<m1;j++)
			{
				if(stu[i].college_num==col[j].num)
				{
					s=(int)stu[i].pro_grade/60;
					h=(int)stu[i].pro_grade%60+stu[i].pro_grade-(int)stu[i].pro_grade;
					printf("NO.%-8d%-10d%-12s%-10s%-12s%d分%.2lf秒\t%d\n",i+1,stu[i].num,stu[i].name,stu[i].sex,col[j].name,s,h,stu[i].score);
					break;
				}
				
			}
		}
		return;
	}
	else
	{
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<m1;j++)
			{
				if(stu[i].college_num==col[j].num)
				{
					printf("NO.%-8d%-10d%-12s%-10s%-12s%.2lf米\t\t%d\n",i+1,stu[i].num,stu[i].name,stu[i].sex,col[j].name,stu[i].pro_grade,stu[i].score);
					break;
				}
			}
		}
		return;
	}
	return;
}
/****************************运动员信息管理结束****************************/

/****************************排名管理****************************/
void showProjectRank(int num)
{
	projectRank(num);
	showStudent1(num);
	
}
void projectRank(int num){
	int n,m1=0,t;
	char root[30]={"xiangmu\\\\"};
	FILE *fpro,*fps;
	struct student temp;
	fpro=fopen("projectdata","ab+");
	
	if(fpro==NULL){printf("can not open!");return;}
	while(!feof(fpro)){
		if(fread(&pro[m1],PROLEN,1,fpro)==1)
		m1++;
	}
	fclose(fpro);
	for(int i=0;i<m1;i++){
		if(num==pro[i].num){
			if(pro[i].unit==1) t=1;else t=2;//判断单位
			strcat(root,pro[i].name);
			break;
		}
	}//find project

	n=0;
	fps=fopen(root,"ab+");
	if(fps==NULL){printf("can not open!");return;}
	while(!feof(fps)){
		if(fread(&stu[n],STULEN,1,fps)==1)
		n++;
	}
	fclose(fps);//read stu

	if(t==1){//从小到大排序
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				if(stu[i].pro_grade>stu[j].pro_grade){
					temp=stu[i];
					stu[i]=stu[j];
					stu[j]=temp;
				}
			}
		}
	}
	else{//从大到小排序
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				if(stu[i].pro_grade<stu[j].pro_grade){
				    temp=stu[i];
					stu[i]=stu[j];
					stu[j]=temp;
				}
			}
		}
	}
	int p;
	int l;
	int p2;
	int x;
	if(n==6){stu[0].score=9;stu[1].score=7;stu[2].score=6;stu[3].score=5;stu[4].score=4;stu[5].score=3;} 
	if(n==7){stu[0].score=9;stu[1].score=7;stu[2].score=6;stu[3].score=5;stu[4].score=4;stu[5].score=3;stu[6].score=2;} 
	if(n>7&&stu[0].num!=0){stu[0].score=9;stu[1].score=7;stu[2].score=6;stu[3].score=5;stu[4].score=4;stu[5].score=3;stu[6].score=2;stu[7].score=1;p2=8; while(p2<n) stu[p2++].score=0;} 
	if(n>7&&stu[0].num==0){stu[0].score=18;stu[1].score=14;stu[2].score=12;stu[3].score=10;stu[4].score=8;stu[5].score=6;stu[6].score=4;stu[7].score=2;x=8; while(x<n) stu[x++].score=0;}
	saveMessage(n,num);
	return;
}

void collegeRank()
{
	FILE *filecol;
	FILE *filepro;
	int m1=0,m2=0,n;
	struct college temp;
	filecol=fopen("collegedata","ab+");
	while(!feof(filecol))
	{
		if(fread(&col[m1],COLLEN,1,filecol)==1)
		m1++;
	}
	fclose(filecol);
	filepro=fopen("projectdata","ab+");
	while(!feof(filepro))
	{
		if(fread(&pro[m2],PROLEN,1,filepro)==1)
		m2++;
	}
	fclose(filepro);
	for(int i=0;i<m1;i++)
		col[i].score=0;
	for(int i=0;i<m2;i++)
	{
		n=getMessage(pro[i].num);
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<m1;k++)
			{
				if(col[k].num==stu[j].college_num)
				{
					col[k].score+=stu[j].score;
					break;
				}
					
			}
		}
	}
	for(int i=0;i<m1-1;i++)
	{
		for(int j=i+1;j<m1;j++)
		{
			if(col[i].score<col[j].score)
			{
				temp=col[i];
				col[i]=col[j];
				col[j]=temp;
			}
		}
	}
	if((filecol=fopen("collegedata","wb"))==NULL)
	{
		printf("can not open\n");
		printf("按任意键返回...");
		getch();
		return;
	}
	for(int i=0;i<m1;i++)/*将新修改的信息写入指定的磁盘文件中*/
		if(fwrite(&col[i] ,COLLEN,1,filecol)!=1)
		{ 
			printf("can not save!"); 
			getch(); 
		}
	fclose(filecol);
}
void showCollegeRank()
{
	collegeRank();
	showCollege1();
}
void showCollege1()
{
	FILE *filecol;
	int m=0;
	filecol=fopen("collegedata","ab+");
	while(!feof(filecol))
	{
		if(fread(&col[m] ,COLLEN,1,filecol)==1) 
			m++;
	}  
	fclose(filecol);
	if(m==0)
	{
		printf("no record!\n");
	}
	else
	{
		printf("\tname      number      score\t\n");
		for(int i=0;i<m;i++)
		{ 
			printf("NO.%d\t",i+1);
			printf(COLFORMAT,COLDATA);/*将信息按指定格式打印*/
		}
	}
	return;
}

/****************************排名管理结束****************************/


/****************************主函数****************************/
int main()
{
	int n; //选择菜单编号 
	menu();
	scanf("%d",&n);
	while(n!=0)
	{
		switch(n)
		{
			case 1:   
				showProject();//比赛项目公布 
				getch();
				break;
			case 2:
				messageMenu();//比赛信息查询 
				break;
			case 3:
				getorder();//秩序册 
				break;
			case 4:
				adminMenu();//管理员登录 
				break;
			default:break;
		}
		menu();
		scanf("%d",&n);
	}
 	printf("按任意键退出...");
	getch();
	return 0;
} 
/****************************主函数****************************/

void getorder()
{
	int day=1;
	char root[20];
	FILE *filepro;
	FILE *file;
	int m1=0,mm=0;
	int q=0,w=0,e=0,r=0,t=0,y=0,u=0;
	int z=0,ww=0,ee=0;
	int a;
	double b;
	float time=8;
	struct aa{
			int time;
			char name[100];
			char place[100];
			int placenum;
		}a1[50],a2[50],a3[50],a4[50],a5[50],a6[50],a7[50],a8[50],a9[50],a10[50];
	
	filepro=fopen("projectdata","ab+");  //这一段主要是把东西保存到数组pro 
	while(!feof(filepro))
	{
		if(fread(&pro[m1] ,PROLEN,1,filepro)==1) 
			m1++;
	}
	fclose(filepro);



	for(int i=0;i<m1;i++){
//		mm=0; 
		
		switch (pro[i].placeNum){
					
			case 1:
				a1[q+1].time=0;
				strcpy(a1[q].name,pro[i].name);
				strcpy(a1[q].place,pro[i].place);
				a1[q].time=pro[i].time;
				q++;
				break;
				
				
			case 2:
				a2[w+1].time=0;
				strcpy(a2[w].name,pro[i].name);
				strcpy(a2[w].place,pro[i].place);
				a2[w].time=pro[i].time;
				w++;
				break;
//				
			case 3:
				a3[e+1].time=0;
				strcpy(a3[e].name,pro[i].name);
				strcpy(a3[e].place,pro[i].place);
				a3[e].time=pro[i].time;
				e++;
				break;
				
			case 4:
				a4[r+1].time=0;
				strcpy(a4[r].name,pro[i].name);
				strcpy(a4[r].place,pro[i].place);
				a4[r].time=pro[i].time;
				r++;
				break;
			case 5:
				a5[t+1].time=0;
				strcpy(a5[t].name,pro[i].name);
				strcpy(a5[t].place,pro[i].place);
				a5[t].time=pro[i].time;
				t++;
				break;
//			case 6:
//				a6[y+1].time=0;
//				strcpy(a6[y].name,pro[i].name);
//				strcpy(a6[y].place,pro[i].place);
//				a6[y].time=pro[i].time;
//				y++;
//				break;
//			case 7:
//				a7[u+1].time=0;
//				strcpy(a7[u].name,pro[i].name);
//				strcpy(a7[u].place,pro[i].place);
//				a7[u].time=pro[i].time;
//				u++;
//				break;
//				
//			case 8:
//				a8[z+1].time=0;
//				strcpy(a8[z].name,pro[i].name);
//				strcpy(a8[z].place,pro[i].place);
//				a8[z].time=pro[i].time;
//				z++;
//				break;
//				
//			case 9:
//				a9[ww+1].time=0;
//				strcpy(a9[ww].name,pro[i].name);
//				strcpy(a9[ww].place,pro[i].place);
//				a9[ww].time=pro[i].time;
//				ww++;
//				break;
//			case 10:
//				a10[ee+1].time=0;
//				strcpy(a10[ee].name,pro[i].name);
//				strcpy(a10[ee].place,pro[i].place);
//				a10[ee].time=pro[i].time;
//				ee++;
//				break;
			default:
				printf("hello");

		}
	}
	
	
	
	printf("\t\t\t\t\t\t\t运动会秩序表\n");
	printf("\t运动项目\t\t\t运动场地\t\t运动时间\n\n\n");
	
	day=1; 	
	time=8;
	for(int j=0;a2[j].time!=0;j++)
	{
		if (time==8){
			printf("%45s%d%s\n\n","第",day,"天");
		}
		
		printf("%-15s",a2[j].name); 
		printf("\t\t\t") ;
		printf("%15s",a2[j].place);
		printf("\t\t\t") ;	
			
		if ((int)((time-int(time))*60)<10){
			printf("%d%s%d%s",int(time),":0",(int)((time-int(time))*60),"--");
		}
		else{
			printf("%d%s%d%s",int(time),":",(int)((time-int(time))*60),"--");
		}
		time=time+a2[j].time*1.0/60+0.001;
		
		if ((int)((time-int(time))*60)<10){
			printf("%d%s%d",int(time),":0",(int)((time-int(time))*60));
		}
		else{
			printf("%d%s%d",int(time),":",(int)((time-int(time))*60));
		}
		time=time+10*1.0/60;
		
		if (time>11&&time<14){
			 
			time=14.0; 
			printf("\n\n");
		}
		if (time>18){
			time=8;
			day=day+1;
			printf("\n\n");	
		}
	printf("\n");


}
printf("\n\n\n\n");

 
	time=8;
	day=1;
	for(int j=0;a1[j].time!=0;j++)
	{
		if (time==8){
			printf("%45s%d%s\n\n","第",day,"天");
		}
		printf("%-10s",a1[j].name); 
		printf("\t\t\t") ;
		printf("%15s",a1[j].place);

		printf("\t\t\t") ;	
//			
		if ((int)((time-int(time))*60)<10){
			printf("%d%s%d%s",int(time),":0",(int)((time-int(time))*60),"--");
		}
		else{
			printf("%d%s%d%s",int(time),":",(int)((time-int(time))*60),"--");
		}
		time=time+a1[j].time*1.0/60+0.001;
		
		if ((int)((time-int(time))*60)<10){
			printf("%d%s%d",int(time),":0",(int)((time-int(time))*60));
		}
		else{
			printf("%d%s%d",int(time),":",(int)((time-int(time))*60));
		}
		time=time+10*1.0/60;
//		
		if (time>11&&time<14){
			 
			time=14.0; 
			printf("\n\n");
		}
		if (time>18){
			time=8;
			day=day+1;
			printf("\n\n");	
		}
	printf("\n");
} 

printf("\n\n\n\n");
 
	time=8;
	day=1;
	for(int j=0;a3[j].time!=0;j++)
	{
		if (time==8){
			printf("%45s%d%s\n\n","第",day,"天");
		}
		printf("%-10s",a3[j].name); 
		printf("\t\t\t") ;
		printf("%15s",a3[j].place);

		printf("\t\t\t") ;	
//			
		if ((int)((time-int(time))*60)<10){
			printf("%d%s%d%s",int(time),":0",(int)((time-int(time))*60),"--");
		}
		else{
			printf("%d%s%d%s",int(time),":",(int)((time-int(time))*60),"--");
		}
		time=time+a1[j].time*1.0/60+0.001;
		
		if ((int)((time-int(time))*60)<10){
			printf("%d%s%d",int(time),":0",(int)((time-int(time))*60));
		}
		else{
			printf("%d%s%d",int(time),":",(int)((time-int(time))*60));
		}
		time=time+10*1.0/60;
//		
		if (time>11&&time<14){
			 
			time=14.0; 
			printf("\n\n");
		}
		if (time>18){
			time=8;
			day=day+1;
			printf("\n\n");	
		}
	printf("\n");
} 

printf("\n\n\n\n");
 
	time=8;
	day=1;
	for(int j=0;a4[j].time!=0;j++)
	{
		if (time==8){
			printf("%45s%d%s\n\n","第",day,"天");
		}
		printf("%-10s",a4[j].name); 
		printf("\t\t\t") ;
		printf("%15s",a4[j].place);

		printf("\t\t\t") ;	
//			
		if ((int)((time-int(time))*60)<10){
			printf("%d%s%d%s",int(time),":0",(int)((time-int(time))*60),"--");
		}
		else{
			printf("%d%s%d%s",int(time),":",(int)((time-int(time))*60),"--");
		}
		time=time+a1[j].time*1.0/60+0.001;
		
		if ((int)((time-int(time))*60)<10){
			printf("%d%s%d",int(time),":0",(int)((time-int(time))*60));
		}
		else{
			printf("%d%s%d",int(time),":",(int)((time-int(time))*60));
		}
		time=time+10*1.0/60;
//		
		if (time>11&&time<14){
			 
			time=14.0; 
			printf("\n\n");
		}
		if (time>18){
			time=8;
			day=day+1;
			printf("\n\n");	
		}
	printf("\n");
} 

printf("\n\n\n\n");
 
	time=8;
	day=1;
	for(int j=0;a5[j].time!=0;j++)
	{
		if (time==8){
			printf("%45s%d%s\n\n","第",day,"天");
		}
		printf("%-10s",a5[j].name); 
		printf("\t\t\t") ;
		printf("%15s",a5[j].place);

		printf("\t\t\t") ;	
//			
		if ((int)((time-int(time))*60)<10){
			printf("%d%s%d%s",int(time),":0",(int)((time-int(time))*60),"--");
		}
		else{
			printf("%d%s%d%s",int(time),":",(int)((time-int(time))*60),"--");
		}
		time=time+a1[j].time*1.0/60+0.001;
		
		if ((int)((time-int(time))*60)<10){
			printf("%d%s%d",int(time),":0",(int)((time-int(time))*60));
		}
		else{
			printf("%d%s%d",int(time),":",(int)((time-int(time))*60));
		}
		time=time+10*1.0/60;
//		
		if (time>11&&time<14){
			 
			time=14.0; 
			printf("\n\n");
		}
		if (time>18){
			time=8;
			day=day+1;
			printf("\n\n");	
		}
	printf("\n");
} 

printf("\n\n\n\n");
 
	time=8;
	day=1;
	for(int j=0;a6[j].time!=0;j++)
	{
		if (time==8){
			printf("%45s%d%s\n\n","第",day,"天");
		}
		printf("%-10s",a6[j].name); 
		printf("\t\t\t") ;
		printf("%15s",a6[j].place);

		printf("\t\t\t") ;	
//			
		if ((int)((time-int(time))*60)<10){
			printf("%d%s%d%s",int(time),":0",(int)((time-int(time))*60),"--");
		}
		else{
			printf("%d%s%d%s",int(time),":",(int)((time-int(time))*60),"--");
		}
		time=time+a1[j].time*1.0/60+0.001;
		
		if ((int)((time-int(time))*60)<10){
			printf("%d%s%d",int(time),":0",(int)((time-int(time))*60));
		}
		else{
			printf("%d%s%d",int(time),":",(int)((time-int(time))*60));
		}
		time=time+10*1.0/60;
//		
		if (time>11&&time<14){
			 
			time=14.0; 
			printf("\n\n");
		}
		if (time>18){
			time=8;
			day=day+1;
			printf("\n\n");	
		}
	printf("\n");
} 



printf("\n\n\n\n");
 
	time=8;
	day=1;
	for(int j=0;a7[j].time!=0;j++)
	{
		if (time==8){
			printf("%45s%d%s\n\n","第",day,"天");
		}
		printf("%-10s",a7[j].name); 
		printf("\t\t\t") ;
		printf("%15s",a7[j].place);

		printf("\t\t\t") ;	
//			
		if ((int)((time-int(time))*60)<10){
			printf("%d%s%d%s",int(time),":0",(int)((time-int(time))*60),"--");
		}
		else{
			printf("%d%s%d%s",int(time),":",(int)((time-int(time))*60),"--");
		}
		time=time+a1[j].time*1.0/60+0.001;
		
		if ((int)((time-int(time))*60)<10){
			printf("%d%s%d",int(time),":0",(int)((time-int(time))*60));
		}
		else{
			printf("%d%s%d",int(time),":",(int)((time-int(time))*60));
		}
		time=time+10*1.0/60;
//		
		if (time>11&&time<14){
			 
			time=14.0; 
			printf("\n\n");
		}
		if (time>18){
			time=8;
			day=day+1;
			printf("\n\n");	
		}
	printf("\n");
} 


printf("\n\n\n\n");

 
	time=8;
	day=1;
	for(int j=0;a8[j].time!=0;j++)
	{
		if (time==8){
			printf("%45s%d%s\n\n","第",day,"天");
		}
		printf("%-10s",a8[j].name); 
		printf("\t\t\t") ;
		printf("%15s",a8[j].place);

		printf("\t\t\t") ;	
//			
		if ((int)((time-int(time))*60)<10){
			printf("%d%s%d%s",int(time),":0",(int)((time-int(time))*60),"--");
		}
		else{
			printf("%d%s%d%s",int(time),":",(int)((time-int(time))*60),"--");
		}
		time=time+a1[j].time*1.0/60+0.001;
		
		if ((int)((time-int(time))*60)<10){
			printf("%d%s%d",int(time),":0",(int)((time-int(time))*60));
		}
		else{
			printf("%d%s%d",int(time),":",(int)((time-int(time))*60));
		}
		time=time+10*1.0/60;
//		
		if (time>11&&time<14){
			 
			time=14.0; 
			printf("\n\n");
		}
		if (time>18){
			time=8;
			day=day+1;
			printf("\n\n");	
		}
	printf("\n");
} 

printf("\n\n\n\n");
 
	time=8;
	day=1;
	for(int j=0;a9[j].time!=0;j++)
	{
		if (time==8){
			printf("%45s%d%s\n\n","第",day,"天");
		}
		printf("%-10s",a9[j].name); 
		printf("\t\t\t") ;
		printf("%15s",a9[j].place);

		printf("\t\t\t") ;	
//			
		if ((int)((time-int(time))*60)<10){
			printf("%d%s%d%s",int(time),":0",(int)((time-int(time))*60),"--");
		}
		else{
			printf("%d%s%d%s",int(time),":",(int)((time-int(time))*60),"--");
		}
		time=time+a1[j].time*1.0/60+0.001;
		
		if ((int)((time-int(time))*60)<10){
			printf("%d%s%d",int(time),":0",(int)((time-int(time))*60));
		}
		else{
			printf("%d%s%d",int(time),":",(int)((time-int(time))*60));
		}
		time=time+10*1.0/60;
//		
		if (time>11&&time<14){
			 
			time=14.0; 
			printf("\n\n");
		}
		if (time>18){
			time=8;
			day=day+1;
			printf("\n\n");	
		}
	printf("\n");
} 

printf("\n\n\n\n");
 
	time=8;
	day=1;
	for(int j=0;a10[j].time!=0;j++)
	{
		if (time==8){
			printf("%45s%d%s\n\n","第",day,"天");
		}
		printf("%-10s",a10[j].name); 
		printf("\t\t\t") ;
		printf("%15s",a10[j].place);

		printf("\t\t\t") ;	
//			
		if ((int)((time-int(time))*60)<10){
			printf("%d%s%d%s",int(time),":0",(int)((time-int(time))*60),"--");
		}
		else{
			printf("%d%s%d%s",int(time),":",(int)((time-int(time))*60),"--");
		}
		time=time+a1[j].time*1.0/60+0.001;
		
		if ((int)((time-int(time))*60)<10){
			printf("%d%s%d",int(time),":0",(int)((time-int(time))*60));
		}
		else{
			printf("%d%s%d",int(time),":",(int)((time-int(time))*60));
		}
		time=time+10*1.0/60;
//		
		if (time>11&&time<14){
			 
			time=14.0; 
			printf("\n\n");
		}
		if (time>18){
			time=8;
			day=day+1;
			printf("\n\n");	
		}
	printf("\n");
} 
getch();
}
