class Cents{
private:
	int m_cents;
public:
	Cents(int cents);
	int getCents();
	void setCents(int cents);
	friend bool operator<(const Cents& c1, const Cents& c2);
	friend bool operator>(const Cents& c1, const Cents& c2);

};

bool operator<(const Cents& c1, const Cents& c2);
bool operator>(const Cents& c1, const Cents& c2);
