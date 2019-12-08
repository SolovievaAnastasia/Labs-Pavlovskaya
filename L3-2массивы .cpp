#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	setlocale (0, "");
	const int n = 4;// статический м.
	int arr[n][n];
	int ma1[4*(n-1)], mas2[4*(n-1)];;
	int krai, num, i, j;
	int raz;
	cout << "Введите сколько раз хотите повернуть" << endl;
	cin >> raz;
	// Ввод матрицы
	int ch = 1;
	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j < n; j++)
		{
			//cout << "Введите эл-нт a[" << i << "][" << j << "] " << endl;
			//cin >> arr[i][j];
			arr[i][j] = ch;
			ch++;
		}
	}
	// Вывод  матрицы
	cout << "Матрица" << endl;
	for ( i = 0; i < n; i++ )
	{
	  for (int j = 0; j < n; j++ )
	    cout << setw(4) << arr[i][j]<< '\t';
	    cout << '\n' << endl;
	}
	//сдвиг матрицы
	for(int k = 0; k < n/2; k++ ) 
  {       
    krai = n-k-1; // находим количество слоев	
    num = 0;
	 	//снимаем слой в стек
    for(j=k;j<krai;j++)             
    {	
		   ma1[num] = arr[k][j];  
       num++;
     }
     for(i=k;i<krai;i++)             
     {      
		    ma1[num] = arr[i][krai];  
        num++;
     }
     for(j=krai;j>=k;j--)    
     {      
			   ma1[num] = arr[krai][j];  
         num++;
     }
     for(i=krai-1;i>k;i--)             
     {      
			  ma1[num] = arr[i][k];   
        num++;
     }
     //переместить на к шагов вправо
     for( i = 0; i < 4*(n-2*k-1); i++)
          mas2[(i+raz)%(4*(n-2*k-1))]=ma1[i];
          num=0;
	 	 //из стека в матрицу   
     for(j=k;j<krai;j++)             
     {   
			  arr[k][j] = mas2[num];   
        num++;
     }
     for(i=k;i<krai;i++)             
     {    
			  arr[i][krai]= mas2[num];
        num++;
     }
     for(j=krai;j>=k;j--)    
     {    
			  arr[krai][j]= mas2[num];
        num++;
     }
     for(i = krai-1;i>k;i--)             
     {    
			  arr[i][k]= mas2[num];
        num++;
      }
  }
	//вывод матрицы
	cout << " New Матрица" << endl;				
	for (i = 0;i<n;i++)
	{
		for ( j = 0;j<n;j++)
			cout<< setw(4) << arr[i][j]<< '\t';
			cout<< '\n'<<endl;
	}
	return 0;
}
