#include "stdio.h"

/*
���η�__global__������������ǽ����CPU�е��ã���GPU�н���ִ�С�
����˺����������ں˺�����
*/
__global__ void hello_world_from_gpu(void)
{
	printf("Hello World from GPU\n");
	return;
}

int main(void)
{
	printf("Hello World from CPU\n");

	hello_world_from_gpu << <1, 5 >> > ();
	/*
	���ؼ�������Ĳ�������������ص�ִ�����ã���������ʹ�ö����߳���ִ���ں˺�����
	�ڱ���������5��GPU�̱߳�ϵͳ�����á�
	*/
	cudaDeviceReset();
	/*
	ִ����ɺ����cudaDeviceReset()�����ͷź�����뵱ǰ����������ص���Դ��
	*/
	return 0;
}