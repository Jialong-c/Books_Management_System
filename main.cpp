#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>   

typedef struct link
{
    char number[100];//��� 
    char bookname[100];//���� 
    char author[100];//���� 
    char publish[100];//������ 
    char time[100];//����ʱ�� 
    float price;//�۸� 
    char status[100];//�ڿ�״̬  
    struct link* next;
}link;

//��������  
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

//������  
int main()
{
    int a, b, c, d, e;
    link* h = NULL, * t = NULL;

    L:system("cls");//LΪһ����־λ�����ڴ��Ӻ�������������  
    mainmenu();
    while (1)//������ѭ������ 
    {
        scanf("%d", &a);
        switch (a)
        {
            case 1://������ϵͳ
            {
                B: system("cls");//BΪһ����־λ�����ڴ��Ӻ������������ܽ���     
                menu1();
                h=Cbook();
                printf("\n��ѡ��");
                while (1)
                {
                    scanf("%d", &b);
                    if (b == 0)
                        goto O;
                    switch (b)
                    {
                        case 1://����ͼ��������ϵͳ      
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
                                    case 1://��ʾ����ͼ����Ϣ      
                                    {
                                        print(h);
                                        printf("��������Ҫ����ͼ����Y/N:\n");
                                        char ch;
                                        scanf("%c", &ch);
                                        if (ch == 'Y' || ch == 'y')
                                        {
                                            borrowbook(h);
                                            hold(h);
                                        }
                                        if (ch == 'N' || ch == 'n')
                                        {
                                            printf("��ѡ����������������\n");
                                        }
                                    }break;
                                    case 2://���һ��ͼ����Ϣ       
                                    {
                                        h = add(h);
                                        h = sortnumber(h);
                                        print(h);
                                        hold(h);
                                    }break;
                                    case 3://�޸�һ�������Ϣ       
                                    {
                                        revamp(h);
                                        hold(h);
                                    }break;
                                    case 4://ɾ��һ��ͼ����Ϣ         
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
                        case 2://����ͼ���ѯ����ϵͳ     
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
                                    case 1://��ʾ����ͼ����Ϣ       
                                    {
                                        print(h);
                                    }break;
                                    case 2://����Ų�ѯͼ��        
                                    {
                                        t = findnumber(h);
                                        if (t == NULL)
                                            printf("û����Ҫ��ѯ��ͼ�飡����");
                                        if (t != NULL)
                                        {
                                            printf("��Ҫ��ѯ��ͼ��Ϊ��");
                                            printf("\n");
                                            printf("\n**************************************************\n");
                                            printf("%-5s\t%-20s\t%-20s\t%-20s\t%-15s\t%-10s\t%-10s", "���", "����", "����", "������", "����ʱ��", "�۸�", "״̬");
                                            printf("\n");
                                            printf("%-5s\t%-20s\t%-20s\t%-20s\t%-15s\t%-10.2f\t%-10s", t->number, t->bookname, t->author, t->publish, t->time,t->price,t->status);
                                            printf("\n");
                                        }
                                    }break;
                                    case 3://��������ѯͼ��        
                                    {
                                        t = findboookname(h);
                                        if (t == NULL)
                                            printf("û����Ҫ��ѯ��ͼ�飡����");
                                        if (t != NULL)
                                        {
                                            printf("��Ҫ��ѯ��ͼ��Ϊ��");
                                            printf("\n");
                                            printf("\n**************************************************\n");
                                            printf("%-5s\t%-20s\t%-20s\t%-20s\t%-15s\t%-10s\t%-10s", "���", "����", "����", "������", "����ʱ��", "�۸�", "״̬");
                                            printf("\n");
                                            printf("%-5s\t%-20s\t%-20s\t%-20s\t%-15s\t%-10.f2\t%-10s", t->number, t->bookname, t->author, t->publish, t->time,t->price,t->status);
                                            printf("\n");
                                        }
                                    }break;
                                    case 4://�����߲�ѯͼ��         
                                    {
                                        t = findauthor(h);
                                        if (t == NULL)
                                            printf("û����Ҫ��ѯ��ͼ�飡����");
                                        if (t != NULL)
                                        {
                                            printf("��Ҫ��ѯ��ͼ��Ϊ��");
                                            printf("\n");
                                            printf("\n**************************************************\n");
                                            printf("%-5s\t%-20s\t%-20s\t%-20s\t%-15s\t%-10s\t%-10s", "���", "����", "����", "������", "����ʱ��", "�۸�", "״̬");
                                            printf("\n");
                                            printf("%-5s\t%-20s\t%-20s\t%-20s\t%-15s\t%-10.2f\t%-10s", t->number, t->bookname, t->author, t->publish, t->time,t->price,t->status);
                                            printf("\n");
                                        }
                                    }break;
                                    case 5://�����ѯ��Ϣ         
                                    {
                                        holdcx(t);
                                    }break;
                                    case 6://�����ϼ��˵�         
                                    {
                                        goto B;
                                    }break;
                                }
                            }
                        }break;
                        case 3://ͼ��軹ϵͳ   
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
                                    case 1://����    
                                    {
                                        print(h);
                                        borrowbook(h);
                                        hold(h);
                                    }break;
                                    case 2://����  
                                    {
                                        returnbook(h);
                                        hold(h);
                                    }break;
                                    case 3://�����ϼ��˵�    
                                    {
                                        goto B;
                                    }break;
                                }
                            }
                        }break;
                        case 4://��ʾ�����ܲ˵�      
                        {
                            system("cls");
                            menu1();
                        }break;
                        case 5://����ϵͳ������      
                        {
                            goto L;
                        }break;
                    }
                }
            }break;
            case 0://�˳�ϵͳ  
            {
                O: system("cls");//OΪһ����־λ�����ڴ��Ӻ�����ֱ�ӽ�������  
                printf("\t\t\t��лʹ�ã��ټ�������");
                exit(0);
            }
        }
    }
}

