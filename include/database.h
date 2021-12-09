#include <unordered_map>

class database
{
private:
    std::unordered_map<unsigned, account> db_;
    
    database() = default;

public:
    database& static instance() const noexcept
    {
        static database db{};
        return db;
    }
    
    auto insert(unsigned, account) noexcept;
    void write_to_file()     const noexcept;
    std::optional<account&>       find(unsigned)       noexcept;
    std::optional<account const&> find(unsigned) const noexcept;
    void erase(unsigned) noexcept;
    auto  begin()  const noexcept;
    auto cbegin()  const noexcept;
    auto    end()  const noexcept;
    auto   cend()  const noexcept;
    bool  empty()  const noexcept;
};