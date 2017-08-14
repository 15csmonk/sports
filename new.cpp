#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#include <direct.h> //�ļ��еĴ��� 
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
	int unit;//1��ʾʱ����  2��ʾ������
	int time;//��λ�� 
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

struct student/*����ѧ���ɼ��ṹ��*/
{ 
	int num;
	char name[15];
	char sex[4];
	int college_num;
	int score;
	int pro_num;
	double pro_grade;
	int pro_score;//���룬����  
};


struct student stu[100];/*����ṹ������*/
struct project pro[100];
struct college col[20];

/************************�˵�������********************************/
void menu();//���˵� 
void menu1();//������Ϣ��ѯ�˵� 
void messageMenu();//������Ϣ��ѯ 
void menu2();//����Ա�˵� 
void adminMenu();//����Ա
void menu3();//��Ŀ����˵� 
void projectMenu();//��Ŀ���� 
void menu4();//ѧԺ����˵� 
void collegeMenu();//ѧԺ���� 
void menu5();//�˶�Ա��Ϣ����˵� 
void studentMenu();// �˶�Ա��Ϣ���� 
/************************�˵������ֽ���********************************/



/************************��Ŀ��Ϣ����********************************/
void inProject();
void delProject();
void modProject();
void showProject();
/************************��Ŀ��Ϣ�������********************************/


/************************ѧԺ��Ϣ����********************************/
void inCollege();//���� 
void delCollege();//ɾ��
void modCollege();//�޸� 
void showCollege();//��ѯ
/************************ѧԺ��Ϣ�������********************************/


/************************�˶�Ա��Ϣ����********************************/
int getMessage(int num);//������Ŀ���num�����ظ���Ŀ���� 
void saveMessage(int m,int num);//������Ŀ���num������Ŀ����m
void inStudent();//���� 
void delStudent();//ɾ��
void modStudent();//�޸� 
void showStudent(int num);//��ѯ
void inScore();//¼��ɼ� 

/************************�˶�Ա��Ϣ�������********************************/

/************************��������********************************/
void projectRank(int num);
void showProjectRank(int num);
void showStudent1(int num);//��ѯ
void collegeRank();
void showCollegeRank();
void showCollege1();
/************************�����������********************************/
void getorder();


/************************�˵�������********************************/
void menu()/*�Զ��庯��ʵ�ֲ˵�����*/
{
	system("cls");
	printf("================================================================================");
	printf("                   �� ӭ �� �� �� ѧ �� �� �� �� �� ϵ ͳ \n");
	printf("================================================================================\n");
	printf("\n\n\n");
	printf("\t\t|--------------------welcome--------------------|\n");
	printf("\t\t|\t 1. ������Ŀ����                        |\n");
	printf("\t\t|\t 2. ������Ϣ��ѯ                        |\n");
	printf("\t\t|\t 3. �����ճ̹���                        |\n");
	printf("\t\t|\t 4. ����Ա��¼                          |\n");
	printf("\t\t|\t 0. �˳�                                |\n");
	printf("\t\t|-----------------------------------------------|\n\n");
	printf("\t\t\tchoose(0-4):");
}

void menu1()
{
	system("cls");
	printf("================================================================================");
	printf("                   �� ӭ �� �� �� ѧ �� �� �� �� �� ϵ ͳ \n");
	printf("================================================================================\n");
	printf("\n\n\n");
	printf("\t\t|--------------------welcome--------------------|\n");
	printf("\t\t|\t 1. ������Ϣ                            |\n");
	printf("\t\t|\t 2. ��Ŀ����                            |\n");
	printf("\t\t|\t 3. ѧԺ����                            |\n");
	printf("\t\t|\t 0. ����                                |\n");
	printf("\t\t|-----------------------------------------------|\n\n");
	printf("\t\t\tchoose(0-3):");
}