//����Ĵ�������Ϣ��¼��  
link* Cbook()
{
    int n = 0;
    link* p, * q, * head = NULL;
    FILE* fp;
    fp = fopen("ͼ����Ϣ.txt", "r+");
    if (fp == NULL)
        printf("û���ҵ��ļ������顭��");
    p = (link*)malloc(sizeof(link));
    if (p == NULL)
        printf("�����ڴ��������\n");
    fscanf(fp, "%s%s%s%s%s", p->number, p->bookname, p->author, p->publish, p->time);
    fscanf(fp, "%f", &p->price);
    fscanf(fp, "%s", p->status);
    while (feof(fp) == 0)//�ļ��������ط���ֵ�����򷵻���ֵ
    {
        n++;
        if (n == 1)
            head = p;
        else {
            q = p;
            p = (link*)malloc(sizeof(link));
            if (p == NULL)
                printf("�����ڴ��������\n");
            fscanf(fp, "%s%s%s%s%s", p->number, p->bookname, p->author, p->publish, p->time);
            fscanf(fp, "%f", &p->price);
            fscanf(fp, "%s", p->status);
            q->next = p;
        }
    }
    p->next = NULL;
    fclose(fp);
    printf("��Ϣ��¼�룡����");
    return head;
}

//ϵͳ������  
void mainmenu() {
    printf("\t18010100284\t������\tͼ�����ϵͳ");
    printf("\n**************************************************\n");
    printf("\n**            ��ӭʹ��ͼ�����ϵͳ              **\n");
    printf("\n**           1.����ϵͳ");
    printf("\t0.�˳�ϵͳ              **\n");
    printf("\n**************************************************\n"); printf("\n   ��ѡ��");
}

//���ܲ˵�  
void menu1() {
    printf("\t18010100284\t������\tͼ�����ϵͳ");
    printf("\n**************************************************\n");
    printf("\n**             1.����ͼ�����ϵͳ               **\n");
    printf("\n**             2.����ͼ���ѯϵͳ               **\n");
    printf("\n**             3.����ͼ��軹ϵͳ               **\n");
    printf("\n**             4.��ʾ�˵�                       **\n");
    printf("\n**             5.�����ϼ��˵�                   **\n");
    printf("\n**************************************************\n");
}

//����ϵͳ�˵�  
void glmenu() {
    printf("\t18010100284\t������\tͼ�����ϵͳ");
    printf("\n**************************************************\n");
    printf("\n**             1.��ʾ����ͼ����Ϣ               **\n");
    printf("\n**             2.���һ��ͼ����Ϣ               **\n");
    printf("\n**             3.�޸�һ��ͼ����Ϣ               **\n");
    printf("\n**             4.ɾ��һ��ͼ����Ϣ               **\n");
    printf("\n**             5.�����ϼ��˵�                   **\n");
    printf("\n**************************************************\n");
    printf("\n��ѡ��");
}

