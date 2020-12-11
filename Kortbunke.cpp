#include <iostream>
#include <vector>
#include <algorithm>
// 0=spar, 1=klør, 2=ruder, 3=hjearte };
class kort
{
public:
	int fave;
	int num;
	char tegn;
	kort(int fave, int num)
	{
		this->fave = fave;
		this->num = num;
		if (num == 1)
			tegn = 'A';
		else if (num == 11)
			tegn = 'J';
		else if (num == 12)
			tegn = 'Q';
		else if (num == 13)
			tegn = 'K';
	}
};
class bunken
{
public:
	std::vector<kort> bunke;
	bunken(bool joker = true)
	{
		for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 1; j < 14; j++)
			{
				bunke.push_back(kort(i, j));
			}
		}
	}
	void blande()
	{
		std::random_shuffle(bunke.begin(), bunke.end());
	}
	kort tagkort()
	{
		return bunke.back();
	}
};


int main()
{
	bunken spil(false);
	kort etkort = spil.tagkort();
	std::cout << "color " << etkort.fave << "\nnum " << etkort.num << " " << etkort.tegn << std::endl;

	spil.blande();
	kort ss = spil.tagkort();
	std::cout << "color " << ss.fave << "\nnum " << ss.num << " " << ss.tegn << std::endl;
	system("pause");
	return 0;
}