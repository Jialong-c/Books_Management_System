#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>   

typedef struct link
{
    char number[100];//编号 
    char bookname[100];//书名 
    char author[100];//作者 
    char publish[100];//出版社 
    char time[100];//出版时间 
    float price;//价格 
    char status[100];//在库状态  
    struct link* next;
}link;

//函数声明  
link* Cbook();
void mainmenu();
void menu1();
void glmenu();
void cxmenu();
void jhmenu();
void print(link* head);
void  hold(link* head);
void holdcx(link* t);
link* findnumber(link* head);
link* findboookname(link* head);
link* findauthor(link* head);
link* add(link* head);
link* sortnumber(link* head);
link* delbook(link* head);
link* revamp(link* head);
link* borrowbook(link* head);
link* returnbook(link* head);

//主函数  
int main()
{
    int a, b, c, d, e;
    link* h = NULL, * t = NULL;

    L:system("cls");//L为一个标志位，用于从子函数返回主界面  
    mainmenu();
    while (1)//主程序循环运行 
    {
        scanf("%d", &a);
        switch (a)
        {
            case 1://进入主系统
            {
                B: system("cls");//B为一个标志位，用于从子函数返回主功能界面     
                menu1();
                h=Cbook();
                printf("\n请选择");
                while (1)
                {
                    scanf("%d", &b);
                    if (b == 0)
                        goto O;
                    switch (b)
                    {
                        case 1://进入图书管理的子系统      
                        {
                            system("cls");
                            glmenu();
                            while (1)
                            {
                                scanf("%d", &c);
                                if (c == 0)
                                    goto O;
                                switch (c)
                                {
                                    case 1://显示所有图书信息      
                                    {
                                        print(h);
                                        printf("请问您需要借阅图书吗？Y/N:\n");
                                        char ch;
                                        scanf("%c", &ch);
                                        if (ch == 'Y' || ch == 'y')
                                        {
                                            borrowbook(h);
                                            hold(h);
                                        }
                                        if (ch == 'N' || ch == 'n')
                                        {
                                            printf("请选择其他操作！！！\n");
                                        }
                                    }break;
                                    case 2://添加一本图书信息       
                                    {
                                        h = add(h);
                                        h = sortnumber(h);
                                        print(h);
                                        hold(h);
                                    }break;
                                    case 3://修改一本书的信息       
                                    {
                                        revamp(h);
                                        hold(h);
                                    }break;
                                    case 4://删除一本图书信息         
                                    {
                                        h = delbook(h);
                                        print(h);
                                        hold(h);
                                    }break;
                                    case 5:
                                    {
                                        goto B;
                                    }break;
                                    }
                                }
                            }break;
                        case 2://进入图书查询的子系统     
                        {
                            system("cls");
                            cxmenu();
                            while (1)
                            {
                                scanf("%d", &d);
                                if (d == 0)
                                    goto O;
                                switch (d)
                                {
                                    case 1://显示所有图书信息       
                                    {
                                        print(h);
                                    }break;
                                    case 2://按编号查询图书        
                                    {
                                        t = findnumber(h);
                                        if (t == NULL)
                                            printf("没有您要查询的图书！！！");
                                        if (t != NULL)
                                        {
                                            printf("您要查询的图书为：");
                                            printf("\n");
                                            printf("\n**************************************************\n");
                                            printf("%-5s\t%-20s\t%-20s\t%-20s\t%-15s\t%-10s\t%-10s", "编号", "书名", "作者", "出版社", "出版时间", "价格", "状态");
                                            printf("\n");
                                            printf("%-5s\t%-20s\t%-20s\t%-20s\t%-15s\t%-10.2f\t%-10s", t->number, t->bookname, t->author, t->publish, t->time,t->price,t->status);
                                            printf("\n");
                                        }
                                    }break;
                                    case 3://按书名查询图书        
                                    {
                                        t = findboookname(h);
                                        if (t == NULL)
                                            printf("没有您要查询的图书！！！");
                                        if (t != NULL)
                                        {
                                            printf("您要查询的图书为：");
                                            printf("\n");
                                            printf("\n**************************************************\n");
                                            printf("%-5s\t%-20s\t%-20s\t%-20s\t%-15s\t%-10s\t%-10s", "编号", "书名", "作者", "出版社", "出版时间", "价格", "状态");
                                            printf("\n");
                                            printf("%-5s\t%-20s\t%-20s\t%-20s\t%-15s\t%-10.f2\t%-10s", t->number, t->bookname, t->author, t->publish, t->time,t->price,t->status);
                                            printf("\n");
                                        }
                                    }break;
                                    case 4://按作者查询图书         
                                    {
                                        t = findauthor(h);
                                        if (t == NULL)
                                            printf("没有您要查询的图书！！！");
                                        if (t != NULL)
                                        {
                                            printf("您要查询的图书为：");
                                            printf("\n");
                                            printf("\n**************************************************\n");
                                            printf("%-5s\t%-20s\t%-20s\t%-20s\t%-15s\t%-10s\t%-10s", "编号", "书名", "作者", "出版社", "出版时间", "价格", "状态");
                                            printf("\n");
                                            printf("%-5s\t%-20s\t%-20s\t%-20s\t%-15s\t%-10.2f\t%-10s", t->number, t->bookname, t->author, t->publish, t->time,t->price,t->status);
                                            printf("\n");
                                        }
                                    }break;
                                    case 5://保存查询信息         
                                    {
                                        holdcx(t);
                                    }break;
                                    case 6://返回上级菜单         
                                    {
                                        goto B;
                                    }break;
                                }
                            }
                        }break;
                        case 3://图书借还系统   
                        {
                            system("cls");
                            jhmenu();
                            while (1)
                            {
                                scanf("%d", &e);
                                if (e == 0)
                                    goto O;
                                switch (e)
                                {
                                    case 1://借书    
                                    {
                                        print(h);
                                        borrowbook(h);
                                        hold(h);
                                    }break;
                                    case 2://还书  
                                    {
                                        returnbook(h);
                                        hold(h);
                                    }break;
                                    case 3://返回上级菜单    
                                    {
                                        goto B;
                                    }break;
                                }
                            }
                        }break;
                        case 4://显示主功能菜单      
                        {
                            system("cls");
                            menu1();
                        }break;
                        case 5://返回系统主界面      
                        {
                            goto L;
                        }break;
                    }
                }
            }break;
            case 0://退出系统  
            {
                O: system("cls");//O为一个标志位，用于从子函数中直接结束程序  
                printf("\t\t\t感谢使用，再见！！！");
                exit(0);
            }
        }
    }
}

