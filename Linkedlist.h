#include<iostream>
#include"AvlTrees.h"
#include"MaxHeap.h"
using namespace std;

struct node{
	Suicide data;
	node *next;
	node *prev;
}; 

class DoublyList : public Suicide
{
	public:
	node *head,*tail;
	
	public:
	AVL avl;
//	Hash hsh;
	DoublyList()
		{
		head = NULL;
		tail = NULL;
		}
		
		
		node* GetHead()
		{
			return head;
		}
		
	//	Suicide n;
	void InsertNode(Suicide n)
	{
		node *tmp = new node;
		tmp->data = n;
		tmp->next = NULL;
		tmp->prev = NULL;
		if(head == NULL)
		{
			head = tmp;
			tail = tmp;
		}
		else
		{
			tail->next=tmp;
			tmp->prev=tail;
			tail=tmp;
		}
	}
	
	void DisplayfromHead()
		{
			node* temp=head;
			while(temp!=NULL)
			{
				cout<<"Data Node:"<<endl;
				temp->data.Display();
				cout<<endl;
			//	cout << "<><><><><><><><><><><><><><><><><><>" << endl;
				temp=temp->next;
			}
		}
		
	int Count()
	{
	int count=0;
	 node* temp=head;
		while(temp!=NULL)
		{
		
            temp=temp->next;
			count++;
		}
	return count;
	}
	
	void read()
	{
		Suicide s;
		string name;
		string sex;
		string age;
		int numOfSuicides,gdpPerCapita,year;
		float suicidesPer100k;
		int population;
		fstream fin;
		int i=0;
        fin.open("master.csv",ios::in);
        if(fin.fail())
        {
        	cout<<"File does not exist"<<endl;		
		}
		else if(fin.bad())
		{
			cout<<"FIle didn't open"<<endl;
		}
		else
	    {
		    while(i!=5000) 
	        {
	        	i++;
	        	fflush(stdin);
	        	fin.ignore();
	        	getline(fin,name ,',');	
	    		fin>>year;
	    		fin.ignore();
	    		getline(fin,sex,',');	
	    		fin.ignore();
				getline(fin,age,',');	
	    		fin>>numOfSuicides;
	    		fin.ignore();
	    		fin>>population;
	    		fin.ignore();
	    		fin>>suicidesPer100k;
	    		fin.ignore();
	    		fin>>gdpPerCapita;
	        	
	        	
	            			cout<<name<<"\t";
	            			s.setName(name);
	            		//	cout<<year<<"\t";
	            			s.setYear(year);
	            		//	cout<<sex<<"\t";
	            			s.setGender(sex);
//	            			cout<<age<<"\t";
	            			s.setAge(age);
	            		//	cout<<numOfSuicides<<"\t";
	            			s.setNumOfSuicide(numOfSuicides);
						//	cout<<population<<"\t";
							s.setPopulation(population);
	            		//	cout<<suicidesPer100k<<"\t";
	            			s.setSuicidesPer100k(suicidesPer100k);
	            		//	cout<<gdpPerCapita<<"\t";
	            			s.setGdpPerCapita(gdpPerCapita);
	            			InsertNode(s);
	            			avl.Insert(s,avl.root);	
	            		//	hsh.insertItem(s);
	            			
	            		//	cout<<endl;
	        }
//			 cout<<"\n\t\t\tPRE-ORDER AVL TREES"<<endl;
//       avl->preOrder(avl->root);
	        fin.close();
	   
		}
	
	}
		void swap_nodes(node* left, node* right)
		{
			node *templeftnext;
			node *templeftprev;
			node *temprightnext;
			node *temprightprev;
			
			templeftnext=left->next;
			templeftprev=left->prev;
			temprightnext=right->next;
			temprightprev=right->prev;
			
			left->next=templeftnext;
			left->prev=templeftprev;
			right->next=temprightnext;
			right->prev=temprightprev;
		}

	
	

		
		void Sort_Cases()
	{
						
		for(node* temp=head;temp->next!=NULL;temp=temp->next)
		{
			for(node* temp2=temp->next;temp2!=NULL;temp2=temp2->next)
			{
				if(temp->data.getNumofSuicides()<temp2->data.getNumofSuicides())
				{
					swap(temp,temp2);
				}
			}
		}
	}
	
//	node* swap(node* ptr1, node* ptr2) 
//	{ 
//    struct node* tmp = ptr2->next; 
//    ptr2->next = ptr1; 
//    ptr1->next = tmp; 
//    return ptr2; 
//	} 
	

