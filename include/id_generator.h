#pragma once
#include <atomic>

class id_generator
{
private:
    std::atomic<std::uint64_t> id_{};
    
    static std::uint64_t read_id()       noexcept;
    void save_last_id()            const noexcept;
    
    id_generator(std::uint64_t i) : id_{i} {}
    
public:
    static id_generator& instance()      noexcept
    {
        static id_generator id{read_id()};
        return id;
    }
    
    std::uint64_t operator++()           noexcept;
    std::uint64_t operator++(int)        noexcept;
    
    ~id_generator();
};