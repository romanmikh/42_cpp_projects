/*
- Like in C, header file for prototypes of class, its const/destructors and attributes
*/

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample {

public:

    int public_foo;

    Sample(void);
    ~Sample(void);

    void public_bar(void) const;


private:

    int _private_foo;

    void _private_bar(void) const;
};

#endif // SAMPLE_CLASS_H