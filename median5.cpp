#include <iostream>

float MF_data[5], MF_sort[5];

float median5(float v) // this will allow 2 of 5 consequent values to be failed
{
    int i;
    float vv;

    for (i = 0; i < 4; i++)
        MF_sort[i] = MF_data[i] = MF_data[i+1];

    MF_sort[4] = v;

    // 1 iteration of shift-and-insert
    i = 4;
    while (v < MF_sort[i] && i > 0)
    {
        MF_sort[i] = MF_sort[i-1];
        i--;
    }
    MF_sort[i] = v;

    // bubble sort
    for (i = 4; i > 1; j--)
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
    int i;
    for (i = 0; i < 20; i++)
    {
        std::cout << i << "\t" << median5(i) << std::endl;
    }
}