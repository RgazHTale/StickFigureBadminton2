#include<graphics.h>
#include<conio.h>
#include<math.h>
#include"EasyXPng.h"
#include"Timer.h"
#include<vector>
#pragma comment(lib,"Winmm.lib")
using namespace std;

//窗口大小
#define WIDTH 1000
#define HEIGHT 600

int score1=0; //左玩家得分
int score2=0; //右玩家得分
int ishit1 = 0; // 判断玩家1是否发球
int isbeat1 = 0; //判断玩家1是否击球 
int ishit2 = 0; // 判断玩家2是否发球
int isbeat2 = 0;//判断玩家2是否击球
int cnt1 = 0; //判断玩家1是否发球
int cnt2 = 0;//当玩家1发球时让球的初速度只设置一次
int cnt3 = 0; //判断玩家2是否发球
int cnt4 = 0;//当玩家2发球时让球的初速度只设置一次
int cnt5 = 0;//判断玩家1和2谁发球，0为玩家1发球，1为玩家2发球
int gameStatus=0;//游戏状态，0为初始菜单页面，1为正常游戏，2为结束游戏状态，3为暂停游戏
int status=0;  // 游戏胜利与失败的状态，1为正常游戏，2为退出游戏，3为游戏结束

void startMenu() //初始游戏界面
{
	IMAGE im_bk; // 定义初始菜单背景
	loadimage(&im_bk,"res\\初始页面.png",1000,600); // 加载初始菜单背景
	putimage(0,0,&im_bk); // 显示初始菜单背景
	setbkmode(TRANSPARENT); // 文字字体透明    
	settextcolor(RGB(0,0,0));// 设定文字颜色
	settextstyle(60, 0, _T("黑体")); //  设定文字大小、样式
	outtextxy(WIDTH*0.7,HEIGHT*0.75,_T("1 Start")); // 输出文字内容(按1键进入游戏)
	outtextxy(WIDTH*0.7,HEIGHT*0.85,_T("2 Exit")); // 输出文字内容(按2键退出游戏)
	FlushBatchDraw(); // 
	Sleep(2);

	if(kbhit())  // 按键判断输入
	{
		if(GetAsyncKeyState('1')) // 如果进入游戏
		{
			gameStatus=1; // 1为正常游戏
		}
		else if(GetAsyncKeyState('2')) // 如果退出游戏
		{
			gameStatus=2; // 2为退出游戏
			exit(0); //退出
		}
	}
}

void pauseMenu()// 暂停游戏界面
{
	IMAGE im_bk; // 定义初始菜单背景
	loadimage(&im_bk,"res\\pause.jpg",1000,600); // 加载初始菜单背景
	putimage(0,0,&im_bk); // 显示初始菜单背景
	FlushBatchDraw(); 
	Sleep(2);

	if(kbhit())  // 按键判断输入
	{
		if(GetAsyncKeyState('1')) // 如果进入游戏
		{
			gameStatus=1; // 1为正常游戏
		}
		else if(GetAsyncKeyState('2')) // 如果退出游戏
		{
			gameStatus=2; // 2为退出游戏
			exit(0); //退出
		}
	}
}
 
void endpage() // 左边玩家获胜时的结束页面
{
	IMAGE im_bk; // 定义初始菜单背景
	loadimage(&im_bk,"res\\游戏结束页面.png",1000,600); // 加载初始菜单背景
	putimage(0,0,&im_bk); // 显示初始菜单背景
	setbkmode(TRANSPARENT); // 文字字体透明    
	settextcolor(RGB(0,0,0));// 设定文字颜色
	settextstyle(60, 0, _T("黑体")); //  设定文字大小、样式
	outtextxy(WIDTH*0.2,HEIGHT*0.6,_T("胜利")); // 输出文字内容
	outtextxy(WIDTH*0.7,HEIGHT*0.6,_T("失败")); // 输出文字内容

	settextstyle(50, 0, _T("黑体")); //  设定文字大小、样式
	outtextxy(WIDTH*0.4,HEIGHT*0.5,_T("1 重新游戏")); // 输出文字内容
	outtextxy(WIDTH*0.4,HEIGHT*0.6,_T("2 结束游戏")); // 输出文字内容

	settextcolor(RGB(255,0,0));// 设定文字颜色
	settextstyle(80, 0, _T("黑体")); //  设定文字大小、样式
	outtextxy(WIDTH*0.34,HEIGHT*0.2,_T("游戏结束")); // 输出文字内容
	FlushBatchDraw(); 
	Sleep(2);

	if(kbhit())  // 按键判断输入
	{
		if(GetAsyncKeyState('1')) // 如果重新游戏
		{
			score1=0;//游戏分数清零
			score2=0;//游戏分数清零
			status=1; // 1为正常游戏
		}
		else if(GetAsyncKeyState('2')) // 如果退出游戏
		{
			status=2; // 2为退出游戏
			exit(0); //退出
		}
	}
}

