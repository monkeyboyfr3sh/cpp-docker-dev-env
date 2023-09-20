FROM localhost:5000/aoi-build

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    git \
    qtcreator \
    libxrender1 \
    gdb \
    fonts-ubuntu \
    dbus \
    nano \
    curl \
    unzip

RUN apt-get update && apt-get install -y qt5-doc qt5-doc-html qtbase5-doc-html qtbase5-examples

# # Copy host source into container
# RUN mkdir -p /root/app
# COPY ${HOST_DIR_PATH} /root/app/

# # Download an image into the container
# RUN curl https://www.python.org/static/apple-touch-icon-144x144-precomposed.png > /root/app/test/image.png

# CMD ["/usr/bin/qtcreator"]