//链表的创建和信息的录入  
link* Cbook()
{
    int n = 0;
    link* p, * q, * head = NULL;
    FILE* fp;
    fp = fopen("图书信息.txt", "r+");
    if (fp == NULL)
        printf("没有找到文件，请检查……");
    p = (link*)malloc(sizeof(link));
    if (p == NULL)
        printf("申请内存出错！！！\n");
    fscanf(fp, "%s%s%s%s%s", p->number, p->bookname, p->author, p->publish, p->time);
    fscanf(fp, "%f", &p->price);
    fscanf(fp, "%s", p->status);
    while (feof(fp) == 0)//文件结束返回非零值，否则返回零值
    {
        n++;
        if (n == 1)
            head = p;
        else {
            q = p;
            p = (link*)malloc(sizeof(link));
            if (p == NULL)
                printf("申请内存出错！！！\n");
            fscanf(fp, "%s%s%s%s%s", p->number, p->bookname, p->author, p->publish, p->time);
            fscanf(fp, "%f", &p->price);
            fscanf(fp, "%s", p->status);
            q->next = p;
        }
    }
    p->next = NULL;
    fclose(fp);
    printf("信息已录入！！！");
    return head;
}

//系统主界面  
void mainmenu() {
    printf("\t18010100284\t王嘉龙\t图书管理系统");
    printf("\n**************************************************\n");
    printf("\n**            欢迎使用图书管理系统              **\n");
    printf("\n**           1.进入系统");
    printf("\t0.退出系统              **\n");
    printf("\n**************************************************\n"); printf("\n   请选择");
}

