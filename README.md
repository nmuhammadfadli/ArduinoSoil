
# Deskripsi Proyek

MoodUp adalah platform kesehatan mental yang dirancang untuk membantu kamu memahami, melacak, dan mengelola kesehatan mental. Website ini menyediakan landing page yang memberikan informasi terkait kesehatan mental, dan dilengkapi dengan kuis berbasis standar SRQ-20 WHO untuk mengevaluasi kondisi mental pengguna. Hasil kuis akan diklasifikasikan menggunakan algoritma Support Vector Machine (SVM), kemudian pengguna akan mendapatkan rekomendasi tindakan yang sesuai berdasarkan hasil tersebut.

## Cara Menjalankan Proyek

### Akses Online:
Platform MoodUp dapat diakses secara online melalui link berikut:  
[https://moodup-beta.vercel.app/](https://moodup-beta.vercel.app/)

Anda dapat langsung mengakses website tanpa perlu mengunduh atau menjalankan file secara lokal. Pada website MoodUp, pengguna dapat mengakses halaman beranda, mengisi kuis mengenai kesehatan mental, dan melihat hasil klasifikasi beserta rekomendasi yang diberikan.

### Akses Lokal:
Jika ingin menjalankan secara lokal, berikut langkah-langkahnya:

1. **Unduh Semua File Proyek:**
   - Pastikan seluruh file dan folder (assets) telah diunduh di direktori yang sama.

2. **Buka `index.html`:**
   - File ini adalah halaman utama dari aplikasi. Anda dapat:
     - Membuka file `index.html` langsung dengan klik dua kali di file explorer.

3. **Navigasi Melalui Website:**
   - Pengguna akan otomatis diarahkan menuju tampilan landing page yang memuat beranda, tentang, Quiz dan Kontak dari MoodUp. Pengguna juga dapat langsung melakukan akses ke kuis kesehatan mental melalui tombol “Mulai Sekarang”. Setelah pengguna mengisikan semua pertanyaan, maka akhirnya MoodUp akan menampilkan hasil klasifikasi beserta rekomendasi penanganan yang sesuai berdasarkan hasil yang didapat.

## Penjelasan Setiap File

1. **index.html**
   - Halaman ini merupakan halaman utama yang memberikan edukasi tentang pentingnya menjaga kesehatan mental. Dari sini, pengguna dapat mengakses kuis atau bagian lain dari website.

2. **about.html**
   - Berisi informasi lebih lanjut tentang platform MoodUp, termasuk misi, keunggulan dan cara kerja dari website MoodUp.

3. **pre-quiz.html**
   - Halaman persiapan sebelum pengguna mengisi kuis. Berisi penjelasan mengenai standar dan cara menjawab kuis dengan benar dan pengisian nama dan umur pengguna. Nama dan umur yang diinputkan boleh dengan data yang tidak riil untuk menjaga privasi pengguna.

4. **cond-quiz.html**
   - Berisi tentang pertanyaan terkait kondisi atau suasana hati pengguna yang akan diberikan kepada pengguna sebelum melakukan quiz.

5. **quiz.html**
   - Halaman utama kuis yang menampilkan 15 pertanyaan terkait kesehatan mental pengguna, berbasis standar SRQ-20 WHO.

6. **after-quiz.html**
   - Halaman yang muncul setelah kuis selesai diisi oleh pengguna, berisi pertanyaan terkait kondisi atau suasana hati pengguna yang akan diberikan kepada pengguna setelah melakukan quiz.

7. **result.html**
   - Menampilkan hasil klasifikasi berdasarkan jawaban pengguna. Proses klasifikasi dilakukan menggunakan algoritma SVM, yang memberikan evaluasi kondisi mental pengguna.

8. **saran.html**
   - Halaman ini berisi tentang feedback berupa saran yang diberikan pengguna terhadap website MoodUp ketika sudah melakukan kuis.

9. **tips.html**
   - Berisi berbagai tips untuk membantu menjaga kesehatan mental, yang bisa digunakan sebagai panduan bagi pengguna dalam meningkatkan kesejahteraan mereka.

10. **assets/**
   - Folder ini menyimpan semua aset seperti gambar, file CSS, dan JavaScript yang digunakan di berbagai halaman dalam aplikasi.

11. **tailwind.config.js**
   - File konfigurasi untuk Tailwind CSS, yang digunakan untuk mengatur gaya dan tampilan di seluruh aplikasi.

## Catatan

- **Algoritma SVM:** Aplikasi menggunakan algoritma Support Vector Machine (SVM) untuk mengklasifikasikan hasil kuis pengguna dan memberikan evaluasi mengenai kondisi kesehatan mental mereka.
- **Standar SRQ-20 WHO:** Kuis ini dirancang berdasarkan standar SRQ-20 WHO, sebuah alat penilaian kesehatan mental yang diakui secara internasional.
- **Pengujian Aplikasi:** Anda dapat menguji aplikasi baik secara online melalui link yang disediakan, maupun secara lokal dengan mengikuti langkah-langkah di atas.
