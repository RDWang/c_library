/*
 * =====================================================================================
 *      
 *    Copyright (C) 2009-2017 Wang Lei
 *
 *    Filename:  GList.c
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017��03��27�� 
 *
 *    Description:  // bo5-6.cpp ��������չ��������洢(�洢�ṹ��c5-6.h����)�Ļ�������(13��)
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
#include "GList.h"

// ��������д��ʽ��ΪHString����
Status InitGList(GList *L)
{ // �����յĹ����L
    *L=NULL;
    return OK;
}

Status sever(HString *str,HString *hstr) // ͬbo5-52.cpp
{ // ���ǿմ�str�ָ��������:hstrΪ��һ��','֮ǰ���Ӵ�,strΪ֮����Ӵ�
    int n,i=1,k=0; // k����δ��Ե������Ÿ���
    HString ch,c1,c2,c3;
    InitString(&ch); // ��ʼ��HString���͵ı���
    InitString(&c1);
    InitString(&c2);
    InitString(&c3);
    StrAssign(&c1,",");
    StrAssign(&c2,"(");
    StrAssign(&c3,")");
    n=StrLength(*str);
    do
    {
        SubString(&ch,*str,i,1);
        if(!StrCompare(ch,c2))
            ++k;
        else if(!StrCompare(ch,c3))
            --k;
        ++i;
    }while(i<=n&&StrCompare(ch,c1)||k!=0);
    if(i<=n)
    {
        StrCopy(&ch,*str);
        SubString(hstr,ch,1,i-2);
        SubString(str,ch,i,n-i+1);
    }
    else
    {
        StrCopy(hstr,*str);
        ClearString(str);
    }
    return OK;
}

Status CreateGList(GList *L,HString S)
{ // ��ʼ����: S�ǹ�������д��ʽ�����������: ��S���������L
    HString emp,sub,hsub;
    GList p;
    InitString(&emp);
    InitString(&sub);
    InitString(&hsub);
    StrAssign(&emp,"()"); // ��emp="()"
    if(!(*L=(GList)malloc(sizeof(GLNode)))) // �����㲻�ɹ�
        return ERROR;
    if(!StrCompare(S,emp)) // �����ձ�
    {
        (*L)->tag=LIST;
        (*L)->data.hp=NULL;
        (*L)->tp=NULL;
    }
    else if(StrLength(S)==1) // ������ԭ�ӹ����
    {
        (*L)->tag=ATOM;
        (*L)->data.atom=S.ch[0];
        (*L)->tp=NULL;
    }
    else // ����һ���
    {
        (*L)->tag=LIST;
        (*L)->tp=NULL;
        SubString(&sub,S,2,StrLength(S)-2); // ���������
        sever(&sub,&hsub); // ��sub�з������ͷ��hsub
        CreateGList(&((*L)->data.hp),hsub);
        p=(*L)->data.hp;
        while(!StrEmpty(sub)) // ��β����,���ظ���n���ӱ�
        {
            sever(&sub,&hsub); // ��sub�з������ͷ��hsub
            CreateGList(&p->tp,hsub);
            p=p->tp;
        };
    }
    return OK;
}

void DestroyGList(GList *L)
{ // ��ʼ����: �����L���ڡ��������: ���ٹ����L
    GList ph,pt;
    if(*L) // L��Ϊ�ձ�
    { // ��ph��pt����L������ָ��
        if((*L)->tag) // ���ӱ�
            ph=(*L)->data.hp;
        else // ��ԭ��
            ph=NULL;
        pt=(*L)->tp;
        free(*L); // �ͷ�L��ָ���
        *L=NULL; // ��LΪ��
        DestroyGList(&ph); // �ݹ����ٱ�ph
        DestroyGList(&pt); // �ݹ����ٱ�pt
    }
}

Status CopyGList(GList *T,GList L)
{ // ��ʼ����: �����L���ڡ��������: �ɹ����L���Ƶõ������T
    if(!L) // L��
    {
        T=NULL;
        return OK;
    }
    *T=(GList)malloc(sizeof(GLNode));
    if(!*T)
        return ERROR;
    (*T)->tag=L->tag; // ����ö�ٱ���
    if(L->tag==ATOM) // ���ƹ����岿��
        (*T)->data.atom=L->data.atom; // ���Ƶ�ԭ��
    else
        CopyGList(&((*T)->data.hp),L->data.hp); // �����ӱ�
    if(L->tp==NULL) // ����β
        (*T)->tp=L->tp;
    else
        CopyGList(&((*T)->tp),L->tp); // �����ӱ�
    return OK;
}

int GListLength(GList L)
{ // ��ʼ����: �����L���ڡ��������: ������L�ĳ���,��Ԫ�ظ���
    int len=0;
    GList p;
    if(L->tag==LIST&&!L->data.hp) // �ձ�
        return 0; // �ձ���0
    else if(L->tag==ATOM) // ��ԭ�ӱ�
        return 1;
    else // һ���
    {
        p=L->data.hp;
        do
        {
            len++;
            p=p->tp;
        }while(p);
        return len;
    }
}

int GListDepth(GList L)
{ // ��ʼ����: �����L���ڡ��������: ������L�����
    int max,dep;
    GList pp;
    if(L==NULL||L->tag==LIST&&!L->data.hp)
        return 1; // �ձ����Ϊ1
    else if(L->tag==ATOM)
        return 0; // ��ԭ�ӱ����Ϊ0
    else // ��һ�������
        for(max=0,pp=L->data.hp;pp;pp=pp->tp)
        {
            dep=GListDepth(pp); // ����ppΪͷָ����ӱ����
            if(dep>max)
                max=dep;
        }
    return max+1; // �ǿձ������Ǹ�Ԫ�ص���ȵ����ֵ��1
}

Status GListEmpty(GList L)
{ // ��ʼ����: �����L���ڡ��������: �ж������L�Ƿ�Ϊ��
    if(!L||L->tag==LIST&&!L->data.hp)
        return OK;
    else
        return ERROR;
}

GList GetHead(GList L)
{ // ��ʼ����: �����L���ڡ��������: ȡ�����L��ͷ
    GList h;
    InitGList(h);
    if(!L||L->tag==LIST&&!L->data.hp)
    {
        printf("\n�ձ��ޱ�ͷ!");
        exit(0);
    }
    h=(GList)malloc(sizeof(GLNode));
    if(!h)
        return ERROR;
    h->tag=L->data.hp->tag;
    h->tp=NULL;
    if(h->tag==ATOM)
        h->data.atom=L->data.hp->data.atom;
    else
        CopyGList(&(h->data.hp),L->data.hp->data.hp);
    return h;
}

GList GetTail(GList L)
{ // ��ʼ����: �����L���ڡ��������: ȡ�����L��β
    GList T;
    if(!L)
    {
        printf("\n�ձ��ޱ�β!");
        exit(0);
    }
    T=(GList)malloc(sizeof(GLNode));
    if(!T)
        return ERROR;
    T->tag=LIST;
    T->tp=NULL;
    CopyGList(&(T->data.hp),L->data.hp->tp);
    return T;
}

Status InsertFirst_GL(GList *L,GList e)
{ // ��ʼ����: ��������
    // �������: ����Ԫ��e��Ϊ�����L�ĵ�һԪ��(��ͷ,Ҳ�������ӱ�)
    GList p=(*L)->data.hp;
    (*L)->data.hp=e;
    e->tp=p;
    return OK;
}

Status DeleteFirst_GL(GList *L,GList *e)
{ // ��ʼ����:�����L���ڡ��������:ɾ�������L�ĵ�һԪ��,����e������ֵ
    if(*L)
    {
        *e=(*L)->data.hp;
        (*L)->data.hp=(*e)->tp;
        (*e)->tp=NULL;
    }
    else
        *e=*L;
    return OK;
}

void Traverse_GL(GList L,void(*v)(AtomType))
{ // ���õݹ��㷨���������L
    GList hp;
    if(L) // L����
    {
        if(L->tag==ATOM) // LΪ��ԭ��
        {
            v(L->data.atom);
            hp=NULL;
        }
        else // LΪ�ӱ�
            hp=L->data.hp;
        Traverse_GL(hp,v);
        Traverse_GL(L->tp,v);
    }
}
