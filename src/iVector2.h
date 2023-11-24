#pragma once

class iVector2 {
public:
    int m_x, m_y;
    iVector2();
    iVector2(int x, int y);
    iVector2 operator+(iVector2 vector);
    iVector2 operator-(iVector2 vector);
    iVector2 operator*(iVector2 vector);
    iVector2 operator/(iVector2 vector);
    iVector2 operator+(int number);
    iVector2 operator-(int number);
    iVector2 operator*(int number);
    iVector2 operator/(int number);
    void operator+=(iVector2 vector);
    void operator-=(iVector2 vector);
    void operator*=(iVector2 vector);
    void operator/=(iVector2 vector);
};
