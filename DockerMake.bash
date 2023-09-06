#!/bin/bash

#################### SETTINGS ####################

# Colors for echo command
R='\033[0;31m'   #'0;31' is Red's ANSI color code
G='\033[0;32m'   #'0;32' is Green's ANSI color code
Y='\033[1;32m'   #'1;32' is Yellow's ANSI color code
B='\033[0;34m'   #'0;34' is Blue's ANSI color code
DGR='\033[1;30m'   #'0;34' is Blue's ANSI color code
N='\033[0;0m'    #'0;34' is no color

# Black        0;30     Dark Gray     1;30
# Red          0;31     Light Red     1;31
# Green        0;32     Light Green   1;32
# Brown/Orange 0;33     Yellow        1;33
# Blue         0;34     Light Blue    1;34
# Purple       0;35     Light Purple  1;35
# Cyan         0;36     Light Cyan    1;36
# Light Gray   0;37     White         1;37

SPLIT_MSG="${B} ######################################################################## ${N}"
SMALL_SPLIT_MSG="${DGR} ------------------------------------------------------------------ ${N}"

DOCKER_CONTAINER_NAME="gcc-arm-none-eabi-sphinx"

# Run command incide docker
RUN_CMD="docker exec -i ${DOCKER_CONTAINER_NAME} bash -c"

BUILD_TARGET='all'

#################### SETTINGS END ####################

StarDocker() {
    export MSYS_NO_PATHCONV=1
    # If ghs container is alive: kill it
    docker rm --force ${DOCKER_CONTAINER_NAME} &> /dev/null
    
    # Start Docker
    if docker run -w /work -v "$(pwd):/work" -idt --name ${DOCKER_CONTAINER_NAME} ${DOCKER_CONTAINER_NAME} bash >> /dev/null;
    then
        echo -e "${G} --- Start Docker OK--- ${N}"
    else
        echo -e "${R} --- Start Docker ERROR --- ${N}"
    fi
}

EndDocker() {
    if docker rm --force ${DOCKER_CONTAINER_NAME} >> /dev/null;
    then
        echo -e "${G} --- Docker killed succesfully --- ${N}"
    else
        echo -e "${R} --- Kill Docker ERROR --- ${N}"
    fi

    echo -e "${G} --- End of Compilation --- ${N}\n"
}

BuildProject() {
    echo -e "${G} --- Start Compilation --- ${N}"

    if [[ ! -d "build" ]]
    then
        ConfugureProject
        echo -e "\n"${SMALL_SPLIT_MSG}"\n"
    fi

    if ${RUN_CMD} "cd build && cmake --build . --target ${BUILD_TARGET}";
    then
        echo -e "${G} --- Compilation OK --- ${N}"
    else
        echo -e "${R} --- Compilation ERROR --- ${N}"
    fi
}

CleanProject() {
    echo -e "${G} --- Start Cleaning --- ${N}"

    if ${RUN_CMD} "rm -f -r build";
    then
        echo -e "${G} --- Cleaning OK --- ${N}"
    else
        echo -e "${R} --- Cleaning ERROR --- ${N}"
    fi
}

ConfugureProject() {
    echo -e "${G} --- Start Configuring Cmake --- ${N}"

    if ${RUN_CMD} "mkdir -p build && cd build && cmake -DCMAKE_BUILD_TYPE=Debug -GNinja ../";
    then
        echo -e "${G} --- Configuring Cmake OK --- ${N}"
    else
        echo -e "${R} --- Configuring Cmake ERROR --- ${N}"
    fi
}

Build() {
    StarDocker
    echo -e ${SPLIT_MSG}"\n"
    BuildProject
    echo -e "\n"${SPLIT_MSG}
    EndDocker
}

Rebuild() {
    StarDocker
    echo -e ${SPLIT_MSG}"\n"
    CleanProject
    echo -e "\n"${SMALL_SPLIT_MSG}"\n"
    ConfugureProject
    echo -e "\n"${SMALL_SPLIT_MSG}"\n"
    BuildProject
    echo -e "\n"${SPLIT_MSG}
    EndDocker
}

Clean(){
    StarDocker
    echo -e ${SPLIT_MSG}"\n"
    CleanProject
    echo -e "\n"${SPLIT_MSG}
    EndDocker
}

Help() {
    echo "
    Options:
        No Option == --build
        --build              Build EHAL, copy lib to ASW and build ASW
        --rebuild            Same as build, but clean cache of EHAL and ASW
        --rebuild-ASW        Same as build, but clean cache only of ASW
        --clean              Clean cache of EHAL and ASW
        -h, --help               Help info

    "
}

########## START ##########

VALID_ARGS=$(getopt -o :h --long build,rebuild,clean,help -- "$@")
if [[ $? -ne 0 ]]; then
    exit 1;
fi

eval set -- "$VALID_ARGS"
while [ : ]; do
  case "$1" in
    --build)
        Build
        break
        ;;
    --rebuild)
        Rebuild
        break
        ;;
    --clean)
        Clean
        break
        ;;
    -h | --help)
        Help
        break
        ;;
    --) shift; 
        Build
        break 
        ;;
  esac
done