/*
 * =====================================================================================
 *
 *    Copyright (C) 2009-2017 Wang Lei
 *
 *    Filename:  LString.h
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017年03月28日 
 *
 *    Description:  // c4-3.h 串的块链存储表示
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

#define CHUNKSIZE 4 // 可由用户定义的块大小
#define  blank   (1)

typedef struct Chunk
{
    char ch[CHUNKSIZE];
    struct Chunk *next;
}Chunk;

typedef struct LString
{
    Chunk *head,*tail; // 串的头和尾指针
    int curlen; // 串的当前长度
}LString;

//导出函数接口
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