void endpage1() // 右边玩家获胜时的结束页面
{
	IMAGE im_bk; // 定义初始菜单背景
	loadimage(&im_bk,"res\\游戏结束页面.png",1000,600); // 加载初始菜单背景
	putimage(0,0,&im_bk); // 显示初始菜单背景
	setbkmode(TRANSPARENT); // 文字字体透明    
	settextcolor(RGB(0,0,0));// 设定文字颜色
	settextstyle(60, 0, _T("黑体")); //  设定文字大小、样式
	outtextxy(WIDTH*0.2,HEIGHT*0.6,_T("失败")); // 输出文字内容
	outtextxy(WIDTH*0.7,HEIGHT*0.6,_T("胜利")); // 输出文字内容

	settextstyle(50, 0, _T("黑体")); //  设定文字大小、样式
	outtextxy(WIDTH*0.4,HEIGHT*0.5,_T("1 重新游戏")); // 输出文字内容
	outtextxy(WIDTH*0.4,HEIGHT*0.6,_T("2 结束游戏")); // 输出文字内容

	settextcolor(RGB(255,0,0));// 设定文字颜色
	settextstyle(80, 0, _T("黑体")); //  设定文字大小、样式
	outtextxy(WIDTH*0.34,HEIGHT*0.2,_T("游戏结束")); // 输出文字内容
	FlushBatchDraw(); 
	Sleep(2);

	if(GetAsyncKeyState('1')) // 如果进入游戏
		{
			score1=0;// 游戏分数清零
			score2=0;// 游戏分数清零
			status=1; // 1为正常游戏
		}
		else if(GetAsyncKeyState('2')) // 如果退出游戏
		{
			status=2; // 2为退出游戏
			exit(0); //退出
		}
}

enum PlayerStatus // 枚举游戏角色可能的状态
{
  standright,standleft,runright,runleft,jumpright,jumpleft,beatright,beatleft,hitright,hitleft
};
// hit 为发球 beat 为击球

class Scene // 游戏场景
{
public:
     IMAGE ui[2];
     enum Elment{i_bk,i_net};//背景,球网 

	 void initialize() // 初始化
	 {
		 loadimage(ui+i_bk,"res\\background.jpg",1000,600);//导入背景图像并适应窗口
	     loadimage(ui+i_net,"res\\net.png",30,130); // 导入球网图像
	 }

	 void draw() // 显示相关信息
	 {
		putimage(0,0,ui+i_bk); // 显示背景
		putimagePng(485,HEIGHT-(ui+i_net)->getheight()-10,ui+i_net); //显示球网
		TCHAR a[20],b[20]; // 定义字符串数组
		_stprintf(a,_T("%d"),score1); // 将score1转换为字符串
		_stprintf(b,_T("%d"),score2); // 将score2转换为字符串
		settextstyle(70, 0, _T("黑体")); // 设置文字大小、字体
		settextcolor(RGB(0,0,0));  // 设置字体颜色
		outtextxy(WIDTH*0.4,HEIGHT*0.05,a); // 输出得分文字
		outtextxy(WIDTH*0.6,HEIGHT*0.05,b); // 输出得分文字
	 }
};

class Ball // 羽毛球
{
public:
	IMAGE im_ball; // 羽毛球图像 
	float x,y; // 刻画羽毛球坐标
	float ball_width,ball_height; // 羽毛球图像的宽度和高度
    float x_min,x_max; // 羽毛球移动x坐标的最大和最小值
	float vx,vy,gravity; // 羽毛球在x、y方向的速度和重力加速度

