# Подпроект тестов
add_executable(run_tests
    test_pet.cpp
    test_event.cpp
)

target_link_libraries(run_tests PRIVATE Qt5::Test Qt5::Core)

add_test(NAME PetTests COMMAND run_tests)
add_test(NAME EventTests COMMAND run_tests)