//功能菜单  
void menu1() {
    printf("\t18010100284\t王嘉龙\t图书管理系统");
    printf("\n**************************************************\n");
    printf("\n**             1.进入图书管理系统               **\n");
    printf("\n**             2.进入图书查询系统               **\n");
    printf("\n**             3.进入图书借还系统               **\n");
    printf("\n**             4.显示菜单                       **\n");
    printf("\n**             5.返回上级菜单                   **\n");
    printf("\n**************************************************\n");
}

//管理系统菜单  
void glmenu() {
    printf("\t18010100284\t王嘉龙\t图书管理系统");
    printf("\n**************************************************\n");
    printf("\n**             1.显示所有图书信息               **\n");
    printf("\n**             2.添加一本图书信息               **\n");
    printf("\n**             3.修改一本图书信息               **\n");
    printf("\n**             4.删除一本图书信息               **\n");
    printf("\n**             5.返回上级菜单                   **\n");
    printf("\n**************************************************\n");
    printf("\n请选择");
}

//查询系统菜单  
void cxmenu() {
    printf("\t18010100284\t王嘉龙\t图书管理系统");
    printf("\n**************************************************\n");
    printf("\n**             1.显示所有图书信息               **\n");
    printf("\n**             2.按编号查询图书                 **\n");
    printf("\n**             3.按书名查询图书                 **\n");
    printf("\n**             4.按作者查询图书                 **\n");
    printf("\n**             5.保存所查询图书的信息           **\n");
    printf("\n**             6.返回上级菜单                   **\n");
    printf("\n**************************************************\n");
    printf("\n请选择");
}

//借还系统菜单 
void jhmenu() {
    printf("\t18010100284\t王嘉龙\t图书管理系统");
    printf("\n**************************************************\n");
    printf("\n**             1.借书                           **\n");
    printf("\n**             2.还书                           **\n");
    printf("\n**             3.返回上级菜单                   **\n");
    printf("\n**************************************************\n");
    printf("\n请选择");
}

//输出链表函数  
void print(link* head)
{
    link* p;  p = head;
    if (p == NULL)
        printf("文件中没有图书信息\n");
    else
    {
        printf("\n");
        printf("\n**************************************************\n");
        printf("%-5s\t%-20s\t%-20s\t%-20s\t%-15s\t%-10s\t%-10s\n", "编号", "书名", "作者", "出版社", "出版时间", "价格", "状态");
        while (p != NULL&&p->next!=NULL)
        {
            printf("\n");
            printf("%-5s\t%-20s\t%-20s\t%-20s\t%-15s\t%-10.2f\t%-10s", p->number, p->bookname, p->author, p->publish, p->time,p->price,p->status);
            printf("\n");
            p = p->next;
        }
    }
}

//保存信息到文件子函数 
void  hold(link* head) {
    link* p;
    FILE* fp;
    fp = fopen("图书信息.txt", "w+");
    if (fp == NULL) {
        printf("文件操作出错！！！");
        exit(1);
    }
    p = head;
    for (; p != NULL&&p->next!=NULL; p = p->next) {
        fprintf(fp, "\n");
        fprintf(fp, "%-5s\t%-20s\t%-20s\t%-20s\t%-15s\t%-10.2f\t%-10s", p->number, p->bookname, p->author, p->publish, p->time,p->price,p->status);
    }
    fclose(fp);
    printf("信息已保存。");
}

