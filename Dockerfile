FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update
RUN apt-get install -y \
        htop \
        jq \
        wget \
        curl \
        cmake \
        g++ \
        build-essential \
        bash \
        vim \
        git

RUN mkdir /root/src

