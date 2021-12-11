add_library(account account.cpp)
target_include_directories(account PUBLIC ../include)

add_library(account_builder account_builder.cpp)
target_include_directories(account_builder PUBLIC ../include)

add_library(database database.cpp)
target_link_libraries(database PUBLIC account)

add_library(bank_ bank.cpp)
target_link_libraries(bank_ PUBLIC account_builder)

add_executable(bank main.cpp)
target_link_libraries(bank PUBLIC database bank_)
target_compile_options(bank PRIVATE -O3 -pedantic-errors)