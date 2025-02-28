/*
- Like in C, header file for prototypes of class, its const/destructors and attributes
*/

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample {

public:

    float const pi;
    int         qd;

    Sample(float const f);
    ~Sample(void);

    void bar(void) const;  // const keyword after function means that the function will *not* modify the current instance of the class
};

#endif // SAMPLE_CLASS_H