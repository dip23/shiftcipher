/*
Nama 		: Difa Bagasputra Maulana
Kelas		: A / Praktikum B
Program		: Shift Chipper
tanggal		: 20 September 2020
*/	

#include<iostream>
#include<string.h>

using namespace std;

void encrypt();
void decrypt();

int main(){
    int pil;
    
	do{
		system("cls");
    	cout<<"Mau ngapain nih?"<<endl;
    	cout<<"================="<<endl;
    	cout<<"1. Enkripsi"<<endl;
    	cout<<"2. Dekripsi"<<endl;
    	cout<<"3. Exit"<<endl;
    	cout<<"Pilih : ";cin>>pil;
    	switch(pil){
    		case 1 :
    			encrypt();
    			system("pause");
    			break;
    		case 2 :
    			decrypt();
    			system("pause");
    			break;
    		case 3 :
    			break;
    		default :
    			cout<<"Pilihan tidak tersedia"<<endl;
    			system("pause");
    		break;
		}
	}while(pil!=3);
    
    return 0;
}

void encrypt(){
	int k;
    string plain,chipper; 
    int n;
	char kata; 
    
    cout<<"Masukkan kata : ";cin>>plain;
    n = plain.length();
    cout<<"Masukkan Key Pergeseran : ";cin>>k;
    chipper = " ";
    
    for (int i = 0; i < n; i++) {
    	kata = plain[i];
        if(isupper(kata)){
        	kata -= 65;
        	kata = (kata+k) % 26;
        	kata += 65;	
		}else{
			kata -= 97;
        	kata = (kata+k) % 26;
        	kata += 97;
		}
        chipper += kata;
    } 

	cout<<"hasil : "<<chipper<<endl;	
}

void decrypt(){
	int k;
    string plain,chipper; 
    int n;
	char kata; 
    
    cout<<"Masukkan kata : ";cin>>plain;
    n = plain.length();
    cout<<"Masukkan Key Pergeseran : ";cin>>k;
    chipper = " ";
    
    for (int i = 0; i < n; i++) {
    	kata = plain[i];
    	
        if(isupper(kata)){
        	kata -= 65;
        	if(kata-k<0){
				kata = 26 + (kata-k);
			}else{
				kata = (kata-k) % 26;	
			}
        	kata += 65;	
		}else{
			kata -= 97;
			if(kata-k<0){
				kata = 26 + (kata-k);
			}else{
				kata = (kata-k) % 26;	
			}
        	kata += 97;
		}
        chipper += kata;
    } 

	cout<<"hasil : "<<chipper<<endl;	
}

