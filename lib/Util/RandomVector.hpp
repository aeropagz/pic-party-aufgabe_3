#pragma once
#include <iterator>
#include <random>
#include <vector>
#include <memory>

using std::move;
using std::unique_ptr;
using std::vector;

int random(int start, int end)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(start, end);
    return dist6(rng);
}

template <typename T>
unique_ptr<T> popRandom(vector<unique_ptr<T>> &v)
{
    int index = random(0, v.size() - 1);
    unique_ptr<T> el = move(v.at(index));
    v.erase(v.begin() + index);
    return el;
}

