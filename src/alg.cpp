// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return value;
    } else {
        return value * pown(value, n-1);
    }
}

uint64_t fact(uint16_t n) {
  uint64_t res = n, schet = n;
  if (res <= 1) {
    return 1;
  }
  while (schet != 1) {
    res = res * (schet - 1);
    schet--;
  }
  return res;
}

double calcItem(double x, uint16_t n) {
  return (pown(x, n) / fact(n));
}

double expn(double x, uint16_t count) {
  double res = 0;
  for (int i = count; i >= 0; i--)
    res += calcItem(x, i);
  return res;
}

double sinn(double x, uint16_t count) {
  double res = 0;
    for (int i = count; i > 0; i--) {
        res += pown(-1, i-1) * calcItem(x, 2*i-1);
    }
    return res;
}

double cosn(double x, uint16_t count) {
  double res = 0;
    for (int i = count; i > 0; i--) {
        res += pown(-1, i-1) * calcItem(x, 2*i-2);
    }
    return res;
}
