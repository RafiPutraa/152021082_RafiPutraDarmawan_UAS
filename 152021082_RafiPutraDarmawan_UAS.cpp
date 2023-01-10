#include<iostream>
#include<cmath>
using namespace std;

struct nilai {
    float x,y,xy,xkuadrat,ykuadrat;
};

nilai inputnilai[100];
void inputxy(int _banyak);

int main(){
    float sigmax, sigmay, x2, y2, sigmaxy, sigmax2, sigmay2, op_atas, op_bawah, akar_x, akar_y, op_x, op_y, r, kd;
    sigmax = 0; sigmay = 0; sigmaxy = 0; x2 = 0; y2 = 0; sigmax2 = 0; sigmay2 = 0; op_atas =0; op_bawah=0; akar_x=0; akar_y=0;
    op_x =0; op_y = 0; r = 0;

    // Menginput nilai n
    int n;
    cout << "Input nilai n : ";
    cin >> n;

    // Menginput nilai x dan y
    cout << endl << "   INPUT NILAI" << endl;
    for(int i = 1; i<=n;i++){
        cout << "Input x ke-" << i << " : ";
        cin >> inputnilai[i].x;
        cout << "Input y ke-" << i << " : ";
        cin >> inputnilai[i].y;
        cout << endl;
    }

    // Mencari sigma xy
    for(int i = 1; i <= n; i++){
        sigmax = inputnilai[i].x + sigmax;
        sigmay = inputnilai[i].y + sigmay;
        inputnilai[i].xy= inputnilai[i].x * inputnilai[i].y;
        sigmaxy += inputnilai[i].xy;
    }

    // Mencari sigma x kuadrat dan y kuadrat
    for(int i =1; i <=n; i++) {
        inputnilai[i].xkuadrat = inputnilai[i].x * inputnilai[i].x;
        x2 += inputnilai[i].xkuadrat;
        inputnilai[i].ykuadrat = inputnilai[i].y * inputnilai[i].y;
        y2 += inputnilai[i].ykuadrat;
    }

    // Mencari nilai r
    sigmax2 = sigmax * sigmax;
    sigmay2 = sigmay * sigmay;
    op_x = n * x2 - sigmax2;
    op_y = n * y2 - sigmay2;
    akar_x = sqrt(op_x);
    akar_y = sqrt(op_y); 
    op_atas = n * sigmaxy - (sigmax*sigmay);
    op_bawah = akar_x * akar_y;
    r = op_atas / op_bawah;

    // Menampilkan sigma
    cout << endl << "   TAMPILAN SIGMA" << endl;
    cout << "Sigma x : " << sigmax << endl;
    cout << "Sigma y : " << sigmay << endl;
    cout << "Sigma xy : " << sigmaxy << endl;
    cout << "Sigma x kuadrat : " << x2 << endl;
    cout << "Sigma y kuadrat : " << y2 << endl;

    // Output akhir
    cout << endl << "   NILAI KORELASI PEARSON" << endl;
    cout << "Nilai korelasi r = " << r << endl;
    kd = r * r * 100 / 100;
    cout << "Nilai koefisien determinasi = " << kd << endl;
    
    cout << endl << "   KESIMPULAN" << endl;
    cout << "Kekuatan Hubungan dari nilai Korelasi : " ;
    if(r < 0) cout << "Hubungan antara variabel x dan y adalah negatif, dimana jika nilai x betambah, maka nilai y akan mengecil, dan juga sebaliknya" << endl;
    else if(r == 0) cout << "Tidak Ada Hubungan antara antara variabel x dan y" << endl; 
    else if(r > 0 && r <= 0.09){
         cout << "Hubungan Korelasinya diabaikan" << endl;
         cout << "Hubungan antara variabel x dan y adalah positif, dimana jika nilai x bertambah, maka nilai y pun bertambah, dan juga sebaliknya" << endl;
    }
    else if (r > 0.09 && r <= 0.29) {
        cout << "Hubungan Korelasinya rendah" << endl;
        cout << "Hubungan antara variabel x dan y adalah positif, dimana jika nilai x bertambah, maka nilai y pun bertambah, dan juga sebaliknya" << endl;
    }
    else if(r > 0.29 && r <= 0.49) {
        cout << "Hubungan Korelasinya moderat" << endl;
        cout << "Hubungan antara variabel x dan y adalah positif, dimana jika nilai x bertambah, maka nilai y pun bertambah, dan juga sebaliknya" << endl;
    }
    else if(r > 0.49 && r <= 0.7) {
        cout << "Hubungan Korelasinya sedang" << endl;
        cout << "Hubungan antara variabel x dan y adalah positif, dimana jika nilai x bertambah, maka nilai y pun bertambah, dan juga sebaliknya" << endl;
    }
    else if(r >0.7) {
        cout << "Hubungan Korelasinya sangat kuat" << endl;
        cout << "Hubungan antara variabel x dan y adalah positif, dimana jika nilai x bertambah, maka nilai y pun bertambah, dan juga sebaliknya" << endl;
    }
}