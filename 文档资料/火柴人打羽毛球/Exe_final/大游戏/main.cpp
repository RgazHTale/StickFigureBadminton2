#include<graphics.h>
#include<conio.h>
#include<math.h>
#include"EasyXPng.h"
#include"Timer.h"
#include<vector>
#pragma comment(lib,"Winmm.lib")
using namespace std;

//���ڴ�С
#define WIDTH 1000
#define HEIGHT 600

int score1=0; //����ҵ÷�
int score2=0; //����ҵ÷�
int ishit1 = 0; // �ж����1�Ƿ���
int isbeat1 = 0; //�ж����1�Ƿ���� 
int ishit2 = 0; // �ж����2�Ƿ���
int isbeat2 = 0;//�ж����2�Ƿ����
int cnt1 = 0; //�ж����1�Ƿ���
int cnt2 = 0;//�����1����ʱ����ĳ��ٶ�ֻ����һ��
int cnt3 = 0; //�ж����2�Ƿ���
int cnt4 = 0;//�����2����ʱ����ĳ��ٶ�ֻ����һ��
int cnt5 = 0;//�ж����1��2˭����0Ϊ���1����1Ϊ���2����
int gameStatus=0;//��Ϸ״̬��0Ϊ��ʼ�˵�ҳ�棬1Ϊ������Ϸ��2Ϊ������Ϸ״̬��3Ϊ��ͣ��Ϸ
int status=0;  // ��Ϸʤ����ʧ�ܵ�״̬��1Ϊ������Ϸ��2Ϊ�˳���Ϸ��3Ϊ��Ϸ����

void startMenu() //��ʼ��Ϸ����
{
	IMAGE im_bk; // �����ʼ�˵�����
	loadimage(&im_bk,"res\\��ʼҳ��.png",1000,600); // ���س�ʼ�˵�����
	putimage(0,0,&im_bk); // ��ʾ��ʼ�˵�����
	setbkmode(TRANSPARENT); // ��������͸��    
	settextcolor(RGB(0,0,0));// �趨������ɫ
	settextstyle(60, 0, _T("����")); //  �趨���ִ�С����ʽ
	outtextxy(WIDTH*0.7,HEIGHT*0.75,_T("1 Start")); // �����������(��1��������Ϸ)
	outtextxy(WIDTH*0.7,HEIGHT*0.85,_T("2 Exit")); // �����������(��2���˳���Ϸ)
	FlushBatchDraw(); // 
	Sleep(2);

	if(kbhit())  // �����ж�����
	{
		if(GetAsyncKeyState('1')) // ���������Ϸ
		{
			gameStatus=1; // 1Ϊ������Ϸ
		}
		else if(GetAsyncKeyState('2')) // ����˳���Ϸ
		{
			gameStatus=2; // 2Ϊ�˳���Ϸ
			exit(0); //�˳�
		}
	}
}

void pauseMenu()// ��ͣ��Ϸ����
{
	IMAGE im_bk; // �����ʼ�˵�����
	loadimage(&im_bk,"res\\pause.jpg",1000,600); // ���س�ʼ�˵�����
	putimage(0,0,&im_bk); // ��ʾ��ʼ�˵�����
	FlushBatchDraw(); 
	Sleep(2);

	if(kbhit())  // �����ж�����
	{
		if(GetAsyncKeyState('1')) // ���������Ϸ
		{
			gameStatus=1; // 1Ϊ������Ϸ
		}
		else if(GetAsyncKeyState('2')) // ����˳���Ϸ
		{
			gameStatus=2; // 2Ϊ�˳���Ϸ
			exit(0); //�˳�
		}
	}
}
 
