#include <QCoreApplication>
#include <QDebug>
#include <QList>
#include <QString>
class student         //定义类
{
public:
    int Number;
    QString Name;
    int Score1;
    int Score2;

};



bool Namesort(const student t1, const student t2)                                 //定义一个函数，实现姓名比较
{
    if (t1.Name>t2.Name)
        return 1;
    else
        return 0;
}

bool Score1sort(const student t1, const student t2)                                //定义一个函数，实现课程1比较
{
    if (t1.Score1>t2.Score1)
        return 1;
    else
        return 0;
}

bool Score2sort(const student t1, const student t2)                                //定义一个函数，实现课程2比较
{
    if (t1.Score2>t2.Score2)
        return 1;
    else
        return 0;
}
void mulu()       //定义一个目录函数
{
      qDebug()<<"学号\t"<<"\t姓名\t"<<"\t课程1"<<"\t课程2";
}
void shuchu(QList <student> A)    //定义一个输出函数
{
    for(int i=0;i<4;i++)
    {
        qDebug()<<A[i].Number<<"\t"<<A[i].Name<<"\t"<<A[i].Score1<<"\t"<<A[i].Score2;
    }
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    student s[4];
        s[0].Number=1403130209; s[0].Name="鲁智深";  s[0].Score1=80;s[0].Score2=72;
        s[1].Number=1403140101; s[1].Name=" 林冲 ";  s[1].Score1=82;s[1].Score2=76;
        s[2].Number=1403140102; s[2].Name=" 宋江 ";  s[2].Score1=76;s[2].Score2=85;
        s[3].Number=1403140103; s[3].Name=" 武松 ";  s[3].Score1=88;s[3].Score2=80;

        QList <student> A;
          A<<s[0]<<s[1]<<s[2]<<s[3];        //定义一个QList
          qDebug("排序前为：");
          mulu();
          shuchu(A);


          std::sort(A.begin(),A.end(),Namesort);
          qDebug("按姓名排序为：");
          mulu();
          shuchu(A);

          std::sort(A.begin(),A.end(),Score1sort);
          qDebug("按课程1成绩为标准结果排序为：");
          mulu();
          shuchu(A);

          std::sort(A.begin(),A.end(),Score2sort);
          qDebug("按课程2成绩为标准结果排序为：");
          mulu();
          shuchu(A);

          return a.exec();
      }

