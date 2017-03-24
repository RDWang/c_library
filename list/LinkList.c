/*
 * =====================================================================================
 *      
 *    Copyright (C), Agioe Devices Co.,Ltd.
 *
 *    Filename:  LinkList.c
 *
 *    Author: Wang Lei, lwang@agioe.com   Version: 1.0  Date: 2017��03��18�� 
 *
 *    Description:  ���������Ա�Ļ�������(12��)+���������Ա����չ����(11��)
 *
 *    Others:
 *
 *    Function List:
 *
 *      1.
 *
 *    History:(None)
 *
 *      1. Date:
 *         Author:
 *         Modification: 
 *
 *      2. ...
 *
 * =====================================================================================
 */
#include "LinkList.h"


Status InitList(LinkList *L)
 { // �������������һ���յ����Ա�L
   *L=(LinkList)malloc(sizeof(struct LNode)); // ����ͷ���,��ʹLָ���ͷ���
   if(!*L) // �洢����ʧ��
     return ERROR;
   (*L)->next=NULL; // ָ����Ϊ��
   return OK;
 }

Status DestroyList(LinkList *L)
 { // ��ʼ���������Ա�L�Ѵ��ڡ�����������������Ա�L
   LinkList q;
   while(*L)
   {
     q=(*L)->next;
     free(*L);
     *L=q;
   }
   return OK;
 }

Status ClearList(LinkList L) // ���ı�L
 { // ��ʼ���������Ա�L�Ѵ��ڡ������������L����Ϊ�ձ�
   LinkList p,q;
   p=L->next; // pָ���һ�����
   while(p) // û����β
   {
     q=p->next;
     free(p);
     p=q;
   }
   L->next=NULL; // ͷ���ָ����Ϊ��
   return OK;
 }

Status ListEmpty(LinkList L)
 { // ��ʼ���������Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE
   if(L->next) // �ǿ�
     return FALSE;
   else
     return TRUE;
 }

 int ListLength(LinkList L)
 { // ��ʼ���������Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ���
   int i=0;
   LinkList p=L->next; // pָ���һ�����
   while(p) // û����β
   {
     i++;
     p=p->next;
   }
   return i;
 }

 Status GetElem(LinkList L,int i,ElemType *e) // �㷨2.8
 { // LΪ��ͷ���ĵ������ͷָ�롣����i��Ԫ�ش���ʱ,��ֵ����e������OK,���򷵻�ERROR
   int j=1; // jΪ������
   LinkList p=L->next; // pָ���һ�����
   while(p&&j<i) // ˳ָ��������,ֱ��pָ���i��Ԫ�ػ�pΪ��
   {
     p=p->next;
     j++;
   }
   if(!p||j>i) // ��i��Ԫ�ز�����
     return ERROR;
   *e=p->data; // ȡ��i��Ԫ��
   return OK;
 }

 int LocateElem(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType))
 { // ��ʼ����: ���Ա�L�Ѵ���,compare()������Ԫ���ж�����(����Ϊ1,����Ϊ0)
   // �������: ����L�е�1����e�����ϵcompare()������Ԫ�ص�λ��
   //           ������������Ԫ�ز�����,�򷵻�ֵΪ0
   int i=0;
   LinkList p=L->next;
   while(p)
   {
     i++;
     if(compare(p->data,e)) // �ҵ�����������Ԫ��
       return i;
     p=p->next;
   }
   return 0;
 }

 Status PriorElem(LinkList L,ElemType cur_e,ElemType *pre_e)
 { // ��ʼ����: ���Ա�L�Ѵ���
   // �������: ��cur_e��L������Ԫ��,�Ҳ��ǵ�һ��,����pre_e��������ǰ��,
   //           ����OK;�������ʧ��,pre_e�޶���,����INFEASIBLE
   LinkList q,p=L->next; // pָ���һ�����
   while(p->next) // p��ָ����к��
   {
     q=p->next; // qΪp�ĺ��
     if(q->data==cur_e)
     {
       *pre_e=p->data;
       return OK;
     }
     p=q; // p�����
   }
   return INFEASIBLE;
 }

 Status NextElem(LinkList L,ElemType cur_e,ElemType *next_e)
 { // ��ʼ���������Ա�L�Ѵ���
   // �����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣�
   //           ����OK;�������ʧ�ܣ�next_e�޶��壬����INFEASIBLE
   LinkList p=L->next; // pָ���һ�����
   while(p->next) // p��ָ����к��
   {
     if(p->data==cur_e)
     {
       *next_e=p->next->data;
       return OK;
     }
     p=p->next;
   }
   return INFEASIBLE;
 }

 Status ListInsert(LinkList L,int i,ElemType e) // ���ı�L
 { // �ڴ�ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e
   int j=0;
   LinkList p=L,s;
   while(p&&j<i-1) // Ѱ�ҵ�i-1�����
   {
     p=p->next;
     j++;
   }
   if(!p||j>i-1) // iС��1���ߴ��ڱ�
     return ERROR;
   s=(LinkList)malloc(sizeof(struct LNode)); // �����½��
   s->data=e; // ����L��
   s->next=p->next;
   p->next=s;
   return OK;
 }

 Status ListDelete(LinkList L,int i,ElemType *e) // ���ı�L
 { // �ڴ�ͷ���ĵ������Ա�L�У�ɾ����i��Ԫ��,����e������ֵ
   int j=0;
   LinkList p=L,q;
   while(p->next&&j<i-1) // Ѱ�ҵ�i�����,����pָ����ǰ��
   {
     p=p->next;
     j++;
   }
   if(!p->next||j>i-1) // ɾ��λ�ò�����
     return ERROR;
   q=p->next; // ɾ�����ͷŽ��
   p->next=q->next;
   *e=q->data;
   free(q);
   return OK;
 }

 Status ListTraverse(LinkList L,void(*vi)(ElemType))
 // vi���β�����ΪElemType����bo2-1.cpp����Ӧ�������β�����ElemType&��ͬ
 { // ��ʼ���������Ա�L�Ѵ���
   // �������:���ζ�L��ÿ������Ԫ�ص��ú���vi()��һ��vi()ʧ��,�����ʧ��
   LinkList p=L->next;
   while(p)
   {
     vi(p->data);
     p=p->next;
   }
   printf("\n");
   return OK;
 }

