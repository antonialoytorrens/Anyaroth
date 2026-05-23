FROM debian:trixie

ARG DEBIAN_FRONTEND=noninteractive
ARG CXX=g++
ARG JOBS=

RUN apt-get update && apt-get install -y --no-install-recommends \
        build-essential \
        make \
        pkg-config \
        g++ \
        clang-19 \
        libsdl2-dev \
        libsdl2-image-dev \
        libsdl2-mixer-dev \
        libsdl2-ttf-dev \
        libbox2d-dev \
        nlohmann-json3-dev \
        ca-certificates \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /src
COPY . /src

WORKDIR /src/Anyaroth
RUN make distclean >/dev/null 2>&1 || true \
    && make CXX=${CXX} -j${JOBS:-$(nproc)}

CMD ["./bin/Anyaroth"]
