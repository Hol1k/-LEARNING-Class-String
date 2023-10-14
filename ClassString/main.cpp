#include <iostream>

using namespace std;

int Strlen(const char* other)
{
	int i = 0;
	while (other[i] != '\0')
	{
		i++;
	}
	return i;
}

class String
{
private:
	char* str;
	int length;
public:

	String()
	{
		str = nullptr;
		length = 0;
	}
	String(const char* str)
	{
		length = Strlen(str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}

		this->str[length] = '\0';
	}
	~String()
	{
		delete[] this->str;
	}
	String(const String& other)
	{
		length = Strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';
	}
	String(String&& other)
	{
		this->length = other.length;
		this->str = other.str;
		other.str = nullptr;
	}
	String& operator =(const String& other)
	{
		if (this->str!= nullptr)
		{
			delete[] str;
		}
		length = Strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';

		return *this;
	}
	String operator +(const String& other)
	{
		String newStr;

		int thisLength = Strlen(this->str);
		int otherLength = Strlen(other.str);

		newStr.length = thisLength + otherLength;

		newStr.str = new char[thisLength + otherLength + 1];

		for (int i = 0; i < thisLength; i++)
		{
			newStr.str[i] = this->str[i];
		}

		for (int i = 0; i < otherLength; i++)
		{
			newStr.str[i + thisLength] = other.str[i];
		}

		newStr.str[thisLength + otherLength] = '\0';

		return newStr;
	}

	int Length()
	{
		return length;
	}

	bool operator ==(const String& other)
	{
		if (this->length != other.length) return false;
		for (int i = 0; i < length; i++)
		{
			if (this->str[i] != other.str[i]) return false;
		}
		return true;
	}

	bool operator !=(const String& other)
	{
		return !(this->operator==(other));
	}

	char& operator[](const int index)
	{
		if (index<this->length && index>=0) return this->str[index];
	}

	char* GetStr()
	{
		return this->str;
	}

	friend ostream& operator <<(ostream& out, String& str)
	{
		return out << str.str;
	}

	friend istream& operator >>(istream& in, String& str)
	{
		return in >> str.str;
	}

};



int main()
{
	String a("Hello");
	String b("World");
	String c = a + b;
	cin >> a;
	cout << a << " " << b << "\n" << c;
	return 0;
}