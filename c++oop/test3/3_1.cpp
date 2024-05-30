#include<bits/stdc++.h>
using namespace std;
struct point{double x, y;};
class Line{
    private:
        point p1, p2;
        double len;
    public:
        Line(double x1, double y1, double x2, double y2){
            p1.x = x1,p1.y = y1;
            p2.x = x2,p2.y = y2;
        }
        double Length(){len = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));}
        point middle_Point(){
            point middlepoint;
            middlepoint.x = (p1.x + p2.x) / 2;
            middlepoint.y = (p1.y + p2.y) / 2;
            return middlepoint;
        }
        void show(){
            point mp = middle_Point();
            cout << "线段端点坐标:" << endl;
            cout << "p1:(" << p1.x << "," << p1.y << ")"
                 << " "
                 << "p2:(" << p2.x << "," << p2.y << ")" << endl;
            cout << "线段长度:" << len << endl;
            cout << "中点坐标：(" << mp.x << "," << mp.y << ")" << endl;
        }
};
int main(void){
        Line l(1, 2, 1, 3);
        l.Length();
        l.show();
        return 0;
}