#!/bin/bash
c++ $1 -Wall -Wextra -O2 -Wshadow -Wformat=2 -lm -lcrypt -std=c++11 -pipe -DONLINE_JUDGE