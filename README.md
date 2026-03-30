# 🎵 Music Catalog & Rating System (RYM Clone)

O aplicație de tip catalog muzical inspirată de platforme precum **RateYourMusic**, dezvoltată în C++. Proiectul gestionează o bază de date complexă de artiști, albume și melodii, permițând utilizatorilor să ofere recenzii și să genereze topuri bazate pe diverse criterii.

---

### 🛠️ Concepte și Tehnologii Utilizate
Proiectul pune în practică concepte avansate de **Software Engineering**:

* **Design Patterns:**
    * **Factory Method:** Folosit pentru instanțierea dinamică a obiectelor muzicale (Melodii, Albume etc.).
    * **Strategy Pattern:** Utilizat pentru algoritmii de sortare ai topurilor (permite schimbarea criteriului de sortare la runtime).
* **Smart Pointers (`std::shared_ptr`):** Gestiune automată a memoriei pentru a preveni memory leak-urile.
* **Templates:** Funcții și clase generice pentru gestionarea recenziilor și a input-ului de la utilizator.
* **STL (Standard Template Library):** Utilizare intensivă de `std::vector`, `std::string` și algoritmi de sortare (`std::sort`).
* **Exception Handling:** Mecanisme custom de tratare a erorilor (ex: `NotaInvalidaException`).
* **Polimorfism & RTTI:** Utilizarea `dynamic_pointer_cast` pentru navigarea în ierarhia de clase (`ObiectMuzical` -> `Artist`/`Melodie`).

---

### 📋 Funcționalități
* **Sistem de Topuri:** Generare Top 5 Melodii, Albume sau Artiști în funcție de rating-ul mediu.
* **Filtrare Avansată:** Afișarea albumelor dintr-un an specific.
* **Management Recenzii:** Adăugarea de recenzii cu note (1-10) și comentarii pentru fiecare melodie.
* **Persistența Datelor:** Încărcarea automată a bazei de date din fișier text (`date.txt`).
* **Interfață CLI Interactivă:** Meniu complet pentru navigarea prin colecția de muzică.

---

### 🏗️ Structura Claselor
* **ObiectMuzical:** Clasa de bază abstractă.
* **Artist, Album, Melodie:** Clasele ce moștenesc baza și implementează detaliile specifice.
* **Recenzie<T>:** Clasă template pentru stocarea notelor și comentariilor.
* **Topuri:** Clasă utilitară pentru procesarea datelor și generarea clasamentelor.

---

### 🚀 Cum se rulează
Asigură-te că ai un compilator C++ (min. standard **C++17**). Plasează fișierul `date.txt` în același director cu executabilul.

**Compilare și rulare (Linux/Bash):**
```bash
g++ main.cpp Artist.cpp Album.cpp Melodie.cpp -o rym_app
./rym_app
