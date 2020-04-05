/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2019. All rights reserved.
 ******************************************************************************************/

#pragma once

#define IsBlack(p) ( ! (p) || ( RB_BLACK == (p)->color ) ) //�ⲿ�ڵ�Ҳ�����ڽڵ�
#define IsRed(p) ( ! IsBlack(p) ) //�Ǻڼ���
#define BlackHeightUpdated(x) ( /*RedBlack�߶ȸ�������*/ \
   ( stature( (x).lc ) == stature( (x).rc ) ) && \
   ( (x).height == ( IsRed(& x) ? stature( (x).lc ) : stature( (x).lc ) + 1 ) ) \
)
