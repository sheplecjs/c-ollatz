FROM ubuntu:latest

RUN apt update
RUN apt install -y build-essential
RUN apt install -y clang-format
RUN apt install -y git
RUN apt install -y libgmp-dev