void messageMenu()
{
	int n,a; //ѡ��˵���� 
	menu1();
	scanf("%d",&n);
	while(n!=0)
	{
		switch(n)
		{
			case 1:   
				showProject(); 
				printf("������Ҫ�鿴����Ŀ��ţ�");
				scanf("%d",&a);
				system("cls");
				showStudent(a);//��ѯ
				getch();
				break;
			case 2:
				showProject(); 
				printf("������Ҫ�鿴����Ŀ��ţ�");
				scanf("%d",&a);
				system("cls");
				showProjectRank(a);//��Ŀ���� 
				getch();
				break;
			case 3:
				system("cls");
				showCollegeRank();//ѧԺ���� 
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
	printf("                   �� ӭ �� �� �� ѧ �� �� �� �� �� ϵ ͳ \n");
	printf("================================================================================\n");
	printf("\n\n\n");
	printf("\t\t|---------------------admin---------------------|\n");
	printf("\t\t|\t 1. ��Ŀ��Ϣ����                        |\n");
	printf("\t\t|\t 2. ѧԺ��Ϣ����                        |\n");
	printf("\t\t|\t 3. �˶�Ա��Ϣ����                      |\n");
	printf("\t\t|\t 4. ���������                          |\n");
	printf("\t\t|\t 0. ����                                |\n");
	printf("\t\t|-----------------------------------------------|\n\n");
	printf("\t\t\tchoose(0-4):");
}
void adminMenu()
{
	char psw[9]={"Ab123456"};
	char input[9]={NULL};
	int i,n; //ѡ��˵���� 
	printf("���������Ա����:");
	for(i=0;i<8;i++)
	{
		input[i]=getch();
		printf("*");
	}
	input[i]='\0';
	if(strcmp(input,psw)!=0)
	{
		printf("\n�������\n");
		printf("�����������...");
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
				projectMenu();//��Ŀ��Ϣ���� 
				break;
			case 2:
				collegeMenu();//ѧԺ��Ϣ���� 
				break;
			case 3:
				studentMenu();//�˶�Ա��Ϣ���� 
				break;
			case 4:
				getorder();//����� 
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
	printf("                   �� ӭ �� �� �� ѧ �� �� �� �� �� ϵ ͳ \n");
	printf("================================================================================\n");
	printf("\n\n\n");
	printf("\t\t|---------------------admin---------------------|\n");
	printf("\t\t|\t 1. ¼����Ŀ��Ϣ                        |\n");
	printf("\t\t|\t 2. ɾ����Ŀ��Ϣ                        |\n");
	printf("\t\t|\t 3. �޸���Ŀ��Ϣ                        |\n");
	printf("\t\t|\t 4. ��ѯ��Ŀ��Ϣ                        |\n");
	printf("\t\t|\t 0. ����                                |\n");
	printf("\t\t|-----------------------------------------------|\n\n");
	printf("\t\t\tchoose(0-4):");
}
void projectMenu()
{
	int n; //ѡ��˵���� 
	menu3();
	scanf("%d",&n);
	while(n!=0)
	{
		switch(n)
		{
			case 1:   
				inProject();//���� 
				break;
			case 2:
				delProject();//ɾ��
				break;
			case 3:
				modProject();//�޸� 
				break;
			case 4:
				showProject();//��ѯ
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
	printf("                   �� ӭ �� �� �� ѧ �� �� �� �� �� ϵ ͳ \n");
	printf("================================================================================\n");
	printf("\n\n\n");
	printf("\t\t|---------------------admin---------------------|\n");
	printf("\t\t|\t 1. ¼��ѧԺ��Ϣ                        |\n");
	printf("\t\t|\t 2. ɾ��ѧԺ��Ϣ                        |\n");
	printf("\t\t|\t 3. �޸�ѧԺ��Ϣ                        |\n");
	printf("\t\t|\t 4. ��ѯѧԺ��Ϣ                        |\n");
	printf("\t\t|\t 0. ����                                |\n");
	printf("\t\t|-----------------------------------------------|\n\n");
	printf("\t\t\tchoose(0-4):");
}
void collegeMenu()
{
	int n; //ѡ��˵���� 
	menu4();
	scanf("%d",&n);
	while(n!=0)
	{
		switch(n)
		{
			case 1:   
				inCollege();//���� 
				break;
			case 2:
				delCollege();//ɾ��
				break;
			case 3:
				modCollege();//�޸� 
				break;
			case 4:
				showCollege();//��ѯ
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
	printf("                   �� ӭ �� �� �� ѧ �� �� �� �� �� ϵ ͳ \n");
	printf("================================================================================\n");
	printf("\n\n\n");
	printf("\t\t|---------------------admin---------------------|\n");
	printf("\t\t|\t 1. ¼���˶�Ա��Ϣ                      |\n");
	printf("\t\t|\t 2. ɾ���˶�Ա��Ϣ                      |\n");
	printf("\t\t|\t 3. �޸��˶�Ա��Ϣ                      |\n");
	printf("\t\t|\t 4. ��ѯ�˶�Ա��Ϣ                      |\n");
	printf("\t\t|\t 5. ¼���˶�Ա�ɼ�                      |\n");
	printf("\t\t|\t 0. ����                                |\n");
	printf("\t\t|-----------------------------------------------|\n\n");
	printf("\t\t\tchoose(0-5):");
}
void studentMenu()
{
	int n; //ѡ��˵���� 
	int a;
	menu5();
	scanf("%d",&n);
	while(n!=0)
	{
		switch(n)
		{
			case 1:   
				inStudent();//���� 
				break;
			case 2:
				delStudent();//ɾ��
				break;
			case 3:
				modStudent();//�޸� 
				break;
			case 4:
				showProject(); 
				printf("������Ҫ�鿴����Ŀ��ţ�");
				scanf("%d",&a);
				system("cls");
				showStudent(a);//��ѯ
				getch();
				break;
			case 5:
				inScore();//¼��ɼ� 
				break;
			default:break;
		}
		menu5();
		scanf("%d",&n);
	}
	return;
}
/****************************�˵������ֽ���****************************/



/****************************��Ŀ��Ϣ����****************************/
void inProject()//¼����Ŀ��Ϣ
{
	int i,m=0;/*m�Ǽ�¼������*/
	char ch[2];
	FILE *filepro;/*�����ļ�ָ��*/
	FILE *fp;
	if((filepro=fopen("projectdata","ab+"))==NULL)/*��ָ���ļ�*/
	{ 
		printf("can not open\n");
		return;
	}
	while(!feof(filepro)) 
	{ 
		if(fread(&pro[m] ,PROLEN,1,filepro)==1)
			m++;/*ͳ�Ƶ�ǰ��¼����*/
	}
	fclose(filepro);
	system("cls");
	showProject();/*����show��������ʾԭ����Ϣ*/


	if((filepro=fopen("projectdata","wb"))==NULL)
	{ 
		printf("can not open\n");
		return;
	}
	for(i=0;i<m;i++) 
		fwrite(&pro[i] ,PROLEN,1,filepro);/*��ָ���Ĵ����ļ�д����Ϣ*/

	ch[0]='y';
    while(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)/*�ж��Ƿ�Ҫ¼������Ϣ*/
	{
		printf("project name:");
		scanf("%s",&pro[m].name);
		
		printf("project num:");
		scanf("%d",&pro[m].num);
		
		printf("place:");
		scanf("%s",&pro[m].place);
		
		printf("place num:");
		scanf("%d",&pro[m].placeNum);
		
		printf("unit(1.��  2.��):");
		scanf("%d",&pro[m].unit);
		
		printf("time(min):");
		scanf("%d",&pro[m].time);
			
		if(fwrite(&pro[m],PROLEN,1,filepro)!=1)/*����¼�����Ϣд��ָ���Ĵ����ļ�*/
		{
			printf("can not save!"); 
			getch(); 
		}
		else
		{ 
			printf("%s saved!\n",pro[m].name);
			m++;
		}
			printf("����������?(y/n):");/*ѯ���Ƿ����*/
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
		printf("�����������...");
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
		printf("�����������...");
		getch();
		return;
	}
	else
	{
		system("cls");
		showProject();/*����show��������ʾԭ����Ϣ*/
	}
	printf("��������Ŀ���:");
	scanf("%d",&snum);
	for(i=0;i<m;i++)
		if(snum==pro[i].num)
			break;
 	if(i==m)
	{
		printf("can not find��");
		printf("�����������...");
		getch();
		return;
	}
		
	printf("�ҵ��ˣ�ȷ��ɾ����(y/n)");
	scanf("%s",ch);
	if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)/*�ж��Ƿ�Ҫ����ɾ��*/
	{
		for(int j=i;j<m;j++)
			pro[j]=pro[j+1];/*����һ����¼�Ƶ�ǰһ����¼��λ��*/
			m--;/*��¼���ܸ�����1*/
			printf("ɾ���ɹ�!\n");
	}
	if((filepro=fopen("projectdata","wb"))==NULL)
	{ 
		printf("can not open\n");
		printf("�����������...");
		getch();
		return;
	}
	for(int j=0;j<m;j++)/*�����ĺ�ļ�¼����д��ָ���Ĵ����ļ���*/
		if(fwrite(&pro[j] ,PROLEN,1,filepro)!=1)
		{ 
			printf("can not save!\n");
			printf("�����������...");
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
		printf("�����������...");
		getch();
		return;
	}
	else
	{
		system("cls");
		showProject();/*����show��������ʾԭ����Ϣ*/
	}
		
	printf("��������Ŀ���!\n");
	scanf("%d",&snum);
	for(i=0;i<m;i++)
		if(snum==pro[i].num)/*������¼���Ƿ���Ҫ�޸ĵ���Ϣ*/
			break;
	if(i<m)
	{	
		printf("�ҵ���! \n");
		system("cls");
		printf("name      number      place      placeNum        unit       time\t\n");
		printf(PROFORMAT,PRODATA);/*�����ҳ��Ľ����ָ����ʽ���*/
		printf("���޸���һ������?(1.name 2.number 3.place 4.placeNum 5.unit  6.time):");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("project name:");
				scanf("%s",&pro[i].name);/*������Ŀ����*/
				break;
			case 2:
				printf("project number:");
				scanf("%d",&pro[i].num);/*������Ŀ���*/
				break;
			case 3:
				printf("place:");
				scanf("%s",&pro[i].place);/*������Ŀ�ص�*/
				break;
			case 4:
				printf("place number:");
				scanf("%d",&pro[i].placeNum);/*������Ŀ�ص���*/
				break;
			case 5:
				printf("unit(1.�� 2.��):");
				scanf("%d",&pro[i].unit);/*������Ŀ�ص���*/
				break;
			case 6:
				printf("time(min):");
				scanf("%d",&pro[i].time);/*������Ŀ�ص���*/
				break;
				default:break;
		}
	}
	else 
	{
		printf("can not find!");
		printf("�����������...");
		getch();
		return;
	}
	if((filepro=fopen("projectdata","wb"))==NULL)
	{
		printf("can not open\n");
		printf("�����������...");
		getch();
		return;
	}
	for(j=0;j<m;j++)/*�����޸ĵ���Ϣд��ָ���Ĵ����ļ���*/
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
			printf(PROFORMAT,PRODATA);/*����Ϣ��ָ����ʽ��ӡ*/
		}
	}
	return;
}
/****************************��Ŀ��Ϣ�������****************************/




/****************************ѧԺ��Ϣ����****************************/
void inCollege()//¼����Ŀ��Ϣ
{
	int i,m=0;/*m�Ǽ�¼������*/
	char ch[2];
	FILE *filecol;/*�����ļ�ָ��*/
	if((filecol=fopen("collegedata","ab+"))==NULL)/*��ָ���ļ�*/
	{ 
		printf("can not open\n");
		printf("�����������...");
		getch();
		return;
	}
	while(!feof(filecol)) 
	{ 
		if(fread(&col[m] ,COLLEN,1,filecol)==1)
			m++;/*ͳ�Ƶ�ǰ��¼����*/
	}
	fclose(filecol);
	system("cls");
	showCollege();/*����show��������ʾԭ����Ϣ*/
	
	if((filecol=fopen("collegedata","wb"))==NULL)
	{ 
		printf("can not open\n");
		return;
	}
	for(i=0;i<m;i++) 
		fwrite(&col[i] ,COLLEN,1,filecol);/*��ָ���Ĵ����ļ�д����Ϣ*/
	ch[0]='y';
	
    while(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)/*�ж��Ƿ�Ҫ¼������Ϣ*/
	{
		printf("college name:");
		scanf("%s",&col[m].name);
		
		printf("college num:");
		scanf("%d",&col[m].num);
		
			
		if(fwrite(&col[m],COLLEN,1,filecol)!=1)/*����¼�����Ϣд��ָ���Ĵ����ļ�*/
		{
			printf("can not save!"); 
			getch(); 
		}
		else
		{ 
			printf("%s saved!\n",col[m].name);
			m++;
		}
			printf("����������?(y/n):");/*ѯ���Ƿ����*/
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
		printf("�����������...");
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
		printf("�����������...");
		getch();
		return;
	}
	else
	{
		system("cls");
		showCollege();/*����show��������ʾԭ����Ϣ*/
	}
	
	printf("������ѧԺ���:");
	scanf("%d",&snum);
	for(i=0;i<m;i++)
		if(snum==col[i].num)
			break;
 	if(i==m)
	{
		printf("can not find��");
		printf("�����������...");
		getch();
		return;
	}
	printf("�ҵ��ˣ�ȷ��ɾ����(y/n)");
	scanf("%s",ch);
	if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)/*�ж��Ƿ�Ҫ����ɾ��*/
	{
		for(int j=i;j<m;j++)
			col[j]=col[j+1];/*����һ����¼�Ƶ�ǰһ����¼��λ��*/
			m--;/*��¼���ܸ�����1*/
			printf("ɾ���ɹ�!\n");
	}
	if((filecol=fopen("collegedata","wb"))==NULL)
	{ 
		printf("can not open\n");
		printf("�����������...");
		getch();
		return;
	}
	for(int j=0;j<m;j++)/*�����ĺ�ļ�¼����д��ָ���Ĵ����ļ���*/
		if(fwrite(&col[j] ,COLLEN,1,filecol)!=1)
		{ 
			printf("can not save!\n");
			printf("�����������...");
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
		printf("�����������...");
		getch();
		return;
	}
	else
	{
		system("cls");
		showCollege();/*����show��������ʾԭ����Ϣ*/
	}
		
	printf("������ѧԺ���!\n");
	scanf("%d",&snum);
	for(i=0;i<m;i++)
		if(snum==col[i].num)/*������¼���Ƿ���Ҫ�޸ĵ���Ϣ*/
			break;
	if(i<m)
	{	
		printf("�ҵ���! \n");
		system("cls");
		printf("name      number      score\t\n");
		printf(COLFORMAT,COLDATA);/*�����ҳ��Ľ����ָ����ʽ���*/
		printf("���޸���һ������?(1.name 2.number):");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("college name:");
				scanf("%s",&col[i].name);/*������Ŀ����*/
				break;
			case 2:
				printf("college number:");
				scanf("%d",&col[i].num);/*������Ŀ���*/
				break;
				default:break;
		}
	}
	else 
	{
		printf("can not find!");
		printf("�����������...");
		getch();
		return;
	}
	if((filecol=fopen("collegedata","wb"))==NULL)
	{
		printf("can not open\n");
		printf("�����������...");
		getch();
		return;
	}
	for(j=0;j<m;j++)/*�����޸ĵ���Ϣд��ָ���Ĵ����ļ���*/
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
			printf(COLFORMAT,COLDATA);/*����Ϣ��ָ����ʽ��ӡ*/
		}
	}
	return;
}

