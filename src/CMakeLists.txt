add_library(account account.cpp)
target_include_directories(account PUBLIC ../include)

add_executable(bank main.cpp bank.cpp)
target_link_libraries(bank PUBLIC account)
target_compile_options(bank PRIVATE -O3 -pedantic-errors)