	void initialize() // 初始化
	{
		loadimage(&im_ball,"res\\ball.png",16,16); // 导入羽毛球图像
		ball_width = im_ball.getwidth(); // 获得图像的宽和高
		ball_height = im_ball.getheight();
		x_min = 0;
		x_max = 984;
	   	
		// 设置初位置
		x = 306;
		y = 541;
		
		vx = 0; // 设置初速度
		vy = 0;
		gravity = 0;	
	}

	void draw() // 显示相关信息
	{
		putimagePng(x,y,&im_ball); // 以羽毛球中心绘制羽毛球图像
	}
	
	void collideWallorGroundorNet() //羽毛球碰到墙面或者地面或者球网的情况
	{
		y += vy;
		vy += gravity; 
		x += vx;
		if(x<=x_min||x>=x_max) //碰到两边墙面
			vx = -vx;
		else if((y>=554&&x>=485)||(x>=1000)) // 当球落到右边地面，左边玩家加一分
		{
			y = 554;
			vx = 0;
			score1++;
			if(score1>=6)// 当左边玩家游戏分数为6时，游戏结束，右边玩家获胜
			{
				status=3;// 游戏结束
				while(status==3)// 持续执行该函数
				{
					endpage(); // 进入左边玩家获胜时游戏结束页面
				}
			}
		}
		else if((y>=554&&x<=515)||(x<=0)) // 当球落到左边地面，右边玩家加一分
		{
			y=554;
			vx=0;
			score2++;
			if(score2>=6) // 当左边玩家游戏分数为6时，游戏结束，右边玩家获胜
			{
				status=3; // // 游戏结束
				while(status==3)// 持续执行该函数
				{
					endpage1(); //进入右边玩家获胜时游戏结束页面
				}
			}
		}
		else if(x>=485&&x<=515&&y>=444) // 碰到球网
	    {
		  vx = -vx;
		  vy = 0;
		}
	}
	void begin1()
	{
		if(cnt1==1){
			mciSendString("close fgmusic",NULL,0,NULL);
			mciSendString("open res\\beatball.mp3 alias fgmusic",NULL,0,NULL);
			mciSendString("play fgmusic",NULL,0,NULL);
		   vx = 15; // 设置玩家1发球初速度
		   vy = -15;
		   gravity = 1;
		   cnt2 = 1;
		}
	}
	void begin2()
	{
		if(cnt3==1){
			mciSendString("close fgmusic",NULL,0,NULL);
			mciSendString("open res\\beatball.mp3 alias fgmusic",NULL,0,NULL);
			mciSendString("play fgmusic",NULL,0,NULL);
		   vx = -15; // 设置玩家2初速度
		   vy = -15;
		   gravity = 1;
		   cnt4 = 1;
		}
	}
};

class Player1 //玩家1的控制
{
public:
	IMAGE im_show;// 玩家1当前时刻要显示的图像
	IMAGE im_standright;
	IMAGE im_jumpright;
	vector <IMAGE> ims_runright; // 向右奔跑的图像序列
	vector <IMAGE> ims_runleft; // 向左奔跑的图像序列
	vector <IMAGE> ims_hitright; // 向右发球的图像序列
	vector <IMAGE> ims_beatright; // 向右击球的图像序列

	int animId; // 用于循环播放动画的id

	PlayerStatus playerStatus; // 当前的状态

	float x_left,y_up,ground; //以这两个坐标判定碰撞
	float vx,vy; //速度
	float gravity; // 重力加速度
	float width ,height;//  图片的宽和高

	void draw() //显示相关信息
	{
		putimagePng(x_left,y_up,&im_show); // 显示游戏中的角色
	}

