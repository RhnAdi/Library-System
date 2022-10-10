#ifndef MAHASISWA_H
#define MAHASISWA_H
#include "./mahasiswa.c"

struct Mahasiswa;

struct Mahasiswa initMahasiswa(
    char *name,
    char *study_program,
    char *phone_number,
    char *address,
    int nim
);

#endif