	template <typename T>
	int search(T x)
		{
			node *temp;
			int count=0;
			if(head==NULL)
			{
				return 0;
			}
			else
			{
				temp=head;
				while(temp!=NULL)
				{
					if(temp->data.getName()==x)
					{
					count+=temp->data.getNumofSuicides();
					}
					else if(temp->data.getAge()==x)
					{
					//	cout<<temp->data.getAge();
						count+=temp->data.getNumofSuicides();
					}
					else if(temp->data.getGender()==x)
					{
					count+=temp->data.getNumofSuicides();
					}
					temp=temp->next;
					
				}
			}
			cout<<"The Total Number of Suicide Cases in "<<x<<" is: "<<count<<endl;
	}
	
	template <typename T>
	int searchyear(T x)
		{
			node *temp;
			int count=0;
			if(head==NULL)
			{
				return 0;
			}
			else
			{
				temp=head;
				while(temp!=NULL)
				{
					if(temp->data.getYear()==x)
					{
					count+=temp->data.getNumofSuicides();
					}
					
					
						temp=temp->next;
					
				}
			}
			cout<<"The Total Number of Suicide Cases in "<<x<<" is: "<<count<<endl;
		}
		
		int SuicideCases_GenderWise(string country_name,string g)
	{
    	node *temp=head;
		string str;
		string str2;
		int count=0;
		while(temp!=NULL)
		{
			str=temp->data.getName();
			str2=temp->data.getGender();
			if(str.find(country_name)!= std::string::npos)
			{
		   		if(str2.find(g)!= std::string::npos)
				{
					count+=temp->data.getNumofSuicides();
				}
				
			}
			temp=temp->next;
		}
		return count;
	}


	
		void traverse()
	{
    	node *temp=head;
		
		while(temp!=NULL)
		{
			cout<<"Country Name:"<<temp->data.getName()<<"\t\tNumber of Suicides:"<<temp->data.getNumofSuicides()<<"\t\tYear:"<<temp->data.getYear()<<"\t\tPopulation:"<<temp->data.getPopulation()<<endl;
			temp=temp->next;
		}
	}
	
	int Max_Num_Suicides() 
	{ 
	node* temp=head;
    int max = INT_MIN; 
    int year;
    string name;
    while (temp != NULL) { 
  
        if (max < temp->data.getNumofSuicides()) 
            {
			max = temp->data.getNumofSuicides(); 
            year=temp->data.getYear();
			name=temp->data.getName();}
            
            
        temp = temp->next; 
    } 
    cout<<"Maximum Number of Suicides:"<<max<<"\t"<<year<<"\t"<<name<<endl;
   }
		
		
		int Gender_Count(string country_name,string x)
	{
    	node *temp=head;
		string str;
		string str2;
		int count=0;
		while(temp!=NULL)
		{
			str=temp->data.getName();
			str2=temp->data.getGender();
			if(str.find(country_name)!= std::string::npos)
			{
		   if(str2.find(x)!= std::string::npos)
				{
					count++;
				}
				
			}
			temp=temp->next;
		}
		return count;
	}
	
	
	
	int Age_Analysis(string a)
	{
    	node *temp=head;
		string str2;
		int count=0;
		while(temp!=NULL)
		{
			str2=temp->data.getAge();
		
			if(str2.find(a)!= std::string::npos)
				{
					count+=temp->data.getNumofSuicides();
				}
				
			
			temp=temp->next;
		}
		return count;
	}
	

	
	int SuicideCases_Agewisexx(string country_name,string a)
	{
    	node *temp=head;
		string str;
		string str2;
		int count=0;
		while(temp!=NULL)
		{
			str=temp->data.getName();
			str2=temp->data.getAge();
			if(str.find(country_name)!= std::string::npos)
			{
		   		if(str2.find(a)!= std::string::npos)
				{
					count+=temp->data.getNumofSuicides();
				}
				
			}
			temp=temp->next;
		}
		return count;
	}
	
	int SuicideCases_Yearwise(string country_name,int year)
	{
    	node *temp=head;
		string str;
		int str2;
		int count=0;
		while(temp!=NULL)
		{
			str=temp->data.getName();
			str2=temp->data.getYear();
			if(str.find(country_name)!= std::string::npos)
			{
		   if(str2==year)
				{
					count+=temp->data.getNumofSuicides();
				}
				
			}
			temp=temp->next;
		}
		return count;
	}

	
	
