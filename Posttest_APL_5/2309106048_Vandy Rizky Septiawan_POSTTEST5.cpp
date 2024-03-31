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

void tambah(int *jumlah){
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

void lihat(int *jumlah){
	if (*jumlah == 0){
		cout<< "Belum ada data kamera" << endl;
		}
	else{
		for (int i=0; i< *jumlah; i++ ){
			cout<< "Kamera ke-"<< i+1 << " "<< dkmr[i].kmr.namaKamera << " Harga Rp. " << dkmr[i].hrg.harga << endl;				
			}
		}
}

int hapus(int *jumlah){ //Fungsi rekursif
	if (*jumlah == 0){
		cout << "Belum ada data kamera"<< endl;
	}else{
		for (int i=0; i<*jumlah; i++ ){
			cout<< "Kamera ke-"<< i+1 << " "<< dkmr[i].kmr.namaKamera << " Harga Rp. " << dkmr[i].hrg.harga << endl;				
			}
		cout << "Masukkan indeks yang ingin dihapus: ";
		cin >> idx;
		if (idx > *jumlah){
			cout << "Indeks kamera tidak mencapai "<< idx<< endl;
			return hapus(&jml);
		}else{
			for (int q = idx-1; q <*jumlah; q++){
				dkmr[q] = dkmr[q+1];
			}
			cout << "Kamera berhasil dihapus"<< endl;
			jml--;		
		}
	}
	return 0;
}

int edit(int *jumlah){ // fungsi Rekursif
	if (*jumlah == 0){
		cout<< "Belum ada data kamera"<< endl;
	}else{
		for (int i=0; i<*jumlah; i++ ){
			cout<< "Kamera ke-"<< i+1 << " "<< dkmr[i].kmr.namaKamera << " Harga Rp. " << dkmr[i].hrg.harga << endl;				
			}
		cout << "Masukkan indeks yang ingin diedit: ";
		cin >> idx;
		if (idx > *jumlah){
			cout << "Indeks kamera tidak mencapai "<< idx<< endl;
			return edit(&jml);
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
			tambah(&jml);
		}else if (menu == 2){
			lihat(&jml);
		}else if (menu == 3){
			hapus(&jml);
		}else if(menu == 4){
			edit(&jml);
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
