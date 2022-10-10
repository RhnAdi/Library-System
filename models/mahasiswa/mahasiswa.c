#include <stdio.h>

struct Mahasiswa {
    char Name[20];
    char StudyProgram[20];
    char PhoneNumber[16];
    char Address[30];
    int NIM;
};

struct Mahasiswa initMahasiswa(
    char *name,
    char *study_program,
    char *phone_number,
    char *address,
    int nim
) {
    struct Mahasiswa m;
    strcpy(m.Name, name);
    strcpy(m.StudyProgram, study_program);
    strcpy(m.PhoneNumber, phone_number);
    strcpy(m.Address, address);
    m.NIM = nim;
    return m;
}