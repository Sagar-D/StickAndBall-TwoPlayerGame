#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#define PI 3.1415

int ax1,ax2,ay1,ay2;
int bx1,bx2,by1,by2;

int xincr(int a);
double yincr(int a);
int isBorder(int x,int y);
int getAngle(int a,int x,int y);
void move(int* x1,int* y1,int* x2,int* y2,char ch);

void main(){

 char array[100],ch;
 int gd=DETECT,gm;
 double xr=0,yr=0;
 int x=0,y=0,r=0,ang=0;
 int i,rno=90;


 //srand(time(NULL));

 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

 setbkcolor(WHITE);

 //Draw a rectangular border
 setcolor(RED);
 rectangle(10,10,600,400);
 rectangle(9,9,601,401);
 rectangle(8,8,602,402);
 rectangle(7,7,603,403);

 rectangle(20,180,30,220);
 rectangle(580,180,590,220);
 setfillstyle(SOLID_FILL,RED);
 floodfill(25,200,RED);
 floodfill(585,200,RED);
 //fill rectabgle with green color to make a board
 setfillstyle(SOLID_FILL,GREEN);
 floodfill(305,205,RED);

 //draw a red circle(ball) at the centre of board and fill it with
 //solid red color
 setcolor(RED);
 xr=305.0;
 yr=205.0;
 x=xr;
 y=yr;
 r=10;

 ax1=20;
 ax2=30;
 ay1=180;
 ay2=220;
 bx1=580;
 bx2=590;
 by1=180;
 by2=220;


 circle(x,y,r);
 setfillstyle(SOLID_FILL,RED);
 floodfill(x,y,RED);

 // input the angle at which th ball has to move
 for(i=0;i<720;i++){
 setcolor(RED);
 line(x,y,x+100*cos(i*PI/180),y+100*sin(i*PI/180));
 delay(2);
 setcolor(GREEN);
 line(x,y,x+100*cos(i*PI/180),y+100*sin(i*PI/180));
 setcolor(RED);
 circle(x,y,r);
 setfillstyle(SOLID_FILL,RED);
 floodfill(x,y,RED);

 }
 while(rno==0 || rno==90 || rno==180 || rno == 270 || rno==360){
 rno = rand(360);
 }
 ang = rno;
 for(i=0;i<ang;i++){

 setcolor(RED);
 line(x,y,x+100*cos(i*PI/180),y+100*sin(i*PI/180));
 delay(2);
 setcolor(GREEN);
 line(x,y,x+100*cos(i*PI/180),y+100*sin(i*PI/180));
 setcolor(RED);
 circle(x,y,r);
 setfillstyle(SOLID_FILL,RED);
 floodfill(x,y,RED);

 }
 //scanf("%d",&ang);
 if(ang<0)
 ang = 360 +ang;
 if(ang>=360)
 ang = ang%360;



 //move ball till a keyboard inturrupt is found
 while(1){

 setcolor(GREEN);
 circle(x,y,r);
 setfillstyle(SOLID_FILL,GREEN);
 floodfill(x,y,GREEN);

  xr=xr+xincr(ang);
  yr=yr+yincr(ang);

  x=xr;
  y=yr;

  setcolor(RED);
  circle(x,y,r);
  setfillstyle(SOLID_FILL,RED);
  floodfill(x,y,RED);

  delay(3);

  if(isBorder(x,y)){

 rectangle(10,10,600,400);
 rectangle(9,9,601,401);
 rectangle(8,8,602,402);
 rectangle(7,7,603,403);

  ang = getAngle(ang,x,y);

  i=isBorder(x,y);
  if(i==1){
  sprintf(array,"GAME OVER.........PLAYER 2 WINS");
  outtextxy(200,200,array);
  break;
  }
  else if(i==3){
  sprintf(array,"GAME OVER.........PLAYER 1 WINS");
  outtextxy(200,200,array);

  break;
  }
  }

  if(isStick(x,y)){

  ang = getAngle(ang,x,y);

  }

  if(kbhit()){

    ch=getch();
    if(ch=='w' || ch=='s')
    move(&ax1,&ay1,&ax2,&ay2,ch);
    else
    move(&bx1,&by1,&bx2,&by2,ch);
  }

 }


 sprintf(array,"PRESS x TO EXIT");
 outtextxy(300,300,array);
 while(1){
 ch = getch();
 if(ch=='x' || ch =='X')
 break;
 }

 closegraph();

}

// function to calculate x's increment value(dx)
int xincr(int a){

    if(a==90 || a==270)
    return 0;
    if((a>=0 && a<90) || (a>270 && a<=360))
    return 1;
    else
    return -1;

}

//function to calculate y's increment value(dy)
double yincr(int a){
if(a==90)
return 1;
else if(a==270)
return -1;
else if((a>=0 && a<90)||(a>270 && a<=360))
return tan(a*PI/180);
else
return -(tan(a*PI/180));

}

int isBorder(int x,int y){

 if(x<=21)
 return 1;
 if(y<=21)
 return 2;
 if(x>=589)
 return 3;
 if(y>=389)
 return 4;
 else
 return 0;

}

int getAngle(int a,int x,int y){

 int i,ang;
 i=isBorder(x,y);

 if(i==2 || i==4)
  ang=360-a;
 else
  ang=180-a;

 if(ang<0)
 ang=360+ang;

 return ang;

}

void move(int* x1,int* y1,int* x2,int* y2,char ch){

int dx,dy,p,q,r,s,t;

//p = *x1;
//q = *x2;
//dx = q-p;
//r = *y1;
//s = *y2;
//dy = s-r;

  switch(ch){
  case 'w':
  case 'i':
  if(!isBorder(100,*y1)){
	setcolor(GREEN);
	rectangle(*x1,*y1,*x2,*y2);
	setfillstyle(SOLID_FILL,GREEN);
	floodfill(*x1+1,*y1+1,GREEN);
	*y1-=10;
	*y2-=10;
	setcolor(RED);
	rectangle(*x1,*y1,*x2,*y2);
	setfillstyle(SOLID_FILL,RED);
	floodfill(*x1+1,*y1+1,RED);
	}
	break;

  case 's':
  case 'k':
  if(!isBorder(100,*y2)){
	setcolor(GREEN);
	rectangle(*x1,*y1,*x2,*y2);
	setfillstyle(SOLID_FILL,GREEN);
	floodfill(*x1+1,*y1+1,GREEN);
	*y1=(*y1)+10;
	*y2=(*y2)+10;
	setcolor(RED);
	rectangle(*x1,*y1,*x2,*y2);
	setfillstyle(SOLID_FILL,RED);
	floodfill(*x1+1,*y1+1,RED);
	}
	break;

  case 'x':
	exit(0);
  default :
	break;


 }


}

int isStick(int x,int y){

if(x<=ax2+11 && y>=ay1-11 && y<=ay2+11)
return 1;
else if(x >= bx1-11 && y>=by1-11 && y<=by2+11)
return 1;
else
return 0;


}