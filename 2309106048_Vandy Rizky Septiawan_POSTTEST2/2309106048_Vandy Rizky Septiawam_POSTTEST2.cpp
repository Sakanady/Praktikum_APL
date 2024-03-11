#include <iostream>

using namespace std;

void menuUser(){
	cout<< "==sewaKamera==\n"
	"1. Tambah \n"
	"2. Tampilkan \n"
	"3. Hapus \n"
	"4. Edit \n"
	"5. Keluar\n";	
}

void tampilan(){
	string ulang = "y";
	int jml =0, idx, menu, kapasitas=10;
	string kamera[kapasitas];
	
	while (ulang == "y"){
		menuUser();
		cout<< "Masukan pilihan anda: ";
		cin >> menu;
		if (menu == 1){
			cout<< "Masukkan nama kamera: ";
			cin.ignore();
			getline(cin, kamera[jml]);
			jml ++;
			cout << "Kamera berhasil ditambahkan"<< endl;
		}else if (menu == 2){
			if (jml == 0){
				cout<< "Belum ada data kamera" << endl;
			}
			else{
				for (int i=0; i<kapasitas; i++ ){
					if (!kamera[i].empty()){
						cout<< "Kamera ke-"<< i+1 << " "<< kamera[i] << endl;	
					}		
				}
			}
		}else if (menu == 3){
			if (jml == 0){
				cout << "Belum ada data kamera"<< endl;
			}else{
				for (int i=0; i<kapasitas; i++ ){
					if (!kamera[i].empty()){
						cout<< "Kamera ke-"<< i+1 << " "<< kamera[i] << endl;
					}
				}
				cout << "Masukkan indeks yang ingin dihapus: ";
				cin >> idx;
				for (int q = idx-1; q <jml; q++){
					kamera[q] = kamera[q+1];
			}
			cout << "Kamera berhasil dihapus"<< endl;
			jml--;	
			}
		}else if (menu == 4){
			if (jml == 0){
				cout<< "Belum ada data kamera"<< endl;
			}else{
				for (int i=0; i<kapasitas; i++ ){
					if (!kamera[i].empty()){
						cout<< "Kamera ke-"<< i+1 << " "<< kamera[i] << endl;	
					}		
				}
				cout << "Masukkan indeks yang ingin diedit: ";
				cin >> idx;
				cout << "Masukkan nama kamera: ";
				cin.ignore();
				getline(cin, kamera[idx-1]);
				cout << "Berhasil melakukan pengeditan"<< endl;
			}
		}else if (menu == 5){
			cout << "Program berhenti" << endl;
			ulang = "n";
		}
	}
}

int login (){
	string nama, password;
	string namaKey = "Vandy Rizky Septiawan", passwordKey = "2309106048";
	int ulang = 0;
	int login = 0;
	
	while (ulang<3){
		cout << "Masukkan nama: ";
		cin.ignore();
		getline(cin, nama);
		cout << "Masukkan NIM: ";
		cin >> password;
		
		if ((nama == namaKey) && (password == passwordKey)){
			login = 1;
			break;
		}else{
			cout << "Nama atau NIM salah!!!" << endl;
		}
	}
	return login;	
}

int main(){
	if (login()== 1){
		cout << "Login Berhasi" << endl;
		tampilan();
	}else{
		cout << "Login gagal";
	}
	return 0;
}
