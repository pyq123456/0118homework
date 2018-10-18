#include <QCoreApplication>
#include <QDebug>
#include <QVector>
#include <QTextStream>
#include <QFile>


namespace SK {     //定义命名空间SK，将文本文件划分为不同的列
enum SortKind{
    col01    =   0x00000001<<0,         //!< 第1列
    col02    =   0x00000001<<1,         //!< 第2列
    col03    =   0x00000001<<2,         //!< 第3列
    col04    =   0x00000001<<3,         //!< 第4列
    col05    =   0x00000001<<4,         //!< 第5列
    col06    =   0x00000001<<5,         //!< 第6列
    col07    =   0x00000001<<6,         //!< 第7列
    col08    =   0x00000001<<7,         //!< 第8列
    col09    =   0x00000001<<8,         //!< 第9列
    col10    =   0x00000001<<9,         //!< 第10列
    col11    =   0x00000001<<10,        //!< 第11列
    col12    =   0x00000001<<11,        //!< 第12列
    col13    =   0x00000001<<12,        //!< 第13列
    col14    =   0x00000001<<13,        //!< 第14列
    col15    =   0x00000001<<14,        //!< 第15列
    col16    =   0x00000001<<15,        //!< 第16列
    col17    =   0x00000001<<16,        //!< 第17列
    col18    =   0x00000001<<17,        //!< 第18列
    col19    =   0x00000001<<18,        //!< 第19列
    col20    =   0x00000001<<19,        //!< 第20列
    col21    =   0x00000001<<20,        //!< 第21列
    col22    =   0x00000001<<21,        //!< 第22列
    col23    =   0x00000001<<22,        //!< 第23列
    col24    =   0x00000001<<23,        //!< 第24列
    col25    =   0x00000001<<24,        //!< 第25列
    col26    =   0x00000001<<25,        //!< 第26列
    col27    =   0x00000001<<26,        //!< 第27列
    col28    =   0x00000001<<27,        //!< 第28列
    col29    =   0x00000001<<28,        //!< 第29列
    col30    =   0x00000001<<29,        //!< 第30列
    col31    =   0x00000001<<30,        //!< 第31列
    col32    =   0x00000001<<31,        //!< 第32列
};
}

//信息存储结构体
typedef struct
{
    QStringList student;       //定义一个字符串类student
} studData;

QDebug operator << (QDebug d, const studData &data)                //重载 " << "符号
{
    for(int i=0;i<data.student.size();i++)
    d.noquote().nospace()<<QString(data.student.at(i))<<"\t" ;    //按照要求分别输出每一行的学生数据
    return d;
}

class myCmp                                                       //定义比较类
{
public:
    myCmp(int selectedColumn) { this->currentColumn = selectedColumn; }
    bool operator() (const studData& d1,const studData& d2) ;
private:
    int currentColumn;
};

#define rule(q)   (d1.student.at(q)>=d2.student.at(q))?  1:0       //宏定义学生的成绩比较规则
bool myCmp::operator()(const studData &d1,const  studData &d2)     //比较的规则
{
    bool result = false;
    quint32 sortedColumn = 0x00000001<<currentColumn;
    switch (sortedColumn)
    {
       case SK::col01:result=rule(1);break;                        //调用宏定义学生的成绩比较规则
       case SK::col02:result=rule(2);break;
       case SK::col03:result=rule(3);break;
       case SK::col04:result=rule(4);break;
       case SK::col05:result=rule(5);break;
       case SK::col06:result=rule(6);break;
       case SK::col07:result=rule(7);break;
       case SK::col08:result=rule(8);break;
       case SK::col09:result=rule(9);break;
       case SK::col10:result=rule(10);break;
       case SK::col11:result=rule(11);break;
       case SK::col12:result=rule(12);break;
       case SK::col13:result=rule(13);break;
       case SK::col14:result=rule(14);break;
       case SK::col15:result=rule(15);break;
       case SK::col16:result=rule(16);break;
       case SK::col17:result=rule(17);break;
       case SK::col18:result=rule(18);break;
       case SK::col19:result=rule(19);break;
       case SK::col20:result=rule(20);break;
       case SK::col21:result=rule(21);break;
       case SK::col22:result=rule(22);break;
       case SK::col23:result=rule(23);break;
       case SK::col24:result=rule(24);break;
       case SK::col25:result=rule(25);break;
       case SK::col26:result=rule(26);break;
       case SK::col27:result=rule(27);break;
       case SK::col28:result=rule(28);break;
       case SK::col29:result=rule(29);break;
       case SK::col30:result=rule(30);break;
       case SK::col31:result=rule(31);break;
       case SK::col32:result=rule(32);break;
       default:;break;
    }
    return result;
}
class ScoreSorter                         //排序执行类
{
public:
    ScoreSorter(QString dataFile);
    void read();                         //定义成员函数，读文件
    void sort();                        //定义成员函数，排序
    void super(quint8 age);
    friend QDebug operator << (QDebug d, const studData &data);
private:
    QString route;
    QList<studData > data;
    studData constellation;
};

