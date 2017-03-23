/*
 * =====================================================================================
 *      
 *    Copyright (C), Agioe Devices Co.,Ltd.
 *
 *    Filename:  SqList.c
 *
 *    Author: Wang Lei, lwang@agioe.com   Version: 1.0  Date: 2017��03��18�� 
 *
 *    Description:  ˳���ʾ�����Ա�Ļ�������(12��)+��չ����(10��)
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
#include "SqList.h"

Status InitList(SqList *L) 
{ // �������������һ���յ�˳�����Ա�
    L->elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L->elem)
        return ERROR; // �洢����ʧ��
    L->length=0; // �ձ���Ϊ0
    L->listsize=LIST_INIT_SIZE; // ��ʼ�洢����
    return OK;
}

Status DestroyList(SqList *L)
{ // ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������˳�����Ա�L
    free(L->elem);
    L->elem=NULL;
    L->length=0;
    L->listsize=0;
    return OK;
}

Status ClearList(SqList *L)
{ // ��ʼ������˳�����Ա�L�Ѵ��ڡ������������L����Ϊ�ձ�
    L->length=0;
    return OK;
}

Status ListEmpty(SqList L)
{ // ��ʼ������˳�����Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE
    if(L.length==0)
        return TRUE;
    else
        return FALSE;
}

int ListLength(SqList L)
{ // ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ���
    return L.length;
}

Status GetElem(SqList L,int i,ElemType *e)
{ // ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L)
    // �����������e����L�е�i������Ԫ�ص�ֵ
    if(i<1||i>L.length)
        return ERROR;
    *e=*(L.elem+i-1);
    return OK;
}

int LocateElem(SqList L,ElemType e,Status(*compare)(ElemType,ElemType))
{ // ��ʼ������˳�����Ա�L�Ѵ��ڣ�compare()������Ԫ���ж�����(����Ϊ1,����Ϊ0)
    // �������������L�е�1����e�����ϵcompare()������Ԫ�ص�λ��
    //           ������������Ԫ�ز����ڣ��򷵻�ֵΪ0���㷨2.6
    ElemType *p;
    int i=1; // i�ĳ�ֵΪ��1��Ԫ�ص�λ��
    p=L.elem; // p�ĳ�ֵΪ��1��Ԫ�صĴ洢λ��
    while(i<=L.length&&!compare(*p++,e))
        ++i;
    if(i<=L.length)
        return i;
    else
        return 0;
}

Status PriorElem(SqList L,ElemType cur_e,ElemType *pre_e)
{ // ��ʼ������˳�����Ա�L�Ѵ���
    // �����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ����
    //           �������ʧ�ܣ�pre_e�޶���
    int i=2;
    ElemType *p=L.elem+1;
    while(i<=L.length&&*p!=cur_e)
    {
        p++;
        i++;
    }
    if(i>L.length)
        return INFEASIBLE;
    else
    {
        *pre_e=*--p;
        return OK;
    }
}

Status NextElem(SqList L,ElemType cur_e,ElemType *next_e)
{ // ��ʼ������˳�����Ա�L�Ѵ���
    // �����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣�
    //           �������ʧ�ܣ�next_e�޶���
    int i=1;
    ElemType *p=L.elem;
    while(i<L.length&&*p!=cur_e)
    {
        i++;
        p++;
    }
    if(i==L.length)
        return INFEASIBLE;
    else
    {
        next_e=*++p;
        return OK;
    }
}

Status ListInsert(SqList *L,int i,ElemType e) // �㷨2.4
{ // ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L)+1
    // �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1
    ElemType *newbase,*q,*p;
    if(i<1||i>L->length+1) // iֵ���Ϸ�
        return ERROR;
    if(L->length>=L->listsize) // ��ǰ�洢�ռ�����,���ӷ���
    {
        if(!(newbase=(ElemType *)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType))))
            return ERROR; // �洢����ʧ��
        L->elem=newbase; // �»�ַ
        L->listsize+=LISTINCREMENT; // ���Ӵ洢����
    }
    q=L->elem+i-1; // qΪ����λ��
    for(p=L->elem+L->length-1;p>=q;--p) // ����λ�ü�֮���Ԫ������
        *(p+1)=*p;
    *q=e; // ����e
    ++L->length; // ����1
    return OK;
}

Status ListDelete(SqList *L,int i,ElemType *e) // �㷨2.5
{ // ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L)
    // ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1
    ElemType *p,*q;
    if(i<1||i>L->length) // iֵ���Ϸ�
        return ERROR;
    p=L->elem+i-1; // pΪ��ɾ��Ԫ�ص�λ��
    e=*p; // ��ɾ��Ԫ�ص�ֵ����e
    q=L->elem+L->length-1; // ��βԪ�ص�λ��
    for(++p;p<=q;++p) // ��ɾ��Ԫ��֮���Ԫ������
        *(p-1)=*p;
    L->length--; // ����1
    return OK;
}

Status ListTraverse(SqList L,void(*vi)(ElemType*))
{ // ��ʼ������˳�����Ա�L�Ѵ���
    // ������������ζ�L��ÿ������Ԫ�ص��ú���vi()��һ��vi()ʧ�ܣ������ʧ��
    //           vi()���βμ�'&'��������ͨ������vi()�ı�Ԫ�ص�ֵ
    ElemType *p;
    int i;
    p=L.elem;
    for(i=1;i<=L.length;i++)
        vi(*p++);
    return OK;
}

// ˳���ʾ�����Ա����չ����(10��)
void InsertAscend(SqList *L,ElemType e)
{ // ��ʼ���������ǽ������е�˳�����Ա�L�Ѵ���
    // �����������L�а��ǽ�������µ�����Ԫ��e��L�ĳ��ȼ�1
    ElemType *newbase,*p;
    int k;
    if(L->length>=L->listsize) // ��ǰ�洢�ռ�����,���ӷ���
    {
        if(!(newbase=(ElemType *)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType))))
            exit(OVERFLOW); // �洢����ʧ��
        L->elem=newbase; // �»�ַ
        L->listsize+=LISTINCREMENT; // ���Ӵ洢����
    }
    p=L->elem;
    for(k=1;k<=L->length;k++)
        if(e>*p)
            p++;
        else
            break;
    ListInsert(L,k,e); // ������bo2-1.cpp��
}

void InsertDescend(SqList *L,ElemType e)
{ // ��ʼ�����������������е�˳�����Ա�L�Ѵ���
    // �����������L�а�����������µ�����Ԫ��e��L�ĳ��ȼ�1
    ElemType *newbase,*p;
    int k;
    if(L->length>=L->listsize) // ��ǰ�洢�ռ�����,���ӷ���
    {
        if(!(newbase=(ElemType *)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType))))
            exit(OVERFLOW); // �洢����ʧ��
        L->elem=newbase; // �»�ַ
        L->listsize+=LISTINCREMENT; // ���Ӵ洢����
    }
    p=L->elem;
    for(k=1;k<=L->length;k++)
        if(e<*p)
            p++;
        else
            break;
    ListInsert(L,k,e); // ������bo2-1.cpp��
}

Status HeadInsert(SqList *L,ElemType e)
{ // ��ʼ������˳�����Ա�L�Ѵ��ڡ������������L��ͷ�������µ�����Ԫ��e��L�ĳ��ȼ�1
    ElemType *p,*q,*newbase;
    if(L->length>=L->listsize)
    {
        if(!(newbase=(ElemType *)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType))))
            exit(OVERFLOW);
        L->elem=newbase;
        L->listsize+=LISTINCREMENT;
    }
    q=L->elem;
    for(p=L->elem+L->length-1;p>=q;--p)
        *(p+1)=*p;
    *q=e;
    L->length++;
    return OK;
}

Status EndInsert(SqList *L,ElemType e)
{ // ��ʼ������˳�����Ա�L�Ѵ��ڡ������������L��β�������µ�����Ԫ��e��L�ĳ��ȼ�1��
    ElemType *q,*newbase;
    if(L->length>=L->listsize) // ��ǰ�洢�ռ�����,���ӷ���
    {
        if(!(newbase=(ElemType *)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType))))
            exit(OVERFLOW); // �洢����ʧ��
        L->elem=newbase; // �»�ַ
        L->listsize+=LISTINCREMENT; // ���Ӵ洢����
    }
    q=L->elem+L->length; // qΪ����λ��
    *q=e;
    L->length++;
    return OK;
}

Status DeleteFirst(SqList *L,ElemType *e)
{ // ��ʼ������˳�����Ա�L�Ѵ��ڣ����в�����1��Ԫ��
    // ���������ɾ��L�ĵ�һ������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1
    ElemType *p,*q;
    if(ListEmpty(L)) // �ձ��޷�ɾ��
        return ERROR;
    p=L->elem; // pָ���һ��Ԫ��
    e=*p;
    q=L->elem+L->length-1; // qָ�����һ��Ԫ��
    for(++p;p<=q;++p)
        *(p-1)=*p; // �ӵ�2��Ԫ��������Ԫ����ǰ�ƶ�һ��λ��
    L->length--; // ��ǰ���ȼ�1
    return OK;
}

Status DeleteTail(SqList *L,ElemType *e)
{ // ��ʼ������˳�����Ա�L�Ѵ��ڣ����в�����1��Ԫ��
    // ���������ɾ��L�����һ������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1
    ElemType *p;
    if(!L->length) // �ձ�
        return ERROR;
    p=L->elem+L->length-1; // ���һ������Ԫ�ص�λ��
    e=*p; // ��ɾ��Ԫ�ص�ֵ����e
    L->length--; // ����1
    return OK;
}

Status DeleteElem(SqList *L,ElemType e)
{ // ɾ������ֵΪe��Ԫ�أ�������TRUE�����޴�Ԫ�أ��򷵻�FALSE
    int i=0,j;
    while(i<L->length&&e!=*(L->elem+i))
        i++;
    if(i==L->length) // û�ҵ�
        return FALSE;
    else
    {
        for(j=i;j<L->length;j++)
            *(L->elem+j)=*(L->elem+j+1); // �����Ԫ������ǰ��
        L->length--; // ��ǰ���ȼ�1
        return TRUE;
    }
}

Status ReplaceElem(SqList L,int i,ElemType e)
{ // ��eȡ����L�е�i��Ԫ�ص�ֵ
    if(i<1||i>L.length) // iֵ���Ϸ�
        exit(ERROR);
    *(L.elem+i-1)=e;
    return OK;
}

Status CreatAscend(SqList *L,int n)
{ // ���ǽ�����n��Ԫ�ص����Ա�
    int i,j;
    ElemType e;
    InitList(L);
    printf("������%d��Ԫ��:\n",n);
    cin>>e;
    ListInsert(L,1,e); // �ڿձ��в����1��Ԫ��
    for(i=1;i<n;i++)
    {
        cin>>e;
        for(j=0;j<L->length;j++)
            if(e<=*(L->elem+j))
                break;
        ListInsert(L,j+1,e); // ���ڱ���
    }
    return TRUE;
}

Status CreatDescend(SqList *L,int n)
{ // ����������n��Ԫ�ص����Ա�
    int i,j;
    ElemType e;
    InitList(L);
    printf("������%d��Ԫ��:\n",n);
    cin>>e;
    ListInsert(L,1,e); // �ڿձ��в����1��Ԫ��
    for(i=1;i<n;i++)
    {
        cin>>e;
        for(j=0;j<L->length;j++)
            if(e>=*(L->elem+j))
                break;
        ListInsert(L,j+1,e); // ���ڱ���
    }
    return TRUE;
}
