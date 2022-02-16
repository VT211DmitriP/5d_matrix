add_library(data_structures
        matrix/matrix.c
        matrix/matrixTest.c matrix/matrixTest.h)

target_link_libraries(data_structures algorithms)