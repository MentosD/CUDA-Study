#include "stdio.h"

/*
修饰符__global__表明这个函数是将会从CPU中调用，在GPU中进行执行。
并借此函数来启动内核函数。
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
	三重尖括号里的参数表明的是相关的执行配置，用来表明使用多少线程来执行内核函数，
	在本例子中有5个GPU线程被系统所调用。
	*/
	cudaDeviceReset();
	/*
	执行完成后调用cudaDeviceReset()函数释放和清空与当前进程运行相关的资源。
	*/
	return 0;
}