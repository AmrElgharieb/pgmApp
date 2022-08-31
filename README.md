# pgmApp
This repository shall contain the implementation of a simple program which generates the average pgm file for multiple pgm files

## Steps for running the app

- Clone the repository:  git clone https://github.com/AmrElgharieb/pgmApp.git  

1- Using the terminal:

- Compile the code:      g++  main.cpp  pgm.cpp -o pgm_app -Wall  
- Run the app:           pgm_app.exe [full\\\path\\\to\\\the\\\input\\\files]     (e.g. pgm_app.exe E:\\\work\\\InputFiles)


2- Using docker

- Build the docker image:   docker build . -t pgm_app:1.0
- Run the created image:    docker run -v [full/path/to/the/input/files]:/usr/source/pgm_app/files pgm_app:1.0
- Save the generated file: 	docker cp container_id:/usr/source/pgm_app/files/average.pgm  [full/path/to/the/input/files]

- To get the container Id use : docker ps -a 
