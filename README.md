# Environment Setup

## Description
This is a Docker environment for building applications with Qt and OpenCV.

## Steps
1. Navigate to the build environment - `$ cd ./env/build-env`
2. Build the build environment - `$ docker build -t "localhost:5000/aoi-build" .`
3. Navigate to the dev environment - `$ cd ./../dev-env`
4. Build the dev environment - `$ docker build -t "localhost:5000/aoi-dev" .`
