#pragma once

#include <iostream>
#include <mutex>

using namespace std;
class Singleton
{
public:
  static Singleton* GetInstance() {
  // 注意这里一定要使用Double-Check的方式加锁，才能保证效率和线程安全
    if (nullptr == m_pInstance) {
      m_mtx.lock();
      if (nullptr == m_pInstance) {
        m_pInstance = new Singleton();
      }
      m_mtx.unlock();
    }
    return m_pInstance;
  }
  // 实现一个内嵌垃圾回收类 
  class CGarbo {
  public:
    ~CGarbo(){
    if (Singleton::m_pInstance)
      delete Singleton::m_pInstance;
    }
  };
  // 定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
  static CGarbo Garbo;
  private:
  // 构造函数私有
    Singleton(){};
    // 防拷贝
    Singleton(Singleton const&);
    Singleton& operator=(Singleton const&);
    static Singleton* m_pInstance; // 单例对象指针
    static mutex m_mtx; //互斥锁
};
Singleton* Singleton::m_pInstance = nullptr;
Singleton::CGarbo Garbo;
mutex Singleton::m_mtx;



