#include <iostream>

using namespace std;

struct kamera{
	string namaKamera;
};
struct harga{
	string harga;
};
struct dataKamera{
	kamera kmr;
	harga hrg;
};
const int kapasitas=10;
dataKamera dkmr[kapasitas];
int jml=0, idx;

string menuUser(){
	return "==sewaKamera==\n"
	"1. Tambah \n"
	"2. Tampilkan \n"
	"3. Hapus \n"
	"4. Edit \n"
	"5. Keluar\n";
}

void tambah(){
	if (jml == kapasitas){
		cout << "Data kamera penuh"<< endl;
	}else{
		cout<< "Masukkan nama kamera: ";
		cin.ignore();
		getline(cin, dkmr[jml].kmr.namaKamera);
		cout<< "Masukkan harga kamera: ";
		cin >> dkmr[jml].hrg.harga;
		jml ++;
		cout << "Kamera berhasil ditambahkan"<< endl;
	}
}

void lihat(){
	if (jml == 0){
		cout<< "Belum ada data kamera" << endl;
		}
	else{
		for (int i=0; i<jml; i++ ){
			cout<< "Kamera ke-"<< i+1 << " "<< dkmr[i].kmr.namaKamera << " Harga Rp. " << dkmr[i].hrg.harga << endl;				
			}
		}
}

int hapus(){ //Fungsi rekursif
	if (jml == 0){
		cout << "Belum ada data kamera"<< endl;
	}else{
		for (int i=0; i<jml; i++ ){
			cout<< "Kamera ke-"<< i+1 << " "<< dkmr[i].kmr.namaKamera << " Harga Rp. " << dkmr[i].hrg.harga << endl;				
			}
		cout << "Masukkan indeks yang ingin dihapus: ";
		cin >> idx;
		if (idx > jml){
			cout << "Indeks kamera tidak mencapai "<< idx<< endl;
			return hapus();
		}else{
			for (int q = idx-1; q <jml; q++){
				dkmr[q] = dkmr[q+1];
			}
			cout << "Kamera berhasil dihapus"<< endl;
			jml--;		
		}
	}
	return 0;
}

int edit(){ // fungsi Rekursif
	if (jml == 0){
		cout<< "Belum ada data kamera"<< endl;
	}else{
		for (int i=0; i<jml; i++ ){
			cout<< "Kamera ke-"<< i+1 << " "<< dkmr[i].kmr.namaKamera << " Harga Rp. " << dkmr[i].hrg.harga << endl;				
			}
		cout << "Masukkan indeks yang ingin diedit: ";
		cin >> idx;
		if (idx > jml){
			cout << "Indeks kamera tidak mencapai "<< idx<< endl;
			return edit();
		}else{
			cout << "Masukkan nama kamera: ";
			cin.ignore();
			getline(cin, dkmr[idx-1].kmr.namaKamera);
			cout << "Masukkan harga kamera: ";
			cin >> dkmr[idx-1].hrg.harga;
			cout << "Berhasil melakukan pengeditan"<< endl;
		}
	}
	return 0;
}

void tampilan(){
	string ulang = "y";
	int menu;
	
	while (ulang == "y"){
		cout << menuUser();
		cout << "Masukkan pilihan: ";
		cin >> menu;
		if (menu == 1){
			tambah();
		}else if (menu == 2){
			lihat();
		}else if (menu == 3){
			hapus();
		}else if(menu == 4){
			edit();
		}else if (menu ==5){
			ulang = "t";	
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
		getline(cin, nama);
		cout << "Masukkan NIM: ";
		cin >> password;
		cin.ignore();
		
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
