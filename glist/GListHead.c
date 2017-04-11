/*
 * =====================================================================================
 *      
 *    Copyright (C) 2009-2017 Wang Lei
 *
 *    Filename:  GListHead.c
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017��03��27�� 
 *
 *    Description:  // bo5-5.cpp ������ͷβ����洢(�洢�ṹ��c5-5.h����)�Ļ�������(11��)
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
#include "GListHead.h"

Status InitGList(GList *L)
{ // �����յĹ����L
    *L=NULL;
    return OK;
}

void DestroyGList(GList *L) // ������ͷβ����洢�����ٲ���
{ // ���ٹ����L
    GList q1,q2;
    if(*L)
    {
        if((*L)->tag==ATOM)
        {
            free(*L); // ɾ��ԭ�ӽ��
            *L=NULL;
        }
        else // ɾ������
        {
            q1=(*L)->data.ptr.hp;
            q2=(*L)->data.ptr.tp;
            free(*L);
            *L=NULL;
            DestroyGList(&q1);
            DestroyGList(&q2);
        }
    }
}

Status CopyGList(GList *T,GList L)
{ // ����ͷβ����洢�ṹ,�ɹ����L���Ƶõ������T���㷨5.6
    if(!L) // ���ƿձ�
        *T=NULL;
    else
    {
        *T=(GList)malloc(sizeof(GLNode)); // ������
        if(!*T)
            return ERROR;
        (*T)->tag=L->tag;
        if(L->tag==ATOM)
            (*T)->data.atom=L->data.atom; // ���Ƶ�ԭ��
        else
        {
            CopyGList(&((*T)->data.ptr.hp),L->data.ptr.hp);
            // ���ƹ����L->ptr.hp��һ������T->ptr.hp
            CopyGList(&((*T)->data.ptr.tp),L->data.ptr.tp);
            // ���ƹ����L->ptr.tp��һ������T->ptr.tp
        }
    }
    return OK;
}

int GListLength(GList L)
{ // ���ع����ĳ���,��Ԫ�ظ���
    int len=0;
    if(!L)
        return 0;
    if(L->tag==ATOM)
        return 1;
    while(L)
    {
        L=L->data.ptr.tp;
        len++;
    }
    return len;
}

int GListDepth(GList L)
{ // ����ͷβ����洢�ṹ,������L����ȡ��㷨5.5
    int max,dep;
    GList pp;
    if(!L)
        return 1; // �ձ����Ϊ1
    if(L->tag==ATOM)
        return 0; // ԭ�����Ϊ0
    for(max=0,pp=L;pp;pp=pp->data.ptr.tp)
    {
        dep=GListDepth(pp->data.ptr.hp); // ����pp->a.ptr.hpΪͷָ����ӱ����
        if(dep>max)
            max=dep;
    }
    return max+1; // �ǿձ������Ǹ�Ԫ�ص���ȵ����ֵ��1
}

Status GListEmpty(GList L)
{ // �ж�������Ƿ�Ϊ��
    if(!L)
        return TRUE;
    else
        return FALSE;
}

GList GetHead(GList L)
{ // ȡ�����L��ͷ
    GList h,p;
    if(!L)
    {
        printf("�ձ��ޱ�ͷ!\n");
        exit(0);
    }
    p=L->data.ptr.tp;
    L->data.ptr.tp=NULL;
    CopyGList(&h,L);
    L->data.ptr.tp=p;
    return h;
}

GList GetTail(GList L)
{ // ȡ�����L��β
    GList t;
    if(!L)
    {
        printf("�ձ��ޱ�β!\n");
        exit(0);
    }
    CopyGList(&t,L->data.ptr.tp);
    return t;
}

Status InsertFirst_GL(GList *L,GList e)
{ // ��ʼ����: ��������
    // �������: ����Ԫ��e��Ϊ�����L�ĵ�һԪ��(��ͷ,Ҳ�������ӱ�)
    GList p=(GList)malloc(sizeof(GLNode));
    if(!p)
        return ERROR;
    p->tag=LIST;
    p->data.ptr.hp=e;
    p->data.ptr.tp=*L;
    *L=p;
    return OK;
}

Status DeleteFirst_GL(GList *L,GList *e)
{ // ��ʼ����: �����L����
    // �������: ɾ�������L�ĵ�һԪ��,����e������ֵ
    GList p;
    *e=(*L)->data.ptr.hp;
    p=*L;
    *L=(*L)->data.ptr.tp;
    free(p);
    return OK;
}

void Traverse_GL(GList L,void(*v)(AtomType))
{ // ���õݹ��㷨���������L
    if(L) // L����
    {
        if(L->tag==ATOM) // LΪ��ԭ��
            v(L->data.atom);
        else // LΪ�����
        {
            Traverse_GL(L->data.ptr.hp,v);
            Traverse_GL(L->data.ptr.tp,v);
        }
    }
}
