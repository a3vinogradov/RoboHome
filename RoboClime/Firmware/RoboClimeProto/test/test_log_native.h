#pragma once

#include "unity.h"
#include "TypeDef.h"
#include "ILog.h"
#include "CStringLog.h"
#include "CCompositorLog.h"


void test_log_create()
{
    CStringLog logger;
    ILog* interface = &logger;  
    TEST_PASS();
} 

void test_log_write()
{
    CStringLog logger;
    ILog* interface = &logger;  
    String testString = "Test String";

    interface->Write(testString);
    TEST_ASSERT_EQUAL_STRING(testString.c_str(), logger.GetBuffer().c_str());
}

void test_log_writeln()
{
    CStringLog logger(";");
    ILog* interface = &logger;  

    interface->WriteLn("Test String");
    TEST_ASSERT_EQUAL_STRING("Test String;", logger.GetBuffer().c_str());
}

void test_log_multywrite()
{
    CStringLog logger(";");
    ILog* interface = &logger;  

    interface->Write("Begin of string");
    interface->WriteLn(" - End of string");
    interface->WriteLn("Second String");
    TEST_ASSERT_EQUAL_STRING("Begin of string - End of string;Second String;", logger.GetBuffer().c_str());
}

void test_log_clear()
{
    CStringLog logger;
    ILog* interface = &logger;  
    String testString = "Test String";
    interface->Write(testString);

    interface->Clear();
    TEST_ASSERT_EQUAL_STRING("", logger.GetBuffer().c_str());
}

//////////////////////// CompositorLog ///////////////////////////////

void test_compositor_log_create()
{
    CCompositorLog compositor;
    ILog* p_compositor = &compositor;  
    TEST_ASSERT_EQUAL(0, compositor.Count());
} 

void test_compositor_log_add_child_success()
{
    CCompositorLog compositor;
    CStringLog log_child;
    ILog* p_log_child = &log_child;
    TEST_ASSERT_TRUE(compositor.Add(p_log_child));
}

void test_compositor_log_add_null_fail()
{
    CCompositorLog compositor;
    TEST_ASSERT_FALSE(compositor.Add(NULL));
}

void test_compositor_log_add_capacity_fail()
{
    CCompositorLog compositor;
    CStringLog log_child0;
    ILog* p_log_child0 = &log_child0;    
    CStringLog log_child1;
    ILog* p_log_child1 = &log_child1;    
    CStringLog log_child2;
    ILog* p_log_child2 = &log_child2;    
    CStringLog log_child3;
    ILog* p_log_child3 = &log_child3;    
    CStringLog log_child4;
    ILog* p_log_child4 = &log_child4;    
    CStringLog log_child5;
    ILog* p_log_child5 = &log_child5;    
    TEST_ASSERT_TRUE(compositor.Add(p_log_child0));
    TEST_ASSERT_TRUE(compositor.Add(p_log_child1));
    TEST_ASSERT_TRUE(compositor.Add(p_log_child2));
    TEST_ASSERT_TRUE(compositor.Add(p_log_child3));
    TEST_ASSERT_TRUE(compositor.Add(p_log_child4));
    TEST_ASSERT_FALSE(compositor.Add(p_log_child5));
}

void test_compositor_log_add_exists_fail()
{
    CCompositorLog compositor;
    CStringLog log_child;
    ILog* p_log_child = &log_child;
    TEST_ASSERT_TRUE(compositor.Add(p_log_child));
    TEST_ASSERT_FALSE(compositor.Add(p_log_child));
}

void test_compositor_log_remove_exists_success()
{
    CCompositorLog compositor;
    CStringLog log_child;
    ILog* p_log_child = &log_child;
    compositor.Add(p_log_child);
    TEST_ASSERT_TRUE(compositor.Remove(p_log_child));
}

void test_compositor_log_remove_notexists_fail()
{
    CCompositorLog compositor;

    CStringLog log_child;
    ILog* p_log_child = &log_child;
    
    TEST_ASSERT_FALSE(compositor.Remove(NULL));
    TEST_ASSERT_FALSE(compositor.Remove(p_log_child));
}

