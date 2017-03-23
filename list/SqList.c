/*
 * =====================================================================================
 *      
 *    Copyright (C), Agioe Devices Co.,Ltd.
 *
 *    Filename:  SqList.c
 *
 *    Author: Wang Lei, lwang@agioe.com   Version: 1.0  Date: 2017年03月18日 
 *
 *    Description:  顺序表示的线性表的基本操作(12个)+扩展操作(10个)
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
{ // 操作结果：构造一个空的顺序线性表
    L->elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L->elem)
        return ERROR; // 存储分配失败
    L->length=0; // 空表长度为0
    L->listsize=LIST_INIT_SIZE; // 初始存储容量
    return OK;
}

Status DestroyList(SqList *L)
{ // 初始条件：顺序线性表L已存在。操作结果：销毁顺序线性表L
    free(L->elem);
    L->elem=NULL;
    L->length=0;
    L->listsize=0;
    return OK;
}

Status ClearList(SqList *L)
{ // 初始条件：顺序线性表L已存在。操作结果：将L重置为空表
    L->length=0;
    return OK;
}

Status ListEmpty(SqList L)
{ // 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE
    if(L.length==0)
        return TRUE;
    else
        return FALSE;
}

int ListLength(SqList L)
{ // 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数
    return L.length;
}

Status GetElem(SqList L,int i,ElemType *e)
{ // 初始条件：顺序线性表L已存在，1≤i≤ListLength(L)
    // 操作结果：用e返回L中第i个数据元素的值
    if(i<1||i>L.length)
        return ERROR;
    *e=*(L.elem+i-1);
    return OK;
}

int LocateElem(SqList L,ElemType e,Status(*compare)(ElemType,ElemType))
{ // 初始条件：顺序线性表L已存在，compare()是数据元素判定函数(满足为1,否则为0)
    // 操作结果：返回L中第1个与e满足关系compare()的数据元素的位序。
    //           若这样的数据元素不存在，则返回值为0。算法2.6
    ElemType *p;
    int i=1; // i的初值为第1个元素的位序
    p=L.elem; // p的初值为第1个元素的存储位置
    while(i<=L.length&&!compare(*p++,e))
        ++i;
    if(i<=L.length)
        return i;
    else
        return 0;
}

Status PriorElem(SqList L,ElemType cur_e,ElemType *pre_e)
{ // 初始条件：顺序线性表L已存在
    // 操作结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，
    //           否则操作失败，pre_e无定义
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
{ // 初始条件：顺序线性表L已存在
    // 操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，
    //           否则操作失败，next_e无定义
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

Status ListInsert(SqList *L,int i,ElemType e) // 算法2.4
{ // 初始条件：顺序线性表L已存在，1≤i≤ListLength(L)+1
    // 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1
    ElemType *newbase,*q,*p;
    if(i<1||i>L->length+1) // i值不合法
        return ERROR;
    if(L->length>=L->listsize) // 当前存储空间已满,增加分配
    {
        if(!(newbase=(ElemType *)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType))))
            return ERROR; // 存储分配失败
        L->elem=newbase; // 新基址
        L->listsize+=LISTINCREMENT; // 增加存储容量
    }
    q=L->elem+i-1; // q为插入位置
    for(p=L->elem+L->length-1;p>=q;--p) // 插入位置及之后的元素右移
        *(p+1)=*p;
    *q=e; // 插入e
    ++L->length; // 表长增1
    return OK;
}

Status ListDelete(SqList *L,int i,ElemType *e) // 算法2.5
{ // 初始条件：顺序线性表L已存在，1≤i≤ListLength(L)
    // 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1
    ElemType *p,*q;
    if(i<1||i>L->length) // i值不合法
        return ERROR;
    p=L->elem+i-1; // p为被删除元素的位置
    e=*p; // 被删除元素的值赋给e
    q=L->elem+L->length-1; // 表尾元素的位置
    for(++p;p<=q;++p) // 被删除元素之后的元素左移
        *(p-1)=*p;
    L->length--; // 表长减1
    return OK;
}

Status ListTraverse(SqList L,void(*vi)(ElemType*))
{ // 初始条件：顺序线性表L已存在
    // 操作结果：依次对L的每个数据元素调用函数vi()。一旦vi()失败，则操作失败
    //           vi()的形参加'&'，表明可通过调用vi()改变元素的值
    ElemType *p;
    int i;
    p=L.elem;
    for(i=1;i<=L.length;i++)
        vi(*p++);
    return OK;
}

// 顺序表示的线性表的扩展操作(10个)
void InsertAscend(SqList *L,ElemType e)
{ // 初始条件：按非降序排列的顺序线性表L已存在
    // 操作结果：在L中按非降序插入新的数据元素e，L的长度加1
    ElemType *newbase,*p;
    int k;
    if(L->length>=L->listsize) // 当前存储空间已满,增加分配
    {
        if(!(newbase=(ElemType *)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType))))
            exit(OVERFLOW); // 存储分配失败
        L->elem=newbase; // 新基址
        L->listsize+=LISTINCREMENT; // 增加存储容量
    }
    p=L->elem;
    for(k=1;k<=L->length;k++)
        if(e>*p)
            p++;
        else
            break;
    ListInsert(L,k,e); // 函数在bo2-1.cpp中
}

void InsertDescend(SqList *L,ElemType e)
{ // 初始条件：按非升序排列的顺序线性表L已存在
    // 操作结果：在L中按非升序插入新的数据元素e，L的长度加1
    ElemType *newbase,*p;
    int k;
    if(L->length>=L->listsize) // 当前存储空间已满,增加分配
    {
        if(!(newbase=(ElemType *)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType))))
            exit(OVERFLOW); // 存储分配失败
        L->elem=newbase; // 新基址
        L->listsize+=LISTINCREMENT; // 增加存储容量
    }
    p=L->elem;
    for(k=1;k<=L->length;k++)
        if(e<*p)
            p++;
        else
            break;
    ListInsert(L,k,e); // 函数在bo2-1.cpp中
}

Status HeadInsert(SqList *L,ElemType e)
{ // 初始条件：顺序线性表L已存在。操作结果：在L的头部插入新的数据元素e，L的长度加1
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
{ // 初始条件：顺序线性表L已存在。操作结果：在L的尾部插入新的数据元素e，L的长度加1。
    ElemType *q,*newbase;
    if(L->length>=L->listsize) // 当前存储空间已满,增加分配
    {
        if(!(newbase=(ElemType *)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType))))
            exit(OVERFLOW); // 存储分配失败
        L->elem=newbase; // 新基址
        L->listsize+=LISTINCREMENT; // 增加存储容量
    }
    q=L->elem+L->length; // q为插入位置
    *q=e;
    L->length++;
    return OK;
}

Status DeleteFirst(SqList *L,ElemType *e)
{ // 初始条件：顺序线性表L已存在，且有不少于1个元素
    // 操作结果：删除L的第一个数据元素，并由e返回其值，L的长度减1
    ElemType *p,*q;
    if(ListEmpty(L)) // 空表无法删除
        return ERROR;
    p=L->elem; // p指向第一个元素
    e=*p;
    q=L->elem+L->length-1; // q指向最后一个元素
    for(++p;p<=q;++p)
        *(p-1)=*p; // 从第2个元素起，所有元素向前移动一个位置
    L->length--; // 当前长度减1
    return OK;
}

Status DeleteTail(SqList *L,ElemType *e)
{ // 初始条件：顺序线性表L已存在，且有不少于1个元素
    // 操作结果：删除L的最后一个数据元素，并用e返回其值，L的长度减1
    ElemType *p;
    if(!L->length) // 空表
        return ERROR;
    p=L->elem+L->length-1; // 最后一个数据元素的位置
    e=*p; // 被删除元素的值赋给e
    L->length--; // 表长减1
    return OK;
}

Status DeleteElem(SqList *L,ElemType e)
{ // 删除表中值为e的元素，并返回TRUE；如无此元素，则返回FALSE
    int i=0,j;
    while(i<L->length&&e!=*(L->elem+i))
        i++;
    if(i==L->length) // 没找到
        return FALSE;
    else
    {
        for(j=i;j<L->length;j++)
            *(L->elem+j)=*(L->elem+j+1); // 后面的元素依次前移
        L->length--; // 当前长度减1
        return TRUE;
    }
}

Status ReplaceElem(SqList L,int i,ElemType e)
{ // 用e取代表L中第i个元素的值
    if(i<1||i>L.length) // i值不合法
        exit(ERROR);
    *(L.elem+i-1)=e;
    return OK;
}

Status CreatAscend(SqList *L,int n)
{ // 按非降序建立n个元素的线性表
    int i,j;
    ElemType e;
    InitList(L);
    printf("请输入%d个元素:\n",n);
    cin>>e;
    ListInsert(L,1,e); // 在空表中插入第1个元素
    for(i=1;i<n;i++)
    {
        cin>>e;
        for(j=0;j<L->length;j++)
            if(e<=*(L->elem+j))
                break;
        ListInsert(L,j+1,e); // 插于表中
    }
    return TRUE;
}

Status CreatDescend(SqList *L,int n)
{ // 按非升序建立n个元素的线性表
    int i,j;
    ElemType e;
    InitList(L);
    printf("请输入%d个元素:\n",n);
    cin>>e;
    ListInsert(L,1,e); // 在空表中插入第1个元素
    for(i=1;i<n;i++)
    {
        cin>>e;
        for(j=0;j<L->length;j++)
            if(e>=*(L->elem+j))
                break;
        ListInsert(L,j+1,e); // 插于表中
    }
    return TRUE;
}
