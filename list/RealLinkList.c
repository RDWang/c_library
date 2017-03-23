/*
 * =====================================================================================
 *      
 *    Copyright (C), Agioe Devices Co.,Ltd.
 *
 *    Filename:  RealLinkList.c
 *
 *    Author: Wang Lei, lwang@agioe.com   Version: 1.0  Date: 2017��03��18�� 
 *
 *    Description:  // ����ѭ�����Ա�(�洢�ṹ��c2-4.h����)�Ļ�������(14��)
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
#include "RealLinkList.h"

// ����ʵ���������������(�洢�ṹ��c2-5.h����)��24����������
Status MakeNode(Link *p,ElemType e)
{ // ������pָ���ֵΪe�Ľ�㣬������OK��������ʧ�ܡ��򷵻�ERROR
    *p=(Link)malloc(sizeof(LNode));
    if(!*p)
        return ERROR;
    *p->data=e;
    return OK;
}

void FreeNode(Link p)
{ // �ͷ�p��ָ���
    free(p);
    p=NULL;
}

Status InitList(LinkList *L)
{ // ����һ���յ���������
    Link p;
    p=(Link)malloc(sizeof(LNode)); // ����ͷ���
    if(p)
    {
        p->next=NULL;
        L->head=L->tail=p;
        L->len=0;
        return OK;
    }
    else
        return ERROR;
}

Status ClearList(LinkList *L)
{ // ����������L����Ϊ�ձ������ͷ�ԭ�����Ľ��ռ�
    Link p,q;
    if(L->head!=L->tail)// ���ǿձ�
    {
        p=q=L->head->next;
        L->head->next=NULL;
        while(p!=L->tail)
        {
            p=q->next;
            free(q);
            q=p;
        }
        free(q);
        L->tail=L->head;
        L->len=0;
    }
    return OK;
}

Status DestroyList(LinkList *L)
{ // ������������L��L���ٴ���
    ClearList(L); // �������
    FreeNode(L->head);
    L->tail=NULL;
    L->len=0;
    return OK;
}

Status InsFirst(LinkList *L,Link h,Link s) // �β�����L,��Ϊ���޸�L
{ // hָ��L��һ����㣬��h����ͷ��㣬��s��ָ�������ڵ�һ�����֮ǰ
    s->next=h->next;
    h->next=s;
    if(h==L->tail) // hָ��β���
        L->tail=h->next; // �޸�βָ��
    L->len++;
    return OK;
}

Status DelFirst(LinkList *L,Link h,Link *q) // �β�����L,��Ϊ���޸�L
{ // hָ��L��һ����㣬��h����ͷ��㣬ɾ�������еĵ�һ����㲢��q���ء�
    // ������Ϊ��(hָ��β���)��q=NULL������FALSE
    *q=h->next;
    if(*q) // �����ǿ�
    {
        h->next=*q->next;
        if(!h->next) // ɾ��β���
            L->tail=h; // �޸�βָ��
        L->len--;
        return OK;
    }
    else
        return FALSE; // ������
}

Status Append(LinkList *L,Link s)
{ // ��ָ��s(s->dataΪ��һ������Ԫ��)��ָ(�˴���ָ������,��NULL��β)��
    // һ�������������������L�����һ�����֮��,���ı�����L��βָ��ָ����
    // ��β���
    int i=1;
    L->tail->next=s;
    while(s->next)
    {
        s=s->next;
        i++;
    }
    L->tail=s;
    L->len+=i;
    return OK;
}

Link PriorPos(LinkList L,Link p)
{ // ��֪pָ����������L�е�һ����㣬����p��ָ����ֱ��ǰ����λ��
    // ����ǰ�����򷵻�NULL
    Link q;
    q=L.head->next;
    if(q==p) // ��ǰ��
        return NULL;
    else
    {
        while(q->next!=p) // q����p��ֱ��ǰ��
            q=q->next;
        return q;
    }
}

Status Remove(LinkList *L,Link *q)
{ // ɾ����������L�е�β��㲢��q���أ��ı�����L��βָ��ָ���µ�β���
    Link p=L->head;
    if(L->len==0) // �ձ�
    {
        *q=NULL;
        return FALSE;
    }
    while(p->next!=L->tail)
        p=p->next;
    *q=L->tail;
    p->next=NULL;
    L->tail=p;
    L->len--;
    return OK;
}

Status InsBefore(LinkList *L,Link *p,Link s)
{ // ��֪pָ����������L�е�һ����㣬��s��ָ��������p��ָ���֮ǰ��
    // ���޸�ָ��pָ���²���Ľ��
    Link q;
    q=PriorPos(L,p); // q��p��ǰ��
    if(!q) // p��ǰ��
        q=L->head;
    s->next=*p;
    q->next=s;
    *p=s;
    L->len++;
    return OK;
}

Status InsAfter(LinkList *L,Link *p,Link s)
{ // ��֪pָ����������L�е�һ����㣬��s��ָ��������p��ָ���֮��
    // ���޸�ָ��pָ���²���Ľ��
    if(*p==L->tail) // �޸�βָ��
        L->tail=s;
    s->next=p->next;
    p->next=s;
    p=s;
    L->len++;
    return OK;
}

Status SetCurElem(Link p,ElemType e)
{ // ��֪pָ�����������е�һ����㣬��e����p��ָ���������Ԫ�ص�ֵ
    p->data=e;
    return OK;
}

ElemType GetCurElem(Link p)
{ // ��֪pָ�����������е�һ����㣬����p��ָ���������Ԫ�ص�ֵ
    return p->data;
}

Status ListEmpty(LinkList L)
{ // ����������LΪ�ձ����򷵻�TRUE�����򷵻�FALSE
    if(L.len)
        return FALSE;
    else
        return TRUE;
}

int ListLength(LinkList L)
{ // ������������L��Ԫ�ظ���
    return L.len;
}

Link GetHead(LinkList L)
{ // ������������L��ͷ����λ��
    return L.head;
}

Link GetLast(LinkList L)
{ // ������������L�����һ������λ��
    return L.tail;
}

Link NextPos(Link p)
{ // ��֪pָ����������L�е�һ����㣬����p��ָ����ֱ�Ӻ�̵�λ��
    // ���޺�̣��򷵻�NULL
    return p->next;
}

Status LocatePos(LinkList L,int i,Link *p)
{ // ����pָʾ��������L�е�i������λ�ã�������OK��iֵ���Ϸ�ʱ����ERROR
    // i=0Ϊͷ���
    int j;
    if(i<0||i>L.len)
        return ERROR;
    else
    {
        *p=L.head;
        for(j=1;j<=i;j++)
            *p=*p->next;
        return OK;
    }
}

Position LocateElem(LinkList L,ElemType e,Status (*compare)(ElemType,ElemType))
{ // ������������L�е�1����e���㺯��compare()�ж���ϵ��Ԫ�ص�λ�ã�
    // ��������������Ԫ�أ��򷵻�NULL
    Link p=L.head;
    do
        p=p->next;
    while(p&&!(compare(p->data,e))); // û����β��û�ҵ������ϵ��Ԫ��
    return p;
}

Status ListTraverse(LinkList L,void(*visit)(ElemType))
{ // ���ζ�L��ÿ������Ԫ�ص��ú���visit()��һ��visit()ʧ�ܣ������ʧ��
    Link p=L.head->next;
    int j;
    for(j=1;j<=L.len;j++)
    {
        visit(p->data);
        p=p->next;
    }
    printf("\n");
    return OK;
}

Status OrderInsert(LinkList *L,ElemType e,int (*comp)(ElemType,ElemType))
{ // ��֪LΪ����������������Ԫ��e���ǽ��������L�С�������һԪ����ʽ��
    Link o,p,q;
    q=L->head;
    p=q->next;
    while(p!=NULL&&comp(p->data,e)<0) // p���Ǳ�β��Ԫ��ֵС��e
    {
        q=p;
        p=p->next;
    }
    o=(Link)malloc(sizeof(LNode)); // ���ɽ��
    o->data=e; // ��ֵ
    q->next=o; // ����
    o->next=p;
    L->len++; // ������1
    if(!p) // ���ڱ�β
        L->tail=o; // �޸�β���
    return OK;
}

Status LocateElem(LinkList L,ElemType e,Link *q,int(*compare)(ElemType,ElemType))
{ // ����������L�д�����e�����ж�����compare()ȡֵΪ0��Ԫ�أ���qָʾL��
    // ��һ��ֵΪe�Ľ���λ�ã�������TRUE������qָʾ��һ����e�����ж�����
    // compare()ȡֵ>0��Ԫ�ص�ǰ����λ�á�������FALSE��������һԪ����ʽ��
    Link p=L.head,pp;
    do
    {
        pp=p;
        p=p->next;
    }while(p&&(compare(p->data,e)<0)); // û����β��p->data.expn<e.expn
    if(!p||compare(p->data,e)>0) // ����β��compare(p->data,e)>0
    {
        *q=pp;
        return FALSE;
    }
    else // �ҵ�
    {
        *q=p;
        return TRUE;
    }
}