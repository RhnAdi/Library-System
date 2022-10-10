struct Time {
    int day;
    int month;
    int year;
};

struct Time initTime(
    int day,
    int month,
    int year
) {
    struct Time t;
    t.day = day;
    t.month = month;
    t.year = year;
    return t;
}