// bo2-9.cpp ���������Ա�(�洢�ṹ��c2-2.h����)����չ����(11��)
 void InsertAscend(LinkList L,ElemType e)
 { // ��ʼ���������ǽ������е����Ա�L�Ѵ��ڡ������������L�а��ǽ�������µ�����Ԫ��e
   LinkList q=L,p=L->next;
   while(p&&e>p->data)
   {
     q=p;
     p=p->next;
   }
   q->next=(LinkList)malloc(sizeof(struct LNode)); // ����q��
   q->next->data=e;
   q->next->next=p;
 }

 void InsertDescend(LinkList L,ElemType e)
 { // ��ʼ�����������������е����Ա�L�Ѵ��ڡ������������L�а�����������µ�����Ԫ��e
   LinkList q=L,p=L->next;
   while(p&&e<p->data)
   {
     q=p;
     p=p->next;
   }
   q->next=(LinkList)malloc(sizeof(struct LNode)); // ����q��
   q->next->data=e;
   q->next->next=p;
 }

 Status HeadInsert(LinkList L,ElemType e)
 { // ��ʼ���������Ա�L�Ѵ��ڡ������������L��ͷ�������µ�����Ԫ��e,��Ϊ����ĵ�һ��Ԫ��
   LinkList s;
   s=(LinkList)malloc(sizeof(struct LNode)); // �����½��
   s->data=e; // ����㸳ֵ
   s->next=L->next; // ���ڱ�ͷ
   L->next=s;
   return OK;
 }

 Status EndInsert(LinkList L,ElemType e)
 { // ��ʼ���������Ա�L�Ѵ��ڡ������������L��β�������µ�����Ԫ��e,��Ϊ��������һ��Ԫ��
   LinkList p=L;
   while(p->next) // ʹpָ���βԪ��
     p=p->next;
   p->next=(LinkList)malloc(sizeof(struct LNode)); // �ڱ�β�����½��
   p->next->data=e; // ���½�㸳ֵ
   p->next->next=NULL; // ��β
   return OK;
 }

 Status DeleteFirst(LinkList L,ElemType *e)
 { // ��ʼ���������Ա�L�Ѵ��ڣ����в�����1��Ԫ��
   // ���������ɾ��L�ĵ�һ������Ԫ�أ�����e������ֵ
   LinkList p=L->next;
   if(p)
   {
     *e=p->data;
     L->next=p->next;
     free(p);
     return OK;
   }
   else
     return ERROR;
 }

 Status DeleteTail(LinkList L,ElemType *e)
 { // ��ʼ���������Ա�L�Ѵ��ڣ����в�����1��Ԫ��
   // ���������ɾ��L�����һ������Ԫ�أ�����e������ֵ
   LinkList p=L,q;
   if(!p->next) // ����Ϊ��
     return ERROR;
   while(p->next)
   {
     q=p;
     p=p->next;
   }
   q->next=NULL; // ��β����next����ΪNULL
   *e=p->data;
   free(p);
   return OK;
 }

 Status DeleteElem(LinkList L,ElemType e)
 { // ɾ������ֵΪe��Ԫ�أ�������TRUE�����޴�Ԫ�أ��򷵻�FALSE
   LinkList p=L,q;
   while(p)
   {
     q=p->next;
     if(q&&q->data==e)
     {
       p->next=q->next;
       free(q);
       return TRUE;
     }
     p=q;
   }
   return FALSE;
 }

 Status ReplaceElem(LinkList L,int i,ElemType e)
 { // ��eȡ����L�е�i��Ԫ�ص�ֵ
   LinkList p=L;
   int j=0;
   while(p->next&&j<i)
   {
     j++;
     p=p->next;
   }
   if(j==i)
   {
     p->data=e;
     return OK;
   }
   else // ���в����ڵ�i��Ԫ��
     return ERROR;
 }

 Status CreatAscend(LinkList *L,int n)
 { // ���ǽ�����n��Ԫ�ص����Ա�
   int j;
   LinkList p,q,s;
   if(n<=0)
     return ERROR;
   InitList(L);
   printf("������%d��Ԫ��:\n",n);
   s=(LinkList)malloc(sizeof(struct LNode)); // ��һ�����
   scanf("%d",&s->data);
   s->next=NULL;
   (*L)->next=s;
   for(j=1;j<n;j++)
   {
     s=(LinkList)malloc(sizeof(struct LNode)); // ������
     scanf("%d",&s->data);
     q=*L;
     p=(*L)->next;
     while(p&&p->data<s->data) // pû����β������ָԪ��ֵС����ֵ
     {
       q=p;
       p=p->next; // ָ�����
     }
     s->next=q->next; // Ԫ�ز���q�ĺ���
     q->next=s;
   }
   return OK;
 }

 Status CreatDescend(LinkList *L,int n)
 { // ����������n��Ԫ�ص����Ա�
   int j;
   LinkList p,q,s;
   if(n<=0)
     return ERROR;
   InitList(L);
   printf("������%d��Ԫ��:\n",n);
   s=(LinkList)malloc(sizeof(struct LNode)); // ��һ�����
   scanf("%d",&s->data);
   s->next=NULL;
   (*L)->next=s;
   for(j=1;j<n;j++)
   {
     s=(LinkList)malloc(sizeof(struct LNode)); // ������
     scanf("%d",&s->data);
     q=*L;
     p=(*L)->next;
     while(p&&p->data>s->data) // pû����β������ָԪ��ֵ������ֵ
     {
       q=p;
       p=p->next; // ָ�����
     }
     s->next=q->next; // Ԫ�ز���q�ĺ���
     q->next=s;
   }
   return OK;
 }

 Status GetFirstElem(LinkList L,ElemType *e)
 { // ���ر�ͷԪ�ص�ֵ
   LinkList p=L->next;
   if(!p) // �ձ�
     return ERROR;
   else // �ǿձ�
     *e=p->data;
   return OK;
 } 
