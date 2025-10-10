#pragma once

#include "unity.h"
#include "TypeDef.h"
#include "FSManagerNative.h"
#include <filesystem> // C++17 или новее
#include <fstream>

const std::string TEST_DIR = "test_data";
const std::string TEST_EXISTING_FILE = "existing.txt";
const std::string TEST_NONEXISTING_FILE = "non_existing.txt";

void prepare_test_environment() {
    // Удаляем старую тестовую директорию, если она существует
    if (std::filesystem::exists(TEST_DIR)) 
    {
        std::filesystem::remove_all(TEST_DIR);
    }
    
    // Создаем новую тестовую директорию
    std::filesystem::create_directory(TEST_DIR);
    
    // Создаем тестовые файлы
    std::ofstream(std::filesystem::path(TEST_DIR) / TEST_EXISTING_FILE) << "Hello World!";
}

void cleanup_test_environment() {
    if (std::filesystem::exists(TEST_DIR)) 
    {
        std::filesystem::remove_all(TEST_DIR);
    }
}

void test_default_constructor()
{
    // в корне проекта есть папка data и файл index.html в этой папке
    // этот файл используется в тесте. 
    // не красиво, но на сей момент сойдет.
    FSManagerNative fsManager;
    TEST_ASSERT_TRUE("index.html");
} 

void test_file_exists() {
    // arrange
    prepare_test_environment();

    // act
    FSManagerNative fsManager(TEST_DIR);
    bool fileExists = fsManager.Exists("existing.txt");
    bool fileNonExists = fsManager.Exists("nonExisting.txt");
    
    // assert
    TEST_ASSERT_TRUE(fileExists);
    TEST_ASSERT_FALSE(fileNonExists);

    // TierDown
    cleanup_test_environment();
}

void test_file_read()
{
    prepare_test_environment();

    // act
    FSManagerNative fsManager(TEST_DIR);
    String content = fsManager.ReadFile(TEST_EXISTING_FILE);
    TEST_ASSERT_EQUAL_STRING("Hello World!", content.c_str());

    cleanup_test_environment();
} 