	void initialize() //初始化
	{
		ims_runleft.clear(); // 先清空掉vector
		ims_runright.clear();
	    ims_hitright.clear();
		ims_beatright.clear();

		loadimage(&im_standright,"res\\standright.png");// 导入向右站立的图片
		loadimage(&im_jumpright,"res\\jumpIMG\\jumpright.png");// 导入向右跳跃的图片

		playerStatus = standright; // 初始为向右站立的游戏状态
		im_show = im_standright;  // 初始显示向右站立的图片
		width = im_show.getwidth(); //获得初始图像的宽和高
		height = im_show.getheight();

		TCHAR filename[100]; // 存储动画张数
        for(int i=0;i<3;i++) // 把向右奔跑的3张图片对象添加到ims_runright中
	   {
		//格式化打印:sprintf
		_stprintf(filename,"res\\player1runright\\%03d.png",i);
		//加载部分
		IMAGE im;
		loadimage(&im,filename);
		ims_runright.push_back(im);
	    }

		for(int i=0;i<4;i++) // 把向左奔跑的4张图片对象添加到ims_runleft中
	   {
		_stprintf(filename,"res\\player1runleft\\%03d.png",i);
		IMAGE im;
		loadimage(&im,filename);
		ims_runleft.push_back(im);
	    }

		for(int i=0;i<5;i++) // 把向右发球的5张图片对象添加到ims_hitright中
	   {
		_stprintf(filename,"res\\hitright\\%03d.png",i);
		IMAGE im;
		loadimage(&im,filename);
		ims_hitright.push_back(im);
	    }

		for(int i=0;i<4;i++) // 把向右击球的4张图片对象添加到ims_hitright中
	   {
		_stprintf(filename,"res\\beatright\\%03d.png",i);
		IMAGE im;
		loadimage(&im,filename);
		ims_beatright.push_back(im);
	    }

		animId = 0; //动画id开始设为0

		// 设置角色xz坐标初位置
		x_left = 200;
		y_up = 570 -height;
		ground = 570;

		vx = 10; // 设置初速度
		vy = 0;
		gravity = 3;
	}

	void runRight() //角色向右奔跑
	{
		if(x_left<=400)
		{
		x_left += vx; //横坐标增加向右移动
	    if(playerStatus == standright||playerStatus == runleft) // 如果之前的角色状态不是向右奔跑
		{
			playerStatus = runright; // 切换为向右奔跑的状态
			animId = 0;  // 动画播放id初始化为0
		}
		else // 表示之前就是向右奔跑的状态
		{
			animId++; // 动画图片开始切换
			if(animId>=ims_runright.size()) // 循环切换
				animId = 0;
		}
		im_show = ims_runright[animId];  // 要显示的图片
		}
	}

	void runLeft() //角色向左奔跑
	{
	  if(x_left>=0)
	  {
		x_left -= vx; //横坐标减小向左移动
		if(playerStatus == runright||playerStatus == standright) // 如果之前的角色状态不是向左奔跑
		{
			playerStatus = runleft; // 切换为向左奔跑的状态
			animId = 0;  // 动画播放id初始化为0
		}
		else // 表示之前就是向左奔跑的状态
		{
			animId++; // 动画图片开始切换
			if(animId>=ims_runleft.size()) // 循环切换
				animId = 0;
		}
		im_show = ims_runleft[animId];  // 要显示的图片
	  }
	}

	void hitRight(Ball &ball) // 角色发球
	{
		static int time = 0;
		static int song = 0; // 判断是否播放音乐
		if(time<2){
			im_show = ims_hitright[0];
			time++;
		}
		if(time>=2 && time <4)
		{
			im_show = ims_hitright[1];
			time++;
			if(abs(y_up+79-(ball.y+ball.ball_height/2))<=15&&abs(x_left+115-(ball.x+ball.ball_width/2))<=14)//判断是否碰到球
			{
			  ball.vx = 15;
			  ball.vy = -20;
			  song++;
			}
		}
		if(time>=4 && time <6)
		{
			im_show = ims_hitright[2];
			time++;
		}
		if(time >=6 && time <8)
		{
			im_show = ims_hitright[3];
			time++;
		}
		if(time>=8 && time <10)
		{
			im_show = ims_hitright[4];
			time++;
		}
		height = im_show.getheight();
		y_up = ground -height;
		if(time>=10)
		{
			time = 0;
			ishit1=0;
		}
		if(song!=0)
		{
			mciSendString("close fgmusic",NULL,0,NULL);
			mciSendString("open res\\beatball.mp3 alias fgmusic",NULL,0,NULL);
			mciSendString("play fgmusic",NULL,0,NULL);
		}
		song=0;
	}

