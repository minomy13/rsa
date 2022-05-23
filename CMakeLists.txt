cmake_minimum_required(VERSION 3.22)
project(RSA)

set(CMAKE_CXX_STANDARD 14)

add_executable(RSA main.cpp bigint/bigint.h euclid.h ask.h decrypt.h prime.h ownbigpow.h getblocks.h encrypt.h)