ScoreSorter::ScoreSorter(QString dataFile)  //进行初始化
{
    this->route=dataFile;
}
void ScoreSorter::read()               //对文件进行读取，将数据进行整理
{
    QFile file(this->route);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"Can't open the file!"<<endl;
    }
    QString titile(file.readLine());
    this->constellation.student = titile.split(" ", QString::SkipEmptyParts);      //对文件进行读取
    if((this->constellation.student).last() == "\n") this->constellation.student.removeLast();
    studData eachdata;
    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        QString str(line);
        eachdata.student = str.split(" ", QString::SkipEmptyParts);
        if((eachdata.student).last() == "\n") eachdata.student.removeLast();
        if(eachdata.student.size()==0) continue;
        this->data.append(eachdata);
    }
    file.close();
}
void ScoreSorter::sort()//ScoreSorter类中排序函数
{
    for(int i=1;i<this->constellation.student.size();i++)
    {
        myCmp stducmp(i-1);                                                        //对规则对象进行初始化排序
        std::sort(this->data.begin() , this->data.end() , stducmp );               //进行排序
        qDebug()<<"排序后输出，当前排序第 "<<i+1 <<" 列：";
        qDebug() << '\t'<< (this->constellation);    //qDebug重载输出
        for(int i=0;i<this->data.size();i++)  qDebug() << this->data.at(i);
        qDebug()<<"---------------------------------------------------------------\n";
        this->super(i+1);                                                          //当前排序规则下的data 输出到文件
    }
}
void ScoreSorter::super(quint8 age)
{
    QFile file("sorted_"+this->route);
    file.open(QIODevice::ReadWrite | QIODevice::Append);
    QTextStream stream(&file);
    stream.setCodec("UTF-8");
    stream<<QString("排序后输出，当前排序第 ")<<age <<QString(" 列：")<<"\r\n";
    stream<<"\t";
    for(int j=0;j<this->constellation.student.size();j++)
        stream<<this->constellation.student.at(j)<<"\t";
        stream<<"\r\n";
    for(int i=0;i<this->data.size();i++)
    {
        for(int j=0;j<this->constellation.student.size();j++)
        stream<<this->data.at(i).student.at(j)<<"\t";
        stream<<"\r\n";
    }
    stream<<"------------------------------------------------------------------"<<"\r\n\r\n";
    file.close();
}
void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    // 自定义qDebug
        QFile file("Sorter_data.txt");               // 输出信息保存至文件Sorter_data.txt中
        file.open(QIODevice::WriteOnly | QIODevice::Append);
        QTextStream stream(&file);
        stream <<msg << endl;
        file.flush();
        file.close();
        QTextStream ts (stdout);
        ts << msg << endl;
        file.flush();
        file.close();
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
        Q_UNUSED(argc);
        Q_UNUSED(argv);
    qInstallMessageHandler(myMessageOutput);     //调用myMessageOutput函数
    QString datafile = "data.txt";
    QFile f("sorted_"+datafile);
    if (f.exists())  f.remove();
    ScoreSorter s(datafile);
    s.read();                       //读取data.txt文件
    s.sort();                       //排序输出
    return 0;
}
