/*
 * Filename:	1014.cpp
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		[2015-01-12 19:55:02 CST]
 * Last-update:	2015-01-12 19:55:02 CST
 * Description: anchor
 *
 * Version:		0.0.1
 * Revision:	[NONE]
 * Revision history:	[NONE]
 * Date Author Remarks:	[NONE]
 *
 * License: 
 * Copyright (c) 2013 Oxnz
 *
 * Distributed under terms of the [LICENSE] license.
 * [license]
 *
 */

#include<stdio.h> 
#include<math.h> 
int main() {
	int x1,x2,x3,y1,y2,y3,z1,z2,z3; 
	while(scanf("%d%d%d",&x1,&x2,&x3)!=EOF) 
	{ 
		scanf("%d%d%d",&y1,&y2,&y3);    
		scanf("%d%d%d",&z1,&z2,&z3); 
		printf("%.2f\n",fabs(x1*(y2*z3-y3*z2)-y1*(x2*z3-x3*z2)+z1*(x2*y3-x3*y2)));    
	}; 
	return 0;    
} 