//��ѯϵͳ�˵�  
void cxmenu() {
    printf("\t18010100284\t������\tͼ�����ϵͳ");
    printf("\n**************************************************\n");
    printf("\n**             1.��ʾ����ͼ����Ϣ               **\n");
    printf("\n**             2.����Ų�ѯͼ��                 **\n");
    printf("\n**             3.��������ѯͼ��                 **\n");
    printf("\n**             4.�����߲�ѯͼ��                 **\n");
    printf("\n**             5.��������ѯͼ�����Ϣ           **\n");
    printf("\n**             6.�����ϼ��˵�                   **\n");
    printf("\n**************************************************\n");
    printf("\n��ѡ��");
}

//�軹ϵͳ�˵� 
void jhmenu() {
    printf("\t18010100284\t������\tͼ�����ϵͳ");
    printf("\n**************************************************\n");
    printf("\n**             1.����                           **\n");
    printf("\n**             2.����                           **\n");
    printf("\n**             3.�����ϼ��˵�                   **\n");
    printf("\n**************************************************\n");
    printf("\n��ѡ��");
}

//���������  
void print(link* head)
{
    link* p;  p = head;
    if (p == NULL)
        printf("�ļ���û��ͼ����Ϣ\n");
    else
    {
        printf("\n");
        printf("\n**************************************************\n");
        printf("%-5s\t%-20s\t%-20s\t%-20s\t%-15s\t%-10s\t%-10s\n", "���", "����", "����", "������", "����ʱ��", "�۸�", "״̬");
        while (p != NULL&&p->next!=NULL)
        {
            printf("\n");
            printf("%-5s\t%-20s\t%-20s\t%-20s\t%-15s\t%-10.2f\t%-10s", p->number, p->bookname, p->author, p->publish, p->time,p->price,p->status);
            printf("\n");
            p = p->next;
        }
    }
}

//������Ϣ���ļ��Ӻ��� 
void  hold(link* head) {
    link* p;
    FILE* fp;
    fp = fopen("ͼ����Ϣ.txt", "w+");
    if (fp == NULL) {
        printf("�ļ�������������");
        exit(1);
    }
    p = head;
    for (; p != NULL&&p->next!=NULL; p = p->next) {
        fprintf(fp, "\n");
        fprintf(fp, "%-5s\t%-20s\t%-20s\t%-20s\t%-15s\t%-10.2f\t%-10s", p->number, p->bookname, p->author, p->publish, p->time,p->price,p->status);
    }
    fclose(fp);
    printf("��Ϣ�ѱ��档");
}

//�Ӻ��������ѯ����Ϣ���ļ�  
void holdcx(link* t)
{
    link* p = NULL;
    FILE* fp;
    fp = fopen("��ѯ.txt", "a+");
    p = t;
    fprintf(fp, "��ѯ������ϢΪ��\n");
    fprintf(fp, "\n");
    fprintf(fp, "\n**************************************************\n");
    fprintf(fp, "%-5s\t%-20s\t%-20s\t%-20s\t%-15s\t%-10s\t%-10s\n", "���", "����", "����", "������", "����ʱ��", "�۸�", "״̬");
    fprintf(fp, "\n");
    fprintf(fp, "%-5s\t%-20s\t%-20s\t%-20s\t%-15s\t%-10.2f\t%-10s", p->number, p->bookname, p->author, p->publish, p->time,p->price,p->status);
    fprintf(fp, "\n");
    fclose(fp);
    printf("��Ϣ�ѱ���!!!");
}

