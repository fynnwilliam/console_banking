add_library(activity activity.cpp)
target_include_directories(activity PUBLIC ../include)

add_library(id_gen id_generator.cpp)
target_include_directories(id_gen PUBLIC ../include)

add_library(transaction transaction.cpp)
target_link_libraries(transaction PUBLIC activity id_gen)

add_library(account account.cpp)
target_link_libraries(account PUBLIC transaction)

add_library(account_builder account_builder.cpp)
target_include_directories(account_builder PUBLIC ../include)

add_library(database database.cpp)
target_link_libraries(database PUBLIC account)

add_library(bank_ bank.cpp)
target_link_libraries(bank_ PUBLIC account_builder)

add_executable(bank main.cpp)
target_link_libraries(bank PUBLIC database bank_)

if(MSVC)
  target_compile_options(bank PRIVATE /O2 /W4)
else()
  target_compile_options(bank PRIVATE -O3 -pedantic-errors)
endif()
