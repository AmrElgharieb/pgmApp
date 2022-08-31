FROM gcc:latest

COPY . /usr/source/pgm_app

WORKDIR /usr/source/pgm_app

RUN g++ main.cpp pgm.cpp -o pgm_app
 
CMD ["./pgm_app","/usr/source/pgm_app/files"] 








# Steps for building the image

#docker build . -t pgm_app:1.0
#docker run -v [FULL/PATH/TO/INPUT/FILES]:/usr/source/pgm_app/files pgm_app:1.0
#docker cp Container_id :/usr/source/pgm_app/files/average.pgm  [FULL/PATH/TO/INPUT/FILES]


