#include <atomic>

class id_generator
{
private:
    std::atomic<std::uint64_t> id_{};
    
    static std::uint64_t read_id()    noexcept;
    void save_last_id()         const noexcept;
    
    id_generator() = default;
    
public:
    static id_generator& instance()   noexcept;
    
    ~id_generator();
};