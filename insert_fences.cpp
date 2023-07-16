#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include"insert_fences.h"


bool comp(const Fence* a, const Fence* b){
    return a->line<b->line;
}

bool Insert_Fence::insert(int x){
    fences_list.push_back(new Fence(x));
    return true;
}
void Insert_Fence::print_final(){
    for(int i=0;i<fences_list.size();i++){
        std::cout<<fences_list[i]->line<<"\n";
    }
}

bool Insert_Fence::modify(std::string source_filename, std::string modif_filename){
    std::sort(fences_list.begin(),fences_list.end(),comp);
    
    // print_final();
    // return true;
    std::ifstream infile(source_filename);
    std::ofstream outfile(modif_filename);

    std::string line;
    int line_num = 1;
    int i = 0;

    while(std::getline(infile,line)){
        outfile<<line;
        outfile<<"\n";
        if(i<fences_list.size() && line_num == fences_list[i]->line){
            outfile<<fences_list[i]->fence_name;
            outfile<<"\n";
            i++;
        }

        line_num++;
    }

    outfile.close();
    infile.close();

    if(i!=fences_list.size()) return false;

    return true;
}


