g++ source/*.cpp \
   source/*/*.cpp \
   -I include \
   -DTEST_BUILD \
   -g \
   -o blueprint \
   -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
