#include"suicide.h"
#include"Linkedlist.h"

		class Hash : public DoublyList
		{    
		public: 
		 DoublyList table[10]; 
		Hash();
		    Hash(int V);
		    void insertItem(Suicide s); 
		    void SearchItem(int y); 
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