//�Ӻ�������Ų�ѯ 
link* findnumber(link* head) {
    char key[100]; link* h, * t1 = NULL;
    printf("������ͼ��ı�ţ�");
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

//�Ӻ�����������ѯ 
link* findboookname(link* head) {
    char key[100];
    link* h, * t2 = NULL;
    printf("������ͼ���������");
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

//�Ӻ��������߲�ѯ 
link* findauthor(link* head) {
    char key[100];
    link* h, * t3 = NULL;
    printf("����������������");
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

//���һ��ͼ����Ϣ  
link* add(link* head)
{
    link* h, * h1;
    h1 = head;
    h = (link*)malloc(sizeof(link));
    if (h == NULL)
    {
        printf("�����ڴ��������");
        exit(1);
    }
    printf("���������ͼ�����Ϣ");
    printf("\n");
    printf("\n**************************************************\n");
    printf("%-5s\t%-20s\t%-20s\t%-20s%-15s\t%-10s\t%-10s\n", "���", "����", "����", "������", "����ʱ��", "�۸�", "״̬");
    scanf("%s%s%s%s%s", h->number, h->bookname, h->author, h->publish, h->time);
    scanf("%f", &h->price);
    scanf("%s", h->status);
    h->next = h1;
    return h;
}

//������������� 
link* sortnumber(link* head) {
    link* p, * q, * temp;
    temp = (link*)malloc(sizeof(link));
    if (temp == NULL) {
        printf("�����ڴ��������");
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

//ɾ��һ��ͼ����Ϣ  
link* delbook(link* head) {
    int k = 0; char str[100];
    link* h, * t, * p;
    h = t = p = head;
    printf("������Ҫɾ��ͼ�������:");
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

//�޸�һ������Ϣ���������⣩  
link* revamp(link* head)
{
    link* h, * t;  h = head;
    t = findboookname(h);
    if (t == NULL)
        printf("û���ҵ�����");
    else {
        printf("�޸�ǰͼ����ϢΪ��");
        printf("\n");
        printf("\n**************************************************\n");
        printf("%-5s\t%-20s\t%-20s\t%-20s%-15s\t%-10s\t%-10s\n", "���", "����", "����", "������", "����ʱ��", "�۸�", "״̬");
        printf("\n");
        printf("%-5s\t%-20s\t%-20s\t%-20s\t%-15s\t%-10.2f\t%-10s", t->number, t->bookname, t->author, t->publish, t->time,t->price,t->status);
        printf("\n");
    }
    printf("�������Ȿ��ģ��������⣩������Ϣ��\n");
    printf("\n**************************************************\n");
    printf("%-5s\t%-20s\t%-20s\t%-20s%-15s\t%-10s\t%-10s\n", "���", "����", "����", "������", "����ʱ��", "�۸�", "״̬");
    printf("\n");
    scanf("%s%s%s%s", t->number, t->author, t->publish, t->time);
    scanf("%f", &t->price);
    scanf("%s", t->status);
    printf("�޸ĺ�ͼ����ϢΪ��");
    printf("\n");
    printf("\n**************************************************\n");
    printf("%-5s\t%-20\t%-20s\t%-20s%-15s\t%-10s\t%-10s\n", "���", "����", "����", "������", "����ʱ��", "�۸�", "״̬");
    printf("\n");
    printf("%-5s\t%-20s\t%-20s\t%-20s\t%-15s\t%-10.2f\t%-10s", t->number, t->bookname, t->author, t->publish, t->time,t->price,t->status);
    printf("\n");
    return head;
}

//����
link* borrowbook(link* head) {
    link* h, * p;
    char ch, ch1[100] = "�ڿ�", ch2[100] = "���ڿ�";
    h = head;
    printf("\n**************************************************\n");
    printf("\t\t��ӭʹ�ý���ϵͳ!!!\n");
    p = findboookname(h);
    if (p == NULL)
        printf("����ʧ�ܣ������û���Ȿ�飡����");
    else if (strcmp(p->status, ch2) == 0)
        printf("����ʧ�ܣ�ͼ�鲻�ڿ⣡����");
    else {
        printf("ȷ�Ͻ����Y/N:");
        scanf("%c", &ch);
        getchar();
        if (ch == 'Y' || ch == 'y')
        {
            strcpy(p->status, ch2);
            printf("����ɹ�������\n");
        }
        if (ch == 'N' || ch == 'n')
        {
            printf("����ʧ�ܣ�����\n");
        }
    }
    return head;
}

//���� 
link* returnbook(link* head) {
    link* h, * p;
    char ch, ch1[100] = "�ڿ�", ch2[100] = "���ڿ�";
    h = head;
    printf("\n**************************************************\n");
    printf("\t\t��ӭʹ�û���ϵͳ!!!\n");
    p = findboookname(h);
    if (p == NULL)
        printf("����ʧ�ܣ��ⲻ�Ǳ������飡��");
    else {
        printf("ȷ�ϻ��飿Y/N:");
        scanf("%c", &ch);
        getchar();
        if (ch == 'Y' || ch == 'y')
        {
            strcpy(p->status, ch1);
            printf("����ɹ�������\n");
        }
        if (ch == 'N' || ch == 'n')
            printf("����ʧ�ܣ�����\n");
    }
    return head;
}
