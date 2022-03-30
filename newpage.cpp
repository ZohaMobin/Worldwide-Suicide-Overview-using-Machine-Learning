#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<math.h>
#include"Linkedlist.h"
#include"LinearRegressionModel.h"
#include <bits/stdc++.h>
using namespace std;


int main()
{
 string cnt,age,gen;
 int year;
 Hash h;
 DoublyList *d=new DoublyList();
//	h.Input_Hash();

	d->read();
	system("cls");
	
		int n1;
		
		do{
		
		system("Color B5");
			
			cout<<"\n\n\n\n\n\n\n\n"<<endl;
			cout << "\t\t\t\t\t*** WorldWide Suicide Overview ***" << endl;
			cout<<"\t\t\t\t\t    Data Scanned:"<<d->Count()<<endl;
		cout<<"\t\t\t\t\t\tLOADING! \n";
		cout<<"\t\t\t  ";
			char a=219;
			
		for(int i=0;i<=50;i++)
		{
			cout<<a;
			Sleep(30);
		}

		system("cls");
			cout << "\t\t\t\t\t*** WorldWide Suicide Overview ***" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\n\t\t\tSelect a Suitable Option:" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\n\t\t\t<1> Operations\n\t\t\t<2> Analysis\n\t\t\t<0> Exit\n\t\t\t";
		cin >> n1;
		switch(n1)
		{
			case 1:       //case 1 for n1
				{
					system("cls");
						int n2;
						do{
		system("Color B5");
			cout << "\t\t\t\t\t*** WorldWide Suicide Overview ***" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\n\t\t\tSelect a Suitable Option:" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\n\t\t\t<1> Search\n\t\t\t<2> Sort\n\t\t\t<0> Exit\n\t\t\t";
		cin >> n2;
		switch(n2)
		{
			case 1:
			{	int yy;
				int n3;
				do
				{
			//	system("cls");
				system("Color B5");
				cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "\n\t\t\tSelect a Suitable Option:" << endl;
				cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "\n\t\t\t<1>Suicide Cases of Country\n\t\t\t<2>Suicide Cases of Country-AgeWise\n\t\t\t<3>Suicide Cases of Country-YearWise\n\t\t\t<4>Suicide Cases Genderwise\n\t\t\t<0> Exit\n\t\t\t";
				cin >> n3;
				system("cls");
						
				switch(n3)
				{
					case 1:
						{
							cout<<"Enter Country name: ";
							cin>>cnt;
							d->search(cnt);						
							break;
						}
						
					case 2:
						{
//							system("cls");
							cout<<"Enter Country name: ";
							cin>>cnt;	
							cout<<"Enter Age: ";
							fflush(stdin);
							getline(cin,age);
							cout<<"The Total Number of Suicide Cases in "<<cnt<<" of "<<age<<" is "<<d->SuicideCases_Agewisexx(cnt,age)<<endl;
							break;
						}
					
					case 3:
						{
//							system("cls");
							cout<<"Enter Country name: ";
							cin>>cnt;
							//	h.Input_Hash();
							cout<<"Enter Year: ";
							cin>>year;
//							cin>>yy;
//							h.SearchItem(yy);
							cout<<"The Total Number of Suicide Cases in "<<cnt<<" of the year "<<year<<" is "<<d->SuicideCases_Yearwise(cnt,year)<<endl;
							break;
						}
						
					case 4:
						{
//							system("cls");
							cout<<"Enter Country name: ";
							cin>>cnt;
							cout<<"Enter Gender: ";
							fflush(stdin);
							getline(cin,gen);
							cout<<"The Total Number of Suicide Cases in "<<cnt<<" of "<<gen<<" are "<<d->SuicideCases_GenderWise(cnt,gen)<<endl;
							//d->search(gen);
							break;
						}
				
					case 0:
						{
							cout << "Thankyou" << endl;
								system("cls");
					cout << "-----------------------------------------------------------------------------------------------------------------------";
				cout << "\n\t\t\tGroup Members:\n<1> Rutba Asghari K19-0162\n<2> Zoha Mobin K19-1469\n<3> Midhat Mohib K19-0226\n" << endl;
					cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
				getch();
							break;
						}
						default:
							break;
		}
			}while(n3!=0);
			break;
		}
			case 2:      
			{
			    //system("cls");
				int n4;

				system("Color B5");
				cout << "\t\t\t\t\t*** WorldWide Suicide Overview ***" << endl;
				cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "\n\t\t\tSelect a Suitable Option:" << endl;
				cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "\n\t\t\t<1> Number of Suicide Cases\n\t\t\t<2> Population\n\t\t\t<3> Gross Domestic Product\n\t\t\t<0> Exit\n\t\t\t";
				cin >> n4;
				switch(n4)
				{
					case 1:
						{   
						    system("cls");
						    node *temp=d->GetHead();
						   	d->MergeSort(&temp);
							d->traverse();
					
							
							break;
						}
						
					case 2:
						{
							system("cls");
							node *temp=d->GetHead();
							d->MergeSort_cases(&temp);
							d->traverse();
							break;
						}
						
						case 3:
						{
							system("cls");
							d->avl.preOrder(d->avl.root);
						
							break;
						}
						
					case 0:
						{
							system("cls");
							cout << "Thankyou" << endl;
							break;
						}
						default :
							break;
				}
			break;
			}
			
			case 0:   
			{
				system("cls");
				system("cls");
					cout << "-----------------------------------------------------------------------------------------------------------------------";
				cout << "\n\t\t\tGroup Members:\n<1> Rutba Asghari K19-0162\n<2> Zoha Mobin K19-1469\n<3> Midhat Mohib K19-0226\n" << endl;
					cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
				getch();
			break;
			}
			
			default:
			{
			cout<<"\n\t\t\tOption not available.....!!!";
			cout<<"\n\t\t\tPress any key to   continue....!!";
			getch();
			}
		
		}
	}while(n2!=0);
	break;
}
	case 2:
		{
				string cn,cn1;
			int n5;
				system("cls");
				system("Color B5");
				cout << "\t\t\t\t\t*** WorldWide Suicide Overview ***" << endl;
				cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "\n\t\t\tSelect a Suitable Option:" << endl;
				cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "\n\t\t\t<1> Overall Maximum Suicide Cases\n\t\t\t<2> Gender Analysis\n\t\t\t<3> Prediction\n\t\t\t<4> Suicide Rates in accordance with GDP\n\t\t\t<5> Analysis of Ages\n\t\t\t<0> Exit\n\t\t\t";
				cin >> n5;
				
				switch(n5)
				{
					case 1:
						{
							system("cls");
							cout<<"Enter the Country:"<<endl;
							cin>>cn;
							d->Heap(cn);
								system("pause");
							break;
						}
					case 2:
						{
							int x1,x2;
						//	system("cls");
							cout<<"Enter the Country:"<<endl;
							cin>>cn1;
							
							x1=d->Gender_Count(cn1,"female");
							x2=d->Gender_Count(cn1,"male");
							cout<<"Female Count:"<<x1<<endl;
							cout<<"Male Count:"<<x2<<endl;
							
							if(x1>x2)
							{
									cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
								cout<<"\t\t\tThe Suicide Cases Count of Women is more than Men"<<endl;
									cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
							}
							else
							{
									cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
								cout<<"\t\t\tThe Suicide Cases Count of Men is more than Women"<<endl;
									cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
							}
							system("pause");
							break;
						}
					case 3:
						{
							system("cls");
							 int length_train;
							    const char* filename = "test.csv";
							    std::cout << "\t\t\t\t\tReading CSV \n";
							    Dataset data = read_csv(filename);
							
							
							    // Regression Variables
							    int max_iteration = 1000;
							    float learning_rate = 0.1;
							
							    // Training
							    std::cout << "\t\t\t\tMaking LinearRegressionModel \n";
							    LinearRegressionModel linear_reg = LinearRegressionModel(data);
							    	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
							    std::cout << "\t\t\tPlotting a Graph of Suicides Rate vs Year"<<endl;
							    	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
							    linear_reg.train(max_iteration, learning_rate);
							    
							    std::cout << "\t\t\tSuicide Cases: \n";
							    // Testing
							    float X_test[2];
							    X_test[0] = 1;
							    X_test[1] = 123;
							    float y_test = linear_reg.predict(X_test);
							    
							    linear_reg.print_weights();
							    std::cout << "\t\t\t\t Testing for Different Points"<<"\n";
							    std::cout << "\t\t\t\tTesting for X0 = " << X_test[0] << ", X1 = " << X_test[1] << "\n";
							    std::cout << "\t\t\t\t    Gradient = " << y_test << "\n"; 
							    int predict;
							    predict=y_test;
							    	cout << "-----------------------------------------------------------------------------------------------------------------------";
							    std::cout << "\t\tIt has been predicted that around "<<predict<<" Suicide cases will be Reported in the Next Year.\n";
							    	cout << "-----------------------------------------------------------------------------------------------------------------------";
							    
								
							    	system("pause");
							
							
							break;
												}
					case 4:
						{
							system("cls");
//							AVL *avl=new AVL();
//							avl->Input_AVL(avl);
							cout<<"\n\t\t\tPRE-ORDER AVL TREES"<<endl;
       						d->avl.preOrder(d->avl.root);
							system("pause");
							break;
						}
						case 5:
						{
							int L1=0,L2=0,L3=0,L4=0,L5=0,L6=0;
							system("cls");
							cout<<"Age Groups \n\t\t\t <1> 5-15 years\n\t\t\t<2> 15-24 years\n\t\t\t<3> 25-34 years\n\t\t\t<4> 35-54 years\n\t\t\t<5> 55-74 years\n\t\t\t<6> 75+ years\n\t\t\t"<<endl;
							L1=d->Age_Analysis("5-15 years");
							L2=d->Age_Analysis("5-24 years");
							L3=d->Age_Analysis("5-34 years");
							L4=d->Age_Analysis("5-54 years");
							L5=d->Age_Analysis("5-74 years");
							L6=d->Age_Analysis("5+ years");
							
							cout<<"Overall Suicide Cases of these Age Groups\n\n\t\t\t5-15 years:"<<L1<<"\n\t\t\t15-24 years:"<<L2<<"\n\t\t\t25-34 years:"<<L3<<"\n\t\t\t35-54 years:"<<L4<<"\n\t\t\t55-74 years: "<<L5<<"\n\t\t\t75+ years   :"<<L6<<endl;
							int arr[6]={0};
							
							int  n=6, i, max, min;
							arr[0]=L1;
							arr[1]=L2;
							arr[2]=L3;
							arr[3]=L4;
							arr[4]=L5;
							arr[5]=L6;
							
								cout << "-----------------------------------------------------------------------------------------------------------------------"; 
					 
					    // Find the maximum element
					    cout << "\n\t\t\tMaximum Sucide according to AgeGroup= "
					         << *max_element(arr, arr + n);
					         	
							cout << "\n\t\t\tMinimum Sucide according to AgeGroup= "
					         << *min_element(arr, arr + n)<<endl;
					 	cout << "-----------------------------------------------------------------------------------------------------------------------";
						
							system("pause");
							break;
						}
					case 0:
						{
							system("cls");
							break;
						}
					default:
						break;
				}
			break;
		}
	case 0:
		{
			system("cls");
			break;
		}
		default:
			{
				system("cls");
					cout << "-----------------------------------------------------------------------------------------------------------------------";
				cout << "\n\t\t\tGroup Members:\n<1> Rutba Asghari K19-0162\n<2> Zoha Mobin K19-1469\n<3> Midhat Mohib K19-0226\n" << endl;
					cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
				getch();
			}
				}
		}while(n1!=0);
	


	


}
