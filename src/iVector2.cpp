#include "iVector2.h"

iVector2::iVector2() { m_x = 0; m_y = 0; }
iVector2::iVector2(int x, int y) { m_x = x; m_y = y; }

bool iVector2::operator==(iVector2 vector) { return (m_x == vector.m_x && m_y == vector.m_y); }

iVector2 iVector2::operator+(iVector2 vector) { return {m_x + vector.m_x, m_y + vector.m_y}; }
iVector2 iVector2::operator-(iVector2 vector) { return {m_x - vector.m_x, m_y - vector.m_y}; }
iVector2 iVector2::operator*(iVector2 vector) { return {m_x * vector.m_x, m_y * vector.m_y}; }
iVector2 iVector2::operator/(iVector2 vector) { return {m_x / vector.m_x, m_y / vector.m_y}; }

iVector2 iVector2::operator+(int number) { return {m_x + number, m_y + number}; }
iVector2 iVector2::operator-(int number) { return {m_x - number, m_y - number}; }
iVector2 iVector2::operator*(int number) { return {m_x * number, m_y * number}; }
iVector2 iVector2::operator/(int number) { return {m_x / number, m_y / number}; }

void iVector2::operator+=(iVector2 vector)
{
    m_x = m_x + vector.m_x;
    m_y = m_y + vector.m_y;
}
void iVector2::operator-=(iVector2 vector)
{
    m_x = m_x - vector.m_x;
    m_y = m_y - vector.m_y;
}
void iVector2::operator*=(iVector2 vector)
{
    m_x = m_x * vector.m_x;
    m_y = m_y * vector.m_x;
}
void iVector2::operator/=(iVector2 vector)
{
    m_x = m_x / vector.m_x;
    m_y = m_y / vector.m_y;
}

void iVector2::operator+=(int number)
{
    m_x = m_x + number;
    m_y = m_y + number;
}
void iVector2::operator-=(int number)
{
    m_x = m_x - number;
    m_y = m_y - number;
}
void iVector2::operator*=(int number)
{
    m_x = m_x * number;
    m_y = m_y * number;
}
void iVector2::operator/=(int number)
{
    m_x = m_x / number;
    m_y = m_y / number;
}
