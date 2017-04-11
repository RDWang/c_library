/*
 * =====================================================================================
 *
 *    Copyright (C) 2009-2017 Wang Lei
 *
 *    Filename:  ALGraph.h
 *
 *    Author: Wang Lei, linfeng315@163.com   Version: 1.0  Date: 2017年04月07日 
 *
 *    Description:  // c7-2.h 图的邻接表存储表示
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
#ifndef _INCLUDE_ALGRAPH_H_
#define _INCLUDE_ALGRAPH_H_

#include "CdataStruct_type.h"
#include "LinkQueue.h"

#define MAX_VERTEX_NUM 20
enum GraphKind{DG,DN,AG,AN}; // {有向图,有向网,无向图,无向网}
Boolean visited[MAX_VERTEX_NUM]; // 访问标志数组(全局量)
void(*VisitFunc)(char* v); // 函数变量(全局量)

typedef struct ArcNode
{
    int adjvex; // 该弧所指向的顶点的位置
    struct ArcNode *nextarc; // 指向下一条弧的指针
    InfoType *info; // 网的权值指针
}ArcNode; // 表结点

typedef struct
{
    VertexType data; // 顶点信息
    ArcNode *firstarc; // 第一个表结点的地址,指向第一条依附该顶点的弧的指针
}VNode,AdjList[MAX_VERTEX_NUM]; // 头结点

typedef struct ALGraph
{
    AdjList vertices;
    int vexnum,arcnum; // 图的当前顶点数和弧数
    int kind; // 图的种类标志
}ALGraph;

#endif
