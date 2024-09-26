#include <random>
#include <algorithm>
#include <cmath>
#include <iostream>

int main()
{
	std::random_device rd; // Non-determinstic seed source
	std::mt19937 eng{ rd() }; // Create random number generator
	std::uniform_real_distribution<double> distx(0, 1);
	std::uniform_real_distribution<double> disty(0, 1);//Distribution of x and y
	int sample = 100, count=0;
	while (sample < 1000000000)
	{
		for (int i = 0;i < sample;i++)
		{//Generate samples of points
			//x and y
			double x = distx(eng);
			double y = disty(eng);
			//distance
			double distance = std::sqrt(x * x + y * y);
			//Whether in circle
			if (distance < 1.0)
			{
				count++;
			}
		}
		std::cout << "pi=" << ((double)count / (double)sample * 4.0) << " with " << sample << " samples.\n";
		sample *= 10;
		count = 0;
	}
	//3.14159 with 1000000000 samples.

}