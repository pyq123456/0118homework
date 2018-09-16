#include <QCoreApplication>
#include<QDebug>
#include<Qlist>
typedef quint8 byte;//定义8位字符
typedef quint32 word;//定义32位字符
#define MAX(x,y) (((x)>(y))?(x):(y))//取两数中最大值
#define MIN(x,y) (((x)<(y))?(x):(y))//取两数中最小值
#define HHI(xxx) ((byte)(((word)(xxx)>>24)))//取32位数中的高位中的高8位
#define LHI(xxx) ((byte)(((word)(xxx)>>16)&0xFF))//取32位数中的高位中的低8位
#define LLO(xxx) ((byte)(((word)(xxx)&0xFF)))//取32位数中的低位中的低8位
#define HLO(xxx) ((byte)(((word)(xxx)>>8)&0xFF))//取32位数的低位中的高8位
#define n 0x12345678//定义32位无符号整型数
int main()
{

    QList<quint8> vaules;//定义一个8位无符号整型结构体
    vaules<<HHI(n)<<LHI(n)<<HLO(n)<<LLO(n);//取出高位中的高8位、高位中的低8位、低位中的高8位、低位中的低8位,并存入vaules这个数组中
    qDebug("原始值：  0x%x==%d",n,n);//输出原数
    qDebug("高位中的高8位的值：0x%x==%d ",HHI(n),HHI(n));//输出高位中的高8位
    qDebug("高位中的低8位的值：0x%x==%d ",LHI(n),LHI(n));//输出高位中的低8位
    qDebug("低位中的高8位的值：0x%x==%d ",HLO(n),HLO(n));//输出低位中的高8位
    qDebug("低位中的低8位的值：0x%x==%d ",LLO(n),LLO(n));//输出低位中的低8位
    qDebug("高位中的高8位和高位中的低8位的最大值：  0x%x <%d>",MAX(HHI(n), LHI(n)),MAX(HHI(n), LHI(n)));//输出高位中的高8位和高位中的低8位的最大值
    qDebug("低位中的高8位和低位中的低8位的最小值：  0x%x <%d>",MIN(HLO(n), LLO(n)),MIN(HLO(n), LLO(n)));//输出低位中的高8位和低位中的低8位的最小值
    quint32 m=(LHI(n))<<0|(LLO(n))<<8|(HHI(n))<<16|(HLO(n))<<24;//组合成一个新的32位无符号整形数，由高位到低位分别为原低位中的低8位、高位中的高8位、高位中的低8位和高位中的高8位
    qDebug("重新组合后的数值：  0x%x <%d>",m,m);//输出重新组合后的数组
    qDebug()<<"排序前的："<<vaules;//输出排序前的vaules数组
    std::sort(vaules.begin(),vaules.end(),std::greater<quint8>());//将vaules数组进行降序排序
    qDebug()<<"排序后的："<<vaules;//输出排序后的vaules数组
    return 0;
}
