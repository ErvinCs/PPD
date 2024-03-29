// PPD-Lab03-3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "PoolMatrix.h"
#include "AsyncMatrix.h"
#include <iostream>

void runThreadPool(int rows, int columns)
{
	//ThreadPool
	std::cout << "ThreadPool\n\n";

	PoolMatrix pMatrix1 = PoolMatrix(rows, columns);
	pMatrix1.populate();
	std::cout << pMatrix1.toString();

	PoolMatrix pMatrix2 = PoolMatrix(rows, columns);
	pMatrix2.populate();
	std::cout << pMatrix2.toString();

	PoolMatrix pMatrixSum = PoolMatrix(rows, columns);
	pMatrixSum = pMatrix1.add(pMatrix2);
	std::cout << "\nMulti-threaded Addition:\n" << pMatrixSum.toString();

	PoolMatrix pMatrixSumSecv = PoolMatrix(rows, columns);
	pMatrixSumSecv = pMatrix1.addNoThreads(pMatrix2);
	std::cout << "\nSingle-threaded Addition:\n" << pMatrixSumSecv.toString();

	PoolMatrix pMatrixProd = PoolMatrix(rows, columns);
	pMatrixProd = pMatrix1.multiply(pMatrix2);
	std::cout << "\nMulti-threaded Multiplication:\n"  << pMatrixProd.toString();

	PoolMatrix pMatrixProdSecv = PoolMatrix(rows, columns);
	pMatrixProdSecv = pMatrix1.multiplyNoThreads(pMatrix2);
	std::cout << "\nSingle-threaded Multiplication:\n" << pMatrixProdSecv.toString();
}

void runAsync(int rows, int columns)
{
	//Async
	std::cout << "Async\n\n";
	AsyncMatrix aMatrix1 = AsyncMatrix(rows, columns);
	aMatrix1.populate();
	std::cout << aMatrix1.toString();

	AsyncMatrix aMatrix2 = AsyncMatrix(rows, columns);
	aMatrix2.populate();
	std::cout << aMatrix2.toString();

	AsyncMatrix aMatrixSum = AsyncMatrix(rows, columns);
	aMatrixSum = aMatrix1.add(aMatrix2);
	std::cout << "\nMulti-threaded Addition:\n" << aMatrixSum.toString();

	AsyncMatrix aMatrixSumSecv = AsyncMatrix(rows, columns);
	aMatrixSumSecv = aMatrix1.addNoThreads(aMatrix2);
	std::cout << "\nSingle-threaded Addition:\n" << aMatrixSumSecv.toString();

	AsyncMatrix aMatrixProd = AsyncMatrix(rows, columns);
	aMatrixProd = aMatrix1.multiply(aMatrix2);
	std::cout << "\nMulti-threaded Multiplication:\n" << aMatrixProd.toString();

	AsyncMatrix aMatrixProdSecv = AsyncMatrix(rows, columns);
	aMatrixProdSecv = aMatrix1.multiplyNoThreads(aMatrix2);
	std::cout << "\nSingle-threaded Multiplication:\n" << aMatrixProdSecv.toString();
}

int main()
{
	int columns = 4;
	int rows = 4;

	runThreadPool(rows, columns);
	std::cout << "\n---------------------------------------\n";
	runAsync(rows, columns);

	int terminated;
	std::cin >> terminated;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