void endpage() // �����һ�ʤʱ�Ľ���ҳ��
{
	IMAGE im_bk; // �����ʼ�˵�����
	loadimage(&im_bk,"res\\��Ϸ����ҳ��.png",1000,600); // ���س�ʼ�˵�����
	putimage(0,0,&im_bk); // ��ʾ��ʼ�˵�����
	setbkmode(TRANSPARENT); // ��������͸��    
	settextcolor(RGB(0,0,0));// �趨������ɫ
	settextstyle(60, 0, _T("����")); //  �趨���ִ�С����ʽ
	outtextxy(WIDTH*0.2,HEIGHT*0.6,_T("ʤ��")); // �����������
	outtextxy(WIDTH*0.7,HEIGHT*0.6,_T("ʧ��")); // �����������

	settextstyle(50, 0, _T("����")); //  �趨���ִ�С����ʽ
	outtextxy(WIDTH*0.4,HEIGHT*0.5,_T("1 ������Ϸ")); // �����������
	outtextxy(WIDTH*0.4,HEIGHT*0.6,_T("2 ������Ϸ")); // �����������

	settextcolor(RGB(255,0,0));// �趨������ɫ
	settextstyle(80, 0, _T("����")); //  �趨���ִ�С����ʽ
	outtextxy(WIDTH*0.34,HEIGHT*0.2,_T("��Ϸ����")); // �����������
	FlushBatchDraw(); 
	Sleep(2);

	if(kbhit())  // �����ж�����
	{
		if(GetAsyncKeyState('1')) // ���������Ϸ
		{
			score1=0;//��Ϸ��������
			score2=0;//��Ϸ��������
			status=1; // 1Ϊ������Ϸ
		}
		else if(GetAsyncKeyState('2')) // ����˳���Ϸ
		{
			status=2; // 2Ϊ�˳���Ϸ
			exit(0); //�˳�
		}
	}
}

void endpage1() // �ұ���һ�ʤʱ�Ľ���ҳ��
{
	IMAGE im_bk; // �����ʼ�˵�����
	loadimage(&im_bk,"res\\��Ϸ����ҳ��.png",1000,600); // ���س�ʼ�˵�����
	putimage(0,0,&im_bk); // ��ʾ��ʼ�˵�����
	setbkmode(TRANSPARENT); // ��������͸��    
	settextcolor(RGB(0,0,0));// �趨������ɫ
	settextstyle(60, 0, _T("����")); //  �趨���ִ�С����ʽ
	outtextxy(WIDTH*0.2,HEIGHT*0.6,_T("ʧ��")); // �����������
	outtextxy(WIDTH*0.7,HEIGHT*0.6,_T("ʤ��")); // �����������

	settextstyle(50, 0, _T("����")); //  �趨���ִ�С����ʽ
	outtextxy(WIDTH*0.4,HEIGHT*0.5,_T("1 ������Ϸ")); // �����������
	outtextxy(WIDTH*0.4,HEIGHT*0.6,_T("2 ������Ϸ")); // �����������

	settextcolor(RGB(255,0,0));// �趨������ɫ
	settextstyle(80, 0, _T("����")); //  �趨���ִ�С����ʽ
	outtextxy(WIDTH*0.34,HEIGHT*0.2,_T("��Ϸ����")); // �����������
	FlushBatchDraw(); 
	Sleep(2);

	if(GetAsyncKeyState('1')) // ���������Ϸ
		{
			score1=0;// ��Ϸ��������
			score2=0;// ��Ϸ��������
			status=1; // 1Ϊ������Ϸ
		}
		else if(GetAsyncKeyState('2')) // ����˳���Ϸ
		{
			status=2; // 2Ϊ�˳���Ϸ
			exit(0); //�˳�
		}
}

enum PlayerStatus // ö����Ϸ��ɫ���ܵ�״̬
{
  standright,standleft,runright,runleft,jumpright,jumpleft,beatright,beatleft,hitright,hitleft
};
// hit Ϊ���� beat Ϊ����

class Scene // ��Ϸ����
{
public:
     IMAGE ui[2];
     enum Elment{i_bk,i_net};//����,���� 

	 void initialize() // ��ʼ��
	 {
		 loadimage(ui+i_bk,"res\\background.jpg",1000,600);//���뱳��ͼ����Ӧ����
	     loadimage(ui+i_net,"res\\net.png",30,130); // ��������ͼ��
	 }

	 void draw() // ��ʾ�����Ϣ
	 {
		putimage(0,0,ui+i_bk); // ��ʾ����
		putimagePng(485,HEIGHT-(ui+i_net)->getheight()-10,ui+i_net); //��ʾ����
		TCHAR a[20],b[20]; // �����ַ�������
		_stprintf(a,_T("%d"),score1); // ��score1ת��Ϊ�ַ���
		_stprintf(b,_T("%d"),score2); // ��score2ת��Ϊ�ַ���
		settextstyle(70, 0, _T("����")); // �������ִ�С������
		settextcolor(RGB(0,0,0));  // ����������ɫ
		outtextxy(WIDTH*0.4,HEIGHT*0.05,a); // ����÷�����
		outtextxy(WIDTH*0.6,HEIGHT*0.05,b); // ����÷�����
	 }
};

