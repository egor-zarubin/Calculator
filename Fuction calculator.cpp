#include"TXlib.h"
#include <fstream>
using namespace std;
void inter (bool *Button1 ,bool *Button2 ,bool *Button3 ,bool *ButtonK ,bool *ButtonA ,bool *ButtonLeft ,bool *ButtonRight ,bool *ButtonSpace ,bool *ButtonTab ,bool *ButtonUp ,bool *ButtonDown,bool *ButtonQ,bool *ButtonS,bool *ButtonW,bool *ButtonM,bool *ButtonControl);
double model (double a);
double Conversion(string str);
int main()
{
    bool Button1=false ,Button2=false ,Button3=false,ButtonK=false ,ButtonA=false ,ButtonLeft=false ,ButtonRight=false ,ButtonSpace=false,ButtonTab=false,ButtonUp=false,ButtonDown=false,ButtonQ=false,ButtonC=false,ButtonB=false,ButtonM=false,ButtonControl=false ;

    txCreateWindow(1200,800);
    txClear();
    txSetColor(TX_BLACK);

    HDC InfoButton=txLoadImage("infobutton.bmp");
    HDC SavingButtons=txLoadImage("savingbuttons.bmp");
    HDC Instruction=txLoadImage("instruction.bmp");
    HDC Properties1=txLoadImage("Properties1.bmp");
    HDC Properties2=txLoadImage("Properties2.bmp");
    HDC Properties3=txLoadImage("Properties3.bmp");
    HDC Properties4=txLoadImage("Properties4.bmp");
    HDC Properties5=txLoadImage("Properties5.bmp");
    HDC Properties6=txLoadImage("Properties6.bmp");
    HDC Properties7=txLoadImage("Properties7.bmp");
    HDC Properties8=txLoadImage("Properties8.bmp");
    HDC Properties9=txLoadImage("Properties9.bmp");
    HDC Properties10=txLoadImage("Properties10.bmp");

    ofstream fout;
    ifstream fin;

    double AbcissaX=1;
    double AbcissaX2;
    double OrdinateY;
    double OrdinateY2;

    int FuctionType=0;

    double ParametrA=0;
    double ParametrB=0;
    double ParametrC=0;
    double ParametrK=0;

    int YMove=0;
    int XMove=0;
    int Scale=20;

    bool ModelMode=false;
    int ModelModeCount=0;
    int ClickCount=0;

    int ButtonACount=0;
    int ButtonKCount=0;
    int ButtonBCount=0;
    int ButtonCCount=0;

    char ParametrAText[6];
    char ParametrBText[6];
    char ParametrCText[6];
    char ParametrKText[6];

    double ParametrsChanging=1;
    int Window=0;

    double PresentedCoordinateX=0;
    char PresentedCoordinateXText[4];
    char PresentedCoordinateYText[4];
    double PresentedCoordinateY=0;
    double ModelModeNumber;

    txBegin();
    while(true)
    {
    if(Window==0)
    {
    ///разметка///////////
    for(int i=-800/(Scale);i<800/(Scale);i++)
    {
    txSetColor(RGB(204,204,255));
    if(i==XMove/400/Scale)
    {
    txSetColor(RGB(255,0,0));
    }
    txLine(0,i*(-Scale)+400+YMove,400,i*(-Scale)+400+YMove);
    txLine(800,i*(-Scale)+400+YMove,400,i*(-Scale)+400+YMove);
    }
    for(int i=-800/(Scale);i<800/(Scale);i++)
    {
    txSetColor(RGB(204,204,255));
    if(i==YMove/400/Scale)
    {
    txSetColor(RGB(255,0,0));
    }
    txLine(i*(-Scale)+400+XMove,0,i*(-Scale)+400+XMove,400);
    txLine(i*(-Scale)+400+XMove,800,i*(-Scale)+400+XMove,400);
    }

    //////////////////////
    ///√–ј‘»  ‘”Ќ÷»»/////
    txSetColor(TX_BLACK);
    ///линейна€
    if(FuctionType==1)
    {
    for(double i=-800/Scale;i<800/Scale;i+=0.01)
    {
    AbcissaX=i;
    AbcissaX2=i+0.01;
    OrdinateY=AbcissaX*ParametrK+ParametrB;
    OrdinateY2=AbcissaX2*ParametrK+ParametrB;
    if(ModelMode)
    {
    OrdinateY=model(OrdinateY);
    OrdinateY2=model(OrdinateY2);
    }
    txLine(AbcissaX*(Scale)+400+XMove,(OrdinateY*(-Scale)+400+YMove),AbcissaX2*(Scale)+400+XMove,(OrdinateY2*(-Scale)+400+YMove));
    }
    }
    ///корень из x
    if(FuctionType==2)
    {
    for(double i=0/Scale;i<800/Scale;i+=0.01)
    {

    AbcissaX=i;
    AbcissaX2=i+0.01;
    OrdinateY=sqrt(i);
    OrdinateY2=sqrt(i+0.01);

    if(ModelMode)
    {
    OrdinateY=model(OrdinateY);
    OrdinateY2=model(OrdinateY2);
    }
    txLine(AbcissaX*(Scale)+400+XMove,(OrdinateY*(-Scale)+400+YMove),AbcissaX2*(Scale)+400+XMove,(OrdinateY2*(-Scale)+400+YMove));
    }
    }
    ///треть€ степень
    if(FuctionType==3)
    {
    for(double i=-800/Scale;i<800/Scale;i+=0.01)
    {
    AbcissaX=i;
    AbcissaX2=i+0.01;
    OrdinateY=AbcissaX*AbcissaX*AbcissaX*ParametrA+AbcissaX*AbcissaX*ParametrB+AbcissaX*ParametrC+ParametrK;
    OrdinateY2=AbcissaX2*AbcissaX2*AbcissaX2*ParametrA+AbcissaX2*AbcissaX2*ParametrB+AbcissaX2*ParametrC+ParametrK;
    if(ModelMode)
    {
    OrdinateY=model(OrdinateY);
    OrdinateY2=model(OrdinateY2);
    }
    txLine(AbcissaX*(Scale)+400+XMove,(OrdinateY*(-Scale)+400+YMove),AbcissaX2*(Scale)+400+XMove,(OrdinateY2*(-Scale)+400+YMove));
    }
    }
    ///втора€ степень
    if(FuctionType==4)
    {
    for(double i=-800/Scale;i<800/Scale;i+=0.01)
    {
    AbcissaX=i;
    OrdinateY=(ParametrA*AbcissaX*AbcissaX)+(AbcissaX*ParametrB)+ParametrC;
    AbcissaX2=i+0.01;
    OrdinateY2=(ParametrA*AbcissaX2*AbcissaX2)+(AbcissaX2*ParametrB)+ParametrC;
    if(ModelMode)
    {
    OrdinateY=model(OrdinateY);
    OrdinateY2=model(OrdinateY2);
    }
    txLine(AbcissaX*(Scale)+400+XMove,(OrdinateY*(-Scale)+400+YMove),AbcissaX2*(Scale)+400+XMove,(OrdinateY2*(-Scale)+400+YMove));
    }
    }
    ///синус
    if(FuctionType==5)
    {
    for(double i=-800/Scale;i<800/Scale;i+=0.01)
    {
    AbcissaX=i;
    AbcissaX2=i+0.01;
    OrdinateY2=(sin(AbcissaX2*ParametrA))*ParametrB+ParametrC;
    OrdinateY=(sin(AbcissaX*ParametrA))*ParametrB+ParametrC;
    if(ModelMode)
    {
    OrdinateY=model(OrdinateY);
    OrdinateY2=model(OrdinateY2);
    }
    txLine(AbcissaX*(Scale)+400+XMove,(OrdinateY*(-Scale)+400+YMove),AbcissaX2*(Scale)+400+XMove,(OrdinateY2*(-Scale)+400+YMove));
    }
    }
    ///косинус
    if(FuctionType==6)
    {
    for(double i=-800/Scale;i<800/Scale;i+=0.01)
    {
    AbcissaX=i;
    AbcissaX2=i+0.01;
    OrdinateY2=(cos(AbcissaX2*ParametrA))*ParametrB+ParametrC;
    OrdinateY=(cos(AbcissaX*ParametrA))*ParametrB+ParametrC;
    if(ModelMode)
    {
    OrdinateY=model(OrdinateY);
    OrdinateY2=model(OrdinateY2);
    }
    txLine(AbcissaX*(Scale)+400+XMove,(OrdinateY*(-Scale)+400+YMove),AbcissaX2*(Scale)+400+XMove,(OrdinateY2*(-Scale)+400+YMove));
    }
    }
    ///тангенс
    if(FuctionType==7)
    {
    for(double i=-800/Scale;i<800/Scale;i+=0.01)
    {
    AbcissaX=i;
    AbcissaX2=i+0.01;
    OrdinateY2=(tan(AbcissaX2*ParametrA))*ParametrB+ParametrC;
    OrdinateY=(tan(AbcissaX*ParametrA))*ParametrB+ParametrC;
    if((OrdinateY*(-Scale)+400)*(OrdinateY2*(-Scale)+400)>=0)
    {
    if(ModelMode)
    {
    OrdinateY=model(OrdinateY);
    OrdinateY2=model(OrdinateY2);
    }
    txLine(AbcissaX*(Scale)+400+XMove,(OrdinateY*(-Scale)+400+YMove),AbcissaX2*(Scale)+400+XMove,(OrdinateY2*(-Scale)+400+YMove));
    }
    }
    }
    ///котангенс
    if(FuctionType==8)
    {
    for(double i=-800/Scale;i<800/Scale;i+=0.03)
    {
    AbcissaX=i;
    AbcissaX2=i+0.03;
    OrdinateY2=(1/(tan(AbcissaX2*ParametrA)))*ParametrB+ParametrC;
    OrdinateY=(1/(tan(AbcissaX*ParametrA)))*ParametrB+ParametrC;
    txSetColor(TX_BLACK);
    if((OrdinateY*(-Scale)+400)*(OrdinateY2*(-Scale)+400)>0)
    {
    if(ModelMode)
    {
    OrdinateY=model(OrdinateY);
    OrdinateY2=model(OrdinateY2);
    }
    txLine(AbcissaX*(Scale)+400+XMove,(OrdinateY*(-Scale)+400+YMove),AbcissaX2*(Scale)+400+XMove,(OrdinateY2*(-Scale)+400+YMove));
    }
    }
    }
    ///a в степени x
    if(FuctionType==9)
    {
    for(double i=-800/Scale;i<800/Scale;i+=1)
    {
    AbcissaX=i;
    AbcissaX2=i+1;
    OrdinateY=ParametrA;
    OrdinateY2=ParametrA;
    for(int i=1;i<AbcissaX;i++)
    {
    OrdinateY=OrdinateY*ParametrA;
    }
    for(int i=1;i<AbcissaX2;i++)
    {
    OrdinateY2=OrdinateY2*ParametrA;
    }
    if(ModelMode)
    {
    OrdinateY=model(OrdinateY);
    OrdinateY2=model(OrdinateY2);
    }
    txLine(AbcissaX*(Scale)+400+XMove,(OrdinateY*(-Scale)+400+YMove),AbcissaX2*(Scale)+400+XMove,(OrdinateY2*(-Scale)+400+YMove));
    }
    }
    ///гипербола
    if(FuctionType==10)
    {
    for(double i=-800/Scale;i<800/Scale;i+=0.01)
    {
    AbcissaX=i;
    AbcissaX2=i+0.01;
    bool a=AbcissaX>=-0.01&&AbcissaX<0.01;
    if(!a)
    {
    OrdinateY2=(ParametrK/AbcissaX2)+ParametrB;
    OrdinateY=(ParametrK/AbcissaX)+ParametrB;
    txSetColor(TX_BLACK);
    if((OrdinateY*(-Scale)+400)*(OrdinateY2*(-Scale)+400)>0)
    {
    if(ModelMode)
    {
    OrdinateY=model(OrdinateY);
    OrdinateY2=model(OrdinateY2);
    }
    txLine(AbcissaX*(Scale)+400+XMove,(OrdinateY*(-Scale)+400+YMove),AbcissaX2*(Scale)+400+XMove,(OrdinateY2*(-Scale)+400+YMove));
    }
    }
    }
    }
    ///арксинус
    if(FuctionType==11)
    {
    for(double i=-800/Scale;i<800/Scale;i+=0.1)
    {
    bool a=AbcissaX<=0.1&&AbcissaX>=-0.1;
    if(i>=-1&&i<=1&&a)
    {
    AbcissaX=i;
    AbcissaX2=i+0.1;
    OrdinateY2=asin(AbcissaX2);
    OrdinateY=asin(AbcissaX);
    if(ModelMode)
    {
    OrdinateY=model(OrdinateY);
    OrdinateY2=model(OrdinateY2);
    }
    txLine(AbcissaX*(Scale)+400+XMove,(OrdinateY*(-Scale)+400+YMove),AbcissaX2*(Scale)+400+XMove,(OrdinateY2*(-Scale)+400+YMove));
    }
    }
    }
    ///арккосинус
    if(FuctionType==12)
    {
    for(double i=-800/Scale;i<800/Scale;i+=0.3)
    {
    if(i>=-1&&i<=1)
    {
    AbcissaX=i;
    AbcissaX2=i+0.01;
    OrdinateY2=(acos(AbcissaX2*ParametrA))*ParametrB+ParametrC;
    OrdinateY=(acos(AbcissaX*ParametrA))*ParametrB+ParametrC;
    if(ModelMode)
    {
    OrdinateY=model(OrdinateY);
    OrdinateY2=model(OrdinateY2);
    }
    txLine(AbcissaX*(Scale)+400+XMove,(OrdinateY*(-Scale)+400+YMove),AbcissaX2*(Scale)+400+XMove,(OrdinateY2*(-Scale)+400+YMove));
    }
    }
    }
    ///арктангенс
    if(FuctionType==13)
    {
    for(double i=-800/Scale;i<800/Scale;i+=0.01)
    {
    AbcissaX=i;
    AbcissaX2=i+0.01;
    OrdinateY2=(atan(AbcissaX2*ParametrA))*ParametrB+ParametrC;
    OrdinateY=(atan(AbcissaX*ParametrA))*ParametrB+ParametrC;
    if((OrdinateY*(-Scale)+400)*(OrdinateY2*(-Scale)+400)>=0)
    {
    if(ModelMode)
    {
    OrdinateY=model(OrdinateY);
    OrdinateY2=model(OrdinateY2);
    }
    txLine(AbcissaX*(Scale)+400+XMove,(OrdinateY*(-Scale)+400+YMove),AbcissaX2*(Scale)+400+XMove,(OrdinateY2*(-Scale)+400+YMove));
    }
    }
    }
    if(FuctionType==14)
    {
    for(double i=-800/Scale;i<800/Scale;i+=0.01)
    {
    AbcissaX=i;
    AbcissaX2=i+0.01;
    OrdinateY2=log(AbcissaX2);
    OrdinateY=log(AbcissaX);

    if(ModelMode)
    {
    OrdinateY=model(OrdinateY);
    OrdinateY2=model(OrdinateY2);
    }
    txLine(AbcissaX*(Scale)+400+XMove,(OrdinateY*(-Scale)+400+YMove),AbcissaX2*(Scale)+400+XMove,(OrdinateY2*(-Scale)+400+YMove));

    }
    }
    ///кнопки/////////////
    txSetColor(TX_BLACK);
    txRectangle(800,0,1200,800);
    for(int i=220;i<810;i+=60)
    {
    txRectangle(900,i,1100,i+30);
    }
    txSelectFont ("Times New Roman",25);
    txTextOut (970,220,"y=kx+b");
    txTextOut (970,280,"y=x^1/2");
    txTextOut (920,340,"y=ax^3+bx^2+cx+k");
    txTextOut (940,400,"y=ax^2+bx+c");
    txTextOut (940,460,"y=b*sin(ax)+c");
    txTextOut (940,520,"y=b*cos(ax)+c");
    txTextOut (940,580,"y=b*tg(ax)+c");
    txTextOut (940,640,"y=b*ctg(ax)+c");
    txTextOut (970,700,"y=a^x");
    txTextOut (970,760,"y=k/x+b");
    txBitBlt (txDC(), 810, 625, 800, 450, SavingButtons, 0, 0);
    if(FuctionType!=0)
    {
    txSetFillColor(TX_BLACK);
    txCircle(839, 511, 32);
    txSetFillColor(TX_WHITE);
    txCircle(839, 511, 28);
    txSelectFont ("Times New Roman",40);
    txTextOut (820, 489,"—в.");
    }
    txBitBlt (txDC(), 807, 553, 800, 450, InfoButton, 0, 0);
    //////////////////////
    ///отображение текущей функции
    txSetColor(TX_BLACK);
    txSelectFont ("Times New Roman",60);
    int x=820;
    int y=10;
    sprintf(ParametrAText,"%g",ParametrA);
    sprintf(ParametrKText,"%g",ParametrK);
    sprintf(ParametrCText,"%g",ParametrC);
    sprintf(ParametrBText,"%g",ParametrB);
    if(!ModelMode)
    {
    switch(FuctionType)
    {
    case 1:
    txTextOut (x,y,"y=kx+b");
    txTextOut (x,y+50,"k=");
    txTextOut (x+50,y+50,ParametrKText);
    txTextOut (x,y+100,"b=");
    txTextOut (x+50,y+100,ParametrBText);
    break;
    case 2:
    txTextOut (x,y,"y=x^1/2");
    break;
    case 3:
    txTextOut (x,y,"ax^3+bx^2+cx+k");
    txTextOut (x,y+50,"a=");
    txTextOut (x+50,y+50,ParametrAText);
    txTextOut (x,y+100,"b=");
    txTextOut (x+50,y+100,ParametrBText);
    txTextOut (x,y+150,"c=");
    txTextOut (x+50,y+150,ParametrCText);
    txTextOut (x+200,y+50,"k=");
    txTextOut (x+250,y+50,ParametrKText);
    break;
    case 4:
    txTextOut (x,y,"y=ax^2+bx+c");
    txTextOut (x,y+50,"a=");
    txTextOut (x+50,y+50,ParametrAText);
    txTextOut (x,y+100,"b=");
    txTextOut (x+50,y+100,ParametrBText);
    txTextOut (x,y+150,"c=");
    txTextOut (x+50,y+150,ParametrCText);
    break;
    case 5:
    txTextOut (x,y,"y=b*sin(ax)+c");
    txTextOut (x,y+50,"a=");
    txTextOut (x+50,y+50,ParametrAText);
    txTextOut (x,y+100,"b=");
    txTextOut (x+50,y+100,ParametrBText);
    txTextOut (x,y+150,"c=");
    txTextOut (x+50,y+150,ParametrCText);
    break;
    case 6:
    txTextOut (x,y,"y=b*cos(ax)+c");
    txTextOut (x,y+50,"a=");
    txTextOut (x+50,y+50,ParametrAText);
    txTextOut (x,y+100,"b=");
    txTextOut (x+50,y+100,ParametrBText);
    txTextOut (x,y+150,"c=");
    txTextOut (x+50,y+150,ParametrCText);
    break;
    case 7:
    txTextOut (x,y,"y=b*tg(ax)+c");
    txTextOut (x,y+50,"a=");
    txTextOut (x+50,y+50,ParametrAText);
    txTextOut (x,y+100,"b=");
    txTextOut (x+50,y+100,ParametrBText);
    txTextOut (x,y+150,"c=");
    txTextOut (x+50,y+150,ParametrCText);
    break;
    case 8:
    txTextOut (x,y,"y=b*ctg(ax)+c");
    txTextOut (x,y+50,"a=");
    txTextOut (x+50,y+50,ParametrAText);
    txTextOut (x,y+100,"b=");
    txTextOut (x+50,y+100,ParametrBText);
    txTextOut (x,y+150,"c=");
    txTextOut (x+50,y+150,ParametrCText);
    break;
    case 9:
    txTextOut (x,y,"y=a^x");
    txTextOut (x,y+50,"a=");
    txTextOut (x+50,y+50,ParametrAText);
    break;
    case 10:
    txTextOut (x,y,"y=k/x+b");
    txTextOut (x,y+50,"k=");
    txTextOut (x+50,y+50,ParametrKText);
    txTextOut (x,y+100,"b=");
    txTextOut (x+50,y+100,ParametrBText);
    break;
    }
    }
    if(ModelMode)
    {
    switch(FuctionType)
    {
    case 1:
    txTextOut (x,y,"y=|kx+b|");
    txTextOut (x,y+50,"k=");
    txTextOut (x+50,y+50,ParametrKText);
    txTextOut (x,y+100,"b=");
    txTextOut (x+50,y+100,ParametrBText);
    break;
    case 2:
    txTextOut (x,y,"y=|x^1/2|");
    break;
    case 3:
    txTextOut (x,y,"|ax^3+bx^2+cx+k|");
    txTextOut (x,y+50,"a=");
    txTextOut (x+50,y+50,ParametrAText);
    txTextOut (x,y+100,"b=");
    txTextOut (x+50,y+100,ParametrBText);
    txTextOut (x,y+150,"c=");
    txTextOut (x+50,y+150,ParametrCText);
    txTextOut (x+200,y+50,"k=");
    txTextOut (x+250,y+50,ParametrKText);
    break;
    case 4:
    txTextOut (x,y,"y=|ax^2+bx+c|");
    txTextOut (x,y+50,"a=");
    txTextOut (x+50,y+50,ParametrAText);
    txTextOut (x,y+100,"b=");
    txTextOut (x+50,y+100,ParametrBText);
    txTextOut (x,y+150,"c=");
    txTextOut (x+50,y+150,ParametrCText);
    break;
    case 5:
    txTextOut (x,y,"y=|b*sin(ax)+c|");
    txTextOut (x,y+50,"a=");
    txTextOut (x+50,y+50,ParametrAText);
    txTextOut (x,y+100,"b=");
    txTextOut (x+50,y+100,ParametrBText);
    txTextOut (x,y+150,"c=");
    txTextOut (x+50,y+150,ParametrCText);
    break;
    case 6:
    txTextOut (x,y,"y=|b*cos(ax)+c|");
    txTextOut (x,y+50,"a=");
    txTextOut (x+50,y+50,ParametrAText);
    txTextOut (x,y+100,"b=");
    txTextOut (x+50,y+100,ParametrBText);
    txTextOut (x,y+150,"c=");
    txTextOut (x+50,y+150,ParametrCText);
    break;
    case 7:
    txTextOut (x,y,"y=|b*tg(ax)+c|");
    txTextOut (x,y+50,"a=");
    txTextOut (x+50,y+50,ParametrAText);
    txTextOut (x,y+100,"b=");
    txTextOut (x+50,y+100,ParametrBText);
    txTextOut (x,y+150,"c=");
    txTextOut (x+50,y+150,ParametrCText);
    break;
    case 8:
    txTextOut (x,y,"y=|b*ctg(ax)+c|");
    txTextOut (x,y+50,"a=");
    txTextOut (x+50,y+50,ParametrAText);
    txTextOut (x,y+100,"b=");
    txTextOut (x+50,y+100,ParametrBText);
    txTextOut (x,y+150,"c=");
    txTextOut (x+50,y+150,ParametrCText);
    break;
    case 9:
    txTextOut (x,y,"y=|a^x|");
    txTextOut (x,y+50,"a=");
    txTextOut (x+50,y+50,ParametrAText);
    break;
    case 10:
    txTextOut (x,y,"y=|k/x+b|");
    txTextOut (x,y+50,"k=");
    txTextOut (x+50,y+50,ParametrKText);
    txTextOut (x,y+100,"b=");
    txTextOut (x+50,y+100,ParametrBText);
    break;
    }
    }
    if((txMouseY()-511)*(txMouseY()-511)+(txMouseX()-839)*(txMouseX()-839)<=32*32&&txMouseButtons()== 1 )
    {
    switch(FuctionType)
    {
    case 1:
    txBitBlt (txDC(), 0, 0, 1200, 800, Properties1, 0, 0);
    break;
    case 2:
    txBitBlt (txDC(), 0, 0, 1200, 800, Properties2, 0, 0);
    break;
    case 3:
    txBitBlt (txDC(), 0, 0, 1200, 800, Properties3, 0, 0);
    break;
    case 4:
    txBitBlt (txDC(), 0, 0, 1200, 800, Properties4, 0, 0);
    break;
    case 5:
    txBitBlt (txDC(), 0, 0, 1200, 800, Properties5, 0, 0);
    break;
    case 6:
    txBitBlt (txDC(), 0, 0, 1200, 800, Properties6, 0, 0);
    break;
    case 7:
    txBitBlt (txDC(), 0, 0, 1200, 800, Properties7, 0, 0);
    break;
    case 8:
    txBitBlt (txDC(), 0, 0, 1200, 800, Properties8, 0, 0);
    break;
    case 9:
    txBitBlt (txDC(), 0, 0, 1200, 800, Properties9, 0, 0);
    break;
    case 10:
    txBitBlt (txDC(), 0, 0, 1200, 800, Properties10, 0, 0);
    break;
    }
    }
    if(txMouseY()>0&&txMouseY()<800&&txMouseX()>0&&txMouseX()<800)
    {
    int j,j2,j3;
    if(txMouseY()>=750)
    {
    j=-40;
    j2=-20;
    j3=-50;
    }
    if(txMouseY()<750)
    {
    j=10;
    j2=30;
    j3=50;
    }
    PresentedCoordinateX=(txMouseX()-400-XMove)*100/(Scale)*0.01;
    PresentedCoordinateY=(txMouseY()-400-YMove)*100/(-Scale)*0.01;
    txRectangle(txMouseX(),txMouseY(),txMouseX()+65,txMouseY()+j3);
    txSelectFont ("Times New Roman",15);
    sprintf(PresentedCoordinateXText,"%g",PresentedCoordinateX);
    txTextOut (txMouseX()+30,txMouseY()+j,PresentedCoordinateXText);
    sprintf(PresentedCoordinateYText,"%g",PresentedCoordinateY);
    txTextOut (txMouseX()+30,txMouseY()+j2,PresentedCoordinateYText);
    txTextOut (txMouseX()+15,txMouseY()+j,"x=");
    txTextOut (txMouseX()+15,txMouseY()+j2,"y=");
    }
    //////////////////////
    ///обработка клавиш///
    inter(&Button1 ,&Button2 ,&Button3 ,&ButtonK ,&ButtonC ,&ButtonLeft ,&ButtonRight ,&ButtonSpace ,&ButtonTab ,&ButtonUp ,&ButtonDown,&ButtonQ,&ButtonA,&ButtonB,&ButtonM,&ButtonControl);
    if(Button1)
    {
    ParametrsChanging=1;
    }
    if(Button2)
    {
    ParametrsChanging=0.1;
    }
    if(Button3)
    {
    ParametrsChanging=0.01;
    }
    if(ButtonM&&ModelModeCount==0)
    {
    ModelMode=!ModelMode;
    ModelModeCount=2;
    }
    if(ButtonUp&&!ButtonControl&&!ButtonB&&!ButtonC&&!ButtonA&&!ButtonK)
    {
    YMove-=400/Scale;
    }
    if(ButtonDown&&!ButtonControl&&!ButtonB&&!ButtonC&&!ButtonA&&!ButtonK)
    {
    YMove+=400/Scale;
    }
    if(ButtonLeft)
    {
    XMove-=400/Scale;
    }
    if(ButtonRight)
    {
    XMove+=400/Scale;
    }
    if(ButtonUp&&ButtonControl)
    {
    Scale++;
    }
    if(ButtonDown&&ButtonControl)
    {
    Scale--;
    }
    if(ButtonUp&&ButtonB&&ButtonBCount==0)
    {
    ParametrB=ParametrB+ParametrsChanging;
    ButtonBCount=2;
    }
    if(ButtonDown&&ButtonB&&ButtonBCount==0)
    {
    ParametrB=ParametrB-ParametrsChanging;
    ButtonBCount=2;
    }
    if(ButtonUp&&ButtonC&&ButtonCCount==0)
    {
    ParametrC=ParametrC+ParametrsChanging;
    ButtonCCount=2;
    }
    if(ButtonDown&&ButtonC&&ButtonCCount==0)
    {
    ParametrC=ParametrC-ParametrsChanging;
    ButtonCCount=2;
    }
    if(ButtonUp&&ButtonK&&ButtonKCount==0)
    {
    ParametrK=ParametrK+ParametrsChanging;
    ButtonKCount=2;
    }
    if(ButtonDown&&ButtonK&&ButtonKCount==0)
    {
    ParametrK=ParametrK-ParametrsChanging;
    ButtonKCount=2;
    }
    if(ButtonUp&&ButtonA&&ButtonACount==0)
    {
    ParametrA=ParametrA+ParametrsChanging;
    ButtonACount=2;
    }
    if(ButtonDown&&ButtonA&&ButtonACount==0)
    {
    ParametrA=ParametrA-ParametrsChanging;
    ButtonACount=2;
    }
    if(FuctionType==9)
    {
    if(ParametrA>1.4)
    {ParametrA=1.4;}
    if(ParametrA<0)
    {ParametrA=0;}
    }
    if(FuctionType==10)
    {
    if(Scale>44)
    {Scale=44;}
    if(Scale<19)
    {Scale=19;}
    }
    if(ParametrB<0.01&&ParametrB>-0.01)
    {ParametrB=0;}
    if(ModelModeCount!=0)
    {
    ModelModeCount--;
    }
    if(ButtonACount!=0)
    {
    ButtonACount--;
    }
    if(ButtonBCount!=0)
    {
    ButtonBCount--;
    }
    if(ButtonCCount!=0)
    {
    ButtonCCount--;
    }
    if(ButtonKCount!=0)
    {
    ButtonKCount--;
    }

    if(txMouseY()>=652&&txMouseY()<=706&&txMouseX()>=810&&txMouseX()<=874&&txMouseButtons()== 1)
    {
    /*
    FuctionTypeSafe=FuctionType;
    ParametrASafe=ParametrA;
    ParametrBSafe=ParametrB;
    ParametrCSafe=ParametrC;
    ParametrKSafe=ParametrK;
    YMoveSafe=YMove;
    XMoveSafe=XMove;
    ScaleSafe=Scale;
    ModelModeSafe=ModelMode;
    */
    if(ModelMode)
    {
    ModelModeNumber=1;
    }
    else
    {
    ModelModeNumber=0;
    }
    double KeepsavingArr[9]={FuctionType,ParametrA,ParametrB,ParametrC,ParametrK,XMove,YMove,Scale,ModelModeNumber};
    fout.open("keepsaving.txt");
    if(!fout.is_open())
    {
    cout<<"error"<<endl;
    }
    else
    {
    for(int i=0;i<9;i++)
    {
    fout<< KeepsavingArr[i]<<endl;
    }
    }
    fout.close();

    }
    if(txMouseY()>=715&&txMouseY()<=773&&txMouseX()>=810&&txMouseX()<=874&&txMouseButtons()== 1)
    {
    /*
    FuctionType=FuctionTypeSafe;
    ParametrA=ParametrASafe;
    ParametrB=ParametrBSafe;
    ParametrC=ParametrCSafe;
    ParametrK=ParametrKSafe;
    YMove=YMoveSafe;
    XMove=XMoveSafe;
    Scale=ScaleSafe;
    ModelMode=ModelModeSafe;
    */
    char str[6];
    fin.open("keepsaving.txt");
    if(!fin.is_open())
    {
    cout<<"error"<<endl;
    }
    else
    {
    int i=0;
    while(!fin.eof())
    {
    fin >> str;
    switch(i)
    {
    case 0:
    FuctionType=atof(str);
    break;
    case 1:
    ParametrA=atof(str);
    break;
    case 2:
    ParametrB=atof(str);
    break;
    case 3:
    ParametrC=atof(str);
    break;
    case 4:
    ParametrK=atof(str);
    break;
    case 5:
    XMove=atof(str);
    break;
    case 6:
    YMove=atof(str);
    break;
    case 7:
    Scale=atof(str);
    break;
    case 8:
    ModelModeNumber=atof(str);
    break;
    }
    i++;
    }
    fin.close();
    if(ModelModeNumber==1)
    {
    ModelMode=true;
    }
    else
    {
    ModelMode=false;
    }

    }

    }
    /////////////////
    if(txMouseX()>=900&&txMouseX()<=1100&&txMouseButtons()== 1)
                {
                if(txMouseY()>=220&&txMouseY()<=250)
                {
                FuctionType=1;
                ParametrA=0;
                ParametrB=0;
                ParametrC=0;
                ParametrK=1;
                YMove=0;
                XMove=0;
                Scale=20;
                ModelMode=false;
                }
                if(txMouseY()>=280&&txMouseY()<=310)
                {
                FuctionType=2;
                ParametrA=0;
                ParametrB=0;
                ParametrC=0;
                ParametrK=0;
                YMove=0;
                XMove=0;
                Scale=20;
                ModelMode=false;
                }
                if(txMouseY()>=340&&txMouseY()<=370)
                {
                FuctionType=3;
                ParametrA=1;
                ParametrB=1;
                ParametrC=1;
                ParametrK=0;
                YMove=0;
                XMove=0;
                Scale=20;
                ModelMode=false;
                }
                if(txMouseY()>=400&&txMouseY()<=430)
                {
                FuctionType=4;
                AbcissaX=1;
                ParametrA=1;
                ParametrB=0;
                ParametrC=0;
                ParametrK=0;
                YMove=0;
                XMove=0;
                Scale=20;
                ModelMode=false;
                }
                if(txMouseY()>=460&&txMouseY()<=490)
                {
                FuctionType=5;
                ParametrA=1;
                ParametrB=1;
                ParametrC=0;
                ParametrK=0;
                YMove=0;
                XMove=0;
                Scale=20;
                ModelMode=false;
                }
                if(txMouseY()>=520&&txMouseY()<=550)
                {
                FuctionType=6;
                ParametrA=1;
                ParametrB=1;
                ParametrC=0;
                ParametrK=0;
                YMove=0;
                XMove=0;
                Scale=20;
                ModelMode=false;
                }
                if(txMouseY()>=580&&txMouseY()<=610)
                {
                FuctionType=7;
                ParametrA=1;
                ParametrB=1;
                ParametrC=0;
                ParametrK=0;
                YMove=0;
                XMove=0;
                Scale=20;
                ModelMode=false;
                }
                if(txMouseY()>=640&&txMouseY()<=670)
                {
                FuctionType=8;
                ParametrA=1;
                ParametrB=1;
                ParametrC=0;
                ParametrK=0;
                YMove=0;
                XMove=0;
                Scale=20;
                ModelMode=false;
                }
                if(txMouseY()>=700&&txMouseY()<=730)
                {
                FuctionType=9;
                ParametrA=1.1;
                ParametrB=0;
                ParametrC=0;
                ParametrK=0;
                YMove=0;
                XMove=0;
                Scale=20;
                ModelMode=false;
                }
                if(txMouseY()>=760&&txMouseY()<=790)
                {
                FuctionType=10;
                ParametrA=0;
                ParametrB=0;
                ParametrC=0;
                ParametrK=1;
                YMove=0;
                XMove=0;
                Scale=20;
                ModelMode=false;
                }
                }
                /*
                if(txMouseX()>=960&&txMouseX()<=1120&&txMouseButtons()== 1)
                {
                if(txMouseY()>=220&&txMouseY()<=250)
                {
                FuctionType=11;
                ParametrA=1;
                ParametrB=1;
                ParametrC=0;
                ParametrK=1;
                YMove=0;
                XMove=0;
                Scale=20;
                ModelMode=false;
                }
                if(txMouseY()>=280&&txMouseY()<=310)
                {
                FuctionType=12;
                ParametrA=1;
                ParametrB=1;
                ParametrC=0;
                ParametrK=0;
                YMove=0;
                XMove=0;
                Scale=20;
                ModelMode=false;
                }
                if(txMouseY()>=340&&txMouseY()<=370)
                {
                FuctionType=13;
                ParametrA=1;
                ParametrB=1;
                ParametrC=0;
                ParametrK=0;
                YMove=0;
                XMove=0;
                Scale=20;
                ModelMode=false;
                }
                if(txMouseY()>=400&&txMouseY()<=430)
                {
                FuctionType=14;
                AbcissaX=1;
                ParametrA=1;
                ParametrB=0;
                ParametrC=0;
                ParametrK=0;
                YMove=0;
                XMove=0;
                Scale=20;
                ModelMode=false;
                }
                if(txMouseY()>=460&&txMouseY()<=490)
                {
                FuctionType=15;
                ParametrA=1;
                ParametrB=1;
                ParametrC=0;
                ParametrK=0;
                YMove=0;
                XMove=0;
                Scale=20;
                ModelMode=false;
                }
                if(txMouseY()>=520&&txMouseY()<=550)
                {
                FuctionType=16;
                ParametrA=1;
                ParametrB=1;
                ParametrC=0;
                ParametrK=0;
                YMove=0;
                XMove=0;
                Scale=20;
                ModelMode=false;
                }
                if(txMouseY()>=580&&txMouseY()<=610)
                {
                FuctionType=17;
                ParametrA=1;
                ParametrB=1;
                ParametrC=0;
                ParametrK=0;
                YMove=0;
                XMove=0;
                Scale=20;
                ModelMode=false;
                }
                if(txMouseY()>=640&&txMouseY()<=670)
                {
                FuctionType=18;
                ParametrA=1;
                ParametrB=1;
                ParametrC=0;
                ParametrK=0;
                YMove=0;
                XMove=0;
                Scale=20;
                ModelMode=false;
                }
                if(txMouseY()>=700&&txMouseY()<=730)
                {
                FuctionType=19;
                ParametrA=1.1;
                ParametrB=0;
                ParametrC=0;
                ParametrK=0;
                YMove=0;
                XMove=0;
                Scale=20;
                ModelMode=false;
                }
                if(txMouseY()>=760&&txMouseY()<=790)
                {
                FuctionType=20;
                ParametrA=0;
                ParametrB=0;
                ParametrC=0;
                ParametrK=1;
                YMove=0;
                XMove=0;
                Scale=20;
                ModelMode=false;
                }
                }
                */
                if((txMouseY()-585)*(txMouseY()-585)+(txMouseX()-839)*(txMouseX()-839)<=32*32&&txMouseButtons()== 1 )
                {Window=1;
                ClickCount=5;}
    if(Scale>100)
    {Scale=100;}
    if(Scale<15)
    {Scale=15;}
    if(XMove>400)
    {XMove=400;}
    if(XMove<-400)
    {XMove=-400;}
    if(YMove>400)
    {YMove=400;}
    if(YMove<-400)
    {YMove=-400;}

    }
    if(Window==1)
    {
    txRectangle(20,30,150,80);
    txRectangle(1050,30,1180,80);
    txTextOut (30,20,"назад");
    txTextOut (1050,20,"выход");
    txTextOut (440,20,"»Ќ—“–” ÷»я");
    txBitBlt (txDC(), 450, 100, 800, 800,Instruction, 0, 0);
    if(txMouseY()>30&&txMouseY()<80&&txMouseButtons()== 1 )
    {
    if(txMouseX()>20&&txMouseX()<150)
    {
    Window=0;
    }
    if(txMouseX()>1050&&txMouseX()<1180&&ClickCount==0)
    {
    txClear();
    break;
    }
    }
    inter(&Button1 ,&Button2 ,&Button3 ,&ButtonK ,&ButtonC ,&ButtonLeft ,&ButtonRight ,&ButtonSpace ,&ButtonTab ,&ButtonUp ,&ButtonDown,&ButtonQ,&ButtonA,&ButtonB,&ButtonM,&ButtonControl);
    }
    if(ClickCount!=0)
    {ClickCount--;}
    txSleep(20);
    txClear();
    }
    txEnd();
    txDeleteDC (InfoButton);
    txDeleteDC (SavingButtons);
    txDeleteDC (Instruction);
    txDeleteDC (Properties1);
    txDeleteDC (Properties2);
    txDeleteDC (Properties3);
    txDeleteDC (Properties4);
    txDeleteDC (Properties5);
    txDeleteDC (Properties6);
    txDeleteDC (Properties7);
    txDeleteDC (Properties8);
    txDeleteDC (Properties9);
    txDeleteDC (Properties10);
    return 0;
}
void inter (bool *Button1 ,bool *Button2 ,bool *Button3 ,bool *ButtonK ,bool *ButtonC ,bool *ButtonLeft ,bool *ButtonRight ,bool *ButtonSpace ,bool *ButtonTab ,bool *ButtonUp ,bool *ButtonDown,bool *ButtonQ,bool *ButtonA,bool *ButtonB,bool *ButtonM,bool *ButtonControl)
    {
        if(GetAsyncKeyState(VK_UP))
        {
            *ButtonUp=true;
        }
        else
        {
            *ButtonUp=false;
        }
        if(GetAsyncKeyState(VK_DOWN))
        {
            *ButtonDown=true;
        }
        else
        {
            *ButtonDown=false;
        }
        if(GetAsyncKeyState(VK_LEFT))
        {
            *ButtonLeft=true;
        }
        else
        {
            *ButtonLeft=false;
        }
        if(GetAsyncKeyState(VK_RIGHT))
        {
            *ButtonRight=true;
        }
        else
        {
            *ButtonRight=false;
        }
        if(GetAsyncKeyState(VK_SPACE))
        {
            *ButtonSpace=true;
        }
        else
        {
            *ButtonSpace=false;
        }
        if(GetAsyncKeyState(VK_TAB))
        {
            *ButtonTab=true;
        }
        else
        {
            *ButtonTab=false;
        }
        if(GetAsyncKeyState(65))
        {
            *ButtonA=true;
        }
        else
        {
            *ButtonA=false;
        }
        if(GetAsyncKeyState(75))
        {
            *ButtonK=true;
        }
        else
        {
            *ButtonK=false;
        }
        if(GetAsyncKeyState(81))
        {
            *ButtonQ=true;
        }
        else
        {
            *ButtonQ=false;
        }
        if(GetAsyncKeyState(66))
        {
            *ButtonB=true;
        }
        else
        {
            *ButtonB=false;
        }
        if(GetAsyncKeyState(67))
        {
            *ButtonC=true;
        }
        else
        {
            *ButtonC=false;
        }
        if(GetAsyncKeyState(77))
        {
            *ButtonM=true;
        }
        else
        {
            *ButtonM=false;
        }
        if(GetAsyncKeyState(VK_CONTROL))
        {
            *ButtonControl=true;
        }
        else
        {
            *ButtonControl=false;
        }
         if(GetAsyncKeyState(49))
        {
            *Button1=true;
        }
        else
        {
            *Button1=false;
        }
         if(GetAsyncKeyState(50))
        {
            *Button2=true;
        }
        else
        {
            *Button2=false;
        }
         if(GetAsyncKeyState(51))
        {
            *Button3=true;
        }
        else
        {
            *Button3=false;
        }
    }
double model(double a)
{
if(a<0)
{
a=a*(-1);
}
return a;
}
double Conversion(string str)
{
double Original=0;
double Multiplier=0.01;
bool negative=false;
for(int i=str.length()-1;i>=0;i--)
{
if((int)str[i]==45)
{
negative=true;
}
else
{
Original=Original+((int)str[i]-48)*Multiplier;
Multiplier=Multiplier*10;
}
}
if(negative)
{
Original=Original*(-1);
}
return Original;
}