	void beatRight(Ball &ball) // 角色击球
	{
		static int song = 0; // 判断是否播放音乐
		static int time = 0;
		if(time<2){
			im_show = ims_beatright[0];
			time++;
			height = im_show.getheight();
		    y_up = ground -height;
			if(abs(y_up+12-(ball.y+ball.ball_height/2))<=12&&abs(x_left+15-(ball.x+ball.ball_width/2))<=15)
			{
			  ball.vx = 15;
			  ball.vy = -20;
			  song++;
			}
		}
		if(time>=2 && time <4)
		{
			im_show = ims_beatright[1];
			time++;
			height = im_show.getheight();
		    y_up = ground -height;
			if(abs(y_up+1.0*35/2-(ball.y+ball.ball_height/2))<=1.0*35/2&&abs(x_left+80+1.0*15/2-(ball.x+ball.ball_width/2))<=1.0*15/2)
			{
			  ball.vx = 20;
			  ball.vy = -8;
			  song++;
			}
		}
		if(time>=4 && time <6)
		{
			im_show = ims_beatright[2];
			time++;
		}
		if(time >=6 && time <8)
		{
			im_show = ims_beatright[3];
			time++;
		}
		height = im_show.getheight();
		y_up = ground -height;
		if(time>=8)
		{
			time = 0;
			isbeat1=0;
		}
		if(song!=0)
		{
			mciSendString("close fgmusic",NULL,0,NULL);
			mciSendString("open res\\beatball.mp3 alias fgmusic",NULL,0,NULL);
			mciSendString("play fgmusic",NULL,0,NULL);
		}
		song=0;
	}

	void standStill() // 设置角色默认为站立状态
	{
	   if (playerStatus==runleft || playerStatus == standright||playerStatus==runright)
			im_show = im_standright;
	}

	void beginJump() // 角色跳跃处理
	{
		if(playerStatus!=jumpright) // 已经在空中则不起跳
		{
			im_show = im_jumpright; // 切换到起跳的图片
			playerStatus = jumpright; // 切换到起跳的状态
			vy = -24; // 给角色向上的初速度
		}
	}

	void updateYcoordinate() // x为键盘控制，y为自动更新的
	{
		if(playerStatus==jumpright) // 当前是在空中跳跃状态
		{
			vy +=gravity; // y方向速度受重力影响变化
			y_up +=vy; // y方向位置受重力影响变化
			ground = y_up + height;
     		if((y_up+height)>=570) // 防止落到地面之下
			{
				y_up = 570 - height; // 保证正好落到地面上
				// 落地后切换到站立图像
                playerStatus = standright;
			    im_show = im_standright;   
		    }
		}

	}
};

class Player2 //玩家2控制的游戏角色类
{
public:
	IMAGE im_show;// 玩家2当前时刻要显示的图像
	IMAGE im_standleft;
	IMAGE im_jumpleft;
	vector <IMAGE> ims_runright; // 向右奔跑的图像序列
	vector <IMAGE> ims_runleft; // 向左奔跑的图像序列
	vector <IMAGE> ims_hitleft; // 向左发球的图像序列
	vector <IMAGE> ims_beatleft; // 向左击球的图像序列

	int animId; // 用于循环播放动画的id

	PlayerStatus playerStatus; // 当前的状态

	float x_left,y_up,x_right,ground; //以这两个坐标判定碰撞
	float vx,vy; //速度
	float gravity; // 重力加速度
	float width ,height;//  图片的宽和高

	void draw() //显示相关信息
	{
       putimagePng(x_left,y_up,&im_show); // 显示游戏中的角色
	}