class Ball // ��ë��
{
public:
	IMAGE im_ball; // ��ë��ͼ�� 
	float x,y; // �̻���ë������
	float ball_width,ball_height; // ��ë��ͼ��Ŀ�Ⱥ͸߶�
    float x_min,x_max; // ��ë���ƶ�x�����������Сֵ
	float vx,vy,gravity; // ��ë����x��y������ٶȺ��������ٶ�

	void initialize() // ��ʼ��
	{
		loadimage(&im_ball,"res\\ball.png",16,16); // ������ë��ͼ��
		ball_width = im_ball.getwidth(); // ���ͼ��Ŀ�͸�
		ball_height = im_ball.getheight();
		x_min = 0;
		x_max = 984;
	   	
		// ���ó�λ��
		x = 306;
		y = 541;
		
		vx = 0; // ���ó��ٶ�
		vy = 0;
		gravity = 0;	
	}

	void draw() // ��ʾ�����Ϣ
	{
		putimagePng(x,y,&im_ball); // ����ë�����Ļ�����ë��ͼ��
	}
	
	void collideWallorGroundorNet() //��ë������ǽ����ߵ���������������
	{
		y += vy;
		vy += gravity; 
		x += vx;
		if(x<=x_min||x>=x_max) //��������ǽ��
			vx = -vx;
		else if((y>=554&&x>=485)||(x>=1000)) // �����䵽�ұߵ��棬�����Ҽ�һ��
		{
			y = 554;
			vx = 0;
			score1++;
			if(score1>=6)// ����������Ϸ����Ϊ6ʱ����Ϸ�������ұ���һ�ʤ
			{
				status=3;// ��Ϸ����
				while(status==3)// ����ִ�иú���
				{
					endpage(); // ���������һ�ʤʱ��Ϸ����ҳ��
				}
			}
		}
		else if((y>=554&&x<=515)||(x<=0)) // �����䵽��ߵ��棬�ұ���Ҽ�һ��
		{
			y=554;
			vx=0;
			score2++;
			if(score2>=6) // ����������Ϸ����Ϊ6ʱ����Ϸ�������ұ���һ�ʤ
			{
				status=3; // // ��Ϸ����
				while(status==3)// ����ִ�иú���
				{
					endpage1(); //�����ұ���һ�ʤʱ��Ϸ����ҳ��
				}
			}
		}
		else if(x>=485&&x<=515&&y>=444) // ��������
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
		   vx = 15; // �������1������ٶ�
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
		   vx = -15; // �������2���ٶ�
		   vy = -15;
		   gravity = 1;
		   cnt4 = 1;
		}
	}
};

class Player1 //���1�Ŀ���
{
public:
	IMAGE im_show;// ���1��ǰʱ��Ҫ��ʾ��ͼ��
	IMAGE im_standright;
	IMAGE im_jumpright;
	vector <IMAGE> ims_runright; // ���ұ��ܵ�ͼ������
	vector <IMAGE> ims_runleft; // �����ܵ�ͼ������
	vector <IMAGE> ims_hitright; // ���ҷ����ͼ������
	vector <IMAGE> ims_beatright; // ���һ����ͼ������

	int animId; // ����ѭ�����Ŷ�����id

	PlayerStatus playerStatus; // ��ǰ��״̬

	float x_left,y_up,ground; //�������������ж���ײ
	float vx,vy; //�ٶ�
	float gravity; // �������ٶ�
	float width ,height;//  ͼƬ�Ŀ�͸�

	void draw() //��ʾ�����Ϣ
	{
		putimagePng(x_left,y_up,&im_show); // ��ʾ��Ϸ�еĽ�ɫ
	}