void test_compositor_log_count()
{
    CCompositorLog compositor;
    CStringLog log_child0;
    ILog* p_log_child0 = &log_child0;    
    compositor.Add(p_log_child0);
    TEST_ASSERT_EQUAL(1, compositor.Count());

    CStringLog log_child1;
    ILog* p_log_child1 = &log_child1;    
    compositor.Add(p_log_child1);
    TEST_ASSERT_EQUAL(2, compositor.Count());

    CStringLog log_child2;
    ILog* p_log_child2 = &log_child2;    
    compositor.Add(p_log_child2);
    TEST_ASSERT_EQUAL(3, compositor.Count());

    CStringLog log_child3;
    ILog* p_log_child3 = &log_child3;    
    compositor.Add(p_log_child3);
    TEST_ASSERT_EQUAL(4, compositor.Count());

    CStringLog log_child4;
    ILog* p_log_child4 = &log_child4;    
    compositor.Add(p_log_child4);
    TEST_ASSERT_EQUAL(5, compositor.Count());
}

void test_compositor_log_count_fragmentate()
{
    CCompositorLog compositor;
    CStringLog log_child0;
    ILog* p_log_child0 = &log_child0;    

    CStringLog log_child1;
    ILog* p_log_child1 = &log_child1;    

    CStringLog log_child2;
    ILog* p_log_child2 = &log_child2;    

    compositor.Add(p_log_child0);
    compositor.Add(p_log_child1);
    compositor.Add(p_log_child2);
    compositor.Remove(p_log_child1);

    TEST_ASSERT_EQUAL(2, compositor.Count());   
    TEST_ASSERT_FALSE(compositor.IsExists(p_log_child1));   
}

void test_compositor_log_IsExists_true()
{
    CCompositorLog compositor;
    CStringLog log_child0;
    ILog* p_log_child0 = &log_child0;    

    CStringLog log_child1;
    ILog* p_log_child1 = &log_child1;    

    compositor.Add(p_log_child0);
    compositor.Add(p_log_child1);

    TEST_ASSERT_TRUE(compositor.IsExists(p_log_child0));
    TEST_ASSERT_TRUE(compositor.IsExists(p_log_child1));
}

void test_compositor_log_IsExists_false_null()
{
    CCompositorLog compositor;
    TEST_ASSERT_FALSE(compositor.IsExists(NULL));
}

void test_compositor_log_IsExists_false_notexists()
{
    CCompositorLog compositor;
    CStringLog log_child0;
    ILog* p_log_child0 = &log_child0;    

    CStringLog log_child1;
    ILog* p_log_child1 = &log_child1;    

    compositor.Add(p_log_child0);

    TEST_ASSERT_FALSE(compositor.IsExists(p_log_child1));
}

void test_compositor_log_persistmethods_empty() {
    CCompositorLog compositor;
    ILog* p_compositor = &compositor;
    p_compositor->Write("Message1");
    p_compositor->WriteLn("Message2");
    p_compositor->Clear();
    TEST_PASS();
}

void test_compositor_log_write()
{
    CCompositorLog compositor;
    CStringLog child1, child2;
    
    compositor.Add(&child1);
    compositor.Add(&child2);

    compositor.Write("Message1");
    
    // Проверяем, что сообщение пришло ТОЛЬКО в child1
    TEST_ASSERT_EQUAL_STRING("Message1", child1.GetBuffer().c_str());
    TEST_ASSERT_EQUAL_STRING("Message1", child2.GetBuffer().c_str());
}
void test_compositor_log_writeln()
{
    CCompositorLog compositor;
    CStringLog child1(";"), child2("|");
    
    compositor.Add(&child1);
    compositor.Add(&child2);

    compositor.WriteLn("Message1");
    
    // Проверяем, что сообщение пришло ТОЛЬКО в child1
    TEST_ASSERT_EQUAL_STRING("Message1;", child1.GetBuffer().c_str());
    TEST_ASSERT_EQUAL_STRING("Message1|", child2.GetBuffer().c_str());
}

void test_compositor_log_clear()
{
    CCompositorLog compositor;
    CStringLog child1(";"), child2("|");
    
    compositor.Add(&child1);
    compositor.Add(&child2);

    compositor.WriteLn("Message1");
    compositor.Clear();

    TEST_ASSERT_EQUAL_STRING("", child1.GetBuffer().c_str());
    TEST_ASSERT_EQUAL_STRING("", child2.GetBuffer().c_str());
}

void test_compositor_log_remove_affects_behavior() {
    CCompositorLog compositor;
    CStringLog child1, child2;
    
    compositor.Add(&child1);
    compositor.Add(&child2);
    compositor.Write("A");
    
    compositor.Remove(&child1);
    compositor.Write("B");
    
    TEST_ASSERT_EQUAL_STRING("A", child1.GetBuffer().c_str());
    TEST_ASSERT_EQUAL_STRING("AB", child2.GetBuffer().c_str());

}