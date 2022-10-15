# Library-System using C-Language

Program dengan ADT dengan bahasa C untuk kasus peminjaman buku perpustakaan (mencakup minimal data mahasiswa, buku yang dipinjam, lama waktu peminjaman, waktu pengembalian, denda jika terlambat mengembalikan).

Fitur :
- Perpustakaan (Add Buku, Get Buku, Update Buku, Delete Buku)
- Peminjaman (Add Peminjaman, Get Peminjaman, Delete Peminjaman, Return Peminjaman, Denda)

| Model | Description | Define |
| ----- | ----------- | ------ |
| Book | Mendefiniskan detail buku seperti id, title, description, etc | [book.c] |
| Library | Berisikan array yang berisi book dan jumlah buku | [library.c] |
| Mahasiswa | Mendefinisikan detail mahasiswa ketila meminjam buku | [mahasiswa.c] |
| Borrowing | Medefinisikan sebuah peminjaman yang berisi data book dan mahasiswa | [borrowing.c] |
| BorrowingList | Berisikan array yang berisi peminjaman dan jumlah peminjaman | [borrowing_list.c] |
| Time | Mendefinisikan data waktu day, month, year | [time.c]

### Usage

- Initializing :

```
void main() {
    struct Library lib = initLibrary();
    struct BorrowingList borrowing_list = initBorrowingList();
    
    ...
}
```

- Handler :
```
LibraryHandler(&lib); // Handler untuk library
BorrowingHandler(&lib, &borrowing_list); // Handler untuk Peminjaman
```

### Service

Library
- ### Add Book

Fungsi untuk menambahkan buku ke library

```
struct Book AddBook(struct Library *library, struct Book book, char *error){
    book.Borrowed = 0;
    for (int i = 0; i < library->count; i++) {
        int compare = strcmp(book.ID, library->books[i].ID);
        if (compare == 0) {
            strcpy(error, BOOK_ALREADY_EXIST);
            return book;
        }
    }

    if (library->count == 0) {
        library->books[0] = book;
    } else {
        library->books[library->count] = book;
    }
    library->count += 1;

    return book;
}
```
- ### Get Book

Fungsi untuk mencari buku berdasarkan id buku

```
struct Book *GetBook(struct Library *library, char *id, char *error){
    for (int i = 0; i <= library->count; i++ ) {
        int result = strcmp(id, library->books[i].ID);
        if (result == 0) {
            return (&library->books[i]);
        }
    };

    strcpy(error, BOOK_NOT_FOUND);
};
```

- ### Update Book

Fungsi untuk mengubah buku berdasarkan id buku

```
struct Book UpdateBook(struct Library *lib, struct Book book, char *error) {
    for (int i = 0; i <= lib->count; i++) {
        if (strcmp(lib->books[i].ID, book.ID) == 0) {
            strcpy(lib->books[i].Title, book.Title);
            strcpy(lib->books[i].Description, book.Description);
            strcpy(lib->books[i].Author, book.Author);
            strcpy(lib->books[i].Publisher, book.Publisher);
            lib->books[i].CountPage = book.CountPage;
            lib->books[i].Year = book.Year;
            return lib->books[i];
        }
        strcpy(error, BOOK_NOT_FOUND);
    }
}
```

- ### Delete Book

Fungsi untuk menghapus buku berdasarkan id buku

```
bool DeleteBook(struct Library *lib, char *id, char *error) {
    for (int i = 0; i < lib->count; i++) {
        int compare = strcmp(id, lib->books[i].ID);
        if (compare == 0) {
            for (int j = i + 1; j < lib->count; j++) {
                lib->books[i] = lib->books[j];
            }
            lib->count = lib->count - 1;
            return true;
        }
    }

    strcpy(error, BOOK_NOT_FOUND);
    return false;
}
```
Borrowing

> Untuk mengubah denda keterlambatan pengembalian per hari berada pada [setting.h]

- ### Add Borrowing

Menambahkan peminjaman dengan memasukan id book dan informasi mahasiswa

