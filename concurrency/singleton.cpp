// Thread-safe singleton

struct SingletonFoo {
    auto& getInstance();
};

inline auto& SingletonFoo::getInstance() {
    static SingletonFoo instance;   // Thread-safe static initialization
    return instance;
}