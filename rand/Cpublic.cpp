#include "stdafx.h"
#include "CPublic.h"
CPublic::CPublic()
{
}
double CPublic::m_MeanA[10000] = { 0 };
CPublic::coordinate CPublic::m_randA[10000] = { 0, 0 };
double CPublic::AverageRandomdecimal(double x)
{
	return double(rand() % int(x*1000))/1000;
}
double CPublic::AverageRandom(int x)
{
	return rand() % (x+1) ;
}
double CPublic::Normal(double x, double miu, double sigma)
{
	return 1.0 / sqrt(2 * 3.1415*sigma)*exp(-1 * (x - miu)*(x - miu) / (2*sigma*sigma));
}


double CPublic::NormalRandom(double miu, double sigma, double max)
{
	double x;
	double dScope;
	double y;
	do
	{
		x = AverageRandom(max);
		y = Normal(x, miu, sigma);
		dScope = AverageRandomdecimal(Normal(miu, miu, sigma));
	} while (dScope>y);
	return x;
}
void CPublic::getnorm(int numberf,int maxf,int lenf)
{
	double *rfB = new double[numberf*lenf];
	for (int i = 0; i < numberf; i++)
	{
		m_MeanA[i] = 0;
		for (int j = 0; j < lenf; j++)
		{

			rfB[i*lenf + j] = NormalRandom(double(maxf)/2, 1, maxf);
			m_MeanA[i] += rfB[i*lenf + j] * 1.0 / lenf;
		}
	}
	delete[]rfB;
}
CPublic::~CPublic()
{
}
