#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct NOTE {
	string Name,Surname;
	string  Num;
	int Bith[3];
} ;
int main()
{
	const int n =4;
    setlocale(0,"");
    NOTE *p_mass = new NOTE[4];
    
     for (int i=0; i<n; i++)
    {
      
	cout<<"Введите информацию"<<i+1<<endl;
	cout<<"Введите имя"<<endl;
	getline(cin,p_mass[i].Name);
		cout<<"Введите фамилию "<<endl;
		getline(cin,p_mass[i].Surname);
		cout<<"Введите номер "<<endl;
		getline(cin,p_mass[i].Num);
		cout<<"Введите день рождения"<<endl;
		for (int j=0;j<3;j++)
	  cin>>p_mass[i]->Bith[j];
       //*p = &p_mass[i];
}


for(int i=3;i>=0;i--)
	for (int j = 0;j < i;j++) {
		if(p_mass[i]->Num.substr(0, 3) <p_mass[i+1]->Num.substr(0,3)) 
		{swap(p_mass[i]->Num, p_mass[i + 1]->Num); }
	}
   for (int i = 0;i < n;i++) {												 
		cout<<	p_mass[i]->Surname;
		cout<<	p_mass[i]->Name;
		cout<<	p_mass[i]->Num;
		for (int j=0;j<3;j++)
			cout<<	p_mass[i]->Bith[j];
	}
	string Sur;
	bool j=0;
	cout<<"Введите фамилию"<<endl;
	cin >> Sur;
	for (int i = 0;i < 4;i++) {
	    if (Sur== p_mass[i]->Surname)
	        {cout<<"Фамилия:"<< p_mass[i]->Surname<<endl;
	        cout<<"Имя:"<< p_mass[i]->Name<<endl;
	        cout<<"Номер телефона:"<< p_mass[i]->Num<<endl;
	        cout<<"День Рождения:";
	        for (int i =0;i<3;i++) cout<<p_mass[i]->Bith[i];
	        j=1;
	    }
	}
	if (j!=1) cout<<"Нет такого человека в системе"<<endl; 
	delete []p_mass;
return 0;	
}
