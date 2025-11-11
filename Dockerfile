FROM ubuntu:jammy

RUN apt-get update && \
    apt-get install -y python3 python3-pip gcc clang && \
    pip3 install --no-cache-dir autograder