/****************************ѧԺ��Ϣ�������****************************/


/****************************�˶�Ա��Ϣ����****************************/
int getMessage(int num){//��ȡ��Ŀ������,���ҽ�ѧ����Ϣ�浽ȫ�ֱ���stu���� 
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

void saveMessage(int m,int num){//����stu����m����stu���´����Ŀ���Ϊnum���ļ����� 
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
void inStudent()/*¼��ѧ����Ϣ*/
{ 
	int num,m=0;//num��Ŀ���,m�����е��˶�Ա���� 
	int ch;
	
    while(true)//����¼��ֱ���˳� 
	{
		system("cls");
		showProject();
		printf("\n�����ĸ���Ŀ��(0�˳�)��");
		scanf("%d",&num);
		if(num==0)//����0ʱ�˳� 
		{
			break; 
		} 
		m=getMessage(num);
		if(m==-1)
		{
			printf("��ȡ�ļ�����!\n");
			printf("�����������...");
			getch();
			return; 
		}
		ch=1;
		while(ch==1)/*�ж��Ƿ�Ҫ¼������Ϣ*/
		{
			system("cls");
			printf("ѧ��:");
			scanf("%d",&stu[m].num);/*����ѧ��ѧ��*/
			printf("����:");
			scanf("%s",&stu[m].name);/*����ѧ������*/
			printf("�Ա�:");
			scanf("%s",&stu[m].sex);/*����ѧ��sex*/
			showCollege();
			printf("\nѧԺ:");
			scanf("%d",&stu[m].college_num);/*����ѧ������ѧԺ*/
			stu[m].pro_num=num;/*������Ŀ���*/
			m++;
			printf("continue?(1/0):");/*ѯ���Ƿ����*/
			scanf("%d",&ch);	
		}
		saveMessage(m,num);
		printf("�����������...");
		getch(); 
	}
	printf("OK!\n");
	return;
}

void inScore()/*¼��ѧ���ɼ�*/
{ 
	int num,m=0,m1=0,i;//num��Ŀ���,m�����е��˶�Ա���� 
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
    while(true)//����¼��ֱ���˳� 
	{
		system("cls");
		showProject();
		printf("\n¼���ĸ���Ŀ��(0�˳�)��");
		scanf("%d",&num);
		if(num==0)//����0ʱ�˳� 
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
			printf("��ȡ�ļ�����!\n");
			printf("�����������...");
			getch();
			return; 
		}
		switch(pro[i].unit)
		{
			case 1:
				for(int j=0;j<m;j++)
				{
					printf("%s\t\t�ɼ����� �� ���룩��",stu[j].name);
					scanf("%d%d%d",&min,&sec,&mm);/*����ѧ��ѧ��*/
					stu[j].pro_grade=60*min+sec+(mm/100.0);
				}
				break;
			case 2:
				for(int j=0;j<m;j++)
				{
					printf("%s\t\t�ɼ����ף���",stu[j].name);
					scanf("%lf",&stu[j].pro_grade);
				}
				break;
			default:break;
		}
		
				
		saveMessage(m,num);
		printf("�����������...");
		getch(); 
	}
	printf("OK!\n");
	return;
}

void delStudent()/*�Զ���ɾ������*/
{
	
	FILE *fp;
	int snum,i,j,m=0;
	int num;
	int ch;
	showProject(); 
	printf("������Ҫɾ�����˶�Ա��Ŀ��ţ�");
	scanf("%d",&num);
	m=getMessage(num);
	system("cls");
	showStudent(num); 
	printf("�������˶�Աѧ��:");
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
	printf("�ҵ��ˣ�ȷ��ɾ����(1/0)");
	scanf("%d",&ch);
	if(ch==1)/*�ж��Ƿ�Ҫ����ɾ��*/
	{
		for(j=i;j<m;j++)
			stu[j]=stu[j+1];/*����һ����¼�Ƶ�ǰһ����¼��λ��*/
		m--;/*��¼���ܸ�����1*/
		printf("delete successfully!\n");
	}
	saveMessage(m,num);
	printf("�����������...");
	getch();
	return;
				
}

void modStudent()/*�Զ���ɾ������*/
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
	printf("������Ҫ�޸ĵ��˶�Ա��Ŀ��ţ�");
	scanf("%d",&num);
	m=getMessage(num);
	for(a=0;a<m1;a++){
		if(num==pro[a].num){
			break;
		}
	}
	system("cls");
	showStudent(num); 
	printf("�������˶�Աѧ��:");
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
	printf("�����޸���һ������?(1.���� 2.�Ա� 3.ѧԺ 4.ѧ�� 5.�ɼ� )");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			printf("����:");
			scanf("%s",&stu[i].name);/*����ѧ������*/
			break;
		case 2:
			printf("�Ա�:");
			scanf("%s",&stu[i].sex);/*����ѧ��sex*/
			break;
		case 3:
			showCollege();
			printf("ѧԺ���:");
			scanf("%d",&stu[i].college_num);/*����ѧ������ѧԺ*/
			break;
		case 4:
			printf("ѧ��:");
			scanf("%d",&stu[i].num);/*����ѧ������ѧԺ*/
			break;
		case 5:
			switch(pro[a].unit)
				{
					case 1:
							printf("�ɼ����� �� ���룩��");
							scanf("%d%d%d",&min,&sec,&mm);
							stu[i].pro_grade=60*min+sec+(mm/100.0);
						break;
					case 2:
							printf("�ɼ����ף���");
							scanf("%lf",&stu[i].pro_grade);
							printf("%f",stu[i].pro_grade);
						break;
					default:break;
				}
			break;
			default:break;
	}
	saveMessage(m,num);
	printf("�����������...");
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
	printf("ѧ��         ����         �Ա�          ѧԺ          �ɼ�\n");
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
					printf("%-12d%-15s%-12s%-14s%d��%.2lf��\n",stu[i].num,stu[i].name,stu[i].sex,col[j].name,s,h);
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
					printf("%-12d%-15s%-12s%-14s%.2lf��\n",stu[i].num,stu[i].name,stu[i].sex,col[j].name,stu[i].pro_grade);
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
	printf("����      ѧ��       ����       �Ա�        ѧԺ         �ɼ�         ����\n");
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
					printf("NO.%-8d%-10d%-12s%-10s%-12s%d��%.2lf��\t%d\n",i+1,stu[i].num,stu[i].name,stu[i].sex,col[j].name,s,h,stu[i].score);
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
					printf("NO.%-8d%-10d%-12s%-10s%-12s%.2lf��\t\t%d\n",i+1,stu[i].num,stu[i].name,stu[i].sex,col[j].name,stu[i].pro_grade,stu[i].score);
					break;
				}
			}
		}
		return;
	}
	return;
}
/****************************�˶�Ա��Ϣ�������****************************/