//子函数保存查询的信息到文件  
void holdcx(link* t)
{
    link* p = NULL;
    FILE* fp;
    fp = fopen("查询.txt", "a+");
    p = t;
    fprintf(fp, "查询到的信息为：\n");
    fprintf(fp, "\n");
    fprintf(fp, "\n**************************************************\n");
    fprintf(fp, "%-5s\t%-20s\t%-20s\t%-20s\t%-15s\t%-10s\t%-10s\n", "编号", "书名", "作者", "出版社", "出版时间", "价格", "状态");
    fprintf(fp, "\n");
    fprintf(fp, "%-5s\t%-20s\t%-20s\t%-20s\t%-15s\t%-10.2f\t%-10s", p->number, p->bookname, p->author, p->publish, p->time,p->price,p->status);
    fprintf(fp, "\n");
    fclose(fp);
    printf("信息已保存!!!");
}

//子函数按编号查询 
link* findnumber(link* head) {
    char key[100]; link* h, * t1 = NULL;
    printf("请输入图书的编号：");
    getchar();
    gets_s(key);
    for (h = head; h != NULL; h = h->next) {
        if (strcmp(key, h->number) == 0)
        {
            t1 = h;
            break;
        }
    }
    return t1;
}

//子函数按书名查询 
link* findboookname(link* head) {
    char key[100];
    link* h, * t2 = NULL;
    printf("请输入图书的书名：");
    getchar();
    gets_s(key);
    for (h = head; h != NULL; h = h->next) {
        if (strcmp(key, h->bookname) == 0)
        {
            t2 = h;
            break;
        }
    }
    return  t2;
}

//子函数按作者查询 
link* findauthor(link* head) {
    char key[100];
    link* h, * t3 = NULL;
    printf("请输入作者姓名：");
    getchar();
    gets_s(key);
    for (h = head; h != NULL; h = h->next) {
        if (strcmp(key, h->author) == 0)
        {
            t3 = h;
            break;
        }
    }
    return  t3;
}

//添加一本图书信息  
link* add(link* head)
{
    link* h, * h1;
    h1 = head;
    h = (link*)malloc(sizeof(link));
    if (h == NULL)
    {
        printf("申请内存出错！！！");
        exit(1);
    }
    printf("请输入添加图书的信息");
    printf("\n");
    printf("\n**************************************************\n");
    printf("%-5s\t%-20s\t%-20s\t%-20s%-15s\t%-10s\t%-10s\n", "编号", "书名", "作者", "出版社", "出版时间", "价格", "状态");
    scanf("%s%s%s%s%s", h->number, h->bookname, h->author, h->publish, h->time);
    scanf("%f", &h->price);
    scanf("%s", h->status);
    h->next = h1;
    return h;
}

//将链表按编号排序 
link* sortnumber(link* head) {
    link* p, * q, * temp;
    temp = (link*)malloc(sizeof(link));
    if (temp == NULL) {
        printf("申请内存出错！！！");
        exit(1);
    }
    for (p = head; p != NULL; p = p->next) {
        for (q = p->next; q != NULL; q = q->next)
        {
            if (strcmp(p->number, q->number) > 0)
            {
                strcpy(temp->number, p->number);
                strcpy(temp->bookname, p->bookname);
                strcpy(temp->author, p->author);
                strcpy(temp->publish, p->publish);
                strcpy(temp->time, p->time);
                temp->price = p->price;
                strcpy(temp->status, p->status);
                strcpy(p->number, q->number);
                strcpy(p->bookname, q->bookname);
                strcpy(p->author, q->author);
                strcpy(p->publish, q->publish);
                strcpy(p->time, q->time);
                p->price = q->price;
                strcpy(p->status, temp->status);
                strcpy(q->number, temp->number);
                strcpy(q->bookname, temp->bookname);
                strcpy(q->author, temp->author);
                strcpy(q->publish, temp->publish);
                strcpy(q->time, temp->time);
                q->price = temp->price;
                strcpy(q->status, temp->status);
            }
        }
    }
    return head;
}

