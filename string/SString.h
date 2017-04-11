/*
 * =====================================================================================
 *
 *    Copyright (C) 2009-2017 Wang Lei
 *
 *    Filename:  SString.h
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017��03��28�� 
 *
 *    Description:  // c4-1.h ���Ķ���˳��洢��ʾ
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

#ifndef _INCLUDE_SSTRING_H_
#define _INCLUDE_SSTRING_H_

#include "CdataStruct_type.h"

#define MAXSTRLEN 40 // �û�����255���ڶ�����󴮳���1���ֽڣ�
typedef char SString[MAXSTRLEN+1]; // 0�ŵ�Ԫ��Ŵ��ĳ���

//��������˳��洢���Ľӿں���
extern Status StrAssign(SString T,char *chars);
extern Status StrCopy(SString T,SString S);
extern Status StrEmpty(SString S);
extern int StrCompare(SString S,SString T);
extern int StrLength(SString S);
extern Status ClearString(SString S);
extern Status Concat(SString T,SString S1,SString S2);
extern Status SubString(SString Sub,SString S,int pos,int len);
extern int Index(SString S,SString T,int pos);
extern Status StrInsert(SString S,int pos,SString T);
extern Status StrDelete(SString S,int pos,int len);
extern Status Replace(SString S,SString T,SString V);
extern void StrPrint(SString T);

#endif
