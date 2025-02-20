// 4252 函数值 - 数组实现
#include<iostream>
using namespace std;

// 效率不正确

// 考虑迭代返回，整块放入

// 一个有限规模的只需要插入的数组管
template <class elemType>
class pipe{
private:
    elemType* data;
    bool isEmpty;
    int size;
public:
    pipe(int initsize){
        size = initsize;
        data = new elemType[size];
        isEmpty = true;      
    };
    //合并 每次merge相同规模的数组
    void merge(elemType* array){
        if (isEmpty){
            //初始化覆写
            for (int i=0;i<size;++i){
                data[i]=array[i];
            }
            isEmpty=false;
        }
        else{
            //正式归并
            //二分法查找位置

            //正在查找的元素
            elemType *finding = array;

            for(int j=size;j>0;--j){
                int low=0;
                int high=size-1;
                int mid;
                elemType target = *finding;
                int result;

                while(true){
                    if(low>high){
                        result=-1;  //should not happen
                        break;
                    }
                    if(low==high||low==high-1){
                        if(target<data[low])
                            {result=low;break;}
                        else if(target<data[high])
                            {result=high;break;}
                        else{result=high+1;break;}
                    }
                    mid=(low+high)/2;
                    if (data[mid]>target)
                        high=mid;
                    else if(data[mid]<target)
                        low=mid;
                    else{
                        result=mid;
                        break;
                    }
                }

                for(int i=size-2;i>=result;--i)
                    data[i+1]=data[i];
                data[result]=target;

                ++finding;
            }
        }
    }
    //显示
    void disp(){
        for(int i=0;i<size;++i)
            cout<<data[i]<<" ";
    }

};

// 手写一个floor函数
int floor(double input){
    //下取整函数
    // c++ 17 会向0取整。
    return static_cast<int>(input) + (input>0?0:-1);

}

// 最小的 k 个数至少对每一个函数都要取最小的 k 个数。
// 该函数将把新的最小值与 result 合并
// 按照从小到大的顺序
void minf(int a,int b,int c,int k,pipe<int>&result){
    // 采用螺旋上升式方法 自然排序

    double middle = -b/(2.0*a);
    //初值会有偏左的偏置
    int middle_int = floor(middle);

    // 决定取值的初始方向 true = 向右 false = 向左
    bool initdir = (middle - middle_int>0.5)?true:false;

    // 决定取值的初始方向 1 = 向右，0 = 向左
    middle_int += (initdir)?1:0;
    
    // 存储符号，现在是第一次取值的方向
    int sign = (initdir)?1:-1;

    int x = middle_int;       //自变量
    int *tmp = new int[k];  
    int result1;
    tmp[0] = a*x*x+b*x+c;
    for(int i=1;i<k;++i){
        sign*=-1;             //反向
        x+=sign*i;            //下一个数
        result1 = a*x*x+b*x+c;
        tmp[i] = result1; //函数值输入
    }

    //将tmp并入result
    result.merge(tmp);

    delete tmp;
}

int main(){
    int n,k;
    cin>>n>>k;
    int a,b,c;  //a>0
    //int* result = new int[k];
    pipe<int> result(k);
    for (int i=0;i<n;++i){
        cin>>a>>b>>c;
        minf(a,b,c,k,result);
    }
    result.disp();
    cout<<'\n';
    //delete result;
    //system("pause");
    return 0;
}