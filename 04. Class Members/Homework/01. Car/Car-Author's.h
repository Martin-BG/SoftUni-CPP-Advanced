#ifndef CAR_H
#define CAR_H

#include <string>

using namespace std;

class Car
{

private:

    string m_sBrand;

    string m_sModel;

    unsigned int m_unYear;

public:

    Car( string sBrand, string sModel, unsigned int unYear )
    {
        m_sBrand = sBrand;

        m_sModel = sModel;

        m_unYear = unYear;
    }

    string GetBrand() const
    {
        return m_sBrand;
    }

    string GetModel() const
    {
        return m_sModel;
    }

    int GetYear() const
    {
        return m_unYear;
    }

};

#endif // !CAR_H
