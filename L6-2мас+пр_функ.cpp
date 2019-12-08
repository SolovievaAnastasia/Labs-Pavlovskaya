#include <iostream>
#include <iomanip>
using namespace std;
 const int n = 4;
// lab 6 functions
 
int kolvo(){
    int raz;
	cout<< "Введите сколько раз хотите повернуть"<<endl;
	cin>>raz;
return raz;
}
 void vvod( int ( &arr )[4][4] ){ //(int arr[n][n],const int n){
 	for (int i=0;i<n;i++)
        	for (int j=0;j<n;j++){
        	cout<< "Введите элемент "<< i<<'\t'<< j  <<endl;
        	cin >> arr[i][j];
        	}
 };

void output( int ( &arr )[4][4] ){
cout << "Матрица" << endl;
	for ( int i = 0;i<n;i++)
	{
		for (int j = 0;j<n;j++)
			cout<< setw(4) << arr[i][j]<< '\t';
			cout<< '\n'<<endl;
	}
};
int sdvig ( int ( &arr )[4][4] , int raz){
    int ma1[4*(n-1)], mas2[4*(n-1)], krai;
	int i, j;
	for(int k=0; k<n/2;k++) 
        {       krai = n-k-1; // находим количество слоев	
            	int num=0;
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
            	for(i=0;i<4*(n-2*k-1);i++)
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
            	for(i=krai-1;i>k;i--)             
                {    
			arr[i][k]= mas2[num];
                      	num++;
                }
        }

};

int main()
{
    
	setlocale(0, "");
	int arr[n][n];
	vvod(arr);
	output(arr);
	sdvig(arr, kolvo());
	output(arr);
	return 0;
}
