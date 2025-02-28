/*
- Like in C, header file for prototypes of class, its const/destructors and attributes
*/

#ifndef SAMPLE_CLASS_1_H
# define SAMPLE_CLASS_1_H

struct Sample1 {

public: 

    Sample1(void);
    ~Sample1(void);
    
    int     getFoo(void) const;
    void    setFoo(int v);

private:

    int _foo;

};

#endif // SAMPLE_CLASS_1_H