//删除一本图书信息  
link* delbook(link* head) {
    int k = 0; char str[100];
    link* h, * t, * p;
    h = t = p = head;
    printf("请输入要删除图书的书名:");
    getchar();
    gets_s(str);
    for (; p != NULL; p = p->next) {
        k++;
        if (k > 2)
            t = t->next;
        if ((strcmp(p->bookname, str) == 0) && (k == 1))
            h = p->next;
        else if (strcmp(p->bookname, str) == 0 && k > 1)
            t->next = p->next;
        else  if (strcmp(p->bookname, str) == 0 && p->next == NULL)
            t = NULL;
    }
    return h;
}

//修改一本书信息（除书名外）  
link* revamp(link* head)
{
    link* h, * t;  h = head;
    t = findboookname(h);
    if (t == NULL)
        printf("没有找到……");
    else {
        printf("修改前图书信息为：");
        printf("\n");
        printf("\n**************************************************\n");
        printf("%-5s\t%-20s\t%-20s\t%-20s%-15s\t%-10s\t%-10s\n", "编号", "书名", "作者", "出版社", "出版时间", "价格", "状态");
        printf("\n");
        printf("%-5s\t%-20s\t%-20s\t%-20s\t%-15s\t%-10.2f\t%-10s", t->number, t->bookname, t->author, t->publish, t->time,t->price,t->status);
        printf("\n");
    }
    printf("请输入这本书的（除书名外）所有信息：\n");
    printf("\n**************************************************\n");
    printf("%-5s\t%-20s\t%-20s\t%-20s%-15s\t%-10s\t%-10s\n", "编号", "书名", "作者", "出版社", "出版时间", "价格", "状态");
    printf("\n");
    scanf("%s%s%s%s", t->number, t->author, t->publish, t->time);
    scanf("%f", &t->price);
    scanf("%s", t->status);
    printf("修改后图书信息为：");
    printf("\n");
    printf("\n**************************************************\n");
    printf("%-5s\t%-20\t%-20s\t%-20s%-15s\t%-10s\t%-10s\n", "编号", "书名", "作者", "出版社", "出版时间", "价格", "状态");
    printf("\n");
    printf("%-5s\t%-20s\t%-20s\t%-20s\t%-15s\t%-10.2f\t%-10s", t->number, t->bookname, t->author, t->publish, t->time,t->price,t->status);
    printf("\n");
    return head;
}

//借书
link* borrowbook(link* head) {
    link* h, * p;
    char ch, ch1[100] = "在库", ch2[100] = "不在库";
    h = head;
    printf("\n**************************************************\n");
    printf("\t\t欢迎使用借书系统!!!\n");
    p = findboookname(h);
    if (p == NULL)
        printf("借书失败，书库中没有这本书！！！");
    else if (strcmp(p->status, ch2) == 0)
        printf("借书失败，图书不在库！！！");
    else {
        printf("确认借出？Y/N:");
        scanf("%c", &ch);
        getchar();
        if (ch == 'Y' || ch == 'y')
        {
            strcpy(p->status, ch2);
            printf("借书成功！！！\n");
        }
        if (ch == 'N' || ch == 'n')
        {
            printf("借书失败！！！\n");
        }
    }
    return head;
}

//还书 
link* returnbook(link* head) {
    link* h, * p;
    char ch, ch1[100] = "在库", ch2[100] = "不在库";
    h = head;
    printf("\n**************************************************\n");
    printf("\t\t欢迎使用还书系统!!!\n");
    p = findboookname(h);
    if (p == NULL)
        printf("还书失败，这不是本书库的书！！");
    else {
        printf("确认还书？Y/N:");
        scanf("%c", &ch);
        getchar();
        if (ch == 'Y' || ch == 'y')
        {
            strcpy(p->status, ch1);
            printf("还书成功！！！\n");
        }
        if (ch == 'N' || ch == 'n')
            printf("还书失败！！！\n");
    }
    return head;
}
