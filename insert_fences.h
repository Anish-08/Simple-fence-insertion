#ifndef INSERT_FENCES_H
#define INSERT_FENCES_H

#include<vector>
#include<string>

// typedef enum fence_type{

// } fence_type;

struct Fence{
    int line;
    std::string fence_name;
    // fence_type type;
    Fence(): line(0), fence_name("std::atomic_thread_fence(std::memory_order_release);") {;}
    Fence(int u): line(u), fence_name("std::atomic_thread_fence(std::memory_order_release);") {;}
    bool operator < (const Fence& a) const{
        return line<a.line;
    }
};


struct Insert_Fence{
    std::vector<Fence*> fences_list;

    bool insert(int x);
    void print_final();
    bool modify(std::string source_filename, std::string modif_filename);
};

#endif