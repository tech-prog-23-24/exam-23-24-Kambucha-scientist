
#include <string>
#include <map>


class MemoryCache;

class MemoryCacheDestroyer
{
private:
    MemoryCache* p_instance;
public:
    ~MemoryCacheDestroyer();
    void initialize(MemoryCache* p);
};

class MemoryCache
{
private:
    static MemoryCache* p_instance;
    static MemoryCacheDestroyer destroyer;

    std::map<std::string, std::string> cache;
    size_t maxSize = 100;

protected:
    MemoryCache() {}
    MemoryCache(const MemoryCache&) = delete;
    MemoryCache& operator=(const MemoryCache&) = delete;
    ~MemoryCache() {}
    friend class MemoryCacheDestroyer;

public:
    static MemoryCache* getInstance();


    void put(const std::string& key, const std::string& value);
    std::string get(const std::string& key);
    void remove(const std::string& key);
    void clear();
    size_t size() const;
    bool contains(const std::string& key) const;
    void setMaxSize(size_t size);
};



