#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	bool operator==(Fraction& r_fr) {
		if ((numerator_ * r_fr.denominator_ ) == (r_fr.numerator_ * denominator_)){
				return true;
	}
		else  return false; 
	}

	bool operator!= (Fraction& r_fr) {
		return !(*this == r_fr);
	}
	bool operator<= (Fraction& r_fr) {
		if ((numerator_ * r_fr.denominator_) <= (r_fr.numerator_ * denominator_)) {
				return true;
		}
		else  return false;
	}
	bool operator>= (Fraction& r_fr) {
		if ((numerator_ * r_fr.denominator_) >= (r_fr.numerator_ * denominator_)) {
				return true;
		}
		else  return false;
	}
	bool operator> (Fraction& r_fr) {
		return !(*this <= r_fr);
	}
	bool operator< (Fraction& r_fr) {
		return !(*this >= r_fr);
	}
	

};


int main()
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}