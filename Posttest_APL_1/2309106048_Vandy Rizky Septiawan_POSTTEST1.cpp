#include <iostream>

using namespace std;

void menu(){
	cout << "Program komversi Kilometer/jam, Centimeter/detik, Meter/detik, Mil/jam"<< endl;
	cout << "1. Konversi Kilometer/jam"<< endl;
	cout << "2. Konversi Centimeter/detik"<< endl;
	cout << "3. Konversi Meter/detik" << endl;
	cout << "4. Konversi Mil/jam"<< endl;
	cout << "5. Keluar"<< endl;
}

void kilometer (){
	double km, cm, meter, mil;
	cout << "Masukkan kecepatan yang ingin dikonversi (Km/jam): ";
	cin >> km;
	cm = km * 100000.0 / 3600.0;
	meter = km * 1000.0 / 3600.0;
	mil = km * 0.621371;
	
	cout << "Kecepatan dalam Kilometer/jam: "<< km<< endl;
	cout << "Kecepatan dalam Centimeter/detik: "<< cm << endl;
	cout << "Kecepatan dalam Meter/detik: "<< meter << endl;
	cout << "kecepatan dalam Mil/jam: "<< mil<< endl;
}
void centimeter (){
	double km, cm, meter, mil;
	cout << "Masukkan kecepatan yang ingin dikonversi (cm/detik): ";
	cin >> cm;
	km = cm * 0.036;
	meter = cm * 0.01;
	mil = cm * 0.0000223694;
	
	cout << "Kecepatan dalam Centimeter/detik: "<< cm << endl;
	cout << "Kecepatan dalam Kilometer/jam: "<< km<< endl;
	cout << "Kecepatan dalam Meter/detik: "<< meter << endl;
	cout << "kecepatan dalam Mil/jam: "<< mil<< endl;
}
void meter (){
	double km, cm, meter, mil;
	cout << "Masukkan kecepatan yang ingin dikonversi (meter/detik): ";
	cin >> meter;
	km = meter * 3.6;
	cm = meter * 100.0;
	mil = meter * 2.23694;
	
	cout << "Kecepatan dalam Meter/detik: "<< meter << endl;
	cout << "Kecepatan dalam Centimeter/detik: "<< cm << endl;
	cout << "Kecepatan dalam Kilometer/jam: "<< km<< endl;
	cout << "kecepatan dalam Mil/jam: "<< mil<< endl;
}
void mil(){
	double km, cm, meter, mil;
	cout << "Masukkan kecepatan yang ingin dikonversi (mil/detik): ";
	cin >> mil;
	km = mil * 1.60934;
	cm = mil * 44.704;
	meter = mil * 0.44704;
	
	cout << "kecepatan dalam Mil/jam: "<< mil<< endl;
	cout << "Kecepatan dalam Meter/detik: "<< meter << endl;
	cout << "Kecepatan dalam Centimeter/detik: "<< cm << endl;
	cout << "Kecepatan dalam Kilometer/jam: "<< km<< endl;
}

void pilihanUser (){
	char pilihanUser;
	while (true){ 
		menu();
		cout << "Masukkan Pilihan: ";
		cin>>pilihanUser;
		switch (pilihanUser){
			case '1':
				kilometer();
				break;
			case '2':
				centimeter();
				break;
			case '3':
				meter();
				break;
			case '4':
				mil();
				break;
			case '5':
				cout << "Program Selesai";
				return;
			default:
				cout << "Pilihan tidak ditemukan";
				break;
		}
	}
}

bool login(const string namaAsli, const string nimAsli){
	int percobaan =0;
	int batas = 3;
	string nama, nim;
	bool logIn;
	while (percobaan < batas){
		
		cout << "Masukkan nama: ";
		getline(cin, nama);
		cout << "Masukkan NIM: ";
		getline(cin, nim);
		
		if (nama==namaAsli && nim == nimAsli){
			cout << "Login berhasil" << endl;
			logIn = true;
			break;
		}else{
			cout << "Nama dan NIM tidak ditemukan"<< endl;
			percobaan++;
		}
	}
	return logIn;
}

int main(){
	string namaLogin = "Vandy Rizky Septiawan";
	string nimLogin = "2309106048";
	if (login(namaLogin, nimLogin)){
		pilihanUser();
	}else{
		cout<< "Terlalu banyak login";
	}
	return 0;
}
