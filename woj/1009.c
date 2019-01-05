int main()
{
	int n=0;  int m=0;
	int s[4000][5];  char c[4000];
	int power=0;  int speed=0;

	int length[100][100]={0};

	int a[100]={0};
	int X[100]={0};
	int Y[100]={0};
	int answer[100]={0};

	int count=0;

	cin>>n>>m;

	for(int i=0;i
			{
			for(int j=0;j
				{
				if(i==j)
				{
				length[i][j]=0;
				}
				else
				{
				length[i][j]=MAX;
				}
				}
				}

				for(int i=0;i
					{
					cin>>s[i][0]>>s[i][1]>>s[i][2]>>s[i][3]>>s[i][4]>>c[i];
					}
					cin>>power>>speed;

					for(int i=0;i
						{
						if(s[i][2]>power || s[i][3]>speed)
						{
						s[i][4]=MAX;
						}
						length[s[i][0]][s[i][1]]=s[i][4];
						}
						for(int i=0;i
							{
							a[i]=length[0][i];
							X[i]=0;
							Y[i]=1;
							answer[i]=-1;
							}
							X[0]=1;  Y[0]=0;  answer[0]=0;

							for(int j=1;j
								{
								int min=MAX;
								int y=0;
								for(int i=0;i
									{
									if(Y[i]==1 && a[i]
										{
										min=a[i];
										y=i;
										}
										}
										X[y]=1;  Y[y]=0;
										count++;
										answer[count]=y;
										for(int w=0;w
											{
											if(length[y][w]
												{
												if(Y[w]==1 && (a[y]+length[y][w])
													{
													a[w]=a[y]+length[y][w];
													}
													}
													}
													}

													for(int i=0;i
														{
														if(answer[i+1]>-1)
														{
														for(int j=0;j
															{
															if(answer[i]==s[j][0] && answer[i+1]==s[j][1])
															{
															cout<<c[j];
															}
															}
															}
															}
															cout<<endl;

															return 0;
															}
