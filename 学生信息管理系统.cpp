#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define LEN sizeof(struct Student)



//定义学生结构体
struct Student
{
    long num;
    char name[10];
    float chin;
    float math;
    float en;
    float phy;
	float aver;
	float sum;
    struct Student *next;
};
typedef struct Student Stu;

//定义全局变量
Stu *head = (Stu *)malloc(LEN);
FILE * f;


//主界面菜单
void menu()
{
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t\t|--------------学生信息管理系统-------------|\n");
	printf("\t\t|\t 1.添加学生信息                     |\n");
	printf("\t\t|\t 2.查找学生信息                     |\n");
	printf("\t\t|\t 3.删除学生信息                     |\n");
	printf("\t\t|\t 4.修改学生信息                     |\n");
	printf("\t\t|\t 5.统计平均成绩和总成绩             |\n");
	printf("\t\t|\t 6.保存全部数据到数据文件中         |\n");
	printf("\t\t|\t 7.浏览数据文件中信息               |\n");
	printf("\t\t|\t 8.退相互学生系统                   |\n");
	printf("\t\t|-------------------------------------------|\n\n");
	printf("\t\t\t请选择:");
}

//1添加学生信息
void creat()
{
	int i=1;
	Stu *p = (Stu *)malloc(LEN);
	Stu *p2 = (Stu *)malloc(LEN);
	Stu *temp = (Stu *)malloc(LEN);
	p2=head->next;p=head;
	while(p2->num!=0)
	{
		p=p2;
		p2=p2->next;
	}
	p2=p;
	p=p2->next;
	while(i)
	{
		system("cls");
		//添加学生界面
		printf("\t\t|-------------------------------------------|\n");
		printf("\t\t|             添加学生信息                  |\n");
		printf("\t\t|-------------------------------------------|\n");
		printf("请输入第%d个学生的信息(输入0，退出并返回主界面):\n",i);

		//学号
		printf("学号：");
		scanf("%ld",&p->num);
		if(p->num==0) break;
		printf("\n");

		//姓名
		printf("姓名：");
		scanf("%s",p->name);
		printf("\n");

		//语文
		printf("语文：");
		scanf("%f",&p->chin);
		printf("\n");

		//数学
		printf("数学：");
		scanf("%f",&p->math);
		printf("\n");

		//英语
		printf("英语：");
		scanf("%f",&p->en);
		printf("\n");

		//物理
		printf("物理：");
		scanf("%f",&p->phy);
		printf("\n");

		//背后操作
		//平均值与总值的赋假值
		p->sum=-1;
		p->aver=-1;
		i++;
		temp=p;
		p=(Stu *)malloc(LEN);
		temp->next=p;

	}
}

//2.1全部浏览
void watch()
{
	Stu * p = (Stu *)malloc(LEN);
	if(head->next==NULL)
	{
		printf("无学生信息，请先添加学生信息！按任意键返回：");
		_getch();
	}
	else
	{
		p=head->next;
		printf("\t\t学号\t姓名\t语文\t数学\t英语\t物理\t平均\t总成绩\n");
		while(p->num!=0)
		{
			if(p->aver==-1)
			{
				printf("\t\t%ld\t%s\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t\n",
					p->num,p->name,p->chin,p->math,p->en,p->phy);
				p=p->next;
			}else
			{
				printf("\t\t%ld\t%s\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t%3.1f\n",
					p->num,p->name,p->chin,p->math,p->en,p->phy,p->aver,p->sum);
				p=p->next;
			}
		}
		printf("按任意键返回上级。。。");
		_getch();
	}
}

//2.2按学号查找
void num()
{
	//
	long num;
	printf("请输入查询学号：");
	scanf("%ld",&num);
	Stu * p=head->next;
	printf("\t\t学号\t姓名\t语文\t数学\t英语\t物理\t平均\t总成绩\n");
	while(p->num!=0)
	{
		if(p->num==num)
		{
			if(p->aver==-1) printf("\t\t%ld\t%s\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t\n",
					p->num,p->name,p->chin,p->math,p->en,p->phy);
			else printf("\t\t%ld\t%s\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t%3.1f\n",
					p->num,p->name,p->chin,p->math,p->en,p->phy,p->aver,p->sum);
		}
		p=p->next;
	}
	printf("按任意键返回上级。。。");
	_getch();
}

//2.3按姓名查找
void name()
{
	char name[10];
	printf("请输入所查姓名：");
	scanf("%s",name);
	Stu * p = head->next;
	printf("\t\t学号\t姓名\t语文\t数学\t英语\t物理\t平均\t总成绩\n");
	while(p->num!=0)
	{
		if(!strcmp(p->name,name))
		{
			if(p->aver==-1) printf("\t\t%ld\t%s\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t\n",
					p->num,p->name,p->chin,p->math,p->en,p->phy);
			else printf("\t\t%ld\t%s\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t%3.1f",
					p->num,p->name,p->chin,p->math,p->en,p->phy,p->aver,p->sum);
		}
		p=p->next;
	}
	printf("按任意键返回上级。。。");
	_getch();
}


//2查找学生信息
void search()
{
	int i=0;
	while(i!=4)
	{
		system("cls");
		//查找学生界面
		printf("\t\t|-------------------------------------------|\n");
		printf("\t\t|             查找学生信息                  |\n");
		printf("\t\t|-------------------------------------------|\n");
		printf("1.全部浏览\n");
		printf("2.按学号查找\n");
		printf("3.按姓名查找\n");
		printf("4.返回主菜单\n\n");
		printf("请选择：");
		scanf("%d",&i);
		switch(i)
		{
		case 1:watch();break;
		case 2:num();break;
		case 3:name();break;
		case 4:break;
		default:printf("错误！请输入1~4（按任意键返回）：");search();break;
		}
	}

}

