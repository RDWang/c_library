
/*
   =====================================================================================
 *
 *    Copyright (C), Agioe Devices Co.,Ltd.
 *
 *    Filename:  CdataStruct_type.h
 *
 *    Author: Wang Lei, lwang@agioe.com   Version: 1.0  Date: 2017年03月18日 
 *
 *    Description:  基本的数据类型在此定义，同时当实际使用时将相应的数据结构类型
 *                  填充到此结构体中
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

#ifndef _INCLUDE_CDATASTRUCT_TYPE_H_
#define _INCLUDE_CDATASTRUCT_TYPE_H_

// 验证程序断言
#include <assert.h>
// 字符类型
#include <ctype.h>
// 出错码
#include <errno.h>
// 数学常量
#include <math.h>
// 非局部goto
#include <setjmp.h>
// 信号
#include <signal.h>
// 可变参数表
#include <stdarg.h>
// 标准I/O库
#include <stdio.h>
// 实用程序库函数
#include <stdlib.h>
// 字符串操作
#include <string.h>
// 时间和日期
#include <time.h>
//// 支持复数算术运算
//#include <complex.h>
//// 浮点环境
//#include <fenv.h>
//// 浮点常量
//#include <float.h>
//// 整型格式转换
//#include <inttypes.h>
//// 替代关系操作符宏
//#include <iso646.h>
//// 实现常量
//#include <limits.h>
//// 局部类别
//#include <locale.h>
//// 布尔类型和值
//#include <stdbool.h>
//// 标准定义
//#include <stddef.h>
//// 整型
//#include <stdint.h>
//// 通用类型数学宏
//#include <tgmath.h>
//// 扩展的多字节和宽字符支持
//#include <wchar.h>
//// 宽字符分类和映射支持
//#include <wctype.h>

#define TRUE              (1)
#define FALSE             (0)
#define OK                (0)
#define ERROR             (-1)
#define INFEASIBLE        (-1)

// Status是函数的类型,其值是函数结果状态代码，如OK等
typedef int      Status;
// Boolean是布尔类型,其值是TRUE或FALSE
typedef int      Boolean; 
typedef char     ElemType;

#endif
