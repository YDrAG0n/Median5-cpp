#include <iostream>


float MF_data[5], MF_sort[5];

float median5(float v) // this will allow 2 of 5 consequent values to be one-side failed
{
    int i, j;
    float vv;

    for (i = 0; i < 4; i++)
        MF_sort[i] = MF_data[i] = MF_data[i+1];

    MF_data[4] = v;

    // 1 iteration of shift-and-insert
    i = 4;
    while (v < MF_sort[i] && i > 0)
    {
        MF_sort[i] = MF_sort[i-1];
        i--;

    }
    MF_sort[i] = v;

    // bubble sort
    for (j = 4; j > 1; j--)
        for (i = 0; i < j; i++)
        {
            if (MF_sort[i] > MF_sort[i + 1])
            {
                vv = MF_sort[i];
                MF_sort[i] = MF_sort[i+1];
                MF_sort[i+1] = vv;
            }
        }

    return MF_sort[2];
}


int main()
{
    int i, v;
    for (i = 0; i < 500; i++)
    {
        v = int(std::sin(i*6.28/100.0) * 50.0 + 50);
        if (i % 7 == 0)
            v = -10;
        if (i % 15 == 0)
            v = +210;
        if (i % 11 == 0)
            v = +110;
        if (i % 17 == 0)
            v = +310;

        std::cout << v << "\t" << median5(v) << std::endl;
    }
}