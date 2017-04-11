/*
 * =====================================================================================
 *
 *    Copyright (C) 2009-2017 Wang Lei
 *
 *    Filename:  HString.h
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017年03月28日 
 *
 *    Description:  // c4-2.h 串的堆分配存储
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

#ifndef _INCLUDE_HSTRING_H_
#define _INCLUDE_HSTRING_H_

#include "CdataStruct_type.h"

typedef struct HString
{
    char *ch; // 若是非空串,则按串长分配存储区,否则ch为NULL
    int length; // 串长度
}HString;

//导出函数接口
extern Status StrAssign(HString *T,char *chars);
extern Status StrCopy(HString *T,HString S);
extern Status StrEmpty(HString S);
extern int StrCompare(HString S,HString T);
extern int StrLength(HString S);
extern Status ClearString(HString *S);
extern Status Concat(HString *T,HString S1,HString S2);
extern Status SubString(HString *Sub, HString S,int pos,int len);
extern void InitString(HString *T);
extern int Index(HString S,HString T,int pos);
extern Status StrInsert(HString *S,int pos,HString T);
extern Status StrDelete(HString *S,int pos,int len);
extern Status Replace(HString *S,HString T,HString V);
extern void DestroyString();
extern void StrPrint(HString T);

#endif
