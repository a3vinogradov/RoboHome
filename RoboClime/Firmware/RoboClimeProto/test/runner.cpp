 #include "unity.h"
 #include "test_fsmanager_native.h"
 #include "test_idisplay.h"
 #include "test_log_native.h"
 #include "test_main_controller_native.h"
 
void setUp(void) {
    // Установочный код, запускается перед каждым тестом
}

void tearDown(void) {
    // Код очистки, запускается после каждого теста
}

int main(void) {
    UNITY_BEGIN();
    
    // Регистрация тестовых случаев
    RUN_TEST(test_file_exists);
    RUN_TEST(test_file_read);
    RUN_TEST(test_default_constructor);

    // String Log
    RUN_TEST(test_log_create);
    RUN_TEST(test_log_write);
    RUN_TEST(test_log_writeln);
    RUN_TEST(test_log_multywrite);
    RUN_TEST(test_log_clear);

    // Composite Log
    RUN_TEST(test_compositor_log_create);
    RUN_TEST(test_compositor_log_add_child_success);
    RUN_TEST(test_compositor_log_add_null_fail);
    RUN_TEST(test_compositor_log_add_capacity_fail);
    RUN_TEST(test_compositor_log_add_exists_fail);
    RUN_TEST(test_compositor_log_remove_exists_success);
    RUN_TEST(test_compositor_log_remove_notexists_fail);
    RUN_TEST(test_compositor_log_count);
    RUN_TEST(test_compositor_log_count_fragmentate);
    RUN_TEST(test_compositor_log_IsExists_true);
    RUN_TEST(test_compositor_log_IsExists_false_null);
    RUN_TEST(test_compositor_log_IsExists_false_notexists);
    RUN_TEST(test_compositor_log_persistmethods_empty);
    RUN_TEST(test_compositor_log_write);
    RUN_TEST(test_compositor_log_writeln);
    RUN_TEST(test_compositor_log_clear);
    RUN_TEST(test_compositor_log_remove_affects_behavior);
    
    RUN_TEST(test_create_display_console);
    RUN_TEST(test_display_show_page0);
    RUN_TEST(test_display_show_page1);
    RUN_TEST(test_display_draw_pointer);
    RUN_TEST(test_display_draw_void);
    

    RUN_TEST(test_mainctrl_create);

    return UNITY_END();
}