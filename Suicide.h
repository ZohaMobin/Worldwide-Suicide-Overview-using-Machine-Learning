
#include<fstream>
#include"Country_Gender_Age.h"

using namespace std;


class Suicide : public Country, public Gender
{
	//Country c;
	int year;
	//Age age;
//	Gender gender;
	float suicidesPer100k;
	int numOfSuicides;
	
	public:
		Suicide()
		{
			
			year = 0;
			suicidesPer100k = 0.0;
			numOfSuicides = 0;
			//read();
		}
		
		void setYear(int y)
		{
			year = y;
		}
		
		void setSuicidesPer100k(float sp)
		{
			suicidesPer100k = sp;
		}
		
		void setNumOfSuicide(int n)
		{
			numOfSuicides = n;
		}
		
		int getYear()
		{
			return year;
		}
		
		float getSuicidePer100k()
		{
			return suicidesPer100k;
		}
		
		int getNumofSuicides()
		{
			return numOfSuicides;
		}
		
	void Display()
	{
		cout<<"\t\t\tCountry Name:"<<getName()<<endl;
		cout<<"\t\t\tPopulation:"<<getPopulation()<<endl;
		cout<<"\t\t\tGDP:"<<getPerCapita()<<endl;
		cout<<"\t\t\tGender:"<<getGender()<<endl;
		cout<<"\t\t\tAge:"<<getAge()<<endl;
		cout<<"\t\t\tYear:"<<getYear()<<endl;
		cout<<"\t\t\tSuicide Rate:"<<getSuicidePer100k()<<endl;
			cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
		cout<<"\t\t\tNumber of Suicides:"<<getNumofSuicides()<<endl;
			cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
		
	}
	
};
