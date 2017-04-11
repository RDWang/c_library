/*
 * =====================================================================================
 *      
 *    Copyright (C) 2009-2017  Wang Lei
 *
 *    Filename:  LinkQueue.c
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017��03��28�� 
 *
 *    Description:  // bo3-2.cpp ������(�洢�ṹ��c3-2.h����)�Ļ�������(9��)
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


#include "LinkQueue.h"

Status InitQueue(LinkQueue *Q)
{ // ����һ���ն���Q
    if(!(Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode))))
        return ERROR;
    Q->front->next=NULL;
    return OK;
}

Status DestroyQueue(LinkQueue *Q)
{ // ���ٶ���Q(���ۿշ����)
    while(Q->front)
    {
        Q->rear=Q->front->next;
        free(Q->front);
        Q->front=Q->rear;
    }
    return OK;
}

Status ClearQueue(LinkQueue *Q)
{ // ��Q��Ϊ�ն���
    QueuePtr p,q;
    Q->rear=Q->front;
    p=Q->front->next;
    Q->front->next=NULL;
    while(p)
    {
        q=p;
        p=p->next;
        free(q);
    }
    return OK;
}

Status QueueEmpty(LinkQueue Q)
{ // ��QΪ�ն���,�򷵻�TRUE,���򷵻�FALSE
    if(Q.front==Q.rear)
        return TRUE;
    else
        return FALSE;
}

int QueueLength(LinkQueue Q)
{ // ����еĳ���
    int i=0;
    QueuePtr p;
    p=Q.front;
    while(Q.rear!=p)
    {
        i++;
        p=p->next;
    }
    return i;
}

Status GetHead(LinkQueue Q,QElemType *e)
{ // �����в���,����e����Q�Ķ�ͷԪ��,������OK,���򷵻�ERROR
    QueuePtr p;
    if(Q.front==Q.rear)
        return ERROR;
    p=Q.front->next;
    *e=p->data;
    return OK;
}

Status EnQueue(LinkQueue *Q,QElemType e)
{ // ����Ԫ��eΪQ���µĶ�βԪ��
    QueuePtr p;
    if(!(p=(QueuePtr)malloc(sizeof(QNode)))) // �洢����ʧ��
        return ERROR;
    p->data=e;
    p->next=NULL;
    Q->rear->next=p;
    Q->rear=p;
    return OK;
}

Status DeQueue(LinkQueue *Q,QElemType *e)
{ // �����в���,ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������OK,���򷵻�ERROR
    QueuePtr p;
    if(Q->front==Q->rear)
        return ERROR;
    p=Q->front->next;
    *e=p->data;
    Q->front->next=p->next;
    if(Q->rear==p)
        Q->rear=Q->front;
    free(p);
    return OK;
}

Status QueueTraverse(LinkQueue Q,void(*vi)(QElemType))
{ // �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�ص��ú���vi()��һ��viʧ��,�����ʧ��
    QueuePtr p;
    p=Q.front->next;
    while(p)
    {
        vi(p->data);
        p=p->next;
    }
    printf("\n");
    return OK;
}