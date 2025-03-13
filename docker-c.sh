#!/bin/bash

ARQUIVO=trabalho1

docker run -it --rm -v $(pwd)/${ARQUIVO}.c:/${ARQUIVO}.c gcc:latest bash -c "gcc ${ARQUIVO}.c -o ${ARQUIVO} && ./${ARQUIVO}"