add_library(cidade STATIC cidade.cpp)

install(TARGETS cidade DESTINATION lib)
install(FILES cidade.hpp DESTINATION include)
