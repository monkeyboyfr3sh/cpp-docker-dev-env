
####################################
# Get Host #########################
####################################
# FROM amd64/ubuntu:bionic
FROM ubuntu:focal

ARG DEBIAN_FRONTEND=noninteractive

####################################
# Get Tools ########################
####################################
RUN apt-get update && apt-get install -y \
    libgl1-mesa-dev \
    libgtk2.0-dev \
    git \
    cmake \
    pkg-config

####################################
# Setup OpenCV #####################
####################################
# Clone the OpenCV repository
RUN git clone https://github.com/opencv/opencv.git

# Build and install OpenCV in the environment
RUN mkdir -p opencv/build && \
    cd opencv/build/ && \
    cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D WITH_TBB=ON -D BUILD_NEW_PYTHON_SUPPORT=ON -D WITH_V4L=ON -D INSTALL_C_EXAMPLES=ON -D INSTALL_PYTHON_EXAMPLES=ON -D BUILD_EXAMPLES=ON -D WITH_QT=ON -D WITH_GTK=ON -D WITH_OPENGL=ON .. && \
    make -j8 && \
    make install

####################################
# Get Qt Default ###################
####################################
RUN apt-get update && apt-get install -y cmake g++ make qt5-default build-essential

####################################
# Setup Custom Qt ##################
####################################
RUN apt-get -y update && DEBIAN_FRONTEND=noninteractive apt-get -y install \
    git \
    cmake \
    python3 \
    python3-pip \
    build-essential \
    libdbus-1-3 \
    libpulse-mainloop-glib0

RUN pip3 install aqtinstall

ARG QT=5.15.0
ARG QT_MODULES=all
ARG QT_HOST=linux
ARG QT_TARGET=desktop
ARG QT_ARCH=
RUN aqt install-qt \
    ${QT_HOST} ${QT_TARGET} \
    -O /opt/qt \
    ${QT} \ 
    -m ${QT_MODULES}

ENV PATH /opt/qt/${QT}/gcc_64/bin:$PATH
ENV QT_PLUGIN_PATH /opt/qt/${QT}/gcc_64/plugins/
ENV QML_IMPORT_PATH /opt/qt/${QT}/gcc_64/qml/
ENV QML2_IMPORT_PATH /opt/qt/${QT}/gcc_64/qml/

CMD ["/bin/bash"]