	void initialize() //��ʼ��
	{
		ims_runleft.clear(); // ����յ�vector
		ims_runright.clear();
	    ims_hitright.clear();
		ims_beatright.clear();

		loadimage(&im_standright,"res\\standright.png");// ��������վ����ͼƬ
		loadimage(&im_jumpright,"res\\jumpIMG\\jumpright.png");// ����������Ծ��ͼƬ

		playerStatus = standright; // ��ʼΪ����վ������Ϸ״̬
		im_show = im_standright;  // ��ʼ��ʾ����վ����ͼƬ
		width = im_show.getwidth(); //��ó�ʼͼ��Ŀ�͸�
		height = im_show.getheight();

		TCHAR filename[100]; // �洢��������
        for(int i=0;i<3;i++) // �����ұ��ܵ�3��ͼƬ������ӵ�ims_runright��
	   {
		//��ʽ����ӡ:sprintf
		_stprintf(filename,"res\\player1runright\\%03d.png",i);
		//���ز���
		IMAGE im;
		loadimage(&im,filename);
		ims_runright.push_back(im);
	    }

		for(int i=0;i<4;i++) // �������ܵ�4��ͼƬ������ӵ�ims_runleft��
	   {
		_stprintf(filename,"res\\player1runleft\\%03d.png",i);
		IMAGE im;
		loadimage(&im,filename);
		ims_runleft.push_back(im);
	    }

		for(int i=0;i<5;i++) // �����ҷ����5��ͼƬ������ӵ�ims_hitright��
	   {
		_stprintf(filename,"res\\hitright\\%03d.png",i);
		IMAGE im;
		loadimage(&im,filename);
		ims_hitright.push_back(im);
	    }

		for(int i=0;i<4;i++) // �����һ����4��ͼƬ������ӵ�ims_hitright��
	   {
		_stprintf(filename,"res\\beatright\\%03d.png",i);
		IMAGE im;
		loadimage(&im,filename);
		ims_beatright.push_back(im);
	    }

		animId = 0; //����id��ʼ��Ϊ0

		// ���ý�ɫxz�����λ��
		x_left = 200;
		y_up = 570 -height;
		ground = 570;

		vx = 10; // ���ó��ٶ�
		vy = 0;
		gravity = 3;
	}

	void runRight() //��ɫ���ұ���
	{
		if(x_left<=400)
		{
		x_left += vx; //���������������ƶ�
	    if(playerStatus == standright||playerStatus == runleft) // ���֮ǰ�Ľ�ɫ״̬�������ұ���
		{
			playerStatus = runright; // �л�Ϊ���ұ��ܵ�״̬
			animId = 0;  // ��������id��ʼ��Ϊ0
		}
		else // ��ʾ֮ǰ�������ұ��ܵ�״̬
		{
			animId++; // ����ͼƬ��ʼ�л�
			if(animId>=ims_runright.size()) // ѭ���л�
				animId = 0;
		}
		im_show = ims_runright[animId];  // Ҫ��ʾ��ͼƬ
		}
	}

	void runLeft() //��ɫ������
	{
	  if(x_left>=0)
	  {
		x_left -= vx; //�������С�����ƶ�
		if(playerStatus == runright||playerStatus == standright) // ���֮ǰ�Ľ�ɫ״̬����������
		{
			playerStatus = runleft; // �л�Ϊ�����ܵ�״̬
			animId = 0;  // ��������id��ʼ��Ϊ0
		}
		else // ��ʾ֮ǰ���������ܵ�״̬
		{
			animId++; // ����ͼƬ��ʼ�л�
			if(animId>=ims_runleft.size()) // ѭ���л�
				animId = 0;
		}
		im_show = ims_runleft[animId];  // Ҫ��ʾ��ͼƬ
	  }
	}