	int Min_Num_Suicides()
	{ 
	node* temp=head;
	int min = INT_MAX; 
	string name;
	int year;
   
    while (temp != NULL) { 
   
        if (min > temp->data.getNumofSuicides()) 
           {
		   min = temp->data.getNumofSuicides(); 
            year=temp->data.getYear();
			name=temp->data.getName();
			} 
		
  
        temp = temp->next; 
    }
   cout<<"Minimum Number of Suicides:"<<min<<"\t"<<year<<"\t"<<name<<endl;
} 
void Heap(string country_name)
		{
    	node *temp=head;
		string str;
		int n=30;
		int *arr= new int[n];
		for(int i=0;i<n;i++)
		{
			arr[i]=0;
		}
		int i = 0;
		int year = temp->data.getYear();

		int count=0;
		//arr[0]=temp->data.getNumofSuicides();
		while(temp!=NULL)
		{
			fflush(stdin);
			str=temp->data.getName();
			if(str.find(country_name)!= std::string::npos)
			{
		   	if(temp->data.getYear()==year)
				{
					fflush(stdin);
					
					arr[i]+=temp->data.getNumofSuicides();
				}
				
			else
			{
				year++;
				i++;
				arr[i]+=temp->data.getNumofSuicides();
			}
				
			}
			temp=temp->next;
		}
			
			MaxHeap m1(n);
			for(int i=0;i<n;i++)
			{
				m1.Insert(arr[i]);
			}
			
				cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "\t\t\tMaximum number of Suicides in "<<country_name<<"=" << m1.getMax()<<endl;
				cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
		}
		
		
	void MergeSort(node** headRef) 
	{ 
	    head= *headRef;
	    node* a; 
	    node* b; 
	  
	    if ((head == NULL) || (head->next == NULL)) 
		{ 
	        return; 
	    } 
	  
	    FrontBackSplit(head, &a, &b); 
	  
	    MergeSort(&a); 
	    MergeSort(&b); 
	  
	    *headRef=SortedMerge(a, b); 
	} 
	  
	node* SortedMerge(node* a, node* b) 
	{ 
	    node* result = NULL; 
	  
	    if (a == NULL) 
	        return (b); 
	    else if (b == NULL) 
	        return (a); 
	  
	    if (a->data.getNumofSuicides() >b->data.getNumofSuicides()) 
		{ 
	        result = a; 
	        result->next = SortedMerge(a->next, b); 
	    } 
	    else 
		{ 
	        result = b; 
	        result->next = SortedMerge(a, b->next); 
	    } 
	    return (result); 
	} 
	  
	void FrontBackSplit(node* source, node** frontRef, node** backRef) 
	{ 
	    node* fast; 
	    node* slow; 
	    slow = source; 
	    fast = source->next; 
	  
	    while (fast != NULL) { 
	        fast = fast->next; 
	        if (fast != NULL) { 
	            slow = slow->next; 
	            fast = fast->next; 
	        } 
	    } 
	  
	    *frontRef = source; 
	    *backRef = slow->next; 
	    slow->next = NULL; 
	}



		void MergeSort_cases(node** headRef) 
	{ 
	    head= *headRef;
	    node* a; 
	    node* b; 
	  
	    if ((head == NULL) || (head->next == NULL)) 
		{ 
	        return; 
	    } 
	  
	    FrontBackSplit_c(head, &a, &b); 
	  
	    MergeSort_cases(&a); 
	    MergeSort_cases(&b); 
	  
	    *headRef=SortedMerge_c(a, b); 
	} 
	  
	node* SortedMerge_c(node* a, node* b) 
	{ 
	    node* result = NULL; 
	  
	    if (a == NULL) 
	        return (b); 
	    else if (b == NULL) 
	        return (a); 
	  
	    if (a->data.getPopulation() >b->data.getPopulation()) 
		{ 
	        result = a; 
	        result->next = SortedMerge_c(a->next, b); 
	    } 
	    else 
		{ 
	        result = b; 
	        result->next = SortedMerge_c(a, b->next); 
	    } 
	    return (result); 
	} 
	  
	void FrontBackSplit_c(node* source, node** frontRef, node** backRef) 
	{ 
	    node* fast; 
	    node* slow; 
	    slow = source; 
	    fast = source->next; 
	  
	    while (fast != NULL) { 
	        fast = fast->next; 
	        if (fast != NULL) { 
	            slow = slow->next; 
	            fast = fast->next; 
	        } 
	    } 
	  
	    *frontRef = source; 
	    *backRef = slow->next; 
	    slow->next = NULL; 
	}
	
