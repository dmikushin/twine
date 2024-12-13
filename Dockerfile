FROM ubuntu:22.04

RUN apt update && \
    apt install --no-install-recommends -y build-essential gcc-multilib vim flex bison

COPY . /src/wine/

WORKDIR /src/wine

RUN mkdir build && cd build && \
    ../configure --prefix=$(pwd)/../install --without-x --without-freetype --disable-tests && \
    make include/htiframe.h 2>&1 | tee log && \
    make 2>&1 | tee -a log && \
    make install 2>&1 | tee -a log
