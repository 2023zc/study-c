#include<bits/stdc++.h>
using namespace std;
class Point{
private:
    double *x, *y;


public:    
    //空参构造
    Point(){
        x=new double,y=new double;  //申请内存
        *x=0,*y=0;    //初始化为0,不要写成x=0,y=0;
    };


    /*用const * 修饰传入的指针有两大好处:
    * 1.const防止意外修改传入的指针
    * 2.用指针传递可以不让函数生成临时变量，减少临时变量复制，析构等操作的时间，提高效率
    */
    Point(const Point *other){   //普通拷贝函数
        x=new double,y=new double;  //申请新的内存空间
        this->x=other->x,this->y=other->y;  //赋值
    }


    /*不建议使用const *修饰,原因有两点:
    *1.因为double 是内置的数据类型,而内置的数据类型在值传递和地址传递的效率是差不多的
    *2.加了const * 反而会降低代码可读性
    */
    Point(double X,double Y){  //普通构造函数
        x=new double,y=new double;  //申请内存空间
        *x=X,*y=Y;  //赋值
    }


    //const * 修饰other好处与上述相同
    Point& operator = (const Point &other){    //point的拷贝赋值函数
        if(&other==this){
            return *this;   //防止自赋值:防止间接赋值和地址间接赋值
        }
        delete x,y;  //清除原有的数据
        x=new double,y=new double;  //申请新的内存空间
        this->x=other.x,this->y=other.y;   //实现赋值
        //返回对象本身,切记不要写成 this
        return *this;   
    }

    //const * 修饰other好处与上述相同
    double getDistance(const Point &other){   //得到两点之间距离的函数
        double ans;
        ans=pow(pow(*x-other.getX(),2)+pow(*y-other.getY(),2),0.5);  //勾股定理
        return ans;
    }

    double getX() const{  //返回X的值
        return *x;
    }
    double getY() const{  //返回Y的值
        return *y;
    }

    void setX(double X){  //设置X的值
        *x=X;  
    }
    void setY(double Y){  //设置Y的值
        *y=Y;
    }

    void setXY(double X,double Y){  //设置X,Y的值，通过调用其他成员函数实现
        setX(X);
        setY(Y);
    }

    ~Point(){  //析构函数
        delete x,y;
    }
};
