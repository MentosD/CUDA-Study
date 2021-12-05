#include <stdio.h>
#include <stdlib.h>
#include <cuda_runtime.h>
#include <device_launch_parameters.h>


__global__ void MatMul(int* M, int* N, int* P, int width)
{
	int x = threadIdx.x;
	int y = threadIdx.y;

	float Pervalue = 0;

	float elem1 = 0.0, elem2 = 0.0, value = 0.0;
	for (int i = 0; i < width; i++)
	{
		elem1 = M[y * width + i];//ȡM�����һ��
		elem2 = N[i * width + x];//ȡN�����һ��

		value += elem1 * elem2;//���
	}

	P[y * width + x] = value;
}

int main()
{
	const int ND = 30; //�㶨����ı��� ND=30
	int a[ND][ND], b[ND][ND], c[ND][ND];
	int* M, * N, * P;	//int��ָ��

	int width = ND;	//������
	int NUM = 900;	//
	dim3 blockSize(ND, ND); 

	cudaEvent_t start, stop;
	float elapsedTime = 0;
	cudaEventCreate(&start);
	cudaEventCreate(&stop);

	//�豸���ڴ����
	cudaMalloc((void**)&M, ND * ND * sizeof(int));
	cudaMalloc((void**)&N, ND * ND * sizeof(int));
	cudaMalloc((void**)&P, ND * ND * sizeof(int));

	//��ʼ��
	for (int i = 0; i < ND; i++)
	{
		for (int j = 0; j < ND; j++)
		{
			a[i][j] = 2;
			b[i][j] = 3;
		}
	}

	int Size = ND * ND;

	//���ݿ������������豸
	cudaMemcpy(M, a, Size * sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(N, b, Size * sizeof(int), cudaMemcpyHostToDevice);

	cudaEventRecord(start, 0);
	MatMul <<<1, blockSize>>> (M, N, P, width);
	cudaThreadSynchronize();
	cudaEventRecord(stop, 0);
	cudaEventSynchronize(stop);
	cudaEventElapsedTime(&elapsedTime, start, stop);

	cudaMemcpy(c, P, Size * sizeof(int), cudaMemcpyDeviceToHost);

	//printf("c0 = %d \n", c[0][0]);

	for (int i = 0; i < ND; i++)
	{
		for (int j = 0; j < ND; j++)
			printf("%d ", c[i][j]);
		printf("\n");
	}

	//�ͷ��豸�ڴ�
	cudaFree(M);
	cudaFree(N);
	cudaFree(P);

	return 0;
}