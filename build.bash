g++ source/main.cpp \
    source/ui/blocks.cpp \
    source/states/loadingState.cpp \
    source/states/menuState.cpp \
   -I include \
    -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