/****************************��������****************************/
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
			if(pro[i].unit==1) t=1;else t=2;//�жϵ�λ
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

	if(t==1){//��С��������
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
	else{//�Ӵ�С����
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
		printf("�����������...");
		getch();
		return;
	}
	for(int i=0;i<m1;i++)/*�����޸ĵ���Ϣд��ָ���Ĵ����ļ���*/
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
			printf(COLFORMAT,COLDATA);/*����Ϣ��ָ����ʽ��ӡ*/
		}
	}
	return;
}

/****************************�����������****************************/


/****************************������****************************/
int main()
{
	int n; //ѡ��˵���� 
	menu();
	scanf("%d",&n);
	while(n!=0)
	{
		switch(n)
		{
			case 1:   
				showProject();//������Ŀ���� 
				getch();
				break;
			case 2:
				messageMenu();//������Ϣ��ѯ 
				break;
			case 3:
				getorder();//����� 
				break;
			case 4:
				adminMenu();//����Ա��¼ 
				break;
			default:break;
		}
		menu();
		scanf("%d",&n);
	}
 	printf("��������˳�...");
	getch();
	return 0;
} 
/****************************������****************************/

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
	
	filepro=fopen("projectdata","ab+");  //��һ����Ҫ�ǰѶ������浽����pro 
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
	
	
	
	printf("\t\t\t\t\t\t\t�˶��������\n");
	printf("\t�˶���Ŀ\t\t\t�˶�����\t\t�˶�ʱ��\n\n\n");
	
	day=1; 	
	time=8;
	for(int j=0;a2[j].time!=0;j++)
	{
		if (time==8){
			printf("%45s%d%s\n\n","��",day,"��");
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
			printf("%45s%d%s\n\n","��",day,"��");
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
			printf("%45s%d%s\n\n","��",day,"��");
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
			printf("%45s%d%s\n\n","��",day,"��");
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
			printf("%45s%d%s\n\n","��",day,"��");
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
			printf("%45s%d%s\n\n","��",day,"��");
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
			printf("%45s%d%s\n\n","��",day,"��");
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
			printf("%45s%d%s\n\n","��",day,"��");
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
			printf("%45s%d%s\n\n","��",day,"��");
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
			printf("%45s%d%s\n\n","��",day,"��");
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
