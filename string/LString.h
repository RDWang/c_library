/*
 * =====================================================================================
 *
 *    Copyright (C) 2009-2017 Wang Lei
 *
 *    Filename:  LString.h
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017��03��28�� 
 *
 *    Description:  // c4-3.h ���Ŀ����洢��ʾ
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

#ifndef _INCLUDE_LSTRING_H_
#define _INCLUDE_LSTRING_H_

#include "CdataStruct_type.h"

#define CHUNKSIZE 4 // �����û�����Ŀ��С
#define  blank   (1)

typedef struct Chunk
{
    char ch[CHUNKSIZE];
    struct Chunk *next;
}Chunk;

typedef struct LString
{
    Chunk *head,*tail; // ����ͷ��βָ��
    int curlen; // ���ĵ�ǰ����
}LString;

//���������ӿ�
extern void InitString(LString *T);
extern Status StrAssign(LString *T,char *chars);
extern Status StrCopy(LString *T,LString S);
extern Status StrEmpty(LString S);
extern int StrCompare(LString S,LString T);
extern int StrLength(LString S);
extern Status ClearString(LString *S);
extern Status Concat(LString *T,LString S1,LString S2);
extern Status SubString(LString *Sub, LString S,int pos,int len);
extern int Index(LString S,LString T,int pos);
extern void Zip(LString *S);
extern Status StrInsert(LString *S,int pos,LString T);
extern Status StrDelete(LString *S,int pos,int len);
extern Status Replace(LString *S,LString T,LString V);
extern void StrPrint(LString T);
extern void DestroyString();

#endif
