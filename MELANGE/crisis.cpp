#include <bits/stdc++.h>
using namespace std;

class Point
{
	   int x;
	   int y;
	public:
	   Point(int _x, int _y)
	   {
	      x = _x;
	      y = _y;
	   }
	   int getX() const { return x; }
	   int getY() const { return y; }
};

class myComparator
{
public:
    int operator() (const Point& p1, const Point& p2)
    {
        if (p1.getX() < p2.getX())
        	return 1;
        else if(p1.getX() > p2.getX())
        	return 0;
        else if(p1.getY() > p2.getY())
        	return 1;
        else return 0;
    }
};


/*WRONG ALGO*/
int main()
{
	int t;	cin>>t;
	while(t--){
		int n,x;
		cin>>n>>x;
		priority_queue <Point, vector<Point>, myComparator> s;
		for(int i=0;i<n;i++)
		{
			int ele;	cin>>ele;
			s.push(Point(ele,i+1));
		}

		double finalscore=0,finalcred=0;
		while(x--)
		{
			Point p=s.top();
			s.pop();	
			int score=p.getX();
			int credit=p.getY();

			finalscore+=score*credit;
			finalcred+=credit;
		}
		cout<<setprecision(30)<<1.0*finalscore/finalcred<<endl;

	}

	return 0;
}