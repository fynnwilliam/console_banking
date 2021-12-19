#pragma once
#include <atomic>
#include <fstream>

class id_generator
{
private:
    std::atomic<std::uint64_t> id_{};
    
    static std::uint64_t read_id()       noexcept;
    void save_last_id()            const noexcept;
    
    id_generator(std::uint64_t i) : id_{i} {}
    id_generator(id_generator const&) = delete;
    id_generator& operator=(id_generator const&) = delete;
    
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