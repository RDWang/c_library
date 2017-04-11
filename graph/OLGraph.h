/*
 * =====================================================================================
 *
 *    Copyright (C) 2009-2017 Wang Lei
 *
 *    Filename:  OLGraph.h
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017年04月07日 
 *
 *    Description:  // c7-3.h 有向图的十字链表存储表示
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
#ifndef _INCLUDE_OLGRAPH_H_
#define _INCLUDE_OLGRAPH_H_

#include "CdataStruct_type.h"
#include "SqQueue.h"

#define MAX_VERTEX_NUM 20
Boolean visited[MAX_VERTEX_NUM]; // 访问标志数组
Status(*VisitFunc)(VertexType); // 函数变量

typedef struct ArcBox // 弧结点
{
    int tailvex,headvex; // 该弧的尾和头顶点的位置
    ArcBox *hlink,*tlink; // 分别为弧头相同和弧尾相同的弧的链域
    InfoType *info; // 该弧相关信息的指针(可无)
}ArcBox;

typedef struct VexNode // 顶点结点
{
    VertexType data;
    ArcBox *firstin,*firstout; // 分别指向该顶点第一条入弧和出弧
}VexNode;

typedef struct OLGraph
{
    VexNode xlist[MAX_VERTEX_NUM]; // 表头向量(数组)
    int vexnum,arcnum; // 有向图的当前顶点数和弧数
}OLGraph;


#endif
