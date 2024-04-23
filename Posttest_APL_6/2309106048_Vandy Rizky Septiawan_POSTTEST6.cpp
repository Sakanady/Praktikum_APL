#include <iostream>

using namespace std;

struct kamera{
	string namaKamera;
};
struct harga{
	int harga;
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
	"5. Cari\n"
	"6. Keluar\n";
}

void tambah(int *jumlah){
	if (*jumlah == kapasitas){
		cout << "Data kamera penuh"<< endl;
	}else{
		cout<< "Masukkan nama kamera: ";
		cin.ignore();
		getline(cin, dkmr[*jumlah].kmr.namaKamera);
		cout<< "Masukkan harga kamera: ";
		cin >> dkmr[*jumlah].hrg.harga;
		jml ++;
		cout << "Kamera berhasil ditambahkan"<< endl;
	}
}

void tampilkan(int *jumlah){
	for (int i=0; i< *jumlah; i++ ){
		cout<< "Kamera ke-"<< i+1 << " "<< dkmr[i].kmr.namaKamera << " Harga Rp. " << dkmr[i].hrg.harga << endl;				
		}
}
//============Quick Sort================
void swap(dataKamera *a, dataKamera *b) {
    dataKamera temp = *a;
    *a = *b;
    *b = temp;
}
int partition(dataKamera arr[], int low, int high) {
    int pivot = arr[high].hrg.harga;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].hrg.harga < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(dataKamera arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void tampilkanQuickSort(){
	quickSort(dkmr, 0, jml - 1);
	tampilkan(&jml);
}
//==============Bubble Sort===================
void swap(dataKamera &a, dataKamera &b) {
    dataKamera temp = a;
    a = b;
    b = temp;
}
void bubbleSort(dataKamera arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Membandingkan dua string nama
            if (arr[j].kmr.namaKamera > arr[j + 1].kmr.namaKamera) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void tampilkanBubbleSort(){
	bubbleSort(dkmr, jml);
	tampilkan(&jml);
}
//==============Insertion Sort================
void insertionSort(dataKamera arr[], int n) {
    int i, j;
    dataKamera key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j].kmr.namaKamera < key.kmr.namaKamera) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void tampilkanInsertionSort(){
	insertionSort(dkmr, jml);
	tampilkan(&jml);
}
//===========================================
//===============Binary Search===============
int binarySearch(dataKamera arr[], int l, int r, string nama_cari) {
    while (l <= r) {
        int mid = l + (r - l) / 2;

        // Periksa apakah nama berada di tengah
        if (arr[mid].kmr.namaKamera == nama_cari)
            return mid;

        // Jika nama lebih besar, cari di setengah kiri
        if (arr[mid].kmr.namaKamera < nama_cari)
            r = mid - 1;

        // Jika nama lebih kecil, cari di setengah kanan
        else
            l = mid + 1;
    }

    // Jika nama tidak ditemukan, kembalikan -1
    return -1;
}
void tampilkanBinarySearch(){
	string cari;
	cout << "Masukkan nama Kamera: ";
	getline(cin, cari);
	insertionSort(dkmr, jml);
	int hasil = binarySearch(dkmr, 0, jml-1, cari);
	if (hasil == -1){
		cout << "Nama tidak ditemukan." << endl;
	}else{
		cout << "Nama " << dkmr[hasil].kmr.namaKamera << " harga Rp. "<< dkmr[hasil].hrg.harga << endl; 
	}	
}
//=============Interpolation Search============
int interpolationSearch(dataKamera arr[], int size, const string& x) {
    int low = 0;
    int high = size - 1;

    while (low <= high && x >= arr[low].kmr.namaKamera && x <= arr[high].kmr.namaKamera) {
        if (low == high) {
            if (arr[low].kmr.namaKamera == x) return low;
            return -1;
        }

        // Perhitungan posisi dengan memperkirakan di mana x berada berdasarkan distribusi proporsional dari nama kamera
        int pos = low + ((high - low) / (arr[high].kmr.namaKamera[0] - arr[low].kmr.namaKamera[0])) * (x[0] - arr[low].kmr.namaKamera[0]);

        // Jika ditemukan
        if (arr[pos].kmr.namaKamera == x) return pos;

        // Jika x lebih besar, cari di sebelah kiri
        if (arr[pos].kmr.namaKamera > x) high = pos - 1;
        // Jika x lebih kecil, cari di sebelah kanan
        else low = pos + 1;
    }
    return -1;
}

void tampilkanInterpolationSearch(){
	string cari;
	cout << "Masukkan nama Kamera: ";
	getline(cin, cari);
	bubbleSort(dkmr, jml);
	int hasil = interpolationSearch(dkmr, jml, cari);
	if (hasil== -1){
		cout << "Nama tidak ditemukan." << endl;
	}else{
		cout << "Nama " << dkmr[hasil].kmr.namaKamera << " harga Rp. "<< dkmr[hasil].hrg.harga << endl; 
	}	
}
//=============================================
void cari(int *jumlah){
	if (*jumlah == 0){
		cout<< "Belum ada data kamera" << endl;
	}else{
		cout << "1. Cari secara Descending\n"
		"2. Cari secara Ascending\n";
		int pilih;
		cout << "Masukkan pilihan: ";
		cin >> pilih;
		cin.ignore();
		if (pilih == 1){
			tampilkanBinarySearch();
		}else if (pilih == 2){
			tampilkanInterpolationSearch();
		}
	}	
}
void lihat(int *jumlah){
	if (*jumlah == 0){
		cout<< "Belum ada data kamera" << endl;
	}
	else{
			cout << "1. Urutkan berdasarkan harga secara ascending\n"
			"2. Urutkan berdasarkan nama secara ascending\n"
			"3. Urutkan berdasarkan nama secara desceding\n";
			int pilih;
			cout << "Masukkan Pilian: ";
			cin >> pilih;
			if (pilih == 1){
				tampilkanQuickSort();
			}else if (pilih == 2){
				tampilkanBubbleSort();
			}else if(pilih == 3){
				tampilkanInsertionSort();
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
		}else if (menu == 5){
			cari(&jml);
		}else if (menu ==6){
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
