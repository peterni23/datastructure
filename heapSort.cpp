
#include<iostream>
using namespace std;

//�����㷨��������С��

//��������洢,�±��0��ʼ������Ϊ2i+1,�Һ���Ϊ2i+2.

//��������
void swap(int*a,int*b){
     int tmp = *a;
	 *a=*b;
	 *b = tmp;
}


void HeapAdjust(int h[],int s,int m){
    int rc = h[s];
	for(int j =2*s+1;j<=m;j=j*2+1){
	  if(j<m&&h[j+1]<h[j]) ++j;//ȡ���������н�С���Ǹ�
	  if(rc<=h[j]) break;
	  h[s]=h[j];
	  s=j; }//for
	  h[s] = rc;
	}


void  heapSort(int h[],int n){
	//��һ�ν���
   for(int i=n/2-1;i>=0;i--)
	   HeapAdjust(h,i,n-1);
   //��������
	for(int i=n;i>1;i--){   
	  swap(h[0],h[i-1]);//���Ѷ�Ԫ�غ����һ��Ԫ�ؽ���
	  HeapAdjust(h,0,i-2);
	  }
}


int main(){

	int h[8] = {49,38,65,97,76,13,27,49};
	cout<<"����ǰ:";
	for(int i=0;i<8;i++)
		cout<<h[i]<<" ";
	cout<<endl;
	heapSort(h,8);
	cout<<"�����";
	for(int i=0;i<8;i++)
		cout<<h[i]<<" ";
	system("pause");
}