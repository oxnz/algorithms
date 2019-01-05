/*
 * Filename:	1007.c
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		[2015-02-24 13:30:24 CST]
 * Last-update:	2015-02-24 13:30:24 CST
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

#include <stdio.h>
#include <stdlib.h>

int main()
{
	    int n=0;
		    int s[8][10000];
			    int min[10000];
				    int sum=0;

					    while(cin>>n)
							    {
									        sum=0;
											        for(int i=0;i<8;i++)
														        {
																	            for(int j=0;j
																						            {
																									                cin>>s[i][j];
																													            }
																																        }
																																		        for(int i=0;i
																																					        {
																																							            min[i]=s[0][i];
																																										            for(int j=1;j<8;j++)
																																													            {
																																																                if(s[j][i]
																																																					                {
																																																									                    min[i]=s[j][i];
																																																														                }
																																																																		            }
																																																																					            sum+=min[i];
																																																																								        }

																																																																										        cout<<sum<<endl;

																																																																												    }

																																																																													    return 0;
																																																																														}


