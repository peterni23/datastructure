
#include<iostream>
using namespace std;

//建堆算法，建立最小堆

//堆用数组存储,下标从0开始，左孩子为2i+1,右孩子为2i+2.

//交换函数
void swap(int*a,int*b){
     int tmp = *a;
	 *a=*b;
	 *b = tmp;
}


void HeapAdjust(int h[],int s,int m){
    int rc = h[s];
	for(int j =2*s+1;j<=m;j=j*2+1){
	  if(j<m&&h[j+1]<h[j]) ++j;//取两个孩子中较小的那个
	  if(rc<=h[j]) break;
	  h[s]=h[j];
	  s=j; }//for
	  h[s] = rc;
	}


void  heapSort(int h[],int n){
	//第一次建堆
   for(int i=n/2-1;i>=0;i--)
	   HeapAdjust(h,i,n-1);
   //后序排序
	for(int i=n;i>1;i--){   
	  swap(h[0],h[i-1]);//将堆顶元素和最后一个元素交换
	  HeapAdjust(h,0,i-2);
	  }
}


int main(){

	int h[8] = {49,38,65,97,76,13,27,49};
	cout<<"建堆前:";
	for(int i=0;i<8;i++)
		cout<<h[i]<<" ";
	cout<<endl;
	heapSort(h,8);
	cout<<"排序后：";
	for(int i=0;i<8;i++)
		cout<<h[i]<<" ";
	system("pause");
}