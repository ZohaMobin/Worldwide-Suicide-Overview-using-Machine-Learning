#include"suicide.h"
#include<windows.h>
class AvlTrees
{
	public:
	Suicide s;
	AvlTrees *left;
	AvlTrees *right;
	int height;
	NodeAvl(){
		
	}
	AvlTrees(Suicide s){
		this->s=s;
		height=1;
		left=NULL;
		right=NULL;
	}
};

class AVL
{
	public:
		AvlTrees *root;
		
		AVL()
		{
			root=NULL;
		}
	
		void Input_AVL(AVL *avl)
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
	        	
	        	
	            			s.setName(name);
	            			s.setYear(year);
	            			s.setGender(sex);
	            			s.setAge(age);
	            			s.setNumOfSuicide(numOfSuicides);
							s.setPopulation(population);
	            			s.setSuicidesPer100k(suicidesPer100k);
	            			s.setGdpPerCapita(gdpPerCapita);
	            			avl->Insert(s,avl->root);
	            		
						cout<<"\t\t\t\t\t\tInserting Data in AVL";
							char a=219;
			
		for(int i=0;i<=50;i++)
		{
			cout<<a;
			Sleep(30);
		}	
	        }
			
	        fin.close();
	       
	    cout<<"\n\t\t\tPRE-ORDER AVL TREES"<<endl;
        avl->preOrder(avl->root);
		}
	
	}

	int GetHeight(AvlTrees* node)  
	{ 
	 
    if (node == NULL)  
       {return 0;}
	     
    return node->height;  
	}  
  
 	 int Get_Max(int a, int b)  
	{  
    return (a > b)? a : b;  
	}  
	
	int GetBalance(AvlTrees* node)  
	{  
    if (node == NULL)  
        return 0;  
    return  GetHeight(node->left) -  GetHeight(node->right);  
	}  
	
	AvlTrees* Insert(Suicide s,AvlTrees *temp){
		if(root==NULL){
			root=new AvlTrees(s);
		}
		else if(temp==NULL){
			temp=new AvlTrees(s);
			return temp;
		}
		else{
			if(s.getPerCapita()<temp->s.getPerCapita())
			{
				temp->left=Insert(s,temp->left);
			}
			else{
				temp->right=Insert(s,temp->right);	
				}
			}
		return temp;
		
		temp->height=1+Get_Max(GetHeight(temp->left),GetHeight(temp->right));
		
		int balance =GetBalance(temp);
		
		//LL Rotation
		if(balance > 1 && s.getPerCapita()<temp->left->s.getPerCapita())
		{	return rotateright(temp);}
		
		//LR Rotation
		if(balance > 1 &&  s.getPerCapita()>temp->left->s.getPerCapita())
		{temp->left=rotateleft(temp);
			return rotateright(temp);}
		
		//RR Rotation
		if(balance < 1 &&  s.getPerCapita()>temp->left-> s.getPerCapita())
		{	return rotateleft(temp);}
		
		//RL Rotation
		if(balance < 1 &&  s.getPerCapita()<temp->left-> s.getPerCapita())
		{temp->right=rotateright(temp);
			return rotateleft(temp);}
	}
		
		
	AvlTrees *rotateleft(AvlTrees *x){ 
		AvlTrees *y = x->right; 
		AvlTrees *T2 = y->left; 
		y->left = x; 
		x->right = T2; 
		
		// Update Heights  
		x->height =  Get_Max(GetHeight(x->left),
							GetHeight(x->right)) + 1; 
		y->height =  Get_Max(GetHeight(y->left),
							GetHeight(y->right)) + 1;  
		return y; 
	} 
	
	AvlTrees *rotateright(AvlTrees *y){ 
		AvlTrees *x = y->left; 
		AvlTrees *T2 = x->right;
		x->right = y; 
		y->left = T2;
		
		// Update Heights  
		y->height =  Get_Max(GetHeight(y->left),
							GetHeight(y->right)) + 1; 
		x->height =  Get_Max(GetHeight(x->left),
							GetHeight(x->right)) + 1;
		return x; 
	}
	
	void preOrder(AvlTrees *root)  
	{  
    if(root != NULL)  
    {  
    cout<<endl;
        root->s.Display(); 
        preOrder(root->left);  
        preOrder(root->right);  
    }  
	} 
	
};
	


