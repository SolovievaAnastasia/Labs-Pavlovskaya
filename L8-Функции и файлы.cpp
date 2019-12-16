#include <iostream>
#include <fstream>
using namespace std;

struct NOTEBOOK {
	char model[21];
	struct size {
		float x;
		float y;
		float z;
	};
	float w;
	int price;
};
void read(NOTEBOOK zap[], int num)
{
    int i;
    ifstream myfile("note.txt");
if(!myfile){
        cout<<"Невозможно открыть файл"<<endl;
	return 1;
    }
for (i=0; i < num; i++)
	{		 
	myfile.getline(zap[i].model,20);
	myfile.getline(zap[i].num[i].x,5);
	myfile.getline(zap[i].num[i].y, 5);
	myfile.getline(zap[i].num[i].z, 5);
	myfile.getline(zap[i].w,5);
	myfile.getline(zap[i].price,5);
}
    myfile.close();
}

void write(NOTEBOOK zap[] ,int num) {
 file.open ("bin.txt", out | binary);

 file.write((char*)&num, sizeof(num));      
   file.seekp(0, end);
	for (i=0; i < num; i++)
	{		 
file.write((char*)&zap[i].model,sizeof(  zap[i].model));
file.write((char*)&zap[i].num[i].x,sizeof(zap[i].num[i].x));
file.write((char*)&zap[i].num[i].y,sizeof(zap[i].num[i].y));
file.write((char*)&zap[i].num[i].z,sizeof(zap[i].num[i].z));
file.write((char*)&zap[i].w,sizeof(zap[i].w));
file.write((char*)&zap[i].price,sizeof(zap[i].price));
	}
	file.close();
}


int main()
{
setlocale(0,"");
NOTEBOOK zap[21];
size num[21];

read(NOTEBOOK zap[21], 21);
write(NOTEBOOK zap[21], 21);	
wrdiag(	NOTEBOOK zap[21], 21);
	
return 0;
}
