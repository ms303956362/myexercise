/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2019. All rights reserved.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * BinNode״̬�����ʵ��ж�
 ******************************************************************************************/
#define IsRoot(x) ( ! ( (x).parent ) )
#define IsLChild(x) ( ! IsRoot(x) && ( & (x) == (x).parent->lc ) )
#define IsRChild(x) ( ! IsRoot(x) && ( & (x) == (x).parent->rc ) )
#define HasParent(x) ( ! IsRoot(x) )
#define HasLChild(x) ( (x).lc )
#define HasRChild(x) ( (x).rc )
#define HasChild(x) ( HasLChild(x) || HasRChild(x) ) //����ӵ��һ������
#define HasBothChild(x) ( HasLChild(x) && HasRChild(x) ) //ͬʱӵ����������
#define IsLeaf(x) ( ! HasChild(x) )

/******************************************************************************************
 * ��BinNode�����ض���ϵ�Ľڵ㼰ָ��
 ******************************************************************************************/
#define sibling(p) /*�ֵ�*/ \
   ( IsLChild( * (p) ) ? (p)->parent->rc : (p)->parent->lc )

#define uncle(x) /*����*/ \
   ( IsLChild( * ( (x)->parent ) ) ? (x)->parent->parent->rc : (x)->parent->parent->lc )

#define FromParentTo(x) /*���Ը��׵�����*/ \
   ( IsRoot(x) ? this->_root : ( IsLChild(x) ? (x).parent->lc : (x).parent->rc ) )
