#include <iostream>
#include <Windows.h>
class Fraction
{
private:
	int numerator_;
	int denominator_;
	char div = '/';
public:
	int NOD(int a, int b)
	{
		while (a != b)
			if (a > b) { a = a - b ;}
			else { b = b - a; }
		return a;
	}
	Fraction() {};
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator / NOD(numerator, denominator);
		denominator_ = denominator  / NOD(numerator, denominator);
	
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
		numerator_ = numerator_ + denominator_;
		return Fraction(numerator_, denominator_);
	}
	Fraction operator--() {
		numerator_ = numerator_ - denominator_;
		return Fraction(numerator_, denominator_);
	}
	friend  Fraction operator++(Fraction&, int);
	friend  Fraction operator--(Fraction&, int);
	friend std::ostream& operator<<(std::ostream& l_op, Fraction& r_op);

};
Fraction operator++(Fraction& f, int) {
	int t = f.numerator_;
	f.numerator_ = f.numerator_ + f.denominator_;

	return Fraction(t, f.denominator_);
}
Fraction  operator--(Fraction& f, int) {
	int t = f.numerator_;
	f.numerator_ = f.numerator_ - f.denominator_;
	
	return Fraction(t , f.denominator_);
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
	Fraction f3 ;

	std::cout << f1 << " + " << f2 << " = ";
	f3 = f1 + f2; std::cout << f3 << std::endl;
	std::cout << f1 << " - " << f2 << " = ";
	f3 = ++f1 - f2; std::cout << f3 << std::endl;
	std::cout << f1 << " * " << f2 << " = ";
	f3 = f1 * f2;  std::cout << f3 << std::endl;
	std::cout << f1 << " / " << f2 << " = ";
	f3 = f1-- / f2;  std::cout << f3 << std::endl;
	
	
	return 0;
}