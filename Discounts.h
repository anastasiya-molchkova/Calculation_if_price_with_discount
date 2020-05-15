#ifndef Discounts
#define Discounts

#include<array>

namespace DiscountConst
{
	// ��������� ��� �������� ������ �� �������� ������ - � ����� ����� ����� %
	struct DiscountCharacteristics
	{
		double limit;   // �����, ����� ����� ����� ��������� ������
		int percentage; // ������� ������
	};

	// ��������� ��� �������� ���������� ������, �� ������� ������ �� ���
	const unsigned int discount_number{ 2 };

	// ������ ��� �������� ������ ��� ���� ������� - ������ ��������� �����-�������
	const std::array <DiscountCharacteristics, discount_number> discountParameters{{{500, 3}, {1000, 5}}};
	// ������ � 3% ���������������, ���� ����� ������� ������ 500 ���., � 5% � ���� ����� ������� ������ 1000 ���.

	//�������, ������� ���������� ������ ������ � ��������� � ����������� �� ����� �������
	double get_discount_by_summ(const double summ)
	{
		double percent = 0;   // ���������� ��� �������� ������
		double max_summ = 0;  // � ��� ���������� ����� ���������� ������������ �� �������, ������� �������� ���� ����������� �����
		for (unsigned short i = 0; i < discount_number; i++)
		{
			if ((summ > discountParameters.at(i).limit) && (discountParameters.at(i).limit > max_summ))
			{
				max_summ = discountParameters.at(i).limit;    // ���������� �����, ������� ��������� ���� �����, ��� ������������, �.�. ���������� ������������ ����� ����� ��������
				percent = discountParameters.at(i).percentage; // � ���������� �������, ������� ������������� ����� ������������� ������
			}
		}
		std::cout << "��� ��������������� ������ � " << percent << "%" << std::endl;
		return percent;
	}
};

#endif