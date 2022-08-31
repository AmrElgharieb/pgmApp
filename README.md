# pgmApp
This repository shall contain the implementation of a simple program which generates the average pgm file for multiple pgm files

## Steps for running the app

1- Using the terminal:

- Clone the repository:  git clone https://github.com/AmrElgharieb/pgmApp.git  
- Compile the code:      g++  main.cpp  pgm.cpp -o pgm_app -Wall  
- Run the app:           pgm_app.exe FULL\\PATH\\TO\\THE\\INPUT\\FIles     (e.g. pgm_app.exe E:\\work\\InputFiles)


2- Using docker

- Build the docker image:   docker build . -t pgm_app:1.0
- Run the created image:    docker run -v FULL/PATH/TO/THE/INPUT/FILES:/usr/source/pgm_app/files pgm_app:1.0
- Save the generated file: 	docker cp CONTAINER_ID:/usr/source/pgm_app/files/average.pgm  FULL/PATH/TO/THE/INPUT/FILES

- To get the container Id used : docker ps -a 
