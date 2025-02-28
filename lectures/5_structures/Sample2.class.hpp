/*
- Like in C, header file for prototypes of class, its const/destructors and attributes
*/

#ifndef SAMPLE_CLASS_2_H
# define SAMPLE_CLASS_2_H

class Sample2 {

    int foo;

    Sample2(void);
    ~Sample2(void);

    void bar(void) const;
};

#endif // SAMPLE_CLASS_2_H