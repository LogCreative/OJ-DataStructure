#include<iostream>
using namespace std;

template<class KEY,class OTHER>
struct SET {
    KEY key;
    OTHER other;
};

//直接插入排序
template<class KEY,class OTHER>
void simpleInsertSort(SET<KEY,OTHER> a[],int size) {
    int k;
    SET<KEY,OTHER> tmp;

    for(int j=1;j<size;++j){
        tmp = a[j];
        for(k=j-1;tmp.key<a[k].key&&k>=0;--k)
            a[k+1]=a[k];
        a[k+1]=tmp;
    }
}

//希尔排序
template<class KEY,class OTHER>
void shellSort(SET<KEY,OTHER> a[],int size){
    int step,i,j;
    SET<KEY,OTHER> tmp;

    for(step=size/2;step>0;step/=2)
        for(i=step;i<size;++i){
            tmp = a[i];
            for(j=i-step;j>=0&&a[j].key>tmp.key;j-=step)
                a[j+step]=a[j];
            a[j+step]=tmp;
        }
}

//直接选择排序
template<class KEY,class OTHER>
void simpleSelectSort(SET<KEY,OTHER> a[],int size){
    int i,j,min;
    SET<KEY,OTHER> tmp;
    for(i=0;i<size-1;++i){
        min = i;
        for(j=i+1;j<size;++j)
            if(a[j].key<a[min].key) min = j;
        tmp = a[i]; a[i]=a[min]; a[min]=tmp;
    }
}

//堆排序
template<class KEY,class OTHER>
void heapSort(SET<KEY,OTHER> a[],int size){
    int i;
    SET<KEY,OTHER> tmp;

    for(i=size/2-1;i>=0;--i)
        percolateDown(a,i,size);
    
    for(i=size-1;i>0;--i){
        tmp = a[0]; a[0]=a[i]; a[i]=tmp;
        percolateDown(a,0,i);
    }
}

template<class KEY,class OTHER>
void percolateDown(SET<KEY,OTHER> a[],int hole,int size){
//找最大的儿子
    int child;
    SET<KEY,OTHER> tmp = a[hole];

    for(;hole*2+1<size;hole=child){
        child = hole*2+1;
        if(child!=size-1 && a[child+1].key>a[child].key)
            child++;
        if(a[child].key>tmp.key) a[hole]=a[child];
        else break;
    }
    a[hole]=tmp;
}

//冒泡排序
template<class KEY,class OTHER>
void bubbleSort(SET<KEY,OTHER> a[],int size){
    int i,j;
    SET<KEY,OTHER> tmp;
    bool flag = true;

    for(i=1;i<size&&flag;++i){
        flag=false;
        for(j=0;j<size-i;++j)
            if(a[j+1].key<a[j].key){
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                flag = true;
            }
    }
}

//快速排序
template<class KEY,class OTHER>
void quickSort(SET<KEY,OTHER> a[],int size){ quickSort(a,0,size-1); }

template<class KEY,class OTHER>
int divide(SET<KEY,OTHER> a[], int low, int high){
    SET<KEY,OTHER> k=a[low];
    do{
        while(low<high && a[high].key>=k.key) --high;
        if(low<high) {a[low]=a[high];++low;}
        while(low<high && a[low].key<=k.key) ++low;
        if(low<high) {a[high]=a[low];--high;}
    } while (low!=high);
    a[low]=k;
    return low;
}

template<class KEY,class OTHER>
void quickSort(SET<KEY,OTHER> a[], int low, int high){
    int mid;
    if (low>=high) return;
    mid = divide(a,low,high);
    quickSort(a,low,mid-1);
    quickSort(a,mid+1,high);
}

//归并排序
template<class KEY,class OTHER>
void mergeSort(SET<KEY,OTHER> a[], int size){
    mergeSort(a,0,size-1);
}

template<class KEY,class OTHER>
void merge(SET<KEY,OTHER> a[], int left, int mid, int right){
    SET<KEY,OTHER> *tmp = new SET<KEY,OTHER>[right-left+1];
    int i = left, j = mid, k=0;

    while(i<mid && j<=right)
        if(a[i].key<a[j].key) tmp[k++]=a[i++];
        else tmp[k++]=a[j++];
    
    while(i<mid) tmp[k++]=a[i++];
    while(j<=right) tmp[k++]=a[i++];

    for(i=0,k=left;k<=right;) a[k++]=tmp[i++];
    delete[] tmp;
}

template<class KEY,class OTHER>
void mergeSort(SET<KEY,OTHER> a[], int left, int right){
    int mid = (left+right)/2;

    if(left==right) return ;
    mergeSort(a,left,mid);
    mergeSort(a,mid+1,right);
    merge(a,left,mid+1,right);
}

template<class OTHER>
struct node
{
    SET<int,OTHER> data;
    node *next;

    node() { next = NULL; }
    node(SET<int,OTHER> d):data(d),next(NULL) {}
};

template<class OTHER>
void bucketSort(node<OTHER> *&p){
    node<OTHER> *bucket[10],*last[10],*tail;
    int i,j,k,base = 1,max = 0,len = 0;

    for(tail=p;tail!=NULL;tail=tail->next)
        if(tail->data.key>max) max = tail->data.key;
    
    if(max==0) len=0;
    else while(max>0) {++len;max/=10;}

    for(i=1;i<=len;++i){
        for(j=0;j<=9;++j)
            bucket[j]=last[j]=NULL;
        while(p!=NULL){                     //分配
            k = p->data.key/base % 10;
            if(bucket[k]==NULL) bucket[k]=last[k]=p;
            else last[k]=last[k]->next=p;
            p = p->next;
        }
        p=NULL;
        for(j=0;j<=9;++j){                  //重组
            if(bucket[j]==NULL) continue;
            if(p==NULL) p = bucket[j];
            else tail->next = bucket[j];
            tail = last[j];
        }
        tail->next = NULL;
        base *= 10;
    }
}


int main(){
    node<char> *front=new node<char>({26,'\0'}),*p=front;
    for(int j=0;j<25;++j){
        p = p->next = new node<char>({25-j,'\0'});
    }
    bucketSort(front);
    for(p=front;p!=NULL;p=p->next) cout<<p->data.key<<' ';
    return 0;
}