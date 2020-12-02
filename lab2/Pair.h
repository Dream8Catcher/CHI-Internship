#ifndef CLION_PAIR_H
#define CLION_PAIR_H

template<class A, class B>
struct Pair
{
    A first;
    B second;

    Pair() : first(), second() {}
    Pair(const A& _f, const B& _s) : first(_f), second(_s) {}
    template <class _A1, class _B2>
    explicit Pair(const Pair<_A1, _B2> & _pair) : first(_pair.first), second(_pair.second) {}
    const A & getKey () const { return first; }
    const B & getValue () const { return second; }
};
#endif