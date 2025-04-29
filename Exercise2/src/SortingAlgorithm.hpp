#pragma once

#include <iostream>
#include <vector>


namespace SortLibrary {

template<typename T>
concept Sortable = requires(T& t){
    {t < t} -> std::convertible_to<bool>;
};


template<Sortable T>
void BubbleSort(std::vector<T>& v)
{
    const unsigned int n = v.size();
        
        for (unsigned int i = 0; i < n - 1; i++) {
            for (unsigned int j = 0; j < n - i -1; j++) {
                if (v[j] > v[j+1]) {
                    std::swap(v[j], v[j + 1]);
                }
            }
        }

}



template<Sortable T>
void HeapSort(std::vector<T>& v) {
    int n = v.size();


    for (int i = n / 2 - 1; i >= 0; i--) {
        int radice = i;
        while (true) {
            int grande = radice;
            int sx = 2 * radice + 1;
            int dx = 2 * radice + 2;

            if (sx < n && v[sx] > v[grande])
                grande = sx;
            if (dx < n && v[dx] > v[grande])
                grande = dx;

            if (grande != radice) {
                std::swap(v[radice], v[grande]);
                radice = grande;
            } else {
                break;
            }
        }
    }

    for (int i = n - 1; i > 0; --i) {
        std::swap(v[0], v[i]);

        int radice = 0;
        while (true) {
            int grande = radice;
            int sx = 2 * radice + 1;
            int dx = 2 * radice + 2;

            if (sx < i && v[sx] > v[grande]) grande = sx;
            if (dx < i && v[dx] > v[grande]) grande = dx;

            if (grande != radice) {
                std::swap(v[radice], v[grande]);
                radice = grande;
            } else {
                break;
            }
        }
    }
}


}

