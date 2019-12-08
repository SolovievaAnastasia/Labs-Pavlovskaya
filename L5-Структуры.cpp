#include <iostream>
#include <string>
using namespace std;

struct NOTE {
	string Name,Surname;
	string  Num;
	int Bith[3];
};
int main()
{
	const int n =4;
setlocale(0,"");
NOTE zap[n];
for (int i = 0;i < n;i++) {
	cout<<"Введите информацию"<<i+1<<endl;
	cout<<"Введите имя"<<endl;
	cin>>zap[i].Name;
		cout<<"Введите фамилию "<<endl;
	cin>> zap[i].Surname;
		cout<<"Введите номер "<<endl;
	cin>>zap[i].Num;
		cout<<"Введите день рождения"<<endl;
		for (int j=0;j<3;j++)
	        cin>>zap[i].Bith[j];
}
for(int i=3;i>=0;i--)
	for (int j = 0;j < i;j++) {
		if(zap[i].Num.substr(0, 3) <zap[i+1].Num.substr(0,3)) 
		{swap(zap[i].Num, zap[i + 1].Num); }
	}
   for (int i = 0;i < n;i++) {												 
		cout<<	zap[i].Surname;
		cout<<	zap[i].Name;
		cout<<	zap[i].Num;
		for (int j=0;j<3;j++)
			cout<<	zap[i].Bith[j];
	}
	string Sur;
	bool j=0;
	cout<<"Введите фамилию"<<endl;
	cin >> Sur;
	for (int i = 0;i < 4;i++) {
	    if (Sur== zap[i].Surname)
	        {cout<<"Фамилия:"<< zap[i].Surname<<endl;
	        cout<<"Имя:"<< zap[i].Name<<endl;
	        cout<<"Номер телефона:"<< zap[i].Num<<endl;
	        cout<<"День Рождения:";
	        for (int i =0;i<3;i++) cout<<zap[i].Bith[i];
	        j=1;
	    }
	}
	if (j!=1) cout<<"Нет такого человека в системе"<<endl; 
return 0;	
}
