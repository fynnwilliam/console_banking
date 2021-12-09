
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
    void write_to_file() const noexcept;
};