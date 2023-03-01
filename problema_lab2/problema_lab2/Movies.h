#pragma once
#define _CRT_SECURE_NO_WARNING
class Movie {
  private:
    char name[256];
    int release, length;
    double score;

  public:

    void set_name(const char* name);
    void set_score(double x);
    void set_year(int x);
    void set_length(int x);
    const char* get_name();
    double get_score();
    int get_year();
    int get_length();
    int get_passed_years();
};
