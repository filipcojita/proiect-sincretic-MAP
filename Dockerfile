FROM gcc:latest
WORKDIR /usr/src/myapp
COPY tari2.cpp .
RUN gcc -o myapp tari2.cpp -lstdc++
CMD ["./myapp"]