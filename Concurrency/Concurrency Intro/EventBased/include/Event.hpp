#pragma once

// namespace custom_events{
#include <mutex>
#include <condition_variable>
#include <functional>
class manual_event
{
  public:
    explicit manual_event() noexcept : m_signaled(false) {}
    /*change the state(m_signaled=true) and remains signaled until it is explicitly reset to nonsignaled by the reset function */
    void signal()
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_signaled = true;
        m_cv.notify_all(); //signals/notifies all threads waiting on this event
    }
    
    /* all threads waiting on an event to be signalled, lock realeased when (m_signaled=true)*/
    void wait()
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_cv.wait(lock, [&]() { return m_signaled == true; });
    }

    /*explicit reset changes the state(m_signaled=false)*/
    void reset()
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_signaled = false;
    }

  private:
    
    bool m_signaled = false;
    std::mutex m_mutex;
    std::condition_variable m_cv;
};

class auto_event
{
  public:
    explicit auto_event(bool signaled = false) noexcept
        : m_signaled(signaled) {}

    void signal() noexcept
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_signaled = true;
        m_cv.notify_one();
    }

    void wait() noexcept
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_cv.wait(lock, [&]() { return m_signaled != false; });
        m_signaled = false;
    }

  private:
    bool m_signaled = false;
    std::mutex m_mutex;
    std::condition_variable m_cv;
};

// }