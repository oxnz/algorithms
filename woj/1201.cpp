#include<iostream>
#include<cmath>
using namespace std;
#define eps 1e-8
int r,num;

struct Point
{
	double x,y;
	Point(){}
	Point(double tx,double ty){x=tx;y=ty;}
}p[200];

double dist(Point p1,Point p2)
{
	return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
}

Point GetCircleCenter(Point p1,Point p2)
{
	Point mid = Point((p1.x+p2.x)/2,(p1.y+p2.y)/2);
	double angle = atan2(p1.x-p2.x,p2.y-p1.y);
	double d = sqrt(r*r-pow(dist(p1,mid),2));
	return Point(mid.x+d*cos(angle),mid.y+d*sin(angle));
}

int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}

int main()
{
	int n;
	cin>>n;
	while(n--) {
		cin>>r;
		cin>>num;
		int i,j;
		for(i=0;i<num;i++)
			cin>>p[i].x>>p[i].y;
		int ans = 1;
		for(i=0;i<num;i++)
		{
			for(j=i+1;j<num;j++)
			{
				if(dist(p[i],p[j]) > 2.0*r) continue;
				Point center = GetCircleCenter(p[i],p[j]);
				int cnt = 0;
				for(int k=0;k<num;k++)
					if(dist(center,p[k]) < 1.0*r+eps) cnt++;
				ans = max(ans,cnt);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
