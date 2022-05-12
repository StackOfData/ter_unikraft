# Docker

## Documentation
1. https://faun.pub/what-is-docker-writing-hello-world-program-in-c-using-isolated-docker-environments-bde3fde91e88

## Commandes
### comming from *Documentation 1*
file -> dockerfile
```
FROM gcc:4.9
COPY . /HelloWorld
WORKDIR /HelloWorld/
RUN gcc -o HelloWorld helloworld.c
CMD ["./HelloWorld"]
```

Buils
```
docker build -t gcc-docker .
```

Run
```
docker run -it gcc-docker:latest
```
### from other doc
Print images
```
docker image ls
```

Remove an image 
```
docker image rm -f <ID>
```

Take a look at running container
```
docker ps
```