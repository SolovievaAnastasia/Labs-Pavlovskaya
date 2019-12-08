#include <iostream>
#include <iomanip>
using namespace std;
// Lab 4 pointers
int main()
{
	setlocale(0, "");
	int rows;
	cout <<" Введите количество строк:";
	cin >> rows;
	// создание матрицы 
	int **arr = new int *[rows] ; 
	for(int i = 0; i<rows; i++) 
		arr[i] = new int [rows];
	// ввод данных
 	for (int i=0;i<rows;i++)
        	for (int j=0;j<rows;j++)
         		arr[i][j] = rand()%20;// случайные от 0 до 20 
	// вывод матрицы
	cout << "Матрица" << endl;
	for (int i=0;i<rows;i++){
        	for (int j=0;j<rows;j++)
		
			cout<< setw(4) << arr[i][j]<< '\t';
			cout<< '\n'<<endl;
	}	
	// сдвиг матрицы
	int ma1[4*(rows-1)], mas2[4*(rows-1)];;
	int krai, num,i ,j;
	int raz;
	cout<< "Введите сколько раз хотите повернуть"<<endl;
	cin>>raz;
	
	//сдвиг матрицы
	for(int k=0; k<rows/2;k++) 
        {       krai = rows-k-1; // находим количество слоев	
            	num=0;
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
            	for(i=0;i<4*(rows-2*k-1);i++)
                	mas2[(i+raz)%(4*(rows-2*k-1))]=ma1[i];
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
            	for(i=krai-1;i>k;i--)             
                {    
			arr[i][k]= mas2[num];
                      	num++;
                }
        }
	//вывод матрицы
	cout << "Матрица" << endl;
	for (int i=0;i<rows;i++){
        	for (int j=0;j<rows;j++)
			cout<< setw(4) << arr[i][j]<< '\t';
			cout<< '\n'<<endl;
	}
	// удаление места в оперативной памяти 
	for(int i = 0; i<rows; i++) 
		delete []arr[i];
	delete[]arr;
return 0;
}
