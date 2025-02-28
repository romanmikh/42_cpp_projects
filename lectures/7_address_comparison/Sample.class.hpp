/*
- Like in C, header file for prototypes of class, its const/destructors and attributes
*/

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

struct Sample {

public: 

    Sample(int n);
    ~Sample(void);
    
    int     getFoo(void) const;
    int     compare(Sample * other) const;

private:

    int _foo;

};

#endif // SAMPLE_CLASS_H