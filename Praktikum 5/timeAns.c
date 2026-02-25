/* File: time.h */
/* Definisi ADT TIME */

#ifndef TIME_H
#define TIME_H
#include <stdio.h>
#include "boolean.h"

/* *** Definisi TYPE TIME <HH:MM:SS> *** */
typedef struct { 
	int HH; /* integer [0..23] */
	int MM; /* integer [0..59] */
	int SS; /* integer [0..59] */
} TIME;

/* *** Notasi Akses: selektor TIME *** */
#define Hour(T) (T).HH
#define Minute(T) (T).MM
#define Second(T) (T).SS

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsTIMEValid (int H, int M, int S){
    return ((H <= 23 && H >= 0) &&
            (M >= 0 && M <= 59) &&
            (S >= 0 && S <= 59)
    );
}
/* Mengirim true jika H,M,S dapat membentuk T yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
void CreateTime (TIME * T, int HH, int MM, int SS){
    if(IsTIMEValid(HH, MM, SS)){
        T->HH = HH;
        T->MM = MM;
        T->SS = SS;
    }
    
}
/* Membentuk sebuah TIME dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk TIME */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaTIME (TIME * T){
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    while(!IsTIMEValid(x, y, z)){
        printf("Jam tidak valid\n");
        scanf("%d %d %d", &x, &y, &z);
    }
    T->HH = x;
    T->MM = y;
    T->SS = z;
}
/* I.S. : T tidak terdefinisi */
/* F.S. : T terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk T */
/* yang valid. Tidak mungkin menghasilkan T yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika TIME tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh: 
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk TIME <1,3,4> */
   
void TulisTIME (TIME T){
    printf("%d:%d:%d", T.HH, T.MM, T.SS);
}
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen T ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/ 

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long TIMEToDetik (TIME T){
    return (3600*T.HH + 60*T.MM + T.SS);
}
/* Diberikan sebuah TIME, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */

