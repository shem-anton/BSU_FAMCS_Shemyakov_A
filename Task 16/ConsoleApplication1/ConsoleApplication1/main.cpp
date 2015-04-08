#include <chrono>
#include <random>
#include <thread>
#include <iostream>
#include <mutex>
#include <fstream>

std::default_random_engine generate(std::chrono::system_clock::now().time_since_epoch().count());

std::ofstream fout("result.txt");

int **matrix1, **matrix2, **result;
int n, threads;

void RandomMatrix(int num)
{
	int i=0, j=num;
	while(i<n)
	{
		matrix1[i][j] = generate()%900+100;
		matrix2[i][j] = generate()%900+100;
		j+=threads;
		if(j>=n)
		{
			j-=n;
			i++;
		}
	}
}

void Multiply(int num)
{
	int i=0, j=num;
	while(i<n)
	{
		int sum = 0;
		for(int k=0; k<n; k++)
			sum += matrix1[j][k]*matrix2[k][i];
		result[j][i] = sum;
		j+=threads;
		if(j>=n)
		{
			j-=n;
			i++;
		}
	}
}

int main()
{
	std::cout << "Enter the size of matrix\n";
	std::cin >> n;
	std::cout << "Enter the number of threads\n";
	std::cin >> threads;
	threads = threads%10;

	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();


	matrix1 = new int*[n];
	matrix2 = new int*[n];
	result = new int*[n];
	for(int i = 0; i<n; ++i)
	{
		matrix1[i] = new int[n];
		matrix2[i] = new int[n];
		result[i] = new int[n];
	}

	std::thread *THR = new std::thread [threads];

	std::cout<<"Generating...\n";

	for(int i = 0; i<threads; i++)
		THR[i] = std::thread(RandomMatrix, i);
	for(int i = 0; i<threads; i++)
		THR[i].join();

	std::cout<<"Done generating, now calculating...\n";

	for(int i = 0; i<threads; i++)
		THR[i] = std::thread(Multiply, i);
	for(int i = 0; i<threads; i++)
		THR[i].join();

	std::cout<<std::endl;

	std::cout<<"Done calculating, now outputting...\n";

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			fout<<result[i][j]<<"  ";

		fout<<std::endl;
	}
	end = std::chrono::system_clock::now();
	std::chrono::duration<double> time_result = end - start;
	std::cout << time_result.count() <<" seconds\n";
	system("PAUSE");
	return 0;
}