//3删除学生信息
void del()
{
	system("cls");
	//删除学生界面
	printf("\t\t|-------------------------------------------|\n");
	printf("\t\t|             删除学生信息                  |\n");
	printf("\t\t|-------------------------------------------|\n\n");
	printf("\t\t请输入要删除学生信息的学生学号：\n");
	long num;
	scanf("%ld",&num);
	Stu * p2;
	Stu * p = head->next;
	p2=head;
	printf("\t\t学号\t姓名\t语文\t数学\t英语\t物理\n");
	while(1)
	{
		if(p->num==num)
		{
            printf("\t\t%ld\t%s\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t\n",
                p->num,p->name,p->chin,p->math,p->en,p->phy);
			break;
		}
        p2=p;
        p=p->next;
	}
	char a;
	scanf("%c",&a);
	printf("请确定是否删除该学生学生信息：");
	scanf("%c",&a);
	switch(a)
	{
	case 'y': p2->next = p->next;
		printf("该生信息已删除\n");_getch();
		break;
	default: printf("删除操作已取消\n");
		break;
	}
}

//4修改学生信息
void modify()
{
	system("cls");
	long num;
	//修改学生界面
	printf("\t\t|-------------------------------------------|\n");
	printf("\t\t|             修改学生信息                  |\n");
	printf("\t\t|-------------------------------------------|\n");
	printf("\t\t请输入要修改学生信息的学生学号：");
	scanf("%ld",&num);
	Stu * p = head->next;
	Stu * p2;
	printf("查找到的信息：\n\n");
    printf("\t\t学号\t姓名\t语文\t数学\t英语\t物理\n");
	while(1)
	{
		if(p->num==num)
		{
			printf("\t\t%ld\t%s\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t\n",
				p->num,p->name,p->chin,p->math,p->en,p->phy);
		}
		p2=p;
		p=p->next;
		break;
		if(p->num == 0) printf("查无此人");
		break;
	}
	printf("\t\t\t1.语文成绩\n");
	printf("\t\t\t2.数学成绩\n");
	printf("\t\t\t3.英语成绩\n");
	printf("\t\t\t4.物理成绩\n");
	printf("\t\t\t5.返回主菜单\n\n");
	printf("请选择：");
	int i;
	scanf("%d",&i);
	switch(i)
	{
	case 1:printf("语文");scanf("%f",&p2->chin);break;
	case 2:printf("数学");scanf("%f",&p2->math);break;
	case 3:printf("英语");scanf("%f",&p2->en);break;
	case 4:printf("物理");scanf("%f",&p2->phy);break;
	case 5:break;
	}

}


//5统计平均成绩和总成绩
void total()
{
    //
    Stu * p=head->next;
    system("cls");
	printf("\t\t学号\t姓名\t语文\t数学\t英语\t物理\t平均\t总成绩\n");
    while(p->num!=0)
    {
        p->aver = (p->chin+p->math+p->en+p->phy)/4;
        p->sum = p->chin+p->math+p->en+p->phy;
        printf("\t\t%ld\t%s\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t%3.1f\n",
            p->num,p->name,p->chin,p->math,p->en,p->phy,p->aver,p->sum);
        p=p->next;
    }
	printf("按任意键返回主菜单。。。");
	_getch();
}

//6保存全部数据到数据文件中
void save()
{
    Stu * p = head->next;
    f=fopen("file.txt","w");
    while(p->num!=0)
    {
        fprintf(f,"%ld %s %3.1f %3.1f %3.1f %3.1f %3.1f %3.1f ",
					p->num,p->name,p->chin,p->math,p->en,p->phy,p->aver,p->sum);
        p=p->next;
    }
    fclose(f);
	printf("按任意键返回主菜单。。。");
	_getch();
}

//7浏览数据文件中信息
Stu * look()
{
    Stu * p = (Stu *)malloc(LEN);
    Stu * z=p;
    f=fopen("file.txt","r");
    system("cls");
	printf("\t\t学号\t姓名\t语文\t数学\t英语\t物理\t平均\t总成绩\n");
    while(!feof(f))
    {
        fscanf(f,"%ld %s %f %f %f %f %f %f ",
               &p->num,&p->name,&p->chin,&p->math,&p->en,&p->phy,&p->aver,&p->sum);
        printf("\t\t%ld\t%s\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t%3.1f\n",
            p->num,p->name,p->chin,p->math,p->en,p->phy,p->aver,p->sum);
        p= p->next = (Stu *)malloc(LEN);
    }
    fclose(f);
	printf("按任意键返回主菜单。。。");
	_getch();
	p->num=0;
    Stu * a = (Stu *)malloc(LEN);
    a->next = z;
    return a;
}

//9主函数
int main()
{
    int n;Stu *p=(Stu *)malloc(LEN);p->num=0;
	head->next=p;
	menu();
	scanf("%d",&n);
    while(n)
	{
		switch(n)
		{
			case 1:creat();break;
			case 2:search();break;
			case 3:del();break;
			case 4:modify();break;
			case 5:total();break;
			case 6:save();break;
			case 7:head = look();break;
			case 8:return 0;
			default:printf("错误！按任意键返回，请输入1~8：");_getch();break;
		}
		menu();
		scanf("%d",&n);

	}
	return 0;
}
