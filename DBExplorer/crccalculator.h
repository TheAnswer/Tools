#ifndef CRCCALCULATOR_H
#define CRCCALCULATOR_H

class CRCCalculator {
public:
    CRCCalculator();
    ~CRCCalculator();

    static unsigned int hashCode(const char* str, int len);
};

#endif // CRCCALCULATOR_H