TIME DetikToTIME (long N){
    TIME P;
    N = N % 86400;

    P.HH = N/3600;
    N = N - (3600 * P.HH);

    P.MM = N/60;
    N = N - (60 * P.MM);

    P.SS = N;
    return P;
} 
/* Mengirim  konversi detik ke TIME */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang 
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus: 
   N1 = N mod 86400, baru N1 dikonversi menjadi TIME */

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean TEQ (TIME T1, TIME T2){
    return ((T1.MM == T2.MM) && (T1.HH == T2.HH) && (T1.SS == T2.SS));
}
/* Mengirimkan true jika T1=T2, false jika tidak */
boolean TNEQ (TIME T1, TIME T2){
    return (!TEQ(T1, T2));
}
/* Mengirimkan true jika T1 tidak sama dengan T2 */
boolean TLT (TIME T1, TIME T2){
    if(TNEQ(T1,T2)){
        if(T1.HH < T2.HH){
            return true;
        }
        else if(T1.HH == T2.HH){
            if(T1.MM < T2.MM){
                return true;
            }
            else if(T1.MM == T2.MM){
                if(T1.SS < T2.SS){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
/* Mengirimkan true jika T1<T2, false jika tidak */
boolean TGT (TIME T1, TIME T2){
    if(TNEQ(T1,T2)){
        if(T1.HH > T2.HH){
            return true;
        }
        else if(T1.HH == T2.HH){
            if(T1.MM > T2.MM){
                return true;
            }
            else if(T1.MM == T2.MM){
                if(T1.SS > T2.SS){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
/* Mengirimkan true jika T1>T2, false jika tidak */
/* *** Operator aritmatika TIME *** */
TIME NextDetik (TIME T){
    TIME R = T;
    if(T.SS == 59){
        if(T.MM == 59){
            if(T.HH == 23){
                R.HH = 0;
                R.MM = 0;
                R.SS = 0;
            }
            else{
                R.HH = T.HH + 1;
                R.MM = 0;
                R.SS = 0;
            }
            
        }
        else{
            R.MM = T.MM + 1;
            R.SS = 0;
        }
    }
    else{
        R.SS = T.SS + 1;
    }
    return R;
}
/* Mengirim 1 detik setelah T dalam bentuk TIME */
TIME NextNDetik (TIME T, int N){
    TIME R = T;
    for(int i = 0; i < N; i++){
        R = NextDetik(R);
    }
    return R;
}
/* Mengirim N detik setelah T dalam bentuk TIME */
TIME PrevDetik (TIME T){
    TIME R = T;
    if(T.SS == 0){
        if(T.MM == 0){
            if(T.HH == 0){
                R.HH = 23;
                R.MM = 59;
                R.SS = 59;
            }
            else{
                R.HH = T.HH - 1;
                R.MM = 59;
                R.SS = 59;
            }
        }
        else{
            R.MM = T.MM - 1;
            R.SS = 59;
        }
    }
    else{
        R.SS = T.SS - 1;
    }
    return R;
}
/* Mengirim 1 detik sebelum T dalam bentuk TIME */
TIME PrevNDetik (TIME T, int N){
    TIME R = T;
    for(int i = 0; i < N; i++){
        R = PrevDetik(R);
    }
    return R;
}
/* Mengirim N detik sebelum T dalam bentuk TIME */
/* *** Kelompok Operator Aritmetika *** */
long Durasi (TIME TAw, TIME TAkh){
    long d = 0;
    while(!TEQ(TAkh, TAw)){
        TAw = NextDetik(TAw);
        d++;
    }
    return d;
}
/* Mengirim TAkh-TAw dlm Detik, dengan kalkulasi */
/* Jika TAw > TAkh, maka TAkh adalah 1 hari setelah TAw */

#endif

/* File: time.h */
/* Definisi ADT TIME */

#ifndef TIME_H
#define TIME_H
#include <stdio.h>
#include "boolean.h"

/* *** Definisi TYPE TIME <HH:MM:SS> *** */
typedef struct { 
	int HH; /* integer [0..23] */
	int MM; /* integer [0..59] */
	int SS; /* integer [0..59] */
} TIME;

/* *** Notasi Akses: selektor TIME *** */
#define Hour(T) (T).HH
#define Minute(T) (T).MM
#define Second(T) (T).SS

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsTIMEValid (int H, int M, int S){
    return ((H <= 23 && H >= 0) &&
            (M >= 0 && M <= 59) &&
            (S >= 0 && S <= 59)
    );
}
/* Mengirim true jika H,M,S dapat membentuk T yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
void CreateTime (TIME * T, int HH, int MM, int SS){
    if(IsTIMEValid(HH, MM, SS)){
        T->HH = HH;
        T->MM = MM;
        T->SS = SS;
    }
    
}
/* Membentuk sebuah TIME dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk TIME */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaTIME (TIME * T){
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    while(!IsTIMEValid(x, y, z)){
        printf("Jam tidak valid\n");
        scanf("%d %d %d", &x, &y, &z);
    }
    T->HH = x;
    T->MM = y;
    T->SS = z;
}
/* I.S. : T tidak terdefinisi */
/* F.S. : T terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk T */
/* yang valid. Tidak mungkin menghasilkan T yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika TIME tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh: 
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk TIME <1,3,4> */
   
void TulisTIME (TIME T){
    printf("%d:%d:%d", T.HH, T.MM, T.SS);
}
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen T ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/ 

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long TIMEToDetik (TIME T){
    return (3600*T.HH + 60*T.MM + T.SS);
}
/* Diberikan sebuah TIME, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */

TIME DetikToTIME (long N){
    TIME P;
    N = N % 86400;

    P.HH = N/3600;
    N = N - (3600 * P.HH);

    P.MM = N/60;
    N = N - (60 * P.MM);

    P.SS = N;
    return P;
} 
/* Mengirim  konversi detik ke TIME */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang 
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus: 
   N1 = N mod 86400, baru N1 dikonversi menjadi TIME */

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean TEQ (TIME T1, TIME T2){
    return ((T1.MM == T2.MM) && (T1.HH == T2.HH) && (T1.SS == T2.SS));
}
/* Mengirimkan true jika T1=T2, false jika tidak */
boolean TNEQ (TIME T1, TIME T2){
    return (!TEQ(T1, T2));
}
/* Mengirimkan true jika T1 tidak sama dengan T2 */
boolean TLT (TIME T1, TIME T2){
    if(TNEQ(T1,T2)){
        if(T1.HH < T2.HH){
            return true;
        }
        else if(T1.HH == T2.HH){
            if(T1.MM < T2.MM){
                return true;
            }
            else if(T1.MM == T2.MM){
                if(T1.SS < T2.SS){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
/* Mengirimkan true jika T1<T2, false jika tidak */
boolean TGT (TIME T1, TIME T2){
    if(TNEQ(T1,T2)){
        if(T1.HH > T2.HH){
            return true;
        }
        else if(T1.HH == T2.HH){
            if(T1.MM > T2.MM){
                return true;
            }
            else if(T1.MM == T2.MM){
                if(T1.SS > T2.SS){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
/* Mengirimkan true jika T1>T2, false jika tidak */
/* *** Operator aritmatika TIME *** */
TIME NextDetik (TIME T){
    TIME R = T;
    if(T.SS == 59){
        if(T.MM == 59){
            if(T.HH == 23){
                R.HH = 0;
                R.MM = 0;
                R.SS = 0;
            }
            else{
                R.HH = T.HH + 1;
                R.MM = 0;
                R.SS = 0;
            }
            
        }
        else{
            R.MM = T.MM + 1;
            R.SS = 0;
        }
    }
    else{
        R.SS = T.SS + 1;
    }
    return R;
}
/* Mengirim 1 detik setelah T dalam bentuk TIME */
TIME NextNDetik (TIME T, int N){
    TIME R = T;
    for(int i = 0; i < N; i++){
        R = NextDetik(R);
    }
    return R;
}
/* Mengirim N detik setelah T dalam bentuk TIME */
TIME PrevDetik (TIME T){
    TIME R = T;
    if(T.SS == 0){
        if(T.MM == 0){
            if(T.HH == 0){
                R.HH = 23;
                R.MM = 59;
                R.SS = 59;
            }
            else{
                R.HH = T.HH - 1;
                R.MM = 59;
                R.SS = 59;
            }
        }
        else{
            R.MM = T.MM - 1;
            R.SS = 59;
        }
    }
    else{
        R.SS = T.SS - 1;
    }
    return R;
}
/* Mengirim 1 detik sebelum T dalam bentuk TIME */
TIME PrevNDetik (TIME T, int N){
    TIME R = T;
    for(int i = 0; i < N; i++){
        R = PrevDetik(R);
    }
    return R;
}
/* Mengirim N detik sebelum T dalam bentuk TIME */
/* *** Kelompok Operator Aritmetika *** */
long Durasi (TIME TAw, TIME TAkh){
    long d = 0;
    while(!TEQ(TAkh, TAw)){
        TAw = NextDetik(TAw);
        d++;
    }
    return d;
}
/* Mengirim TAkh-TAw dlm Detik, dengan kalkulasi */
/* Jika TAw > TAkh, maka TAkh adalah 1 hari setelah TAw */

#endif

int main(){
    TIME T1, T2;
    BacaTIME(&T1);
    BacaTIME(&T2);
    long d = Durasi(T1, T2);
    printf("%ld", d);
}