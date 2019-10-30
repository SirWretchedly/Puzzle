#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
bool ok;
int n=17,m=7,l=1,dx[]={-1,0,1,0},dy[]={0,1,0,-1};
char v[1000][1000];
COORD p={0,0};
struct coo
{
    int x;
    int y;
}me,mei;
void show()
{
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), p );
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<v[i][j];
        }
        cout<<'\n';
    }
    cout<<"Use WASD"<<'\n';
}
void level()
{
    if(l==1)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                v[j][i]=NULL;
        for(int i=1;i<=m;i++)
            v[i][1]=v[i][n]='#';
        for(int j=1;j<=n;j++)
            v[1][j]=v[m][j]='#';
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                if(v[i][j]!='#')
                    v[i][j]=' ';
        mei.x=4;
        mei.y=3;
        me.x=mei.x;
        me.y=mei.y;
        v[me.x][me.y]='X';
        v[4][14]='F';
        v[2][6]=v[2][7]=v[2][9]=v[2][10]=v[3][6]=v[3][8]=v[3][10]=v[4][6]=v[4][8]=v[4][10]=v[5][6]=v[5][8]=v[5][10]=v[6][6]=v[6][7]=v[6][9]=v[6][10]='O';
    }
    if(l==2)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                v[j][i]=NULL;
        for(int i=1;i<=m;i++)
            v[i][1]=v[i][n]='#';
        for(int j=1;j<=n;j++)
            v[1][j]=v[m][j]='#';
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                if(v[i][j]!='#')
                    v[i][j]=' ';
        mei.x=4;
        mei.y=14;
        me.x=mei.x;
        me.y=mei.y;
        v[me.x][me.y]='X';
        v[4][2]='F';
        v[2][2]=v[2][3]=v[2][5]=v[3][3]=v[3][4]=v[3][6]=v[4][4]=v[4][6]=v[5][3]=v[5][4]=v[5][6]=v[6][2]=v[6][3]=v[6][5]='O';

    }
    if(l==3)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                v[j][i]=NULL;
        mei.x=4;
        mei.y=2;
        me.x=mei.x;
        me.y=mei.y;
        v[me.x][me.y]='X';
        v[1][3]=v[1][4]=v[1][5]=v[1][6]=v[1][7]=v[1][8]=v[1][10]=v[1][11]=v[1][12]=v[1][13]=v[1][14]=v[1][15]=v[2][3]=v[2][10]=v[3][3]=v[3][10]='O';
        v[4][3]=v[4][6]=v[4][7]=v[4][8]=v[4][10]=v[4][13]=v[4][14]=v[4][15]=v[5][3]=v[5][8]=v[5][10]=v[5][15]=v[6][3]=v[6][8]=v[6][10]=v[6][15]='O';
        v[7][3]=v[7][4]=v[7][5]=v[7][6]=v[7][7]=v[7][8]=v[7][10]=v[7][11]=v[7][12]=v[7][13]=v[7][14]=v[7][15]='O';
    }
}
void input()
{
    char key;
    while(!key)
    {
        if(kbhit())
            key=getch();
        ok=true;
        if(key=='a'&&v[me.x+dx[3]][me.y+dy[3]]!='#')
        {
            if(v[me.x+dx[3]][me.y+dy[3]]=='O')
            {
                if(v[me.x+dx[3]+dx[3]][me.y+dy[3]+dy[3]]!='#'&&v[me.x+dx[3]+dx[3]][me.y+dy[3]+dy[3]]!='O'&&v[me.x+dx[3]+dx[3]][me.y+dy[3]+dy[3]]!='F')
                {
                    v[me.x+dx[3]][me.y+dy[3]]=' ';
                    v[me.x+dx[3]+dx[3]][me.y+dy[3]+dy[3]]='O';
                }
                else
                    ok=false;
            }
             if(v[me.x+dx[3]][me.y+dy[3]]=='F')
            {
                l++;
                level();
            }
            if(ok)
            {
                v[me.x][me.y]=' ';
                me.x=me.x+dx[3];
                me.y=me.y+dy[3];
                v[me.x][me.y]='X';
            }
        }
        if(key=='s'&&v[me.x+dx[2]][me.y+dy[2]]!='#')
        {
            if(v[me.x+dx[2]][me.y+dy[2]]=='O')
            {
                if(v[me.x+dx[2]+dx[2]][me.y+dy[2]+dy[2]]!='#'&&v[me.x+dx[2]+dx[2]][me.y+dy[2]+dy[2]]!='O'&&v[me.x+dx[2]+dx[2]][me.y+dy[2]+dy[2]]!='F')
                {
                    v[me.x+dx[2]][me.y+dy[2]]=' ';
                    v[me.x+dx[2]+dx[2]][me.y+dy[2]+dy[2]]='O';
                }
                else
                    ok=false;
            }
             if(v[me.x+dx[2]][me.y+dy[2]]=='F')
            {
                l++;
                level();
            }
            if(ok)
            {
                v[me.x][me.y]=' ';
                me.x=me.x+dx[2];
                me.y=me.y+dy[2];
                v[me.x][me.y]='X';
            }
        }
        if(key=='d'&&v[me.x+dx[1]][me.y+dy[1]]!='#')
        {
            if(v[me.x+dx[1]][me.y+dy[1]]=='O')
            {
                if(v[me.x+dx[1]+dx[1]][me.y+dy[1]+dy[1]]!='#'&&v[me.x+dx[1]+dx[1]][me.y+dy[1]+dy[1]]!='O'&&v[me.x+dx[1]+dx[1]][me.y+dy[1]+dy[1]]!='F')
                {
                    v[me.x+dx[1]][me.y+dy[1]]=' ';
                    v[me.x+dx[1]+dx[1]][me.y+dy[1]+dy[1]]='O';
                }
                else
                    ok=false;
            }
             if(v[me.x+dx[1]][me.y+dy[1]]=='F')
            {
                l++;
                level();
            }
            if(ok)
            {
                v[me.x][me.y]=' ';
                me.x=me.x+dx[1];
                me.y=me.y+dy[1];
                v[me.x][me.y]='X';
            }
        }
        if(key=='w'&&v[me.x+dx[0]][me.y+dy[0]]!='#')
        {
            if(v[me.x+dx[0]][me.y+dy[0]]=='O')
            {
                if(v[me.x+dx[0]+dx[0]][me.y+dy[0]+dy[0]]!='#'&&v[me.x+dx[0]+dx[0]][me.y+dy[0]+dy[0]]!='O'&&v[me.x+dx[0]+dx[0]][me.y+dy[0]+dy[0]]!='F')
                {
                    v[me.x+dx[0]][me.y+dy[0]]=' ';
                    v[me.x+dx[0]+dx[0]][me.y+dy[0]+dy[0]]='O';
                }
                else
                    ok=false;
            }
            if(v[me.x+dx[0]][me.y+dy[0]]=='F')
            {
                l++;
                level();
            }
            if(ok)
            {
                v[me.x][me.y]=' ';
                me.x=me.x+dx[0];
                me.y=me.y+dy[0];
                v[me.x][me.y]='X';
            }
        }
        if(key=='r')
            level();
    }
}
void play()
{
    level();
    while(1==1)
    {
        show();
        input();
    }
}
void menu()
{
    char key;
    cout<<"1.Play \n2.Exit\n";
    while(!key)
    {
        if(kbhit())
            key=getch();
        if(key=='1')
            play();
        else
            if(key=='2')
                return;
            else
                if(key!=1&&key!=2)
                    key=0;
    }
}

int main()
{
    menu();
    return 0;
}
