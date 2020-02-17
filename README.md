# STHASH

A dynamic hash library userd for `ngx_http_stunnel_module`.

## Usage

This repo aims to provide an simple example of how to implement the hash library that required by `ngx_http_stunnel_module`. Just copy the dynamic library to a path where it can be found by the linker.

## Deps

- C compiler with c99 support at leaset.
- Mbedtls dev package to provide hmac interface.
- Build tool (Optional, recommand xmake or cmake)

## Build

- Xmake (Recommanded)

  ```shell
  xmake build -w
  ```

- Cmake (Recommanded)

  ```shell
  mkdir build && cd build
  cmake .. && make
  ```

- Gcc
  
  ```shell
  mkdir build
  gcc -Wall -std=c99 -shared -fPIC \
  -lmbedtls -lmbedcrypto src/sthash.c \
  -o build\libsthash.so
  ```

## API

See [sthash.h](src/sthash.h).

## Symbols Exported

Everyone can create his own hash library userd for `ngx_http_stunnel_module` easily. Make sure that follow symbols are accessiable in your library.

| symbol       | description       | must |
| ------------ | ----------------- | ---- |
| sthash_init  | Setup secret key. | Yes  |
| sthash_do    | Do hmac.          | Yes  |
| sthash_reset | Clear key setting | No   |