	void hitRight(Ball &ball) // ��ɫ����
	{
		static int time = 0;
		static int song = 0; // �ж��Ƿ񲥷�����
		if(time<2){
			im_show = ims_hitright[0];
			time++;
		}
		if(time>=2 && time <4)
		{
			im_show = ims_hitright[1];
			time++;
			if(abs(y_up+79-(ball.y+ball.ball_height/2))<=15&&abs(x_left+115-(ball.x+ball.ball_width/2))<=14)//�ж��Ƿ�������
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

	void beatRight(Ball &ball) // ��ɫ����
	{
		static int song = 0; // �ж��Ƿ񲥷�����
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

	void standStill() // ���ý�ɫĬ��Ϊվ��״̬
	{
	   if (playerStatus==runleft || playerStatus == standright||playerStatus==runright)
			im_show = im_standright;
	}

	void beginJump() // ��ɫ��Ծ����
	{
		if(playerStatus!=jumpright) // �Ѿ��ڿ���������
		{
			im_show = im_jumpright; // �л���������ͼƬ
			playerStatus = jumpright; // �л���������״̬
			vy = -24; // ����ɫ���ϵĳ��ٶ�
		}
	}

	void updateYcoordinate() // xΪ���̿��ƣ�yΪ�Զ����µ�
	{
		if(playerStatus==jumpright) // ��ǰ���ڿ�����Ծ״̬
		{
			vy +=gravity; // y�����ٶ�������Ӱ��仯
			y_up +=vy; // y����λ��������Ӱ��仯
			ground = y_up + height;
     		if((y_up+height)>=570) // ��ֹ�䵽����֮��
			{
				y_up = 570 - height; // ��֤�����䵽������
				// ��غ��л���վ��ͼ��
                playerStatus = standright;
			    im_show = im_standright;   
		    }
		}

	}
};

class Player2 //���2���Ƶ���Ϸ��ɫ��
{
public:
	IMAGE im_show;// ���2��ǰʱ��Ҫ��ʾ��ͼ��
	IMAGE im_standleft;
	IMAGE im_jumpleft;
	vector <IMAGE> ims_runright; // ���ұ��ܵ�ͼ������
	vector <IMAGE> ims_runleft; // �����ܵ�ͼ������
	vector <IMAGE> ims_hitleft; // �������ͼ������
	vector <IMAGE> ims_beatleft; // ��������ͼ������

	int animId; // ����ѭ�����Ŷ�����id

	PlayerStatus playerStatus; // ��ǰ��״̬

	float x_left,y_up,x_right,ground; //�������������ж���ײ
	float vx,vy; //�ٶ�
	float gravity; // �������ٶ�
	float width ,height;//  ͼƬ�Ŀ�͸�

	void draw() //��ʾ�����Ϣ
	{
       putimagePng(x_left,y_up,&im_show); // ��ʾ��Ϸ�еĽ�ɫ
	}

	void initialize() //��ʼ��
	{
		ims_runleft.clear(); // ����յ�vector
		ims_runright.clear();
		ims_hitleft.clear();
		ims_beatleft.clear();
		loadimage(&im_standleft,"res\\standleft.png");// ��������վ����ͼƬ
		loadimage(&im_jumpleft,"res\\jumpIMG\\jumpleft.png");// ����������Ծ��ͼƬ

		playerStatus = standleft; // ��ʼΪ����վ������Ϸ״̬
		im_show = im_standleft;  // ��ʼ��ʾ����վ����ͼƬ
		width = im_show.getwidth(); // ���ͼ��Ŀ�͸ߣ����ж���ͼƬ��Сһ��
		height = im_show.getheight();

		TCHAR filename[50]; // �洢��������
        for(int i=0;i<5;i++) // �����ұ��ܵ�5��ͼƬ������ӵ�ims_runright��
	   {
		//��ʽ����ӡ:sprintf
		_stprintf(filename,"res\\player2runright\\%03d.png",i);
		//���ز���
		IMAGE im;
		loadimage(&im,filename);
		ims_runright.push_back(im);
	    }
		for(int i=0;i<6;i++) // �������ܵ�6��ͼƬ������ӵ�ims_runright��
	   {
		_stprintf(filename,"res\\player2runleft\\%03d.png",i);
		IMAGE im;
		loadimage(&im,filename);
		ims_runleft.push_back(im);
	    }
		for(int i=0;i<5;i++) // ���������5��ͼƬ������ӵ�ims_hitright��
		{
			_stprintf(filename,"res\\hitleft\\%03d.png",i);
			IMAGE im;
			loadimage(&im,filename);
			ims_hitleft.push_back(im);
		}

		for(int i=0;i<4;i++) // ����������4��ͼƬ������ӵ�ims_hitright��
		{
			_stprintf(filename,"res\\beatleft\\%03d.png",i);
			IMAGE im;
			loadimage(&im,filename);
			ims_beatleft.push_back(im);
		}

		animId = 0; //����id��ʼ��Ϊ0

		// ���ý�ɫ��λ��
		x_left = 712;
		y_up = 570 -height;
		ground = 570;

		vx = 10; // ���ó��ٶ�
		vy = 0;
		gravity = 3;
	}

	void runRight() //��ɫ���ұ���
	{
		if(x_left<=910)
		{
		x_left += vx; //���������������ƶ�
	    if(playerStatus == runleft||playerStatus == standleft) // ���֮ǰ�Ľ�ɫ״̬�������ұ���
		{
			playerStatus = runright; // �л�Ϊ���ұ��ܵ�״̬
			animId = 0;  // ��������id��ʼ��Ϊ0
		}
		else // ��ʾ֮ǰ�������ұ��ܵ�״̬
		{
			animId++; // ����ͼƬ��ʼ�л�
			if(animId>=ims_runright.size()) // ѭ���л�
				animId = 0;
		}
		im_show = ims_runright[animId];  // Ҫ��ʾ��ͼƬ
		}
	}

	void runLeft() //��ɫ������
	{
		if(x_left>=525)
		{
		x_left -= vx; //�������С�����ƶ�
		if(playerStatus == runright||playerStatus == standleft) // ���֮ǰ�Ľ�ɫ״̬����������
		{
			playerStatus = runleft; // �л�Ϊ�����ܵ�״̬
			animId = 0;  // ��������id��ʼ��Ϊ0
		}
		else // ��ʾ֮ǰ���������ܵ�״̬
		{
			animId++; // ����ͼƬ��ʼ�л�
			if(animId>=ims_runleft.size()) // ѭ���л�
				animId = 0;
		}
		im_show = ims_runleft[animId];  // Ҫ��ʾ��ͼƬ
		}
	}

	void hitLeft(Ball &ball) // ��ɫ����
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

	void beatLeft(Ball &ball) // ��ɫ�����ж��Ƿ���У���������ë�򷵻�
	{
		x_right = x_left + width;
		static int time = 0;
		static int song = 0; // �����ж��Ƿ񲥷�����
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

	void standStill() // ���ý�ɫĬ��Ϊվ��״̬
	{
	   if (playerStatus==runleft || playerStatus == standleft ||playerStatus==runright)
			im_show = im_standleft;
	}

	void beginJump() // ��ɫ��Ծ����
	{
		if(playerStatus!=jumpleft) // �Ѿ��ڿ���������
		{
			im_show = im_jumpleft; // �л���������ͼƬ
			playerStatus = jumpleft; // �л���������״̬
			vy = -24; // ����ɫ���ϵĳ��ٶ�
		}
	}

	void updateYcoordinate() // xΪ���̿��ƣ�yΪ�Զ����µ�
	{
		if(playerStatus==jumpleft) // ��ǰ���ڿ�����Ծ״̬
		{
			vy +=gravity; // y�����ٶ�������Ӱ��仯
			y_up +=vy; // y����λ��������Ӱ��仯
			ground = y_up + height;

			if((y_up+height)>=570) // ��ֹ�䵽����֮��
			{
				y_up = 570 - height; // ��֤�����䵽������
				// ��غ��л���վ��ͼ��
                 playerStatus = standleft;
				 im_show = im_standleft;
		    }
		}

	}
};

class Beatball // �������͵Ķ���
{
	public:
		IMAGE im_ball; // ��ë��ͼ�� 
		float x,y; // �̻���ë������

		void initialize() // ��ʼ��
		{
			loadimage(&im_ball,"res\\ball.png",16,16); // ������ë��ͼ��
		}
		void draw1(Player1 &player1) // ��ʾ���1���������Ϣ
		{
			x = player1.x_left+82;
			y = player1.y_up+48;
			putimagePng(x,y,&im_ball); // ����ë�����Ļ�����ë��ͼ��
		}
		void draw2(Player2 &player2) // ��ʾ���2���������Ϣ
		{
			x = player2.x_left-10;
			y = player2.y_up+48;
			putimagePng(x,y,&im_ball); // ����ë�����Ļ�����ë��ͼ��
		}
};

Scene scene; // ���峡��
Player1 player1; // �������1���Ƶ���Ϸ��ɫ����
Player2 player2; // �������2���Ƶ���Ϸ��ɫ����
Ball ball; // ������ë��
Beatball beatball;//���巢��
Timer timer;  // ��ȷ��ʱ

void startup() //��ʼ��
{
	mciSendString(_T("open res\\game_music.mp3 alias bkmusic"), NULL, 0, NULL);//�򿪱�������
	mciSendString(_T("play bkmusic repeat"), NULL, 0, NULL);  // ѭ������

	player1.initialize();
	player2.initialize();
	scene.initialize();
	beatball.initialize();
	ball.initialize();

	initgraph(WIDTH,HEIGHT); // �¿�һ������
    BeginBatchDraw(); // ��ʼ��������

	while(gameStatus==0) // ������ʾ��ʼ��Ϸ����
		startMenu();
}

void show() // ��ʾ
{
	while(gameStatus==3)
		pauseMenu();  // ��Ϸ��ͣ��Ĳ˵����棬һ�㰴Esc�������ý���

	scene.draw(); // ��ʾ���������Ϣ
	player1.draw(); // ��ʾ���1�����Ϣ
	player2.draw(); // ��ʾ���2�����Ϣ
	if(cnt5==0){//��ë�������1�ƶ�
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
	if(cnt5==1){//��ë�������2�ƶ�
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
	timer.Sleep(50); //��ͣ���ɺ���
}

void updateWithoutInput()  // �������޹صĸ���
{
	player1.updateYcoordinate(); 
	player2.updateYcoordinate(); 
    ball.collideWallorGroundorNet();
	if(ball.y>=554&&ball.x>=515)//��ë���䵽�ұ�
	{
		cnt1 = 0;
		cnt2 = 0;
		player1.initialize();
	    player2.initialize();
	    ball.initialize();
		cnt5 = 0;
	}
	if(ball.y>=554&&ball.x<=485)//��ë���䵽���
	{
		cnt3 = 0;
		cnt4 = 0;
		player1.initialize();
	    player2.initialize();
	    ball.initialize();
		cnt5 = 1;
	}
 }

void updateWithInput() // �������йصĸ���
{
	player1.standStill(); // ��ɫ1Ĭ��Ϊվ��
	player2.standStill(); // ��ɫ2Ĭ��Ϊվ��

	if(kbhit())  //������ʱ�л�ͼƬ��ı�λ�ý�ɫ1
	{
		if(GetAsyncKeyState('A')) // ����
		{
			player1.runLeft();
		}
		if (GetAsyncKeyState('D')) // ����
		{
			player1.runRight();
		}
		if (GetAsyncKeyState('W')) // ����
		{
			player1.beginJump();
		}
		if(GetAsyncKeyState('E'))
		{
			ishit1=1;//����
			cnt1 = 1;
		}
		if(GetAsyncKeyState('S'))
		{
			isbeat1=1;//����
		}
	}
	if(kbhit())  //������ʱ�л�ͼƬ��ı�λ�ý�ɫ2
	{
		if(GetAsyncKeyState(VK_LEFT)) // ����
		{
			player2.runLeft();
		}
		if (GetAsyncKeyState(VK_RIGHT)) // ����
		{
			player2.runRight();
		}
		if (GetAsyncKeyState(VK_UP)) // ����
		{
			player2.beginJump();
		}
		if (GetAsyncKeyState(VK_RETURN)) // ����
		{
			ishit2=1;
			cnt3 = 1;
		}
		if (GetAsyncKeyState(VK_DOWN)) // ����
		{
			isbeat2=1;
		}
	}
	if(kbhit())  
	{
		if(GetAsyncKeyState(VK_ESCAPE)) // ��Esc��ʱ��ʾ��ͣ��Ϸ����
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

int main()   //������
{
	startup();  //��ʼ��
	while(1)   //  һֱѭ��
	{
		if(ishit1==1)
		player1.hitRight(ball);
		if(isbeat1==1)
		player1.beatRight(ball);
		if(ishit2==1)
		player2.hitLeft(ball);
		if(isbeat2==1)
		player2.beatLeft(ball);
		show();      //  ��ʾ
		updateWithoutInput();  //�������޹صĸ���
		updateWithInput();    //�������йصĸ���
	}
	gameover();//��Ϸ����
	return 0;
}