	void initialize() //初始化
	{
		ims_runleft.clear(); // 先清空掉vector
		ims_runright.clear();
		ims_hitleft.clear();
		ims_beatleft.clear();
		loadimage(&im_standleft,"res\\standleft.png");// 导入向右站立的图片
		loadimage(&im_jumpleft,"res\\jumpIMG\\jumpleft.png");// 导入向右跳跃的图片

		playerStatus = standleft; // 初始为向右站立的游戏状态
		im_show = im_standleft;  // 初始显示向右站立的图片
		width = im_show.getwidth(); // 获得图像的宽和高，所有动画图片大小一样
		height = im_show.getheight();

		TCHAR filename[50]; // 存储动画张数
        for(int i=0;i<5;i++) // 把向右奔跑的5张图片对象添加到ims_runright中
	   {
		//格式化打印:sprintf
		_stprintf(filename,"res\\player2runright\\%03d.png",i);
		//加载部分
		IMAGE im;
		loadimage(&im,filename);
		ims_runright.push_back(im);
	    }
		for(int i=0;i<6;i++) // 把向左奔跑的6张图片对象添加到ims_runright中
	   {
		_stprintf(filename,"res\\player2runleft\\%03d.png",i);
		IMAGE im;
		loadimage(&im,filename);
		ims_runleft.push_back(im);
	    }
		for(int i=0;i<5;i++) // 把向左发球的5张图片对象添加到ims_hitright中
		{
			_stprintf(filename,"res\\hitleft\\%03d.png",i);
			IMAGE im;
			loadimage(&im,filename);
			ims_hitleft.push_back(im);
		}

		for(int i=0;i<4;i++) // 把向左击球的4张图片对象添加到ims_hitright中
		{
			_stprintf(filename,"res\\beatleft\\%03d.png",i);
			IMAGE im;
			loadimage(&im,filename);
			ims_beatleft.push_back(im);
		}

		animId = 0; //动画id开始设为0

		// 设置角色初位置
		x_left = 712;
		y_up = 570 -height;
		ground = 570;

		vx = 10; // 设置初速度
		vy = 0;
		gravity = 3;
	}

	void runRight() //角色向右奔跑
	{
		if(x_left<=910)
		{
		x_left += vx; //横坐标增加向右移动
	    if(playerStatus == runleft||playerStatus == standleft) // 如果之前的角色状态不是向右奔跑
		{
			playerStatus = runright; // 切换为向右奔跑的状态
			animId = 0;  // 动画播放id初始化为0
		}
		else // 表示之前就是向右奔跑的状态
		{
			animId++; // 动画图片开始切换
			if(animId>=ims_runright.size()) // 循环切换
				animId = 0;
		}
		im_show = ims_runright[animId];  // 要显示的图片
		}
	}

	void runLeft() //角色向左奔跑
	{
		if(x_left>=525)
		{
		x_left -= vx; //横坐标减小向左移动
		if(playerStatus == runright||playerStatus == standleft) // 如果之前的角色状态不是向左奔跑
		{
			playerStatus = runleft; // 切换为向左奔跑的状态
			animId = 0;  // 动画播放id初始化为0
		}
		else // 表示之前就是向左奔跑的状态
		{
			animId++; // 动画图片开始切换
			if(animId>=ims_runleft.size()) // 循环切换
				animId = 0;
		}
		im_show = ims_runleft[animId];  // 要显示的图片
		}
	}

	void hitLeft(Ball &ball) // 角色发球
	{
		x_right = x_left + width;
		static int time = 0;
		static int song = 0;
		if(time<2){
			im_show = ims_hitleft[0];
			time++;
		}
		if(time>=2 && time <4)
		{
			im_show = ims_hitleft[1];
			time++;
			y_up = ground -height;
			width = im_show.getwidth();
			x_left = x_right - width;
			if(abs(y_up+66-(ball.y+ball.ball_height/2))<=12&&abs(x_left+16-(ball.x+ball.ball_width/2))<=16)
			{
			  ball.vx = -15;
			  ball.vy = -20;
			  song++;
			}
		}
		if(time>=4 && time <6)
		{
			im_show = ims_hitleft[2];
			time++;
		}
		if(time >=6 && time <8)
		{
			im_show = ims_hitleft[3];
			time++;
		}
		if(time>=8 && time <10)
		{
			im_show = ims_hitleft[4];
			time++;
		}
		height = im_show.getheight();
		y_up = ground -height;
		width = im_show.getwidth();
		x_left = x_right - width;
		if(time>=10)
		{
			time = 0;
			ishit2=0;
		}
		if(song!=0)
		{
			mciSendString("close fgmusic",NULL,0,NULL);
			mciSendString("open res\\beatball.mp3 alias fgmusic",NULL,0,NULL);
			mciSendString("play fgmusic",NULL,0,NULL);
		}
		song=0;
	}

