class Rational{
    private:
    int numer;
    int denom;
    int gcdND;

    friend std::ostream& operator<<(std::ostream&,const Rational&);
    friend std::istream& operator>>(std::istream&, Rational&);

    //void initialize(int numerator, int denominator);
    
    public:
    Rational(int numerator, int denominator = 1);
    ~Rational(){}
    Rational(const Rational& copy);

    Rational& operator=(const Rational&);
    Rational& operator=(int);

    int numerator() const {return numer;}
    int denominator() const {return denom;}

    //static Rational normalize(const Rational& other);
    static Rational normalized(int numerator, int denominator);
    static int calculateGCD(int numerator, int denominator);

    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;

    Rational operator+() const;
    Rational operator-() const;

    bool operator==(const Rational& other) const;
    bool operator>=(const Rational& other) const;
    bool operator<=(const Rational& other) const;
    bool operator>(const Rational& other) const;
    bool operator<(const Rational& other) const;
};

Rational operator+(const Rational&, int);
Rational operator+(int, const Rational&);

Rational operator-(const Rational&, int);
Rational operator-(int, const Rational&);

Rational operator*(const Rational&, int);
Rational operator*(int, const Rational&);

Rational operator/(const Rational&, int);
Rational operator/(int, const Rational&);