		float Predict_Cases(float r)
		{
			 int n=2000, i;
			 float x[2000], y[2000], sumX=0, sumX2=0, sumY=0, sumXY=0, a, b,c;
			 node* temp= head;
			 for(i=1;i<n && temp!=NULL;i++)
			 {
				x[i]=temp->data.getNumofSuicides();
				y[i]=temp->data.getYear();
				temp=temp->next;
			 }
			
			 for(i=1;i<=n;i++)
			 {
				  sumX = sumX + x[i];
				  sumX2 = sumX2 + x[i]*x[i];
				  sumY = sumY + y[i];
				  sumXY = sumXY + x[i]*y[i];
			 }
		
			 b = (n*sumXY-sumX*sumY)/(n*sumX2-sumX*sumX);
			 a = (sumY - b*sumX)/n;
			
			c=b*r;
			c+=a;
	//		cout<<c;
			return c;	
		}
	
};

	class Hash
	{    
	public: 
	 DoublyList table[10]; 
	Hash();
	    Hash(int V);
	    void insertItem(Suicide s); 
	    void SearchItem(int y); 
	    void Input_Hash ();
	    int hashFunction(int x) 
		{ 
	        return (x % 10); 
	    } 
	    void displayHash(); 
	}; 
	
	Hash::Hash()
	{
		table[10].head = NULL;
	}
	 
	void Hash::insertItem(Suicide s) 
	{ 
	    int index = hashFunction(s.getYear()); 
	    //cout <<index;
	    table[index].InsertNode(s);  
	} 
	
	void Hash::SearchItem (int y)
	{
		string name;
		string str;
		int index = hashFunction(y); 
		system("cls");
		node* temp=table[index].head;
		while(temp!=NULL)
		{
			cout<<"Data Node:"<<endl;
			temp->data.Display();
			cout<<endl;
			temp=temp->next;
		}
		cout << "Enter Country name" << endl;
		cin >> name;
		cout << endl;
		system("cls");
			cout << "--------------Y E A R -------------------" << endl;
			node* temp1=table[index].head;
			while(temp1!=NULL)
			{
				str=temp1->data.getName();
				if((str.find(name)!= std::string::npos))
				{
						cout<<"Data Node:"<<endl;
						temp1->data.Display();
						cout<<endl;
						temp1=temp1->next;	
				}
			}
		
	}
	
	 					
	
	void Hash::Input_Hash()
	{
		Hash hsh;
		Suicide s;
		string name;
		string sex;
		string age;
		int numOfSuicides,gdpPerCapita,year;
		float suicidesPer100k;
		int population;
		fstream fin;
		int i=0;
        fin.open("master.csv",ios::in);
        if(fin.fail())
        {
        	cout<<"File does not exist"<<endl;		
		}
		else if(fin.bad())
		{
			cout<<"FIle didn't open"<<endl;
		}
		else
	    {
		    while(i!=20) 
	        {
	        	i++;
	        	fin.ignore();
	        	getline(fin,name ,',');	
	    		fin>>year;
	    		fin.ignore();
	    		getline(fin,sex,',');	
	    		fin.ignore();
				getline(fin,age,',');	
	    		fin>>numOfSuicides;
	    		fin.ignore();
	    		fin>>population;
	    		fin.ignore();
	    		fin>>suicidesPer100k;
	    		fin.ignore();
	    		fin>>gdpPerCapita;
	        	
	        	
	            			cout<<name<<"\t";
	            			s.setName(name);
	            		//	cout<<year<<"\t";
	            			s.setYear(year);
	            		//	cout<<sex<<"\t";
	            			s.setGender(sex);
//	            			cout<<age<<"\t";
	            			s.setAge(age);
	            		//	cout<<numOfSuicides<<"\t";
	            			s.setNumOfSuicide(numOfSuicides);
						//	cout<<population<<"\t";
							s.setPopulation(population);
	            		//	cout<<suicidesPer100k<<"\t";
	            			s.setSuicidesPer100k(suicidesPer100k);
	            		//	cout<<gdpPerCapita<<"\t";
	            			s.setGdpPerCapita(gdpPerCapita);
	            		//	InsertNode(s);
	            		//	avl.Insert(s,avl.root);	
	            			hsh.insertItem(s);
	            			
	            		//	cout<<endl;
	        }
//			 
	        fin.close();
	   hsh.displayHash();
		}
	
	}
	
	void Hash::displayHash()
	{
		for(int i=0;i<10;i++)
		{
			cout <<i;
			node* temp=table[i].head;
				while(temp!=NULL)
				{
					cout<<"Data Node:"<<endl;
					temp->data.Display();
					cout<<endl;
					temp=temp->next;
				}
		}
			
	}
	
