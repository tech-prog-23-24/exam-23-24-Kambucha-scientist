#include "MemoryCache.h"


MemoryCache* MemoryCache::getInstance() {
    if (!p_instance) {
        p_instance = new MemoryCache();
        destroyer.initialize(p_instance);
    }
    return p_instance;
}

void MemoryCache::put(const std::string& key, const std::string& value) {
    if (cache.size() >= maxSize) {
        cache.erase(cache.begin());
    }
    cache[key] = value;
}

std::string MemoryCache::get(const std::string& key) {
    auto it = cache.find(key);
    return (it != cache.end()) ? it->second : "???";
}

void MemoryCache::remove(const std::string& key) {
    cache.erase(key);
}

void MemoryCache::clear() {
    cache.clear();
}

size_t MemoryCache::size() const {
    return cache.size();
}

bool MemoryCache::contains(const std::string& key) const {
    return cache.find(key) != cache.end();
}

void MemoryCache::setMaxSize(size_t size) {
    maxSize = size;
    while (cache.size() > maxSize) {
        cache.erase(cache.begin());
    }
}

MemoryCacheDestroyer::~MemoryCacheDestroyer() {
    delete p_instance;
}

void MemoryCacheDestroyer::initialize(MemoryCache* p) {
    p_instance = p;
}

MemoryCache* MemoryCache::p_instance = nullptr;
MemoryCacheDestroyer MemoryCache::destroyer;