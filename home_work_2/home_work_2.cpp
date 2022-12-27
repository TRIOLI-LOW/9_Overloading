#include <iostream>
#include <Windows.h>
class Fraction
{
private:
	int numerator_;
	int denominator_;
	char div = '/';
	
public:
	
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
		while (((numerator_ % 2 == 0) && (denominator_ % 2 == 0)) || ((numerator_ % 3 == 0) && (denominator_ % 3 == 0))) {
			if ((numerator_ % 2 == 0) && (denominator_ % 2 == 0)) {
				numerator_ / 2;
				denominator_ / 2;
			}
			else {
				numerator_ / 3;
				denominator_ / 3;
			}
			// Не срабатывает эта часть кода. Голову уже сломал, куда ее можно переместить.
		}
	}
	
	Fraction operator+(Fraction& r_fr) {
		double n1 = (numerator_ * r_fr.denominator_) + (r_fr.numerator_ *denominator_);
		double d1 = denominator_ * r_fr.denominator_;
		return Fraction(n1, d1);
	}
	Fraction operator-(Fraction& r_fr) {
		double n1 = (numerator_ * r_fr.denominator_) - (r_fr.numerator_ * denominator_);
		double d1 = denominator_ * r_fr.denominator_;
		return Fraction(n1, d1);
	}
	Fraction operator*(Fraction& r_fr) {
		double n1 = numerator_ * r_fr.numerator_;
		double d1 = denominator_ * r_fr.denominator_;
		return Fraction(n1, d1);
	}
	Fraction operator/(Fraction& r_fr) {
		double n1 = numerator_ * r_fr.denominator_ ;
		double d1 = denominator_ * r_fr.numerator_;
		return Fraction(n1, d1);
	}
	Fraction operator++( ){
		
		return Fraction(numerator_ + denominator_, denominator_);
	}
	Fraction operator--() {

		return Fraction(numerator_ - denominator_, denominator_);
	}
	friend  void operator++(Fraction&, int);
	friend  void operator--(Fraction&, int);
	friend std::ostream& operator<<(std::ostream& l_op, Fraction& r_op);

};
void operator++(Fraction& f, int) {
	
	f.numerator_ = f.numerator_ + f.denominator_;
	//return Fraction(f.numerator_, f.denominator_);
}
void operator--(Fraction& f, int) {
	f.numerator_ = f.numerator_ - f.denominator_;
	//return Fraction(f.numerator_, f.denominator_);
}
std::ostream& operator<<(std::ostream& l_op, Fraction& r_op) {
	std::cout << r_op.numerator_ << r_op.div << r_op.denominator_;
	return l_op;
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int a (0), b(0), c(0), d(0);
	
	std::cout << "Введите числитель дроби 1: ";
	std::cin >> a;
	std::cout << "Введите знаминатель дроби 1: ";
	std::cin >> b;
	std::cout << "Введите числитель дроби 2: ";
	std::cin >> c;
	std::cout << "Введите знаминатель дроби 2: ";
	std::cin >> d;
	Fraction f1(a, b);
	Fraction f2(c, d);
	Fraction f3 = f1 + f2;
	std::cout << f1 << " + " << f2 << " = " << f3 << std::endl;
	f3 = ++f1 - f2;
	std::cout << f1 << " - " << f2 << " = " << f3 << std::endl;
	f3 = f1 * f2;
	std::cout << f1 << " * " << f2 << " = " << f3 << std::endl;
	f3 = --f1 / f2;
	std::cout << f1 << " / " << f2 << " = " << f3 << std::endl;
	
	return 0;
}