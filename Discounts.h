#ifndef Discounts
#define Discounts

#include<array>

namespace DiscountConst
{
	// структура дл€ хранени€ данных об услови€х скидки - с какой суммы какой %
	struct DiscountCharacteristics
	{
		double limit;   // лимит, после какой суммы учитывать скидку
		int percentage; // процент скидки
	};

	// константа дл€ хранени€ количества скидок, по условию задачи их две
	const unsigned int discount_number{ 2 };

	// массив дл€ хранени€ данных обо всех скидках - хранит структуры лимит-процент
	const std::array <DiscountCharacteristics, discount_number> discountParameters{{{500, 3}, {1000, 5}}};
	// —кидка в 3% предоставл€етс€, если сумма покупки больше 500 руб., в 5% Ч если сумма покупки больше 1000 руб.

	//функци€, котора€ определ€ет размер скидки в процентах в зависимости от суммы покупки
	double get_discount_by_summ(const double summ)
	{
		double percent = 0;   // переменна€ дл€ процента скидки
		double max_summ = 0;  // в эту переменную будем записывать максимальный из лимитов, который превысит наша изначальна€ сумма
		for (unsigned short i = 0; i < discount_number; i++)
		{
			if ((summ > discountParameters.at(i).limit) && (discountParameters.at(i).limit > max_summ))
			{
				max_summ = discountParameters.at(i).limit;    // записываем лимит, который превысила наша сумма, как максимальный, т.к. предыдущий максимальный лимит также превышен
				percent = discountParameters.at(i).percentage; // и записываем процент, который соответствует этому максимальному лимиту
			}
		}
		std::cout << "¬ам предоставл€етс€ скидка в " << percent << "%" << std::endl;
		return percent;
	}
};

#endif