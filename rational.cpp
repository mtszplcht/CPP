#include <iostream>
#include <algorithm>
#include "rational.h"
using namespace std;

Rational::Rational(int numerator, int denominator){
    if(denominator != 0){
        this->numer = numerator;
        this->denom = denominator;
    }else{ 
        this->numer = numerator;
        this->denom = 1;
    }
}

Rational::Rational(const Rational& other){
    this->numer = other.numer;
    this->denom = other.denom;
}

Rational& Rational::operator=(const Rational& other){
    if(this != &other){
        this->numer = other.numer;
        this->denom = other.denom;
    }
    return *this;
}
Rational& Rational::operator=(int number){
    this->numer = number;
    this->denom = 1;
    return *this;
}
Rational Rational::operator+(const Rational& other) const{
    int numerator = (this->numer * other.denom) + (other.numer * this->denom);
    int denominator = this->denom * other.denom;
    return Rational::normalized(numerator, denominator);
}
Rational Rational::normalized(int numerator, int denominator){
        if(numerator < 0 && denominator < 0){
                numerator *= -1;
                denominator *= -1;         
        }else if(numerator > 0 && denominator < 0){
                numerator *= -1;
                denominator *= -1;
        }

        int gcd = __gcd(abs(numerator), denominator);
        Rational rational(numerator/gcd, denominator/gcd);
        return rational;
}

Rational Rational::operator-(const Rational& other) const{
    return Rational::normalized((this->numer * other.denom) - (other.numer * this->denom), this->denom * other.denom);
}
Rational Rational::operator*(const Rational& other) const{
    return Rational::normalized(this->numer * other.numer, this->denom * other.denom);
}
Rational Rational::operator/(const Rational& other) const{
    return Rational::normalized(this->numer * other.denom, this->denom * other.numer);
}

Rational Rational::operator-() const{
    Rational rational = Rational::normalized(this->numer, this->denom);
    return Rational((-1 * rational.numer), rational.denom);
}
Rational Rational::operator+() const{    
    return Rational::normalized(this->numer, this->denom);
}
bool Rational::operator==(const Rational& other) const{
    if((this->numer == other.numer) && (this->denom == other.denom)) return true;
    else return false;
}

bool Rational::operator>=(const Rational& other) const{
    if((this->numer >= other.numer) && (this->denom <= other.denom)) return true;
    else return false;
}
bool Rational::operator<=(const Rational& other) const{
    if((this->numer <= other.numer) && (this->denom >= other.denom)) return true;
    else return false;
}
bool Rational::operator>(const Rational& other) const{
    if((this->numer > other.numer) && (this->denom <= other.denom)) return true;
    else return false;
}
bool Rational::operator<(const Rational& other) const{
    if((this->numer < other.numer) && (this->denom >= other.denom)) return true;
    else return false;
}

ostream& operator<<(ostream& os, const Rational& other){
    os << "(" << other.numerator() << "," << other.denominator()<<")";
    return os;
}

istream& operator>>(istream& is, Rational& rational){
    int denominator;
    cout << "Enter numerator = ";
    is >> rational.numer;
    cout << "Enter denumerator = ";
    is >> denominator;
    if(denominator == 0) rational.denom = 1;
    else rational = denominator;
    return is;
}

Rational operator+(const Rational& r, int i){
    return Rational::normalized(r.numerator() + (i * r.denominator()), r.denominator());
}
Rational operator+(int i, const Rational& r){
    return Rational::normalized(r.numerator() + (i * r.denominator()), r.denominator());
}
Rational operator-(const Rational& r, int i){
    return Rational::normalized(r.numerator() - (i * r.denominator()), r.denominator());
}
Rational operator-(int i, const Rational& r){
    return Rational::normalized(r.numerator() - (i * r.denominator()), r.denominator());
}

Rational operator*(const Rational& r, int i){
    return Rational::normalized(r.numerator() * i, r.denominator());
}
Rational operator*(int i, const Rational& r){
    return Rational::normalized(r.numerator() * i, r.denominator());
}

Rational operator/(const Rational& r, int i){
    return Rational::normalized(r.numerator(), r.denominator() * i);
}
Rational operator/(int i, const Rational& r){
    return Rational::normalized(r.numerator(), r.denominator() * i);
}