	void beatLeft(Ball &ball) // 角色击球并判断是否击中，若击中羽毛球返回
	{
		x_right = x_left + width;
		static int time = 0;
		static int song = 0; // 用来判断是否播放音乐
		if(time<2){
			im_show = ims_beatleft[0];
			time++;
			y_up = ground -height;
			width = im_show.getwidth();
			x_left = x_right - width;
			if(abs(y_up+12-(ball.y+ball.ball_height/2))<=12&&abs(x_left+58+15-(ball.x+ball.ball_width/2))<=15)
			{
			  ball.vx = -15;
			  ball.vy = -20;
			  song++;
			}
		}
		if(time>=2 && time <4)
		{ 
			im_show = ims_beatleft[1];
			time++;
			height = im_show.getheight();
			y_up = ground -height;
			width = im_show.getwidth();
			x_left = x_right - width;
			if(abs(y_up+1.0*35/2-(ball.y+ball.ball_height/2))<=1.0*35/2&&abs(x_left+24+1.0*11/2-(ball.x+ball.ball_width/2))<=1.0*11/2)
			{
			  ball.vx = -20;
			  ball.vy = -8;
			  song++;
			}
		}
		if(time>=4 && time <6)
		{
			im_show = ims_beatleft[2];
			time++;
			height = im_show.getheight();
			y_up = ground -height;
			width = im_show.getwidth();
			x_left = x_right - width;
			if(abs(y_up+1.0*21/2-(ball.y+ball.ball_height/2))<=1.0*21/2&&abs(x_left+1.0*33/2-(ball.x+ball.ball_width/2))<=1.0*33/2)
			{
			  ball.vx = -20;
			  ball.vy = 0;
			  song++;
			}
		}
		if(time >=6 && time <8)
		{
			im_show = ims_beatleft[3];
			time++;
		}
		height = im_show.getheight();
		y_up = ground -height;
		width = im_show.getwidth();
		x_left = x_right - width;
		if(time>=8)
		{
			time = 0;
			isbeat2=0;
		}
		if(song!=0)
		{
			mciSendString("close fgmusic",NULL,0,NULL);
			mciSendString("open res\\beatball.mp3 alias fgmusic",NULL,0,NULL);
			mciSendString("play fgmusic",NULL,0,NULL);
		}
		song=0;
	}

	void standStill() // 设置角色默认为站立状态
	{
	   if (playerStatus==runleft || playerStatus == standleft ||playerStatus==runright)
			im_show = im_standleft;
	}

	void beginJump() // 角色跳跃处理
	{
		if(playerStatus!=jumpleft) // 已经在空中则不起跳
		{
			im_show = im_jumpleft; // 切换到起跳的图片
			playerStatus = jumpleft; // 切换到起跳的状态
			vy = -24; // 给角色向上的初速度
		}
	}

	void updateYcoordinate() // x为键盘控制，y为自动更新的
	{
		if(playerStatus==jumpleft) // 当前是在空中跳跃状态
		{
			vy +=gravity; // y方向速度受重力影响变化
			y_up +=vy; // y方向位置受重力影响变化
			ground = y_up + height;

			if((y_up+height)>=570) // 防止落到地面之下
			{
				y_up = 570 - height; // 保证正好落到地面上
				// 落地后切换到站立图像
                 playerStatus = standleft;
				 im_show = im_standleft;
		    }
		}

	}
};

class Beatball // 发球类型的定义
{
	public:
		IMAGE im_ball; // 羽毛球图像 
		float x,y; // 刻画羽毛球坐标

		void initialize() // 初始化
		{
			loadimage(&im_ball,"res\\ball.png",16,16); // 导入羽毛球图像
		}
		void draw1(Player1 &player1) // 显示玩家1发球相关信息
		{
			x = player1.x_left+82;
			y = player1.y_up+48;
			putimagePng(x,y,&im_ball); // 以羽毛球中心绘制羽毛球图像
		}
		void draw2(Player2 &player2) // 显示玩家2发球相关信息
		{
			x = player2.x_left-10;
			y = player2.y_up+48;
			putimagePng(x,y,&im_ball); // 以羽毛球中心绘制羽毛球图像
		}
};

Scene scene; // 定义场景
Player1 player1; // 定义玩家1控制的游戏角色对象
Player2 player2; // 定义玩家2控制的游戏角色对象
Ball ball; // 定义羽毛球
Beatball beatball;//定义发球
Timer timer;  // 精确延时

