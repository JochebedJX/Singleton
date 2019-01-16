#pragma once
#include<iostream>

class Singleton
{
public:
  static Singleton* GetInstance()
  {
    return &m_instance;
  }
 
private:
  // 构造函数私有
  Singleton(){};
 
  // 防拷贝
  Singleton(Singleton const&); 
  Singleton& operator=(Singleton const&); 
 
  static Singleton m_instance;
};
 
Singleton Singleton::m_instance; // 在程序入口之前就完成单例对象的初始化





