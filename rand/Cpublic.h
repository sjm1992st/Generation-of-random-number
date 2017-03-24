#pragma once
class CPublic
{
public:
	static double m_MeanA[10000];
	CPublic();
	static double AverageRandom(int x);
	static double AverageRandomdecimal(double x);
	static double Normal(double x, double miu, double sigma);
	static double NormalRandom(double miu, double sigma, double max);
	static  void getnorm(int numberf, int maxf, int lenf);
	struct coordinate
	{
		double x;
		double y;
	};
	static coordinate m_randA[10000];
	~CPublic();
};