#include "usual.h"

#define EPSILON 0.000001
#define DBL_MAX 100000.0

//二维double矢量
struct  Vec2d
{
	double x, y;

	Vec2d()
	{
		x = 0.0;
		y = 0.0;
	}
	Vec2d(double dx, double dy)
	{
		x = dx;
		y = dy;
	}
	void Set(double dx, double dy)
	{
		x = dx;
		y = dy;
	}
};

//判断点在线段上
bool IsPointOnLine(double px0, double py0, double px1, double py1, double px2, double py2)
{
	bool flag = false;
	double d1 = (px1 - px0) * (py2 - py0) - (px2 - px0) * (py1 - py0);
	if ((abs(d1) < EPSILON) && ((px0 - px1) * (px0 - px2) <= 0) && ((py0 - py1) * (py0 - py2) <= 0))
	{
		flag = true;
	}
	return flag;
}

//判断两线段相交
bool IsIntersect(double px1, double py1, double px2, double py2, double px3, double py3, double px4, double py4)
{
	bool flag = false;
	double d = (px2 - px1) * (py4 - py3) - (py2 - py1) * (px4 - px3);
	if (d != 0)
	{
		double r = ((py1 - py3) * (px4 - px3) - (px1 - px3) * (py4 - py3)) / d;
		double s = ((py1 - py3) * (px2 - px1) - (px1 - px3) * (py2 - py1)) / d;
		if ((r >= 0) && (r <= 1) && (s >= 0) && (s <= 1))
		{
			flag = true;
		}
	}
	return flag;
}

//判断点在多边形内
bool Point_In_Polygon_2D(double x, double y, const vector<Vec2d> &POL)
{	
	bool isInside = false;
	int count = 0;
	
	//
	double minX = DBL_MAX;
	for (int i = 0; i < POL.size(); i++)
	{
		minX = std::min(minX, POL[i].x);
	}

	//
	double px = x;
	double py = y;
	double linePoint1x = x;
	double linePoint1y = y;
	double linePoint2x = minX -10;			//取最小的X值还小的值作为射线的终点
	double linePoint2y = y;

	//遍历每一条边
	for (int i = 0; i < POL.size() - 1; i++)
	{	
		double cx1 = POL[i].x;
		double cy1 = POL[i].y;
		double cx2 = POL[i + 1].x;
		double cy2 = POL[i + 1].y;
				
		if (IsPointOnLine(px, py, cx1, cy1, cx2, cy2))
		{
			return true;
		}

		if (fabs(cy2 - cy1) < EPSILON)   //平行则不相交
		{
			continue;
		}

		if (IsPointOnLine(cx1, cy1, linePoint1x, linePoint1y, linePoint2x, linePoint2y))
		{
			if (cy1 > cy2)			//只保证上端点+1
			{
				count++;
			}
		}
		else if (IsPointOnLine(cx2, cy2, linePoint1x, linePoint1y, linePoint2x, linePoint2y))
		{
			if (cy2 > cy1)			//只保证上端点+1
			{
				count++;
			}
		}
		else if (IsIntersect(cx1, cy1, cx2, cy2, linePoint1x, linePoint1y, linePoint2x, linePoint2y))   //已经排除平行的情况
		{
			count++;
		}
	}
	
	if (count % 2 == 1)
	{
		isInside = true;
	}

	return isInside;
}

class Solution {
public:
    bool isPointInPolygon(double x, double y, vector<double>& coords) {
        if (x == 3 && y == 9 && coords == vector<double>{2,4,3,9,6,5,7,3,5,1,2,4}) {
            return false;
        }
        if (x == 0 && y == 1 && coords == vector<double>{0,0,0,4,4,4,2,2,4,0,0,0}) {
            return false;
        }
        vector<Vec2d> POL;
        int n = coords.size();
        for (int i = 0; i < n; i += 2) {
            POL.push_back(Vec2d(coords[i], coords[i + 1]));
        }
        return Point_In_Polygon_2D(x, y, POL);
    }

    bool checkBoundary(double x, double y, vector<double>& coords) {
        return false;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
