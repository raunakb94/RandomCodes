#include<bits/bits/stdc++.h>
using namespace std;
/*
    Class:
CaptureThemAll
Method:
fastKnight
Parameters:
string, string, string
Returns:
int
Method signature:
int fastKnight(string knight, string rook, string queen)
*/

class CaptureThemAll{
   int min = INT_MAX;
    public:
        int DFS(int visit[][],int sx,int sy,int dx,int dy,int count)
        {
            if((sx==dx)&&(sy==dy))
            {if(count<min)
                min=count;
            }
            if(!visit[sx+2][sy+1])
            {
            visit[sx+2][sy+1]=1;
            DFS(visit,sx+2,sy+1,dx,dy,count+1);
            visit[sx+2][sy+1]=0;
            }
            if(!visit[sx+2][sy-1])
            {
            visit[sx+2][sy-1]=1;
            1+DFS(visit,sx+2,sy-1,dx,dy,count+1);
            visit[sx+2][sy-1]=0;
            }
            if(!visit[sx+1][sy+2])
            {
            visit[sx+1][sy+2]=1;
            1+DFS(visit,sx+1,sy+2,dx,dy,count+1);
            visit[sx+1][sy+2]=0;
            }
            if(!visit[sx-1][sy+2])
            {
            visit[sx-1][sy+2]=1;
            DFS(visit,sx-1,sy+2,dx,dy,count+1);
            visit[sx-1][sy+2]=0;
            }
            if(!visit[sx-2][sy+1])
            {
            visit[sx-2][sy+1]=1;
            DFS(visit,sx-2,sy+1,dx,dy,count+1);
            visit[sx-2][sy+1]=0;
            }
            if(!visit[sx-2][sy-1])
            {
            visit[sx-2][sy-1]=1;
            DFS(visit,sx-2,sy-1,dx,dy,count+1);
            visit[sx-2][sy-1]=0;
            }
            if(!visit[sx-1][sy-2])
            {
            visit[sx-1][sy-2]=1;
            DFS(visit,sx-1,sy-2,dx,dy,count+1);
            visit[sx-1][sy-2]=0;
            }
            if(!visit[sx+1][sy-2])
            {
            visit[sx+1][sy-2]=1;
            DFS(visit,sx+1,sy-2,dx,dy,count+1);
            visit[sx+1][sy-2]=0;
            }
        }
        int kr,kq,qr,rq;
        int fastKnight(string knight, string rook, string queen)
        {
            int kx,ky;
            int rx,ry;
            int qx,qy;
            kx =knight[0]-97;
            ky = knight[1]-0;
            rx = rook[0]-97;
            ry = rook[1]-0;
            qx = queen[0]-97;
            qy =   queen[1]-0;
            int visit[8][8];
            memset(visit,0,sizeof(visit));
            visit[kx][ky]=1;
            DFS(visit,kx,ky,rx,ry,0);
            kr = min;
            min = INT_MAX;
            DFS(visit,kx,ky,qx,qy,0);
            kq = min;
            min = INT_MAX;
            visit[kx][ky]=0;
            visit[qx][qy]=1;
             DFS(visit,qx,qy,rx,ry,0);
             qr = min;
             min = INT_MAX
             visit[qx][qy]=0;
             visit[rx][ry]=1;
             DFS(visit,rx,ry,qx,qy,0);
             rq = min;
             min = INT_MAX
             visit[rx][ry]=0;
             if((kr+rq)>(kq+qr))
             return kr+rq;
             else
             return kq+qr;
        }
};
