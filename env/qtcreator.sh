#!/bin/bash
set -ex

# +=====================================================================================+
SCRIPTDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"
# +=====================================================================================+
IMAGE=localhost:5000/aoi-dev
CONTAINER_NAME=aoi-container
FAKE_HOME=$SCRIPTDIR/dev-env-home           # Build docker home directory
APP_DIR=$SCRIPTDIR/../app                   # Application directory 
SHARED_SPACE_DIR=$SCRIPTDIR/../shared-space # Application directory 
# +=====================================================================================+

# Set fonts config
mkdir -p $FAKE_HOME
FONTCONF=.config/fontconfig/fonts.conf
if [ ! -e  $FAKE_HOME/$FONTCONF ] ; then
    mkdir -p `dirname $FAKE_HOME/$FONTCONF`
    cp $HOME/$FONTCONF $FAKE_HOME/$FONTCONF
fi

# Enable anyone to connect to xhost server
xhost +

# Start docker container
docker run --rm --name $CONTAINER_NAME \
    --privileged --net=host -it \
    -u `id -u`:`id -g` -e DISPLAY -e LANG=C.UTF-8 -e LC_ALL=C.UTF-8 \
    --volume="/etc/passwd:/etc/passwd:ro" \
    --volume="/tmp/.X11-unix:/tmp/.X11-unix:rw" \
    --volume="$FAKE_HOME:/home/$(id -un)" \
    --volume="$APP_DIR:/home/$(id -un)/app" \
    --volume="$SHARED_SPACE_DIR:/home/$(id -un)/shared-space" \
    $IMAGE