void startup() //初始化
{
	mciSendString(_T("open res\\game_music.mp3 alias bkmusic"), NULL, 0, NULL);//打开背景音乐
	mciSendString(_T("play bkmusic repeat"), NULL, 0, NULL);  // 循环播放

	player1.initialize();
	player2.initialize();
	scene.initialize();
	beatball.initialize();
	ball.initialize();

	initgraph(WIDTH,HEIGHT); // 新开一个画面
    BeginBatchDraw(); // 开始批量绘制

	while(gameStatus==0) // 首先显示初始游戏界面
		startMenu();
}

void show() // 显示
{
	while(gameStatus==3)
		pauseMenu();  // 游戏暂停后的菜单界面，一般按Esc键启动该界面

	scene.draw(); // 显示场景相关信息
	player1.draw(); // 显示玩家1相关信息
	player2.draw(); // 显示玩家2相关信息
	if(cnt5==0){//羽毛球随玩家1移动
		if(cnt1==0)
			beatball.draw1(player1);
		else{
				if(cnt2==0){
				ball.begin1();
				ball.x = player1.x_left+82;
				ball.y = player1.y_up+48;
			}
			ball.draw();
		}
	}
	if(cnt5==1){//羽毛球随玩家2移动
		if(cnt3==0)
			beatball.draw2(player2);
		else{
			if(cnt4==0){
				ball.begin2();
				ball.x = player2.x_left-10;
				ball.y = player2.y_up+48;
			}
			ball.draw();
		}
	}
	FlushBatchDraw();
	timer.Sleep(50); //暂停若干毫秒
}

void updateWithoutInput()  // 和输入无关的更新
{
	player1.updateYcoordinate(); 
	player2.updateYcoordinate(); 
    ball.collideWallorGroundorNet();
	if(ball.y>=554&&ball.x>=515)//羽毛球落到右边
	{
		cnt1 = 0;
		cnt2 = 0;
		player1.initialize();
	    player2.initialize();
	    ball.initialize();
		cnt5 = 0;
	}
	if(ball.y>=554&&ball.x<=485)//羽毛球落到左边
	{
		cnt3 = 0;
		cnt4 = 0;
		player1.initialize();
	    player2.initialize();
	    ball.initialize();
		cnt5 = 1;
	}
 }

void updateWithInput() // 和输入有关的更新
{
	player1.standStill(); // 角色1默认为站立
	player2.standStill(); // 角色2默认为站立

	if(kbhit())  //当按键时切换图片与改变位置角色1
	{
		if(GetAsyncKeyState('A')) // 向左
		{
			player1.runLeft();
		}
		if (GetAsyncKeyState('D')) // 向右
		{
			player1.runRight();
		}
		if (GetAsyncKeyState('W')) // 向上
		{
			player1.beginJump();
		}
		if(GetAsyncKeyState('E'))
		{
			ishit1=1;//发球
			cnt1 = 1;
		}
		if(GetAsyncKeyState('S'))
		{
			isbeat1=1;//击球
		}
	}
	if(kbhit())  //当按键时切换图片与改变位置角色2
	{
		if(GetAsyncKeyState(VK_LEFT)) // 向左
		{
			player2.runLeft();
		}
		if (GetAsyncKeyState(VK_RIGHT)) // 向右
		{
			player2.runRight();
		}
		if (GetAsyncKeyState(VK_UP)) // 向上
		{
			player2.beginJump();
		}
		if (GetAsyncKeyState(VK_RETURN)) // 发球
		{
			ishit2=1;
			cnt3 = 1;
		}
		if (GetAsyncKeyState(VK_DOWN)) // 击球
		{
			isbeat2=1;
		}
	}
	if(kbhit())  
	{
		if(GetAsyncKeyState(VK_ESCAPE)) // 按Esc键时显示暂停游戏界面
		{
			gameStatus=3;
		}
	}
}

void gameover()
 {
	 EndBatchDraw();
	 getch();
	 closegraph();
 }

int main()   //主函数
{
	startup();  //初始化
	while(1)   //  一直循环
	{
		if(ishit1==1)
		player1.hitRight(ball);
		if(isbeat1==1)
		player1.beatRight(ball);
		if(ishit2==1)
		player2.hitLeft(ball);
		if(isbeat2==1)
		player2.beatLeft(ball);
		show();      //  显示
		updateWithoutInput();  //和输入无关的更新
		updateWithInput();    //和输入有关的更新
	}
	gameover();//游戏结束
	return 0;
}