```
struct Borrowing AddBorrowing(
    struct Library *library, 
    struct BorrowingList *borrowing_list, 
    struct Mahasiswa mahasiswa,
    char *id, 
    char *error
) {
    for (int i = 0; i <= library->count; i++ ) {
        int result = strcmp(id, library->books[i].ID);
        if (result == 0) {
            if (library->books[i].Quantity != library->books[i].Borrowed) {
                if (borrowing_list->count == 0) {
                    struct Borrowing b;
                    
                    library->books[i].Borrowed++;
                    b.book = (&library->books[i]);

                    time_t t = time(NULL);
                    t += 604800;
                    struct tm now = *localtime(&t);
                    struct Time deadline;
                    deadline.day = now.tm_mday;
                    deadline.month = now.tm_mon;
                    deadline.year = now.tm_year;

                    b.deadline = deadline;
                    b.mahasiswa = mahasiswa;
                    b.late_charge = 0;

                    borrowing_list->list[0] = b;
                    
                    borrowing_list->count++;
                    return borrowing_list->list[0]; 
                } else {
                    library->books[i].Borrowed++;
                    borrowing_list->list[borrowing_list->count].book = (&library->books[i]);

                    time_t t = time(NULL);
                    struct tm now = *localtime(&t);
                    struct tm date = { .tm_mday = now.tm_mday + 7, .tm_mon = now.tm_mon, .tm_year = now.tm_year };
                    struct Time deadline;
                    deadline.day = date.tm_mday;
                    deadline.month = date.tm_mon;
                    deadline.year = date.tm_year;

                    struct Borrowing b;

                    b.deadline = deadline;
                    b.mahasiswa = mahasiswa;
                    b.late_charge = 0;

                    borrowing_list->list[borrowing_list->count] = b;

                    borrowing_list->count++;
                    return borrowing_list->list[borrowing_list->count];
                }
            } else {
                strcpy(error, OUT_OF_BOOK);
            }
        } else {
            strcpy(error, BOOK_NOT_FOUND);
        }
    };
}
```

- ### Get Borrowing

Mendapatkan detail peminjaman berdasarkan nomor peminjaman dan akan mengenerate denda jika telah melebihi batas waktu

> Nomor peminjaman berdasarkan urutan array ke - n

```
struct Borrowing GetBorrowing(struct BorrowingList *borrowing_list, int id, char *error){
    if (id - 1 <= borrowing_list->count ) {
        
        time_t t = time(NULL);
        struct tm now = *localtime(&t);

        struct Time deadline = borrowing_list->list[id-1].deadline;
        if (now.tm_mday > deadline.day) {
            int number_of_days_late = now.tm_mday - deadline.day;
            borrowing_list->list[id-1].late_charge = number_of_days_late * LATE_CHARGE;
        }

        return borrowing_list->list[id-1];
    }

    strcpy(error, BORROWING_NOT_FOUND);
};
```

- ### Return Book

Fungsi untuk pengembalian buku dan akan mengenerate denda keterlambatan

```
struct Borrowing ReturnBorrowing(struct BorrowingList *borrowing_list, int id, char *error){
    if (id - 1 <= borrowing_list->count ) {
        
        time_t t = time(NULL);
        struct tm now = *localtime(&t);

        struct Time deadline = borrowing_list->list[id-1].deadline;
        if (now.tm_mday > deadline.day) {
            int number_of_days_late = now.tm_mday - deadline.day;
            borrowing_list->list[id-1].late_charge = number_of_days_late * LATE_CHARGE;
        }

        DeleteBorrowing(borrowing_list, id, error);

        return borrowing_list->list[id-1];
    }

    strcpy(error, BORROWING_NOT_FOUND);
};
```

- ### Delete Borrowing

Menghapus peminjaman

```
bool DeleteBorrowing(struct BorrowingList *borrowing_list, int id, char *error) {
    if (id - 1 <= borrowing_list->count) {
        for (int i = id; i < borrowing_list->count; i++) {
            borrowing_list->list[i - 1] = borrowing_list->list[i];
        }
        borrowing_list->count--;
        return true;
    }
    strcpy(error, BORROWING_NOT_FOUND);
    return false;
}
```