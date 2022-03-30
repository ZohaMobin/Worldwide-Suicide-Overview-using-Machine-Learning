#include<iostream>
using namespace std;
class Country{

		protected:
	string name;
	long long int population;
	int gdpPerCapita;
	
	public:
		Country()
		{
			name = ' ';
			population = 0;
			gdpPerCapita = 0;
		}
		
		Country(string n, long long int p, int g)
		{
			name = n;
			population = p;
			gdpPerCapita = g;
		}
		
		void setName(string n)
		{
			name = n;
		}
		
		void setPopulation(long long int p)
		{
			population = p;
		}
		
		void setGdpPerCapita(int g)
		{
			gdpPerCapita = g;
		}
		
		string getName()
		{
			return name;
		}
		
		long long int getPopulation()
		{
			return population;
		}
		
		int getPerCapita()
		{
			return gdpPerCapita;
		}	
};


class Gender
{
	string gender;
	string age;
	public:
		Gender()
		{
			gender = ' ';
			age=' ';
		}
		
		void setGender(string g)
		{
			gender = g;
		}
		
		string getGender()
		{
			return gender;
		}
		
		string setAge(string age)
		{
			this->age=age;
		}
		string getAge()
		{
			return age;
		}
		
};


